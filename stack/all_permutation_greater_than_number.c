// Given a number n, find all numbers between 1:n 
// whose all permutations are greather than that number

#include<stdio.h>

void print_permutation(int n)
{
	int i = 1, j = 1;
	for(i = 1; i <= 9; i++) {
		if( i <= 9) {
			printf("%d  ", i);
		}

		int num = 0;
		for(j = i; j <= 9; j++) {
			num = i * 10  + j;
			if (num <= n) {
				printf("%d  ", num);
			}
		}
		num = 0;
		printf("\n");
	}
}

int main()
{
	int n;
	printf("Enter a number: ");
	scanf("%d", &n);

	print_permutation(n);
}
