//
// Created by Maxim on 29.12.2022.
//

#ifndef TASK3_SERVICEFACTORY_HPP
#define TASK3_SERVICEFACTORY_HPP
#include "IncludeLibs.hpp"
#include "Interface/ServiceInfo.hpp"
#include "MuteService/MuteService.hpp"
#include "ReverseService/ReverseService.hpp"
#include "MixService/MixService.hpp"
class ServiceFactory {
private:
  std::unordered_map<std::string, ServiceInfo> map;
  bool registerService(const std::string&, const ServiceInfo& serviceInfo);
  ServiceFactory();
public:
  static const ServiceFactory& getInstance();
  Service* orderService(const std::string& name) const;
};

#endif // TASK3_SERVICEFACTORY_HPP
