#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
	int info; 
	struct node *next;
};
struct node *start=NULL;
struct node *ptr;

void insert_at_beg(){
	ptr=malloc(sizeof(struct node));
	printf("\n Enter the Info: ");
	scanf("%d",&ptr->info);
	ptr->next=start;
	start=ptr;
}

void traverse(){
	struct node *temp;
	temp=start;
	while(temp!=NULL){
		printf("\t%d",temp->info);
		temp=temp->next;
	}
}
	
void insert_at_end(){
	ptr=malloc(sizeof(struct node));
	printf("\n Enter the Info: ");
	scanf("%d",&ptr->info);	
	ptr->next=NULL;
	struct node *temp=start;
	struct node *pre;
	if(temp==NULL){
		start=ptr;
	}
	else{
		while(temp->next!=NULL){
			temp=temp->next;
			}
		temp->next=ptr;
			
		}
	}

}
int main(){
	int c;
	do{
		printf("\n1-Insertion at Begining\n2-Insertion at End\n3-Insertion after a specific node\n4-Traverse\n5-Exit\nEnter Your Choice  ");
		scanf("%d",&c);
		switch(c){
			case 1:insert_at_beg(); break;
			case 2:insert_at_end(); break;
			case 4:traverse(); break;
			case 5:exit(0); break;
			default:printf("\nINVALID CHOICE"); break;
		}
	}while(1);

	return(0);
}
