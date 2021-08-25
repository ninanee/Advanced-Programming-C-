//
// Created by Yun Ni
//

#include "Mat2x2.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <array>
#include <initializer_list>

using std::cout;
using std::cin;
using std::endl;

Mat2x2::Mat2x2(double a, double b, double c, double d) {
    matrix[0] = a;
    matrix[1] = b;
    matrix[2] = c;
    matrix[3] = d;
}

Mat2x2::Mat2x2(const array<double, 4> & matrixArray)
: Mat2x2{ matrixArray[0],matrixArray[1], matrixArray[2],matrixArray[3] }{}

Mat2x2::Mat2x2(const array<array<double, 2>, 2>& matrixArray)
: Mat2x2{ matrixArray[0][0], matrixArray[0][1], matrixArray[1][0], matrixArray[1][1]} {}

//need to control the num of input
Mat2x2::Mat2x2(const initializer_list<double> matrixList)
{
    for (int i = 0; i < 4 && (matrixList.begin()+i) != matrixList.end(); i++) {
        matrix[i] = *(matrixList.begin()+i);
    }
}

//returns the norm of the calling object
double Mat2x2::norm() const
{
    return sqrt(pow(matrix[0],2) + pow(matrix[1],2) +
    pow(matrix[2],2)+ pow(matrix[3],2));

}

//returns the inverse of the calling object
Mat2x2 Mat2x2::inverse() const
{
    double d = det();
    if(d == 0.0)
    {
        try{
            throw std::invalid_argument("Division by zero!");
        }
        catch (const std::invalid_argument& ia){
            cout << "Problem:\n" << ia.what() << std::endl;
        }
    }
    Mat2x2 temp { 1/d*matrix[3], 1/d*-matrix[1], 1/d*-matrix[2], 1/d*matrix[0]};
    return temp;
}

//Calculate the determinant of the invoking matrix, return the determinant
double Mat2x2::det() const{
    return matrix[0] * matrix[3] - matrix[1] * matrix[2];
}


//Compound arithmetic assignment operators are overloaded first so that they can be used
//to implement the simple arithmetic operators and prevent clutter and facilitate code re-use.

// M += M'
Mat2x2& Mat2x2::operator+=(const Mat2x2& m)
{
    this->matrix[0] += m[0];
    this->matrix[1] += m[1];
    this->matrix[2] += m[2];
    this->matrix[3] += m[3];
    return *this;
}

// M -= M'
Mat2x2& Mat2x2::operator-=(const Mat2x2& m)
{
    this->matrix[0] -= m[0];
    this->matrix[1] -= m[1];
    this->matrix[2] -= m[2];
    this->matrix[3] -= m[3];
    return *this;
}

// M *= M'
Mat2x2& Mat2x2::operator*=(const Mat2x2& m)
{
    double a = matrix[0] * m[0] + matrix[1] * m[2];
    double b = matrix[0] * m[1] + matrix[1] * m[3];
    double c = matrix[2] * m[0] + matrix[3] * m[2];
    double d = matrix[2] * m[1] + matrix[3] * m[3];
    this->matrix[0] = a;
    this->matrix[1] = b;
    this->matrix[2] = c;
    this->matrix[3] = d;
    return *this;
}

// M /= M'
Mat2x2& Mat2x2::operator/=(const Mat2x2& m)
{
    Mat2x2 temp1 {*this};
    Mat2x2 temp2 {m};
    temp1 *= temp2.inverse();
    this->matrix[0] = temp1[0];
    this->matrix[1] = temp1[1];
    this->matrix[2] = temp1[2];
    this->matrix[3] = temp1[3];
    return *this;
}

// M += x'
Mat2x2& Mat2x2::operator+=(const double& x)
{
    this->matrix[0] += x;
    this->matrix[1] += x;
    this->matrix[2] += x;
    this->matrix[3] += x;
    return *this;
}

// M -= x'
Mat2x2& Mat2x2::operator-=(const double& x)
{
    this->matrix[0] -= x;
    this->matrix[1] -= x;
    this->matrix[2] -= x;
    this->matrix[3] -= x;
    return *this;
}

// M *= x'
Mat2x2& Mat2x2::operator*=(const double& x)
{
    this->matrix[0] *= x;
    this->matrix[1] *= x;
    this->matrix[2] *= x;
    this->matrix[3] *= x;
    return *this;
}

// M /= x'
Mat2x2& Mat2x2::operator/=(const double& x)
{
    if(x == 0.0){
        try{
            throw std::invalid_argument("Division by zero condition!");
        }
        catch (const std::invalid_argument& ia){
            cout << "Problem:\n" << ia.what() << std::endl;
        }
    }
    else {
        this->matrix[0] /= x;
        this->matrix[1] /= x;
        this->matrix[2] /= x;
        this->matrix[3] /= x;
        return *this;
    }
}

//Unary operators
// unary +
Mat2x2 Mat2x2::operator+() const
{
    return *this;
}

// unary -
Mat2x2 Mat2x2::operator-() const
{
    Mat2x2 temp {*this};
    temp *= -1;
    return temp;
}

// unary prefix increment
Mat2x2& Mat2x2::operator++()
{
    *this += 1;
    return *this;
}

// unary prefix decrement // unary prefix decrement
Mat2x2& Mat2x2::operator--()
{
    *this -= 1;
    return *this;
}

// unary postfix increment
Mat2x2 Mat2x2::operator++(int)
{
    Mat2x2 temp {*this};
    *this += 1;
    return temp;
}

// unary postfix decrement
Mat2x2 Mat2x2::operator--(int)
{
    Mat2x2 temp {*this};
    *this -= 1;
    return temp;
}


