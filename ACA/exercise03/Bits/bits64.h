// bits64.h
// MinGW Win32, Intel 64 bits CPU

//int : 4Byte   long : 4Byte   long long : 8Byte

#define nBytes  8
#define nBits   64
#define nHex    16
#define nDouble 1
#define nFloat  2
#define nLong   1
#define nInt    2
#define nShort  4

typedef union {
   unsigned char  byte[nBytes]; 
   double         inDouble;
   float          inFloats[nFloat];
   long long      inLong;
   unsigned long long  unLong;
   int            inInts[nInt];
   unsigned int   unInts[nInt];
   short          inShorts[nShort];
   unsigned short unShorts[nShort];
} Bits64;

char *toHexs (Bits64 *bits);   // "AE38FE84E48B36D2"
char *toBits (Bits64 *bits);   // "10101111001110001111........"
char *toHex4 (Bits64 *bits);   // "AE38 FE84 E48B 36D2"
char *toBit4 (Bits64 *bits);   // "1010-1111 0011-1000 1111-........"
char *littleEndianHex4 (Bits64 *bits);   // "AE38 FE84 E48B 36D2"
char *littleEndianBit4 (Bits64 *bits);   // "1010-1111 0011-1000 1111-........"
char *bigEndianHex4 (Bits64 *bits);      // "AE38 FE84 E48B 36D2"
char *bigEndianBit4 (Bits64 *bits);      // "1010-1111 0011-1000 1111-........"
int  getBit (Bits64 *bits, int index);              // in Big Endian
void setBit (Bits64 *bits, int index, int value);   // in Big Endian

char *DIGITS = "0123456789ABCDEF";
