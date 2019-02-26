#pragma once

#include <netinet/in.h>


class IO
{
  public:
    static int sockfd;
    static struct sockaddr_in serv;
    static socklen_t m;

    static void findMixer();
    static void send(const char *buffer, const size_t &size);

    const size_t & convert(char *buffer, void *value, const size_t &size);
};
