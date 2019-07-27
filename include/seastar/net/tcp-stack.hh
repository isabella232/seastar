/*
 * This file is open source software, licensed to you under the terms
 * of the Apache License, Version 2.0 (the "License").  See the NOTICE file
 * distributed with this work for additional information regarding copyright
 * ownership.  You may not use this file except in compliance with the License.
 *
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */
/*
 * Copyright (C) 2014 Cloudius Systems, Ltd.
 */

// tcp/network-stack integration

#pragma once

#include <seastar/core/future.hh>
#include "../core/internal/api-level.hh"

namespace seastar {

struct listen_options;
SEASTAR_INCLUDE_API_V1 namespace api_v1 { class server_socket; }
SEASTAR_INCLUDE_API_V2 namespace api_v2 { class server_socket; }
class connected_socket;

namespace net {

struct ipv4_traits;
template <typename InetTraits>
class tcp;

server_socket
tcpv4_listen(tcp<ipv4_traits>& tcpv4, uint16_t port, listen_options opts);

seastar::socket
tcpv4_socket(tcp<ipv4_traits>& tcpv4);

}

}
