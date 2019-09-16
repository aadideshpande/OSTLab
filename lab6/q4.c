#include <stdio.h>
#include "q4.h"
#include <string.h>

int main()
{
	QUEUE q,*ptr;
	ptr = &q;
	int num;

	ptr->top1 = -1;
	ptr->top2 = -1;
	int n, k;

	printf("1. insert 2.delete 3. exit \n");
	scanf("%d", &n);

	//input the elements in a loop
	while(n != 4)
	{
		if(n == 1)
		{
			printf("enter the number\n");
			//gets(str);
			scanf(" %d",&num );
			inserts(ptr, num);
		}
		else if(n == 2)
		{
			k = deletes(ptr);
			printf("the element deleted is %d \n", k);
		}
		

		printf("enter another option \n");
		scanf("%d", &n);

	}
}