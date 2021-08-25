//
// Created by Yun Ni on 2021-07-25.
//

#include "AcuteTriangle.h"
#include<cmath>

AcuteTriangle::AcuteTriangle(unsigned int height,unsigned int base, char pen, std::string name)
: Triangle(height, base, pen, name)
{
    if (base % 2 == 0)
    {
        this->width = height + 1;
    }
    else {
        this->width = base;
    }

    this->height = (base + 1) / 2;
}

//A method to compute and return the shape's geometric perimeter;
double AcuteTriangle::geoPerimeter() const
{
    return getWidth() + sqrt(getWidth() * getWidth() + 4 * getHeight() * getHeight());
}

//A method to compute the shape's textual area, which is the number of characters that
//form the textual image of the shape;
unsigned int AcuteTriangle::textualArea() const
{
    return getHeight() * getHeight();
}

//A method to compute the shape's textual perimeter, which is the number of characters on
//the borders of the textual image of the shape;
unsigned int AcuteTriangle::textualPerimeter() const
{
    return 4 * (getHeight() - 1);
}

void  AcuteTriangle::setHeight(unsigned int newHeight)
{
    Shape::setHeight(newHeight);
    Shape::setWidth(2 * newHeight - 1);
}
void  AcuteTriangle::setWidth(unsigned int newWidth)
{
    Shape::setHeight((newWidth + 1) / 2);
    Shape::setWidth(newWidth);
}

Canvas AcuteTriangle::draw() const
{
    Canvas can{ getHeight(), getWidth() };
    char pen {getPen()};
    int half = getWidth() / 2;

    for (int r = 0; r < getHeight(); ++r) {
        for (int c = 0; c < getWidth(); ++c) {
            if (std::abs(int(c - half)) <= r) {
                can.put(r, c, pen);
            }
        }
    }
    return can;
}

void AcuteTriangle::setWidth_cols(unsigned int newWidth)
{
    setWidth(newWidth);
}