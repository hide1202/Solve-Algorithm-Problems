#include <stdio.h>
int main() {
    int array[8];
    for (int i = 0; i < 8; ++i)
        scanf("%d", array + i);
    int subtract = 0, isUp = array[0] == 1 ? 1 : array[0] == 8 ? 0 : -1;
    for (int j = 0; j < 7; ++j) {
        subtract = array[j + 1] - array[j];
        if ((isUp == 1 && subtract != 1) ||
            (isUp == 0 && subtract != -1))
            isUp = -1;
    }
    printf(isUp == -1 ? "mixed" : isUp == 1 ? "ascending" : "descending");
}