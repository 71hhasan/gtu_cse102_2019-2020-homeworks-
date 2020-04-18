#include<stdio.h>			/*haci hasan savan 1901042704*/	
#include<locale.h>
#include<stdlib.h>

#define TRUE 1	//checkLoops flags
#define FALSE 0

#define wholeNews 0	//for checking the displaying of news
#define onlyTitle 1

void menu();
void read_news(char buffer[500], char file_path[10], int is_Only_Title);
void clearBuffer(char x[500]);
void append_file(char *file_path, char c); 		
int wasReadedBefore(char *file_path, char whichNews); /*file_path: readed_news_id.txt*/
void readAppendFile(char *file_path);
void read_magic_numbers(char buffer_magic[10], char bufferNews[500]); //for reading the magic numbers
double f_func(int x); //for calculating the f(x);
double g_func(int x); //for calculating the g(f(x))


int main()
{
	menu();
}

void menu()
{
	char choice,bufferNews[500],bufferMagic[10],*file_path,choice2;		
	int whichText, newsNumber, checkLoops=TRUE;

	file_path="readed_news_id.txt";

	printf("***Daily Press***\n\n");
	printf("Today's news are listed for you: \n");
			
		printf("Title of 1. news: ");
		read_news(bufferNews, "news/1.txt", onlyTitle);		/*reads only titles*/
		printf("\nTitle of 2. news: ");
		read_news(bufferNews, "news/2.txt", onlyTitle);
		printf("\nTitle of 3. news: ");
		read_news(bufferNews, "news/3.txt", onlyTitle);
		printf("\nTitle of 4. news: ");
		read_news(bufferNews, "news/4.txt", onlyTitle);
				
	while(checkLoops==TRUE)
	{
		printf("\n");
		printf("what do you want to do?\na.Read a new\nb.List the readed news\nc.Get decrypted information from the news\n");			
		scanf( " %c",&choice );

		if(choice=='a'|| choice=='A')
		{	
			printf("which text do you want to read? \n");
			scanf("%d",&whichText);
			switch(whichText)
			{
				case 1:
					if(wasReadedBefore(file_path, '1')==FALSE)	//if wasn't readed before
					{
						read_news(bufferNews,"news/1.txt",wholeNews);	
						puts(bufferNews);
						append_file(file_path, '1');		
						break;			
					}
					else 
					{	
						printf("this new is readed. Do you want to read again? Yes(y)/No(n): \n");
						scanf(" %c",&choice2);

						if(choice2=='y' || choice2=='Y'){
							read_news(bufferNews,"news/1.txt",wholeNews);
							puts(bufferNews);	
						}
						else
						{
							checkLoops=FALSE;
							printf("\nexiting....\n");
						}
					}	
					break;
				case 2:	
					if(wasReadedBefore(file_path, '2')==FALSE)
					{	
						read_news(bufferNews,"news/2.txt",wholeNews);
						puts(bufferNews);	
						append_file(file_path, '2');				
						break;
					}
					else 
					{	
						printf("this new is readed. Do you want to read again? Yes(y)/No(n): \n");
						scanf(" %c",&choice2);

						if(choice2=='y'|| choice2=='Y'){
							read_news(bufferNews,"news/2.txt",wholeNews);	
							puts(bufferNews);
						}
						else
						{
							checkLoops=FALSE;
							printf("\nexiting....\n");
						}
					}	
					break;
				case 3:	
					if(wasReadedBefore(file_path, '3')==FALSE)
					{	
						read_news(bufferNews,"news/3.txt",wholeNews);	
						puts(bufferNews);
						append_file(file_path, '3');					
						break;
					}
					else 
					{	
						printf("this new is readed. Do you want to read again? Yes(y)/No(n): \n");
						scanf(" %c",&choice2);

						if(choice2=='y'|| choice2=='Y'){
							read_news(bufferNews,"news/3.txt",wholeNews);	
							puts(bufferNews);
						}
						else
						{
							checkLoops=FALSE;
							printf("\nexiting....\n");
						}
					}	
					break;
				case 4:	
					if(wasReadedBefore(file_path, '4')==FALSE)
					{	
						read_news(bufferNews,"news/4.txt",wholeNews);
						puts(bufferNews);	
						append_file(file_path, '4');				
						break;
					}
					else 
					{	
						printf("this new is readed. Do you want to read again? Yes(y)/No(n): \n");
						scanf(" %c",&choice2);

						if(choice2=='y'|| choice2=='Y'){
							read_news(bufferNews,"news/4.txt",wholeNews);	
							puts(bufferNews);
						}
						else
						{
							checkLoops=FALSE;
							printf("\nexiting....\n");
						}
					}	
					break;
				default:
					printf("there is no news like that! please try again\n");
					break;		
			}
		}

		else if(choice=='b'|| choice2=='B')
		{
			//this function reads the append file and checks if was readed or not and prints it
			//this operatin is carried out in a different function so that becomes more functional
			readAppendFile(file_path); 
			printf("do you want to contiune? Yes(y)/No(n): ");
			scanf(" %c", &choice2);
			
			if(choice2=='n'|| choice2=='N')
			{
				checkLoops=FALSE;
				printf("\nexiting....\n");
			}	
		}
		
		else if(choice=='c' || choice2=='C')
		{
			printf("which news would you like to decrypt?: ");
			scanf("%d",&newsNumber);
			switch(newsNumber)
			{
				case 1:
					read_news(bufferNews,"news/1.txt",wholeNews);
					puts(bufferNews);
					printf("\nthe number of tests performed is ");
					break;
				case 2:
					read_news(bufferNews,"news/2.txt",wholeNews);
					puts(bufferNews);
					printf("\nthe number of sick people is ");
					break;
				case 3:
					read_news(bufferNews,"news/3.txt",wholeNews);
					puts(bufferNews);
					printf("\nthe number of deaths is ");
					break;
				case 4:
					read_news(bufferNews,"news/4.txt",wholeNews);	
					puts(bufferNews);
					printf("\nthe expected number of sick people is ");
					break;
			}
			read_magic_numbers(bufferMagic,bufferNews);
			
			printf("do you want to contiune? Yes(y)/No(n): ");
			scanf(" %c",&choice2);
			
			if(choice2=='n'|| choice2=='N')
			{
				checkLoops=FALSE;	//exit from loop
				printf("\nexiting....\n");
			}
		}
		
		else
			printf("invalid option!! please try again!!!\n");
		
	}
}

