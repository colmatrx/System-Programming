#include <time.h>

typedef struct data_struct {
time_t time;    //time stamp
char type;      //message type I/W/E/F
char *string;   //message string
} data_t;

int accessdata(void);

int addmsg(const char type, char *msg);

int freekey(int key);

int getdata(int key, data_t *datap);