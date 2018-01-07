#include <stdio.h>

long long array[2][90];

int main() {
    int input;
    scanf("%d", &input);
    array[0][0] = 0;
    array[1][0] = 1;

    array[0][1] = 1;
    array[1][1] = 0;

    for (int i = 2; i < input; ++i) {
        array[0][i] = array[0][i - 1] + array[1][i - 1];
        array[1][i] = array[0][i - 1];
    }

    printf("%lli", array[0][input - 1] + array[1][input - 1]);
}