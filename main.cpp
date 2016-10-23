#include "matrix_class.cpp"
Matrix enter_matrix(void)
{
    unsigned int i, j, x_len, y_len, error;
    printf("Введите размеры матрицы\n");
    error = scanf("%u%u", &x_len, &y_len);
    if (error != 2) {
        throw("Incorrect size");
    }
    Matrix matrix(x_len, y_len);
    printf("Введите значения матрицы\n");
    for (i = 0; i < x_len; i++) {
        for (j = 0; j < y_len; j++) {
            error = scanf("%lf", &matrix[i][j]);
            if (error != 1) {
                throw("Can't read matrix_element\n");
            }
        }
    }        
    return matrix;
}

double enter_number(void)
{
    int error;
    double alpha;
    printf("Введите число\n");
    error = scanf("%lf", &alpha);
    if (error != 1) {
        throw("Incorrect number\n");
    }
    return alpha;
}

void print_matrix(const Matrix &matrix)
{
    int i, j;
    printf("Результат:\n");
    printf("%d %d\n", matrix.get_x_len(), matrix.get_y_len());
    for (i = 0; i < matrix.get_x_len(); i++) {
        for (j = 0; j < matrix.get_y_len(); j++) {
            printf("%.2lf ", matrix.at(i, j));
        }
        printf("\n");
    }
    return;
}

int main(void) 
{
    Matrix matrix_1;
    int i, j, operation, error;
    double alpha;
    try {
        printf("Введите номер операции:\n");
        printf(" 1. *\n 2. +\n 3. -\n");
        error = scanf("%d", &operation);
        if (error != 1) {
            throw("Can't define operation\n");
        }
        switch(operation){
            case(2):{
                matrix_1 = enter_matrix();
                Matrix matrix_3(enter_matrix());
                Matrix matrix_2(matrix_3);
                matrix_1 = matrix_1 + matrix_2;
            }
                break;
            case(3):{
                matrix_1 = enter_matrix();
                Matrix matrix_3(enter_matrix());
                matrix_1 = matrix_1 - matrix_3;
            }
                break;
            case(1):
                matrix_1 = enter_matrix();
                alpha = enter_number();
                matrix_1 = matrix_1 * alpha;
                break;
            default: 
                throw("Can't define operation\n");
        }
        print_matrix(matrix_1);
    }    
    catch (const char *message){
        printf("%s", message);
    }
    catch(...) {
        printf("Unknown mistake\n");
    }
    return 0;
}
