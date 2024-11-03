#include <stdio.h>
#include <math.h>

int if_prime(int a) {
    if (a < 2) return 0; 
    for (int i = 2; i <= sqrt(a); i++) {
        if (a % i == 0) {
            return 0; 
        }
    }
    return 1; 
}

int reverse(int a) {
    int reversed = 0;
    while (a > 0) {
        reversed = reversed * 10 + a % 10;
        a /= 10;
    }
    return reversed;
}

int main() {
    int n;
    scanf("%d", &n);
    int count = 0;

    for (int i = 2; i <= n; i++) {
        if (if_prime(i)) {
            if (if_prime(reverse(i))) {
                count++;
            }
        }
    }
    printf("%d\n", count);
    return 0;
}
