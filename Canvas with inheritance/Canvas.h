//
// Created by Yun Ni on 2021-07-25.
//

#ifndef INC_5421A4_CANVAS_H
#define INC_5421A4_CANVAS_H
#include <iostream>
#include <string>
#include <vector>

class Canvas {
private:
    int rows;
    int cols;

public:
    // all special members are defaulted because 'grid',
    // the only data member, is self-sufficient and efficient; that is,
    // it is equipped to handle the corresponding operations efficiently
    Canvas() = default;
    virtual ~Canvas() = default;
    Canvas(const Canvas&) = default;
    Canvas(Canvas&&) = default;
    Canvas& operator=(const Canvas&) = default;
    Canvas& operator=(Canvas&&) = default;

protected:
    std::vector<std::vector<char> > grid{}; // the only data member
    bool check(int r, int c)const; // validates row r and column c
    void resize(size_t rows, size_t cols); // resizes this Canvas's dimensions

public:
    // creates this canvas's (rows x columns) grid filled with blank characters
    Canvas(int rows, int columns, char fillChar = ' ');

    int getRows()const; // returns height
    int getColumns()const; // returns width
    Canvas flip_horizontal()const; // flips this canvas horizontally
    Canvas flip_vertical()const; // flips this canvas vertically
    void print(std::ostream&) const; // prints to ostream
    char get(int r, int c) const; // returns char at row r and column c
    void put(int r, int c, char ch); // puts ch at row r and column c; this is the
    // only function used by a shape's draw functon;
    // returns doing nothing if r or c is invalid

    // draws text starting at row r and col c on the canvas
    void drawString(int r, int c, const std::string text);

    // copies the non-blank characters of "can" onto the invoking canvas;
    // maps can's origin to row r and column c on the invoking canvas
    void overlap(const Canvas& can, size_t r, size_t c);
};

std::ostream& operator<< (std::ostream& sout, const Canvas& f);

#endif //INC_5421A4_CANVAS_H
