#include <stdio.h>
#include "q1.h"
#include <string.h>

int maxsize;
int main()
{
	QUEUE q,*ptr;
	ptr = &q;

	ptr->front = 0;
	ptr->rear = 0;
	int n = 0;
	char str[100];

	printf("1. insert 2. delete, 3. display 4. exit \n");
	scanf("%d", &n);

	while(n != 4)
	{
		if(n == 1)
		{
			printf("enter the string \n");
			//gets(str);
			scanf(" %s", str);
			insertcq(ptr, str);
		}
		else if(n == 2)
		{
			deletecq(ptr);
		}
		else if(n == 3)
		{
			display(ptr);
		}

		printf("enter another option \n");
		scanf("%d", &n);

	}

	
	/*insertcq(ptr, str);
	insertcq(ptr, "science");
	insertcq(ptr, "and");
	deletecq(ptr);
	insertcq(ptr, "algorithms");
	display(ptr);
	*/
}