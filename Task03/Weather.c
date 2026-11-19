#include <stdio.h>
enum kind{TEMPERATURE,HUMIDITY,STATUS};
struct reading{enum kind type;union{float celsius;int percent;char status[8];}value;};
struct all_values{float celsius;int percent;char status[8];};
void show(const struct reading *r){switch(r->type){case TEMPERATURE:printf("Temp %.1f C\n",r->value.celsius);break;case HUMIDITY:printf("Humidity %d %%\n",r->value.percent);break;case STATUS:printf("Status %s\n",r->value.status);break;default:puts("Unknown");}}
int main(void){struct reading a[3]={{TEMPERATURE,{.celsius=31.5f}},{HUMIDITY,{.percent=68}},{STATUS,{.status="OK"}}};printf("sizeof union=%zu, sizeof reading=%zu\n",sizeof a[0].value,sizeof a[0]);printf("sizeof all-fields structure=%zu\n",sizeof(struct all_values));for(int i=0;i<3;i++)show(&a[i]);puts("Misuse: interpreting a temperature union member as humidity is invalid; the value is not a meaningful humidity measurement.");return 0;}
