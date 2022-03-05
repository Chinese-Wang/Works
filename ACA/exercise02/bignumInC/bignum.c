// bignum.c
#include <stdio.h>
#include "bignum.h"

void print_bignum (bignum *n) {
   int i;    /* counter */
   if (n->signbit == MINUS) printf( "- " );
   for (i = n->lastdigit; i >= 0; i--)
      printf( "%c", '0' + n->digits[i] );
   printf ("\n" );
}

void initialize_bignum (bignum *n) {
   int i;    /* counter */
   for (i = 0; i < MAXDIGITS; i++)
      n->digits[i] = 0;
   
   n->signbit = PLUS;
   n->lastdigit = 0;   
};

void set_bignum (bignum *n, char* s) {
   int i = 0, k, length;
   initialize_bignum( n );
   if (s[0] == '-') {       // skip beginning - sign
      n->signbit = MINUS;
      i = 1;
   } else if (s[0] == '+')  // skip beginning + sign
      i = 1;

   while (s[i]=='0') i++;   // skip beginning 0s
   
   for (k = i, length = 0; s[k] != '\0'; k++, length++) /* NONE */ ;

   n->lastdigit = length - 1;
   for (k = length-1; k >= 0; k--, i++)
      n->digits[k] = s[i] - '0';
};

void zero_justify (bignum *n) {
   while ((n->lastdigit > 0) && (n->digits[ n->lastdigit ] == 0))
      n->lastdigit --;

   if ((n->lastdigit == 0) && (n->digits[0] == 0))
      n->signbit = PLUS;   /* hack to avoid -0 */
}

int compare_bignum (bignum *a, bignum *b) {
   int i;    /* counter */
   if ((a->signbit==MINUS) && (b->signbit==PLUS)) return PLUS;
   if ((a->signbit==PLUS) && (b->signbit==MINUS)) return MINUS;
   if (b->lastdigit > a->lastdigit) return (PLUS * a->signbit);
   if (a->lastdigit > b->lastdigit) return (MINUS * a->signbit);
   for (i = a->lastdigit; i >= 0; i--) {
      if (a->digits[i] > b->digits[i])
         return (MINUS * a->signbit);
      if (b->digits[i] > a->digits[i])
         return (PLUS * a->signbit);
   }
   return 0;
}

int max (int a, int b) {
   return (a > b) ? a : b;
}

void add_bignum (bignum *a, bignum *b, bignum *c) {
   // TODO ...
   if (a->signbit == b->signbit) // 1 + 2 ;  -1 + (-2)
      c->signbit = a->signbit;
   else if (a->signbit == PLUS && b->signbit == MINUS) { // 1 + (-2) = 1 - 2
      b->signbit = PLUS;
      subtract_bignum(a, b, c);
      return;
   }
   else {  // -1 + 2 = 2 - 1
      a->signbit = PLUS;
      subtract_bignum(b, a, c);
      return;
   }
   
   int overTen = 0;
   int indexC = 0, indexA = 0, indexB = 0;
   int tmp;

   while (indexA <= a->lastdigit || indexB <= b->lastdigit) {
      tmp = a->digits[indexA++] + b->digits[indexB++] + overTen;
      overTen = tmp / 10;
      c->digits[indexC++] = tmp % 10;
   }
   
   c->lastdigit = indexC - 1;

   zero_justify( c );
}

void subtract_bignum (bignum *a, bignum *b, bignum *c) {
   // TODO ... 
   if (a->signbit != b->signbit){ // 1 - (-2) = 1 + 2 ; -1 - 2 = -1 + (-2)
      b->signbit = MINUS * b->signbit;
      add_bignum(a, b, c);
      return;
   }
   else if (a->signbit == b->signbit && a->signbit == MINUS) {  // -1 - (-2) = -1 + 2 = 2 - 1
      b->signbit = PLUS;
      a->signbit = PLUS;
      subtract_bignum(b, a, c);
      return;
   }
   
   //a - b
   c->signbit = compare_bignum(b, a);
   if (c->signbit == 0) // a == b
      return;
   else if (c->signbit == MINUS) { //b > a, switch them
      bignum* temp = a;
      a = b;
      b = temp;
   }

   int indexA = 0, indexB = 0, indexC = 0;
   int debit = 0;
   int tmp;
   int digitA, digitB;

   while (indexA <= a->lastdigit) {
      digitA = a->digits[indexA];
      digitB = b->digits[indexB];

      if (digitA == digitB) {
         if (debit == 0) 
            tmp = 0;
         else 
            tmp = digitA + 9 - digitB;
      }
      else if (digitA > digitB) {
         tmp = digitA - digitB - debit;
         debit = 0;
      }
      else{
         tmp = digitA + 10 - digitB - debit;
         debit = 1;
      }
      indexA++;
      indexB++;
      c->digits[indexC++] = tmp;
   }

   c->lastdigit = indexC - 1;

   zero_justify(c);
}
