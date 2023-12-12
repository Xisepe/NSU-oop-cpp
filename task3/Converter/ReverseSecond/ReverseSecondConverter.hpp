//
// Created by Maxim on 27.12.2022.
//

#ifndef TASK3_REVERSESECONDCONVERTER_HPP
#define TASK3_REVERSESECONDCONVERTER_HPP

#include "ConverterRegistrator/ConverterRegistrator.hpp"
#include "Interface/Converter.hpp"

class ReverseSecondConverter : public Converter {
public:
  const SampleStream &convert(const std::vector<SampleStream> &input) override;
  ~ReverseSecondConverter() override = default;

protected:
  bool checkInput(const std::vector<SampleStream> &input) override;

private:
  inline static ConverterRegistrations::ConverterRegistrator<
      ReverseSecondConverter>
      _ReverseSecondConverter = {
          "reverse",
          "\nReverseSecondConverter:\nReverses each second of given input from "
          "start second to end second "
          ".\n-std::vector<SampleStream> which must contain one "
          "SampleStream, otherwise throws exception\n-output SampleStream"};
};

#endif // TASK3_REVERSESECONDCONVERTER_HPP
