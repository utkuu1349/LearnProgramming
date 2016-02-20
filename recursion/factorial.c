// this program calculates the factorial of an integer using recursion

#include <stdio.h>

void factorial (int number, int *ptr);

int main () {
    int number;
    int result = 1;
    int *ptr;
    ptr = &result;
    printf("Please enter number:\n");
    scanf("%d", &number);
    factorial(number, ptr);
    printf("%d\n", result);
}

void factorial (int number,int *ptr) {    
    if (number == 0) {
        *ptr = 1;
        return;
    }
    *ptr = *ptr * number;
    if (number > 1) {
        factorial ((number - 1), ptr);   
    }
}
