#include <stdio.h>
#include "q2.h"
#include <string.h>

int maxsize;
int main()
{
	QUEUE q,*ptr;
	ptr = &q;
	int num;

	ptr->front1 = 0;
	ptr->rear1 = 0;
	ptr->front2 = MAXSIZE / 2;
	ptr->rear2 = MAXSIZE / 2;
	int n = 0;

	/* insertcq1(ptr,5);
	insertcq1(ptr,15);
	insertcq1(ptr,50);
	deletecq1(ptr);
	insertcq1(ptr,150);
	display1(ptr);

	insertcq2(ptr,44);
	insertcq2(ptr,34);
	insertcq2(ptr,12);
	insertcq2(ptr,11);
	deletecq2(ptr);
	display2(ptr);	*/


	printf("1. insert 2. delete, 3. display 4. insert2 5. delete2 6.display2 7. exit \n");
	scanf("%d", &n);

	while(n != 7)
	{
		if(n == 1)
		{
			printf("enter the number\n");
			//gets(str);
			scanf(" %d",&num );
			insertcq1(ptr, num);
		}
		else if(n == 2)
		{
			deletecq1(ptr);
		}
		else if(n == 3)
		{
			display1(ptr);
		}
		if(n == 4)
		{
			printf("enter the number \n");
			//gets(str);
			scanf(" %d", &num);
			insertcq2(ptr, num);
		}
		else if(n == 5)
		{
			deletecq2(ptr);
		}
		else if(n == 6)
		{
			display2(ptr);
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