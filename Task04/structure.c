#include <stdio.h>
struct account{int number;float balance;};
void addInterest(struct account *p,float rate){if(!p)return;printf("Address inside function: %p\n",(void*)p);p->balance+=p->balance*rate/100.0f;}
struct account addInterest_copy(struct account a,float rate){a.balance+=a.balance*rate/100.0f;return a;}
int main(void){struct account list[3]={{101,5000},{102,12000},{103,800}};struct account *p=list;for(int i=0;i<3;i++){printf("Address in main: %p\n",(void*)&list[i]);addInterest(&list[i],4);}puts("Updated balances:");for(int i=0;i<3;i++)printf("%d %.2f\n",p[i].number,p[i].balance);list[0]=addInterest_copy(list[0],4);printf("Returned-copy alternative: %d %.2f\n",list[0].number,list[0].balance);return 0;}
