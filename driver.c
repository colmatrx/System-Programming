#include<stdio.h>
#include<stdlib.h>
#include<getopt.h>
#include<unistd.h>
#include<string.h>
#include<strings.h>
#include<time.h>
#include "linklist1.h"

/*Author - Idris Adeleke; Submission Date: 09/18/2021*/

//Block of variables

int main(int argc, char *argv[]){

    int option; int randsec; int lowertimelimit = 0; int uppertimelimit;
    char messages[100]; char *filename;
    char type; char flag = 'Y';
    messages[100] = '\0';
    FILE *openfile; char logstream[1000];
    char logstreamstring[1000];


    if (argc > 3){     //using argc to test if more than required arguments are passed
        printf("\nInvalid number of arguments. Use -h for help.\n");
        exit (1);
    }

    if (argc == 1){     //that is if no filename is explicitly provided
            printf("\nYou have provided no command line arguments. We shall send a message to the logger and name the log file \'messages.log\'\n");
            filename = "Messages.log";
            
            while (1){              //giving the user a chance to enter the message before calling addmsg to create the structure

            printf("\nEnter Message String\n");

            fgets(messages, sizeof(messages), stdin);

            printf("\nEnter Message Type: I -> INFO/ W -> WARNING/ E -> ERROR/ F -> FATAL\n");
    
            scanf("%c%*c", &type); //without this line, fgets() above behaves unpredictably because it could read characters left behind in the stdin buffer

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

        savelog(filename); //calls savelog() with the default filename "messages.log"
        clearlog(); //deallocating memory allocated to the linked list data structure 
        return 0;
    }
            //this block uses getopt function to collect the command line argument
         while ((option = getopt(argc, argv, ":ht:")) != -1){   //starting the options with a ':' turns off getopt's error so we can just print our own perror messages
            switch (option){

                    case 'h':       //-h argument displays the help
                        printf("\nYou chose h\n");
                        printf("\nHelp: driver -h: displays help\n\ndriver -t sec: randomly prints log\n\ndriver <logfilename>: saves the log with the given filename\n\n");
                        exit(2);

                    case 't':       //-t sec displays the content of the default logfile "messages.log" in random number of seconds between 0 and 2*sec
                        printf("\nYou chose t and its parameter is %d\n", atoi(optarg)); //atoi converts string to integer. it converts the time argument from character to integer
                        printf("\nLog Messages are printed here at random interval\n");  
                        uppertimelimit = 2 * (atoi(optarg));
                        
                        openfile = fopen("Messages.log", "r");  //open log file in read mode
                        if (openfile == NULL){
                            perror("\nError: File cannot be opened. No Log File found\n");
                            exit(5);
                        }
                        
                        printf("\nfile opened successfully\n");
                        while(fgets(logstream, 1000, openfile) != NULL) //reads the file content; maximum of 1000 characters
                                strcat(logstreamstring, logstream);     //appends the read content into logstreamstring
                        fclose(openfile);                               //closes the file after everything is read

                        while (1)
                        {
                            printf("\n%s\n", logstreamstring);
                            srand(time(NULL));          //initilize the rand function
                            randsec = (rand() % ((uppertimelimit - lowertimelimit) + 1)) + lowertimelimit; //this logic produces a number between lowertimelit and uppertimelimit
                            printf("\nlog output in %d seconds\n", randsec);
                            sleep(randsec);                  

                        }
                        

                    default: //if none of the correct arguments were passed
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

            printf("\nEnter Message Type: I -> INFO/ W -> WARNING/ E -> ERROR/ F -> FATAL\n");
    
            scanf("%c%*c", &type);

            if(type != 'I' & type != 'W' & type != 'E' & type != 'F'){
                printf("\nWrong Message Type. Terminating Logger Program\n");
                clearlog();
                exit(1);
            }

            addmsg(type, messages); //passes message type and message string to the fucntion addmsg

            printf("\nWould you like to log more message? -> Y/N\n");
            scanf("%c%*c", &flag);
            if (flag == 'Y')
                continue;
            else
                break;
        }    

//end of messages, proceed to call getlog() and savelog() functions; getlog()is called inside savelog()

savelog(filename);

clearlog(); //frees the memory allocated by malloc

return 0;

}

