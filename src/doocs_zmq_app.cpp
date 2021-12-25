#include "doocs_zmq.h"
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "must be at least 1 argument" << std::endl;
    return 1;
  }
  std::string host = argv[1];

  auto connection = connect_to_zmq(host);

  std::string request_string;
  while (true) {
    if (connection.sub_socket.receive(request_string)) {
      nlohmann::json request = nlohmann::json::parse(request_string);
      if (request["origin"] == "doocs") {
        continue;
      }
      nlohmann::json response = respond_magix(request);
      std::string response_string = response.dump();
      connection.push_socket.send(response_string);
    }
  }
}