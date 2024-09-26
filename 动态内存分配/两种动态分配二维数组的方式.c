//#if 0
//该版本为连续分配的方式---即"一维数组模拟二维数组"
#include <stdio.h>
#include <stdlib.h>

void functionName(int row, int col, int (*array)[col]) {
    int i, j, t = 1;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            array[i][j] = t++;
        }
    }
}

int main() {
    int row = 3, col = 4;
    int i, j;
    int *array = (int*)malloc(row * col * sizeof(int));
    functionName(row, col, (int (*)[col])array);
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%d ", array[i*col+j]);
        }
        printf("\n");
    }
    free(array);
    return 0;
}
//#endif

#if 0
//该版本为指针数组模拟二维数组的动态分配方式
#include <stdio.h>
#include <stdlib.h>

void functionName(int row, int col, int**array) {
    int i, j,t=1;
    for (i = 0; i < 3; ++i)
        for (j = 0; j < 4; ++j)
            array[i][j] = t++;
}

int main() {
    int row = 3, col = 4;
    int i, j;
    int** array = (int**)malloc(row * sizeof(int*));
    for (i = 0; i < row; i++) {
        array[i] = (int*)malloc(col * sizeof(int));
    }
    
    functionName(row, col, array);
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    free(array);
    return 0;
}
#endif