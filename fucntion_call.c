#include <stdio.h>
void func1();
void func2();

void main(){

    printf("\nThis is the main function\n");

    printf("\nCalling function 1\n");

    func1();

    printf("\nNow calling function 2\n");

    func2();


}

void func1(){

    printf("\nWelcome to function 1\n");
}

void func2(){

    printf("\nWelcome to function 2\n\n");
}
