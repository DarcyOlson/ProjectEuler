#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
    This code solves the following problem:

    The prime factors of 13195 are 5, 7, 13 and 29.

    What is the largest prime factor of the number 600851475143 ?
*/
int largest_prime_factor(double n);//This function will find the largest prime factor of a given input
void sieve_of_erastothenes(int input[], int size);//This function will find all prime numbers less than size
void initialize_sieve_array(int input[], int size);
int find_largest_prime_factor(int input[], int size, double large_num);

int main()
{
    double big_num = 600851475143.0;
    printf("The largest prime factor of %f is %d",big_num, largest_prime_factor(big_num));
    return 0;
}

/*
This is a method to generate prime numbers less than size. It follows the following steps:
1) Take input n
2) Create array of n variables
3) Set every element in the array to 1
4) Set the first and second element to 0 (these elements represent 0 and 1, neither of which are prime)
5) For every element 2 to n, scan the array and set all multiples of this element to 0
6) All remaining non-zero elements must be prime
*/
void sieve_of_erastothenes(int input[], int size){
    initialize_sieve_array(input,size);
    int i;
    for(i = 2;i < size;i++){
        if(input[i] == 1){
            int j;
            for(j = 2; j*i < size; j++){
                input[j*i] = 0;
            }
        }
    }
}
//this function will provide
int largest_prime_factor(double n){
    int factor_upper_bound = (int)ceil(sqrt(n));//Computes the max value of a factor of input and casts it as an int so that it can be used to size an array
    int primes[factor_upper_bound];
    sieve_of_erastothenes(primes,factor_upper_bound);//Finds all primes that could be factors of input using the criterion that a prime less than the square root of input is a plausible candidate
    return find_largest_prime_factor(primes,factor_upper_bound,n);//Tests all primes to see if they're multiples of input
}

//this method performs steps steps 1-3 of the sieve of erastothenes
void initialize_sieve_array(int input[], int size){
    int i;
    //steps 1 and 2
    input[0] = 0;
    input[1] = 0;
    //step 3
    for(i = 2; i < size; i++){
        input[i] = 1;
    }
}
//Scans an array of integers to find the largest prime factor of big_num
int find_largest_prime_factor(int input[], int size, double big_num){
    int i;
    double largest = 0.0;
    for(i = 0; i < size; i++){
        if(input[i] != 0){
            double test = big_num/i;
            if((test - floor(test)) == 0){//Calculates the fractional part of a number. If the fractional part is zero, the number is an integer and divides big_num. Since the array is in ascending order, this new factor is now largest.
                largest = i;
            }
        }
    }
    return (int)largest;//We cast as an int here because the return type is an integer. The return type is an integer because factors are always integers.
}
