//
// Created by maxim on 15.10.2022.
//

#ifndef TASK_2_COMMANDLINEARGUMENTS_HPP
#define TASK_2_COMMANDLINEARGUMENTS_HPP
#include <ostream>
#include <string>

class CommandLineArguments {
private:
  int _iterations;
  std::string _inputFilepath;
  std::string _outputFilepath;
  int _mode;

public:
  CommandLineArguments();
  CommandLineArguments(int iterations, std::string input, std::string output,
                       int mode);
  int getMode() const;
  void setMode(int mode);

  CommandLineArguments(const CommandLineArguments &args);

  CommandLineArguments &operator=(const CommandLineArguments &args);

  int getIterations() const;

  void setIterations(int iterations);

  const std::string &getInputFilepath() const;

  void setInputFilepath(const std::string &inputFilepath);

  const std::string &getOutputFilepath() const;

  void setOutputFilepath(const std::string &outputFilepath);
  friend std::ostream &operator<<(std::ostream &os,
                                  const CommandLineArguments &arguments);
};

#endif // TASK_2_COMMANDLINEARGUMENTS_HPP
