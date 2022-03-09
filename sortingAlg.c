#include <stdio.h>
#include <math.h>
#include <stdlib.h> //for dynamic allocation funtions
/*funtion for insertion sort*/

#define len 10

void print(int *a, int aLen){
	for(int i=0;i<aLen;i++){
		printf("%d ",a[i]);
	}
}

int *scan(int *a, int aLen){
	for(int i=0;i<len;i++){
		scanf("%d",&a[i]);
	}
	return a;
}

int *insertionSort(int *a,int aLen){
	printf("welcome to insertion sort\n");
	int key,bar;
	for(int j=1;j<aLen;j++){
		key=a[j];
		bar=j-1;
		while(bar>=0 && a[bar]>key){
			a[bar+1]=a[bar];
			bar=bar-1;
		}
		a[bar+1]=key;
	}

	return a;
}

int *createArray(int *a,int aLen){
	printf("please enter the set of %d numbers to sort:\n",len);
	a=scan(a,len);
	printf("your unsorted array is:");
	print(a,len);
	return a;
}

int MERGE(int *a,int p,int q,int r){
	int sizeOfL,sizeOfR;
	sizeOfL=q-p+1;
	sizeOfR=r-q;
	int *leftArr,*rightArr;
	leftArr = (int *)malloc((sizeOfL+1)*sizeof(int));
	rightArr = (int *)malloc((sizeOfR+1)*sizeof(int));

	for(int i=0;i<sizeOfL;i++){
		leftArr[i]=a[p+i];
	}

	for(int j=0;j<sizeOfR;j++){
		rightArr[j]=a[q+j+1];
	}
	
	leftArr[sizeOfL]=INFINITY;
	rightArr[sizeOfR]=INFINITY;
	int i=0;
	int j=0;

	for(int k=p;k<=r;k++){
		if (leftArr[i]<=rightArr[j]){
			a[k]=leftArr[i];
			i++;}
		else 
		{ a[k]=rightArr[j];
			j++;
		}
	}
}


int mergeSort(int *a,int p,int r){
	if(p<r){
		int q = (int)floor((p+r)/2);
		mergeSort(a,p,q);
		mergeSort(a,q+1,r);
		MERGE(a,p,q,r);
	}
}
int main(){
	int i,*a,choice=0;
	a = (int *)malloc(len*sizeof(int));

	while(1){
		printf("\nchoose an option:\n1.Enter new elements\n2.insertion sort\n3.exit\n");
		scanf("%d",&choice);

		switch(choice){
			case 1:a = createArray(a,len);break;
			case 2:a = insertionSort(a,len);
			       printf("your sorted array is:");
			       print(a,len);
			       break;
			case 3:a = mergeSort(a,0,len);
			       printf("your sorted array is:");
			       print(a,len);
			       break;
			default: printf("you have succefully exited the algorithm\n");return(0);
	
		}
	}
}
