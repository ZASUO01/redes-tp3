// file:        network.h
// description: definitions of network useful functions
#ifndef NETWORK_H
#define NETWORK_H

#include <sys/socket.h>

int parse_addr(const char *addr_str, const char *port_str,
               struct sockaddr_storage *storage);

#endif
