#include<stdio.h>
#include<math.h>
					//NOTE!!!! PLEASE EXECUTE THE PROGRAM WITH "-lm" PARAMETER IN GCC 


void find_root();					
void find_newtonian_root();				
int find_multiple_closest(int , int );			

float newton_operation(float, int, int, int);				//newton_operation is x(i+1) = x(i) - f(x)/f'(x)
float fx_function(int, int, int, float);			       // this gives the only f(x) value for showing the f(x) values in table (in finf_newtonian_root)

int main()
{	
	int big_number, small_number;	
	
	printf("---------------part1------------------\n");	
	find_root();
	
	printf("\n---------------part2------------------\n");
	find_newtonian_root();

	printf("\n---------------part3------------------\n");

	
	printf("please enter the first integer: ");
	scanf("%d", &big_number);
		
	printf("\nplease enter the second integer which is smaller: ");		
	scanf("%d", &small_number);	
			
	
	find_multiple_closest(big_number, small_number);


	return 0;
}







void find_root() 		
{

	int coeff_1, coeff_2, coeff_3;
	float  delta, root_1, root_2;
	
	printf("please give the coefficients...\n");
	scanf("%d%d%d",&coeff_1, &coeff_2, &coeff_3);
	

	
	if(coeff_2<0 && coeff_3<0 && coeff_1==1)					//these if blocks are for a better typing the equation
	{
		printf("function is:  x^2 %dx %d \n", coeff_2, coeff_3);
	}	
	
	else if(coeff_2<0 && coeff_3>0 && coeff_1==1)
	{
		printf("function is:  x^2 %dx + %d \n", coeff_2, coeff_3);
	}

	else if(coeff_3<0 && coeff_2>0 && coeff_1==1)
	{
		printf("function is:  x^2 + %dx %d \n", coeff_2, coeff_3);
	}
	
	else if(coeff_3<0 && coeff_2>0 && coeff_1==-1)
	{
		printf("function is:  -x^2 + %dx %d \n", coeff_2, coeff_3);
	}
	
	else if(coeff_2<0 && coeff_3>0 && coeff_1==-1)
	{
		printf("function is:  -x^2 %dx + %d \n", coeff_2, coeff_3);
	}
	
	else if(coeff_2<0 && coeff_3<0 && coeff_1==-1)					//these if blocks are for a better typing the equation
	{
		printf("function is:  -x^2 %dx %d \n", coeff_2, coeff_3);
	}

	else
	{
		printf("function is:  %dx^2 + %dx + %d \n", coeff_1, coeff_2, coeff_3);
	}
	


	
	
	delta = pow(coeff_2,2)- 4*coeff_1*coeff_3;

	
	if(delta< 0.0)
	{
		printf("Your equation does not have any real roots.\n");
	
	}
	
	root_1= (-coeff_2+sqrt(delta))/(2*coeff_1);		// x1,2= (-b +- (squere root delta))/(2a)
	root_2= (-coeff_2-sqrt(delta))/(2*coeff_1);
	
	if(root_1>root_2)					//ordering the roots from big to small
	{printf("%f, %f \n", root_1, root_2);}
	else if(root_2>root_1)
	{printf("%f, %f \n", root_2, root_1);}
	else
	{printf("%f\n", root_1);}	


}


void find_newtonian_root()
{
	int coeff_1, coeff_2, coeff_3, initial;
	float  x1, x2, x3, x4, x5;
	
	
	printf("please give the coefficients...\n");
	scanf("%d%d%d",&coeff_1, &coeff_2, &coeff_3);
	
	printf("please enter a initial: \n");
	scanf("%d", &initial);

	printf("your equation is:  %dx^2 + %dx + %d \n\n", coeff_1, coeff_2, coeff_3);

	x1= newton_operation(initial,coeff_1,coeff_2,coeff_3);
	x2= newton_operation(x1,coeff_1,coeff_2,coeff_3);
	x3= newton_operation(x2,coeff_1,coeff_2,coeff_3);
	x4= newton_operation(x3,coeff_1,coeff_2,coeff_3);
	x5= newton_operation(x4,coeff_1,coeff_2,coeff_3);
	

	printf("step\t");						//table
	printf("x\t\t");
	printf("f(x)\t\t");
	printf("Difference\n\n");

	printf(" x1\t");
	printf("%f\t", x1);
	printf("%f\t", fx_function(coeff_1, coeff_2, coeff_3, x1));			//taking the f(x) values for each step
	printf("%f\n", x1-x5);	

	printf(" x2\t");
	printf("%f\t", x2);
	printf("%f\t", fx_function(coeff_1, coeff_2, coeff_3, x2));
	printf("%f\n", x2-x5);
	
	printf(" x3\t");
	printf("%f\t", x3);
	printf("%f\t", fx_function(coeff_1, coeff_2, coeff_3, x3));
	printf("%f\n", x3-x5);	

	printf(" x4\t");
	printf("%f\t", x4);
	printf("%f\t", fx_function(coeff_1, coeff_2, coeff_3, x4));	
	printf("%f\n", x4-x5);	

	printf(" x5\t");
	printf("%f\t", x5);
	printf("%f\t", fx_function(coeff_1, coeff_2, coeff_3, x5));	
	printf("%f\n", x5-x5);


}

float newton_operation( float xi, int coeff_1, int coeff_2, int coeff_3)
{
	float output;
	output= xi - (pow(xi,2)*coeff_1 + coeff_2 * xi + coeff_3)/(xi*2+ coeff_2);		//newton_operation. x(i+1) = x(i) - f(x)/f'(x)

	return output;

}


float fx_function(int coeff_1, int coeff_2, int coeff_3, float xi)
{
	float fx_value;	

	fx_value= (pow(xi,2)*coeff_1 + coeff_2 * xi + coeff_3);

	return fx_value;
}




int find_multiple_closest(int big_num, int small_num)
{
	int closest, remainder;  
	
	if(big_num % small_num==0)
	{
		printf("Closest number to %d that is multiple of %d is itself. ", big_num, small_num);	
	}

	else
	{	
		remainder=big_num %small_num;
				
		if(remainder>small_num/2)			//if the remainder is bigger than the small_num/2 then the closest number is bigger than our bigger_number
		{	
			closest=big_num + (small_num-remainder);
			printf("\nclosest number to %d that is multiple of %d is %d\n", big_num, small_num, closest);

		}
	
		else if(remainder<small_num/2)			//if the remainder is smaller than small_num/2 then closest number must be smaller than our small_number 
		{
			closest= big_num - remainder;
			printf("\nclosest number to %d that is multiple of %d is %d\n", big_num, small_num, closest);

		}

		else						//if they are equal. doesn't matter. find the bigger one as closest number
		{
			closest= big_num + remainder;
			printf("\nclosest number to %d that is multiple of %d is %d\n", big_num, small_num, closest);
		}		
							
	}
}


