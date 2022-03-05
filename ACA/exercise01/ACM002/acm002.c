<<<<<<< HEAD
#include <stdio.h>

typedef struct Date{
    int year;
    int month;
    int day;
}Date;

int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int isLeapYear (int year){
    int leap = 0;

    if ( (year % 4 == 0 && year % 100 != 0) || year % 400 == 0 )
        leap = 1;
        
    return leap;
}

int daysPassed (Date borrowDate , Date returnDate){
    int days = 0;

    for (int i = borrowDate.year; i <= returnDate.year; i++){
        if(isLeapYear(i))
            days += 366;
        else
            days += 365;
    }

    for (int i = 1; i < borrowDate.month; i++){
        if (i == 2 && isLeapYear(borrowDate.year))
            days -= 29;
        else
            days -= monthDays[i - 1];
    }
    days -= borrowDate.day;

    for (int i = returnDate.month; i < 13; i++){
        if (i == 2 && isLeapYear(returnDate.year))
            days -= 29;
        else
            days -= monthDays[i - 1];
    }
    days += returnDate.day;

    return days;
}

Date DateFrom (char* sDate){
    Date date;

    for ( int i = 0; i < 8; i++)
        sDate[i] -= 48;
    
    date.year = sDate[0] * 1000 + sDate[1] * 100 + sDate[2] * 10 + sDate[3];
    date.month = sDate[4] * 10 + sDate[5];
    date.day = sDate[6] * 10 + sDate[7];

    return date;
}

double lateFee (char* borrowDay, char* returnDay) {
    double fee = 0;

    int passDays;

    Date borrowDate, returnDate;

    borrowDate = DateFrom(borrowDay);
    returnDate = DateFrom(returnDay);

    passDays = daysPassed(borrowDate, returnDate);

    if (passDays < 31)
        fee = 0.0;
    else if ( passDays > 180)
        fee = 250.0;
    else if( passDays < 61)
        fee = (passDays - 30) * 0.5;
    else
        fee = (passDays - 60) * 0.7 + 15.0;
    
    return fee;
}

int main () {
    char borrowDay[9], returnDay[9];
    double fee;

    while (scanf("%s %s", borrowDay, returnDay) != EOF){
        fee = lateFee(borrowDay, returnDay);
        if(fee == 0.0)
            printf("The return is successful!\n");
        else
            printf("You are late, please pay $%.1f!\n", fee);
    }
    
    return 0;
=======
#include <stdio.h>

typedef struct Date{
    int year;
    int month;
    int day;
}Date;

int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int isLeapYear (int year){
    int leap = 0;

    if ( (year % 4 == 0 && year % 100 != 0) || year % 400 == 0 )
        leap = 1;
        
    return leap;
}

int daysPassed (Date borrowDate , Date returnDate){
    int days = 0;

    for (int i = borrowDate.year; i <= returnDate.year; i++){
        if(isLeapYear(i))
            days += 366;
        else
            days += 365;
    }

    for (int i = 1; i < borrowDate.month; i++){
        if (i == 2 && isLeapYear(borrowDate.year))
            days -= 29;
        else
            days -= monthDays[i - 1];
    }
    days -= borrowDate.day;

    for (int i = returnDate.month; i < 13; i++){
        if (i == 2 && isLeapYear(returnDate.year))
            days -= 29;
        else
            days -= monthDays[i - 1];
    }
    days += returnDate.day;

    return days;
}

Date DateFrom (char* sDate){
    Date date;

    for ( int i = 0; i < 8; i++)
        sDate[i] -= 48;
    
    date.year = sDate[0] * 1000 + sDate[1] * 100 + sDate[2] * 10 + sDate[3];
    date.month = sDate[4] * 10 + sDate[5];
    date.day = sDate[6] * 10 + sDate[7];

    return date;
}

double lateFee (char* borrowDay, char* returnDay) {
    double fee = 0;

    int passDays;

    Date borrowDate, returnDate;

    borrowDate = DateFrom(borrowDay);
    returnDate = DateFrom(returnDay);

    passDays = daysPassed(borrowDate, returnDate);

    if (passDays < 31)
        fee = 0.0;
    else if ( passDays > 180)
        fee = 250.0;
    else if( passDays < 61)
        fee = (passDays - 30) * 0.5;
    else
        fee = (passDays - 60) * 0.7 + 15.0;
    
    return fee;
}

int main () {
    char borrowDay[9], returnDay[9];
    double fee;

    while (scanf("%s %s", borrowDay, returnDay) != EOF){
        fee = lateFee(borrowDay, returnDay);
        if(fee == 0.0)
            printf("The return is successful!\n");
        else
            printf("You are late, please pay $%.1f!\n", fee);
    }
    
    return 0;
>>>>>>> 0aa3fb0a71e3b24c81e0cba3065f97bbc676435e
}