#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZEofFILE 2001
#define SIZEofLINE 200
#define TRUE 1
#define FALSE 0
void clearDuplicating(char array[SIZEofFILE][20]);
void gamesThroughYears(float floatInfos[SIZEofFILE][7],char names[SIZEofFILE][SIZEofLINE]);
void showAllInfos(float floatInfos[SIZEofFILE][7],char names[SIZEofFILE][SIZEofLINE],char genres[SIZEofFILE][20], char platforms[SIZEofFILE][20]);
void GeorograpicalInfo(float floatInfos[SIZEofFILE][7], char names[SIZEofFILE][SIZEofLINE]);
void avarageScores(float floatInfos[SIZEofFILE][7]);
void Frequencies(char array[][20],char infoArray[SIZEofFILE][20],int size);

int main(void)
{
	char array[SIZEofFILE][SIZEofLINE],names[SIZEofFILE][SIZEofLINE];
	char genres[SIZEofFILE][20], platforms[SIZEofFILE][20],oldgenres[SIZEofFILE][20], oldplatforms[SIZEofFILE][20];
	char tArray1[50],tArray2[50],tArray3[50],tArray4[50],tArray5[50];
	float floatInfos[SIZEofFILE][7];
	char allGenres[12][20], allPlatforms[10][20];
	int i=0,k=0,m=0,j, checkLoops=TRUE;
	int selection;
	char *p;

	//saving the file to a buffer array
	FILE *fp=fopen("Video_Games.txt","r");

	for(i=0; i<SIZEofFILE; i++)
		fgets(array[i],SIZEofLINE,fp);
	fclose(fp);
	//converting the ',' to whitespaces into array so that we can use sscanf
	for(i=0; i<SIZEofFILE; i++)
	{
		for(k=0; k<strlen(array[i]); k++)
		{
			if(array[i][k]==',')
				array[i][k]=' ';
		}
	}

	// 1.row: Genres 	2.row: platforms 	3.row: release years
	// 4.row: na_sales 	5.row: eu_sales 	6.row: global_sales	 7.row: user_score	
	//creating of names array
	for(i=0; i<SIZEofFILE; i++)
	{
		sscanf(array[i],"%s %s %s %s %s %s %s %s",names[i],oldgenres[i],oldplatforms[i],tArray1,tArray2,tArray3,tArray4,tArray5);
		//genres and platforms are placed in the first 2 columns of each row
		floatInfos[m][1]=strtod(genres[i],&p);
		floatInfos[m][2]=strtod(platforms[i],&p);	
		//others are placed as well
		sscanf(tArray1,"%f",&floatInfos[m][3]);
		sscanf(tArray2,"%f",&floatInfos[m][4]);
		sscanf(tArray3,"%f",&floatInfos[m][5]);
		sscanf(tArray4,"%f",&floatInfos[m][6]);
		sscanf(tArray5,"%f",&floatInfos[m][7]);
		m++;
	}
	for(i=0; i<SIZEofFILE; i++)
	{
		strcpy(genres[i],oldgenres[i]);
		strcpy(platforms[i],oldplatforms[i]);
	}

	clearDuplicating(genres);
	clearDuplicating(platforms);

	for(i=0; i<13; i++)
		strcpy(allGenres[i],genres[i]);

	for(i=0; i<11; i++)
		strcpy(allPlatforms[i],platforms[i]);
	while(checkLoops==TRUE)
	{	
		while(checkLoops==TRUE)
		{
			printf("\n");
			printf("0: List of the Genres\n");
			printf("1: List of the platforms\n");
			printf("2: List of the games through the years\n");
			printf("3: All informations of a single game\n");
			printf("4: Average of the users scores\n");
			printf("5: Georograpical information of a single game\n");
			printf("6: Frequence of the Gernes\n");
			printf("7: Frequence of the platforms\n");
			printf("8: Exit\n");
			scanf("%d",&selection);
			if(selection<0 || selection>8)
				printf("invalid option! please try again...\n");
			else
				checkLoops=FALSE;
		}
		if(selection!=8)
			checkLoops=TRUE;

		switch(selection)
		{
			case 0:		//List of the Genres
				for(i=1; i<=12; i++)
    				printf("%s\n", genres[i]);							
				break;
			case 1:	//List of the platforms
				for(i=1; i<11; i++)
    				printf("%s\n", platforms[i]);							
				break;
			case 2: 	
				//List of the games through the years
				gamesThroughYears(floatInfos,names);
				break;
			case 3:
				//All informations of a single game
				showAllInfos(floatInfos,names,oldgenres,oldplatforms);
				break;
			case 4:
				//Average of the users scores
				avarageScores(floatInfos);
				break;
			case 5:
				//Georograpical information of a single game
				GeorograpicalInfo(floatInfos,names);
				break;
			case 6:
				//Frequencies of the Gernes
				Frequencies(allGenres,oldgenres,13);
				break;
			case 7:
				//Frequencies of the platforms
				Frequencies(allPlatforms,oldplatforms,11);
				break;
		}

	}

}

