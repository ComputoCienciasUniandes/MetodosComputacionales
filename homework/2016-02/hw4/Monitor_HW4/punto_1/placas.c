#include <stdio.h>
#include <stdlib.h>
#include "omp.h"
int L = 5, l = 2, d = 1, V0 = 100, m, N;
double h = 0.01;

int transformer(int i, int j);
double *init(int x0, int x1, int y0, int y1, double *array);

int main(void)
{
  int up, down, left, right, x0, x1, y0, y1, i=1, j=1, n=0, k;
	double average;
	
	m = L/h;
	N = 2*m*m;

	x0 = m/2 - l/(h*2) - 1;
	x1 = m/2 + l/(h*2) - 1;
	y0 = m/2 - d/(h*2) - 1;
	y1 = m/2 + d/(h*2) - 1;
	
	double *V = malloc(m*m*sizeof(double));
	double *V_new = malloc(m*m*sizeof(double));
	for(i=0;i<m*m;i++){
	  V[i] = 0.0;
	}
	
	V = init(x0, x1, y0, y1, V);
	V_new = init(x0, x1, y0, y1, V);

	while (n < N)
	{		

	  omp_set_num_threads(4);
#pragma parallel for private(j,up, down, left, right, average), shared(V, V_new)
	  {
	  for(i=1;i < m-1; i++)
		{
			for(j=1;j < m-1; j++)
			{
				up = transformer(i-1, j);
				down = transformer(i+1, j);
				left = transformer(i, j-1);
				right = transformer(i, j+1);
				if (!(j >= x0 && j <= x1 && i == y0) && !(j >= x0 && j <= x1 && i == y1))
				{
					average = (V[up] + V[down] + V[left] + V[right])/4;
					V_new[transformer(i,j)] = average;
				}
			}
		}
	  }
		for(i=1;i < m-1; i++)
		  {
		    for(j=1;j < m-1; j++)
			  {
			    V[transformer(i,j)] = V_new[transformer(i,j)] ;
			  }
		  }

		n += 1;
	}
	
	
	
	for(i=0;i < m; i++)
	{
		for(j=0;j < m; j++)
		{
			printf("%f\n", V[transformer(i,j)]);
		}
	}
	return 0;
}

int transformer(int i, int j)
{	
	
	return i*m + j;
}

double *init(int x0, int x1, int y0, int y1, double *array)
{	
	int a;
	for(a = x0; a <= x1; a++)
	{
		array[transformer(y0, a)] = V0/2;
		array[transformer(y1, a)] = -V0/2;
	}
	return array;
}
