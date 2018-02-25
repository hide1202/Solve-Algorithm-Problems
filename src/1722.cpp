// TODO 다시 풀어보기 => 이상하게 풀었음

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int pCase;
long long k;
int input[20];

vector<long long> tmp;
vector<long long> a1;

long long f[22];

int calcFac() {
    f[0] = 1, f[1] = 1, f[2] = 2;
    for (long long i = 3; i < 22; ++i)
        f[i] = f[i - 1] * i;
}

int main() {
    calcFac();
    scanf("%d", &n);
    scanf("%d", &pCase);
    if (pCase == 1) {
        scanf("%lli", &k);
        for (int i = 0; i < n; ++i)
            tmp.push_back(i + 1);

        for (int i = 0; i < n; ++i) {
            long long j = f[n - 1 - i];
            long long num = j == 1 ? (k % 2 == 1 ? 0 : 1) : k % j == 0 ? (k / j) - 1 : (k / j);
            if (num >= tmp.size())
                num = static_cast<long long int>(tmp.size() - 1);
            a1.push_back(tmp[num]);
            tmp.erase(tmp.begin() + num);
            k -= (num * j);
        }

        for (long long &i : a1) {
            printf("%lli ", i);
        }
    } else if (pCase == 2) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &input[i]);
        }

        for (int i = 0; i < n; ++i) {
            tmp.push_back(i + 1);
        }

        long long ans = 1;
        for (int i = 0; i < n; ++i) {
            auto findIter = find(tmp.begin(), tmp.end(), input[i]);
            auto idx = findIter - tmp.begin();
            ans += idx * f[n - 1 - i];
            tmp.erase(findIter);
        }
        printf("%lli", ans);
    }
    return 0;
}