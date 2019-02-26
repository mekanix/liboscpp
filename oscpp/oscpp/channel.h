#pragma once

#include "io.h"


class Channel : public IO
{
  public:
    Channel(const int channel);

    void channel(const int &number);
    int channel() const;

    void fader(float value);
    float fader() const;

  private:
    int _channel;
    float _fader;
};
