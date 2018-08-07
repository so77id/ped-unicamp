#include <stdio.h>

#define SIZE 312

int main() {

   int i, j, z, n, buff;
   double sum;
   double M[SIZE][SIZE];
   double ID[SIZE][SIZE];

   scanf("%d", &n);

   for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
         ID[i][j] = 0.0;
      }
   }

   for (i = 0; i < n; i++) {
      scanf("%d", &buff);
      ID[buff - 1][i] = 1;
   }


   for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
         scanf("%lf", &M[i][j]);
      }
   }

   for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
         sum = 0.0;
         for (z = 0; z < n; z++) {
            sum += ID[i][z] * M[z][j];
         }
         if (j+1 < n) printf("%.1f ", sum);
         else printf("%.1f", sum);
      }
      printf("\n");
   }

   return 0;
}
