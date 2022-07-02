#pragma once

#include "../headers/container.h"

/* ---- Constructors ---- */
Container::Container() : c_id(0), c_weight(0.0), c_type(NONE){};

Container::Container(int id, float weight, Container_type type)
    : c_id(id), c_weight(weight), c_type(type){};

Container::Container(const Container &new_container)
{
    c_id = new_container.c_id;
    c_weight = new_container.c_weight;
    c_type = new_container.c_type;
};

/* ---- Access Methods ---- */
int Container::get_id() { return c_id; }
float Container::get_weight() { return c_weight; }
Container_type Container::get_type() { return c_type; }

/* ---- Operator Overloading ---- */
bool Container::operator==(const Container *other)
{
    if (c_id == other->c_id &&
        c_weight == other->c_weight &&
        c_type == other->c_type)
        return true;

    return false;
}

bool Container::operator==(const Container &other)
{
    if (c_id == other.c_id &&
        c_weight == other.c_weight &&
        c_type == other.c_type)
        return true;

    return false;
}

bool Container::operator<(const Container *other)
{
    if (c_type == other->c_type &&
        c_id < other->c_id)
        return true;

    else if (c_type != other->c_type &&
             c_id < other->c_id)
        return true;

    return false;
}

bool Container::operator<(const Container &other)
{
    if (c_type == other.c_type &&
        c_id < other.c_id)
        return true;

    else if (c_type != other.c_type &&
             c_id < other.c_id)
        return true;

    return false;
}
