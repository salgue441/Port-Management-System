#ifndef CONTAINER_H
#define CONTAINER_H

#include <sstream>

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
    virtual ~Container() = default;

    /* ---- Access Methods ---- */
    int get_id() const;
    float get_weight() const;
    Container_type get_type() const;

    /* ---- Operator overloading ---- */
    bool operator==(const Container *);
    bool operator==(const Container &);
    bool operator<(const Container *);
    bool operator<(const Container &);

    /* ---- Public Functions ---- */
    std::string show_needed_space();
    virtual double get_consumption() const = 0;

protected:
    int c_id{};
    float c_weight{}, c_width{2.43}, c_height{2.59}, c_length_short{6.06},
        c_length_long{12.2};
    Container_type c_type{};
    static inline size_t object_count{};

    /* ---- Constructors ---- */
    Container() = default;
    Container(int, float);
    Container(int, float, Container_type);
    Container(const Container &);          // copy constructor
    Container(const Container *) = delete; // deleted constructor

    /* ---- Protected Functions ---- */
    double get_volume(Container_type) const;
    double get_area(Container_type) const;
    double get_cost(Container_type) const;
};

#endif //! CONTAINER_H