#include <stdio.h>

int array[11];
int main() {
    int cnt;
    scanf("%d", &cnt);
    int input[cnt];
    for (int i = 0; i < cnt; ++i)
        scanf("%d", input + i);

    array[0] = 1, array[1] = 2, array[2] = 4;
    for (int i = 3; i < 11; ++i)
        array[i] = array[i - 1] + array[i - 2] + array[i - 3];

    for (int i = 0; i < cnt; ++i) {
        printf("%d\n", array[input[i] - 1]);
    }
}