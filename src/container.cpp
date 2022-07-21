#pragma once

#include "../headers/container.h"

/* ---- Constructors ---- */
Container::Container(float weight, float usage, int rate)
    : c_weight(weight), c_time(usage), c_rate(rate)
{
    c_id = generated_id();
    object_count += 1;
};

Container::Container(float weight, float usage, int rate, Container_type type)
    : c_weight(weight), c_time(usage), c_type(type), c_rate(rate)
{
    c_id = generated_id();
    object_count += 1;
};

Container::Container(const Container &new_container)
{
    object_count += 1;

    c_id = generated_id();

    c_weight = new_container.c_weight;
    c_type = new_container.c_type;
    c_id = new_container.c_id;
    c_rate = new_container.c_rate;
};

/* ---- Destructor ---- */
Container::~Container()
{
    object_count -= 1;
}

/* ---- Access Methods ---- */
std::string Container::get_id() const { return c_id; }
float Container::get_weight() const { return c_weight; }
int Container::get_max_time() const { return max_time; }
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
double Container::get_volume() const
{
    if (c_type == LIGHT)
        return 2 * (c_width * c_length_short * c_height);
    else if (c_type == NONE)
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
double Container::get_area() const
{
    if (c_type == LIGHT)
        return c_width * c_length_short;
    else if (c_type == NONE)
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
double Container::calc_cost() const
{
    return (c_time * get_area());
}

/*
 * Contains the needed characters for the string.
 * Based on "How do I create a random
 * alpha-numeric string in C++?" (Carl, 2012).
 * https://stackoverflow.com/questions/440133/how-do-i-create-a-random-alpha-numeric-string-in-c
 * params: no parameters needed
 * returns: an array of characters
 */
char_array Container::charset()
{
    return char_array(
        {'0', '1', '2', '3', '4',
         '5', '6', '7', '8', '9',
         'A', 'B', 'C', 'D', 'E', 'F',
         'G', 'H', 'I', 'J', 'K',
         'L', 'M', 'N', 'O', 'P',
         'Q', 'R', 'S', 'T', 'U',
         'V', 'W', 'X', 'Y', 'Z',
         'a', 'b', 'c', 'd', 'e', 'f',
         'g', 'h', 'i', 'j', 'k',
         'l', 'm', 'n', 'o', 'p',
         'q', 'r', 's', 't', 'u',
         'v', 'w', 'x', 'y', 'z'});
};

/*
 * Generates the Container's id. Based on "How do I create a random
 * alpha-numeric string in C++?" (Carl, 2012).
 * https://stackoverflow.com/questions/440133/how-do-i-create-a-random-alpha-numeric-string-in-c
 * params: no parameters needed
 * returns: the container's id
 */

std::string Container::generated_id()
{
    // creating the character set
    auto ch_set = charset();

    // non-deterministic random number generator
    std::default_random_engine rng(std::random_device{}());

    // random number "shaper", gives uniformly distributed indices
    // to the character set
    std::uniform_int_distribution<> dist(0, ch_set.size() - 1);

    /*
    lambda function: ties the non-deterministic distribution from
    the character set.
    */
    auto randchar = [ch_set, &dist, &rng]()
    { return ch_set[dist(rng)]; };

    // container's id
    std::string id(id_size, 0);
    std::generate_n(id.begin(), id_size, randchar);

    return id;
}

/**
 * @brief
 * Private function. Handles showing the container's type as a string
 * and not as an index.
 * @param type
 * @return constexpr const char*
 */
const char *Container::enum_to_string(Container_type type)
{
    switch (type)
    {
    case Container_type::LIGHT:
        return "LIGHT";

    case Container_type::HEAVY:
        return "HEAVY";

    case Container_type::REFRIGERATED:
        return "REFRIGERATED";

    case Container_type::LIQUID:
        return "LIQUID";

    case Container_type::NONE:
        return "NONE";

    default:
        std::runtime_error("No container exist with this type");
    }

    return "NONE";
}

/**
 * @brief
 * Shows the container associated data
 * @return std::string
 */
std::string Container::show_container_data()
{
    std::stringstream container_data;

    container_data << "Showing the container's technical specifications: "
                   << "\n - Container's type: " << enum_to_string(c_type)
                   << "\n - Container's id: " << c_id
                   << "\n - Container's rate: " << c_rate << " USD"
                   << "\n - Container's area: " << get_area()
                   << " squared meters"
                   << "\n - Container's capacity: " << get_volume()
                   << " cubic meters"
                   << "\n - Time to be used: " << c_time << " hours"
                   << "\n - Total cost of usage: " << calc_cost() << " USD"
                   << std::endl;

    return container_data.str();
}