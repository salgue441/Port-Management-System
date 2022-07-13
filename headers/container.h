#ifndef CONTAINER_H
#define CONTAINER_H

#include <sstream>
#include <string>
#include <vector>
#include <random>
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
    ~Container() = default;

    /* ---- Access Methods ---- */
    std::string get_id() const;
    float get_weight() const;
    Container_type get_type() const;

    /* ---- Operator overloading ---- */
    bool operator==(const Container *);
    bool operator==(const Container &);
    bool operator<(const Container *);
    bool operator<(const Container &);

    /* ---- Public Functions ---- */
    std::string show_needed_space();
    double get_consumption() const;

protected:
    const size_t id_size{8};
    std::string c_id;
    float c_weight{}, c_width{2.43}, c_height{2.59}, c_length_short{6.06},
        c_length_long{12.2};
    Container_type c_type{};
    static inline size_t object_count{};

public: // delete
    /* ---- Constructors ---- */
    Container() = default;
    Container(float);
    Container(float, Container_type);
    Container(const Container &);          // copy constructor
    Container(const Container *) = delete; // deleted constructor

protected: // delete
    /* ---- Protected Functions ---- */
    double get_volume(Container_type) const;
    double get_area(Container_type) const;
    double get_cost(Container_type, float) const;
    char_array charset();
    std::string generated_id();
};

#endif //! CONTAINER_H