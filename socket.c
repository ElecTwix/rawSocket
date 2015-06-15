#include "socket.h"

// Raw Socket
typedef struct {
        int fd;
        struct sockaddr_in addr;
} socket_t;

// UDP RAW packet
typedef struct {
        char *data;
        size_t len;
} udp_packet_t;


int main(int argc, char *argv[])
{
        return EXIT_SUCCESS;
}

// Create a socket
socket_t *socket_create()
{
        socket_t *sock = malloc(sizeof(socket_t));
        if (sock == NULL) {
                return NULL;
        }
        sock->fd = socket(AF_INET, SOCK_STREAM, 0);
        if (sock->fd == -1) {
                free(sock);
                return NULL;
        }
        return sock;
}


udp_packet_t *udp_packet_create()
{
        udp_packet_t *packet = malloc(sizeof(udp_packet_t));
        if (packet == NULL) {
                return NULL;
        }
        packet->data = malloc(UDP_MAX_PACKET_SIZE);
        if (packet->data == NULL) {
                free(packet);
                return NULL;
        }
        return packet;
}


void send_udp_packet(socket_t *sock, udp_packet_t *packet)
{
        sendto(sock->fd, packet->data, packet->len, 0, (struct sockaddr *)&sock->addr, sizeof(sock->addr));
}
