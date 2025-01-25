#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
#define newPoly(pname, p) \
  poly_t pname;           \
  pname.maxOrder = (p);   \
  pname.coe = (int *)malloc(sizeof(int) * ((p) + 1));
#define maxLen 12
char *name;
struct poly {
  int maxOrder;
  int *coe;  // coefficients
};
typedef struct poly poly_t;
void printItem(int coe, int p) {
  if (p == 0) {
    printf("%d", coe);
    return;
  }
  if (coe != 1 && coe != -1)
    printf("%d", coe);
  else if (coe == -1)
    printf("-");
  printf("%s", name);
  if (p > 1)
    printf("^%d", p);
}
void printPoly(poly_t P) {
  for (int i = P.maxOrder; i >= 0; i--) {
    int coe = P.coe[i];
    if (coe > 0 && i != P.maxOrder)
      printf("+");
    else if (coe == 0)
      continue;
    printItem(coe, i);
  }
  printf("\n");
}
void polyAddMinus(poly_t P1, poly_t P2, int add) {
  newPoly(P, max(P1.maxOrder, P2.maxOrder));
  for (int i = 0; i <= P.maxOrder; i++)
    P.coe[i] = (i <= P1.maxOrder ? P1.coe[i] : 0) +
               (i <= P2.maxOrder ? P2.coe[i] : 0) * (add ? 1 : -1);
  printPoly(P);
  free(P.coe);
}
void polyMul(poly_t P1, poly_t P2) {
  newPoly(P, P1.maxOrder + P2.maxOrder);
  memset(P.coe, 0, sizeof(int) * (P.maxOrder + 1));
  for (int i = P1.maxOrder; i >= 0; i--)
    for (int j = P2.maxOrder; j >= 0; j--)
      P.coe[i + j] += P1.coe[i] * P2.coe[j];
  printPoly(P);
  free(P.coe);
}
int main(void) {
  int p1, p2;
  name = (char *)malloc(sizeof(char) * maxLen);
  scanf("%d%d%s", &p1, &p2, name);
  newPoly(P1, p1);
  newPoly(P2, p2);
  for (int i = p1; i >= 0; i--)
    scanf("%d", P1.coe + i);
  for (int i = p2; i >= 0; i--)
    scanf("%d", P2.coe + i);
  polyAddMinus(P1, P2, 1);
  polyAddMinus(P1, P2, 0);
  polyMul(P1, P2);
  free(P1.coe);
  free(P2.coe);
  return 0;
}