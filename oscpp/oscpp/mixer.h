#pragma once

#include <string>
#include <vector>
#include <oscpp/channel.h>
#include <oscpp/io.h>


class Mixer : public IO
{
  public:
    Mixer();
    Mixer(const std::string &name, const int channels);

    void name(const std::string &n);
    std::string name() const;

    void channels(const int &number);
    int channels() const;

    bool channel(Channel &channel, const int &number);
    Channel * channel(const int &number);

    void buses(const int &number);
    int buses() const;


  private:
    std::string _name;
    std::vector<Channel> _channels;
};
