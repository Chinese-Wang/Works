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

    printf("byte: ");
    for (int i = 0; i < nBytes; i++)
        printf("%d\t", x.byte[i]);
    
    printf("\ninDouble: %lf", x.inDouble);

    printf("\ninFloats:%f\t%f", x.inFloats[0], x.inFloats[1]);

    printf("\ninLong:%lld", x.inLong);

    printf("\nunLong:%lld", x.unLong);

    printf("\ninInts:%d\t%d", x.inInts[0], x.inInts[1]);

    printf("\nunInts:%d\t%d", x.unInts[0], x.unInts[1]);

    printf("\ninShorts:");
    for (int i = 0; i < nShort; i++)
        printf("%d\t", x.inShorts[i]);

    printf("\nunShorts:");
    for (int i = 0; i < nShort; i++)
        printf("%d\t", x.unShorts[i]);
    
    printf("\n");
    printBits(&x);

    return 0;
}