#include "stdio.h"
#include "string.h"

void toShow(int inputYear, int total, char months[15][20], char days[15][20]) {

    //Это выведет на экран общее количество "черных" дней

    printf("\n%d had: %d \"black\" days\n", inputYear, total);

    //Более детальная информация, конкретные месяца, дни недели и числа

    for (int i = 0; i<total; i++) {
        printf("\n%10s%10s\t13th \n", months[i], days[i]);
    }
}
int countBlackDays(int year0, char nameOfMonth[15][20], char nameOfWeekday[15][20]) {
    int count = 0;
    int year;
    int month;

    //Список месяцев

    char listOfMonths[15][20];
    strcpy(listOfMonths[3], "March");
    strcpy(listOfMonths[4], "April");
    strcpy(listOfMonths[5], "May");
    strcpy(listOfMonths[6], "June");
    strcpy(listOfMonths[7], "July");
    strcpy(listOfMonths[8], "August");
    strcpy(listOfMonths[9], "September");
    strcpy(listOfMonths[10], "October");
    strcpy(listOfMonths[11], "November");
    strcpy(listOfMonths[12], "December");
    strcpy(listOfMonths[13], "January");
    strcpy(listOfMonths[14], "February");

    //3 - Вторник, 6 - Пятница. Связано с особенностями формулы

    int tuesday = 3;
    int friday = 6;

    //Нужное нам число месяца, при необходимости изменить значение здесь

    int date = 13;

    //Согласно формуле Зеллера, Январь и Февраль высчитываются как 13-ый и 14-ый месяц предыдущего года соответственно

    for (int m = 1; m<13; m++) {
        if (m<3) {
            month = m + 12; year = year0 - 1;
        }
        else {
            month = m; year = year0;
        }

        //Учитываем високосные года

        int c = year / 100;
        int y = year % 100;

        //Вычисляем дни недели согласно формуле Зеллера

        int weekday = ((month + 1) * 26 / 10 + date + y + y / 4 + c / 4 - 2 * c) % 7;


       if (weekday == tuesday) {
            strcpy(nameOfMonth[count], listOfMonths[month]);
            strcpy(nameOfWeekday[count], "Tuesday");
            count++;
        } else if (weekday == friday) {
            strcpy(nameOfMonth[count], listOfMonths[month]);
            strcpy(nameOfWeekday[count], "Friday");
            count++;
        }
    }
    return count;
}
int main(){
    int blackDays;
    int year0;
    char nameOfMonth[15][20];
    char nameOfWeekday[15][20];

    printf("Type in a year which you would like to inspect for \"black\" days: ");

    scanf("%d", &year0);

    blackDays = countBlackDays(year0, nameOfMonth, nameOfWeekday);

    toShow(year0, blackDays, nameOfMonth, nameOfWeekday);

    getch();
}
