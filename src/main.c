#include "logger.h"
#include "network.h"
#include "parser.h"
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char **argv) {
  // parse command line arguments
  Params p = parse_args(argc, argv);

  // parse the known ip addr
  struct sockaddr_storage storage;
  if (parse_addr(p.addr_str, p.port_str, &storage) != 0) {
    log_exit("addr parsing failure");
  }
  struct sockaddr *addr = (struct sockaddr *)&storage;

  // create tcp socket
  int sock_fd = socket(storage.ss_family, SOCK_STREAM, 0);
  if (sock_fd < 0) {
    log_exit("socket creation failure");
  }

  // conect to the known peer
  if (connect(sock_fd, addr, sizeof(storage)) != 0) {
    log_exit("connect failure");
  }

  close(sock_fd);
  return 0;
}
