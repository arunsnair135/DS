#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
	int info; 
	struct node *next;
};
struct node *start=NULL;
struct node *ptr;

void insert(){
	ptr=malloc(sizeof(struct node));
	printf("\n Enter the Info: ");
	scanf("%d",&ptr->info);
	ptr->next=start;
	start=ptr;
}

void traverse(){
	struct node *temp=malloc(sizeof(struct node));
	temp=start;
	while(temp!=NULL){
		printf("\t%d",temp->info);
		temp=temp->next;
	}
}
	
void count(){
	struct node *temp;
	temp=start;
	int c=0;
	if(temp==NULL){
		printf(" Count=0");
	}
	else{
		while(temp!=NULL){
			c++;
			temp=temp->next;
		}
		printf(" Count=%d",c);
	}	
}
void search(){
	struct node *temp=malloc(sizeof(struct node));
	temp=start;
	int c=0,flag=0;
	if(temp==NULL){
		printf("\n List is Empty");
	}
	else{
		int u;
		printf("\nEnter the data to be searched ");
		scanf("%d",&u);
		while(temp!=NULL){
			c++;
			if(temp->info==u){
				int flag=1;
				printf("\nNode data %d found at %d",u,c);
			}
			temp=temp->next;
		}
		if(flag==0){
			printf("\nNo such data in any node.");
		}
	}
}
		

int main(){
	int c;
	do{
		printf("\n1-Insertion\n2-Traverse\n3-Count\n4-Search\n5-Exit\nEnter Your Choice  ");
		scanf("%d",&c);
		switch(c){
			case 1:insert(); break;
			case 2:traverse(); break;
			case 3:count(); break;
			case 4:search(); break;
			case 5:exit(0); break;
			default:printf("\nINVALID CHOICE"); break;
		}
	}while(1);

	return(0);
}
