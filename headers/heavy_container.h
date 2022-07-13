#ifndef HEAVY_CONTAINER_H
#define HEAVY_CONTAINER_H

#include "../src/container.cpp"

class Heavy_container : public Container
{
public:
    /* ---- Constructors ---- */
    Heavy_container() = default;
    Heavy_container(float, float, int);
    Heavy_container(float, float, int, Container_type);
    Heavy_container(const Container &);
    Heavy_container(const Container *) = delete;

    /* ---- Access Methods ---- */
    float get_safety_plan_rate() const;

    /* ---- Functions ---- */
    std::string show_container_data();

private:
    float safety_plan = 0.15;

    /* ---- Private Functions ---- */
    double calc_plan_cost() const;
    double calc_cost() const;
};

#endif //! HEAVY_CONTAINER_H