#include <stdio.h>
/*#include <stdlib.h>
#include <getopt.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]){

    int option; int timecast;
    
    if (argc > 3){                                      //using argc to test the number of command line arguments
        printf("\nInvalid number of arguments\n");
        exit (1);
    }

   // printf("\nlength of argv[1] is %d\n", strlen(argv[1])); //strlen to collect the length of argv[]


    while ((option = getopt(argc, argv, ":ht:")) != -1){   //starting the options with a : turns off getopt's error so we can just print our own error messages
            switch (option){
                    case 'h':
                        printf("\nYou chose h\n");
                        break;
                    case 't':
                        printf("\nYou chose t and its parameter is %d\n", atoi(optarg)); //use %s to output optarg because it is a pointer and %s will print it all
                        break;                                                           //and use atoi() to convert string to int
                    default:
                        perror("\n\nYou have entered an invalid choice."); //use of perror

            }
    }

    return 0;


}*/