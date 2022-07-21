#ifndef REFRIGERATED_CONTAINER_H
#define REFRIGERATED_CONTAINER_H

#include "../src/container.cpp"

class Refrigerated_container : public Container
{
public:
    /* ---- Constructors ---- */
    Refrigerated_container() = default;
    Refrigerated_container(float, float, int);
    Refrigerated_container(float, float, int, Container_type);
    Refrigerated_container(const Refrigerated_container &);

    /* ---- Functions ---- */
    std::string show_container_data();

private:
    float refrigeration_rate{15.14};
    double gas_consumption_hr{16.5}, max_gas{200}, current_gas{0.0};
    int max_time{250};

    /* ---- Functions ---- */
    int calculate_times_passed() const;
    double calc_refrigeration_costs() const;
    double calc_gas_consumption() const;
    double calc_cost() const;
};

#endif //! REFRIGERATED_CONTAINER_H