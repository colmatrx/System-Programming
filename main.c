#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//#include "linklist1.h"

int appendmsg(char type, char *message);

typedef struct data_struct{

        char messagetype;
        char *messagestring;
        struct data_struct *nextnodelink;
}data_t;

 data_t *HEADPTR = NULL;              //to store the starting point of the linked list
 data_t *TEMPPTR = NULL;              //to temporarily keep the newly created structure before linking it to the linked list
 data_t *ITERATIONPTR = NULL;         //to to traverse the linked list in order to add the new structure to the end of the linked list
 static data_t *staticHEADPTR;

int main(int argc, char *argv[]){

    data_t *HEADPTR = NULL;              //to store the starting point of the linked list
 data_t *TEMPPTR = NULL;              //to temporarily keep the newly created structure before linking it to the linked list
 data_t *ITERATIONPTR = NULL;         //to to traverse the linked list in order to add the new structure to the end of the linked list
 static data_t *staticHEADPTR;

    char messages[50]; 
    char type;
    int i;
    
   /* printf("\nEnter Message String\n");

    fgets(messages, sizeof(messages), stdin);

    printf("\nEnter Message Type -> I/W/E/F\n");
    
    scanf("%c", &type);*/
    
    //addint(5, 3);

    for (i = 0; 1<3; i++){

        printf("\nEnter Message String\n");

        fgets(messages, sizeof(messages), stdin);

        printf("\nEnter Message Type -> I/W/E/F\n");
    
        scanf("%c", &type);
        //appendmsg(type, messages); //passes message type and message string to the fucntion addmsg

    TEMPPTR = malloc(sizeof(data_t)); //always creates a new structure and allocate memory space for it. This structure is currently isolated until we link it below
    TEMPPTR->messagetype = type;
    TEMPPTR->messagestring = messages;
    TEMPPTR->nextnodelink = NULL;

    if (HEADPTR == NULL){

        HEADPTR = TEMPPTR;          //if there is nothing in the list yet, then store the TEMMPPTR structure as the first structure in the list (HEADPTR)

        staticHEADPTR = HEADPTR;

        printf("\nheadptr is %u\n", HEADPTR);

        //return 0;
    }

    else{                            //else block gets executed if there is already a structure in the linked list

        ITERATIONPTR = HEADPTR;     //keep a copy of the HEADPTR in ITERATIONPTR so we don't lose access to the beginning of the linked list. Then we can sefely iterate through the list with ITERATIONPTR
        while (ITERATIONPTR->nextnodelink != NULL){     //this condition checks if we have reached the end of the linked list
            
            
            ITERATIONPTR = ITERATIONPTR->nextnodelink;  //if the current structure is pointing to the next one, then copy the address of the next one to ITERATIONPTR

        }

        ITERATIONPTR->nextnodelink = TEMPPTR;   //inserts the address of the newly created node, i.e. the last structure into the nextnodelink of the penultimate one so they are linked together
        
        //return 0;
    }

}
           

   // printf("\nMessage String from HEADPTR is %s\n", staticHEADPTR->messagestring);

   // printf("\nMessage Type from HEADPTR is %c\n", staticHEADPTR->messagetype);

    return 0;

}

/*This function creates a linked list of structures and adds user provided messages to the the structure
int appendmsg(char type, char *message){

    TEMPPTR = malloc(sizeof(data_t)); //always creates a new structure and allocate memory space for it. This structure is currently isolated until we link it below
    TEMPPTR->messagetype = type;
    TEMPPTR->messagestring = message;
    TEMPPTR->nextnodelink = NULL;

    if (HEADPTR == NULL){

        HEADPTR = TEMPPTR;          //if there is nothing in the list yet, then store the TEMMPPTR structure as the first structure in the list (HEADPTR)

        staticHEADPTR = HEADPTR;

        printf("\nheadptr is %u\n", HEADPTR);

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

}*/