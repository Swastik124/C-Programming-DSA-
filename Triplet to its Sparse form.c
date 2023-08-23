#include<stdio.h>
void read_triplet(int [][3],int);
void sparse_conv(int [][3],int [][10],int);
void display(int [][10]);
void main()
{
	int a[10][3],mat[10][10],r1;
	printf("Number of rows= ");
	scanf("%d",&r1);
	read_triplet(a,r1);
	sparse_conv(a,mat,r1);
	display(mat);
}

void read_triplet(int a[10][3],int r1)
{
	printf("Enter the triplet form= \n");
	int i,j;
	for(i=0;i<=r1;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}

}
void sparse_conv(int a[10][3],int mat[10][10],int r1)
{
	int i,j;
	for(i=0;i<a[0][0];i++)
	{
		for(j=0;j<a[0][1];j++)
		{
			mat[i][j]=0;
		}
	}
	
	for(i=1;i<=r1;i++)
	{
		mat[a[i][0]][a[i][1]]=a[i][2];
	}
}
void display(int mat[10][10])
{
	int i,j;
	printf("Displaying the sparse matrix= \n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d",mat[i][j]);
		}
		printf("\n");
	}

}
