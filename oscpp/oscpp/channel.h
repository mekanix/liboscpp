#pragma once

#include <map>
#include <vector>
#include <string>

#include "io.h"


class Channel : public IO
{
  public:
    Channel();
    Channel(const int &channel);

    void channel(const int &number);
    int channel() const;

    void fader(float &value);
    float fader() const;

    void busLevel(float &value, const int &bus);
    float busLevel(const int &bus) const;

    void mute(const int &mutted);
    int mute() const;

    void solo(const int &soloed);
    int solo() const;

    void buses(const int &number);
    int buses() const;

  private:
    int _channel;
    int _mute;
    int _solo;
    float _fader;
    std::vector<float> _buses;
    static std::map<std::string, std::string> formatStrings;
};
