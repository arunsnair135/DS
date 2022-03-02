#include<stdio.h>
#include<stdlib.h>
#define N 5
int stack[N],top=-1;

void push(){
	int x;
	printf("\n Enter the data\n");
	scanf("%d",&x);
	if(top==N-1){
		printf("\n Overflow!");
	}
	else{
		top++;
		stack[top]=x;
	}
}

void pop(){
	int x;
	if(top==-1){
		printf("\n Underflow!");
	}
	else{
		x=stack[top];
		top--;
		printf("\n%d deleted",x);
	
	}
	
	
}
	
void topp(){
	if(top==-1){
		printf("\n Stack is empty");
	}
	else{
		printf("top=%d",stack[top]);
	}
}

void display(){
	if(top==-1){
		printf("\n Stack is empty");
	}
	else{
		for(int i=top;i>=0;i--){
			printf("%d",stack[i]);
		}
	}

}

	
void main(){
	int c;
	do{

	printf("\n\n1- push\n2-pop\n3-Top\n4-Display\n5-Exit\n Enter the choice:\t");
	scanf("%d",&c);
	switch(c){
		case 1:push();break;
		case 2:pop();break;
		case 3:topp();break;
		case 4:display();break;
		case 5:exit(0); break;
		default:printf("WRONG ENTRY"); break;
	}
	}while(1);
}
