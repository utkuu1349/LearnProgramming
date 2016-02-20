/*  ALARM CLOCK

    . Show current time using a "label"
    . Allow user select a given time and specify a message
    . When clock reaches that time have it pop up and play a sound file

 */

#include <time.h>
#include <stdio.h>

int main () {

    // show current time
    time_t now = time(NULL);
    struct tm *present_time;
/*    printf("%d\n", (int)now);*/
    present_time = localtime(&now);
/*    printf("tm_day: %d\n",present_time -> tm_mday);*/
/*    printf("tm_mon: %d\n", present_time -> tm_mon);*/
/*    printf("tm_year: %d\n", present_time -> tm_year);*/
    printf ("%02d.%02d.%d %02d:%02d:%02d\n",
    present_time->tm_mday, 
    present_time->tm_mon + 1, 
    present_time->tm_year + 1900,
    present_time->tm_hour,
    present_time->tm_min,
    present_time->tm_sec);









}
