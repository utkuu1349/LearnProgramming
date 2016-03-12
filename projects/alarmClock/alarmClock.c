/*  ALARM CLOCK

    . Show current time using a "label"
    . Allow user select a given time and specify a message
    . When clock reaches that time have it pop up and play a sound file

 */

#include <time.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

int main () {

    // show current time
    
    struct tm *present_time;
    struct tm *alarm_time;
    alarm_time = malloc (sizeof(*alarm_time)); 
    char msg[80];
    int y, x;
       
    initscr();
    getmaxyx(stdscr, y, x);   
    
    printw("\nEnter time (HH:MM) -> ");
    scanw("%i:%i\n", &(alarm_time->tm_hour), &(alarm_time->tm_min));
    printw("Enter a message:\n");
    scanw("%s", msg);
/*    mvprintw(LINES - 5, 0, "You just entered: %s", msg);   */
	clear();
    refresh();
    
    while (1)  {
    	time_t now = time(NULL);
   		present_time = localtime(&now);
    	mvprintw (y/2 , (x - 19)/2, "%02d.%02d.%d %02d:%02d:%02d\n",
    	present_time->tm_mday, 
    	present_time->tm_mon + 1, 
    	present_time->tm_year + 1900,
    	present_time->tm_hour,
   	 	present_time->tm_min,
    	present_time->tm_sec);   	
    	refresh();
    	if (1 || alarm_time->tm_hour == present_time->tm_hour && alarm_time->tm_min == present_time->tm_min) {
    		clear();
    		mvprintw(y/2, (x - 10)/2, "%02d:%02d -> %s\n", 
    		alarm_time->tm_hour,
    		alarm_time->tm_min, msg);
    		refresh();
    		getch();
    		endwin();
    		return 1;
    	
    	}   
    }
    	
    getch();
    endwin();

    return 0;







}
