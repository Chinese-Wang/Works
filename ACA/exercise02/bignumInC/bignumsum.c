<<<<<<< HEAD
// bignumsum.c
#include "bignum.c"

void main (int argc, char** argv) {
   bignum a, b, c;
   set_bignum( &a, argv[1] );
   set_bignum( &b, argv[3] );
   initialize_bignum( &c );

   if (argv[2][0] == '-')
      subtract_bignum( &a, &b, &c );
   else
      add_bignum( &a, &b, &c );

   print_bignum( &a );
   printf( "%c\n", argv[2][0] );
   print_bignum( &b );
   printf( "=\n" );
   print_bignum( &c );
   printf( "\n" );
}
=======
// bignumsum.c
#include "bignum.c"

void main (int argc, char** argv) {
   bignum a, b, c;
   set_bignum( &a, argv[1] );
   set_bignum( &b, argv[3] );
   initialize_bignum( &c );

   if (argv[2][0] == '-')
      subtract_bignum( &a, &b, &c );
   else
      add_bignum( &a, &b, &c );

   print_bignum( &a );
   printf( "%c\n", argv[2][0] );
   print_bignum( &b );
   printf( "=\n" );
   print_bignum( &c );
   printf( "\n" );
}
>>>>>>> 0aa3fb0a71e3b24c81e0cba3065f97bbc676435e
