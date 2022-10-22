#include<stdio.h>
#define SIZE 7

//static 
//register


int graph[SIZE][SIZE];
int visited[SIZE];
int count=0;
int value;          //global variable ( extern variable initial value[0])
int top=-1;
int stack[SIZE];
int flag;

void addEdge(int src,int dest,int cost){
	graph[src][dest]=cost;
	graph[dest][src]=cost;
	
}

void push(int num){
	top++;
	stack[top]=num;
}

int pop(){
//	int num=stack[top];
//	top--;
//	return num;

	return stack[top--];      //same as upper line of code
}

int  main(){
	int i,j,ans;
	
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			if(graph[i][j]==0){                     //for this who are already connected
				printf("\n%d is connected with %d:",i,j);
				scanf("%d",&ans);//1 for connect and -1 for not connect
				
				if(ans==-1){                        //for this who are not already connected  
					graph[i][j]=-1;
					graph[j][i]=-1;
				}else{                             
					addEdge(i,j,ans);
					
				}	
			}
			
		}
		
	}
	
	for(i=0;i<SIZE;i++){
		printf("\n%d is connected with =",i);
		for(j=0;j<SIZE;j++){
			if(graph[i][j] != -1){
				printf(" %d(%d) ",j,graph[i][j]);
			}
			
		}
	}
	
	printf("\n Graph travel :\n");   //dfs
	
	printf(" %d ->",0);
	count++;
	visited[0]=1;
	i=0;
	
	
	
	while(count != SIZE){
		
		flag=-1;
		for(j=0;j<SIZE;j++){
		
			if(graph[i][j] != -1){
				if(visited[j] == 0){
					printf(" %d ->",j);
					value=value+graph[i][j];
					visited[j]=1;
					push(i);
					i=j;
					count++;
					flag=1;
					break;
					
				}
				
			}
		}	
		
		if(flag==-1){
			i=pop();
		}
	}
	
	printf("\nTotal value:%d",value);
	return 0;
}
