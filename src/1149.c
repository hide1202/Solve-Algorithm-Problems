#include <stdio.h>

int array[3][1000];

#define MIN2(A, B) (A >= B ? B : A)
#define MIN3(A, B, C) (A >= MIN2(B, C) ? MIN2(B, C) : A)

int main() {
    int cnt = 0;
    scanf("%d", &cnt);
    for (int i = 0; i < cnt; ++i) {
        int r, g, b;
        scanf("%d %d %d", &array[0][i], &array[1][i], &array[2][i]);
        if (i > 0) {
            array[0][i] += MIN2(array[1][i - 1], array[2][i - 1]);
            array[1][i] += MIN2(array[0][i - 1], array[2][i - 1]);
            array[2][i] += MIN2(array[0][i - 1], array[1][i - 1]);
        }
    }
    printf("%d", MIN3(array[0][cnt - 1], array[1][cnt - 1], array[2][cnt - 1]));
}