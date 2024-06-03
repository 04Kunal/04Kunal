//1. Bubble sort

#include<stdio.h>

void bubble(int a[], int n);

int main()
{
    int n, i;

    printf("Enter the number : ");
    scanf("%d", &n);

    int a[n];

    printf("Enter the numbers: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    bubble(a, n);

    return 0;
}

void bubble(int a[], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++) // Fix: Change i++ to j++
        {
            if (a[j + 1] < a[j])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    printf("Sorted array is: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    
}

/*
//2. selection sort

#include<stdio.h>
void selectionsort(int [], int);

int main()
{
	int n, i;
	printf("Enter no. of elements:");
	scanf("%d",&n);
	int a[n];
	printf("Enter array elements:\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	//Function call
	selectionsort(a,n);		
	return 0;
}

void selectionsort(int arr[], int n){
	int i,j,k,small,p,temp;
	
	for(i=0;i<n;i++){			// Actual working
		small = arr[i];
		p = i;
		
		for(j=i+1;j<n;j++){
			if(arr[j] < small){
				small = arr[j];
				p = j;
			}
		}
		
		// Swapping smallest and leftmost
		temp = arr[i];		
		arr[i] = arr[p];
		arr[p] = temp;
		
		// Displaying all pass
		printf("Pass %d:",i+1);
		for(k=0;k<n;k++){
			printf("%d\t",arr[k]);
		}
		printf("\n");
	}
	printf("Displaying sorted list:\n");
	for(i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
}


//3. insertion sort

#include<stdio.h>
void insertionsort(int [], int);

int main()
{
	int n, i;
	printf("Enter no. of elements:");
	scanf("%d",&n);
	
	int arr[n];
	printf("Enter elements:\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	insertionsort(arr, n);
	return 0;
}
void insertionsort(int a[], int n){
	int i,j,key;
	for(i=1;i<n;i++){
		key = a[i];
		
		for(j=i-1;j>=0;j--){
			if(a[j] > key){
				a[j+1] = a[j];
			}
			else{
				a[j+1] = key;
				break;
			}
			a[j] = key;
		}
	}
	printf("Displaying elements:\n");
	for(i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
}


//4. merge sort
#include <stdio.h>

// Merge two sorted subarrays arr[l..m] and arr[m+1..r]
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
// Recursive function to perform merge sort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}

// Function to print an array
void printArray(int A[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main() {
    int n,i;
    printf("Enter array size:");
    scanf("%d",&n);
    
    int arr[n];
    printf("Enter array elements:");
    for(i=0;i<n;i++){
    	scanf("%d",&arr[i]);
	}

    printf("Given array is \n");
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("\nSorted array is \n");
    printArray(arr, n);
    return 0;
}



//5. QuickSorting


#include<stdio.h>
void quicksort(int number[25],int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);

   }
}

int main(){
   int i, count, number[25];

   printf("How many elements are u going to enter?: ");
   scanf("%d",&count);

   printf("Enter %d elements: ", count);
   for(i=0;i<count;i++)
      scanf("%d",&number[i]);

   quicksort(number,0,count-1);

   printf("Order of Sorted elements: ");
   for(i=0;i<count;i++)
      printf(" %d",number[i]);

   return 0;
}


//6. shell
#include <stdio.h>

void shell_sort(int arr[], int n) {
    int gap, i, j, temp;

    for (gap = n/2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = arr[i];
            j = i - gap;

            while (j >= 0 && arr[j] > temp) {
                arr[j + gap] = arr[j];
                j -= gap;
            }

            arr[j + gap] = temp;
        }
    }
}

int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
     int arr[n];
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    shell_sort(arr, n);
    printf("Sorted array: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

*/
