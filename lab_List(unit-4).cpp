/*
//1. WAP to create and display all elements of list.

#include<stdio.h>

int main(){
	int a[100],i,n,deleting;
	printf ("enter the element:");
	scanf("%d",&n);
	
	printf("the list:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		
	}
	printf("display the list\n");
	for(i=0;i<n;i++){
	
	printf("%d\t",a[i]);
}
  
	getchar();
}

*/
/*
//2.WAP to insert a new element in a pre-existed list.

#include<stdio.h>
int main()
{
	int a[100],i,pos,size,item;
	printf("enter the array ");
	scanf("%d",&size);
	printf("enter the number:\n");
	for(i=0;i<size;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter the position to insert:");
	scanf("%d",&pos);
	printf("enter the number that you insert:");
	scanf("%d",&item);
	for(i=size;i>pos;i--)
	{
		a[i]=a[i-1];
	}
	a[pos]=item;
	size++;
	printf("display the number:");
	for(i=0;i<size;i++){
		printf("%d\t",a[i]);
	}
	getchar();
}

*/

/*
//3. WAP to delete an element from a list

#include<stdio.h>
int main(){
	int a[100],pos,i,n;
	printf("enter the number:\n");
	scanf("%d",&n);
	printf("enter the  element:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		
	}
	printf("enter the position to delete:");
	scanf("%d",&pos);
	
	for(i=pos-1;i<n-1;i++)
	{
	
	a[i]=a[i+1];
}
	printf("delete:\n");
	for(i=0;i<n-1;i++)
	{
		printf("%d\t",a[i]);
	}
	getchar();
}

*/


//4 WAP to modify an element from a list.


#include <stdio.h>

int main() {
    int a[100], i, n, m, b;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the update position (0 to %d): ", n - 1);
    scanf("%d", &m);

    if (m >= 0 && m < n) {
        printf("Enter the new value: ");
        scanf("%d", &b);

        a[m] = b;  // Update the element at position m with the new value b

        printf("Updated list:\n");
        for (i = 0; i < n; i++) {
            printf("%d\t", a[i]);
        }
        printf("\n");
    } else {
        printf("Invalid position!\n");
    }

    return 0;
}

*/



//5. WAP to merge two pre-existed list.


// merage two list
#include<stdio.h>
int main(){
	int a1[3],a2[2],a[5],i,j=0;
	printf("Enter 3 elements for the first list:");
	for(i=0;i<3;i++){
	
	scanf("%d",&a1[i]);
	}
	printf("Enter 2 elements for the second list:");
	for(i=0;i<2;i++){
	
	scanf("%d",&a2[i]);
	}
	for(i=0;i<3;i++)
	{
		a[j]=a1[i];
		j++;
	}
	
	for(i=0;i<2;i++)
	{
		a[j]=a2[i];
		j++;
	}
	printf("display merge list:\t");
	for(i=0;i<5;i++)
	{
		printf("%d\t",a[i]);
	}
	getchar();
	
	
}

*/

