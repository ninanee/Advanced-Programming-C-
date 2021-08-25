//
// Created by Yun Ni on 2021-07-25.
//

#ifndef INC_5421A4_ACUTETRIANGLE_H
#define INC_5421A4_ACUTETRIANGLE_H
#include "Triangle.h"

class AcuteTriangle : public Triangle
{
public:
    //default constructor that sets a default name and description of every Acute Triangle
    AcuteTriangle(unsigned int height,unsigned int base, char pen = '*', std::string name = "Wedge");

    //defaulted destructor (should be virtual)
    virtual ~AcuteTriangle() = default;

    //defaulted copy constructor
    AcuteTriangle(const AcuteTriangle&) = default;

    //defaulted assignment operator
    AcuteTriangle& operator = (const AcuteTriangle&) = default;

    //A method to compute and return the shape's geometric perimeter;
    virtual double geoPerimeter() const override;

    //A method to compute the shape's textual area, which is the number of characters that
    //form the textual image of the shape;
    virtual unsigned int textualArea() const override;

    //A method to compute the shape's textual perimeter, which is the number of characters on
    //the borders of the textual image of the shape;
    virtual unsigned int textualPerimeter() const override;

    virtual void setHeight(unsigned int ) override;
    virtual void setWidth(unsigned int ) override;

    virtual Canvas draw() const override;
    void setWidth_cols(unsigned int);

};


#endif //INC_5421A4_ACUTETRIANGLE_H
