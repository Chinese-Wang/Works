#include <stdio.h>
#include "bits64.c"

void printBits(Bits64 *bits)
{
   printf("%s\n", toBits(bits));
   printf("%s\n", toBit4(bits));
   printf("%s\n", toHexs(bits));
   printf("Big Endian:    %s\n", toHex4(bits));
   printf("Little Endian: %s\n\n", littleEndianHex4(bits));
}

int main( ) {
    Bits64 x;
    x.inFloats[0] = 4.8;
    x.inFloats[1] = 256.0;

    printf("byte: ");  //154       153     153     64      0       0       128     67
    for (int i = 0; i < nBytes; i++)
        printf("%d\t", x.byte[i]);
    
    printf("\ninDouble: %lf", x.inDouble); //144115222757716800.000000

    printf("\ninFloats:%f\t%f", x.inFloats[0], x.inFloats[1]); //4.800000       256.000000

    printf("\ninLong:%lld", x.inLong); //4863887598643943834

    printf("\nunLong:%lld", x.unLong); //4863887598643943834

    printf("\ninInts:%d\t%d", x.inInts[0], x.inInts[1]); //1083808154       1132462080

    printf("\nunInts:%d\t%d", x.unInts[0], x.unInts[1]); //1083808154       1132462080

    printf("\ninShorts:"); //-26214 16537   0       17280
    for (int i = 0; i < nShort; i++)
        printf("%d\t", x.inShorts[i]);

    printf("\nunShorts:"); //39322  16537   0       17280
    for (int i = 0; i < nShort; i++)
        printf("%d\t", x.unShorts[i]);
    
    printf("\n");
    printBits(&x);

    return 0;
}