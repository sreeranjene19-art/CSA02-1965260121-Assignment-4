#include <stdio.h>
#define MAX_ITEMS 20
#define MAX_SALES 100
#define PARTS 3
typedef struct{int day,month,year;}Date;
typedef struct{int hour,minute;}Time;
typedef enum{PACKAGED,COOKED,COMBO}ItemType;
typedef struct{int id;char name[40];ItemType type;float price;int stock;union{Date expiry;Time prepared;struct{int ids[PARTS],count;}combo;}detail;}Item;
typedef struct{int id,qty;float revenue;}Sale;
static Item items[MAX_ITEMS];static int nitems;static Sale sales[MAX_SALES];static int nsales;
int find_item(int id){for(int i=0;i<nitems;i++)if(items[i].id==id)return i;return -1;}
int add_item(const Item *p){if(!p||nitems>=MAX_ITEMS||find_item(p->id)>=0)return 0;items[nitems++]=*p;return 1;}
int record_sale(int id,int qty){int i=find_item(id);if(i<0||qty<=0){puts("Rejected: invalid item/quantity");return 0;}if(items[i].stock<qty){printf("Rejected: only %d units of %s available\n",items[i].stock,items[i].name);return 0;}if(nsales>=MAX_SALES){puts("Sales log full");return 0;}items[i].stock-=qty;sales[nsales++]=(Sale){id,qty,items[i].price*qty};printf("Sold %d x %s = Rs.%.2f; stock=%d\n",qty,items[i].name,items[i].price*qty,items[i].stock);return 1;}
float revenue(int id){float r=0;for(int i=0;i<nsales;i++)if(sales[i].id==id)r+=sales[i].revenue;return r;}
void expiry_warning(Date today){puts("Expiry warnings:");int found=0;for(int i=0;i<nitems;i++)if(items[i].type==PACKAGED){Date e=items[i].detail.expiry;if(e.year==today.year&&e.month==today.month&&e.day>=today.day&&e.day-today.day<=2){printf("%s expires in %d day(s)\n",items[i].name,e.day-today.day);found=1;}}if(!found)puts("None");}
void summary(void){int order[MAX_ITEMS];for(int i=0;i<nitems;i++)order[i]=i;for(int i=0;i<nitems-1;i++){int best=i;for(int j=i+1;j<nitems;j++)if(revenue(items[order[j]].id)>revenue(items[order[best]].id))best=j;int t=order[i];order[i]=order[best];order[best]=t;}float total=0;puts("Revenue summary (descending):");for(int i=0;i<nitems;i++){float r=revenue(items[order[i]].id);printf("%s Rs.%.2f stock=%d\n",items[order[i]].name,r,items[order[i]].stock);total+=r;}printf("Grand total Rs.%.2f\n",total);}
int main(void){Item sample[]={{101,"Milk Packet",PACKAGED,30,10,.detail.expiry={20,11,2026}},{102,"Veg Sandwich",COOKED,45,8,.detail.prepared={10,30}},{103,"Tea",COOKED,15,20,.detail.prepared={11,0}},{104,"Combo Meal",COMBO,90,5,.detail.combo={{102,103,101},3}}};for(unsigned i=0;i<sizeof sample/sizeof sample[0];i++)add_item(&sample[i]);puts("Normal sales:");record_sale(101,2);record_sale(102,1);record_sale(104,1);puts("Excess-stock test:");record_sale(104,10);expiry_warning((Date){19,11,2026});summary();return 0;}
