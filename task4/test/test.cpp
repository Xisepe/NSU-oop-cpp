//
// Created by Maxim on 26.12.2022.
//
#include "CSVExceptions.hpp"
#include "CSVParser.hpp"
#include "CommandLineParser.hpp"
#include "IncludeLibs.hpp"
#include "PrintTuple.hpp"
#include <gtest/gtest.h>

using ParserStringIntDouble=CSVParser<std::string, int, double>;



TEST(CommandLineParser, ParseCorrectTest) {
  char *argv[] = {"./test",     "--skip=10",  "--row=\n",
                  "--column=;", "--shield=~", "--filename=f.csv"};
  int argc = 6;
  CommandLineParser p(argc, argv);
  EXPECT_EQ(p.getSkip(), 10);
  EXPECT_EQ(p.getFilename(), "f.csv");
  EXPECT_EQ(p.getColumnDelimiter(), ';');
  EXPECT_EQ(p.getRowDelimiter(), '\n');
  EXPECT_EQ(p.getShield(), '~');
}
TEST(CommandLineParser, ParseWrongTest) {
  char *argv[] = {"./test", "--unsupported=false"};
  int argc = 2;
  EXPECT_THROW(CommandLineParser p(argc, argv), po::error_with_option_name);
}

TEST(PrintTuple, PrintTupleTest) {
  std::tuple<std::string,double,int,bool> t = std::make_tuple("Maxim",25.4,19,true);
  std::ostringstream os_test;
  os_test << t;
  std::ostringstream os_correct;
  os_correct << "Maxim 25.4 19 1 ";
  EXPECT_EQ(os_correct.str(),os_test.str());
}

TEST(CSVParser, ConstructorNoThrowTest) {
  std::string path = "../../Data/";
  std::ifstream in(path + "correct.csv");
  EXPECT_NO_THROW(ParserStringIntDouble parser(&in, 0););
}

TEST(CSVParser, SkipLinesThrowReadExceptionTest) {
  std::string path = "../../Data/";
  std::ifstream in(path + "correct.csv");
  EXPECT_THROW(ParserStringIntDouble parser(&in, 100),ReadException);
}

TEST(CSVParser, WrongInputDataThrowInvalidArgumentTest) {
  std::ifstream in("bad.csv");
  EXPECT_THROW(ParserStringIntDouble parser(&in, 0),std::invalid_argument);
}

TEST(CSVParser, WrongCSVDataThrowWrongDataTest) {
  std::string path = "../../Data/";
  std::ifstream in(path + "wrong.csv");
  EXPECT_THROW(ParserStringIntDouble p(&in,1),WrongDataException);
}

TEST(CSVParser, ShieldTest){
  std::string path = "../../Data/";
  std::ifstream in(path + "shield.csv");
  ParserStringIntDouble p(&in,0);
  auto it = p.begin();
  std::ostringstream os_test;
  os_test << *it;
  std::ostringstream os_correct;
  os_correct << ", 123 123.5 ";
  EXPECT_EQ(os_correct.str(),os_test.str());
}