#include <stdio.h>
#include <math.h>

void print_plus_minus(int n, int boxSize) 
{
	for (int v = 0; v <= n * boxSize; v++)
	{
		if (v % boxSize == 0)
			printf("+");
		else
			printf("-");
	}
	printf("\n");
}

int main()
{
	int m, n, maxN = -999999; 
	printf("\nEnter the number of rows > ");
	scanf("%d", &m);
	printf("Enter the number of cols > ");
	scanf("%d", &n);
	printf("\n");
	int matrix[m][n], Tmatrix[n][m];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf(" Matrix[%d][%d] > ", i, j);
			scanf(" %d", &matrix[i][j]);
			if (matrix[i][j] > maxN)
				maxN = (matrix[i][j] < 0) ? -1*matrix[i][j] : matrix[i][j];
		}
	}
	
	int boxSize = (log(maxN)>3) ? log(maxN)+1  : 3; 

	printf("\nMatrix\n");
	print_plus_minus(n, boxSize);
	for (int i = 0; i < m; i++) 
	{
		for (int j = 0; j < n; j++)
		{
			printf("| %*d", boxSize - 2, matrix[i][j]);
			if (j == n - 1)
				printf("|");
		}
		printf("\n");
		print_plus_minus(n, boxSize);
	}
	
	printf("\n\nTranspose Matrix\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			Tmatrix[i][j] = matrix[j][i];
		}
	}
	print_plus_minus(m, boxSize);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("| %*d", boxSize-2, Tmatrix[i][j]);
			if (j == m - 1)
				printf("|");
		}
		printf("\n");
		print_plus_minus(m, boxSize);
	}
	return 0;
}
