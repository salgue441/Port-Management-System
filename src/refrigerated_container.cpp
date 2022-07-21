#include "../headers/refrigerated_container.h"

// Constructors
Refrigerated_container::Refrigerated_container(float weight,
                                               float usage, int rate)
    : Container(weight, usage, rate){};
Refrigerated_container::Refrigerated_container(float weight, float usage,
                                               int rate,
                                               Container_type type)
    : Container(weight, usage, rate, type){};
Refrigerated_container::Refrigerated_container(
    const Refrigerated_container &other) : Container(other){};

// Functions
/**
 * @brief
 * Private Function. Calculates how much the container refrigeration
 * cost will be.
 * @return double
 */
double Refrigerated_container::calc_refrigeration_costs() const
{
    if (!calc_gas_consumption())
        return (c_time * refrigeration_rate);

    return 0.0;
}

double Refrigerated_container::calc_gas_consumption() const
{
    return 0.0;
}

double Refrigerated_container::calc_cost() const
{
    return ((get_area() * c_time) + c_rate) + calc_refrigeration_costs();
}

/**
 * @brief
 * Shows the containers data. No parameters needed
 * @return std::string
 */
std::string Refrigerated_container::show_container_data()
{
    std::stringstream container_data;

    container_data << "Showing the container's technical specifications: "
                   << "\n - Container's type: " << enum_to_string(c_type)
                   << "\n - Container's id: " << c_id
                   << "\n - Container's rate: " << c_rate << " USD"
                   << "\n - Container's weight: " << c_weight << " kg"
                   << "\n - Max capacity for gas (AC unit): " << max_gas
                   << "\n - Current gas: "
                   << "\n - Container's area: " << get_area()
                   << " squared meters"
                   << "\n - Container's capacity: " << get_volume()
                   << " cubic meters"
                   << "\n - Time to be used: " << c_time << " hours"
                   << "\n - Refrigeration cost: "
                   << calc_refrigeration_costs() << " USD."
                   << "\n - Total cost of usage (before refrigeration costs): "
                   << (get_area() * c_time) + c_rate << " USD"
                   << "\n - Total cost of usage (after refrigeration costs): "
                   << calc_cost() << " USD"
                   << std::endl;

    return container_data.str();
}