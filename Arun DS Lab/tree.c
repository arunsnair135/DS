#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct tree{
	int info;
	struct tree *right;
	struct tree *left;
};
struct tree *root=NULL;
int ch;
struct tree temp;
void create(){
	struct tree *ptr1=malloc(sizeof(struct tree));
	struct tree *ptr2=malloc(sizeof(struct tree));
	struct tree *ptr3=malloc(sizeof(struct tree));
	struct tree *ptr4=malloc(sizeof(struct tree));
	struct tree *ptr5=malloc(sizeof(struct tree));
	struct tree *ptr6=malloc(sizeof(struct tree));
	struct tree *ptr7=malloc(sizeof(struct tree));

	root=ptr1;	

	ptr7->right=NULL;
	ptr7->left=NULL;
	ptr6->right=NULL;
	ptr6->left=NULL;
	ptr5->right=NULL;
	ptr5->left=NULL;
	ptr4->right=NULL;
	ptr4->left=NULL;
	
	ptr1->left=ptr2;
	ptr1->right=ptr3;

	ptr2->left=ptr4;
	ptr2->right=ptr5;

	ptr3->left=ptr6;
	ptr3->right=ptr7;
	printf("\n   1    ");
	printf("\n 2    3");
	printf("\n4 5  6 7");
	printf("\nEnter the data of node 1\n");
	scanf("%d",&ptr1->info);

	printf("\nEnter the data of node 2\n");
	scanf("%d",&ptr2->info);

	printf("\nEnter the data of node 3\n");
	scanf("%d",&ptr3->info);


	printf("\nEnter the data of node 4\n");
	scanf("%d",&ptr4->info);

	printf("\nEnter the data of node 5\n");
	scanf("%d",&ptr5->info);

	printf("\nEnter the data of node 6\n");
	scanf("%d",&ptr6->info);

	printf("\nEnter the data of node 7\n");
	scanf("%d",&ptr7->info);

}
void preorder(struct tree *r){
	struct tree *t=r;
	if(t==NULL)
		return;
	else{
		printf("\t%d",t->info);
		preorder(t->left);
		preorder(t->right);
	}
}

void postorder(struct tree *r){
	struct tree *t=r;
	if(t==NULL)
		return;
	else{
		
		postorder(t->left);
		postorder(t->right);
		printf("\t%d",t->info);
	}
}
void inorder(struct tree *r){
	struct tree *t=r;
	if(t==NULL)
		return;
	else{
		
		inorder(t->left);
		printf("\t%d",t->info);
		inorder(t->right);
		
	}
}
void main(){
	int c;
	do{
		printf("\n1-Insert\n2-preorder\n3-postorder\n4-inorder\n5-exit\nEnter choice;  ");
		scanf("%d",&c);
		switch(c){
			case 1:create();break;
			case 2:preorder(root);break;
			case 3:postorder(root);break;
			case 4:inorder(root);break;
			case 5:exit(0);break;
			default:printf("\nInvalid Choice");break;
		}
	}while(1);

}

