//
// Created by Maxim on 28.12.2022.
//

#ifndef TASK3_APPSTATE_HPP
#define TASK3_APPSTATE_HPP
enum class AppState : int {
  Ok = 0,
  WavFileInputError = 1,
  CommandLineParserError = 2,
  Fail = 3,
  Help = 4,
  WavOutputError = 5,
  ConfigParserError = 6,
  RegistrationError = 7,
  ParserOutputError = 8,
  ServiceError = 9,
  Count = 10
};

#endif // TASK3_APPSTATE_HPP
