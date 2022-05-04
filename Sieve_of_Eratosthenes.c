#include<stdio.h>
#include<string.h>

void	S_Eratosthenes(int n)
{
	int	nums[n];
	memset (nums, 0, sizeof(int) * n);

	for (int p = 2; p <= n; p++)
	{
		if (nums[p - 1] == 0)
		{
			for (int np = p * p; np <= n; np += p)
				nums[np - 1] = 1;
		}
	}
	for (int p = 2; p <= n; p++)
		if(nums[p - 1] == 0)
			printf ("%d, ", p);

}

int	main()
{
	int n = 1000;
	printf("The prime numbers smaller than or equal to %d are: \n", n);
	S_Eratosthenes(n);
	return (0);
}
