<<<<<<< HEAD
#include <stdio.h>

int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int minDigitChanges (int m, int d) {
    int ans = 0;

    if ( m > 12 ){
        if ( m < 20 )
            m = 12;
        else if ( m % 10 == 2 )
            m = 12;
        else if (m % 10 == 0)
            m = 10;
        else 
            m %= 10;
        ans++;
    }
    
    if ( d > monthDays[m-1] || d < 1 )
        ans++;
    return ans;
}

int main () {
    int month, day;
    while (scanf("%d", &month) != EOF) {
        scanf( "%d", &day );
        printf( "%d\n", minDigitChanges( month, day ) );
    }
    return 0;
}
=======
#include <stdio.h>

int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int minDigitChanges (int m, int d) {
    int ans = 0;

    if ( m > 12 ){
        if ( m < 20 )
            m = 12;
        else if ( m % 10 == 2 )
            m = 12;
        else if (m % 10 == 0)
            m = 10;
        else 
            m %= 10;
        ans++;
    }
    
    if ( d > monthDays[m-1] || d < 1 )
        ans++;
    return ans;
}

int main () {
    int month, day;
    while (scanf("%d", &month) != EOF) {
        scanf( "%d", &day );
        printf( "%d\n", minDigitChanges( month, day ) );
    }
    return 0;
}
>>>>>>> 0aa3fb0a71e3b24c81e0cba3065f97bbc676435e
