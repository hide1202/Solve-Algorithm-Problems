#include <stdio.h>

int score[5];

int main() {
    for (int i = 0; i < 5; ++i)
        scanf("%d", score + i);
    int sum = 0;
    for (int j = 0; j < 5; ++j)
        sum += score[j] < 40 ? 40 : score[j];
    printf("%d", sum / 5);
}