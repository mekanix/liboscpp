#pragma once

#include <string>
#include <vector>
#include <oscpp/channel.h>


class Mixer
{
  public:
    Mixer();
    Mixer(const std::string &name, const int channels);

    void name(const std::string &n);
    std::string name() const;

    void channels(const int &number);
    int channels() const;

    bool channel(Channel &channel, const int &number);


  private:
    std::string _name;
    std::vector<Channel> _channels;
};
