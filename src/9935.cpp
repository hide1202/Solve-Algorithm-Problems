#include <cstdio>
#include <cstring>

char stack[1000000];
char str[1000000];
char ex[36];

int sip = -1;

void push(char c) {
    stack[++sip] = c;
}

char pop() {
    char ret = stack[sip];
    stack[sip] = 0;
    sip--;
    return ret;
}

bool isEx(int exLen) {
    int equal = strncmp(stack + sip - exLen + 1, ex, static_cast<size_t>(exLen));
    return equal == 0;
}

void explore(int exLen) {
    for (int i = 0; i < exLen; ++i) {
        pop();
    }
}

int main() {
    scanf("%s", str);
    scanf("%s", ex);
    int strLen = static_cast<int>(strlen(str));
    int exLen = static_cast<int>(strlen(ex));
    for (int i = 0; i < strLen; ++i) {
        push(str[i]);
        do {
            if (isEx(exLen)) {
                explore(exLen);
            }
        } while (isEx(exLen));
    }
    if(stack[0] == 0)
        printf("FRULA");
    else
        printf("%s", stack);
}