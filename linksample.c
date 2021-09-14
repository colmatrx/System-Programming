#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    int data;
    //char mtype;
  //  char mstring[50];
    struct node *next;
}node;

node * createLinkedList(int n);

void displayList(node *head);


int main(){

    int n = 0;
    node *headptr = NULL;
    printf("\nHow many nodes would you like to create\n");
    scanf("%d", n);
    headptr = createLinkedList(n);
    displayList(headptr);

    return 0;
}

node * createLinkedList(int n){
    int i = 0; //char messagestring[50];  
    node *head = NULL;
    node *temp = NULL;
    node *iterate = NULL;

     for(i=0; i<n; i++){

         temp = (node*)malloc(sizeof(node));
        // printf("\nEnter message string\n");
        // gets(temp->mstring);
         printf("\nEnter message data\n");
         scanf("%c", &temp->data);
         temp->next = NULL;

         if (head == NULL)
            head = temp;

        else{

            iterate = head;
            while(iterate->next != NULL)
                iterate = iterate->next;
            iterate->next = temp;

        }


     }

     return head;


}

void displayList(node *head){

    node *iterationptr = head;
    while (iterationptr != NULL){
        //printf("\nMessage String is %s\n", iterationptr->mstring);
        printf("\nMessage Data is %s\n", iterationptr->data);
        iterationptr = iterationptr->next;


    }
}