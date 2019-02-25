#include <arpa/inet.h>
#include "channel.h"


int main()
{
  Channel ch(1);
  ch.serv.sin_addr.s_addr = inet_addr("192.168.5.80");
  ch.fader(0.75);
  return 0;
}
