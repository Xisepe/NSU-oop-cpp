//
// Created by Maxim on 28.11.2022.
//

#ifndef TASK3_HEADER_HPP
#define TASK3_HEADER_HPP

#include "IncludeLibs.hpp"
/**
 * All data values stored in little-endian
 */
struct WAVHeader {
  uint32_t chunkID;
  uint32_t chunkSize;
  uint32_t format;
  uint32_t subchunk1ID;
  uint32_t subchunk1Size;
  uint16_t audioFormat;
  uint16_t numChannels;
  uint32_t sampleRate;
  uint32_t byteRate;
  uint16_t blockAlign;
  uint16_t bitsPerSample;
};

#endif // TASK3_HEADER_HPP
