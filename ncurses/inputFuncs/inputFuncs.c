#include <ncurses.h>    // ncurses.h includes stdio.h
#include <string.h>

int main () {
    char mesg[] = "Enter a string: ";   // message to be appeared on screen
    char str[80];
    int row, col;

    initscr();
    getmaxyx(stdscr, row, col);
    mvprintw(row/2, (col-strlen(mesg))/2, "%s", mesg);
        //print the message at the center of the screen
    getstr(str);
    mvprintw(LINES - 2, 0, "You Entered: %s", str);
    getch();
    endwin();

    return 0;
}
