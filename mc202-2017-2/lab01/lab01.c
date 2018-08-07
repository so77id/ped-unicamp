#include <stdio.h>

int main() {

   size_t i, j;
   int inc = 0;
   int m, n;
   int A[40], B[40];

   scanf("%d %d", &m, &n);

   for (i = 0; i < m; i++) {
      scanf("%d", &A[i]);
   }
   for (i = 0; i < n; i++) {
      scanf("%d", &B[i]);
   }

   for (i = 0; i < m; i++) {
      inc = 0;
      for (j = 0; j < n; j++) {
         if (A[i] == B[j]) {
            inc = 1;
            break;
         }
      }
      if (inc == 0) {
         printf("%d ", A[i]);
      }
   }

   for (i = 0; i < n; i++) {
      inc = 0;
      for (j = 0; j < m; j++) {
         if (B[i] == A[j]) {
            inc = 1;
            break;
         }
      }
      if (inc == 0) {
         printf("%d ", B[i]);
      }
   }

   return 0;
}
