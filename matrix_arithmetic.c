#include<stdio.h>
#include<stdlib.h>

void sum_case(int** matrix, int** matrix_second, int** result);
void multiplication_case(int** matrix, int** matrix_second, int** result);
void transpose_case(int** matrix, int** result);

int get_operation(int* operation_num);
int get_array_size(int* rows, int* cols);
int** memory_allocation(int** matrix, const int rows, const int cols);


int input(int **matrix, const int rows, const int cols);
void output(int **matrix, const int rows, int cols);

int** sum(int** matrix_first, int** matrix_second, int** result, const int rows, const int cols);

int** muliplication(int** matrix, int rows_first, int** matrix_second,
    int rows_second, int cols_second, int** result);

int** transpose(int** matrix, int** result, const int rows, const int cols);

int main()
{
    int operation;
    if (get_operation(&operation)) {
        int** matrix = NULL;
        int** matrix_second = NULL;
        int** result = NULL;

        switch (operation)
        {
        case 1: 
            sum_case(matrix, matrix_second, result);
            break;
        case 2:
            multiplication_case(matrix, matrix_second, result);
            break;
        case 3:
            transpose_case(matrix, result);
            break;
        }
    }
    else {
        printf("Wrong operation number");
    }

    return 0;
}

void sum_case(int** matrix, int** matrix_second, int** result) {
    int rows_first, cols_first;
    int rows_second, cols_second;
    if (!get_array_size(&rows_first, &cols_first)) {
        printf("Wrong array size input");
    }
    else {
        matrix = memory_allocation(matrix, rows_first, cols_first);
        if (matrix == NULL) {
            printf("Memory allocation error");
        }
        else {
            if (input(matrix, rows_first, cols_first)) {
                if (!get_array_size(&rows_second, &cols_second)) {
                    printf("Wrong array size input");
                }
                else {
                    matrix_second = memory_allocation(matrix_second, rows_second, cols_second);
                    if (matrix == NULL) {
                        printf("Memory allocation error");
                    }
                    else {
                        if (input(matrix_second, rows_second, cols_second)) {
                            if (rows_first != rows_second || cols_first != cols_second) {
                                printf("Error! Sum can't be performed");
                            }
                            else {
                                result = memory_allocation(result, rows_first, cols_first);
                                if (result == NULL) {
                                    printf("Memory allocation error");
                                }
                                else {
                                    result = sum(matrix, matrix_second, result, rows_first, rows_first);
                                    output(result, rows_first, cols_second);
                                    free(result);
                                }
                            }
                        }
                        else {
                            printf("Wrong matrix input");
                        }
                        free(matrix_second);
                    }
                }
            }
            else {
                printf("Wrong matrix input");
            }
            free(matrix);
        }
    }
}


void multiplication_case(int** matrix, int** matrix_second, int** result) {
    int rows_first, cols_first;
    int rows_second, cols_second;
    if (!get_array_size(&rows_first, &cols_first)) {
        printf("Wrong array size input");
    }
    else {
        matrix = memory_allocation(matrix, rows_first, cols_first);
        if (matrix == NULL) {
            printf("Memory allocation error");
        }
        else {
            if (input(matrix, rows_first, cols_first)) {
                if (!get_array_size(&rows_second, &cols_second)) {
                    printf("Wrong array size input");
                }
                else {
                    matrix_second = memory_allocation(matrix_second, rows_second, cols_second);
                    if (matrix == NULL) {
                        printf("Memory allocation error");
                    }
                    else {
                        if (input(matrix_second, rows_second, cols_second)) {
                            if (cols_first != rows_second) {
                                printf("Error! Multiplication can't be performed");
                            }
                            else {
                                result = memory_allocation(result, rows_first, cols_first);
                                if (result == NULL) {
                                    printf("Memory allocation error");
                                }
                                else {
                                    result = muliplication(matrix, rows_first, matrix_second,
                                                            rows_second, cols_second, result);
                                    output(result, rows_first, cols_second);
                                    free(result);
                                }
                            }
                        }
                        else {
                            printf("Wrong matrix input");
                        }
                        free(matrix_second);
                    }
                }
            }
            else {
                printf("Wrong matrix input");
            }
            free(matrix);
        }
    }
}


void transpose_case(int** matrix, int** result) {
    int rows, cols;
    if (!get_array_size(&rows, &cols)) {
        printf("Wrong array size input");
    }
    else {
        matrix = memory_allocation(matrix, rows, cols);
        if (matrix == NULL) {
            printf("Memory allocation error");
        }
        else {
            if (input(matrix, rows, cols)) {
                result = memory_allocation(result, rows, cols);
                if (result == NULL) {
                    printf("Memory allocation error");
                }
                else {
                    result = transpose(matrix, result, rows, cols);
                    output(result, rows, cols);
                    free(result);
                }
            }
            free(matrix);
        }
    }
}


int get_operation(int* operation_num) {
    int flag = 0;
    if(scanf("%d", operation_num) == 1 && *operation_num > 0 && *operation_num < 4) {
        flag = 1;
    }
    return flag;
}

int get_array_size(int* rows, int* cols) {
    int flag = 0;
    if (scanf("%d %d", rows, cols) == 2 && *rows > 0 && *cols > 0) {
        flag = 1;
    }
    return flag;
}

int** memory_allocation(int** matrix, const int rows, const int cols) {
    matrix = (int**)malloc(rows * sizeof(int*) + rows * cols * sizeof(int));
    int* ptr = (int*)(matrix + rows);
    
    for (int i = 0; i < rows; i++) {
        matrix[i] = ptr + cols * i;
    }
    return matrix;
}

int input(int** matrix, const int rows, const int cols) {
    int flag = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (scanf("%d", &matrix[i][j])) {
                flag = 1;
            }
        }
    }
    return flag;
}
void output(int** matrix, const int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        printf("%d", matrix[i][0]);
        for (int j = 1; j < cols; j++) {
            printf(" %d", matrix[i][j]);
        }
        if (i != rows - 1) printf("\n");
    }
}

int** sum(int** matrix_first, int** matrix_second, int** result, const int rows, const int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix_first[i][j] + matrix_second[i][j];
        }
    }
    return result;
}


int** muliplication(int** matrix, int rows_first, int** matrix_second,
    int rows_second, int cols_second, int** result) {

    for (int i = 0; i < rows_first; i++) {
        for (int j = 0; j < cols_second; j++) {
            result[i][j] = 0;
            for (int k = 0; k < rows_second; k++) {
                result[i][j] += matrix[i][k] * matrix_second[k][j];
            }
        }
    }
    return result;
}


int** transpose(int** matrix, int** result, const int rows, const int cols) {

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix[j][i];
        }
    }
    return result;
}


