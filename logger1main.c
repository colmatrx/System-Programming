#include <stdio.h>
#include <string.h>
#include "listlib.h"
 int main(){

//data_t user;
char messagetype;
char usermessage[100];  

printf("\nenter a string\n");
fgets(usermessage, sizeof(usermessage), stdin);

printf("\nname is %s\n", usermessage);
//user.string = usermessage;

printf("\nenter message type\n");
scanf("%c", &messagetype);

printf("\nmessage type is %c\n", messagetype);
//user.type = messagetype;

addmsg(messagetype, usermessage);
return 0;

 }