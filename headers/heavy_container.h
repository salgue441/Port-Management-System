#ifndef HEAVY_CONTAINER_H
#define HEAVY_CONTAINER_H

#include "../src/container.cpp"

class Heavy_Container : private Container
{
public:
    /* ---- Constructors ---- */
    Heavy_Container();
    Heavy_Container(int, float);
    Heavy_Container(int, float, Container_type);
    Heavy_Container(const Container &);

    /* ---- Functions ----- */
    double get_space();
};

#endif //! HEAVY_CONTAINER_H