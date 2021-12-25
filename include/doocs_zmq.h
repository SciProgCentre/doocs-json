//
// Created by Alexander Nozik on 04.07.2021.
//

#ifndef BUILDDIR_DOOCS_ZMQ_H
#define BUILDDIR_DOOCS_ZMQ_H

#include "doocs_json.h"
#include <zmqpp/zmqpp.hpp>

struct ZmqConnection {
  zmqpp::socket sub_socket;
  zmqpp::socket push_socket;
};

/**
 *
 * @param host the host address of the magix loop
 * @param active flag to be set flipped to finish the client loop
 * @param pub_port magix host subscription port
 * @param pull_port magix host broadcast port
 * @return connection data
 */
ZmqConnection connect_to_zmq(const zmqpp::context& context, const std::string& host, int pub_port = 7781, int pull_port = 7782);

#endif  // BUILDDIR_DOOCS_ZMQ_H
