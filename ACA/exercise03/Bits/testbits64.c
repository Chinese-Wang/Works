// testbits64.c
// MinGW Win32, Intel 64 bits CPU, Little Endian Word

#include "bits64.c"
#include <stdio.h>

void printBits (Bits64 *bits) {
   printf( "%s\n", toBits( bits ));
   printf( "%s\n", toBit4( bits ));
   printf( "%s\n", toHexs( bits ));
   printf( "Big Endian:    %s\n", toHex4( bits ));
   printf( "Little Endian: %s\n\n", littleEndianHex4( bits ));
}

void main (int argc, char *agrv[]) {
   Bits64 a, b, c;
   a.inDouble = -3.0;
   printf( "double: %f\n", a.inDouble);
   printf( "float: %f, \tfloat: %f\n", a.inFloats[0], a.inFloats[1] );
   printf( "int:   %d, \tint:   %d\n", a.inInts[0], a.inInts[1] );
   printBits( &a );
 
   b.inInts[0] = -1;
   b.inFloats[1] = -5.0;
   printf( "int:   %d,\t\tfloat: %f\n", b.inInts[0], b.inFloats[1] );
   printf( "float: %f, \tint:   %d\n",  b.inFloats[0], b.inInts[1] );
   printBits( &b );

   c.unInts[0] = 0x01234567U;
   c.unInts[1] = 0xA0C00000U;
   printf( "unsign: %u, \tunsign: %u\n", c.unInts[0], c.unInts[1] );
   printf( "int:    %d, \tint:    %d\n", c.inInts[0], c.inInts[1] );
   printBits( &c );

   setBit( &c, 0, 0 );
   setBit( &c, 32, 1 );
   printf( "set bit 0 to 0 and bit 32 to 1\n" );
   printf( "unsign: %u, \tunsign: %u\n", c.unInts[0], c.unInts[1] );
   printf( "int:    %d, \tint:    %d\n", c.inInts[0], c.inInts[1] );
   printBits( &c );
}   
