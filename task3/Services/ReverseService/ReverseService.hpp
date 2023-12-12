//
// Created by Maxim on 29.12.2022.
//

#ifndef TASK3_REVERSESERVICE_HPP
#define TASK3_REVERSESERVICE_HPP
#include "Interface/Service.hpp"
class ReverseService : public Service {
public:
  void execute() override;
  ~ReverseService() override = default;

protected:
  bool validateConfig() override;
};

#endif // TASK3_REVERSESERVICE_HPP
