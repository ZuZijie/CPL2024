#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void printPolynomial(int *coeff, int degree, char *var) {
    int first = 1; 
    for (int i = 0; i <= degree; i++) {
        int power = degree - i;
        int c = coeff[i];
        if (c == 0) continue; 
        if (!first) {
            if (c > 0) printf("+");
        }
        if (c == -1 && power > 0) printf("-");
        else if (c != 1 || power == 0) printf("%d", c);
        if (power > 0) {
            printf("%s", var);
            if (power > 1) printf("^%d", power);
        }
        first = 0;
    }
    if (first) printf("0"); 
    printf("\n");
}
void addPolynomials(int *p1, int d1, int *p2, int d2, int *result, int *dResult) {
    int maxDegree = d1 > d2 ? d1 : d2;
    *dResult = maxDegree;
    for (int i = 0; i <= maxDegree; i++) {
        result[i] = 0;
    }
    for (int i = 0; i <= d1; i++) {
        result[i + (maxDegree - d1)] += p1[i];
    }
    for (int i = 0; i <= d2; i++) {
        result[i + (maxDegree - d2)] += p2[i];
    }
}
void subtractPolynomials(int *p1, int d1, int *p2, int d2, int *result, int *dResult) {
    int maxDegree = d1 > d2 ? d1 : d2;
    *dResult = maxDegree;
    for (int i = 0; i <= maxDegree; i++) {
        result[i] = 0;
    }
    for (int i = 0; i <= d1; i++) {
        result[i + (maxDegree - d1)] += p1[i];
    }
    for (int i = 0; i <= d2; i++) {
        result[i + (maxDegree - d2)] -= p2[i];
    }
}
void multiplyPolynomials(int *p1, int d1, int *p2, int d2, int *result, int *dResult) {
    *dResult = d1 + d2;
    for (int i = 0; i <= *dResult; i++) {
        result[i] = 0;
    }
    for (int i = 0; i <= d1; i++) {
        for (int j = 0; j <= d2; j++) {
            result[i + j] += p1[i] * p2[j];
        }
    }
}
int main() {
    int p1, p2;
    char var[11];
    scanf("%d %d", &p1, &p2);
    scanf("%s", var);

    int coeff1[p1 + 1], coeff2[p2 + 1];
    for (int i = 0; i <= p1; i++) {
        scanf("%d", &coeff1[i]);
    }
    for (int i = 0; i <= p2; i++) {
        scanf("%d", &coeff2[i]);
    }

    int sum[p1 > p2 ? p1 + 1 : p2 + 1], diff[p1 > p2 ? p1 + 1 : p2 + 1];
    int product[p1 + p2 + 1];
    int dSum, dDiff, dProduct;

    addPolynomials(coeff1, p1, coeff2, p2, sum, &dSum);

    subtractPolynomials(coeff1, p1, coeff2, p2, diff, &dDiff);

    multiplyPolynomials(coeff1, p1, coeff2, p2, product, &dProduct);


    printPolynomial(sum, dSum, var);
    printPolynomial(diff, dDiff, var);
    printPolynomial(product, dProduct, var);

    return 0;
}
