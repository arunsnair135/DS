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

struct tree * min(struct tree *r){
	struct tree *t=r;
	if(t==NULL)
		return t;
	else{
		while(t->left!=NULL){
			t=t->left;
		}
	}
	return t;
}

struct tree * max(struct tree *r){
	struct tree *t=r;
	if(t==NULL)
		return t;
	else{
		while(t->right!=NULL){
			t=t->right;
		}
	}
	return t;
	
}
struct tree * search(struct tree *r,int key){
	if(r==NULL){
		return 0;
	}
	else if(key==r->info){
		return r;
	}
	else{
		if(key<r->info){
			search(r->left,key);
		}
		else
		{
			search(r->right,key);
		}
	}	

}

struct tree * inorder_successor(struct tree * t){
	if(t->right!=NULL){
		struct tree *r=t->right;
		while(r->left!=NULL){
			r=r->left;
		}
		return r;
	}
	else{
		struct tree * r=root;
		struct tree * s;
		while(r->info!=t->info){
			if(t->info < r->info){
				s=r;
				r=r->left;
			}
			else{
				r=r->right;
			}
		}
		return s;
}	}

struct tree * delete(struct tree *r,int key){
	if(r==NULL){
		return r;
	}
	else if(key<r->info){
		printf("\nr to left");
		r->left=delete(r->left,key);
		printf("\n left set");
		
	}
	else if(key>r->info){
		printf("\nr to right");
		r->right=delete(r->right,key);
		printf("\n right set");
		
	}
	else{
		printf("\nkey matched");
		if(r->left==NULL && r->right==NULL){
			printf("2 NULL");
			free(r);
			return NULL;
		}
		else if(r->left==NULL){
			struct tree *temp=r->right;
			free(r);
			printf("left NULL");
			return temp;
		}
	
		else if(r->right==NULL){
			struct tree *temp=r->left;
			free(r);
			printf("right NULL");
			return temp;
		}
		struct tree *temp=min(r->right);
		printf("found inorder successor");
		r->info=temp->info;
		r->right=delete(r->right,temp->info);
		
	}
	return r;
}			

void main(){
	int c,k;
	struct tree * res;
	struct tree * in;
	struct tree * ret;
	do{
		printf("\n1-Insert\n2-preorder\n3-postorder\n4-inorder\n5-Minimum\n6-Maximum\n7-Search\n8-Inorder successor\n9-delete\n0-exit\nEnter choice;  ");
		scanf("%d",&c);
		switch(c){
			case 1:create();break;
			case 2:preorder(root);break;
			case 3:postorder(root);break;
			case 4:inorder(root);break;
			case 5:ret=min(root);
				printf("\nMinimum Node:%d",ret->info);
				break;
			case 6:ret=max(root);
				printf("\nMaximum Node: %d",ret->info);
				break;
			case 7:printf("\nEnter the data to be searched: ");
				scanf("%d",&k);
				ret=search(root,k);
				if(ret->info==k){
					printf("\nNode Found");
				}
				else{
					printf("\nNode Not Found");
				}
				break;
			case 8:printf("\nEnter the node to find its inorder successor: ");
				scanf("%d",&k);
				ret=search(root,k);
				printf("%d",ret->info);
				if(ret->info==k){
					res=inorder_successor(ret);
					printf("\nInorder Successor=%d",res->info);
				}
				else{
					printf("\nNo Such Node to Find the Inorder Successor");
				}
				break;
			case 9:printf("\nEnter the data to be deleted: ");
				scanf("%d",&k);
				if(k==root->info){
					root=NULL;
				}
				else{
					delete(root,k);
				}
				 break;
			case 0:exit(0);break;
			default:printf("\nInvalid Choice");break;
		}
	}while(1);

}

