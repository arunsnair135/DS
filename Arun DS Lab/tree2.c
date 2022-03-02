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

int choice;
struct node * create(){  
	struct node *temp;  
	int data;  
	temp=malloc(sizeof(struct tree *));  
	printf("Press 0 to exit");   
	printf("Enter your choice : ");  
	scanf("%d", &choice);   
	if(choice==0){  
		return 0;  
  	}  
	else  
	{  
		printf("Enter the data:");  
  		scanf("%d", &data);  
  		temp->info = data;  
  		printf("Enter the left child of %d", data);  
  		temp->left = create();  
		printf("Enter the right child of %d", data);  
		temp->right = create();  
		return temp;   
	}  
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
		
		preorder(t->left);
		preorder(t->right);
		printf("\t%d",t->info);
	}
}
void inorder(struct tree *r){
	struct tree *t=r;
	if(t==NULL)
		return;
	else{
		
		preorder(t->left);
		printf("\t%d",t->info);
		preorder(t->right);
		
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

