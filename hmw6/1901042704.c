#include<stdio.h>
#include<string.h>
#include <time.h>
#include <stdlib.h>
#define STOP 0
#define CONTINUE 1

#define lefttoRigth 1				
#define righttoLeft 2
#define toptoBottom 3
#define bottomtoTop 4
#define northtoEast 5
#define southtoEast 6
#define southtoWest 7
#define northtoWest 8

void randomWords(char tenWords[10][20]);
void placeWords(char map[22][22], char words[10][20], int whichWord, int direction);
char createRandLetter();
void fillMap(char map[22][22]);
int searchWordInMap(char map[22][22], char answer[], int row, int col);

int main()
{
	char tenWords[10][20];
	char map1[22][22];
	char answer[21];;
	int checkLoops=CONTINUE;
	srand(time(NULL));
	int i=0,k,whichDirection,colNum,row, counter=0;
	/*these areays for taking the answer*/
	char rowNum;

	/*fills the map with * character*/
	for(i=0; i<20; i++)			
		{
			for(k=0; k<20; k++)
			{
				 map1[i][k]='*';	
			}
		}

	//takes ten random words
	randomWords(tenWords); 

		printf("****** WORD HUNTER GAME ******\n");
		printf("please enter the coordinate and word without any space between them (like that: E5random): \n");
		printf("the game will end if you find all (10) words or type '*exit'\n");	//*exit is choosed because of that may be the word file have exit word already 	
		i=0;
		while(i<10)
		{
			//choose which direction randomly
			whichDirection=rand()%8+1;
			placeWords(map1, tenWords, i, whichDirection);		
			i++;
		}

		fillMap(map1);
		for(i=0; i<20; i++)			
			{
				printf("\t");				//prints the map only one time
				for(k=0; k<20; k++)
				{         
					printf("%c ", map1[i][k]);
				}
				printf("\n");
			}

		while(checkLoops==CONTINUE)
		{	
			printf("answer: \n");
			scanf(" %c",&rowNum);
			scanf(" %d",&colNum);
			
			row=(rowNum-0)%65;
			printf("\033[H\033[J"); //cleans the terminal

			/*write the map again*/
			printf("****** WORD HUNTER GAME ******\n");
			printf("#Please enter the coordinate and word WITHOUT ANY SPACE between them (like that: E5random): \n");
			printf("#The game will end if you find all (10) words or type '*exit'\n\n");
			for(i=0; i<20; i++)			
			{
				printf("\t");
				for(k=0; k<20; k++)
				{         
					printf("%c ", map1[i][k]);
				}
				printf("\n");
			}
			for(i=0; i<10; i++)			
			{
				printf("%s", tenWords[i]);
			}
			/*-----------------------*/
			if(searchWordInMap(map1,answer,row,colNum)==1)	 //if ==1 this means that the word in the map!!
			{	
				counter++;
				printf("%d words found\n",counter);				
			}
			printf("%s\n",answer);
			if((answer[0]=='e'&& answer[1]=='x'&& answer[2]=='i'&& answer[3]=='t')||counter==10)
			{
				checkLoops=STOP;	
			}						
		}

return 0;		
}	

/*takes a empty array and fills that with 10 random words*/
void randomWords(char tenWords[10][20])			
{
	int randNum,i;
	char wholeWords[101][20];
	FILE *fp=fopen("words.txt","r");
	
	for(i=0; i<100; i++)			
		fgets(wholeWords[i],20,fp);		//all words in wholeWords array
		
	for(i=0; i<10; i++)
	{
		randNum= (rand()%100)+1;
		strcpy(tenWords[i],wholeWords[randNum]);		
	}	
	fclose(fp);
}

