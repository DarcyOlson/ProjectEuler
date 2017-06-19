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

int largest_prime_factor(double n){
    int factor_upper_bound = (int)ceil(sqrt(n));
    int primes[factor_upper_bound];
    initialize_sieve_array(primes,factor_upper_bound);
    sieve_of_erastothenes(primes,factor_upper_bound);
    return find_largest_prime_factor(primes,factor_upper_bound,n);
}
void initialize_sieve_array(int input[], int size){
    int i;
    input[0] = 0;
    input[1] = 0;
    for(i = 2; i < size; i++){
        input[i] = 1;
    }
}

int find_largest_prime_factor(int input[], int size, double big_num){
    int i;
    double largest = 0.0;
    for(i = 0; i < size; i++){
        if(input[i] != 0){
            double test = big_num/i;
            if((test - floor(test)) == 0){
                largest = i;
            }
        }
    }
    return (int)largest;
}
