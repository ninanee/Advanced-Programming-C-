//
// Created by Yun Ni on 2021-07-23.
//

#ifndef INC_5421A4_RECTANGLE_H
#define INC_5421A4_RECTANGLE_H
#include "Shape.h"

class Rectangle : public Shape
{
public:
    //default constructor
    Rectangle(unsigned int height,unsigned int width, char pen = '*', std::string name = "Rectangle");

    //defaulted destructor
    virtual ~Rectangle() override = default;

    //defaulted copy constructor
    Rectangle(const Rectangle&) = default;

    //defaulted assignment operator
    Rectangle& operator = (const Rectangle&) = default;

    //Two mutator (setter) methods for setting the height and width members;
    virtual void setHeight(unsigned int)  override;
    virtual void setWidth(unsigned int) override;

    //A method to compute and return the shape's geometric area;
    virtual double geoArea() const override;

    //A method to compute and return the shape's geometric perimeter;
    virtual double geoPerimeter() const override;

    //A method to compute the shape's textual area, which is the number of characters that
    //form the textual image of the shape;
    virtual unsigned int textualArea() const override;

    //A method to compute the shape's textual perimeter, which is the number of characters on
    //the borders of the textual image of the shape;
    virtual unsigned int textualPerimeter() const override;

    virtual Canvas draw() const override;

};


#endif //INC_5421A4_RECTANGLE_H
