#include<stdio.h>	
#include<math.h>

int number_length(int );
int find_digit(int , int);

int main()

{
	int num, which_digit, length;

	printf("please enter a number (maximimum 6 digits): \n");

	scanf("%d", &num);


	length=	number_length(num);
	
	if(length<=6)
	{
		printf("\nyour number has %d digits\n", length);


		printf("\nwhen your number is written 100 times next to each other, which digit of this number would you like to see? : ");	
		scanf("%d", &which_digit);

		
		printf("\n%d. digit of the big number sequence: %d\n", which_digit, find_digit(num, which_digit));
	}
	
	else
	{
		printf("please enter a number smaller or equal than 6 !!\n");
	}

	return 0;
}


int number_length(int number)

{
	int digit_number;


	digit_number = log10(number)+1;				//used log10 to find how many digit there are


	return digit_number;
}



int find_digit(int number, int index)				//example: index=which number you want to see (561) - number= number you entered (123456) 

{							

	int length, kalan, result;

	length=	number_length(number);

	kalan = index%length;
	
	if(kalan==0)					//if the kalan is equal 0 the result will be the last digit for this reason 
	{						// we don't have to do the operations which are inside else
		result= number%10;
	}

	else 
	{
		result= number/pow(10,(length-kalan));
		result=result%10;
	}
	
	

	return result;

}
