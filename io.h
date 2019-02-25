#pragma once

#include <netinet/in.h>


class IO
{
  public:
    static int sockfd;
    static struct sockaddr_in serv;
    static socklen_t m;

    const size_t & convert(char *buffer, void *value, const size_t &size);
};
