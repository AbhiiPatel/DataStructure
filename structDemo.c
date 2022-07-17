#include<stdio.h>

struct royal{
	
	char name[30];
	int m,s,e;
	
};

int main(){
	
	/*
	struct royal r;
	
	printf("Enter student name and marks of three subject:");
	scanf("%s%d%d%d",&r.name,&r.m,&r.s,&r.e);
	
	printf("\n%s  %d  %d  %d  ",r.name,r.m,r.s,r.e);*/
	
	
	struct royal *r;
	int i;
	
    r=(struct royal*)malloc(2*sizeof(struct royal));
	
	for(i=0;i<2;i++){
		printf("\nEnter student name and marks of three subject:");
		//scanf("%s%d%d%d",&r[i].name,&r[i].m,&r[i].s,&r[i].e);
		
		scanf("%s%d%d%d",(r+i)->name,&(r+i)->m,&(r+i)->s,&(r+i)->e);
	}
	
	for(i=0;i<2;i++){
		
		//printf("\n%s  %d  %d  %d",r[i].name,r[i].m,r[i].s,r[i].e);
		
		printf("\n%s  %d  %d  %d",(r+i)->name,(r+i)->m,(r+i)->s,(r+i)->e);
	}
	
	
	
	
	
	/*struct royal *r;
	
	r=(struct royal*)malloc(sizeof(struct royal));
	
	printf("Enter student name and marks of three subject:");
	scanf("%s%d%d%d",&r->name,&r->m,&r->s,&r->e);
	
	
	printf("\n%s  %d  %d  %d  ",r->name,r->m,r->s,r->e);*/
	
	return 0;
}
