#include <stdlib.h>
#include <stdio.h>

#define len 10

int a[10];

void swap(int *a, int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
int partition(int p,int r){
	int x,i,j;
	x = a[r];
	i=p-1;

	for(j=p;j<r;j++){
		if(a[j]<x){
			i++;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1],&a[r]);
	return(i+1);
}

void quickSort(int p,int r){
	if (p<r){
		int q;
		q=partition(p,r);
		quickSort(p,q-1);
		quickSort(q+1,r);
	}
}
void print(int a[],int n){
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
}

int main(){
	int p[len];
	printf("enter the array of size %d:\n",len);
	for(int j=0;j<len;j++){
		scanf("%d",&a[j]);
	}
	printf("The unsorted array is: ");
	print(a,len);
	printf("\n");
	quickSort(0,len-1);	
	printf("The sorted array is: ");
	print(a,len);
	printf("\n");	

	return (0);
}
