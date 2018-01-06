#include <stdio.h>

int main() {
    int cnt;
    scanf("%d", &cnt);
    for (int i = 0; i < cnt; ++i) {
        int m, n, x, y;
        scanf("%d %d %d %d", &m, &n, &x, &y);
        int result = -1;
        for (int i = 0; i <= 40000; ++i) {
            int tmp = x + i * m;
            if (tmp % n == y ||
                tmp % n == 0 && n == y) {
                result = x + i * m;
                break;
            }
        }
        printf("%d\n", result);
    }
}