#ifndef LIGHT_CONTAINER_H
#define LIGHT_CONTAINER_H

#include "../src/container.cpp"

class Light_container : public Container
{
public:
    /* ---- Constructors ---- */
    Light_container() = default;
    Light_container(float, float, int);
    Light_container(float, float, int, Container_type);
    Light_container(const Light_container &);

    /* ---- Functions ---- */
    std::string show_container_data();

private:
    float discount{0.20};

    /* ---- Functions ---- */
    double calc_cost() const;
    double calc_discount() const;
};

#endif //! LIGHT_CONTAINER_H