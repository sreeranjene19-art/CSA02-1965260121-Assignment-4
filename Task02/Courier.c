#include <stdio.h>
#include <string.h>
#define MAX 20
typedef struct{int day,month,year;}Date;
typedef struct{char name[40],city[20];int pin;}Address;
typedef enum{NORMAL,EXPRESS}Service;
typedef struct{int id;float weight;Date booked;Address sender,receiver;Service service;float charge;}Parcel;
void print_parcel(const Parcel *p){printf("%d %.1f kg %s-%06d %02d/%02d/%04d %s Rs.%.2f\n",p->id,p->weight,p->receiver.city,p->receiver.pin,p->booked.day,p->booked.month,p->booked.year,p->service==EXPRESS?"Express":"Normal",p->charge);}
void sort_weight(Parcel p[],int n){for(int i=0;i<n-1;i++){int m=i;for(int j=i+1;j<n;j++)if(p[j].weight<p[m].weight)m=j;if(m!=i){Parcel t=p[i];p[i]=p[m];p[m]=t;}}}
void list_city(const Parcel p[],int n,const char city[]){int found=0;for(int i=0;i<n;i++)if(strcmp(p[i].receiver.city,city)==0){print_parcel(&p[i]);found=1;}if(!found)puts("No matching parcels.");}
int main(void){Parcel p[3]={{501,4.5,{12,10,2026},{"Asha","Madurai",625001},{"Kavin","Madurai",625002},NORMAL,120},{502,1.2,{12,10,2026},{"Bala","Chennai",600001},{"Mira","Chennai",600077},EXPRESS,95},{503,2.8,{13,10,2026},{"Devi","Coimbatore",641001},{"Arun","Coimbatore",641002},NORMAL,105}};sort_weight(p,3);for(int i=0;i<3;i++)print_parcel(&p[i]);puts("Receiver city Chennai:");list_city(p,3,"Chennai");printf("Dot PIN=%d\n",p[2].receiver.pin);Parcel *ptr=&p[2];printf("Arrow PIN=%d\n",ptr->receiver.pin);printf("sizeof(Parcel)=%zu\n",sizeof(Parcel));return 0;}
