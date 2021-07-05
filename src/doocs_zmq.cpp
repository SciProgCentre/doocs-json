//
// Created by altavir on 04.07.2021.
//

#include "doocs_zmq.h"

#include <iostream>
#include <string>
#include <zmqpp/zmqpp.hpp>

using namespace std;

void start_zmq_magix_client(string host, int sub_port, int push_port) {
  // initialize the 0MQ context
  zmqpp::context context;

  // generate a sub socket
  zmqpp::socket sub_socket(context, zmqpp::socket_type::subscribe);

  // open the subscription connection
  const string sub_endpoint = host + ":" + to_string(sub_port);
  cout << "Opening subscription connection to " << sub_endpoint << "..."
       << endl;
  sub_socket.connect(sub_endpoint);
  sub_socket.subscribe("");

  // generate a push socket
  zmqpp::socket push_socket(context, zmqpp::socket_type::push);

  // open the push connection
  const string push_endpoint = host + ":" + to_string(push_port);
  cout << "Opening push connection to " << push_endpoint << "..." << endl;
  push_socket.connect(push_endpoint);

  string request_string;
  while (true) {
      if (sub_socket.receive(request_string)) {
        nlohmann::json request = nlohmann::json::parse(request_string);
        nlohmann::json response = respond_magix(request);
        string response_string = response.dump();
        push_socket.send(response_string);
      }
  }

  //  // send a request_string
  //  cout << "Sending text and a number..." << endl;
  //  zmqpp::request_string request_string;
  //  // compose a request_string from a string and a number
  //  request_string << "Hello World!" << 42;
  //  socket.send(request_string);
  //
  //  cout << "Sent request_string." << endl;
  //  cout << "Finished." << endl;
}