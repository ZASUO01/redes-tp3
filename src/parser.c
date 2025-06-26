#include "parser.h"
#include "logger.h"

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
