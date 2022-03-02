#include<stdio.h>
#include<stdlib.h>
#define N 5
int queue[N],rear=-1,front=-1;

void insert(){
	if((front==0 && rear==N-1) || (rear==front-1)){
		printf("\n Overflow");
	}
	else{
		if(front==-1 && rear==-1){
			front=rear=0;
		}
		else if(rear==N-1 && front!=0){
			rear=0;
		}
		else if(front!=0 && rear<front){
			
				rear+=1;
	
		}
		else{
			rear+=1;
		}
		printf("\n Enter the data:");
		scanf("%d",&queue[rear]);
	}
}

void display(){
	int i;
	if(front==-1 && rear==-1)
		printf("\nQUEUE Empty");
	else{
		if(front<rear)
			for(i=front;i<=rear;i++)
				printf("\t%d",queue[i]);
		else{
			for(i=front;i<N;i++)
				printf("\t%d",queue[i]);
			for(i=0;i<=rear;i++)
				printf("\t%d",queue[i]);
		}
	}
}
void delete(){
	if(front==-1){
		printf("\nQUEUE Empty");
	}
	else{
		int val=queue[front];
		if(front==rear)
			front=rear=-1;
		else{
			if(front==N-1)
				front=0;
			else
				front+=1;
		}
		
	}
}

void peek(){
	if(front==-1 && rear==-1)
		printf("\nQUEUE Empty");
	else{
		printf("%d",queue[front]);
	}
}

			

int main(){
	int c;
	do{
		printf("\n1-Insertion\n2-Deletion\n3-Display\n4-Peek\n5-Exit\nEnter Your Choice  ");
		scanf("%d",&c);
		switch(c){
			case 1:insert(); break;
			case 2:delete(); break;
			case 3:display(); break;
			case 4:peek(); break;
			case 5:exit(0); break;
			default:printf("\nINVALID CHOICE"); break;
		}
	}while(1);
}

	return(0);
}
