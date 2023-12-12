//
// Created by Maxim on 24.12.2022.
//

#ifndef TASK3_SAMPLE_HPP
#define TASK3_SAMPLE_HPP

#include "IncludeLibs.hpp"
#include "WAVData.hpp"

using Sample = int16_t;
using SampleStream = std::array<Sample, WAVData::sampleRate>;

#endif // TASK3_SAMPLE_HPP
