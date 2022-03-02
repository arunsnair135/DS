#include<stdio.h>
#include<stdlib.h>
#define N 5
int queue[N],rear=-1,front=-1;

void insert(){
	if(rear==N-1){
		printf("\nOverflow");
	}
	else{
		int q;
		printf("Enter the data to be inserted");
		scanf("%d",&q);
		if(front==-1){
			front++;
		}

		rear++;
		queue[rear]=q;
		
	}
}

void display(){
	if(front==-1){
		printf("\nUnderflow");
	}
	else{
		for(int i=front;i<=rear;i++){
			printf("\n%d",queue[i]);
		}
	}
}

void delete(){
	if(front==-1){
		printf("\nQueue is Empty");
	}
	else{
		int w=queue[front];
		if(rear==front){
			rear=front=-1;
		}
		else{
			front++;
		}
	}
}

void peek(){
	if(front==-1){
		printf("\nQueue is Empty");
	}
	else{
		printf("\n%d",queue[front]);
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

	return(0);
}
