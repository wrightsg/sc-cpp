#ifndef SC_CPP_TURTLE_INTERFACE_H
#define SC_CPP_TURTLE_INTERFACE_H

class turtle_interface
{
public:
    virtual ~turtle_interface () = default;

    virtual void pen_up () = 0;
    virtual void pen_down () = 0;
    virtual void forward (int distance) = 0;
    virtual void turn (int degrees) = 0;
    virtual void go_to (int x, int y) = 0;
    virtual int get_x () const = 0;
    virtual int get_y () const = 0;
};

#endif //SC_CPP_TURTLE_INTERFACE_H
