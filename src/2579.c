#include <stdio.h>

#define MAX2(A, B) (A > B ? A : B)

typedef struct _Score {
    int score, cnt;
} Score;

int score[300];
Score array[2][300];

int main() {
    int cnt;
    scanf("%d", &cnt);
    for (int i = 0; i < cnt; ++i)
        scanf("%d", score + i);

    for (int i = 0; i < 300; ++i) {
        array[0][i].score = array[1][i].score = -1;
        array[0][i].cnt = array[1][i].cnt = 0;
    }

    array[0][0].score = score[0];
    array[0][0].cnt = 1;
    if (cnt >= 2) {
        array[1][1].score = score[1];
        array[1][1].cnt= 1;
    }

    for (int i = 0; i < cnt - 1; ++i) {
        if (array[0][i].score == -1)
            continue;
        int sum = 0;
        if (array[0][i].cnt < 2) {
            sum = array[0][i].score + score[i + 1];
            if (sum > array[0][i + 1].score) {
                array[0][i + 1].score = sum;
                array[0][i + 1].cnt = array[0][i].cnt + 1;
            }
        }
        sum = array[0][i].score + score[i + 2];
        if (sum > array[1][i + 2].score) {
            array[1][i + 2].score = sum;
            array[1][i + 2].cnt = 1;
        }

        if (array[1][i].score == -1)
            continue;
        sum = array[1][i].score + score[i + 1];
        if (sum > array[0][i + 1].score) {
            array[0][i + 1].score = sum;
            array[0][i + 1].cnt = 2;
        }

        sum = array[1][i].score + score[i + 2];
        if (sum > array[1][i + 2].score) {
            array[1][i + 2].score = sum;
            array[1][i + 2].cnt = 1;
        }
    }

    printf("%d", MAX2(array[0][cnt - 1].score, array[1][cnt - 1].score));
}