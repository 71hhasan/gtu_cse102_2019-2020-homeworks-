/*haci hasan savan 1901042704*/
#include<stdio.h>		
#include<time.h>		
#include<math.h>
#include<stdlib.h>
/*checking loops with true-false flags*/
#define TRUE 1
#define FALSE 0

void menu();	
/*part1*/
void decrypt_and_print (char * file_path);	
char decrypt_numbers (int number);
/*part2*/
void deep_decrypt_and_print (char* file_path);
char decrypt_numbers(int number);
/*part3*/
void track_machine();	
void refresh_position (int *X, int *Y, double *D, double *R); 
/*part4*/
void encrypt_messages (char* message);
int encrypting(char number);

int main()
{
	menu();
	srand(time(NULL));
return 0;	
}

void menu(){
	int selectOption, checkLoops=TRUE;     

	while(checkLoops==TRUE)
	{
		/*loop for only taking the selection*/
		while(checkLoops==TRUE)
		{
			checkLoops=FALSE;
			
			printf("\n");
			printf("1) Decrypt and print encrypted_p1.img\n");	
			printf("2) Decrypt and print encrypted_p2.img\n");
			printf("3) Switch on the Tracking Machine\n");
			printf("4) Encrypt the message\n");
			printf("5) Switch off\n");
			printf("\n please make your choice: \n");
			scanf("%d", &selectOption);

		}
			checkLoops=TRUE;
			switch(selectOption)
			{
				case 1:	
					decrypt_and_print ("encrypted_p1.img");
					break;
				case 2: 
					deep_decrypt_and_print ("encrypted_p2.img");
					break;
				case 3:
					system("clear"); 
					track_machine ();
					break;									
				case 4: 
					encrypt_messages ("decrypted_p4.img");
					break;
				case 5: 
					printf("switched off\n");
					checkLoops=FALSE;
					break;					
				default:
					printf("invalid choice! Try again...\n");
					checkLoops=TRUE;
					break;
								
			}
		
		}	
	
	}
	
	/* part1 */
void decrypt_and_print (char *file_path)	
{
	FILE *filePointer;
	char charNumber;
	int intNumber;
	
	if((filePointer=fopen(file_path,"r"))==NULL)
	{
		printf("reading error!!!\n");
		exit(0);
	}

	while(!feof(filePointer))
	{
		fscanf(filePointer,"%c",&charNumber);
		/*changing the char to int*/
		intNumber=charNumber - '0';
		
		if(charNumber!='\n')
			printf("%c",decrypt_numbers(intNumber));
		else
			printf("\n");
			
	}	
}

char decrypt_numbers(int input)
{
	char returnValue;
	switch(input)
	{
		case 0:								
			returnValue=' ';
			break;
		case 1:
			returnValue='-';
			break;
		case 2:
			returnValue='_';
			break;
		case 3:
			returnValue='|';
			break;
		case 4:
			returnValue='/';
			break;
		case 5:
			returnValue='\\';
			break;
		case 6:
			returnValue='O';
			break;
	}	
	return returnValue;
}
	/* part2*/
void deep_decrypt_and_print (char* file_path)
{
	FILE *readingFile;
	char num1, num2, num3;
	int sum=0, remainder;
	
	if((readingFile=fopen(file_path,"r"))==NULL)
	{
		printf("reading error!!!\n");
		exit(0);
	}
	/*firstly take first two pieces*/
	fscanf(readingFile, "%c", &num1);
	fscanf(readingFile, "%c", &num2);
	
	while(!feof(readingFile))
	{
		fscanf(readingFile,"%c",&num3);
		if(num3!='\n')	
		{	/*changing the char numbers to int and summation*/
			sum=(num1 - '0')+(num2 - '0')+(num3 - '0');
			remainder=sum%7;
	
			printf("%c",decrypt_numbers(remainder));
			num1=num2;
			num2=num3;
		}	
		else
		{	/*if num3== '\n' */
			num3='0';						
			sum=(num1 - '0')+(num2 - '0')+(num3 - '0');
			remainder=sum%7;
			printf("%c",decrypt_numbers(remainder));
			
			printf("\n");
			
			fscanf(readingFile,"%c",&num1);
			fscanf(readingFile,"%c",&num2);
		}
	}	
    fclose(readingFile);
}

	/* part3 -track machine- */
