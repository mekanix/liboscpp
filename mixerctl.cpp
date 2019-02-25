#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>


const size_t & convert(char *buffer, void *value, const size_t &size)
{
  for (int i = 0; i < size; ++i)
  {
    buffer[i] = ((char *)value)[size - i - 1];
  }
  return size;
}


int main()
{
  float value = 0.75;
  int channel = 1;
  int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  struct sockaddr_in serv;
  socklen_t m = sizeof(serv);
  char send_buffer[64] = {0};
  int size = 0;

  serv.sin_family = AF_INET;
  serv.sin_port = htons(10024);
  serv.sin_addr.s_addr = inet_addr("192.168.5.80");

  const char *pre = "/ch/";
  size += strlen(pre);
  strncpy(send_buffer, pre, size);

  sprintf(send_buffer + size, "%02d", channel);
  size += 2;

  const char *post = "/mix/fader";
  int postLen = strlen(post);
  strncpy(send_buffer + size, post, postLen);
  size += postLen;
  size += 4;

  strncpy(send_buffer + size, ",f", 2);
  size += 4;

  size += convert(send_buffer + size, &value, sizeof(value));
  printf("%d\n", size);

  sendto(sockfd, send_buffer, size, 0, (struct sockaddr *)&serv, m);

  return 0;
}
