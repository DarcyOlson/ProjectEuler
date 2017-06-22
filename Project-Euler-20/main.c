#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//This function returns the number of digits n! has using the formula number_of_digits(n) = floor(log10(n))+1 and the identity log(AB) = log(A) + log(B)
int factorial_number_of_digits(int n){
    double sum = 0.0;
    for(int i = 1;i <= n;i++){
        sum += log10(i);
    }
    int number_of_digits = (int)floor(sum) + 1;//This adds the one at the end of the number of digits formula
    return number_of_digits;
}

void scalar_multiplication(int input[], int size, int scalar){
    for(int i = 0;i < size;i++){
        input[i] = scalar*input[i];
    }
}

void overflow_scan(int input[], int size){
    for(int i = size - 1;i > 0;i--){
        while(input[i] > 9){
            input[i] = input[i] - 10;
            input[i-1]++;
        }
    }
}

void print_array(int input[],int size){
    printf("[");
    for(int i = 0;i < size - 1;i++){
        printf("%d,",input[i]);
    }
    printf("%d",input[size - 1]);
    printf("] \n");
}

int digit_sum(int input[],int size){
    int sum = 0;
    for(int i = 0;i < size;i++){
        sum += input[i];
    }
    return sum;
}
int main()
{
    int factorial_number = 100;
    int num_digits = factorial_number_of_digits(factorial_number);
    int huge_number[num_digits];
    //printf("The number of digits for test case %d is %d \n",factorial_number,factorial_number_of_digits(factorial_number));
    for(int i = 0;i < num_digits - 1;i++){
        huge_number[i] = 0;
    }
    huge_number[num_digits - 1] = 1;
    for(int i = 1;i <= factorial_number;i++){
        scalar_multiplication(huge_number,num_digits,i);
        overflow_scan(huge_number,num_digits);
    }
    int answer = digit_sum(huge_number,num_digits);
    printf("%d", answer);
    return 0;
}
