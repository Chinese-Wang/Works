// bits64.c
// MinGW Win32, Intel 64 bits CPU, Little Endian Word

#include "bits64.h"
#include <stdlib.h>

int ENDIAN[8] = { 7, 6, 5, 4, 3, 2, 1, 0 };

char *toHexs (Bits64 *bits) {
   char *s = malloc(2 * nBytes + 1);
   char *t = s;
   for (int i = 0; i < nBytes; i++) {
      *t++ = DIGITS[ (bits->byte[ENDIAN[i]] >> 4) & 0x0F ];
      *t++ = DIGITS[ bits->byte[ENDIAN[i]] & 0x0F ];
   }
   *t = '\0';
   return s;
}   // "AE38FE84E48B36D2"

char *littleEndianHex4 (Bits64 *bits) {
   char *s = malloc(2 * nBytes + 4);
   char *t = s;
   for (int i = 0; i < nBytes; i += 2) {
      *t++ = DIGITS[ (bits->byte[i] >> 4) & 0x0F ];
      *t++ = DIGITS[  bits->byte[i] & 0x0F ];
      *t++ = DIGITS[ (bits->byte[i+1] >> 4) & 0x0F ];
      *t++ = DIGITS[  bits->byte[i+1] & 0x0F ];
      *t++ = (i < nBytes-1) ? ' ' : '\0';
   }
   return s;
}    // "AE38 FE84 E48B 36D2"

char *bigEndianHex4 (Bits64 *bits) {
   char *s = malloc(2 * nBytes + 4);
   char *t = s;
   for (int i = 0; i < nBytes; i += 2) {
      *t++ = DIGITS[ (bits->byte[ENDIAN[i]] >> 4) & 0x0F ];
      *t++ = DIGITS[  bits->byte[ENDIAN[i]] & 0x0F ];
      *t++ = DIGITS[ (bits->byte[ENDIAN[i+1]] >> 4) & 0x0F ];
      *t++ = DIGITS[  bits->byte[ENDIAN[i+1]] & 0x0F ];
      *t++ = (i < nBytes-1) ? ' ' : '\0';
   }
   return s;
}    // "AE38 FE84 E48B 36D2"

char *toHex4 (Bits64 *bits) {
   return bigEndianHex4( bits );
}

char *toBits (Bits64 *bits) {
   char *s = malloc(nBits + 1);
   char *t = s;
   for (int i = 0; i < nBytes; i++) {
      for (int b = 7; b >= 0; b--) {
         *t++ = DIGITS[ (bits->byte[ENDIAN[i]] >> b) & 0x01 ];
      }
   }
   *t = '\0';
   return s;
}   // "10101111001110001111........"

char *littleEndianBit4 (Bits64 *bits) {;   
   char *s = malloc(nBits + nBits/4);
   char *t = s;
   for (int i = 0; i < nBytes; i++) {
      *t++ = DIGITS[ (bits->byte[i] >> 7) & 0x01 ];
      *t++ = DIGITS[ (bits->byte[i] >> 6) & 0x01 ];
      *t++ = DIGITS[ (bits->byte[i] >> 5) & 0x01 ];
      *t++ = DIGITS[ (bits->byte[i] >> 4) & 0x01 ];
      *t++ = '-';
      *t++ = DIGITS[ (bits->byte[i] >> 3) & 0x01 ];
      *t++ = DIGITS[ (bits->byte[i] >> 2) & 0x01 ];
      *t++ = DIGITS[ (bits->byte[i] >> 1) & 0x01 ];
      *t++ = DIGITS[  bits->byte[i] & 0x01 ];
      *t++ = (i < nBytes-1) ? ' ' : '\0';
   }
   return s;
}  // "1010-1111 0011-1000 1111-........"

char *bigEndianBit4 (Bits64 *bits) {   
   char *s = malloc(nBits + nBits/4);
   char *t = s;
   for (int i = 0; i < nBytes; i++) {
      *t++ = DIGITS[ (bits->byte[ENDIAN[i]] >> 7) & 0x01 ];
      *t++ = DIGITS[ (bits->byte[ENDIAN[i]] >> 6) & 0x01 ];
      *t++ = DIGITS[ (bits->byte[ENDIAN[i]] >> 5) & 0x01 ];
      *t++ = DIGITS[ (bits->byte[ENDIAN[i]] >> 4) & 0x01 ];
      *t++ = '-';
      *t++ = DIGITS[ (bits->byte[ENDIAN[i]] >> 3) & 0x01 ];
      *t++ = DIGITS[ (bits->byte[ENDIAN[i]] >> 2) & 0x01 ];
      *t++ = DIGITS[ (bits->byte[ENDIAN[i]] >> 1) & 0x01 ];
      *t++ = DIGITS[  bits->byte[ENDIAN[i]] & 0x01 ];
      *t++ = (i < nBytes-1) ? ' ' : '\0';
   }
   return s;
}  // "1010-1111 0011-1000 1111-........"

char *toBit4 (Bits64 *bits) {
   return bigEndianBit4( bits );
}

int  getBit (Bits64 *bits, int index) {
   return (bits->byte[ENDIAN[index/8]] >> (7 - index % 8)) & 0x01;
}

void setBit (Bits64 *bits, int index, int value) {
   int iB = ENDIAN[index/8];
   int b = 7 - index % 8;
   bits->byte[iB] = (value == 0) ? 
      (bits->byte[iB] & ~(0x01 << b)) & 0xFF :
      (bits->byte[iB] |  (0x01 << b)) & 0xFF ;
}
