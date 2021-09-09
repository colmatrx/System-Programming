#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]){

    int option;

    if (argc > 3){                                      //using argc to test the number of command line arguments
        printf("\nInvalid number of arguments\n");
        exit (0);
    }

    if (argc == 1)
            printf("\nYou have provided no command line arguments. We shall send a message to the logger and name the log file \'messages.log\'\n");
    
    else if ((argc == 2) && (argv[1][0] != '-'))
            printf("\nYou have provided filename as %s.log\n", argv[1]);
    
    else{
         while ((option = getopt(argc, argv, ":ht:")) != -1){   //starting the options with a : turns off getopt's error so we can just print our own perror messages
            switch (option){

                    case 'h':
                        printf("\nYou chose h\n");
                        printf("\nHelp Function goes here\n");
                        break;

                    case 't':
                        printf("\nYou chose t and its parameter is %d\n", atoi(optarg)); //use %s to output optarg because it is a pointer and %s will print it all
                        printf("\nLog Messages are printed here at random interval\n");
                        break; 

                    default:
                        perror("\n\nYou have entered an invalid argument/parameter. See Usage below"); //use of perror
                        printf("\ndriver -h: displays help\n\ndriver -t sec: randomly prints log\n\ndriver <logfilename>: saves the log with the given filename\n");
                        
                    
            }
    }

    }
return 0;
}