#include <stdio.h>

class Matrix
{
protected:
    double *matrix;
    unsigned int x_len, y_len;

public:
    Matrix();

    Matrix( const unsigned int x,
            const unsigned int y); 

    ~Matrix();
    
    Matrix(const Matrix &that);

    Matrix(Matrix &&that);

    Matrix& operator=(const Matrix &that);

    Matrix& operator=(Matrix &&that);

    double *operator[](const unsigned int index);

    double at(unsigned int i, unsigned int j) const;
    
    Matrix& operator+(const Matrix &that);

    Matrix& operator-(const Matrix &that);

    Matrix& operator*(const double alpha);

    int get_x_len() const;

    int get_y_len() const;
};
