#include <stdio.h>

/* C recursive function to solve tower of hanoi puzzle*/
void towerOfHanoi(int n, char l, char r, char m)
{
	if (n == 1)
	{
		printf("\n Move disk 1 from rod %c to rod %c", l, r);
		return;
	}
	towerOfHanoi(n-1, l, m, r);
	printf("\n Move disk %d from rod %c to rod %c", n, l, r);
	towerOfHanoi(n-1, m, r, l);
}

int main()
{
	int n;
	printf("\n ENTER NO OF DISk :\n");
	scanf("%d",&n); /* Number of disks*/
	towerOfHanoi(n, 'A', 'C', 'B'); /* A, B and C are names of rods*/
	return 0;
}

