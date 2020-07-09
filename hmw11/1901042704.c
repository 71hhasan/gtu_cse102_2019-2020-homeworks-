#include <stdio.h>			/*haci hasan savan 1901042704*/
#include <stdlib.h>
#include <math.h>								
#include <time.h>								
												
/*linked list node*/
struct n{
	int infoBox;
	struct n *nextBox;
};
typedef struct n node;

/*---------------------------------------------------------------------*/
struct d
{
	int n1;
	int n2;
};
typedef struct d diffElements;

/*prototyps*/
float * stats_linkedlist(node *iter);
int *read_array(char *filename);
node *read_linkedlist(char *filename);
float * stats_array(int *arr);
void findDifferentElements(node *iterr, int *dynArr);
/*---------------------------------------------------------------------*/

int main()
{	
	float *lListResult,*ArrResult;
	clock_t time_taken;
	double avarage_time1,avarage_time2,avarage_time3,avarage_time4;
	char *filename="list.txt"; //file name
	int byte_size1,byte_size2;
	/*---------------------------------------------------------------------*/

	/*1)dynamic array */
	int *dynArr; //values readed from the file
	
	for(int j=0; j<4;j++)
	{
		time_taken=clock();
		dynArr=read_array(filename);
		time_taken=clock()-time_taken;
		avarage_time1+=((double)time_taken)/CLOCKS_PER_SEC;
	}
	avarage_time1=avarage_time1/4;	
	byte_size1=150000*sizeof(int); //150000: number of elements in array
	/*---------------------------------------------------------------------*/
	
	/*2)linked list*/
	node *root;
	root=(node *)malloc(sizeof(node));
	for(int j=0; j<4;j++)
	{
		time_taken=clock();
		root=read_linkedlist(filename);
		time_taken=clock()-time_taken;
		avarage_time2+=((double)time_taken)/CLOCKS_PER_SEC;
	}
	avarage_time2=avarage_time2/4;	
	byte_size2=150000*sizeof(root); //150000: number of elements in array
	/*---------------------------------------------------------------------*/
	
	/*3)part of min-max-mean-s.deviation*/
	for(int j=0; j<4;j++)
	{
		time_taken=clock();
	    ArrResult=stats_array(dynArr);
	    time_taken=clock()-time_taken;
		avarage_time3+=((double)time_taken)/CLOCKS_PER_SEC;
	}
	avarage_time3=avarage_time3/4;
	/*---------------------------------------------------------------------*/

    /*4)part of min-max-mean-s.deviation in linked list */
	for(int j=0; j<4;j++)
    {
    	time_taken=clock();
		lListResult=stats_linkedlist(root);
		time_taken=clock()-time_taken;
		avarage_time4+=((double)time_taken)/CLOCKS_PER_SEC;
    }
    avarage_time4=avarage_time4/4;
	/*---------------------------------------------------------------------*/
	//total_time=read_array_t+stats_array_t;
	/*printing*/
	printf("###################part1#####################\n\n\n");
	printf("Dynamic array infomrmations: \n\n");
	printf(">array filling time (avarage): %lf\n", avarage_time1);
	printf(">Array's data calculation time (avarage): %lf\n",avarage_time3);
	printf(">minimum value: %.3f\n",ArrResult[0]);
	printf(">maximum value: %.3f\n",ArrResult[1]);
	printf(">mean value: %.3f\n",ArrResult[2]);
	printf(">standart deviation value: %.3f\n",ArrResult[3]);
	printf(">bytes used: %d\n", byte_size1);
	
	printf("\n------------------------------------------------\n\n");

	printf("Linked list informations: \n\n");
	printf(">linked list filling time (avarage): %lf\n", avarage_time2);
	printf(">linked list's data calculation time (avarage): %lf\n",avarage_time4);
	printf(">minimum value: %.3f\n",lListResult[0]);
	printf(">maximum value: %.3f\n",lListResult[1]);
	printf(">mean value: %.3f\n",lListResult[2]);
	printf(">standart deviation value: %.3f\n",lListResult[3]);
	printf(">bytes used: %d\n", byte_size2);

	/*-----------------------END OF PART1----------------------------------*/
	/*---------------------------------------------------------------------*/
	int *dyn_arr,entries=0,i=0,k=0;
	dyn_arr=(int*)malloc(sizeof(int));
	dyn_arr[0]=0;
	printf("\n###################part2#####################\n\n\n");
	printf("please enter as many numbers as you want for DYNAMIC ARRAY:\n");
	printf("please type '-1' to terminate the typing\n");
	
	while(entries!=-1)
	{
		scanf("%d",&entries);
		dyn_arr[i]=entries;
		i++;
		dyn_arr=(int*)realloc(dyn_arr,(i+1)*sizeof(int));
	}
	printf("you entered %d numbers\n",i-1);
	while(1)
	{
		if(dyn_arr[k]==-1)
			break;
		printf("%d ",dyn_arr[k]);
		k++;
	}
	entries=0;
	k=0;
	node *_root,*_iter,*_temp;
	_root=(node*)malloc(sizeof(node));
	_iter=_root;
	_temp=_root;
	printf("\n\n");
	printf("please enter as many numbers as you want for LINKED LIST:\n");
	printf("please type '-1' to terminate the typing\n");
	while(entries!=-1)
	{
		scanf("%d",&entries);
		_iter->infoBox=entries;
		k++;
		_iter->nextBox=(node *)malloc(sizeof(node));
		_iter=_iter->nextBox;
	}
	printf("you entered %d numbers\n",k-1);
	while(1)
	{
		if(_temp->infoBox==-1)
			break;
		printf("%d ",_temp->infoBox);
		_temp=_temp->nextBox;
	}
	printf("\n");
	findDifferentElements(_root,dyn_arr);

}
/*---------------------------------------------------------------------*/
float * stats_linkedlist(node *iter)
{
	float *result,sum,tempValue=0.0;
	int operations=4,counter=0;
	node *iter2=iter;
	result=(float *)calloc(operations,sizeof(float));
	result[0]=iter->infoBox;
	result[1]=iter->infoBox;
	result[2]=0;

	/*
	result[0]: min  	result[1]:max		result[2]: mean 	result[3]:standart deviation
	*/
	while(iter->nextBox->nextBox!=NULL)
	{
		/*min*/
		if(iter->infoBox<result[0])
			result[0]=iter->infoBox;
		/*max*/
		if(iter->infoBox>result[1])
			result[1]=iter->infoBox;
		/*sum for mean*/
		sum+=iter->infoBox;
		iter=iter->nextBox;
		counter++;
	}	
	/*mean*/
	result[2]=sum/counter;

	while(iter2->nextBox!=NULL)
	{
		tempValue+=(iter2->infoBox-result[2])*(iter2->infoBox-result[2]);
		iter2=iter2->nextBox;
	}
	result[3]=sqrt(tempValue/counter);

	return result;
}
/*---------------------------------------------------------------------*/
float * stats_array(int *arr) 
{
	int i=0;
	float *result;
	float sum=0.0,tempValue=0.0;
	result=(float*)malloc(4*sizeof(float));
	/*
	result[0]: min  	result[1]:max		result[2]: mean 	result[3]:standart deviation
	*/
	result[0]=arr[0];
	result[1]=arr[0];
	result[2]=0;
	result[3]=0;
	while(arr[i]!=-1)
	{
		if(arr[i]>result[1])
			result[1]=arr[i];
		if(arr[i]<result[0])
			result[0]=arr[i];		
		sum+=arr[i];	
		i++;
	}

	result[2]=sum/(i); 
	i=0;
	while(arr[i]!=-1) 
	{
		tempValue+=(arr[i]-result[2])*(arr[i]-result[2]);
		i++;
	}
	result[3]=sqrt(tempValue/(i));

	return result;	
}
/*---------------------------------------------------------------------*/
node *read_linkedlist(char *filename)	//sonuncuya null değeri vermek lazım
{
	FILE *fp=fopen(filename,"r");
	char garbageValue;
	node *root,*iter;
	root=(node *)malloc(sizeof(node));
	iter=(node *)malloc(sizeof(node));
	iter=root;
	while(!feof(fp))
	{
		fscanf(fp,"%d",&iter->infoBox);
		fscanf(fp,"%c",&garbageValue);
		iter->nextBox=(node *)malloc(sizeof(node));
		iter=iter->nextBox;
	}
	fclose(fp);
	return root;
}
/*---------------------------------------------------------------------*/
int *read_array(char *filename)
{
	FILE *fp=fopen(filename,"r");
	int *arr=NULL;
	int i=1;
	char garbageValue;
	arr=(int *)malloc(sizeof(int));

	while(!feof(fp))
	{
		fscanf(fp,"%d",&arr[i-1]);
		fscanf(fp,"%c",&garbageValue);
		arr=(int *)realloc(arr,(i+1)*sizeof(int));
		arr[i]=-1;
		i++;
	}
	fclose(fp);
	return arr;
}
/*---------------------------------------------------------------------*/
//part2
void findDifferentElements(node *iterr, int *dynArr)
{
	int i=0,k=0;
	diffElements *elements;
	elements=(diffElements*)malloc(sizeof(diffElements));		
	while(dynArr[i]!=-1)
	{
		if(dynArr[i]!=iterr->infoBox)
		{
			elements[k].n1=dynArr[i];
			elements[k].n2=iterr->infoBox;
			k++;
			elements=(diffElements*)realloc(elements,(k+1)*sizeof(diffElements));
			printf("\nn1: %d n2: %d\n",elements[k-1].n1,elements[k-1].n2);
		}
		i++;
		iterr=iterr->nextBox;
	}
}
