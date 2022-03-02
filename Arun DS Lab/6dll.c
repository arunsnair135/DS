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
	if(start!=NULL)
	start->pre=ptr;
	start=ptr;
}
void traverse(){
	if(start==NULL){
		printf("\nList empty");
	}
	else{
		
		struct node *temp=start;
		while(temp!=NULL){
		printf("\t%d",temp->info);
		temp=temp->next;
		}
	}
}

void dll_insert_end(){
	ptr=malloc(sizeof(struct node));
	ptr->next=NULL;
	printf("\nEnter the info");
	scanf("%d",&ptr->info);
	if(start==NULL){
		ptr->next=ptr->pre=NULL;
		start=ptr;
	}
	else{
		struct node *temp=start;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		ptr->pre=temp;
		temp->next=ptr;
	}
}
void dll_delete_beg(){
	if(start==NULL){
		printf("\nList Empty");
	}
	else{
		ptr=start;
		if(start->next==NULL){
			start=NULL;
		}
		else{
			start=start->next;
			start->pre=NULL;
		}
		free(ptr);
	}
}

void dll_delete_end(){
	if(start==NULL){
		printf("\nList Empty");
	}
	else{
		struct node *temp=start;
		if(start->next==NULL){
			start=NULL;
		}
		else{
			while(temp->next!=NULL){
			temp=temp->next;
			}
			ptr=temp->pre;
			ptr->next=NULL;
		}
		free(temp);
	}
}
			
void dll_insert_after(){
	if(start==NULL){
		printf("\nList Empty");
	}
	else{
		struct node *temp=start;
		int item,flag=0;
		ptr=malloc(sizeof(struct node));
		printf("\nEnter the node after which you have to insert the node: ");
		scanf("%d",&item);	
		printf("\nEnter the data");
		scanf("%d",&ptr->info);
		while(temp!=NULL){
			if(temp->info==item){
				ptr->next=temp->next;
				if(temp->next!=NULL)
				temp->next->pre=ptr;
				ptr->pre=temp;
				temp->next=ptr;
				flag=1;
				return;
			}
			temp=temp->next;
		}
		if(flag==0){
			printf("\n No such node");
		}
	}
}
void dll_delete_after(){
	if(start==NULL){
		printf("\nList Empty");
	}
	else{
		struct node *temp=start;
		int item,flag=0;
		struct node *ptr;
		struct node *ptr1;
		printf("\nEnter the node after which you have to delete the node: ");
		scanf("%d",&item);	
		if(start->info==item && start->next==NULL){
			printf("\n No node to delete");
		}
		else{

			while(temp!=NULL){
				if(temp->info==item){
					ptr=temp->next;
					if(temp->next==NULL){
						printf("\n No node to delete");
					}
					
					else{
						if(ptr->next==NULL){
							temp->next=NULL;
						}
						else{
							ptr1=ptr->next;
							ptr1->pre=temp;
							temp->next=ptr1;
							
						}
						free(ptr);
						return;
					}
				}
				temp=temp->next;
			}
		}
	}
}
				
				
				
					
		


int main(){
	int c;
	do{
		printf("\n1-Insertion at Begining\n2-Insertion at End\n3-Insertion after a specific node\n4-Traverse\n5-Delete at begining\n6-Delete at end\n7-Delete after a given node\n8-Exit\nEnter Your Choice  ");
		scanf("%d",&c);
		switch(c){
			case 1:dll_insert_beg(); break;
			case 2:dll_insert_end();break;
			case 3:dll_insert_after();break;
			case 4:traverse(); break;
			case 5:dll_delete_beg();break;
			case 6:dll_delete_end();break;
			case 7:dll_delete_after();break;
			case 8:exit(0); break;
			default:printf("\nINVALID CHOICE"); break;
		}
	}while(1);

	return(0);
}
