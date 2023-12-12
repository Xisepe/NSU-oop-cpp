//
// Created by maxim on 22.10.2022.
//

#include "CommandLineArgumentParser.hpp"
#include "InputArgumentException.h"
#include <getopt.h>
#include <iostream>

CommandLineArguments CommandLineArgumentParser::parse() const {
  const char *short_options = "hi:o:f:m:";

  const struct option long_options[] = {
      {"iterations", required_argument, NULL, 'i'},
      {"mode", required_argument, NULL, 'm'},
      {"filename", required_argument, NULL, 'f'},
      {"output", required_argument, NULL, 'o'},
      {NULL, 0, NULL, 0}};

  int rez;
  int option_index;
  CommandLineArguments args;
  while ((rez = getopt_long(_argc, _argv, short_options, long_options,
                            &option_index)) != -1) {
    switch (rez) {
    case 'i': {
      args.setIterations(std::stoi(optarg));
      break;
    }
    case 'o': {
      args.setOutputFilepath(optarg);
      break;
    }
    case 'f': {
      args.setInputFilepath(optarg);
      break;
    }
    case 'm': {
      args.setMode(std::stoi(optarg));
      break;
    }
    default: {
      throw InputArgumentException();
    }
    }
  }
  return args;
}

CommandLineArgumentParser::CommandLineArgumentParser(int argc, char **argv)
    : _argc(argc), _argv(argv) {}
