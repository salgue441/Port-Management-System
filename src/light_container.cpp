#include "../headers/light_container.h"

// Constructors
Light_container::Light_container(float weight, float usage, int rate)
    : Container(weight, usage, rate){};
Light_container::Light_container(float weight, float usage, int rate,
                                 Container_type type)
    : Container(weight, usage, rate, type){};
Light_container::Light_container(const Light_container &other)
    : Container(other){};

// Functions
/**
 * @brief
 * Private function. Calculates the cost of the available discount
 * (if any) for the container.
 * @return double
 */
double Light_container::calc_discount() const
{
    return (c_time * get_area() * discount);
}

/**
 * @brief
 * Private Function. Calculates the cost of usage of this
 * container type.
 * No parameters needed
 * @return double
 */
double Light_container::calc_cost() const
{
    return ((get_area() * c_time) + c_rate) - calc_discount();
}

/**
 * @brief
 * Shows the container associated data.
 * No parameters needed.
 * @return std::string
 */
std::string Light_container::show_container_data()
{
    std::stringstream container_data;

    container_data << "Showing the container's technical specifications: "
                   << "\n - Container's type: " << enum_to_string(c_type)
                   << "\n - Container's id: " << c_id
                   << "\n - Container's rate: " << c_rate << " USD"
                   << "\n - Container's weight: " << c_weight << "kg"
                   << "\n - Container's area: " << get_area()
                   << " squared meters"
                   << "\n - Container's capacity: " << get_volume()
                   << " cubic meters"
                   << "\n - Time to be used: " << c_time << " hours"
                   << "\n - Available discount: " << calc_discount()
                   << " USD."
                   << "\n - Total cost of usage (before discount): "
                   << (get_area() * c_time) + c_rate << " USD"
                   << "\n - Total cost of usage (after discount): "
                   << calc_cost() << " USD"
                   << std::endl;

    return container_data.str();
}