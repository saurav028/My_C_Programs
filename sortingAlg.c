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
			default: printf("you have succefully exited the algorithm\n");return(0);
	
		}
	}
}
