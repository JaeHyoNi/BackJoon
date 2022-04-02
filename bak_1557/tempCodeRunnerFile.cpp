#include <cstdio>

long long number[1000001];

int main(void) {
        long long min, max;
        int cnt = 0;

        scanf("%lld %lld", &min, &max);

        for (long long i = 2; i * i <= max; i++) {
                long long n = min / (i * i);
                
                if (min % (i * i)) n++;

                while (n * i * i <= max) {		//n*i*i는 min보다 크거나 같은 i의 제곱수의 배수
                        number[n * i * i - min] = 1;
                        n++;
                }
        }

        for (int i = 0; i <= max - min; i++) {
                if (number[i] == 0) cnt++;
        }

        printf("%d", cnt);
        return 0;
}