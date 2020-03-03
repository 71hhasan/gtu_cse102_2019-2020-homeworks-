#include<stdio.h>	
#include<math.h>

int number_length(int );

int find_digit(int number, int index);



int main()

{

	int num, which_digit, length;



	printf("please enter a number (maximimum 6 digits): \n");

	scanf("%d", &num);

		

	length=	number_length(num)+1;

	printf("your number has %d digits\n", length);



	printf("when your number is written 100 times next to each other, which digit of this number would you like to see? : ");	

	scanf("%d", &which_digit);

	printf("%d. digit of the big number sequence: %d", which_digit, find_digit(num, which_digit));


	return 0;

}



int number_length(int number)

{

 	int digit_number;

	

	digit_number = log10(number);



	return digit_number;

}



int find_digit(int number, int index)

{	//index=561 number=123456 girilen sayý

	

	int length, kalan, result;

	length=	number_length(number)+1;

	kalan = index%length;
	
	result= number/pow(10,(length-kalan));
	result=result%10;


	return result;



}
