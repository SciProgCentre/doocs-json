#include "doocs_zmq.h"
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "must be at least 1 argument" << std::endl;
    return 1;
  }
  std::string host = argv[1];
  start_zmq_magix_client(host);
  return 0;
}