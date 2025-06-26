#include "logger.h"
#include <stdio.h>
#include <stdlib.h>

// print program correct usage and exit
void usage(const char *program) {
  fprintf(stderr, "Usage: %s <addr> <port>", program);
  exit(EXIT_FAILURE);
}
// finish program due failure
void log_exit(const char *msg) {
  fprintf(stderr, "%s\n", msg);
  exit(EXIT_FAILURE);
}
