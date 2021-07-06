//
// Created by Alexander Nozik on 04.07.2021.
//

#include <stdatomic.h>

#include "doocs_json.h"

#ifndef BUILDDIR_DOOCS_ZMQ_H
#define BUILDDIR_DOOCS_ZMQ_H

#endif  // BUILDDIR_DOOCS_ZMQ_H

/**
 *
 * @param host the host address of the magix loop
 * @param active flag to be set flipped to finish the client loop
 * @param pub_port magix host subscription  port
 * @param pull_port magix host broadcast port
 */
void start_zmq_magix_client(std::string host, atomic_bool active = true, int pub_port = 7781, int pull_port = 7782);