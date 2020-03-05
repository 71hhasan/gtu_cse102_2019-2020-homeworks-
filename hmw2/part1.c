#include<stdio.h>
#include<math.h>

int draw_triangle(int, int, int);
void type_triangle(int, int, int);
int perimeter_triangle(int, int, int);
double area_triangle(int, int, int, int);

int main()
{
	int a, b, c, temp=1, perimeter;
	
	printf("the length of the first side: ");
	scanf("%d", &a);
	printf("the length of the second side: ");
	scanf("%d", &b);
	printf("the length of the third side: ");
	scanf("%d", &c);
	
	temp=draw_triangle(a, b, c);
	
	if(temp==0)
	{
		printf("\nAccording to the triangle inequality theorem  this triangle cannot be drawn.\n\n");
		return 0;
	}
	
	else
	{
		printf("\nAccording to the triangle inequality theorem, this triangle can be drawn.\n\n");
	}
		
	type_triangle(a, b, c);
	perimeter= perimeter_triangle(a, b, c);
	
	 printf("perimeter of the triangle: %d\n\n", perimeter);
	 
	 printf("area of the triangle: %lf\n", area_triangle( a, b, c, perimeter));	
}


int draw_triangle(int side1, int side2, int side3)
{
	int return_value=0;
	
	if(side1+side2>side3 && side1+side3>side2 && side3+side2>side1)
	{
		return_value=1;
	}
	
	return return_value;	
}


void type_triangle(int side1, int side2, int side3)
{
	
	if(side1 == side2 && side2 == side3)
	{
		printf("it is an equilateral triangle\n\n");
	}
	
	else if((side1==side2 && side1!=side3) || (side1==side3 && side3!=side2) || (side2==side3 && side2!=side1))
	{
		printf("it is an isosceles tirangle\n\n");
	}
	
	else
	{
		printf("it is a scalene tirangle\n\n");
	}
	
}

int perimeter_triangle(int side1, int side2, int side3)
{
	int return_value;
	
	return_value = side1 + side2 + side3;

	return return_value;
}


double area_triangle(int side1, int side2, int side3, int perimeter)
{
	double p, area, temp_value; 
	
	p = (perimeter)/2;
	
	temp_value= p*(p-side1)*(p-side2)*(p- side3);
	
	area=sqrt(temp_value);
	
	return area;
	
}



