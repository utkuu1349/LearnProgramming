#include <ncurses.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
    int ch, prev, row, col;
    prev = EOF;
    FILE *fp;
    int y, x;
    if(argc != 2) {
        printf("Usage: %s <a c file name>\n", argv[0]);
        exit(1);
    }
    fp = fopen(argv[1], "r");
    if(fp == NULL) {
        perror("Cannot open input file");
        exit(1);
    }
    initscr();                      /* Start curses mode */
    getmaxyx(stdscr, row, col);     // dfind the boundaries of the screen
    while (ch = fgetc(fp) != EOF) { // read the file till we reach the end
        getyx(stdscr, y, x);        // get the current curser position
        if (y == (row - 1)) {       // are we at the end of the screen
            printw("<-Press Any Key->");
            getch();
            clear();                //clear the screen
            move(0, 0);
        }
        if (prev == '/' && ch == '*') { // If it is / and * then only
                                        // switch bold on
        attron(A_BOLD);                 // cut bold on
        getyx(stdscr, y, x);            // get the current curser position
        move(y, x - 1);                 // back up one space
        printw("%c%c", '/', ch);        // The actual printing is done here
        }
        else {
            printw("%c", ch);
        }
        refresh();
        if (prev == '*' && ch == '/') {
            attroff(A_BOLD);
        }
        prev = ch;
    }
    endwin();
    fclose(fp);
    return 0;
}





