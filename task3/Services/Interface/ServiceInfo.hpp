//
// Created by Maxim on 29.12.2022.
//

#ifndef TASK3_SERVICEINFO_HPP
#define TASK3_SERVICEINFO_HPP
#include "IncludeLibs.hpp"
#include "Service.hpp"
struct ServiceInfo{
  using CreateMethod = std::function<Service*()>;
  std::string description;
  CreateMethod create;
};
#endif // TASK3_SERVICEINFO_HPP
