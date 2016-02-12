#include <stdio.h>

void add(int *fracs);
void sub(int *fracs);
void mult(int *fracs);
void div(int *fracs);

int main() {
    char op;
    int fracs[4];

//ask user for 1, 2 or more fractions
    printf("Please input two fractions\n");
    printf("Example:\n2/3 4/5\n");
    scanf("%d/%d %d/%d", fracs, fracs+1, fracs+2, fracs+3);
    printf("Your fractions are: %d/%d and %d/%d\n", 
    *fracs, *(fracs+1), *(fracs+2), *(fracs+3));

//ask user which operation they want to do
//add, subtract, multiply, divide
    printf("Please select an operation: + - * /\n");
    scanf("%c", &op);
    switch (op) {
        case '+':
            printf("You selected addition\n");
            break;
        case '-':
            printf("You selected subtraction\n");
            break;
        case '*':
            printf("You selected multiplication\n");
            break;        
        case '/':
            printf("You selected division\n");
            break;
        default:
            printf("Bad input, quitting!\n");
            break;
    }

//divide the fractions to their numerator and denumerator

//get its reciprocal

//reduce the fraction to lowest terms

//print out the result
}


