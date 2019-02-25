#pragma once

#include <string>


class Config
{
  public:
    Config();
    Config(const std::string &name, const int channels);

    void name(const std::string &n);
    std::string name() const;

    void channels(const int &number);
    int channels() const;


  private:
    std::string _name;
    int _channelNumber;
};
