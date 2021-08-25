//
// Created by Yun Ni on 2021-07-23.
//

#include "Rectangle.h"
//default constructor
Rectangle::Rectangle(unsigned int height, unsigned int width, char pen, std::string name)
: Shape(height, width, pen,name) {

}

//Two mutator (setter) methods for setting the height and width members;
void Rectangle::setHeight(unsigned int newHeight)
{
    height = newHeight;
}

void Rectangle::setWidth(unsigned int newWeight)
{
    width = newWeight;
}

//A method to compute and return the shape's geometric area;
double Rectangle::geoArea() const
{
    return height * width;

}

//A method to compute and return the shape's geometric perimeter;
double Rectangle::geoPerimeter() const
{
    return 2 * (height + width);
}

//A method to compute the shape's textual area, which is the number of characters that
//form the textual image of the shape;
unsigned int Rectangle::textualArea() const
{
    return height * width;
}

//A method to compute the shape's textual perimeter, which is the number of characters on
//the borders of the textual image of the shape;
unsigned int Rectangle::textualPerimeter() const
{
    return 2 * (height + width) - 4;
}

Canvas Rectangle::draw() const
{
    Canvas can { getHeight(), getWidth(), getPen()};
    return can;
}