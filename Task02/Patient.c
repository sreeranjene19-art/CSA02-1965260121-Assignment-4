#include <stdio.h>
#define MAX 100
typedef struct { int day,month,year; } Date;
typedef struct { int systolic,diastolic; } BP;
typedef struct { char name[50],phone[16]; int age; BP bp; Date visit; } Patient;
static Patient patients[MAX]; static int count;
int addPatient(Patient *dest,const Patient *src){ if(!dest||!src)return 0; *dest=*src; return 1; }
int add_patient(const Patient *p){ if(!p||count>=MAX)return 0; addPatient(&patients[count],p); count++; return 1; }
void sort_age(Patient a[],int n){ for(int i=1;i<n;i++){Patient x=a[i];int j=i-1;while(j>=0&&a[j].age>x.age){a[j+1]=a[j];j--;}a[j+1]=x;} }
void print_patient(const Patient *p){printf("%s age=%d phone=%s BP=%d/%d visit=%02d/%02d/%04d\n",p->name,p->age,p->phone,p->bp.systolic,p->bp.diastolic,p->visit.day,p->visit.month,p->visit.year);}
int main(void){Patient a={"Anitha","9876543210",42,{120,80},{19,11,2026}},b={"Bharath","9123456780",28,{118,76},{18,11,2026}},c={"Charan","9988776655",61,{140,90},{17,11,2026}};add_patient(&a);add_patient(&b);add_patient(&c);sort_age(patients,count);for(int i=0;i<count;i++)print_patient(&patients[i]);printf("sizeof(Patient)=%zu bytes\n",sizeof(Patient));return 0;}
