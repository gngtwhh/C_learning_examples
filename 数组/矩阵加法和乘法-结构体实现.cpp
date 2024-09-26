#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ELEMENT_TYPE int
typedef struct Matrix{
    unsigned int row;
    unsigned int col;
    ELEMENT_TYPE* data;
}Matrix;

Matrix* setMatrix() {
    Matrix *m = (Matrix*)malloc(sizeof(Matrix));
    int i, j;
    printf("The number of rows in the matrix:");
    scanf("%u", &m->row);
    printf("The number of columns of the matrix:");
    scanf("%u", &m->col);
    m->data = (ELEMENT_TYPE*)malloc(sizeof(ELEMENT_TYPE) * m->row * m->col);
    if (m->data == NULL) {
        printf("malloc error!");
        exit(-1);
    }
    for (i = 0; i < m->row; ++i) {
        printf("Enter the %d line:\n", i + 1);
        for (j = 0; j < m->col; ++j) {
            scanf("%5d", m->data + (m->col) * i + j);
        }
    }
    return m;
}
Matrix* setVoidMatrix() {
    Matrix *temp = (Matrix*)malloc(sizeof(Matrix));
    return temp;
}
void printMatrix(Matrix* m) {
    int i, j;
    if (m == NULL) {
        printf("wrong\n");
        return;
    }
    printf("row=%u col=%u\n", m->row, m->col);
    for (i = 0; i < m->row; ++i) {
        for (j = 0; j < m->col; ++j) {
            printf("%5d ", *(m->data + m->col * i + j));
        }
        putchar('\n');
    }
}
int addition(Matrix *m1, Matrix *m2, Matrix *result) {
    int i, j;
    // Matrix *result = (Matrix*)malloc(sizeof(Matrix));
    if (m1->row != m2->row || m1->col != m2->col) {
        printf("Addition error: Rows and columns do not match!\n");
        return -1;
    }
    result->data = (ELEMENT_TYPE*)malloc(sizeof(ELEMENT_TYPE) * m1->row * m1->col);
    result->row = m1->row;
    result->col = m1->col;
    for (i = 0; i < m1->row; ++i)
        for (j = 0; j < m1->col; ++j)
            *(result->data + result->col * i + j) =
                    *(m1->data + m1->col * i + j) +
                    *(m2->data + m2->col * i + j);
    return 1;
}
int multiplication(Matrix *m1, Matrix *m2, Matrix *result) {
    int i, j, k;
    if (m1->col != m2->row) {
        printf("Multiplication error: Rows and columns do not match\n");
        return -1;
    }
    result->row = m1->row;
    result->col = m2->col;
    result->data = (ELEMENT_TYPE*)malloc(sizeof(ELEMENT_TYPE) * m1->row * m2->col);
    for (i = 0; i < m1->row; ++i)
        for (j = 0; j < m2->col; ++j) {
            *(result->data + result->col * i + j) = 0;
            for (k = 0; k < m1->col; ++k) {
                *(result->data + result->col * i + j) +=
                        *(m1->data + m1->col * i + k) *
                        *(m2->data + m2->col * k + j);
            }
        }
    return 1;
}
int destoryMatrix(Matrix*m) {
    free(m->data);
    free(m);
    return 1;
}
int main() {
    Matrix *m1 = setMatrix(), *m2 = setMatrix();
    Matrix *addResult = setVoidMatrix(),*mclResult=setVoidMatrix();
    printf("the data of the first matrix:\n");
    printMatrix(m1);
    printf("the data of the second matrix:\n");
    printMatrix(m2);
    addition(m1, m2, addResult);
    printf("addition:\n");
    printMatrix(addResult);
    printf("multiplication:\n");
    multiplication(m1, m2,mclResult);
    printMatrix(mclResult);

    destoryMatrix(m1);
    destoryMatrix(m2);
    destoryMatrix(addResult);
    destoryMatrix(mclResult);
    return 0;
}
