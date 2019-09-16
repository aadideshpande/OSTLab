#include <stdio.h>
#include "q3.h"
#include <string.h>

//function to check if the item is present in the queue or not
int check(QUEUE *ptr, int item)
{
	int k, flag = 0;
	for(int i = ptr->front1; i <= ptr->rear1; i++)
	{
		k = ptr->queue1[ptr->front1];
		deletecq1(ptr);
		if(k == item)
		{
			flag = 1;
		}
	}

	if(flag == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	QUEUE q,*ptr;
	ptr = &q;
	int num;

	ptr->front1 = 0;
	ptr->rear1 = 0;
	ptr->front2 = 0;
	ptr->rear2 = 0;
	int n = 0;

	printf("1. insert 3. display 4. exit \n");
	scanf("%d", &n);

	//input the elements in a loop
	while(n != 4)
	{
		if(n == 1)
		{
			printf("enter the number\n");
			//gets(str);
			scanf(" %d",&num );
			insertcq1(ptr, num);
		}
		else if(n == 3)
		{
			display1(ptr);
		}

		printf("enter another option \n");
		scanf("%d", &n);

	}

	//input the element you want to search
	int item;
	printf("enter the number you want to search for \n");
	scanf("%d", &item);

	int answer = check(ptr, item);
	if(answer == 1)
	{
		printf("element present \n");
	}
	else
	{
		printf("element absent\n");
	}
	



	



	
	/*insertcq(ptr, str);
	insertcq(ptr, "science");
	insertcq(ptr, "and");
	deletecq(ptr);
	insertcq(ptr, "algorithms");
	display(ptr);
	*/
}