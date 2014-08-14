#ifndef ORIENTATION_GUARD
#define ORIENTATION_GUARD

#include <memory>

#include "window.h"
#include "element.h"

namespace ncurses
{
    class Orientation
    {
        public:
            Orientation () = default;

            virtual int get_primary_coordinate ( std::shared_ptr < Window > target ) = 0;
            virtual int get_primary_coordinate ( std::shared_ptr < Window_dummy > target ) = 0;
            virtual int get_secondary_coordinate ( std::shared_ptr < Window > target ) = 0;
            virtual int get_secondary_coordinate ( std::shared_ptr < Window_dummy > target ) = 0;

            virtual int get_primary_length ( std::shared_ptr < Window > target ) = 0;
            virtual int get_primary_length ( std::shared_ptr < Window_dummy > target ) = 0;
            virtual int get_secondary_length ( std::shared_ptr < Window > target ) = 0;
            virtual int get_secondary_length ( std::shared_ptr < Window_dummy > target ) = 0;

            virtual void set_primary_coordinate ( std::shared_ptr < Window_dummy > target, int value ) = 0;
            virtual void set_secondary_coordinate ( std::shared_ptr < Window_dummy > target, int value ) = 0;
            virtual void set_primary_length ( std::shared_ptr < Window_dummy > target, int value ) = 0;
            virtual void set_secondary_length ( std::shared_ptr < Window_dummy > target, int value ) = 0;

            virtual int get_prefered_length ( std::shared_ptr < Element > target ) = 0;

            virtual ~Orientation () = default;
    };

    class Vertical : public Orientation
    {
        public:

            virtual int get_primary_coordinate ( std::shared_ptr < Window > target )
                { return target->get_y (); }
            virtual int get_primary_coordinate ( std::shared_ptr < Window_dummy > target )
                { return target->y; }
            virtual int get_secondary_coordinate ( std::shared_ptr < Window > target )
                { return target->get_x (); }
            virtual int get_secondary_coordinate ( std::shared_ptr < Window_dummy > target )
                { return target->x; }

            virtual int get_primary_length ( std::shared_ptr < Window > target )
                { return target->get_height (); }
            virtual int get_primary_length ( std::shared_ptr < Window_dummy > target )
                { return target->height; }
            virtual int get_secondary_length ( std::shared_ptr < Window > target )
                { return target->get_width (); }
            virtual int get_secondary_length ( std::shared_ptr < Window_dummy > target )
                { return target->width; }

            virtual void set_primary_coordinate ( std::shared_ptr < Window_dummy > target, int value )
                { target->y = value; }
            virtual void set_secondary_coordinate ( std::shared_ptr < Window_dummy > target, int value )
                { target->x = value; }
            virtual void set_primary_length ( std::shared_ptr < Window_dummy > target, int value )
                { target->height = value; }
            virtual void set_secondary_length ( std::shared_ptr < Window_dummy > target, int value )
                { target->width = value; }

            virtual int get_prefered_length ( std::shared_ptr < Element > target )
                { return target->get_prefered_height (); }

            virtual ~Vertical () = default;
    };

    class Horizontal : public Orientation
    {
        public:

            virtual int get_primary_coordinate ( std::shared_ptr < Window > target )
                { return target->get_x (); }
            virtual int get_primary_coordinate ( std::shared_ptr < Window_dummy > target )
                { return target->x; }
            virtual int get_secondary_coordinate ( std::shared_ptr < Window > target )
                { return target->get_y (); }
            virtual int get_secondary_coordinate ( std::shared_ptr < Window_dummy > target )
                { return target->y; }

            virtual int get_primary_length ( std::shared_ptr < Window > target )
                { return target->get_width (); }
            virtual int get_primary_length ( std::shared_ptr < Window_dummy > target )
                { return target->width; }
            virtual int get_secondary_length ( std::shared_ptr < Window > target )
                { return target->get_height (); }
            virtual int get_secondary_length ( std::shared_ptr < Window_dummy > target )
                { return target->height; }

            virtual void set_primary_coordinate ( std::shared_ptr < Window_dummy > target, int value )
                { target->x = value; }
            virtual void set_secondary_coordinate ( std::shared_ptr < Window_dummy > target, int value )
                { target->y = value; }
            virtual void set_primary_length ( std::shared_ptr < Window_dummy > target, int value )
                { target->width = value; }
            virtual void set_secondary_length ( std::shared_ptr < Window_dummy > target, int value )
                { target->height = value; }

            virtual int get_prefered_length ( std::shared_ptr < Element > target )
                { return target->get_prefered_width (); }

            virtual ~Horizontal () = default;
    };
}

#endif