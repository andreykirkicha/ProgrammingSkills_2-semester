#include <stdio.h>
#include <malloc.h>

void foo(int* ptr, int size) {
    int temp[4];
    
    temp[0] = 0;
    temp[1] = 4;
    temp[2] = 2;
    temp[3] = 6;
    
    int val = ptr[temp[0]];
    ptr[temp[0]] = ptr[0];
    ptr[0] = val;

    for (int i = 0; i < 4; i++) {
        int val = ptr[temp[i]];
        ptr[temp[i]] = ptr[i+1];
        ptr[i+1] = val;
    }

    if (size > 1) {
        int* p = ptr + 2;
        for (int i = 0; i < size - 2; i++) {
            *p += *(p-1);
            p++;
        }
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    int* input = (int*) malloc(sizeof(int)*N);
    for (int i = 0; i < N; i++) {
        scanf("%d", input + i);
    }

    foo(input, N);

    for (int i = 0; i < N; i++) {
        printf("%d ", input[i]);
    }
    printf("\n");

    free(input);
    return 0;
}
