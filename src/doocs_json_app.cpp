#include <iostream>

#include "doocs_json.h"

void print_usage() {
  std::cerr << "usage: doocs_json_app get "
            << "doocs://host:rpcnum/facility/device/location/property"
            << std::endl
            << "or     doocs_json_app names "
            << "doocs://host:rpcnum/facility/device/location/*"
            << std::endl;
}

int main(int argc, char *argv[]) {
  if (argc != 3 && argc != 4) {
    print_usage();
    return -1;
  }
  std::string cmd = argv[1];
  if (cmd == "get") {
    std::cout << get_property(argv[2]) << std::endl;
  } else if (cmd == "set") {
    std::cout << set_property(argv[2],
                              nlohmann::json::parse(argv[3]))
              << std::endl;
  } else if (cmd == "names") {
    std::cout << list_names(argv[2]) << std::endl;
  } else {
    print_usage();
    return -1;
  }
  return 0;
}