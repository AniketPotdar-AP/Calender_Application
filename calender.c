#include <stdio.h>

/*-------------- It Will Help to Find The Day of Week of Day Zero Of Given Year -----------------*/

int get_1st_day(int year)
{
    int d;
    d = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;
    return d;
}

int main()
{

    int year, month, day, daysInMonth, startingday;
    int weekday = 0;

    /*---------------------------------- It Will Take The User Input -----------------------------*/

    printf("\nEnter Your Desired Year :- ");
    scanf("%d", &year);

    /*------------ It Will Create The array Of Month And The End Date Of The Month ---------------*/

    char *months[] = {"January", "February", "March", "April", "May", "June", "July",
                      "August", "September", "Octomber", "November", "December"};

    int month_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    /*------------------------------- It Will Create a Days of The Week --------------------------*/

    startingday = get_1st_day(year);
    for (month = 0; month < 12; month++)
    {
        printf("\n\n------------- %s ----------------\n", months[month]);
        printf("\n\n  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n\n");

        for (weekday = 0; weekday < startingday; weekday++)
        {
            printf("     ");
        }

        /*------------------- It Will set The Date In A Week Refering To Days Of The Week ------------*/

        daysInMonth = month_days[month];
        for (day = 1; day <= daysInMonth; day++)
        {
            printf("%5d", day);

            if (++weekday > 6)
            {
                printf("\n");
                weekday = 0;
            }
            startingday = weekday;
        }
    }

    /*--------------------------- It Will Help To Display Date In Leap Year ----------------------*/

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        month_days[1] = 29;
    }

    return 0;
}
