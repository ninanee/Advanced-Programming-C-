//
// Created by Yun Ni on 2021-07-25.
//

#include "Rhombus.h"
#include <vector>

Rhombus::Rhombus(unsigned int diagonal,unsigned int diagonal2, char pen, std::string name)
: Shape(diagonal, diagonal2, pen, name)
{
    height = (0 == diagonal % 2) ? diagonal + 1 : diagonal;
    width = (0 == diagonal % 2) ? diagonal + 1 : diagonal;
}

//Two mutator (setter) methods for setting the height and width members;
void Rhombus::setHeight(unsigned int newHeight)
{
    height = newHeight;
}

void Rhombus::setWidth(unsigned int newWidth)
{
    height = newWidth;
}

//A method to compute and return the shape's geometric area;
double Rhombus::geoArea() const
{
    return ((double) (height * height)) / 2;
}

//A method to compute and return the shape's geometric perimeter;
double Rhombus::geoPerimeter() const
{
    return (2 * sqrt(2)) * height;
}

//A method to compute the shape's textual area, which is the number of characters that
//form the textual image of the shape;
unsigned int Rhombus::textualArea() const
{
    int n = height / 2;
    return (2 * n * (n + 1) + 1);
}

//A method to compute the shape's textual perimeter, which is the number of characters on
//the borders of the textual image of the shape;
unsigned int Rhombus::textualPerimeter() const
{
    return 2 * (height - 1);
}

Canvas Rhombus::draw() const
{
    Canvas can{ getHeight(), getHeight() };
    char pen {getPen()};
    int half = getHeight() / 2;

//outer loop: looping through the rhombus's height
    for (int r = 0; r < getHeight(); ++r)
    {
        //inner loop: looping through the rhombus's width
        for (int c = 0; c < getHeight(); ++c) {
            int d = std::abs(int(half - r)) + std::abs(int(half - c));
            if (d <= half) {
                can.put(r, c, pen);
            }
        }
    }
    return can;
}