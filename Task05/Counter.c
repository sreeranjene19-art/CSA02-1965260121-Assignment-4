#ifndef TASK5_GLOBAL_COUNTER_H
#define TASK5_GLOBAL_COUNTER_H
extern int global_token;
int next_global_token(void);
int next_token_by_pointer(int *counter);
#endif
