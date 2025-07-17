#include <stdio.h>
#include <stdbool.h>
bool isLeapYear(int year){
  if (year % 4 != 0){
    return false;
  } else if (year % 100 == 0){
    if (year % 400 == 0){
    return true;
    } else {
      return false;
    }
  } else {
    return true;
  }
}
//array of days in each month, non leap year
int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void addDaysToDate(int* mm, int* dd, int* yy, int daysLeftToAdd){
  int daysLeftInMonth;
  while (daysLeftToAdd > 0){
    daysLeftInMonth = daysInMonth[*mm];
    //to add an extra day for leap years
    if (*mm ==2 && isLeapYear(*yy)){
      daysLeftInMonth += 1;
    }
    //calc days left in current month
    daysLeftInMonth -= *dd;
      //move to next month
      if (daysLeftToAdd > daysLeftInMonth){
        daysLeftToAdd -= daysLeftInMonth + 1;
        *dd = 1;
        if (*mm == 12) { 
          //if dec need to go to next yr
          *mm = 1; //reset to Jan
          *yy += 1; //inc yr
        //daysLeftInMonth --;
        } else {
          *mm += 1; //inc mm
        } 
      } else {
      *dd += daysLeftToAdd;
      daysLeftToAdd = 0;
    }
  }
}



int main() {
  int mm, dd, yy, daysLeftToAdd;
  printf("Enter a year between 1800 and 10000 in format mm dd yyyy: ");
  scanf("%d %d %d %d", &mm, &dd, &yy, &daysLeftToAdd);
  if (isLeapYear(yy)){
    printf("Leap Year\n");
    } else {
      printf("Not Leap Year\n");
    }
    addDaysToDate(&mm, &dd, &yy, daysLeftToAdd);
    printf("After adding %d days: %d/%d/%d US format.\n", daysLeftToAdd, mm, dd, yy);
    return 0;
}
