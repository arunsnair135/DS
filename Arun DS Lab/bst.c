#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct tree{
	int info;
	struct tree *right;
	struct tree *left;
};
struct tree *root=NULL;

void create(){
	int n,item;
	struct tree *q;
	printf("\nEnter the number of nodes to be entered\t");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		struct tree *p;
		p=malloc(sizeof(struct tree));
		printf("\nEnter the data ");
		scanf("%d",&item);
		p->info=item;
		p->left=NULL;
		p->right=NULL;
		if(i==0){
			root=p;
		}
		else{
			q=root;
			while(1){
				if(p->info>q->info){
					if(q->right==NULL){
						q->right=p;
						break;
					}
					else{
						q=q->right;
					}
				}
				else{
					if(q->left==NULL){
						q->left=p;
						break;
					}
					else{
						q=q->left;
					}
				}
			}
		}
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

void min(struct tree *r){
	struct tree *t=r;
	if(t==NULL)
		return;
	else{
		while(t->left!=NULL){
			t=t->left;
		}
	}
	printf("\nMinimum Node: %d",t->info);
}

void max(struct tree *r){
	struct tree *t=r;
	if(t==NULL)
		return;
	else{
		while(t->right!=NULL){
			t=t->right;
		}
	}
	printf("\nMaximum Node: %d",t->info);
}
void main(){
	int c;
	do{
		printf("\n1-Insert\n2-preorder\n3-postorder\n4-inorder\n5-Minimum\n6-Maximum\n7-exit\nEnter choice;  ");
		scanf("%d",&c);
		switch(c){
			case 1:create();break;
			case 2:preorder(root);break;
			case 3:postorder(root);break;
			case 4:inorder(root);break;
			case 5:min(root);break;
			case 6:max(root);break;
			case 7:exit(0);break;
			default:printf("\nInvalid Choice");break;
		}
	}while(1);

}

