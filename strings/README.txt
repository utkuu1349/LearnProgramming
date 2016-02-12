There are two types of strings in C.
    1. Char arrays
    2. String Literals

"This is a string literal (static string)."
char string[50];

They behave similar and can both be passed to functions that accept char arrays
unless function tries to change the string. Then string literal will cause the 
program to crash.

'a' // single character, not a string. You cannot pass this to a function that
        accepts strings. Chars don't act like pointers.

All strings in C are terminated by '\0' char.
-----------------------------------------------------------------------------

-------------------USING STRINGS---------------------------------------------

char *fgets (char *str, int size, FILE* file); //prototype for fgets
                                               //located in stdio.h
//pass stdin to FILE* file, this is a defined variable in stdio.h
//it tells fgets to read from standard input device (keyboard)

-------------------MANIPULATING C STRINGS USING STRING.H---------------------

int strcmp (const char *s1, const char *s2);
*/Negative if s1 is less than s2.
Zero if s1 and s2 are equal.
Positive if s1 is greater than s2.*/

char *strcat (char *dest, const char *src); // Add src to the end of the dest.

char *strcpy (char *dest, const char *src); //Copy src to dest.

size_t strlen (const char *s); //Will return the length of the string 
                               //minus the terminating char

//size_t is actually just an integer that can't be negative
//it is used to indicate that the number is the size of something

char *strncpy (char *dest, const char *src, size_t len);
/*will only copy len bytes from src to dest 
(len should be less than the size of dest or the write could
still go beyond the bounds of the array)*/














