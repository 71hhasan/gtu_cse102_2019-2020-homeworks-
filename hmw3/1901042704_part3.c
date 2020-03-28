#include<stdio.h>				/*hacı hasan savan - 1901042704 - hmw3_part3*/

#define TRUE 1				/*definings are for controlling the loops*/
#define FALSE 0

int powr(int, int);
int andOp(int, int);
int getLength(int);			
int isBinary(int);


int main()
{
	int check=TRUE, userInput1, userInput2,length_1, length_2;
	
	while(check==TRUE)					
	{
		check=FALSE;	

		printf("first integer: ");
		scanf("%d", &userInput1);
		printf("second integer: ");
		scanf("%d", &userInput2);
		
		length_1=getLength(userInput1);							/*getLength function will control the inputs one by one */
		length_2= getLength(userInput2);				
		
		
		if(length_1==length_2)						
		{															
			if(isBinary(userInput1)==0 || isBinary(userInput2)==0)			/*it checks if the numbers are only zero and oone or not*/
			{
				check=TRUE;
				printf("integers should be binary, please enter 2 new integers\n");
			}
			else
				printf("%d AND %d = %d\n", userInput1, userInput2, andOp(userInput1, userInput2));				/*andOp part*/				
		}
		else
		{	
			printf("integers should have the same length, please enter 2 new integers.\n");
			check=TRUE;
		}
	
	}
return 0;
}


int andOp(int input1, int input2)
{
	int endingZeros=0, encounteredOne=FALSE, tempInput1, tempInput2, digitValue, return_value=0;

												
	while(input1>0)										/*endingZeros: zeros in last part of the userInput*/
	{											/*encounteredOne: do we have encountered with one in userInput? FALSE is no, TRUE is yes */
		tempInput1= input1%10;							
		tempInput2= input2%10;
		
		digitValue= tempInput1*tempInput2;
		
		if(digitValue==0 && encounteredOne==FALSE)				/*if we have not encountered with '1' then endingzeros++; so that we can multiply the return_value by endingzeros*/
			endingZeros++;							/*briefly this mechanism controls the zeros in last digits*/
		else if(digitValue==1)
			encounteredOne = TRUE;
		
		return_value*=10;
		return_value+=digitValue;
	
		input1/=10;
		input2/=10;
	}

	return return_value*powr(10,endingZeros);
}
								/*In the homework, the all fuctions (except andOp) take only one input. In this way, codes will be more readable, applicable and flexible*/
int powr(int alt, int us)			
{	int r_value=1;						/*powr function applies the matematichal power operation*/
	while(us>0)
	{
		r_value*=alt;
		us--;
	}	
	return r_value;
}

int getLength(int input)					/* getting only one input. In this way, the function will be more readable, applicable and flexible*/			
{
	int length=1;
	
	while(input>1)
	{
		length++;
		input=input/10;
	}
	
	return length;
}


int isBinary(int num)						/*getting only one input. In this way, the function will be more readable, applicable and flexible*/
{			
	int localCounter, r_value=1;
	localCounter=getLength(num);							

	while(localCounter>0 && r_value==1)								
	{											
		if(num%10!=1 && num%10!=0)
			r_value=0;
		
		num=num/10;
		localCounter--;
	}
								/*If r_value is '1' the input is binary*/
	return r_value;						/*If r_value is '0' the input is not binary*/
}





