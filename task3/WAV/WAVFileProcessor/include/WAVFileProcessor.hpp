//
// Created by Maxim on 27.12.2022.
//

#ifndef TASK3_WAVFILEPROCESSOR_HPP
#define TASK3_WAVFILEPROCESSOR_HPP

#include "IncludeLibs.hpp"
#include "Sample.hpp"
#include "WAVFileStructure.hpp"
#include "WAVParserException/WAVParserReadException/WAVParserReadException.hpp"
#include "WAVParserException/WAVProcessorWriteException/WAVProcessorWriteException.hpp"

class WAVFileProcessor {
private:
  uint32_t dataSize = UINT32_MAX;
  std::fstream in;
  std::fstream out;
  WAVHeader header;
  SampleStream sampleStream;
  long numberOfReadBytes;

  template <class T, long size = sizeof(T)> void readData(T *buf) {
    if (!in) {
      throw WAVParserReadException("Cannot read from file");
    }
    in.read(reinterpret_cast<char *>(buf), size);
    numberOfReadBytes = in.gcount();
  };

  template <class T, long size = sizeof(T)> void writeData(T *buf) {
    if (!out) {
      throw WAVProcessorWriteException("Cannot write to file");
    }
    out.write((char *)buf, size);
  }

  void stepBack();

  void readHeaderAndCheck();
  bool checkHeader();
  void findDataChunk();
  void overwrite(const SampleStream *stream);
  void next();
public:
  void duplicateInput();
  void resetToDataStart();
  uint32_t getDataSize() const;
  const WAVHeader &getHeader() const;
  const SampleStream &getSampleStream() const;
  void skipTo(int seconds);
  void overwriteAfterRead(const SampleStream *stream);

  class input_iterator {
  private:
    WAVFileProcessor *iter_ptr;

  public:
    using iterator_category = std::input_iterator_tag;
    using value_type = SampleStream;
    using pointer = value_type *;
    using reference = value_type &;
    input_iterator(input_iterator &iterator) : iter_ptr(iterator.iter_ptr) {}
    explicit input_iterator(WAVFileProcessor *ptr = nullptr) : iter_ptr(ptr) {}

    friend bool operator==(const input_iterator &iterator1,
                           const input_iterator &iterator2) {
      return iterator1.iter_ptr == iterator2.iter_ptr;
    }
    friend bool operator!=(const input_iterator &iterator1,
                           const input_iterator &iterator2) {
      return !(iterator1 == iterator2);
    }
    reference operator*() const { return iter_ptr->sampleStream; }
    pointer operator->() { return &(iter_ptr->sampleStream); }
    input_iterator &operator++() {
      if (iter_ptr->in.eof()) {
        iter_ptr = nullptr;
        return *this;
      }
      iter_ptr->next();
      return *this;
    }
    input_iterator operator++(int) {
      if (iter_ptr->in.eof()) {
        iter_ptr = nullptr;
        return *this;
      }
      iter_ptr->next();
      return *this;
    }
  };
  WAVFileProcessor() = delete;
  WAVFileProcessor(const std::string &input,
                   const std::string &path);
  WAVFileProcessor(const std::string &input, const std::string &output,
                   const std::string &inPath,
                   const std::string &outPath);
  input_iterator begin();
  input_iterator end();
};

#endif // TASK3_WAVFILEPROCESSOR_HPP
