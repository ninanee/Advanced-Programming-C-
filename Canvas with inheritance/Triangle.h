//
// Created by Yun Ni on 2021-07-25.
//

#ifndef INC_5421A4_TRIANGLE_H
#define INC_5421A4_TRIANGLE_H
#include "Shape.h"

class Triangle : public Shape
{
public:
    //default constructor
    Triangle(unsigned int height,unsigned int base, char pen, std::string name);

    //defaulted destructor (should be virtual)
    virtual ~Triangle() = default;

    //defaulted copy constructor
    Triangle (const Triangle&) = default;

    //defaulted assignment operator
    Triangle& operator = (const Triangle&) = default;


    //A method to compute and return the shape's geometric area;
    virtual double geoArea() const override;


};


#endif //INC_5421A4_TRIANGLE_H
