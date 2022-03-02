#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
	int info; 
	struct node *next;
	struct node *pre;
};
struct node *start=NULL;
struct node *ptr;
void dll_insert_beg(){
	ptr=malloc(sizeof(struct node));
	printf("\nEnter the info");
	scanf("%d",&ptr->info);
	ptr->pre=NULL;
	ptr->next=start;
	start->pre=ptr;
	start=ptr;
}
void traverse(){
	if(start==NULL){
		printf("\nList empty");
	}
	else{
		struct node *temp;
		temp=start;
		while(temp!=NULL){
		printf("\t%d",temp->info);
		temp=temp->next;
		}
	}
}
int main(){
	int c;
	do{
		printf("\n1-Insertion at Begining\n2-Insertion at End\n3-Insertion after a specific node\n4-Traverse\n5-Delete at begining\n6-Delete at end\n7-Delete a given node\n8-Exit\nEnter Your Choice  ");
		scanf("%d",&c);
		switch(c){
			case 1:dll_insert_beg(); break;

			case 4:traverse(); break;
			case 8:exit(0); break;
			default:printf("\nINVALID CHOICE"); break;
		}
	}while(1);

	return(0);
}
