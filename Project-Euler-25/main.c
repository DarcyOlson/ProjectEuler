#include <stdio.h>
#include <stdlib.h>
/*

This code solves the problem of finding the first fibonacci number with 1000 digits

*/
void print_array(int input[],int size){
    for(int i = 0;i < size;i++){
        printf("%d",input[i]);
    }
}
void add_large_nums(int input1[], int input2[], int size){
    int counter = size-1;
    while(counter >= 0){
        input1[counter] = input1[counter] + input2[counter];
        if(input1[counter] > 9){
            input1[counter] = input1[counter] - 10;
            input1[counter - 1]++;
        }
        counter--;
    }
}

void define_large_nums(int input1[], int input2[], int size){
    for(int i = 0;i < size;i++){
        input1[i] = input2[i];
    }
}
int main()
{
    int large_fibonacci1[1000];//Each element of this array will store the value of one digit of the large fibonacci number. Using standard data types won't work here because the number is too large.
    int large_fibonacci2[1000];
    int place_holder[1000];
    for(int i = 0;i < 1000;i++){
        place_holder[i] = 0;
    }
    for(int i = 0;i < 1000;i++){
        large_fibonacci1[i] = 0;
    }
    for(int i = 0;i < 999;i++){
        large_fibonacci2[i] = 0;
    }
    large_fibonacci2[999] = 1;
    int counter = 0;
    while(large_fibonacci1[0] == 0){//As long as large_fibonacci[0] (the most significant digit) == 0, we haven't reached 1000 digits yet.
        define_large_nums(place_holder,large_fibonacci1,1000);
        add_large_nums(large_fibonacci1,large_fibonacci2,1000);
        define_large_nums(large_fibonacci2,place_holder,1000);
        counter++;
    }
    printf("%d",counter);
    return 0;
}
