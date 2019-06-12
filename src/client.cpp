#include <memory.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>

#define PORT 3000

int main()
{
    char buffer[] = "Hello World!";

    int add = (int)GetProcAddress(GetModuleHandleA("kernel32.dll"), "LoadLibraryA");
    printf("%x\n", add);

    WORD sockVersion = MAKEWORD(2, 2);
    WSADATA wsaData;
    WSAStartup(sockVersion, &wsaData);

    int sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
    sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(PORT);

    sendto(sock, buffer, sizeof(buffer), 0, (sockaddr*)&addr, sizeof(addr));
}