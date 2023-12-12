//
// Created by Maxim on 24.12.2022.
//

#include "CommandLineParser.hpp"
#include <WAVFileProcessor.hpp>
#include <gtest/gtest.h>

class CommandLineTester {
private:
  inline static char *c_argv[] = {"./test",           "--input",
                                  "elvis.wav",        "rain.wav",
                                  "--output=out.wav", "--config=config.txt"};
  inline static int c_argc = 6;
  inline static char *w_argv[] = {
      "./test", "--input", "elvis.wav", "rain.wav", "--config=config.txt",
      "-ro"};
  inline static int w_argc = 6;

public:
  static void CorrectTest() {
    CommandLineParser parser;
    parser.parse(c_argc, c_argv);
  }
  static void WrongTest() {
    CommandLineParser parser;
    parser.parse(w_argc, w_argv);
  }
};

TEST(CommandLineParser, CorrectTest) {
  EXPECT_NO_THROW(CommandLineTester::CorrectTest());
}

TEST(CommandLineParser, WrongTest) {
  EXPECT_ANY_THROW(CommandLineTester::WrongTest());
}
