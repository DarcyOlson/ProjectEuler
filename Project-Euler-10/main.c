#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*

This is code to solve the following problem:

The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.

*/
void initialize_sieve_array(int input[], int size){
    input[0] = 0;
    input[1] = 0;
    int i;
    for(i = 2;i < size;i++){
        input[i] = 1;
    }
}
void sieve_of_erastothenes(int input[], int size){
    initialize_sieve_array(input,size);
    int i;
    for(i = 2;i < size;i++){
        int j;
        for(j = 2;i*j < size;j++){
            input[i*j] = 0;
        }
    }
}

int main()
{
    int size = 2000000;
    int test[size];
    sieve_of_erastothenes(test,size);//Generates all primes less than 2*10^6
    int i;
    double sum = 0.0;//We use a double because an int would overflow
    for(i = 2;i < size;i++){
        if(test[i] != 0){
            sum = sum + (double)i;
        }
    }
    printf("The sum of all digits less than %d is %f",size,sum);
    return 0;
}
