#include "channel.h"
#include <string.h>
#include <stdio.h>
#include <sys/socket.h>


Channel::Channel(const int channel)
  : _channel{channel}
{}


void Channel::channel(const int &number)
{ _channel = number; }


int Channel::channel() const
{ return _channel; }


void Channel::fader(float value)
{
  char send_buffer[64] = {0};
  int size = 0;

  const char *pre = "/ch/";
  size += strlen(pre);
  strncpy(send_buffer, pre, size);

  sprintf(send_buffer + size, "%02d", _channel);
  size += 2;

  const char *post = "/mix/fader";
  int postLen = strlen(post);
  strncpy(send_buffer + size, post, postLen);
  size += postLen;
  size += 4;

  strncpy(send_buffer + size, ",f", 2);
  size += 4;

  size += this->convert(send_buffer + size, &value, sizeof(value));

  send(send_buffer, size);
}
