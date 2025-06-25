#include "parser.h"
#include <stdio.h>
#include <stdlib.h>

// print program correct usage and exit
static void usage(const char *program) {
  fprintf(stderr, "Usage: %s <addr> <port>", program);
  exit(EXIT_FAILURE);
}

// parse command line arguments
Params parse_args(int argc, char **argv) {
  // check min arguments number
  if (argc < 3) {
    usage(argv[0]);
  }

  // set param values
  Params p;
  p.addr_str = argv[1];
  p.port_str = argv[2];

  return p;
}
