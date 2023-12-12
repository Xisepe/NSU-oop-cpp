//
// Created by Maxim on 29.11.2022.
//

#ifndef TASK3_WAVCHUNK_HPP
#define TASK3_WAVCHUNK_HPP

#include "IncludeLibs.hpp"

struct WAVChunk {
  uint32_t id; //"data" = 0x61746164
  uint32_t size;  //Chunk data bytes
};
#endif // TASK3_WAVCHUNK_HPP
