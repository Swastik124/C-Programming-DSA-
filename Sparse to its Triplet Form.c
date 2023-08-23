#include<stdio.h>
#define max 10
void read_matrix(int [][max],int,int);
void display_matrix(int [][max],int,int);
void display_triplet(int [][max],int,int);
void main()
{
	int a[10][max],r1,c1;
	printf("Enter row and column respectively= ");
	scanf("%d%d",&r1,&c1);
	read_matrix(a,r1,c1);
	display_matrix(a,r1,c1);
	display_triplet(a,r1,c1);
}

void read_matrix(int a[10][max],int r1,int c1)
{
	int i,j;
	printf("Enter the matrix=\n");
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
}

void display_matrix(int a[][max],int r1,int c1)
{
	int i,j;
	printf("Displaying the matrix=\n");
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			printf("\t%d",a[i][j]);
		}
		printf("\n");
	}
}

void display_triplet(int a[][max],int r1,int c1)
{
	int mat[10][10];
	int i,j,count=0,c=3;
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			if(a[i][j]!=0)
			{
				mat[count][0]=i;
				mat[count][1]=j;
				mat[count][2]=a[i][j];
				count++;
			}
		}
	}
	display_matrix(mat,count,c);
}
