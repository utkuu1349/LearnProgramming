#include <stdio.h> //stdin, printf, and gets
#include <string.h> // for all the new-fangled string functions

/* this function is designed to remove the newline from the end of  a string 
entered using fgets. Note that since we make this into its own function, we 
could easily choose a better tehcnique for removing the newline. Aren't 
functions great? */

void strip_newline (char *str, int size) {
    int i;
    
    //remove the null terminator
    for (i = 0; i < size; i++) {
        if (str[i]=='\n') {
            
            str[i] = '\0';
            // we are done, so just exit the function by returning
            return; 
        }
    }
    // if we get all the way to here, there must not have been a newline!
}

int main () {
    char name[50];
    char lastname[50]; 
    char fullname[100]; //big enough to hold both name and lastname

    printf("Please enter your name: ");
    fgets(name, 50, stdin);

    //see definition above
    strip_newline(name, 50);

    //strcmp returns zero when the two string are equal
    if (strcmp(name, "Alex") == 0){
        printf("That's my name too.\n");
    }
    else{
        printf("That's not my name.\n");
    }
    // Find the length of your name
    printf("Your name is %zu letters long\n", strlen(name));
    /* %zu is used because gcc gives an error that says strlen returns
    size_t and you can't use %d or %i for it*/
    printf("Enter your last name: ");
    fgets(lastname, 50, stdin);
    strip_newline(lastname, 50);
    fullname[0] = '\0';
    /* strcat will look for the \0 and add the second string starting at
        that location */
    strcat(fullname, name); // copy name into full name
    strcat(fullname, " ");  // separate the names by a space
    strcat(fullname, lastname); // copy lastname onto the end of fullname
    printf("Your full name is %s\n", fullname);

    return 0;
    //some change
}
