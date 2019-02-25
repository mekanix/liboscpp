#include "io.h"

#include <sys/socket.h>
#include <arpa/inet.h>


static struct sockaddr_in initSockaddr()
{
  struct sockaddr_in serv;
  serv.sin_family = AF_INET;
  serv.sin_port = htons(10024);
  return serv;
}


int IO::sockfd = socket(AF_INET, SOCK_DGRAM, 0);
struct sockaddr_in IO::serv = initSockaddr();
socklen_t IO::m = sizeof(IO::serv);


const size_t & IO::convert(char *buffer, void *value, const size_t &size)
{
  for (int i = 0; i < size; ++i)
  {
    buffer[i] = ((char *)value)[size - i - 1];
  }
  return size;
}
