#pragma once

#include "io.h"


class Channel : public IO
{
  public:
    Channel(const int channel);

    void channel(const int &number);
    int channel() const;

    void fader(float value);

  private:
    int _channel;
};
