#include<stdio.h>
#include<stdlib.h>
#define N 5
int a[N];
void insert(){
	
	for(int i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
}
void display(){
	for(int i=0;i<N;i++){
		printf("%d",a[i]);
		printf("\n");
	}
}

void lar(){
	int l=a[0];
	for(int i=0;i<N;i++){
		if(l<a[i]){
			l=a[i];
		}
	}
	printf("\nThe Largest Number is %d",l);
}

void small(){
	int s=a[0];
	for(int i=0;i<N;i++){
		if(s>a[i]){
			s=a[i];
		}
	}
	printf("\nThe Smallest Number is %d",s);
}
	
void rev(){
	printf("\nThe Reverse is\n");
	for(int i=N-1;i>=0;i--){
		printf("%d",a[i]);
		printf("\n");
	}
}
void sum(){
	int s=0;
	for(int i=0;i<N;i++){
		s+=a[i];
	}
	printf("\nSum=%d",s);
}
	
void mean(){
	
	int s=0;
	for(int i=0;i<N;i++){
		s+=a[i];
	}
	int m=s/N;
	printf("\nMean=%d",s);
}
	
void main(){
	int c;
	do{

	printf("\n\n1- Insertion\n2-Largest of an array\n3-Smallest ofan array	\n4-Reverse of an array\n5-Sum of an array\n6-Mean of an array\n7-Display\n8-Exit\n Enter the choice:\t");
	scanf("%d",&c);
	switch(c){
		case 1:insert();break;
		case 2:lar();break;
		case 3:small();break;
		case 4:rev();break;
		case 5:sum();break;
		case 6:mean();break;
		case 7:display();break;
		case 8:exit(0); break;
		default:printf("WRONG ENTRY"); break;
	}
	}while(1);
}