/*creates random letters and sends it*/
char createRandLetter()			
{
	 int c=rand()%123;
    while(c<97||c>122)
    	c=rand()%123;
    return c;
}
/*-------------------------------------------------------------------------------------------------*/
/*
* This placeWords function firstly  takes random coordinates in map. after that places the word
* to a usuable place
* before placing the word function controls the gaps	
*/
void placeWords(char map[22][22], char words[10][20], int whichWord, int direction)
{
	int i,k,randRow,randCol,row,col, appropriate=1, gap=0,wordLength;
	srand(time(NULL));
	wordLength=strlen(words[whichWord])-2;
	randRow=rand()%19;	//random rows and columns
	randCol=rand()%19;								
	//for saving the real row and columns (randRow nad randCol)
	row=randRow;
	col=randCol;
	i=wordLength;
	while(i>0)
	{	
		if(map[randRow][randCol]=='*')	//if recieved coordinates have * sign...
		{
			gap++;
			switch(direction)
			{
				case lefttoRigth:
					randCol++;
					if(randRow<0 || randRow>19 || randCol<0 || randCol>19)
					{
						appropriate=0;		//if appropriate==0, this means that the gap is not usable
						break;
					}
					if(gap==wordLength)	//this means that the gap is usable in this direction
					{
						for ( k = 0; k<wordLength; k++)		//places the word letter by letter
						{
							map[row][col]=words[whichWord][k];	
							col++;
						}
					}		
					break;
				
				case righttoLeft:
					randCol--;
					if(randRow<0 || randRow>19 || randCol<0 || randCol>19)
					{
						appropriate=0;		//if appropriate==0, this means that the gap is not usable
						break;
					}
					if(gap==wordLength)		//this means that the gap is usable in this direction
					{
						for ( k = 0; k<wordLength; k++)	//places the word letter by letter
						{
							map[row][col]=words[whichWord][k];
							col--;
						}
					}		
					break;
			
				case bottomtoTop:
					randRow--;
					if(randRow<0 || randRow>19 || randCol<0 || randCol>19)
					{
						appropriate=0;		//if appropriate==0, this means that the gap is not usable
						break;
					}
					if(gap==wordLength)		//this means that the gap is usable in this direction
					{
						for ( k = 0; k<wordLength; k++)	//places the word letter by letter
						{
							map[row][col]=words[whichWord][k];
							row--;
						}
					}		
					break;

				case toptoBottom:
					randRow++;
					if(randRow<0 || randRow>19 || randCol<0 || randCol>19)
					{
						appropriate=0;		//if appropriate==0, this means that the gap is not usable
						break;
					}
					if(gap==wordLength)		//this means that the gap is usable in this direction
					{
						for ( k = 0; k<wordLength; k++)	//places the word letter by letter
						{
							map[row][col]=words[whichWord][k];
							row++;
						}
					}		
					break;

				case southtoEast:
					randRow++;
					randCol++;
					if(randRow<0 || randRow>19 || randCol<0 || randCol>19)
					{
						appropriate=0;		//if appropriate==0, this means that the gap is not usable
						break;
					}
					if(gap==wordLength)		//this means that the gap is usable in this direction
					{
						for ( k = 0; k<wordLength; k++)	//places the word letter by letter
						{
							map[row][col]=words[whichWord][k];
							row++;
							col++;
						}
					}		
					break;

				case northtoEast:
					randRow--;
					randCol++;
					if(randRow<0 || randRow>19 || randCol<0 || randCol>19)
					{
						appropriate=0;		//if appropriate==0, this means that the gap is not usable
						break;
					}
					if(gap==wordLength)		//this means that the gap is usable in this direction
					{
						for ( k = 0; k<wordLength; k++)	//places the word letter by letter
						{
							map[row][col]=words[whichWord][k];
							row--;
							col++;
						}
					}		
					break;

				case southtoWest:
					randRow++;
					randCol--;
					if(randRow<0 || randRow>19 || randCol<0 || randCol>19)
					{
						appropriate=0;		//if appropriate==0, this means that the gap is not usable
						break;
					}
					if(gap==wordLength)		//this means that the gap is usable in this direction
					{
						for ( k = 0; k<wordLength; k++)	//places the word letter by letter
						{
							map[row][col]=words[whichWord][k];
							row++;
							col--;
						}
					}		
					break;

				case northtoWest:
					randRow--;
					randCol--;
					if(randRow<0 || randRow>19 || randCol<0 || randCol>19)
					{
						appropriate=0;		//if appropriate==0, this means that the gap is not usable
						break;
					}
					if(gap==wordLength)		//this means that the gap is usable in this direction
					{
						for ( k = 0; k<wordLength; k++)	//places the word letter by letter
						{
							map[row][col]=words[whichWord][k];
							row--;
							col--;
						}
					}		
					break;
			}
		}	

		else
			appropriate=0;		//if there is another words letter it's not appropriate
		i--;
		if(appropriate==0)		//if the funtion have not found usable place, again takes random places
		{
			i=wordLength;
			appropriate=1;
			randRow=rand()%20;	
			randCol=rand()%20;
			row=randRow;
			col=randCol;
		}
	}
}
/*-------------------------------------------------------------------------------------------------*/
//fills the map with random letters
void fillMap(char map[22][22])			
{
	int i,k;
	char temp;
	for(i=0; i<20;i++)
	{
		for(k=0; k<20; k++)
		{
			if(map[i][k]=='*')
			{
				temp=createRandLetter();
				map[i][k]=temp;
			}	
		}
	}	
}
/*-------------------------------------------------------------------------------------------------*/
/*
* the searchWordInMap funtion checks all direction if the word is here or not. 
* this procces is carried out by checking the letters one by one
*/

