#include<stdio.h>
#include<stdlib.h>
#include<getopt.h>
#include<unistd.h>
#include<string.h>
#include<time.h>
#include<strings.h>
#include "linklist1.h"

/*Author - Idris Adeleke; Submission Date: 09/18/2021*/


 data_t *HEADPTR = NULL;              //to store the starting point of the linked list
 data_t *TEMPPTR = NULL;              //to temporarily keep the newly created structure before linking it to the linked list
 data_t *ITERATIONPTR = NULL;         //to to traverse the linked list in order to add the new structure to the end of the linked list
 time_t mtime;
 char savelogstring[1000] = "\0";        //log string can only be 1000 characters long

//This function creates a linked list of structures and adds user provided messages to the the structure

int addmsg(char type, char *message){

    char *logtime;
    TEMPPTR = malloc(sizeof(data_t)); //always creates a new structure and allocate memory space for it. This structure is currently isolated until we link it below
    TEMPPTR->messagetype = type;
    TEMPPTR->messagestring = message;
    time(&mtime);
    logtime = ctime(&mtime);

     strcat(savelogstring, message); //concatenates the message, message type and time and we can pass 'savelogstring' to savelog() to write to file
     strcat(savelogstring, &type);
     strcat(savelogstring, "  ");
     strcat(savelogstring, logtime);
     strcat(savelogstring, "\n");

    if (HEADPTR == NULL){

        HEADPTR = TEMPPTR;          //if there is nothing in the list yet, then store the TEMMPPTR structure as the first structure in the list (HEADPTR)

        return 0;
    }

    else{                            //else block gets executed if there is already a structure in the linked list

        ITERATIONPTR = HEADPTR;     //keep a copy of the HEADPTR in ITERATIONPTR so we don't lose access to the beginning of the linked list. Then we can sefely iterate through the list with ITERATIONPTR
        while (ITERATIONPTR->nextnodelink != NULL){     //this condition checks if we have reached the end of the linked list
            
            ITERATIONPTR = ITERATIONPTR->nextnodelink;  //if the current structure is pointing to the next one, then copy the address of the next one to ITERATIONPTR

        }

        ITERATIONPTR->nextnodelink = TEMPPTR;   //inserts the address of the newly created node, i.e. the last structure into the nextnodelink of the penultimate one so they are linked together
        
        return 0;
    }
    

}

void clearlog(){

    printf("\nDeallocating memory...\n");
    data_t *STEPPTR;
    ITERATIONPTR = HEADPTR;
    while (ITERATIONPTR != NULL){
        STEPPTR = ITERATIONPTR;
        ITERATIONPTR = ITERATIONPTR->nextnodelink;
        free(STEPPTR);
    }
    printf("\nMemory deallocation completed\n\n");
    
}


char *getlog(){

    return savelogstring;
}


int savelog(char *filename){

    FILE *logfile; char *savelog;

    savelog = getlog();         //calls getlog to collect the memory address of the string to be saved

    logfile = fopen(filename, "a"); //opens logfile in append mode
    if (logfile == NULL){
        perror("\nFile cannot be opened\n");
        exit(1);
    }

    fputs(savelog, logfile);    //writes log message to file
    fclose(logfile);
    return 0;
}