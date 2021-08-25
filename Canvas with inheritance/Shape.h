//
// Created by Yun Ni on 2021-07-23.
//

#ifndef INC_5421A4_SHAPE_H
#define INC_5421A4_SHAPE_H
#include <iostream>
#include <string>
#include "Canvas.h"
using std::cout;


class Shape {
private:
    std::string name;   //a name, a string object; for example, \Book" for a rectangular shape
    unsigned int id {};       //an identity number, a unique positive integer, distinct from that of all the other shapes
    char pen;           //a pen character, the single character to use when drawing the shape
    static int count;

protected:
    unsigned int height{};
    unsigned int width{};

public:
    //A constructor that accepts as parameters the initial values of a shape's height, width,
    //pen, and name, in that order.
    Shape(unsigned int height,unsigned int width, char pen = '*', std::string name = "Shape");

    //defaulted copy constructor
    Shape(const Shape&) = default;

    //defaulted assignment operator
    Shape& operator = (const Shape&) = default;

    //default destructor (should be virtual)
    virtual ~Shape() = default;

    //Five accessor (getter) methods, one for each attribute;
    std::string getName() const;
    unsigned int getID() const;
    char getPen() const;
    int getHeight() const;
    int getWidth() const;

    // Two mutator (setter) methods for setting the name and pen members;
    void setName(std::string);
    void setPen(char);

    //A toString() method that forms and returns a string representation of the this shape
    std::string toString () const;

    //Two mutator (setter) methods for setting the height and width members;
    virtual void setHeight(unsigned int);
    virtual void setWidth(unsigned int);

    //A method to compute and return the shape's geometric area;
    virtual double geoArea() const = 0;

    //A method to compute and return the shape's geometric perimeter;
    virtual double geoPerimeter() const = 0;

    //A method to compute the shape's textual area, which is the number of characters that
    //form the textual image of the shape;
    virtual unsigned int textualArea() const = 0;

    //A method to compute the shape's textual perimeter, which is the number of characters on
    //the borders of the textual image of the shape;
    virtual unsigned int textualPerimeter() const = 0;

    //A method that draws a textual image of the shape on a Canvas object using the shape's
    //pen character.
    virtual Canvas draw() const = 0; // concrete derived classes must implement it

    friend std::ostream& operator<<(std::ostream &, const Shape &);

};

std::ostream& operator<<(std::ostream &, const Shape &);

#endif //INC_5421A4_SHAPE_H
