#include<stdio.h>
#include<math.h>

#define TEuro 6.69			// TEuro:    Euro -> Turkish Lira
#define TDollar 6.14			// TDollar:  Dollar -> Turkish Lira
#define DEuro 1.09			// DEuro:    Euro -> Dollar  ( 1 Euro = 1.09 Dollar)

int main()
{
	float amount;
	int selection1, selection2;
	
	printf("***** Welcome to ABC Exchange Office *****\n\n");
	
	printf("Enter your amount: \n");
	scanf("%f", &amount);
	
	printf("\n\nplease select your currency\n\a");			//first selection represents my money
	printf("1. Turkish Lira\n");					
	printf("2. Euro\n");
	printf("3. Dollar\n");
	
	printf("-------------------\n\n");
	
	scanf("%d", &selection1);
	
	switch(selection1)
	{
		case 1:
			printf("you have %f Turkish Liras\n\n", amount);
			break;
		
		case 2: 
			printf("you have %f Euro\n\n", amount);
			break;
			
		case 3:
			printf("you have %f Dollar\n\n", amount);
			break;
		
		default:
			printf("Your selection is invalid\n\n");
			return 0;
	}
	
	printf("-------------------------------\n");
	
	printf("choose which currency you want to convert\n\a");		//second selection represents which currency you want to convert
	scanf("%d", &selection2);
	
	printf("-------------------------------\n");
	
	
		if(selection1==1)
		{
				switch(selection2)
			{
				case 1: 
					printf("you have %f Turkish Liras\n", amount);
					break;
				
				case 2:
					printf("you have %f Euro\n", amount/TEuro);
					break;
				
				case 3:
					printf("you have %f Dollar\n", amount/TDollar);
					break;
				
				default:
					printf("Your selection is invalid\n");
			}
		}
		
		
		else if(selection1==2) 
		{
				switch(selection2)
			{
				case 1: 
					printf("you have %f Turkish Liras\n", amount*TEuro);
					break;
				
				case 2:
					printf("you have %f Euro\n", amount);
					break;
				
				case 3:
					printf("you have %f Dollar\n", amount*DEuro);
					break;
				
				default:
					printf("Your selection is invalid\n");
			}
		}
		
		else if(selection1==3)
		{
				switch(selection2)
			{
				case 1: 
					printf("you have %f Turkish Liras\n", amount*TDollar);
					break;
				
				case 2:
					printf("you have %f Euro\n", amount/DEuro);
					break;
				
				case 3:
					printf("you have %f Dollar\n", amount);
					break;
				
				default:
					printf("Your selection is invalid\n");
					
			}
		}

}
