#ifndef CONTAINER_H
#define CONTAINER_H

#include <sstream>
#include <string>
#include <vector>
#include <random>
#include <stdexcept> // for std::runtime_error
#include <algorithm> // for std::generate_n

typedef std::vector<char> char_array;

typedef enum
{
    LIGHT,
    HEAVY,
    REFRIGERATED,
    LIQUID,
    NONE
} Container_type;

class Container
{
public:
    /* ---- Destructors ---- */
    virtual ~Container();

    /* ---- Access Methods ---- */
    std::string get_id() const;
    float get_weight() const;
    int get_max_time() const;
    Container_type get_type() const;

    /* ---- Operator overloading ---- */
    bool operator==(const Container *);
    bool operator==(const Container &);
    bool operator<(const Container *);
    bool operator<(const Container &);

    /* ---- Public Functions ---- */
    virtual std::string show_container_data() = 0;

protected:
    const size_t id_size{8};
    int c_rate{}, max_time{};
    std::string c_id{};

    float c_weight{}, c_width{2.43}, c_height{2.59},
        c_length_short{6.06}, c_length_long{12.2},
        c_time;

    Container_type c_type{};
    static inline size_t object_count{1};

    /* ---- Constructors ---- */
    Container() = default;
    Container(float, float, int);
    Container(float, float, int, Container_type);
    Container(const Container &);          // copy constructor
    Container(const Container *) = delete; // deleted constructor

    /* ---- Protected Functions ---- */
    double get_volume() const;
    double get_area() const;
    virtual double calc_cost() const = 0;
    char_array charset();
    std::string generated_id();
    const char *enum_to_string(Container_type) noexcept(false);
};

#endif //! CONTAINER_H