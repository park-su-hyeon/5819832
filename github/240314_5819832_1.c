#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main() {
	clock_t start, stop;
	double duration;
	int sum = 0;

	start = clock();
	for (int i = 2;i <= 100;i++) {
		for (int n = 1;n < i;n++) {
			if (i % n == 0)
				break;
			if( i % n == 1)
			sum += i;
		}
		printf("1부터 100까지 소수의 합: %d\n", sum);
	}
	stop = clock();
	duration = (double)(stop - start) / CLOCKS_PER_SEC;
	printf("수행시간: %f\n", duration);
	return 0;
}
