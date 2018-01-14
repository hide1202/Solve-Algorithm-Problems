#include <stdio.h>
#include <memory.h>

char input[100];
int array[26];
int main(){
    scanf("%s", input);
    memset(array, -1, sizeof(int) * 26);
    for (int i = 0; i < 100; ++i) {
        if(input[i] == 0)
            break;
        int idx = input[i] - 'a';
        if(array[idx] == -1)
            array[idx] = i;
    }
    for (int i = 0; i < 26; ++i)
        printf("%d ", array[i]);
}