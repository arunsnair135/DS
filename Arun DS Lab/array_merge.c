#include<stdio.h>
void main(){
	int a[10],b[10],c[30],n,m,k,i,j;
	printf("\nEnter the size of the first array ");
	scanf("%d",&n);
	printf("\nenter the elements");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("\nEnter the size of the second array ");
	scanf("%d",&m);
	printf("\nenter the elements");
	for(j=0;j<m;j++){
		scanf("%d",&b[j]);
	}
	i=j=k=0;
	while(i<n && j<m){
		if(a[i]<b[j]){
			c[k++]=a[i++];
		}
		else if(a[i]>b[j]){
			c[k++]=b[j++];
		}
		else{
			c[k++]=b[j++];
			i++;
		}
	}
	while(i<n){
		c[k++]=a[i++];
	}
	while(j<m){
		c[k++]=b[j++];
	}
	
	printf("\nMerged array\n");
	for(int f=0;f<k;f++){
		printf("\t%d",c[f]);
	}	
}
	
