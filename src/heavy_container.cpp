#pragma once

#include "../headers/heavy_container.h"

/* ---- Constructors ---- */
Heavy_Container::Heavy_Container() : Container(){};

Heavy_Container::Heavy_Container(int id, float weight)
    : Container(id, weight, HEAVY){};

Heavy_Container::Heavy_Container(int id, float weight,
                                 Container_type type)
    : Container(id, weight, type){};

Heavy_Container::Heavy_Container(const Heavy_Container &other)
    : Container(other){};

/* ---- Functions ---- */
double Heavy_Container::get_space()
{
    int space = 3 * c_weight;
    return space;
}