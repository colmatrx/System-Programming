#include<stdio.h>
#include<stdlib.h>
#include<getopt.h>
#include<unistd.h>
#include<string.h>
#include<time.h>
#include "linklist1.h"

int main(int argc, char *argv[]){

    int option;
    char messages[100]; char *filename;
    char type; char flag = 'Y';
    messages[100] = '\0';


    if (argc > 3){     //using argc to test if more than required arguments are passed
        printf("\nInvalid number of arguments. Use -h for help.\n");
        exit (1);
    }

    if (argc == 1){     //that is if no filename is explicitly provided
            printf("\nYou have provided no command line arguments. We shall send a message to the logger and name the log file \'messages.log\'\n");
            filename = "Messages.log";
            //call addmsg and save file as Messages.log
            while (1){              //giving the user a chance to enter the message before calling addmsg to create the structure

            printf("\nEnter Message String\n");

            fgets(messages, sizeof(messages), stdin);

            printf("\nEnter Message Type -> I/W/E/F\n");
    
            scanf("%c%*c", &type);

            if(type != 'I' & type != 'W' & type != 'E' & type != 'F'){  //checking if the message type is correct
                printf("\nWrong Message Type. Terminating Logger Program\n");
                clearlog();
                exit(1);
            }

            addmsg(type, messages); //passes message type and message string to the fucntion addmsg

            printf("\nWould you like to add more message? -> Y/N\n");
            scanf("%c%*c", &flag);
            if (flag == 'Y')
                continue;
            else
                break;
        }   

        savelog(filename);
        clearlog(); //deallocating linked list allocated memory
        return 0;
    }
            //this block uses getopt function to collect the command line argument
         while ((option = getopt(argc, argv, ":ht:")) != -1){   //starting the options with a ':' turns off getopt's error so we can just print our own perror messages
            switch (option){

                    case 'h':
                        printf("\nYou chose h\n");
                        printf("\nHelp: driver -h: displays help\n\ndriver -t sec: randomly prints log\n\ndriver <logfilename>: saves the log with the given filename\n\n");
                        exit(2);

                    case 't':
                        printf("\nYou chose t and its parameter is %d\n", atoi(optarg)); //use %s to output optarg because it is a pointer and %s will print it all
                        printf("\nLog Messages are printed here at random interval\n");
                        exit(5); //exit for now till getlog() is ready
                        break; 
                        //call getlog and print out the log message and exit

                    default:
                        perror("\n\nYou have entered an invalid argument/parameter. See Usage below"); //use of perror
                        printf("\ndriver -h: displays help\n\ndriver -t sec: randomly prints log\n\ndriver <logfilename>: saves the log with the given filename\\nn");  
                        exit(3);
            }
            
        }

        //if none of the above if conditions is true, then it implies the argument is a filename.
       printf("\nYou have provided filename as %s.log\n", argv[optind]); //optind is part of getopt variables. It is index of the next character not preceded by an '-' so we can use it to print the filename
       filename = argv[optind];
       //start collecting type and message to call addmsg() and make filename as user provided.
       while (1){

            printf("\nEnter Message String\n");

            fgets(messages, sizeof(messages), stdin);

            printf("\nEnter Message Type -> I/W/E/F\n");
    
            scanf("%c%*c", &type);

            if(type != 'I' & type != 'W' & type != 'E' & type != 'F'){
                printf("\nWrong Message Type. Terminating Logger Program\n");
                clearlog();
                exit(1);
            }

            addmsg(type, messages); //passes message type and message string to the fucntion addmsg

            printf("\nWould you like to add more message? -> Y/N\n");
            scanf("%c%*c", &flag);
            if (flag == 'Y')
                continue;
            else
                break;
        }    

//end of messages, proceed to call getlog() and savelog() functions
savelog(filename);

clearlog(); //frees the memory allocated by malloc

return 0;

}

