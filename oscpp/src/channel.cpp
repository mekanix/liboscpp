#include <oscpp/channel.h>
#include <string.h>
#include <stdio.h>
#include <sys/socket.h>


static std::map<std::string, std::string> initFormatStrings()
{
  std::map<std::string, std::string> formatStrings;
  formatStrings["fader"] = "/ch/%02d/mix/fader";
  formatStrings["mute"] = "/ch/%02d/mix/on";
  formatStrings["solo"] = "/-stat/solosw/%02d";
  formatStrings["busLevel"] = "/ch/%02d/mix/%02d/level";
  return formatStrings;
}

std::map<std::string, std::string> Channel::formatStrings = initFormatStrings();


Channel::Channel()
  : _channel{1}
  , _fader{0.75}
{}


Channel::Channel(const int &channel)
  : _channel{channel}
  , _fader{0.75}
{}


void Channel::channel(const int &number)
{ _channel = number; }


int Channel::channel() const
{ return _channel; }


void Channel::fader(float &value)
{
  char send_buffer[64] = {0};
  int size = 0;
  _fader = value;

  sprintf(send_buffer, formatStrings["fader"].data(), _channel);
  size += strlen(send_buffer) + 4;
  strncpy(send_buffer + size, ",f", 2);
  size += 4;
  size += this->convert(send_buffer + size, &_fader, sizeof(_fader));
  send(send_buffer, size);
}


float Channel::fader() const
{ return _fader; }


void Channel::busLevel(float &value, const int &bus)
{
  char send_buffer[64] = {0};
  int size = 0;
  _buses[bus] = value;

  sprintf(send_buffer, formatStrings["busFader"].data(), _channel, bus);
  size += strlen(send_buffer) + 4;
  strncpy(send_buffer + size, ",f", 2);
  size += 4;
  size += this->convert(send_buffer + size, &value, sizeof(value));
  send(send_buffer, size);
}


float Channel::busLevel(const int &bus) const
{ return _buses[bus]; }


void Channel::mute(const int &muted)
{
  char send_buffer[64] = {0};
  int size = 0;
  _mute = muted;

  sprintf(send_buffer, formatStrings["mute"].data(), _channel);
  size += strlen(send_buffer) + 3;
  strncpy(send_buffer + size, ",i", 2);
  size += 4;
  int value = 1 - _mute;
  size += this->convert(send_buffer + size, &value, sizeof(value));
  send(send_buffer, size);
}


int Channel::mute() const
{ return _mute; }


void Channel::solo(const int &soloed)
{
  char send_buffer[64] = {0};
  int size = 0;
  _solo = soloed;

  sprintf(send_buffer, formatStrings["solo"].data(), _channel);
  size += strlen(send_buffer) + 4;
  strncpy(send_buffer + size, ",i", 2);
  size += 4;
  size += this->convert(send_buffer + size, &_solo, sizeof(_solo));
  send(send_buffer, size);
}


int Channel::solo() const
{ return _solo; }


void Channel::buses(const int &number)
{
  const auto currentSize = _buses.size();
  _buses.resize(number);
  for (int i = currentSize; i < number; ++i)
  {
    _buses[i] = 0.75;
  }
}


int Channel::buses() const
{ return _buses.size(); }
