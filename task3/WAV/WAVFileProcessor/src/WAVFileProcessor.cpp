//
// Created by Maxim on 27.12.2022.
//

#include "WAVFileProcessor.hpp"
WAVFileProcessor::input_iterator WAVFileProcessor::begin() {
  return input_iterator(this);
}
WAVFileProcessor::input_iterator WAVFileProcessor::end() {
  return input_iterator();
}
void WAVFileProcessor::next() {
  readData<SampleStream, WAVData::byteRate>(&sampleStream);
}
void WAVFileProcessor::readHeaderAndCheck() {
  readData<WAVHeader>(&header);
  if (!in) {
    throw WAVParserReadException("Cannot read from file");
  }
  if (!checkHeader())
    throw WAVParserReadException("Invalid WAV header");
}
void WAVFileProcessor::findDataChunk() {
  WAVChunk chunk{};
  while (true) {
    readData<WAVChunk>(&chunk);
    if (chunk.id == WAVData::data) {
      break;
    }
    in.seekg(chunk.size, std::ifstream::cur);
  }
  dataSize = chunk.size;
}

WAVFileProcessor::WAVFileProcessor(const std::string &input,
                                   const std::string &path) {
  in = std::fstream(path + input, std::fstream::binary | std::fstream::in |
                                      std::fstream::out);
  if (!in.is_open()) {
    throw WAVParserReadException("Cannot open file " + path);
  }
  readHeaderAndCheck();
  findDataChunk();
  next();
}
bool WAVFileProcessor::checkHeader() {
  if (header.chunkID != WAVData::chunkId)
    return false;
  if (header.format != WAVData::format)
    return false;
  if (header.subchunk1ID != WAVData::subchunk1Id)
    return false;
  if (header.audioFormat != WAVData::audioFormat)
    return false;
  if (header.numChannels != WAVData::numChannels)
    return false;
  if (header.sampleRate != WAVData::sampleRate)
    return false;
  if (header.bitsPerSample != WAVData::bitsPerSample)
    return false;
  if (header.byteRate != WAVData::byteRate)
    return false;
  return true;
}
uint32_t WAVFileProcessor::getDataSize() const { return dataSize; }
const WAVHeader &WAVFileProcessor::getHeader() const { return header; }
const SampleStream &WAVFileProcessor::getSampleStream() const {
  return sampleStream;
}
void WAVFileProcessor::skipTo(int seconds) {
  in.seekg(seconds * header.byteRate, std::ios::cur);
  if (!in) {
    throw WAVParserReadException("Cannot skip to " + std::to_string(seconds));
  }
}
void WAVFileProcessor::overwrite(const SampleStream *stream) {
  in.write((char *)stream, sizeof(SampleStream));
  if (!in) {
    throw WAVProcessorWriteException("Cannot overwrite");
  }
}
void WAVFileProcessor::stepBack() {
  in.seekg(-numberOfReadBytes, std::ios::cur);
}
void WAVFileProcessor::overwriteAfterRead(const SampleStream *stream) {
  stepBack();
  overwrite(stream);
}
WAVFileProcessor::WAVFileProcessor(const std::string &input,
                                   const std::string &output,
                                   const std::string &inPath,
                                   const std::string &outPath) {
  out =
      std::fstream(outPath + output, std::fstream::binary | std::fstream::out);
  in = std::fstream(inPath + input, std::fstream::binary | std::fstream::in |
                                        std::fstream::out);
  if (!in.is_open()) {
    throw WAVParserReadException("Cannot open file " + input);
  }
  if (!out) {
    throw WAVProcessorWriteException("Cannot open file " + output);
  }
  readHeaderAndCheck();
  findDataChunk();
  next();
}
void WAVFileProcessor::resetToDataStart() {
  in.seekg(WAVData::headerSize, std::ios::beg);
}
void WAVFileProcessor::duplicateInput() {
  writeData<WAVHeader>(&header);
  writeData(&WAVData::data);
  writeData(&dataSize);
  for (auto it = begin(); it != end(); ++it) {
    writeData(&(*it));
  }
}
