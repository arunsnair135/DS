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

void insert_pos(){
	struct node *temp=start;
	if(temp==NULL){
		printf("\nList empty");
	}
	else{
		int u,flag=0;
		printf("\nEnter the node data after which you have to insert ");
		scanf("%d",&u);
		ptr=malloc(sizeof(struct node));
		printf("\nEnter the info");
		scanf("%d",&ptr->info);
		while(temp->next!=NULL){
			if(temp->info==u){
				flag=1;
				struct node *pre=temp;
				temp=temp->next;
				ptr->next=temp;
				pre->next=ptr;
				break;
			}
			temp=temp->next;
		}
		if(flag==0){
			printf("\nNo such Node");
		}
	}
}
void del_beg(){
	struct node *temp=start;
	if(temp==NULL){
		printf("\nList empty");
	}
	else{
		start=start->next;
		free(temp);
	}
}
void del_end(){
	struct node *temp=start;
	if(temp==NULL){
		printf("\nList empty");
	}
	else{
		if(start->next==NULL){
			start=NULL;
			free(temp);
		}
		else{
			struct node *pre;
			while(temp->next!=NULL){
				pre=temp;
				temp=temp->next;
			}
			pre->next=NULL;
		}
	}
}

void del_node(){
	struct node *temp=start;
	if(temp==NULL){
		printf("\nList empty");
	}
	else{
		int item;
		struct node *pre;
		printf("\n Enter node to be deleted: ");
		scanf("%d",&item);
		if(start->info==item){
			start=start->next;
			free(temp);
		}
		else{
			while(temp!=NULL){
				if(temp->info==item){
					pre->next=temp->next;
					struct node *w=temp;
					free(w);
				}
				pre=temp;
				temp=temp->next;
			}
		}
		
		
	}
}

				
				
int main(){
	int c;
	do{
		printf("\n1-Insertion at Begining\n2-Insertion at End\n3-Insertion after a specific node\n4-Traverse\n5-Delete at begining\n6-Delete at end\n7-Delete a given node\n8-Exit\nEnter Your Choice  ");
		scanf("%d",&c);
		switch(c){
			case 1:insert_at_beg(); break;
			case 2:insert_at_end(); break;
			case 3:insert_pos(); break;
			case 4:traverse(); break;
			case 5:del_beg(); break;
			case 6:del_end(); break;
			case 7:del_node();break;
			case 8:exit(0); break;
			default:printf("\nINVALID CHOICE"); break;
		}
	}while(1);

	return(0);
}
