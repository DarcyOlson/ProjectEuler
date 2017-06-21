#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*

This is code to solve the following problem:

If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.

The solution to this problem involves finding the sum of all multiples of 3 or 5 below 1000, summing them and then removing all the multiples of 3 and 5 from that sum. We implement a naive solution using loops
in solution 1 and a more sophisticated formula that utilizes a famous mathematical identity in solution 2. In both cases, the answer evaluates to 233168.

*/

int solution_1();
int naive_multiples_of_n(int n);
int solution_2();
int sophisticated_multiples_of_n(int n);
int determine_upper_bound(int n);
int main()
{
    printf("The solution of solution1 is %d \n",solution_1());
    printf("The solution of solution2 is %d",solution_2());
    return 0;
}

//this function takes an input n, computes all its multiples under 1000, sums them and then returns the sum
int naive_multiples_of_n(int n){
    int i,sum = 0;
    for(i = 1;i < 1000.0/n;i++){//Here we use 1000.0 so the number doesn't round down. If we didn't do this, we would add an extra 1000 when computing the multiples of 5000.
        sum += n*i;
    }
    return sum;
}

//This is the first naive solution
int solution_1(){
    int answer = naive_multiples_of_n(3) + naive_multiples_of_n(5) - naive_multiples_of_n(15);
    return answer;
}

//This function determines how many times we should sum a number
int determine_upper_bound(int n){
    if(1000%n == 0){
        return 1000/n-1;
    }else{
        return 1000/n;
    }
}

//This solution takes advantage of the fact that 1+2+ ... + n = n*(n+1)/2 to perform the computations of solution 1 faster
int sophisticated_multiples_of_n(int n){
    int limit = determine_upper_bound(n);
    int sum = (limit*(limit+1))/2;
    return n*sum;
}

//This is the fast second solution
int solution_2(){
    int answer = sophisticated_multiples_of_n(3) + sophisticated_multiples_of_n(5) - sophisticated_multiples_of_n(15);
    return answer;
}