void track_machine ()
{/*coordinateX: X - coordinateY: Y - distanceToEnemy: D - displacementEnemy: R*/									
	int coordinateX=0, coordinateY=0;	/*initial values are zero*/
	double distanceToEnemy;
	double displacementEnemy=0.0;			// our position (6,6)
	int x, y, checkLoops=TRUE, checkLoops2=TRUE;
	char command;			//E: exit - R: refresh	
	
	distanceToEnemy=6.0*sqrt(2); 	/*initial distance*/

	while(checkLoops==TRUE)
	{
		checkLoops2=TRUE;
		
		for(x=1; x<=11; x++)	//line
		{
			for(y=1; y<=11; y++) //column
			{
				if(x==6 && y==6)
					printf("O");
				else if(x==coordinateX && y==coordinateY)
					printf("E");
				else
					printf(".");
				
				printf("\t");	
			}
			printf("\n");
		}
		
		printf("Enemy X position:  %d, ", coordinateX);
		printf("Y poistion: %d,  ", coordinateY);
		printf("Displacement: %lf,  ", displacementEnemy);
		printf("Distance to our camp: %lf\n", distanceToEnemy);
		printf("press 'R' to refresh - press 'E' to exit\n");
		
		
		while(checkLoops2==TRUE)
		{		
			printf("Command waiting... ");
			scanf(" %c", &command);

			 if(command=='E' || command=='e')
			{
				checkLoops=FALSE;	//Exit
				checkLoops2=FALSE;	
			}		
			else if(command=='R' || command=='r')	
			{
				system("clear"); 
				refresh_position(&coordinateX, &coordinateY, &distanceToEnemy, &displacementEnemy);
			
			//the enemy connot be present at our position
				if(coordinateX==6 && coordinateY==6)
					refresh_position(&coordinateX, &coordinateY, &distanceToEnemy, &displacementEnemy);
				
				checkLoops2=FALSE;
				
			}
			else 
				printf("\ninvalid command!!!\n");
			
		}

	}
}

/*coordinateX: X - coordinateY: Y - distanceToEnemy: D - displacementEnemy: R*/		
void refresh_position (int *X, int *Y, double *D, double *R)
{
	int oldX, oldY;

	oldX=*X;
	oldY=*Y;
	
	*X=rand()%11+1;
	*Y=rand()%11+1;
	
	*D=sqrt(pow(*X-6,2) + pow(*Y-6,2));
	*R=sqrt(pow(*X-oldX,2) + pow(*Y-oldY,2));	
}
	
	/* part4 */
void encrypt_messages (char* message)
{
	FILE *readingMessage,*savingFile;
	char piece1, piece2, piece3;
	int writingNumber, line=0;
	
	
	if((readingMessage=fopen(message, "r"))==NULL)
	{
		printf("reading error!!\n");
		exit(0); 	
	}
		if((savingFile=fopen("encrypted_p4.img", "w"))==NULL)
	{
		printf("saving error!!\n");
		exit(0);
	}
	/*function reads 3 pieces at a time*/
	fscanf(readingMessage,"%c",&piece1);
	fscanf(readingMessage,"%c",&piece2);

	while(!feof(readingMessage))
	{
		fscanf(readingMessage,"%c",&piece3);
		if(piece3!='\n')
		{	/*implementing the formula*/
			writingNumber=encrypting(piece1)+encrypting(piece2)+encrypting(piece3);
			writingNumber%=7;
			
			piece1=piece2;
			piece2=piece3;	
			fprintf(savingFile,"%d",writingNumber);					
		}
		else 
		{
			piece3=' ';
			writingNumber=encrypting(piece1)+encrypting(piece2)+encrypting(piece3);
			writingNumber%=7;
			line++;
			fprintf(savingFile,"%d",writingNumber);
			if(line==5)
			{
				fprintf(savingFile,"\n");
				fprintf(savingFile,"\n");
				fprintf(savingFile,"\n");
				fprintf(savingFile,"\n");
			}
			else
				fprintf(savingFile,"\n");
			
			fscanf(readingMessage,"%c",&piece1);
			fscanf(readingMessage,"%c",&piece2);
		}
	}
	
	printf("\n the message enrypted to the encrypted_part4.img file!!!\n");
	fclose(readingMessage);
	fclose(savingFile);
}
int encrypting(char number)
{
	int r_value;
	switch(number)
	{
		case ' ':								
			r_value=0;
			break;
		case '-':
			r_value=1;
			break;
		case '_':
			r_value=2;
			break;
		case '|':
			r_value=3;
			break;
		case '/':
			r_value=4;
			break;
		case '\\':
			r_value=5;
			break;
	}	
	return r_value;
}	
