// bignum.h
#define MAXDIGITS 100       /* maximum length bignum */
#define PLUS 1              /* positive sign bit */
#define MINUS -1            /* negative sign bit */
typedef struct {
   char digits[MAXDIGITS];  /* represent the number */
   int signbit;             /* PLUS or MINUS */
   int lastdigit;           /* index of high-order digit */
} bignum;

void print_bignum (bignum *n);
void initialize_bignum (bignum *n);
void set_bignum (bignum *n, char* s);
void zero_justify (bignum *n);

int compare_bignum (bignum *a, bignum *b);

void subtract_bignum (bignum *a, bignum *b, bignum *c);
void add_bignum (bignum *a, bignum *b, bignum *c);
