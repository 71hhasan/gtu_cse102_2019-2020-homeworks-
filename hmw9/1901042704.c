#include <stdio.h>			/*haci hasan savan 1901042704*/
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define FacesNum 13
#define CardsNum 52

struct Hospital
	{
		char* name;
		char citiesServed[3]; //seçilen hastanelerin isimleri
	};

struct card {                                 
  const char *face;
   const char *suit; 
};    

typedef struct card Card; 
int global_i=0,global_k=0;;
char globalString[4][4];
/* prototypes */
int numPathsHome(int street, int avenue);
int canOfferCovidCoverage(char _cities[6], char _locations[4][4], int _numHospitals, struct Hospital results[4]);
int chooseLocation(char cities[6], char locations[4][4], char array[4]);
void FillAndShuffleTheDeck(Card * Deck, char Faces[][10], char Suits[][10]);

int main()
{	
	int select,_numHospitals,i;
 	char face[][10] = {"Ace", "Deuce", "Three", "Four", "Five","Six", "Seven", "Eight", "Nine", "Ten","Jack", "Queen", "King"}; 
  	char suit[][10] = {"Hearts", "Diamonds", "Clubs", "Spades"};  
 	Card deck[CardsNum]; 
 	
 	struct Hospital results[4];
 	
 	char _cities[6] = {"abcdef"};
	char _locations[4][4]= {{"abc"}, {"acd"}, {"bf"}, {"cef"}};
 	
 	srand(time(NULL));



	printf("1) part1\n2) part2\n3) part3\n"); //menu
	scanf("%d",&select);
	
	if(select==1){
		int street,avenue;
		printf("enter the street number\n");
		scanf("%d",&street);
		printf("enter the avenue number\n");
		scanf("%d",&avenue);
		printf("number of optimal paths to take back home:%d\n",numPathsHome(street-1,avenue-1));
	}
	else if(select==2){
		printf("enter the max number of hospital taht can be constructed: ");
		scanf("%d",&_numHospitals);
		if(_numHospitals<3 )
			printf("no, some cties are not covered\n");
		else if(_numHospitals>4)
			printf("there is enough space to construct %d hospitals\n",_numHospitals);
		else 
		{
			canOfferCovidCoverage( _cities,_locations, _numHospitals, results);
			for(i=0; i<_numHospitals; i++)
			{
				printf("hospital %d\n",i+1);
				printf("%s\n", results[i].citiesServed);
			}
		}
	}
	else if(select==3){
   		FillAndShuffleTheDeck(deck, face, suit); 
	}
	else
		printf("invalid option!!\n");
}

/*------------------------------part1---------------------------------------------------*/

int numPathsHome(int street, int avenue)
{
    if (street==0 || avenue==0)
        return 1;

    return (numPathsHome(street-1, avenue) + numPathsHome(street, avenue-1));
}

/*------------------------------part2---------------------------------------------------*/
int canOfferCovidCoverage(char _cities[6], char _locations[4][4], int _numHospitals, struct Hospital results[4])
{
	char array[4];
 	_numHospitals-=1;
 	if(_numHospitals==-1)
 		return 1;

 	chooseLocation(_cities, _locations, array);
	strcpy(results[global_i].citiesServed,array);
	global_i++;
	canOfferCovidCoverage( _cities,_locations, _numHospitals, results);

}

int chooseLocation(char cities[6], char locations[4][4], char array[4])
{
	int x;
	char temp;
	x=rand()%4;
	strcpy(globalString[global_k],locations[x]);
	int m;
	for( m=0; m<4; m++)
	{
		if(strcmp(array,globalString[m])==0)
 			chooseLocation(cities, locations, array);
 		else
 			break;
	}
	strcpy(array,locations[x]);
	int i;
	for( i=0; i<strlen(array); i++)
	{
		temp=array[i];
		int k;
		for( k=0; k<strlen(cities); k++)
		{
			if(cities[k]==array[i])
				break;
		}
	}
}

/*------------------------------part3---------------------------------------------------*/

void FillAndShuffleTheDeck(Card * Deck, char Faces[][10], char Suits[][10])
{ 
   int j,i;     
   Card temp; 
    for(i=0; i<CardsNum; i++) //this for loop fills the deck array
	{ 
	    Deck[i].face=Faces[i%FacesNum];
	    Deck[i].suit=Suits[i/FacesNum];
	} 
   for (i=0; i<CardsNum; i++) 
   { 
      j=rand()%CardsNum;
      temp=Deck[i];      
      Deck[i]=Deck[j];
      Deck[j]=temp;      
   } 

   for (i=0; i<CardsNum; i++)
    {
      printf("%5s of %-10s", Deck[i].face, Deck[i].suit);
      if((i+1)%2==0)
      	printf("\n");
      else 
      	printf("\t");
   } 

} 


