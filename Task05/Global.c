#include "Task5_Global_Counter.h"
int global_token=1000;
int next_global_token(void){return ++global_token;}
int next_token_by_pointer(int *counter){if(!counter)return -1;return ++(*counter);}