//overloaded XOR operator^ such that x^k returns the Mat2x2 object resulting from
//raising x to the power k (an integer). It does not modify x.
Mat2x2 Mat2x2::operator^(int k)
{
    if(k == 0){
        return Mat2x2 {1,1,1,1};
    }else if(k == -1){
        return this->inverse();
    } else{
        Mat2x2 temp {*this};
        for (int i = 1; i < k; i++) {
            temp *= *this;
        }
        return temp;
    }
}

//Subscript operators [ ], both const and non-const overloads.
double& Mat2x2::operator[](int index)
{
    if(index < 0 || index >= 4 ){
        throw std::invalid_argument("index out of bounds!");
    }
    else{
        return matrix[index];
    }
}

const double& Mat2x2::operator[](int index) const
{
    if(index < 0 || index >= 4 ){
        throw std::invalid_argument("index out of bounds!");
    }
    else{
        return matrix[index];
    }
}

//Returns whether or not the invoking object has inverse.
Mat2x2::operator bool() const
{
    if(this->det() < -tolerance || this->det() > tolerance){
        return true;
    }
    else{
        return false;
    }
}

//Function objects (functor
//double operator()()const Returns the norm of the invoking Mat2x2 object. For ex-ample,
// if x is a Mat2x2 object, then x() returns x.norm().
double Mat2x2::operator()() const
{
    return this->norm();
}

//Returns an lvalue reference to the entry at row r and column c.
double& Mat2x2::operator()(size_t r, size_t c)
{
    if(r < 1 || r > 2) {
        throw std::invalid_argument("row index out of bounds");
    }else if (c < 1 || c > 2){
        throw std::invalid_argument("column index out of bounds");
    }else if (r == 1 && c == 1 ){
        return matrix[0];
    }else if (r == 1 && c == 2 ) {
        return matrix[1];
    }else if (r == 2 && c == 1 ){
        return matrix[2];
    }else{
        return matrix[3];
    }
}


//static methods, need to write in the cpp file
double Mat2x2::tolerance = 0.000001;

void Mat2x2::setTolerance(double tol)
{
    tolerance = tol;
}
double Mat2x2::getTolerance()
{
    return tolerance;
}

//Output and Input operators overloaded to allow easy intialization and printing of the matrix
std::istream& operator >> (std::istream& sin, Mat2x2& target)
{
    for(int i = 0; i  < 4; ++i){
        sin >> target[i];
    }
    return sin;
}
std::ostream& operator << (std::ostream& sout, const Mat2x2& source)
{
    sout << std::fixed << std::setprecision(2);
    sout << "[" << source[0] << ", " <<  source[1] << ", "<< source[2] << ", " << source[3] << "] " ;
    return sout;
}

//Mat2x2 op Mat2x2 x + y, x - y, x * y, x / y
Mat2x2 operator+ (const Mat2x2& x, const Mat2x2& y)
{
    Mat2x2 temp {x};
    temp += y;
    return temp;
}

Mat2x2 operator- (const Mat2x2& x, const Mat2x2& y)
{
    Mat2x2 temp {x};
    temp -= y;
    return temp;
}

Mat2x2 operator* (const Mat2x2& x, const Mat2x2& y)
{
    Mat2x2 temp {x};
    temp *= y;
    return temp;
}

Mat2x2 operator/ (const Mat2x2& x, const Mat2x2& y)
{
    Mat2x2 temp {x};
    temp /= y;
    return temp;
}

//Mat2x2 op double x + k, x - k, x * k, x / k
Mat2x2 operator+ (const Mat2x2& x, const double k)
{
    Mat2x2 temp {x};
    temp += k;
    return temp;
}
Mat2x2 operator- (const Mat2x2& x, const double k)
{
    Mat2x2 temp {x};
    temp -= k;
    return temp;
}
Mat2x2 operator* (const Mat2x2& x, const double k)
{
    Mat2x2 temp {x};
    temp *= k;
    return temp;
}
Mat2x2 operator/ (const Mat2x2& x, const double k)
{
    Mat2x2 temp {x};
    temp /= k;
    return temp;
}


//double op Mat2x2 k + y, k - y, k * y, k / y
Mat2x2 operator+ (const double k, const Mat2x2& y)
{
    return y + k;
}

Mat2x2 operator- (const double k, const Mat2x2& y)
{
    Mat2x2 temp{ k,k,k,k};
    return temp - y;
}
Mat2x2 operator* (const double k, const Mat2x2& y)
{
    return y * k;
}
Mat2x2 operator/ (const double k, const Mat2x2& y)
{
    return k * y.inverse();
}


//Relational operators.
//Mat2x2 op Mat2x2 x < y, x <= y, x > y, x >= y, x == y, x != y
bool operator < (const Mat2x2& x, const Mat2x2& y)
{
    if(x.norm() < y.norm() && x != y){
        return true;
    } else{
        return false;
    }
}

bool operator <= (const Mat2x2& x, const Mat2x2& y)
{
    if(x == y || x < y){
        return true;
    } else{
        return false;
    }
}

bool operator > (const Mat2x2& x, const Mat2x2& y)
{
    if(x.norm() > y.norm() && x != y){
        return true;
    } else{
        return false;
    }
}
bool operator >= (const Mat2x2& x, const Mat2x2& y)
{
        if(x == y || x > y){
            return true;
        } else{
            return false;
        }
}

//Determine if two matrixes are equal
bool operator == (const Mat2x2& x, const Mat2x2& y)
{
    if (x.norm() - y.norm() <= x.getTolerance() && x.norm() - y.norm() >= -x.getTolerance()) {
        return true;
    }
    else {
        return false;
    }
}

// Determine if two matrixes are not equal
bool operator != (const Mat2x2& x, const Mat2x2& y)
{
    return !(x == y);
}
