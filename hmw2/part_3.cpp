#include<stdio.h>
#include<math.h>

#define TEuro 6.69		
#define TDollar 6.14
#define DEuro 1.09			// 1 Euro = 1.09 Dollar

int main()
{
	float amount;
	int selection1, selection2;
	
	printf("***** Welcome to ABC Exchange Office *****\n\n");
	
	printf("Enter your amount: \n");
	scanf("%f", &amount);
	
	printf("please select your currency\n\a");
	printf("1. Turkish Lira\n");
	printf("2. Euro\n");
	printf("3. Dollar\n");
	
	printf("-------------------------------\n");
	
	scanf("%d", &selection1);
	
	switch(selection1)
	{
		case 1:
			printf("you have %f Turkish Liras\n", amount);
			break;
		
		case 2: 
			printf("you have %f Euro\n", amount);
			break;
			
		case 3:
			printf("you have %f Dollar\n", amount);
			break;
		
		default:
			printf("Your selection is invalid");
			return 0;
	}
	
	printf("-------------------------------\n");
	
	printf("choose which currency you want to convert\n\a");
	scanf("%d", &selection2);
	
	printf("-------------------------------\n");
	
	
		if(selection1==1)
		{
				switch(selection2)
			{
				case 1: 
					printf("you have %f Turkish Liras", amount);
					break;
				
				case 2:
					printf("you have %f Euro", amount/TEuro);
					break;
				
				case 3:
					printf("you have %f Dollar", amount/TDollar);
					break;
				
				default:
					printf("Your selection is invalid");
			}
		}
		
		
		else if(selection1==2) 
		{
				switch(selection2)
			{
				case 1: 
					printf("you have %f Turkish Liras", amount*TEuro);
					break;
				
				case 2:
					printf("you have %f Euro", amount);
					break;
				
				case 3:
					printf("you have %f Dollar", amount/DEuro);
					break;
				
				default:
					printf("Your selection is invalid");
			}
		}
		
		else if(selection1==3)
		{
				switch(selection2)
			{
				case 1: 
					printf("you have %f Turkish Liras", amount*TDollar);
					break;
				
				case 2:
					printf("you have %f Euro", amount*DEuro);
					break;
				
				case 3:
					printf("you have %f Dollar", amount);
					break;
				
				default:
					printf("Your selection is invalid");
					
			}
		}

}
