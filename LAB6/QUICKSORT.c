#include<stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(int a[],int low, int high)
{
    int split;
    if(low<high)
    {
        split=partition(a,low,high);
        quicksort(a,low,split-1);
        quicksort(a,split+1,high);
    }

}

int partition(int a[],int low,int high)
{
    int pivot,i,j;
    pivot=a[low];
    i=low+1;
    j=high;
    do{
        while(a[i]>=pivot){
            i++;
        }
        while(a[j]<=pivot){
            j--;
        }
        swap(&a[i],&a[j]);
    }while(i>=j);
    swap(&a[i],&a[j]);
    swap(&a[j],&a[low]);
    return j;
}

void main()
{
int a[15000],n, i,j,ch, temp;
   clock_t start,end;

   while(1)
   {
 printf("\n1:For manual entry of N value and array elements");
 printf("\n2:To display time taken for sorting number of elements N in the range 500 to 14500");
 printf("\n3:To exit");
     printf("\nEnter your choice:");
     scanf("%d", &ch);
     switch(ch)
     {
       case 1:  printf("\nEnter the number of elements: ");
		scanf("%d",&n);
		printf("\nEnter array elements: ");
		for(i=0;i<n;i++)
		 {
		  scanf("%d",&a[i]);
		 }
		start=clock();
		quicksort(a,0,n-1);
		end=clock();
		printf("\nSorted array is: ");
		for(i=0;i<n;i++)
		printf("%d\t",a[i]);
printf("\n Time taken to sort %d numbers is %f Secs",n, (((double)(end-start))/CLOCKS_PER_SEC));
		break;
     case 2:
	       n=500;
	       while(n<=14500) {
	       for(i=0;i<n;i++)
		  {

		    a[i]=n-i;
		  }
	       start=clock();
	       quicksort(a,0,n-1);
	   for(j=0;j<500000;j++){ temp=38/600;}
	       end=clock();
printf("\n Time taken to sort %d numbers is %f Secs",n, (((double)(end-start))/CLOCKS_PER_SEC));
	             n=n+1000;
		  }
	      break;
   case 3: exit(0);
   }
   getchar();
    }
}
