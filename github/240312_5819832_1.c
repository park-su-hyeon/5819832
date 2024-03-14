#include <stdio.h>
#include <stdlib.h>

int main() {
    int sum = 0; //합 0으로 초기화
    int n;

    for (int i = 2; i <= 100; i++) {
        for (n = 2; n <= i; n++) {
            if (i % n == 0) //나머지가 0인 수는 소수에서 제외
                break;
        }
        if (n == i)
            sum += i;
    }

    printf("1부터 100까지 소수의 합: %d\n", sum);
    return 0;
}
