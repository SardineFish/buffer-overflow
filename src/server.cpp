#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <winsock2.h>

#define PORT 3000

void echo(int sock, sockaddr_in* addr, char* buffer)
{
    char text[1024];
    strcpy(text, (char*)buffer);
    printf("%s\n", text);
    sendto(sock, text, 1024, 0, (sockaddr*)addr, sizeof(sockaddr_in));
}

int main()
{
    char buffer[65536];

    WORD sockVersion = MAKEWORD(2, 2);
    WSADATA wsaData;
    WSAStartup(sockVersion, &wsaData);

    int sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
    sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(PORT);

    if(bind(sock, (sockaddr*)&addr, sizeof(addr)) < 0)
    {
        perror("Failed to bind.\n");
        exit(1);
    }
    printf("Server setup.\n");

    while(true)
    {
        sockaddr_in sender;
        int addrLen = sizeof(sender);
        recvfrom(sock, buffer, 65536, 0, (sockaddr*)&sender, &addrLen);
        echo(sock, &sender, buffer);
    }
}