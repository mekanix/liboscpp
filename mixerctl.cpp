#include <iostream>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>

int main()
{
  float value = 0.75;
  int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  struct sockaddr_in serv;
  socklen_t m = sizeof(serv);

  serv.sin_family = AF_INET;
  serv.sin_port = htons(10024);
  serv.sin_addr.s_addr = inet_addr("192.168.5.80");

  std::string message = "/ch/01/mix/fader    ,f  ";
  for (int i = 3; i >= 0; --i)
  {
    message += ((char *)&value)[i];
  }
  auto size = message.size();
  std::transform(message.begin(), message.end(), message.begin(), [](char ch) {
    return ch == ' ' ? '\0' : ch;
  });
  sendto(sockfd, message.data(), size, 0, (struct sockaddr *)&serv, m);

  return 0;
}
