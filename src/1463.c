#include <stdio.h>

char array[1000001];

char min(char a, char b) { return a >= b ? b : a; }

int main() {
    int input = 0;
    scanf("%d", &input);
    int n = 5;
    array[1] = 0, array[2] = array[3] = 1, array[4] = 2;
    while (n <= input) {
        if ((n & 1) == 1 && n % 3 != 0) {
            array[n] = array[n - 1] + 1;
        } else {
            int tmp = n;
            if (tmp % 3 == 0 && (tmp & 1) != 0 ||
                tmp % 3 == 0 && (tmp & 1) == 0)
                tmp /= 3;
            else if ((tmp & 1) == 0)
                tmp >>= 1;

            array[n] = min(array[n - 1] + 1, array[tmp] + 1);
        }
        n++;
    }
    printf("%d", array[input]);
}