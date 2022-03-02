#include<stdio.h>
#include<stdlib.h>
int u[10]={1,2,3,4,5,6,7,8,9,10};
int bit_a[10],bit_b[10],anb[10],aub[10],adb[10];

void display(int z[],int y){
	for(int i=0;i<y;i++){
		printf("%d",z[i]);
	}
}

void a_to_bit(int z[],int y){
	for(int i=0;i<10;i++){
		bit_a[i]=0;
		for(int j=0;j<y;j++){
			if(z[j]==u[i]){
				bit_a[i]=1;
			}
		}
	}
}

void b_to_bit(int z[],int y){
	for(int i=0;i<10;i++){
		bit_b[i]=0;
		for(int j=0;j<y;j++){
			if(z[j]==u[i]){
				bit_b[i]=1;
			}
		}
	}
}
		
void and(){
	for(int i=0;i<10;i++){
		anb[i]=0;
		if(bit_a[i]==bit_b[i] && bit_a[i]==1){
			anb[i]=1;
			continue;
		}
	}
	display(anb,10);
}
void or(){
	for(int i=0;i<10;i++){
		aub[i]=0;
		if(bit_a[i]==1 ||bit_b[i]==1){
			aub[i]=1;
		}
	}
	display(aub,10);		
}
void dif(){
	for(int i=0;i<10;i++){
		adb[i]=1;
	}
	for(int i=0;i<10;i++){
		if(bit_a[i]==bit_b[i]){
			 adb[i]=0;
		}
	}
	for(int i=0;i<10;i++){
		if(bit_b[i]==1){
			adb[i]=0;
		}
	}
	display(adb,10);
}
void main(){
	int a[10],b[10],p,q,choice;
	printf("\nEnter the number of elements in the two arrays\t");
	scanf("%d%d",&p,&q);
	printf("\nEnter the elements in the first array\n");
	for(int i=0;i<p;i++){
		scanf("%d",&a[i]);
	}
	printf("\nEnter the elements in the  array\n");
	for(int i=0;i<q;i++){
		scanf("%d",&b[i]);
	}
	a_to_bit(a,p);
	b_to_bit(b,q);
	
	display(bit_a,10);
	printf("\n");
	display(bit_b,10);
while(1){
	printf("\n1-AND\n2-OR\n3-A-B\n4-Exit\nEnter the choice\t");
	scanf("%d",&choice);
	switch(choice){
		case 1:and();break;
		case 2:or();break;
		case 3:dif();break;
		case 4:exit(0);break;
	}
}

}

