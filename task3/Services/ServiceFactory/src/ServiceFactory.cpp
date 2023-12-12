//
// Created by Maxim on 29.12.2022.
//

#include "ServiceFactory.hpp"
bool ServiceFactory::registerService(const std::string &name,
                                     const ServiceInfo &serviceInfo) {
  if (map.find(name) != map.end()) {
    return false;
  }
  map[name] = serviceInfo;
  return true;
}
Service *ServiceFactory::orderService(const std::string &name) const {
  return map.at(name).create();
}
const ServiceFactory &ServiceFactory::getInstance() {
  static ServiceFactory serviceFactory;
  return serviceFactory;
}
ServiceFactory::ServiceFactory() {
  registerService(
      "mute",
      {
          "MuteService",
          [](){return static_cast<Service*>(new MuteService());}
      }
      );
  registerService(
      "reverse",
      {
          "ReverseSecond",
          [](){return static_cast<Service*>(new ReverseService());}
      }
  );
  registerService(
      "mix",
      {
          "MixService",
          [](){return static_cast<Service*>(new MixService());}
      }
      );
}
