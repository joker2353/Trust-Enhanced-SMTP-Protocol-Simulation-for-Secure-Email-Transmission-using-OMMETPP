#ifndef TRUSTSMTP_UTILS_H
#define TRUSTSMTP_UTILS_H


#include <omnetpp.h>
using namespace omnetpp;


inline std::string uniqueId() {
static int id = 0;
return std::string("m") + std::to_string(++id);
}


#endif
