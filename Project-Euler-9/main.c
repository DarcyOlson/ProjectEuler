#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct possible_triple{
        int a;
        int b;
        int c;
    };
    struct possible_triple exciting_possibilities[498501];
    int counter = 0;
    int c;
    for(c = 1;c <= 1000;c++){
        int b;
        for(b = 1;b <= 1000;b++){
            int a;
            for(a = 1;a <= 1000;a++){
                if(a+b+c == 1000){
                    exciting_possibilities[counter].a = a;
                    exciting_possibilities[counter].b = b;
                    exciting_possibilities[counter].c = c;
                    counter++;
                }
            }
        }
    }
    int i;
    for(i = 0;i < 498501;i++){
        if(exciting_possibilities[i].a*exciting_possibilities[i].a + exciting_possibilities[i].b*exciting_possibilities[i].b == exciting_possibilities[i].c*exciting_possibilities[i].c){
            if(exciting_possibilities[i].a < exciting_possibilities[i].b && exciting_possibilities[i].b < exciting_possibilities[i].c){
                printf("our triple is (%d,%d,%d)",exciting_possibilities[i].a,exciting_possibilities[i].b,exciting_possibilities[i].c);
            }
        }
    }
    return 0;
}
