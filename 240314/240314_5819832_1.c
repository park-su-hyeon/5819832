#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    clock_t start, stop; 
    double duration;
    int sum = 0; //합 0으로 초기화
    int n;

    start = clock(); //시간 측정 시작

    for (int i = 2; i <= 100; i++) { 
        for (n = 2; n < i; n++) { 
            if (i % n == 0) //나머지가 0인 수는 소수에서 제외
                break;
        }
        if (n == i) 
            sum += i;
    }

    printf("1부터 100까지 소수의 합: %d\n", sum);

    stop = clock(); //시간 측정 종료
    duration = (double)(stop - start) / CLOCKS_PER_SEC; 
    printf("수행시간: %f\n", duration);

    return 0;
}
