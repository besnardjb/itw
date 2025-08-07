#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;
    /* TODO Print content of google.com font-page on stdout */


    /* Get address of google.com */
    struct addrinfo hints;
    struct addrinfo *res = NULL;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;

    if (getaddrinfo("google.com", "http", &hints, &res) != 0) {
        perror("getaddrinfo");
        return 1;
    }

    int sock = -1;

    for(struct addrinfo *p = res; p != NULL; p = p->ai_next) {
        sock = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sock == -1) {
            perror("socket");
            continue;
        }

        if (connect(sock, p->ai_addr, p->ai_addrlen) == 0) {
            printf("Connected to google.com\n");
            break;
        }

        close(sock);
        sock = -1;
    }

    freeaddrinfo(res);

    if (sock == -1) {
        fprintf(stderr, "Failed to connect\n");
        return 1;
    }

    /* TODO Send HTTP request */

    /* TODO Read response */


    close(sock);

    return 0;
}