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
 int sockfd;
 sockfd = socket(AF_INET, SOCK_DGRAM, 0);
 struct sockaddr_in serv;

 serv.sin_family = AF_INET;
 serv.sin_port = htons(10024);
 serv.sin_addr.s_addr = inet_addr("192.168.5.80");

 socklen_t m = sizeof(serv);
 std::string message = "/lr/mix/on  ,i     ";
 message += (char)1;

 // std::string message = "/info";
 auto size = message.size();
 std::cout << message << std::endl;

 std::transform(message.begin(), message.end(), message.begin(), [](char ch) {
   return ch == ' ' ? '\0' : ch;
 });
 sendto(sockfd, message.data(), size, 0, (struct sockaddr *)&serv, m);

 // char buffer[256];
 // auto n = recvfrom(sockfd, buffer, 256, 0, (struct sockaddr *)&serv, &m);
 // if (n == -1)
 // {
   // perror("recvfrom");
 // }
 // for (int i = 0; i < n; ++i) {
   // if (buffer[i] == '\0')
   // {
     // buffer[i] = ' ';
   // }
 // }
 // if (n < 256)
 // {
   // buffer[n] = '\0';
 // }
 // std::cout << buffer << std::endl;

 return 0;
}
