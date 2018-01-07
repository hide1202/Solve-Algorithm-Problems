#include <stdio.h>

#define MAX2(A, B) (A >= B ? A : B)

int triangle[500][501];
int array[500][501];

int main() {
    int height = 0;
    scanf("%d", &height);
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < i + 1; ++j) {
            scanf("%d", &triangle[i][j]);
        }
    }
    array[0][0] = triangle[0][0];
    for (int i = 1; i < height; ++i) {
        array[i][0] = array[i - 1][0] + triangle[i][0];
        for (int j = 1; j < i; ++j) {
            int value = MAX2(array[i - 1][j - 1], array[i - 1][j]);
            array[i][j] = triangle[i][j] + value;
        }
        array[i][i] = array[i - 1][i - 1] + triangle[i][i];
    }

    int result = 0;
    for (int i = 0; i < height + 1; ++i) {
        int current = array[height - 1][i];
        if (result <= current)
            result = current;
    }

    printf("%d", result);
}