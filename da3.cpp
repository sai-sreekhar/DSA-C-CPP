#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>

// Function to get IP address by hostname
void getAddressByHostName(const char *hostname)
{
    struct hostent *hostEntry = gethostbyname(hostname);

    // Error handling
    if (hostEntry == nullptr)
    {
        herror("gethostbyname");
        return;
    }

    printf("Official name is: %s\n", hostEntry->h_name);
    printf("IP address: %s\n", inet_ntoa(*(struct in_addr *)hostEntry->h_addr));

    printf("All addresses: ");
    struct in_addr **addrList = (struct in_addr **)hostEntry->h_addr_list;

    // Loop through all addresses in the address list
    for (int i = 0; addrList[i] != nullptr; i++)
    {
        printf("%s\n", inet_ntoa(*addrList[i]));
    }
    printf("\n");
}

// Function to get hostname by IP address
void getHostByAddress(const char *address)
{
    struct in_addr addr;
    inet_aton(address, &addr);
    struct hostent *hostEntry = gethostbyaddr(&addr, sizeof(addr), AF_INET);

    if (hostEntry == nullptr)
    {
        printf("error\n");
        return;
    }

    printf("Official name is: %s\n", hostEntry->h_name);
    printf("IP address: %s\n", inet_ntoa(*(struct in_addr *)hostEntry->h_addr));

    printf("All addresses: ");
    struct in_addr **addrList = (struct in_addr **)hostEntry->h_addr_list;

    // Loop through all addresses in the address list
    for (int i = 0; addrList[i] != nullptr; i++)
    {
        printf("%s\n", inet_ntoa(*addrList[i]));
    }
    printf("\n");
}

int main()
{
    const char hostname[] = "yahoo.com";
    const char address[] = "202.165.107.50";

    // Get IP address by hostname
    getAddressByHostName(hostname);
    printf("\n\n");

    // Get hostname by IP address
    getHostByAddress(address);

    return 0;
}
