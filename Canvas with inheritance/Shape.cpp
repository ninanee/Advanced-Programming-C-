//
// Created by Yun Ni on 2021-07-23.
//

#include "Shape.h"
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>
#include <typeinfo>

using std::cout;
using std::endl;
using std::cin;

int Shape::count {0};

//A constructor that accepts as parameters the initial values of a shape's height, width,
//pen, and name, in that order.
Shape::Shape(unsigned int height,unsigned int width, char pen, std::string name)
: height{ height }, width{ width }, pen{ pen }, name{ name }
{
    ++count;
    id = count;
}

//Five accessor (getter) methods, one for each attribute;
std::string Shape::getName() const
{
    return name;
}

unsigned int Shape::getID() const
{
    return id;
}

char Shape::getPen() const
{
    return pen;
}

int Shape::getHeight() const
{
    return height;
}
int Shape::getWidth() const
{
    return width;
}

// Two mutator (setter) methods for setting the name and pen members;
void Shape::setName(std::string newName)
{
    name = newName;
}

void Shape::setPen(char newPen)
{
    pen = newPen;
}

void Shape::setHeight(unsigned int h)
{
    height = h;
    return;
}

void Shape::setWidth(unsigned int w)
{
    width = w;
    return;
}

//A toString() method that forms and returns a string representation of the this shape
std::string Shape::toString() const
{
    std::string info;
    info.append("Shape Information\n");
    info.append("-----------------\n");
    info.append("id: ");

    //If an integer or double has to be appended to the string,  the "to_string" method is
    // used to convert it to string first

    info.append(std::to_string(getID()));
    info.append("\n");
    info.append("Shape name: ");
    info.append(getName());
    info.append("\n");
    info.append("Pen character: ");
    std::string s (1, getPen());
    info.append(s);
    info.append("\n");
    info.append("Height: ");
    info.append(std::to_string(getHeight()));
    info.append("\n");
    info.append("Width: ");
    info.append(std::to_string(getWidth()));
    info.append("\n");
    info.append("Textual area: ");
    info.append(std::to_string(textualArea()));
    info.append("\n");
    info.append("Geometric area: ");

    //To output exactly 2 decimal places in double "Geometric area and Perimeter",
    // an "ostringstream" object sout is used*/
    std::ostringstream sout;
    sout << std::fixed << std::setprecision(2) << geoArea();

    //Get the string content of "sout" and appending it to the main string
    info.append(sout.str());
    info.append("\n");

    info.append("Textual perimeter: ");
    info.append(std::to_string(textualPerimeter()));
    info.append("\n");
    info.append("Geometric perimeter: ");

    //First, the previous content of sout should be removed
    sout.str("");
    sout.clear();
    sout << std::fixed << std::setprecision(2) << geoPerimeter();
    info.append(sout.str());
    info.append("\n");
    info.append("Static type: ");
    //Gets the name of the static type of the pointer "this" at runtime
    info.append(typeid(this).name());
    info.append("\n");
    info.append("Dynamic type: ");

    //Gets the name of the dynamic type of the pointer "this" at runtime
    info.append(typeid(*this).name());;
    info.append("\n");

    return info;
}

std::ostream& operator<<(std::ostream &out, const Shape &s) {
    out << s.toString();
    return out;
}
