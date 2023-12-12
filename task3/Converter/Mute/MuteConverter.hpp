//
// Created by Maxim on 27.12.2022.
//

#ifndef TASK3_MUTECONVERTER_HPP
#define TASK3_MUTECONVERTER_HPP

#include "ConverterRegistrator/ConverterRegistrator.hpp"
#include "Interface/Converter.hpp"
class MuteConverter : public Converter {
public:
  const SampleStream &convert(const std::vector<SampleStream> &input) override;
  ~MuteConverter() override = default;

protected:
  bool checkInput(const std::vector<SampleStream> &input) override;

private:
  inline static ConverterRegistrations::ConverterRegistrator<MuteConverter>
      _Mute = {
          "mute",
          "\nMuteConverter:\nMute input from start second to end second "
          "one.\n-std::vector<SampleStream> which must contain one "
          "SampleStream, otherwise throws exception\n-output SampleStream"};
};

#endif // TASK3_MUTECONVERTER_HPP
