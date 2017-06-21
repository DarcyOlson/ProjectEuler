#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*

This code is written to solve the following problem

2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 21000?

Our 2^1000 is much larger than any of the basic number types in C can hold, so we store the number in an array and then sum the entries of that array

*/
int digit_sum(int n){
    int sum = 0;
    while(n > 0){
        sum += n%10;
        n = n/10;
    }
    return sum;
}

int main()
{
    int exponent = 1000;
    int number_of_digits = floor(exponent*log10(2)) + 1;//Remember log(2^1000) = 1000*log(2) and that the number of digits in any number can be found by taking the floor of the base 10 log and adding 1
    int big_num[number_of_digits];
    big_num[number_of_digits-1] = 1;
    for(int i = number_of_digits - 2;i >= 0;i--){
        big_num[i] = 0;
    }
    printf("\n");
    int counter = 0;
    while(counter < exponent){
        for(int i = 0;i < number_of_digits;i++){
            big_num[i] = big_num[i]*2;
            if(big_num[i] > 9){
                big_num[i] = big_num[i] - 10;
                big_num[i-1] = big_num[i-1] + 1;
            }
        }
        counter++;
    }
    int sum = 0;
    for(int j = 0;j < number_of_digits;j++){
        sum += big_num[j];
    }
    printf("%d",sum);
    return 0;
}
