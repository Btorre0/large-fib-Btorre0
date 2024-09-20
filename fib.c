// Beatriz Torres Archundia
// CPSC 351 - 08
// 09.06.24
// btorre0@csu.fullerton.edu
// Github Username: Btorre0

#include <stdio.h>



// Recursive function
unsigned long long int fibRec( int num ) {

   if (num <= 1) {

      return 0;

   } else if (num == 2) {

      return 1;
   }

   return fibRec(num - 1) + fibRec(num - 2);
}



// Iterative function
unsigned long long int fibIter( int num ) {

   unsigned long long int a = 0;
   unsigned long long int b = 1;
   unsigned long long int c;

   for (int i = 3; i <= num; i++) {

      c = a + b;
      a = b;
      b = c;
   }

   return b;
}



int main( int argc , char *argv[] ) {

   if (argc < 3) {

      printf("Usage: %s <integer> <r/i> <filename>\n", argv[0]);

      return 1;
   }

   int file_num = 0;
   int num;
   unsigned long long int compute;

   sscanf(argv[1], "%d", &num);

   if (argc == 4) {

      FILE *file = fopen(argv[3], "r");

      if (file == NULL) {

         printf("file doesnt exist\n");

         return 1;
      }

      fscanf(file, "%d", &file_num);

      fclose(file);
   }
   

   num += file_num;

   if (argv[2][0] == 'r') {
      
      compute = fibRec(num);
   } else {

      compute = fibIter(num);
   }

   printf("%llu\n", compute);

   return 0;
}
