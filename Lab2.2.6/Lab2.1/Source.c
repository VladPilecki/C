



#include <stdio.h>
#include <conio.h>
#include <math.h>

void function();

int main(int argc, char* argv[])
{
	

	while (1)
	{
		int choice;
		while (1)
		{
			printf("Press '1' if you want to continue \nPress '2' to exit.\n");

			char tempn = '\n';
			if (scanf_s("%d%c", &choice, &tempn) == 2 && tempn == '\n')
			{
				break;
			}

			printf("Error.Try again...\n");
			_getch;
			rewind(stdin);
		}

		switch (choice)
		{
		case 1:
		{
			function();
		} break;
		case 2:
		{
			return 0;
		}
		}
	}
	return 0;
}

void function()
{
	double eps, x, rightsum = 0, mem;

	int i = 3, k = 1, count = 1;
	long  factorialx;

	printf("Epsilon= ");
	scanf_s("%lf", &eps);

	printf("x=");
	scanf_s("%lf", &x);

	rightsum = x;

	do
	{
		k = (-1) * k;

		factorialx = 2;
		for (int j = 3; j <= i; j++)
		{
			factorialx *= j;
		}

		mem = k * pow(x, (double)i) / factorialx;
		rightsum += mem;

		count++;
		i += 2;
	} while ((fabs(rightsum - sin(x)) >= eps));

	printf("x = %f   E = %f \n\nsin(x) = %f   function decomposition: %f\n last element number:%d\n", x, eps, sin(x), rightsum, count);
}
