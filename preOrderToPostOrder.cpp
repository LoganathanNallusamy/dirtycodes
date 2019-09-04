#include<stdio.h>
#include<limits.h>

void post_order_util(int *pre, int index, int min, int max, int n)
{
	if(index == n) return;
		 	
	int val = pre[index];

	if (val < min || val > max)
		return;
	++index;
	post_order_util(pre, index, min, val, n);
	post_order_util(pre, index, val, max, n);
	
	printf("\n  %d  ", val);	

}

void findPostOrder(int *pre, int n)
{
	int post[n];
	int index =0;
	post_order_util(pre,index,INT_MIN,INT_MAX,n);


}


// Driver code
int main()
{
    int pre[] = { 40, 30, 35, 80, 100 };
 
    int n = sizeof(pre) / sizeof(pre[0]);
 
    // Calling function
    findPostOrder(pre, n);
    return 0;
}	

