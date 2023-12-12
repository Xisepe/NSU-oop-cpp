//
// Created by Maxim on 29.12.2022.
//

#ifndef TASK3_MIXSERVICE_HPP
#define TASK3_MIXSERVICE_HPP
#include "Interface/Service.hpp"

class MixService: public Service {
public:
  void execute() override;
  ~MixService() override = default;

protected:
  bool validateConfig() override;
};

#endif // TASK3_MIXSERVICE_HPP
