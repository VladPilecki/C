#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "math.h"

int maxx(int a, int b) {
    if (a > b) {
        return a;
    }
    else {
        return b;
    }
}

double** input(int* max) {
    FILE* in = fopen("FILE.txt", "r");
    int n, m;
    fscanf_s(in, "%d %d", &m, &n);
    *max = maxx(m, n);
    double** arr = (double**)calloc(*max, sizeof(double*));
    int i, j;
    for (i = 0; i < *max; ++i) {
        arr[i] = (double*)calloc(*max, sizeof(double));
    }
    for (i = 0; i < m; ++i) {
        for (j = 0; j < n; ++j) {
            fscanf_s(in, "%lf", &arr[i][j]);
            
        }
        
    }
    fclose(in);
    return arr;
}

void swap(double** arr, int a, int b) {
    double* tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

int solution(double** arr, const int max) {
    int i, j;
    for (i = 0; i < max - 1; ++i) {
        for (j = i; j < max; ++j) {
            if (fabs(arr[i][j]) > 1e-4) {
                swap(arr, j, i);
                int k;
                for (k = i + 1; k < max; ++k) {
                    if (fabs(arr[k][i]) > 1e-4) {
                        int l = max - 1;
                        for (; l >= i; --l) {
                            arr[k][l] -= arr[k][i] / arr[i][i] * arr[i][l];
                        }
                    }
                }
                break;
            }
        }
    }
    for (i = 0; i < max; ++i) {
        for (j = 0; j < max; ++j) {
            printf("%lf ", arr[i][j]);
        }
        puts("");
    }
    int ans = max;
    for (i = 0; i < max; ++i) {
        int bool = 1;
        for (j = 0; j < max; ++j) {
            if (fabs(arr[i][j]) > 1e-5) {
                bool = 0;
                break;
            }
        }
        if (bool) {
            ans--;
        }
    }
    return ans;
}

void getArrayFree(double** arr, int max) {
    int i;
    for (i = 0; i < max; ++i) {
        free(arr[i]);
    }
    free(arr);
}

int main() {
    int max;
    double** arr = input(&max);
    if (arr == NULL) {
        printf("don't have enough memory");
        return 0;
    }
    printf("rank = %d", solution(arr, max));
    getArrayFree(arr, max);
    return 0;
}
