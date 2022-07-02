#ifndef CONTAINER_H
#define CONTAINER_H

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
    /* ---- Constructors ---- */
    Container();
    Container(int, float, Container_type);
    Container(const Container &);

    /* ---- Access Methods ---- */
    int get_id();
    float get_weight();
    Container_type get_type();

    /* ---- Operator overloading ---- */
    bool operator==(const Container *);
    bool operator==(const Container &);
    bool operator<(const Container *);
    bool operator<(const Container &);

    /* ---- Functions ---- */
    virtual double get_space() = 0;

protected:
    int c_id;
    float c_weight, width = 2.43, hight = 2.59,
                    length_1 = 6.06, length_2 = 12.2;
    Container_type c_type;
};

#endif //! CONTAINER_H