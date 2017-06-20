#include <stdio.h>
#include <stdlib.h>
void sieve_of_erastothenes(int input[], int size);
void initialize_sieve_array(int input[], int size);
void find_nth_prime(int input[], int size, int target);
int main()
{
    int primes[120000];
    find_nth_prime(primes,120000,10001);
    return 0;
}
void initialize_sieve_array(int input[], int size){
    int i;
    input[0] = 0;
    input[1] = 0;
    for(i = 2;i < size;i++){
        input[i] = 1;
    }
}

void sieve_of_erastothenes(int input[], int size){
    initialize_sieve_array(input,size);
    for(int i = 2;i < size;i++){
        for(int j = 2;i*j < size;j++){
            input[i*j] = 0;
        }
    }
}

void find_nth_prime(int input[], int size, int target){
    sieve_of_erastothenes(input,size);
    int index = 0,prime_counter = 0;
    while(prime_counter != target){
        index++;
        if(input[index] != 0){
            prime_counter++;
        }
    }
    printf("%dth prime number is %d",target,index);
}
