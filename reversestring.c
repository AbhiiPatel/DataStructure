#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char s[100];
int top=-1;

void push(){
	int i,l;
    printf("Enter the string:");
    gets(s);
    l=strlen(s);
	for(i=0;i<l;i++){
		
		top++;
		s[top]=s[i];
	}
	
}

void display(){
	int i;
	//printf("\n");
	for(i=top;i>=0;i--){
		printf("%c",s[i]);
	}
	
}


int main(){
	
	push();
	display();
	return 0;
}

