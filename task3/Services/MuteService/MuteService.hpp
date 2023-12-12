//
// Created by Maxim on 29.12.2022.
//

#ifndef TASK3_MUTESERVICE_HPP
#define TASK3_MUTESERVICE_HPP

#include "Interface/Service.hpp"

class MuteService: public Service {
public:
protected:
  bool validateConfig() override;

public:
  void execute() override;
  ~MuteService() override = default;
};

#endif // TASK3_MUTESERVICE_HPP
