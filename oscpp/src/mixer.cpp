#include <oscpp/mixer.h>
#include <iostream>


Mixer::Mixer() {}


Mixer::Mixer(const std::string &name, const int channels)
  : _name{name}
{ this->channels(channels); }


void Mixer::name(const std::string &n)
{ _name = n; }


std::string Mixer::name() const
{ return _name; }


void Mixer::channels(const int &number)
{
  const auto currentSize = _channels.size();
  _channels.resize(number);
  for (int i = currentSize; i < number; ++i)
  {
    _channels[i].channel(i + 1);
  }
}


int Mixer::channels() const
{ return _channels.size(); }


bool Mixer::channel(Channel &channel, const int &number)
{
  if (number >= _channels.size())
  {
    std::cerr << "No such channel" << std::endl;
    return false;
  }
  channel = _channels[number];
  return true;
}


Channel * Mixer::channel(const int &number)
{
  if (number >= _channels.size())
  {
    std::cerr << "No such channel" << std::endl;
    return nullptr;
  }
  return &_channels[number];
}


Channel & channel(const int &number);
