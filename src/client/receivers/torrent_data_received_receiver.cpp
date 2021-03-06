#include "torrent_data_received_receiver.h"

#include "utils/json.h"
#include "client/shared_data.h"
#include "client/torrent_data.h"
#include "client/events/events.h"
#include "events/hub.h"
#include "events/events.h"

#include <vector>
#include <thread>
#include <chrono>
#include <functional>

namespace client
{
    void Torrent_data_received_receiver::receive ( std::shared_ptr < events::Event > event )
    {
        if ( event->get_type () == "Torrent_data_received_event" )
        {
            auto torrent_data_received_event = std::dynamic_pointer_cast < Torrent_data_received_event > ( event );
            utils::Json_list_element torrent_data  ( torrent_data_received_event->get_torrent_data_string () );

            // Create torrent_data
            auto new_torrent_data = std::make_shared < std::vector < std::shared_ptr < Torrent_data > > > ();
            for ( int i = 0; i < torrent_data.size (); i++ )
                new_torrent_data->push_back ( std::make_shared < Torrent_data > ( torrent_data.get_element ( i )->to_small_string () ) );

            // Put it into Shared_data
            client::Shared_data::set_torrent_data ( new_torrent_data );

            // Send another request to get the data periodicly
            auto delayed_request = [] ( events::Connection_receiver* origin ) {
                utils::Json_element torrent_data_request;
                torrent_data_request.set_string ( "type", "Torrent_data_requested_event" );
                std::this_thread::sleep_for ( std::chrono::seconds ( 3 ) );
                events::Hub::send ( std::make_shared < events::Send_message_event >
                        ( torrent_data_request.to_small_string (), origin ) );
            };
            std::thread request_thread ( delayed_request, torrent_data_received_event->get_origin () );
            request_thread.detach ();
        }
    }
}
