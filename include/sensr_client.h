#ifndef SENSR_CLIENT_H
#define SENSR_CLIENT_H

#include <zmq.hpp>
#include "output.pb.h"
#include "labels.pb.h"

namespace sensr
{
class Client
{
public:
  Client(const char *address);
  ~Client();
  bool ReceiveMessageAsync(OutputMessage &message);
  bool ReceiveMessage(OutputMessage &message);

private:
  zmq::context_t context_;
  zmq::socket_t subscriber_;
};
} // namespace sensr

#endif // SENSR_CLIENT_H