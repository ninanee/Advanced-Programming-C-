//
// Created by Yun Ni on 2021-07-25.
//

#include "Canvas.h"
// creates this canvas's (rows x columns) grid filled with blank characters
Canvas::Canvas(int row, int col, char fillCh) : rows(row), cols(col)
{
    for (int i = 0; i < rows; ++i)
    {
        std::vector<char> row;
        for(int j = 0 ; j < cols; ++j){
            row.push_back(fillCh);
        }
        grid.push_back(row);
    }
}

int Canvas::getRows() const // returns height
{
    return rows;
}
int Canvas::getColumns()const // returns width
{
    return cols;
}
// flips this canvas horizontally
Canvas Canvas::flip_horizontal()const
{
    Canvas can {getRows(), getColumns()};
    for (int i = 0; i < getRows(); i++){
        for (int j = 0; j < getColumns(); j++){
            can.put(i, j, get(i, getColumns() - 1 - j));
        }
    }
    return can;
}

// flips this canvas vertically
Canvas Canvas::flip_vertical()const
{
    Canvas can {getRows(), getColumns()};
    for (int i = 0; i < getRows(); i++){
        for (int j = 0; j < getColumns(); j++){
            can.put(i, j, get(getRows() - 1 - i,j));
        }
    }
    return can;
}

// prints to ostream
void Canvas::print(std::ostream& sout) const
{
    std::vector<std::vector<char>>::const_iterator colIt;
    std::vector<char>::const_iterator rowIt;
    for (colIt = grid.begin(); colIt < grid.end(); colIt++) {
        for (rowIt = colIt->begin(); rowIt < colIt->end(); rowIt++) {
            sout << *rowIt;
        }
        sout << std::endl;
    }
}

// returns char at row r and column c
char Canvas::get(int r, int c) const
{
    if(check(r,c)){
        return grid[r][c];
    }
    else {
        return ' ';
    }
}

// puts ch at row r and column c;
void Canvas::put(int r, int c, char ch)
{
    if(check(r,c)) {
        grid[r][c] = ch;
    }
    else{
        return;
    }
}

//validates row r and column c
bool Canvas::check(int r, int c) const
{
    return 0 <= r && r < rows && 0 <= c && c < cols;
}

// resizes this Canvas's dimensions
void Canvas::resize(size_t rows, size_t cols)
{
    std::vector<char> clear(getColumns(), ' ');
    grid.resize(rows, clear);

    std::vector<std::vector<char>>::iterator it;
    for (it = grid.begin(); it != grid.end(); it++) {
        it->resize(cols, ' ');
    }
}

// draws text starting at row r and col c on the canvas
void Canvas::drawString(int r, int c, const std::string text)
{
    std::string::const_iterator stringIt;
    for (stringIt = text.begin(); stringIt < text.end(); stringIt++, c++) {
        put(r, c, *stringIt);
    }
}

// copies the non-blank characters of "can" onto the invoking canvas;
// maps can's origin to row r and column c on the invoking canvas
void Canvas::overlap(const Canvas& can, size_t r, size_t c)
{
    int rows = can.getRows();
    int cols = can.getColumns();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (get(r + i, c + j) == ' ' || can.get(i, j) != ' ')
                put(r + i, c + j, can.get(i, j));
        }
    }
}

std::ostream& operator<< (std::ostream& sout, const Canvas& f)
{
    f.print(sout);
    return sout;
}