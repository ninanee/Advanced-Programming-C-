//
// Created by Yun Ni on 2021-07-25.
//

#include "RightTriangle.h"
#include<cmath>

RightTriangle::RightTriangle(unsigned int height, unsigned int base, char pen, std::string name)
: Triangle(height, base, pen, name){}

//A method to compute and return the shape's geometric perimeter;
double RightTriangle::geoPerimeter() const
{
    return (2 + sqrt(2)) * getHeight();
}

//A method to compute the shape's textual area, which is the number of characters that
//form the textual image of the shape;
unsigned int RightTriangle::textualArea() const
{
    return (getHeight() * (getHeight() + 1) / 2);
}

//A method to compute the shape's textual perimeter, which is the number of characters on
//the borders of the textual image of the shape;
unsigned int RightTriangle::textualPerimeter() const
{
    return 3 * (getHeight() - 1);
}

void RightTriangle::setHeight(unsigned int newHeight)
{
    height = newHeight;
}
void RightTriangle::setWidth(unsigned int newWidth)
{
    width = newWidth;
}

Canvas RightTriangle::draw() const
{
    Canvas can{ getHeight(), getHeight() };
    char pen {getPen()};

    for (int r = 0; r < getHeight(); ++r) {
        for (int c = 0; c < getHeight(); ++c) {
            if (r >= c) {
                can.put(r, c, pen);
            }
        }
    }
    return can;

}
