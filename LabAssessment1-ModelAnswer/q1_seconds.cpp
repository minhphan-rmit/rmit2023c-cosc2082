#include <iostream>

int main() {
    int totalSecs, hours, mins, secs; 

    //Prompt user for input totoal seconds 
    printf("Input total amount of seconds: ");
    scanf("%d", &totalSecs);
	
    //Calculate hours, minutes, and remaining seconds
    hours = totalSecs / 3600; 
    mins = (totalSecs - (3600*hours)) / 60;
    secs =  totalSecs - (3600*hours) - (mins*60);
    printf("It is %d hour(s), %d minute(s) and %d second(s)", hours, mins, secs);
	
    return 0;
}