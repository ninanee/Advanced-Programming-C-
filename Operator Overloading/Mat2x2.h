//
// Created by Yun Ni
//

#ifndef INC_5421A3_MAT2X2_H
#define INC_5421A3_MAT2X2_H
#include <array>
#include <initializer_list>
#include <iostream>
using std::array;
using std::initializer_list;


class Mat2x2 {
private:
    array<double, 4> matrix{};
    static double tolerance; // initial value = 1.0E-6

public:
    explicit Mat2x2(double = 0, double = 0, double = 0, double = 0);
    Mat2x2(const array<double, 4> &);
    Mat2x2(const array<array<double, 2>, 2>&);
    Mat2x2(const initializer_list<double>);

    Mat2x2(const Mat2x2&) = default;                               //Defaulted copy ctor
    Mat2x2(Mat2x2&&) = default;                                    //Defaulted move ctor
    Mat2x2& operator= (const Mat2x2&) = default;                   //Default assign op
    Mat2x2& operator= (Mat2x2&&) = default;                        //Default move op
    ~Mat2x2() = default;                                               //Default dtor

    double norm() const;                                               //returns the norm of the calling object
    Mat2x2 inverse() const;                                            //returns the inverse of the calling object
    double det() const;                                                //returns the determinant of the calling object


    //Compound arithmetic assignment operators are overloaded first so that they can be used
    //to implement the simple arithmetic operators and prevent clutter and facilitate code re-use.

    Mat2x2& operator+=(const Mat2x2&);                            // M += M'
    Mat2x2& operator-=(const Mat2x2&);                            // M -= M'
    Mat2x2& operator*=(const Mat2x2&);                            // M *= M'
    Mat2x2& operator/=(const Mat2x2&);                            // M /= M'

    Mat2x2& operator+=(const double&);                            // M += x'
    Mat2x2& operator-=(const double&);                            // M -= x'
    Mat2x2& operator*=(const double&);                            // M *= x'
    Mat2x2& operator/=(const double&);                            // M /= x'

    //Unary operators
    Mat2x2 operator+() const;                                      // unary +
    Mat2x2 operator-() const;                                      // unary -

    Mat2x2& operator++();                                          // unary prefix increment
    Mat2x2& operator--();                                          // unary prefix decrement

    Mat2x2 operator++(int);                                        // unary postfix increment
    Mat2x2 operator--(int);                                        // unary postfix decrement


    //overloaded XOR operator^ such that x^k returns the Mat2x2 object resulting from
    //raising x to the power k (an integer). It does not modify x.
    Mat2x2 operator^(int k);

    //Subscript operators [ ], both const and non-const overloads.
    double& operator[](int index);
    const double& operator[](int index) const;

    explicit operator bool() const;


    //Function objects (functor
    double operator()() const;
    double& operator()(size_t r, size_t c);

    static void setTolerance(double tol);
    static double getTolerance();

};


//Output and Input operators overloaded to allow easy intialization and printing of the matrix
std::istream& operator >> (std::istream& sin, Mat2x2& target);
std::ostream& operator << (std::ostream& sout, const Mat2x2& source);

//Mat2x2 op Mat2x2 x + y, x - y, x * y, x / y
Mat2x2 operator+ (const Mat2x2& x, const Mat2x2& y);
Mat2x2 operator- (const Mat2x2& x, const Mat2x2& y);
Mat2x2 operator* (const Mat2x2& x, const Mat2x2& y);
Mat2x2 operator/ (const Mat2x2& x, const Mat2x2& y);

//Mat2x2 op double x + k, x - k, x * k, x / k
Mat2x2 operator+ (const Mat2x2& x, const double k);
Mat2x2 operator- (const Mat2x2& x, const double k);
Mat2x2 operator* (const Mat2x2& x, const double k);
Mat2x2 operator/ (const Mat2x2& x, const double k);

//double op Mat2x2 k + y, k - y, k * y, k / y
Mat2x2 operator+ (const double k, const Mat2x2& y);
Mat2x2 operator- (const double k, const Mat2x2& y);
Mat2x2 operator* (const double k, const Mat2x2& y);
Mat2x2 operator/ (const double k, const Mat2x2& y);


//Relational operators.
//Mat2x2 op Mat2x2 x < y, x <= y, x > y, x >= y, x == y, x != y
bool operator < (const Mat2x2& x, const Mat2x2& y);
bool operator <= (const Mat2x2& x, const Mat2x2& y);
bool operator > (const Mat2x2& x, const Mat2x2& y);
bool operator >= (const Mat2x2& x, const Mat2x2& y);
bool operator == (const Mat2x2& x, const Mat2x2& y);
bool operator != (const Mat2x2& x, const Mat2x2& y);

#endif //INC_5421A3_MAT2X2_H
