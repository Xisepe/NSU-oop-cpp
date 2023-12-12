//
// Created by Maxim on 27.12.2022.
//

#ifndef TASK3_WAVDATA_HPP
#define TASK3_WAVDATA_HPP

#include "WAVHeader.hpp"
class WAVData{
public:
  static constexpr auto chunkId = 0x46464952;
  static constexpr auto format = 0x45564157;
  static constexpr auto subchunk1Id = 0x20746D66;
  static constexpr auto audioFormat = 1;
  static constexpr auto numChannels = 1;
  static constexpr auto sampleRate = 44100;
  static constexpr auto byteRate = 88200;
  static constexpr auto data = 0x61746164;
  static constexpr auto bitsPerSample = 16;
  static constexpr auto headerSize = sizeof(WAVHeader) + 8;
};

#endif // TASK3_WAVDATA_HPP
