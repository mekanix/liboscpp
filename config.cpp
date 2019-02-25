#include "config.h"


Config::Config() {}


Config::Config(const std::string &name, const int channels)
  : _name{name}
  , _channelNumber{channels}
{}


void Config::name(const std::string &n)
{ _name = n; }


std::string Config::name() const
{ return _name; }


void Config::channels(const int &number)
{ _channelNumber = number; }


int Config::channels() const
{ return _channelNumber; }
