#include <stdio.h>
#include <stdlib.h>
/*
    This program solves the following quesiton:

    2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

    What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

//This finds any common multiples to avoid making the number larger than it needs to be
int is_greater_multiple(int n){
    int i,greatest_multiple = 0;
    for(i = 1;i < n;i++){
        if(n%i == 0){
             greatest_multiple = i;
        }
    }
    return greatest_multiple;
}
//This code finds the smallest multiple of an input n
int smallest_multiple(int n){
    int smallest_multiple = 1,i;
    for(i = 1;i <= n;i++){
        if(smallest_multiple%(i) == 0 && is_greater_multiple(i) != 0){//In this case we do nothing, as the smallest multiple is unchanged

        }else if (smallest_multiple%(i) != 0 && is_greater_multiple(i) != 0){//Here we increase the smallest multiple but also divide it by an existing common multiple
            smallest_multiple = i*smallest_multiple/is_greater_multiple(i);
        }else{//Here we are forced to multiply the current smallest multiple by i to satisfy constraints
            smallest_multiple = i*smallest_multiple;
        }
    }
    return smallest_multiple;
}

int main()
{
    printf("%d",smallest_multiple(20));
    return 0;
}

