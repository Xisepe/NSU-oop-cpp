//
// Created by Maxim on 27.12.2022.
//

#ifndef TASK3_MIXCONVERTER_HPP
#define TASK3_MIXCONVERTER_HPP
#include "ConverterRegistrator/ConverterRegistrator.hpp"
#include "Interface/Converter.hpp"

class MixConverter : public Converter {
public:
  const SampleStream &convert(const std::vector<SampleStream> &input) override;
  ~MixConverter() override = default;

protected:
  bool checkInput(const std::vector<SampleStream> &input) override;

private:
  inline static ConverterRegistrations::ConverterRegistrator<MixConverter>
      _Mix = {"mix",
              "\nMixConverter:\nMixes two inputs into "
              "one from given second.\n-std::vector<SampleStream> which must "
              "contain two "
              "SampleStream, otherwise throws exception\n-output SampleStream"};
};

#endif // TASK3_MIXCONVERTER_HPP
