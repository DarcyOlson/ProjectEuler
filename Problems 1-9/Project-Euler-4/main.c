#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*

    This code solves the following problem:

    "A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

    Find the largest palindrome made from the product of two 3-digit numbers."

*/
/*
This is code that was written to generate all palindromes that ended up not being used in the final product
void generate_palindrome(int input[], int size){
    int counter = 0;
        int j;
        for(j = 1;j < 10;j++){
            int k;
            for(k = 0;k < 10;k++){
                int l;
                for(l = 0;l < 10;l++){
                    counter++;
                    input[counter] = 100000*j+10000*k+1000*l+100*l+10*k+j;
                }
            }
        }
}*/
//This function will output the reverse (i.e. the palindrome) of the integer input
int reverse_number(int n){
    int reverse = 0;
    while(n > 0){
        reverse = 10*reverse + n%10;
        n = n/10;
    }
    return reverse;
}
//This function determines if an input is a palindrome, returning 1 if it is and 0 if it is not
int is_palindrome(int n){
    if(n == reverse_number(n)){//If number is equal to its reverse (i.e. it's a palindrome) return 1
        return 1;
    }else{//else return 0
        return 0;
    }
}
//This returns the largest palindrome that is the product of two 3 digit numbers
void largest_palindrome(){
    int a = 999, largest_palindrome = 0;
    while(a >= 100){//100 is the smallest 3 digit number so we stop here
        int b = 999;
        while(b >= 100){
            if(is_palindrome(a*b) == 1 && a*b > largest_palindrome){
                largest_palindrome = a*b;
            }
            b--;
        }
        a--;
    }
    printf("%d is the largest palindrome that is a product of two 3 digit integers",largest_palindrome);
}
int main(){
    largest_palindrome();
    return 0;
}
