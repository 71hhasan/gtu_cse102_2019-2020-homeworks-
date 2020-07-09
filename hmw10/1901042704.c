#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct points
{
	char name[10];
	double x;
	double y;
}PointArray[100];
struct line
{
	char name[10];
	struct points endpoint;
	struct points startpoint;
	double lengthofline;  //noktalar arası uzaklık formulüyle hesaplanacak
}lineArray[100];
struct polygons
{
	char name[10];
	double perimeter;
	double area;
	struct points PolygonPoints[20];
	struct line PolygonLines[20];
	int cornernumber;
}PolygonArray[20];

int main(){
	char buffer[20],data[56][20],temp;
	int i=0,count=0,indexNum=0,whichElement,whichElement2,start,end;
	/*open the file*/
	FILE*fp=fopen("commands.txt","r");
	/*takes the the data*/
	fscanf(fp,"%s",buffer);//'data'
	if(strcmp(buffer,"data")==0){
		fscanf(fp,"%s",buffer);//'10'
		
		while(count<atoi(buffer)){
			fscanf(fp,"%s",data[i]);
			//strcpy(data[i],buffer);
			i++;
			fscanf(fp,"%c",&temp);
			if(temp=='\n'){
				count++;
				if(data[i][0]=='P' && data[i][1]!='G'){//POİNT
					whichElement=(int)data[i][1];//Ex: it takes P1 from 1
					strcpy(PointArray[whichElement].name,data[i]);//coppy the name
					PointArray[whichElement].x=atof(data[i-2]);//x
					PointArray[whichElement].y=atof(data[i-1]);//y
				}
				if(data[i][0]=='L'){//LİNE
					strcpy(lineArray[indexNum].name,data[i]);
					start=data[i-2][1];
					end=data[i-1][1];
					lineArray[indexNum].startpoint=PointArray[start];
					lineArray[indexNum].endpoint=PointArray[end];
					indexNum++;
				}
				else{//POLYGON
					}
			}
			fscanf(fp,"%s",data[i]);
			if(strcmp(data[i],"//")==0){
				count++;
				temp='\0'; //tempi sıfırla
				while(temp!='\n'){
					fscanf(fp,"%c",&temp); //amac fp yi artırarak alt satıra geçirmek
				}
					if(data[i][0]=='P' && data[i][1]!='G'){//POİNT
					whichElement=(int)data[i][1];//Ex: it takes P1 from 1
					strcpy(PointArray[whichElement].name,data[i]);//coppy the name
					PointArray[whichElement].x=atof(data[i-2]);//x
					PointArray[whichElement].y=atof(data[i-1]);//y
				}
				if(data[i][0]=='L'){//LİNE
					strcpy(lineArray[indexNum].name,data[i]);
					start=data[i-2][1];
					end=data[i-1][1];
					lineArray[indexNum].startpoint=PointArray[start];
					lineArray[indexNum].endpoint=PointArray[end];
					indexNum++;
				}
				else{//POLYGON
					}

				fscanf(fp,"%s",buffer);
				i++;
			}
			strcpy(data[i],buffer);
			i++;
		}
	}

	count=0;
	fscanf(fp,"%s",buffer);
	fscanf(fp,"%s",buffer);//'actions'
	if(strcmp(buffer,"actions")==0){
		fscanf(fp,"%s",buffer);//'outputs.txt'
		fscanf(fp,"%s",buffer);//'6'
		while(count<atoi(buffer)){
			fscanf(fp,"%s",buffer);
			strcpy(data[i],buffer);
			i++;
			if(strcmp(data[i],"Distance")){
				fscanf(fp,"%s",data[i]);
				i++;
				fscanf(fp,"%s",data[i]);
				whichElement=(int)data[i-1][2];
				whichElement2=(int)data[i][2];	
			}
			else if(strcmp(data[i],"Angle")){
				
			}
			else if(strcmp(data[i],"Length")){
				
			}
			else if(strcmp(data[i],"Area")){
				
			}
			i++;
			count++;
		}
	}
	printf("%lf\n",PointArray[5].y);
	fclose(fp);
}
