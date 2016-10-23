#include "Matrix.h"

void my_swap(unsigned int *x, unsigned int *y) {
    int aux;
        
    aux = *x;
    *x = *y;
    *y = aux;

    return;
}

Matrix::Matrix()
{
    matrix = nullptr;
    x_len = 0;
    y_len = 0;
    printf("Matrix()\n");
    return;
}

Matrix::Matrix(const unsigned int x,
        const unsigned int y)
    : x_len(x)
    , y_len(y)
{
    matrix = new double[x_len * y_len];
    printf("Matrix(int, int)\n");
}

Matrix::~Matrix()
{
    delete[] matrix;
    printf("~Matrix()\n");
}

Matrix::Matrix(const Matrix &that) 
    : x_len(that.x_len)
    , y_len(that.y_len)
{
    int i;
    if (this != &that) {
        matrix = new double[x_len * y_len];

        for (i = 0; i < x_len * y_len; i++) {
            matrix[i] = that.matrix[i];
        }
    }
    printf("Matrix(Matrix&)\n");
}

Matrix::Matrix(Matrix &&that)
{
    matrix = that.matrix;
    x_len = that.x_len;
    y_len = that.y_len;

    that.x_len = 0;
    that.y_len = 0;
    that.matrix = nullptr;
    printf("Matrix(Matrix&&)\n");
}

Matrix& Matrix::operator=(const Matrix &that) {
    int i;
    if (x_len == that.x_len &&
    y_len == that.y_len) {
        for (i = 0; i < x_len * y_len; i++) {
            matrix[i] = that.matrix[i];
        }
    } else {
        throw("Incorrect operarion '='\n");
    }
    printf("operator=(Matrix &)\n");
    return *this;
}

Matrix& Matrix::operator=(Matrix &&that)
{
    double *aux_matrix;

    aux_matrix = matrix;
    matrix = that.matrix;
    that.matrix = aux_matrix;

    my_swap(&x_len, &that.x_len);
    my_swap(&y_len, &that.y_len);
    printf("operator=(Martix &&)\n");
    return *this;
}

double *Matrix::operator[](const unsigned int index)
{
    return &matrix[index * y_len];
}

double Matrix::at(unsigned int i, unsigned int j) const{
    if (i < x_len && j < y_len) {
        return matrix[i * y_len + j];
    } else {
        throw ("Indices are out of range\n");
    }
    return 0;
}

Matrix& Matrix::operator+(const Matrix &that) {
    int i;
    if (that.x_len == x_len && that.y_len == y_len) {
         for (i = 0; i < x_len * y_len; i++) {
             matrix[i] += that.matrix[i];
         }
    } else {
        throw("Incorrect operation '+'\n");
    }
    return *this;
}

Matrix& Matrix::operator-(const Matrix &that) {
    int i;
    if (that.x_len == x_len && that.y_len == y_len) {
         for (i = 0; i < x_len * y_len; i++) {
             matrix[i] -= that.matrix[i];
         }
    } else {
        throw("Incorrect operation '-'\n");
    }
    return *this;
}

Matrix& Matrix::operator*(const double alpha) {
    int i;
    for (i = 0; i < x_len * y_len; i++) {
        matrix[i] *= alpha;
    }
    return *this;
}

int Matrix::get_x_len() const {
    return x_len;
}

int Matrix::get_y_len() const{
    return y_len;
}
