//
// Created by Yun Ni on 2021-07-25.
//

#include "Triangle.h"

Triangle::Triangle(unsigned int height,unsigned int base, char pen, std::string name)
: Shape(height, base, pen, name) {}


double Triangle::geoArea() const
{
    return (height * width) / 2.0;
}