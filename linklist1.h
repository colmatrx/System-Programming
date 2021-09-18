
#include<stdio.h>
#include<stdlib.h>
#include<getopt.h>
#include<unistd.h>
#include<string.h>
#include<time.h>

typedef struct data_struct{
        
        //time_t messagetime;
        char messagetype;
        char *messagestring;
        struct data_struct *nextnodelink;
}data_t;

int addmsg(char type, char *message);

char *getlog();

int savelog(char *filename);

void clearlog();



 



