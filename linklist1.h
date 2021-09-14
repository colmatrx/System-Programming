
#include<stdio.h>
#include<stdlib.h>
#include<getopt.h>
#include<unistd.h>
#include<string.h>

typedef struct data_struct{

        char messagetype;
        char *messagestring;
        struct data_struct *nextnodelink;
}data_t;

int appendmsg(char type, char *message);

void clearlog();

static data_t *staticHEADPTR;



 



