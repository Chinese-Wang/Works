// numtrans i k ddddddddddddd
// Transfer an i-based number string to a k-based number string
// i and k in [2..36]
// @ Max, 2020, 2021
#include <stdio.h>
#include <stdlib.h>

int ctoi (char c) {     // helper function
   if ('0' <= c && c <= '9') return c - '0';
   if ('A' <= c && c <= 'Z') return c - 'A' + 10;
   if ('a' <= c && c <= 'z') return c - 'a' + 10;
   return 0;   
}

//long : 4Byte
long long atol_with_radix (char* s, int radix) {
   long long ans = 0;
   int r = 1;
   int len = 0;

   while (s[len] != '\0') len++;
   len--;

   while (len >= 0) {
      ans += ctoi(s[len]) * r;
      r = r * radix;
     len--;
   }

   return ans;
}

void main (int argc, char** argv) {
   int i = atoi( argv[1] );    // call atoi in stdlib
   int k = atoi( argv[2] );
   long long n = atol_with_radix( argv[3], i );

   char s[65];                 // long has 64 bits 
   ltoa( n, s, k );            // call ltoa in stdlib
   printf( "%s\n", s );
}

