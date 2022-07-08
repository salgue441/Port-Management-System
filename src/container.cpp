#pragma once

#include "../headers/container.h"

/* ---- Constructors ---- */
Container::Container() : c_id(0), c_weight(0.0), c_type(NONE){};

Container::Container(int id, float weight) : c_id(id), c_weight(weight){};

Container::Container(int id, float weight, Container_type type)
    : c_id(id), c_weight(weight), c_type(type){};

Container::Container(const Container &new_container)
{
    c_id = new_container.c_id;
    c_weight = new_container.c_weight;
    c_type = new_container.c_type;
};

/* ---- Destructor ---- */
Container::~Container()
{
    --object_count;
}

/* ---- Access Methods ---- */
int Container::get_id() const { return c_id; }
float Container::get_weight() const { return c_weight; }
Container_type Container::get_type() const { return c_type; }

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

/* ---- Functions ---- */
/*
 * Calculates the cubic volume of the container according to its type.
 * If the container's type equals 'LIGHT' it will use the shorter length
 * value, otherwise length_2 will be used. It's a private function
 * because it can only be called from the members of the class.
 * params:
 *   - type: from the enumerated list.
 * return:
 *   - the volume of the container
 */
double Container::get_volume(Container_type type) const
{
    if (type == LIGHT)
        return 2 * (c_width * c_length_short * c_height);
    else if (type == NONE)
        return 0.0;

    return 2 * (c_width * c_length_long * c_height);
}

/*
 * Calculates the cubic volume of the container according to its type.
 * If the container's type equals 'LIGHT' it will use the shorter length
 * value, otherwise length_2 will be used. It's a private function
 * because it can only be called from the members of the class.
 * params:
 *   - type: from the enumerated list.
 * return:
 *   - the volume of the container
 */
double Container::get_area(Container_type type) const
{
    if (type == LIGHT)
        return c_width * c_length_short;
    else if (type == NONE)
        return 0.0;

    return c_width * c_length_long;
}

/*
 * Calculates the rate at which the container is used.
 * params:
 *   - type: from the enumerated list.
 * return:
 *   - returns the total cost for renting or using the container.
 */
double Container::get_cost(Container_type type) const
{
    double cost{};
}

/*
 * Shows the area and volume of the desired container.
 * params: no parameters.
 * return: returns the data stream as a string
 */
std::string Container::show_needed_space()
{
    std::stringstream needed_space;

    needed_space << "According to the calculations "
                 << "based on the container's type, " << c_type
                 << ", it will take "
                 << get_area(c_type) << " squared meters from the ship"
                 << ", and the total volume is: " << get_volume(c_type)
                 << std::endl;

    return needed_space.str();
}