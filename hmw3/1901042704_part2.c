#include<stdio.h>			/* hacı hasan savan - 1901042704 - hmw3_part2*/
#include<math.h>

						
int isPrime (int);

int main()
{
	int userInput, i;
	printf("please enter an integer: ");
	scanf("%d", &userInput);
	printf("\n");

	for(i=2; i<userInput; i++)
	{
		if(isPrime(i)==1)								// If it's 1 it means that the i is prime
			printf("%d is a prime number\n", i);
		else										//else it's not a prime; it's dividible by coming number from isPrime funciton				
			printf("%d is not a prime number. It's dividible by %d\n", i, isPrime(i));
	}
}

int isPrime (int a)
{
	int k, flag=1;			

	for(k=2; k<=sqrt(a); k++)
	{
		if(a%k==0)
			flag=k;
	}
	
	return flag;
}
