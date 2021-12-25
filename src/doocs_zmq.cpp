//
// Created by altavir on 04.07.2021.
//

#include "doocs_zmq.h"

#include <string>

using namespace std;

ZmqConnection connect_to_zmq(const zmqpp::context& context, const std::string& host, int pub_port, int pull_port) {

  zmqpp::socket sub_socket(context, zmqpp::socket_type::subscribe);
  const string sub_endpoint = host + ":" + to_string(pub_port);
  sub_socket.connect(sub_endpoint);
  sub_socket.subscribe("");

  zmqpp::socket push_socket(context, zmqpp::socket_type::push);
  const string push_endpoint = host + ":" + to_string(pull_port);
  push_socket.connect(push_endpoint);

  return {
      std::move(sub_socket),
      std::move(push_socket)
  };
}