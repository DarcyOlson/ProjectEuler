#include <stdio.h>
#include <stdlib.h>
/*

The sum of the squares of the first ten natural numbers is,

1^2 + 2^2 + ... + 10^2 = 385
The square of the sum of the first ten natural numbers is,

(1 + 2 + ... + 10)^2 = 552 = 3025
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

*/

int sum_of_squares(int n);
int square_of_sum(int n);
void sum_square_difference(int n);
int main()
{
    sum_square_difference(100);
    return 0;
}
int sum_of_squares(int n){
    return (n*(n+1)*(2*n+1))/6;
}
int square_of_sum(int n){
    return ((n*(n+1))/2)*((n*(n+1))/2);
}
void sum_square_difference(int n){
    int answer = square_of_sum(n) - sum_of_squares(n);
    printf("%d",answer);
}
