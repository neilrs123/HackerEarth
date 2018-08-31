/*
Pcart is an online shopping website with N different items for sale such that all items are available in infinite quantities. Panik is opening a shop and wants to buy M items for his shop at the lowest possible price. The price of the ith item is A[i]. But there is a catch, Panik can order only 1 item at a time and after ordering it, the price of the chosen item changes according to the following expression,

New price=(original price xor Pcart constant(X))+1

Panik is not aware of this expression so he always purchases the item with the lowest price in a single transaction.

Predict the amount Panik would have to pay to purchase M items.

As the answer can be very large, print the ans%1e9+7
*/

#include<stdio.h>
#include<math.h>

int parent(int i)
{
	return i/2;
}

int left(int i)
{
	return 2*i;
}

int right(int i)
{
	return 2*i+1;
}

int leaf(int i,int n)
{
	return 2*i > n? 1 : 0;
}

void minheapify(int A[],int i, int n)
{
	int done = 0;
	int smallest;
	while(leaf(i,n)==0 && done==0)
	{
		if(A[i-1]>A[left(i)-1])
		{
			smallest = left(i);
		}
		else smallest = i;
		if(right(i)<=n && (A[smallest-1] > A[right(i)-1]))
		{
			smallest = right(i);
		}
		if(smallest == i)
		{
			done = 1;
		}
		else 
		{
			int temp = A[i-1];
			A[i-1] = A[smallest-1];
			A[smallest-1]= temp;
			i = smallest;
		}
	}
}

void buildheap(int A[], int n)
{
	int i;
	for(i=n/2;i>=0;i--)
	{
		minheapify(A,i+1,n);
	}
}


void update(int a[], int j, int x)
{
	a[j] = (a[j]^x) + 1;
	return;
}

int main()
{
	int i,n,m,x;
	scanf("%d %d %d",&n,&m,&x);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	buildheap(a,n);
	long int cost =0;
	for(i=0;i<m;i++)
	{
	    cost = cost + a[0];
	    update(a,0,x);
	    minheapify(a,1,n);
	}
	printf("%ld",cost%((long int)pow(10,9)+7));
}