void read_news(char buffer[500], char file_path[10], int is_Only_Title)
{	
	FILE *filePointer;
	char ch; 
	int i=0;
	if((filePointer=fopen(file_path,"r"))==NULL)
	{
		perror("reading error at read_news function!! ");
		exit(EXIT_FAILURE);	
	}
	
	if(is_Only_Title==onlyTitle)
	{		
		while(!feof(filePointer))
		{	
			fscanf(filePointer,"%c",&ch);
			buffer[i]=ch;
			if(ch=='\n')
			{
				buffer[i]='\0';
				break;
			}
			i++;
		}
		puts(buffer);
	}
	
	else if(is_Only_Title==wholeNews)
	{
		while(!feof(filePointer))
		{	
			fscanf(filePointer,"%c",&ch);			
			buffer[i]=ch;
			buffer[i+1]='\0';
			i++;					
		}
		
	}
	fclose(filePointer);	
}
/*appendFile, adds previously read news to the file*/
void append_file(char *file_path, char c)		
{
	FILE *fp;
	char temp;
	if((fp=fopen(file_path,"a+"))==NULL)	
	{
		perror("error in append file ");
		exit(EXIT_FAILURE);
	}
	while(!feof(fp))
	{
		fscanf(fp,"%c",&temp);
		if(temp!=c)
		{
			fprintf(fp,"%c",c);
			fprintf(fp,"\n");
			break;
		}
	}
	fclose(fp);
}
/*checks if the selected news was readed bofore or not*/
int wasReadedBefore(char *file_path, char whichNews)	
{														
	FILE *fp; 
	char ch; 
	int returnValue=FALSE;                                                    
	if((fp=fopen(file_path,"r"))==NULL){
		perror("error!!");
		exit(EXIT_FAILURE);
	}	
	while(!feof(fp)){
		if(ch!='\n')
			fscanf(fp," %c",&ch);
		if(ch==whichNews)
			returnValue=TRUE; //if the returnValue is TRUE, this means that the selected news readed before	
	}
	fclose(fp);
	return returnValue;
}

//this function reads the append file and checks if was readed or not and prints it
//this operatin is carried out in a different function so that becomes more functional
void readAppendFile(char *file_path)			
{
	FILE *fp;
	char ch;
	if((fp=fopen(file_path,"r"))==NULL){
		perror("error!!");
		exit(EXIT_FAILURE);
	}	
	while(!feof(fp)){
		fscanf(fp,"%c",&ch);
		
		if(ch!='\n'){
			
			if(ch!='1' && ch!='2' && ch!='3' && ch!='4')
			{
				printf("there isn't any readed new\n");
				break;
			}
			printf("%c. new is readed\n", ch);
		}

	}
}
void read_magic_numbers(char buffer_magic[10], char bufferNews[500])
{
	int k=0,i=0,x;
	char ch;
	double result=0;

	while(bufferNews[i])
	{	
		if(bufferNews[i]=='#')
		{
			buffer_magic[k]=bufferNews[i+1];
			x=buffer_magic[k]-'0';
			result+=g_func(x);	
		}
								
		i++;
	}
	printf("%lf\n",result);
}

double g_func(int x)
{
	double returnValue;
	returnValue=f_func(x)*f_func(x);
	return returnValue;
}
double f_func(int x)
{
	double returnValue;
	returnValue=x*x*x-x*x+2;
	return returnValue;
}
