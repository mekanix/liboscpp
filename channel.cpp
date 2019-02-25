#include "channel.h"
#include <string.h>
#include <stdio.h>
#include <sys/socket.h>


Channel::Channel(const int channel)
  : _channel{channel}
  , _fader{0.75}
{}


void Channel::channel(const int &number)
{ _channel = number; }


int Channel::channel() const
{ return _channel; }


void Channel::fader(float value)
{
  static const char *faderFormat = "/ch/%02d/mix/fader";
  char send_buffer[64] = {0};
  int size = 0;
  _fader = value;

  sprintf(send_buffer, faderFormat, _channel);
  size += strlen(send_buffer) + 4;
  strncpy(send_buffer + size, ",f", 2);
  size += 4;
  size += this->convert(send_buffer + size, &_fader, sizeof(_fader));
  send(send_buffer, size);
}