void gamesThroughYears(float floatInfos[SIZEofFILE][7],char names[SIZEofFILE][SIZEofLINE])
{
	int i, oldest=0, youngest=2021,yearColm=3,checkLoops=TRUE;	//oldest and youngest must have initial values
	int year, UntilOrSince;
	//finds youngest and oldest games
	for(i=0; i<SIZEofFILE; i++)
	{
		if(floatInfos[i][yearColm]>oldest)
			oldest=floatInfos[i][yearColm];
		
		if(floatInfos[i][yearColm]<youngest)
			youngest=floatInfos[i][yearColm];	
	}

	while(checkLoops==TRUE)
	{
		while(checkLoops==TRUE)	
		{	
			checkLoops=FALSE;
			printf("Enter a year: \n");
			scanf("%d",&year);
			printf("Until (0) or Since (1) %d: ",year);
			scanf("%d",&UntilOrSince);
			
			if(year==oldest && UntilOrSince==1)
			{
				printf("there is no game since %d\n please try again!!\n",oldest);
				checkLoops=TRUE;
			}
			else if(year==youngest && UntilOrSince==0)
			{
				printf("there is no game until %d\n please try again!!\n",youngest);
				checkLoops=TRUE;
			}
		}
			for(i=1;i<SIZEofFILE;i++)
			{
				if(UntilOrSince==0)
				{
					if(floatInfos[i][yearColm]<year)
						printf("%s\n",names[i]);	
				}
				else if(UntilOrSince==1)
				{
					if(floatInfos[i][yearColm]>year)
						printf("%s\n",names[i]);
				}
			}	
	}

}
//shows all information for choosen game by using float array
void showAllInfos(float floatInfos[SIZEofFILE][7],char names[SIZEofFILE][SIZEofLINE],char genres[SIZEofFILE][20], char platforms[SIZEofFILE][20])
{
	int checkLoops=TRUE,i,k, gameRow;
	char userInput[50];
	
	while(checkLoops==TRUE)
	{
		printf("please enter a name: ");
		scanf("%s",userInput);
		checkLoops=FALSE;
		for(i=0;i<SIZEofFILE; i++)
		{		
			if(strcmp(names[i],userInput)==0)	//find game row so that we can arrive other information	
			{
				gameRow=i;		
				break;
			}
			else
				gameRow=-1;		//there is no row who has this game like this!
		}

		if(gameRow==-1)
		{
			printf("wrong name please try again\n");
			checkLoops=TRUE;
		}	
		else
		{
			printf("Name: %s\n",names[gameRow]);
			printf("Genre: %s\n",genres[gameRow]);	
			printf("Platform: %s\n",platforms[gameRow]);	
			printf("Year: %f\n",floatInfos[gameRow][3]);
			printf("Sales In Na: %f\n",floatInfos[gameRow][4]);
			printf("Sales In Eu: %f\n",floatInfos[gameRow][5]);
			if(floatInfos[gameRow][6]==0)							//not avaliable=0;
				printf("Total Sales: Not Avaible\n");
			else
				printf("Total Sales: %f\n",floatInfos[gameRow][6]);

			printf("User Score: %f\n",floatInfos[gameRow][7]);
			printf("\n");
		}
	}

}

void GeorograpicalInfo(float floatInfos[SIZEofFILE][7], char names[SIZEofFILE][SIZEofLINE])
{
	char userInput[50];
	int checkLoops=TRUE, i, gameRow;

	while(checkLoops==TRUE)
	{
		printf("please enter the name of the game: \n");
		scanf("%s",userInput);
		checkLoops=FALSE;
		for(i=0;i<SIZEofFILE; i++)
		{
			if(strcmp(names[i],userInput)==0)
			{
				gameRow=i;
				break;
			}
			else
				gameRow=-1;
		}

		if(gameRow==-1)
		{
			printf("wrong name please try again!!!\n");
			checkLoops=TRUE;
		}
		else
		{	//4: na_sales row, 5: eu_sales row.
			if(floatInfos[gameRow][4]>floatInfos[gameRow][5])
				printf("this game was more popular in north America.\n");
			else
				printf("this game was more popular in Europe.\n");
		}
	}	

}

void avarageScores(float floatInfos[SIZEofFILE][7])
{
	int i;
	float result,sum=0.0;

	for(i=0;i<SIZEofFILE;i++)
		sum+=floatInfos[i][7];

	result=sum/2000;
	printf("%lf\n",result);
}

//this funciton removes the duplicating values
void clearDuplicating(char array[SIZEofFILE][20])
{
	int i,j,k, size=SIZEofFILE;

	for(i=0; i<size; i++)		
	{
       	for(j=i+1;j<size;)
        {
            if(strcmp(array[i],array[j])==0)
            {
                for(k=j+1; k<size; k++)
                    strcpy(array[k-1], array[k]);  
                size--;
            }
            else
                j++;      
        }
    }
}
void Frequencies(char array[][20],char infoArray[SIZEofFILE][20], int size)
{
	int i, k,tempArray[size][2],temp;

	for(i=1; i<size+1; i++)
		tempArray[i][1]=0;
		
	printf("-------------------------\n");
	for(i=0; i<SIZEofFILE; i++)
	{
		for(k=1; k<size+1; k++)
		{		
			if(strcmp(infoArray[i],array[k])==0)	
			{
				temp=tempArray[k][1];
				temp++;
				tempArray[k][1]=temp;						
			}
		}
	}

	for(i=1; i<size; i++)
		printf("%s     %-15d\n", array[i], tempArray[i][1]);	
}