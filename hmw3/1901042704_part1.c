#include<stdio.h>				/*hacı hasan savan - 1901042704- hmw3_part1*/

#define TRUE 1			/*these flags are for controlling loops*/	
#define FALSE 0

int sum (int, int);
int mult (int, int);

int main()
{
	int check=TRUE, userInput, selectOperation, numberType;
	
	while(check==TRUE)
	{
	check=FALSE;

	printf("\nplease enter an integer: ");							/* choose the operation summation or multiplication*/
	scanf("%d", &userInput);
	printf("\nplease enter '0' for sum, '1' for multiplication> ");		
	scanf("%d", &selectOperation);

		switch(selectOperation)
		{
		case 0:										/*If  the selectOperation is '0', call the summation operation*/				
			printf("please enter '0' to work on even number; '1' to work on odd numbers> ");			
			scanf("%d", &numberType);							/*choose the number type even or odd*/
			
			if(numberType!=0 && numberType!=1)
			{
				printf("invalid value for odd/even selection!!\n");
				check=TRUE;
			}
			else
				printf("%d\n", sum(userInput, numberType));					//the summation is called. It will be worked according to the numberType 
			break;
		
		case 1: 											/*If  the selectOperation is '1', call the multiplication operation*/
			printf("please enter '0' to work on even number; '1' to work on odd numbers> ");
			scanf("%d", &selectOperation);								/*choose the number type even or odd*/
			
			if(selectOperation!=0 && selectOperation!=1)
			{
				printf("invalid value for odd/even selection!!\n");
				check=TRUE;
			}
			
			else
				printf("%d\n",mult(userInput,selectOperation));								 
			break;
		
		default :
			printf("unsupported operation!!\n");
			check=TRUE;
		
	}
		
	}

}




int sum(int n, int flag)					/*flag is 0 --> even; flag is 1 --> odd*/
{
	int i, result=0;
	if(flag==0)  					
	{
		for(i=2; i<=n; i+=2)
		{
		   	if(n-i==1 || n==i)			/*In this if block, check the digit is last or not. If is last number then don't write the '+' anymore */
			printf("%d = ", i);
			else
			printf("%d + ",i);
			
			result+=i;			//find the result
		}
		
		
		
		
	}
	
	else if(flag==1) 		
	{
		for(i=1; i<=n; i+=2)
		{
			if(n-i==1 || n==i)
			printf("%d = ", i);
			else
			printf("%d + ",i);
			
			result+=i;			//find the result
		}
			
	}
			
	return result;
	
}

int mult (int n, int flag)
{
	int i, result=1;
	
	if(flag==0)
	{
		for(i=2; i<=n; i+=2)
		{
			if(n-i==1 || n==i)				/*In this if block, check the digit is last or not. If is last number then don't write the '+' anymore */
			printf("%d = ", i);
			else
			printf("%d * ",i);
			
			result*=i;			//find the result
		}	
	}
	
	
	else 
	{
		for(i=1; i<=n; i+=2)
		{
			if(n-i==1 || n==i)
			printf("%d = ", i);
			else
			printf("%d * ",i);
			
			result*=i;			//find the result
		}
	}
	
	
	return result;
}













