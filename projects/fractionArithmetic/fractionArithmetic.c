#include <stdio.h>

void add(int *fracs, int *result);
void sub(int *fracs, int *result);
void mult(int *fracs, int *result);
void div(int *fracs, int *result);
void reciprocal(int *fracs);
void reduce(int *result);

int main() {
    char op;
    int fracs[4];
    int result[2];
    //int number_of_fractions;

//ask user for 1, 2 or more fractions (only two for now) 
    printf("Please select an operation: + - * /\n");
    scanf("%c", &op);
    if (!(op == '+' || op == '-' || op == '*' || op == '/' )) {
        printf("Bad input, quitting!\n");
        return -1;
    }
    printf("Please input two fractions\n");
    printf("Example:\n2/3 4/5\n");
    scanf("%d/%d %d/%d", fracs, fracs+1, fracs+2, fracs+3);
    printf("Your fractions are: %d/%d and %d/%d\n", 
    *fracs, *(fracs+1), *(fracs+2), *(fracs+3));

//ask user which operation they want to do
//add, subtract, multiply, divide
    
    switch (op) {
        case '+':
            printf("You selected addition\n");
            reciprocal(fracs);            
            add(fracs, result);
            reduce(result);
            break;
        case '-':
            printf("You selected subtraction\n");
            reciprocal(fracs);
            sub(fracs, result);
            reduce(result);
            break;
        case '*':
            printf("You selected multiplication\n");
            mult(fracs, result);
            reduce(result);
            break;        
        case '/':
            printf("You selected division\n");
            div(fracs, result);
            reduce(result);
            break;
        //default:
            //printf("Bad input, quitting!\n");
            //break;
    }

//divide the fractions to their numerator and denumerator (already done that)

//get its reciprocal

//reduce the fraction to lowest terms

//print out the result
    printf("Your result is:\n");
    printf("%d/%d \n", *result, *(result+1));
}

// operation functions
void add(int *fracs, int *result){
    printf("ADD is called\n");
    if (*(fracs + 1) != *(fracs + 3)) {
        printf("Denumerators don't match. Some error during reciprocal!\n");
        printf("QUITTING!");
        return;       
    } 
    *result = *(fracs) + *(fracs + 2);
    *(result + 1) = *(fracs + 1);
}
void sub(int *fracs, int *result){
    printf("SUB is called\n"); 
    if (*(fracs + 1) != *(fracs + 3)) {
        printf("Denumerators don't match. Some error during reciprocal!\n");
        printf("Quitting!\n");
        return;
    }
    *result = *(fracs) - *(fracs + 2);
    *(result + 1) = *(fracs + 1);
}
void mult(int *fracs, int *result){
    printf("MULT is called\n");
    *(result) = *(fracs) * *(fracs + 2);
    *(result + 1) = *(fracs + 1) * *(fracs + 3); 
}
void div(int *fracs, int *result){
    printf("DIV is called\n"); 
    *(result) = *(fracs) * *(fracs + 3);
    *(result + 1) = *(fracs + 1) * *(fracs + 2);
}
void reciprocal(int *fracs){
    printf("RECIPROCAL is called\n");
    if (*(fracs + 1) == *(fracs + 3)) {
        printf("Denumerators are already equal nothing to do here!");
        return;
    }
    *(fracs) = *(fracs) * *(fracs + 3 );        //1st num
    *(fracs + 2) = *(fracs + 2) * *(fracs + 1); //2nd num
    *(fracs + 1) = *(fracs + 1) * *(fracs + 3); //common denum
    *(fracs + 3) = *(fracs + 1);                //2nd denum to common denum
    printf("Your fractions with common denumerator are:\n");
    printf("%d/%d and %d/%d\n",
                         *(fracs), *(fracs + 1), *(fracs +2), *(fracs + 3));
}   
void reduce(int *result){
    //int j = 1; // this becomes 0 if i reaches to 1 and cant find any common denum 
    printf("REDUCE is called\n");
    printf("Fraction before reduce: %d/%d\n", *result, *(result +1));
    if (*result == *(result + 1)) {
        *result = 1;
        *(result + 1) = 1;    
    }
    else if (*result < *(result + 1)) {
        for (int i = *(result); i > 1; i-- ) {
            if (*(result) % i == 0 && *(result + 1) % i == 0) {
                *(result) = *(result) / i;
                *(result + 1) = *(result +1 ) / i;            
            }
        }
        
    }
    else {
        for (int i = *(result + 1); i > 1; i-- ) {
            if (*(result) % i == 0 && *(result + 1) % i == 0) {
                *(result) = *(result) / i;
                *(result + 1) = *(result +1 ) / i; 
            }     
        }
    }
    printf("Fraction after reduce: %d/%d\n", *result, *(result + 1));
}



