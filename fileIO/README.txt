FILE *fp; // file pointer, thats how C knows which file you're working on


-------------------------fopen-------------------------------------

FILE *fopen(const char *filename, const char *mode);
/* filename is a string literal */


fopen modes--------------------------------------------------------
r - open for reading
w - open for writing (file need not exist)
a - open for appending (file need not exist)
r+ - open for reading and writing, start a begining
w+ - open for reading and writing (overwrite file)
a+ - open for reading and writing (append if file exist)
//add b to the end of open mode to open the file in binary mode
//ex: rb, r+b, rb+ etc.

//fopen will return NULL pointer if it fails to open the file

FILE *fp;
fp = fopen("c:\\test.txt", "r");


-------------------------fclose---------------------------------

int fclose(FILE *a_file); //returns zero if the file is closed successfully

fclose(fp);


----------reading and writing with fprintf, fscanf, fputc, fgetc----------

FILE *fp;
fp = fopen("c:\\test.txt", "w");
fprintf(fp, "Testing...\n");

int fgetc (FILE *fp); /* read a single char from a file if it reaches to the
end of the file it returns a special EOF value */

int fputc (int c, FILE *fp); /* first argument is the value of the char to
be written, second argument is the file pointer to file to write to on
success it will return the value of c, on failure, it will return EOF. */


--------------------binary file I/O - fread and fwrite--------------------

size_t fread (void *ptr, size_t size_of_elements, size_t number_of_elements, FILE *a_file);
size_t fwrite (const void *ptr, size_t size_of_elements, size_t number_of_elements, FILE *a_file);

/* void *ptr means that it is a pointer that can be used for any type of 
variable.
size_of_elements is the size of the each element of the array, in bytes
you can use sizeof() to get the exact size of each type of element
number_of_elements is the number of elements in your array of struct
file pointer is the pointer to the file we're working on */

FILE *fp;
fp = fopen("c:\\test.bin", "wb");
char x[10] = "ABCDEFGHIJ";
fwrite(x, sizeof(x[0]), sizeof(x)/sizeof(x[0]), fp);

















































