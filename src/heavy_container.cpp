#include "../headers/heavy_container.h"

/* ---- Constructors ---- */
Heavy_container::Heavy_container(float weight, float usage, int rate)
    : Container(weight, usage, rate){};
Heavy_container::Heavy_container(float weight, float usage, int rate,
                                 Container_type type)
    : Container(weight, usage, rate, type){};
Heavy_container::Heavy_container(const Container &other)
    : Container(other){};

/* ---- Access Methods ---- */
float Heavy_container::get_safety_plan_rate() const { return safety_plan; }

/* ---- Functions ---- */
/*
 * Private function. Calculates the cost of the 15% safety plan for these
 * container.
 * params: no parameter needed
 * return: returns the cost of the safetyplan
 */
double Heavy_container::calc_plan_cost() const
{
    return (c_time * get_area() * safety_plan);
}

/*
 * Private Function. Calculates the total cost of usage of
 * this container type.
 * params:
 *   - time: type const. The total time the container is going to
 *           be used.
 * return: returns the total cost of usage
 */
double Heavy_container::calc_cost() const
{
    return (get_area() * c_time) + calc_plan_cost() + c_rate;
}

/*
 * Shows the container associated data
 * params: no parameters needed.
 * return: returns de data stream as a string.
 */
std::string Heavy_container::show_container_data()
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
                   << "\n - Safety plan cost: " << calc_plan_cost()
                   << " USD."
                   << "\n - Total cost of usage (before safety plan): "
                   << (get_area() * c_time) + c_rate << " USD"
                   << "\n - Total cost of usage (with safety plan): "
                   << calc_cost() << " USD" << std::endl;

    return container_data.str();
}