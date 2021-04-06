#include <stdio.h>

int leap(int y){ //function to know if year is a leap year
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0); //will return 0 if false, will return 1 if true
}

int DayOfYear(int j, int d){ //function to count the day of the year
	
	int month[] = {31,28+leap(j),31,30,31,30,31,31,30,31,30,31};
	int i, dayYear=0;

	for (i=0; i<(j-1); i++) {
    dayYear += month[i];
	}

	dayYear += d;

return dayYear;
}

int DayOfWeek(int k){ //function to know the day of the week 	
	return ((1 + 5 * ((k - 1) % 4)) + 4 * ((k - 1) % 100) + 6 * ((k - 1) % 400)) % 7; //GIATAY NGANU JUD NI
}
	
int main (){
	
	int day, yr, mon;
	
	printf("Enter a date (YYYY MM DD): ");
	scanf("%i %i %i", &yr, &mon, &day);

	switch (DayOfWeek(yr)){
      case 0:
         printf("Sunday, ");
         break;
      case 1:
         printf("Monday, ");
         break;
      case 2:
         printf("Tuesday, ");
         break;
      case 3:
         printf("Wednesday, ");
         break;
      case 4:
         printf("Thursday, ");
         break;
      case 5:
         printf("Friday, ");
         break;
      case 6:
         printf("Saturday, ");
         break;
      default:
         printf("Incorrect data");
   }

	switch (DayOfYear(mon, day) % 10){
      case 1:
         printf("%dst day of the year\n", DayOfYear(mon, day));
         break;
      case 2:
         printf("%dnd day of the year\n", DayOfYear(mon, day));
         break;
      case 3:
         printf("%drd day of the year\n", DayOfYear(mon, day));
         break;
      default:
         printf("%dth day of the year\n", DayOfYear(mon, day));
    }

return 0;
}
