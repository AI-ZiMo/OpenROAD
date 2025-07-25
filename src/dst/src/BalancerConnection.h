// SPDX-License-Identifier: BSD-3-Clause
// Copyright (c) 2021-2025, The OpenROAD Authors

#pragma once
#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/make_shared.hpp>
#include <cstddef>

namespace utl {
class Logger;
}
namespace dst {

namespace asio = boost::asio;
using asio::ip::tcp;

class LoadBalancer;

class BalancerConnection
    : public boost::enable_shared_from_this<BalancerConnection>
{
 public:
  using Pointer = boost::shared_ptr<BalancerConnection>;
  BalancerConnection(asio::io_context& service,
                     LoadBalancer* owner,
                     utl::Logger* logger);
  static Pointer create(asio::io_context& service,
                        LoadBalancer* owner,
                        utl::Logger* logger)
  {
    return boost::make_shared<BalancerConnection>(service, owner, logger);
  }
  tcp::socket& socket();
  void start();
  void handle_read(boost::system::error_code const& err,
                   size_t bytes_transferred);
  LoadBalancer* getOwner() const { return owner_; }

 private:
  tcp::socket sock_;
  asio::streambuf in_packet_;
  utl::Logger* logger_;
  LoadBalancer* owner_;
  static const int kMaxFailedWorkersTrials = 3;
  static const int kMaxBroadcastFailedNodes = 2;
};
}  // namespace dst