int searchWordInMap(char map[22][22], char answer[], int row, int col)    
{
  int tempRow,tempCol,i,k,length,returnValue=1,checkLoops=CONTINUE;
 
 //assign the col and row values to temporary variables to save the real col and row
  tempCol=col;
  tempRow=row;
  length=strlen(answer);		

  while(checkLoops==CONTINUE)
  {		
 	/*--------------------------------------------*/
 	/*left-right*/
  	for(i=tempCol,k=1; i<19,k<length; k++,i++)
  	{
  		if(map[tempRow][i+1]!=answer[k])
  		{	//the word isn't in this direction 
  			returnValue=0;
  			break; //leave the for loop
  		}
  	}

  	if(returnValue==1)
  	{
  		for(k=0; k<length; k++)
  		{	//make word uppercase in map 
	  		map[tempRow][tempCol]=answer[k]-32;
	  		tempCol++;
	  		if(tempCol>=19)
	  			break;
  		}
  		break; //leave the while loop
  	}

  	/*------------------------------------------*/
 	/*rigth-left*/
  	returnValue=1;
  	tempCol=col;
 	tempRow=row;
  	for(i=tempCol,k=1; i>0,k<length; k++,i--)
  	{
  		if(map[tempRow][i-1]!=answer[k])
  		{	//the word isn't in this direction 
  			returnValue=0;
  			break; //leave the for loop
  		}
  	}

  	if(returnValue==1)
  	{
  		for(k=0; k<length; k++)
  		{	//make word uppercase in map 
	  		map[tempRow][tempCol]=answer[k]-32;	
	  		tempCol--;
	  		if(tempCol<0)
	  			break;
  		}
  		break; //leave the while loop
  	}

  	/*---------------------------------------------*/
 	/*top-bottom*/
  	returnValue=1;
  	tempCol=col;
 	tempRow=row;
  	for(i=tempRow,k=1; i<19,k<length; k++,i++)
  	{
  		if(map[i+1][tempCol]!=answer[k])
  		{	//the word isn't in this direction 
  			returnValue=0;
  			break; //leave the for loop
  		}
  	}

  	if(returnValue==1)
  	{
  		for(k=0; k<length; k++)
  		{	//make word uppercase in map 
	  		map[tempRow][tempCol]=answer[k]-32;	
	  		tempRow++;
	  		if(tempRow>=19)
	  			break;
  		}
  		break; //leave the while loop
  	}

  	/*----------------------------------------------*/
 	/*bottom-top*/
  	returnValue=1;
  	tempCol=col;
 	tempRow=row;
  	for(i=tempRow,k=1; i>0,k<length; k++,i--)
  	{
  		if(map[i-1][tempCol]!=answer[k])
  		{	//the word isn't in this direction 
  			returnValue=0;
  			break; //leave the for loop
  		}
  	}

  	if(returnValue==1)
  	{
  		for(k=0; k<length; k++)
  		{	//make word uppercase in map 
	  		map[tempRow][tempCol]=answer[k]-32;	
	  		tempRow--;
	  		if(tempRow<0)
	  			break;
  		}
  		break; //leave the while loop
  	}

  	/*------------------------------------------------*/
 	/*right-bottom*/
  	returnValue=1;
  	tempCol=col;
 	tempRow=row;
  	for(i=tempRow,k=1; i<19,k<length; k++,i++)
  	{
  		if(map[i+1][tempCol+1]!=answer[k])
  		{	//the word isn't in this direction 
  			returnValue=0;
  			break; //leave the for loop
  		}
  		tempCol++;
  	}

  	if(returnValue==1)
  	{
  		for(k=0; k<length; k++)
  		{	//make word uppercase in map 
	  		map[tempRow][tempCol]=answer[k]-32;	
	  		tempRow++;
	  		tempCol++;
	  		if(tempRow>=19||tempCol>=19)
	  			break;
  		}
  		break; //leave the while loop
  	}

  	/*--------------------------------------------------*/
 	/*left-top*/
  	returnValue=1;
  	tempCol=col;
 	tempRow=row;
  	for(i=tempRow,k=1; i>0,k<length; k++,i--)
  	{
  		if(map[i-1][tempCol-1]!=answer[k])
  		{	//the word isn't in this direction 
  			returnValue=0;
  			break; //leave the for loop
  		}
  		tempCol--;
  	}

  	if(returnValue==1)
  	{
  		for(k=0; k<length; k++)
  		{	//make word uppercase in map 
	  		map[tempRow][tempCol]=answer[k]-32;	
	  		tempRow--;
	  		tempCol--;
	  		if(tempRow>=19||tempCol>=19)
	  			break;
  		}
  		break; //leave the while loop
  	}

  	/*--------------------------------------------------*/
 	/*right-top*/
  	returnValue=1;
  	tempCol=col;
 	tempRow=row;
  	for(i=tempCol,k=1; i<19,k<length; k++,i++)
  	{
  		if(map[tempRow-1][i+1]!=answer[k])
  		{	//the word isn't in this direction 
  			returnValue=0;
  			break; //leave the for loop
  		}
  		tempRow--;
  	}
  	tempCol=col;
 	tempRow=row;
  	if(returnValue==1)
  	{
  		for(k=0; k<length; k++)
  		{	//make word uppercase in map
	  		map[tempRow][tempCol]=answer[k]-32;	
	  		tempRow--;
	  		tempCol++;
	  		if(tempRow<0||tempCol>=19)
	  			break;
  		}
  		break; //leave the while loop
  	}

  	/*--------------------------------------------------*/
 	/*rigth-bottom*/
  	returnValue=1;
  	tempCol=col;
 	tempRow=row;
  	for(i=tempRow,k=1; i<19,k<length; k++,i++)
  	{	
  		if(map[i+1][tempCol-1]!=answer[k])
  		{	//the word isn't in this direction
  			returnValue=0;
  			break; //leave the for loop
  		}
  		tempCol--;
  	}

  	tempCol=col;
 	tempRow=row;
  	if(returnValue==1)
  	{
  		for(k=0; k<length; k++)
  		{	//make word uppercase in map
	  		map[tempRow][tempCol]=answer[k]-32;	
	  		tempRow--;
	  		tempCol++;
	  		if(tempCol<0||tempRow>=19)
	  			break;
  		}
  		break; //leave the while loop
  	}

  	checkLoops=STOP;
  }
  return returnValue;
}

