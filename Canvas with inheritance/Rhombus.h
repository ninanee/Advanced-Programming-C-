//
// Created by Yun Ni on 2021-07-25.
//


#ifndef INC_5421A4_RHOMBUS_H
#define INC_5421A4_RHOMBUS_H
#include "Shape.h"

class Rhombus : public Shape
{

public:

    //default constructor
    Rhombus(unsigned int diagonal,unsigned int diagonal2, char pen = '*', std::string name = "Diamond");

    //defaulted destructor
    virtual ~Rhombus() override = default;

    //defaulted copy constructor
    Rhombus(const Rhombus&) = default;

    //defaulted assignment operator
    Rhombus& operator = (const Rhombus&) = default;

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


#endif //INC_5421A4_RHOMBUS_H
