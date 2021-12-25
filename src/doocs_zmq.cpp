//
// Created by altavir on 04.07.2021.
//

#include "doocs_zmq.h"

#include <iostream>
#include <string>
#include <zmqpp/zmqpp.hpp>

using namespace std;

[[noreturn]] void start_zmq_magix_client(const string &host, int pub_port, int pull_port) {
  // initialize the 0MQ context
  zmqpp::context context;

  // generate a sub socket
  zmqpp::socket sub_socket(context, zmqpp::socket_type::subscribe);

  // open the subscription connection
  const string sub_endpoint = host + ":" + to_string(pub_port);
  cout << "Opening subscription connection to " << sub_endpoint << "..."
       << endl;
  sub_socket.connect(sub_endpoint);
  sub_socket.subscribe("");

  // generate a push socket
  zmqpp::socket push_socket(context, zmqpp::socket_type::push);

  // open the push connection
  const string push_endpoint = host + ":" + to_string(pull_port);
  cout << "Opening push connection to " << push_endpoint << "..." << endl;
  push_socket.connect(push_endpoint);

  string request_string;
  while (true) {
    if (sub_socket.receive(request_string)) {
      nlohmann::json request = nlohmann::json::parse(request_string);
      if (request["origin"] == "doocs") {
        continue;
      }
      nlohmann::json response = respond_magix(request);
      string response_string = response.dump();
      push_socket.send(response_string);
    }
  }
}