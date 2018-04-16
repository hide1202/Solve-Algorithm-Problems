#include <cstdio>
#include <cstring>

struct Recommand {
    int stdNum;
    int recNum;
    int order;
};

int totalFrameCnt;
int totalRecommandCnt;
struct Recommand selected[20];
struct Recommand recommand[1000];

int EmptyFrame() {
    for (int i = 0; i < totalFrameCnt; ++i) {
        if (selected[i].stdNum == 0)
            return i;
    }
    return -1;
}

int SelectFrame() {
    int ret = 0;
    int idx[20] = {0,}, n = 0;
    int minNum = 10000;

    for (int i = 0; i < totalFrameCnt; ++i) {
        if (selected[i].recNum < minNum) {
            minNum = selected[i].recNum;
            memset(idx, 0, sizeof(int) * 20);
            n = 0;
            idx[n++] = i;
        } else if (selected[i].recNum == minNum) {
            idx[n++] = i;
        }
    }

    int orderMin = 10001;
    for (int i = 0; i < n; ++i) {
        if (selected[idx[i]].order <= orderMin) {
            orderMin = selected[idx[i]].order;
            ret = idx[i];
        }
    }
    return ret;
}

int AlreadyFrame(int stdNum) {
    for (int i = 0; i < totalFrameCnt; ++i) {
        if (selected[i].stdNum == stdNum)
            return i;
    }
    return -1;
}

int main() {
    scanf("%d", &totalFrameCnt);
    scanf("%d", &totalRecommandCnt);
    for (int i = 0; i < totalRecommandCnt; ++i) {
        scanf("%d", &((recommand + i)->stdNum));
        (recommand + i)->order = i;
    }
    for (int i = 0; i < totalRecommandCnt; ++i) {
        int already = AlreadyFrame(recommand[i].stdNum);
        if (already != -1) {
            selected[already].recNum++;
        } else {
            int frame = EmptyFrame();
            if (frame == -1) {
                frame = SelectFrame();
            }
            selected[frame].recNum = 0;
            selected[frame].stdNum = recommand[i].stdNum;
            selected[frame].order = recommand[i].order;
            selected[frame].recNum = 1;
        }
    }

    for (int i = 0; i < totalFrameCnt; ++i) {
        for (int j = i + 1; j < totalFrameCnt; ++j) {
            if (selected[i].stdNum == 0 ||
                selected[j].stdNum == 0)
                continue;
            if (selected[i].stdNum > selected[j].stdNum) {
                struct Recommand tmp = selected[i];
                selected[i] = selected[j];
                selected[j] = tmp;
            }
        }
    }

    for (int i = 0; i < totalFrameCnt; ++i) {
        if (selected[i].stdNum != 0)
            printf("%d ", selected[i].stdNum);
    }
    return 0;
}