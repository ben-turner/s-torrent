#ifndef CONNECTION_RECEIVER_GUARD
#define CONNECTION_RECEIVER_GUARD

#include "wrappers/sockets/client_socket.h"
#include "event_types/event.h"
#include "receiver.h"

#include <memory>
#include <string>
#include <thread>

namespace events
{
    class Connection_receiver : public Receiver < std::shared_ptr < Event > >
    {
        public:
            Connection_receiver ( std::string address, int port );
            Connection_receiver ( sockets::Client_socket&& socket );

            void start ();
            void receive ( std::shared_ptr < Event > );
            void listen_on_socket ();
            void disconnect ();

            virtual ~Connection_receiver () noexcept;

        private:
            std::unique_ptr < sockets::Client_socket > connection;
            bool connected;
            std::thread listening_thread;
    };
}

#endif //CONNECTION_RECEIVER_GUARD
