//
// Created by Yun Ni on 2021-07-25.
//

#ifndef INC_5421A4_RIGHTTRIANGLE_H
#define INC_5421A4_RIGHTTRIANGLE_H
#include "Triangle.h"

class RightTriangle : public Triangle
{
public:
    //default constructor that sets a default name and description of every RightTriangle
    RightTriangle(unsigned int height,unsigned int base, char pen = '*', std::string name = "Ladder");

    //defaulted destructor (should be virtual)
    virtual ~RightTriangle() = default;

    //defaulted copy constructor
    RightTriangle(const RightTriangle&) = default;

    //defaulted assignment operator
    RightTriangle& operator = (const RightTriangle&) = default;

    //Two mutator (setter) methods for setting the height and width members;
    virtual void setHeight(unsigned int) override;
    virtual void setWidth(unsigned int) override;

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


#endif //INC_5421A4_RIGHTTRIANGLE_H
