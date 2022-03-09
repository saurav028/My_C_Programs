#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int heapSize;


void swap(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}


void maxHeapify(int *a,int i){
	int leftChild,rightChild,largest;
	leftChild=2*i;
	rightChild=2*i+1;

	if (leftChild<=heapSize && a[leftChild]>a[i]){
		largest = leftChild;
	}
	else largest = i;

	if (rightChild<=heapSize && a[rightChild]>a[i]){
		largest = rightChild;
	}

	if (largest != i){
		swap(&a[i],&a[largest]);
		maxHeapify(a,largest);
	}
}

//function to buiild heap
void buildHeap(int *a,int len){
	heapSize=len;printf("length=%d\n",len);
	for(int i=(int)floor(len/2);i>=1;i--){
		printf("i=%d\n",i);
		maxHeapify(a,i);
	}
}
void print(int *a,int len){
	for(int i=1;i<=len;i++){
		printf("%d ",a[i]);
	}
}

//function to implement heap sort

void heapSort(int *a, int len){
	buildHeap(a,len);
	for(int i=len;i>1;i--)
	{
		//printf("last element:%d\n",a[i]);
		printf("the unsorted list is: ");print(a,len);printf("\n");
		swap(&a[i],&a[1]);
		heapSize--;
		maxHeapify(a,1);
	}
}

	

int main(){
	int sizeOfList;
	printf("Etner the size of list:");scanf("%d",&sizeOfList);
	int *list;
	//creating an array of size "sizeofList"+ '1'
	list = (int *)malloc((sizeOfList+1)*sizeof(int));

	printf("Enter the List element:\n");
	for(int i=1;i<=sizeOfList;i++){
		scanf("%d",&list[i]);
	}
	printf("the unsorted list is: ");print(list,sizeOfList);printf("\n");

	heapSort(list,sizeOfList);
	printf("the sorted list is: ");print(list,sizeOfList);printf("\n");

	return(0);
}


























