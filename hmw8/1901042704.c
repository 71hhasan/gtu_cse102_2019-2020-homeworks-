#include <stdio.h>								/*haci hasan savan 1901042704*/
#include <math.h>

#define TRUE 1
#define FALSE 0
#define N 500
//prototypes
void generate_hofstadters_sequence (int *arr, int n);
int find_max (int arr[], int index, int max_value);
int sum_array (int arr[]);
double std_array (int arr[], double *mean, int n, int index);		
char *remove_duplicates(char *str);
void FillArrWithZero(int arr[]);

double sum=0;

int main(void) 
{
	int checkLoops=TRUE,selection,choice, arr[N],n,i,max=0, index=1;
	char remoDup[N];
	double mean=0;
	FillArrWithZero(arr);

	while(checkLoops==TRUE)
	{	
		printf("\n\n");	
		printf("Welcome to Homework 8, please choose one of the parts to continue\n");	//menu
		printf("-----------------------------\n");
		printf("1) Execute Part 1\n2) Execute Part 2\n3) Execute Part 3\n4) Exit\n");
		scanf("%d",&selection);

		switch(selection)
		{
			case 1:
				while(checkLoops==TRUE)	//menu for part1
				{
					printf("\n###########################################\n");
					printf("Please make your choice:\n");
					printf("-------------------------\n");
					printf("1) Fill Array\n2) Find Biggest Number\n3) Calculate Sum\n");
					printf("4) Calculate Standart Deviation\n5) Exit\n");
					scanf("%d",&choice);
					if(choice==1)
					{
						printf("please enter a number: ");
						scanf("%d",&n);
						generate_hofstadters_sequence (arr, n);
						for(i=1; i<n+1; i++)
							printf("%d\n",arr[i]);
					}
					else if(choice==2)
						printf("max number is %d\n",find_max(arr,index,max));	
					else if(choice==3)
					{
						printf("sum: %d\n",sum_array(arr));
						FillArrWithZero(arr);
						generate_hofstadters_sequence(arr, n);
					}
					else if(choice==4)
					{
						printf("standart deviation: %lf\n",std_array(arr, &mean, n,index));
						printf("mean: %lf\n", mean );
					}
					else if(choice==5)
						checkLoops=FALSE;	//if choice=5 ,exit from this loop
					else					//else checkLoops is still TRUE for this reason continue in here 
						printf("invalid option!! try again\n");
				}
				checkLoops=TRUE;
				break;

			case 2:
				printf("sorry, I couldn't hocam ;[ \n");
				break;

			case 3:
				printf("please enter your word or sentence and press enter(max N character)\n");
			    scanf(" %[^\n]s",remoDup);
  				printf("%s\n",remove_duplicates(remoDup));
				break;

			case 4:
				checkLoops=FALSE;
				break;
			default:
				printf("invalid option!! try again\n");
		}

	}

	return 0;
}

void generate_hofstadters_sequence (int *arr, int n)
{
	if(n>2)
	{
		generate_hofstadters_sequence(arr,n-1);
		arr[n]=arr[n-arr[n-1]] + arr[n-arr[n-2]];
	}
	else	//if n is 1 or 2, this means that arr[1] and arr[2] are eaqual 1 (from hofstadters sequence)
	{
		arr[1]=1;
		arr[2]=1;
	}
}

int find_max (int arr[], int index, int max_value)
{
	if(index>=N)			//the function works for all element of array
 		return max_value;
	if(max_value<arr[index])
		max_value=arr[index];

	find_max (arr, index+1, max_value);
}

int sum_array (int arr[])	
{
	int *p;
	p=arr;

	if(p[1]!=0)	//the values are starting from 1. index not 0.
	{
		p[1]=p[0]+p[1];
		p++;
		sum_array(p);	//send the pointer which corresponds the next element, to sum_array function again
	}
	else
		return p[0];	
}


double std_array (int arr[], double *mean, int n, int index)        
{
    double SD, temp;
    if(index==1){ 
        *mean=(double)(sum_array(arr))/n;
        FillArrWithZero(arr);						//these two function was called to fill array again with same numbers 
		generate_hofstadters_sequence(arr, n);
    }     

    if(arr[index]!=0)		//apllying the standart deviation equation
    {
        temp=arr[index]-*mean;
        sum+=(pow(temp,2));
        std_array (arr,mean,n,index+1); 
    }
   else
    {
        SD=sqrt(sum/(n-1));
        return SD;
    }  
}
void FillArrWithZero(int arr[])
{
	int i;
	for(i=0; i<N; i++)
		arr[i]=0;
}

char *remove_duplicates(char *str) 
{
	int i=0;
	static char arr[N];

	if(str[0]=='\0')	//whis means that end of sentence was reached
		return str;
	if(str[0]==str[1])	//if two consecutive char are equal then start shifting 
	{
		while(str[i]!='\0')
		{
			str[i]=str[i+1];
			i++;
		}
		remove_duplicates(str);
	}
	else if(str[0]!=str[1])
		remove_duplicates(str+1);
	

	return str;
}
