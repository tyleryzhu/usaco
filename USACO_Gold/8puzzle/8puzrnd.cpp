#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

#define n 3
#define MAX 500

int git[n][n]={1,2,3,8,0,4,7,6,5};

// Hamle
int hamle(int no)
{
  int i,j,bosx,bosy;

  // bosyer bul
  for (i=0; i<n; ++i)
    for (j=0; j<n; ++j)
      if (!git[i][j]) bosy=i,bosx=j;

  switch(no)
  {
    case 0:
      if (bosx>0)
      {
	git[bosy][bosx]=git[bosy][bosx-1];
	git[bosy][bosx-1]=0;
	return 1;
      }
      break;
    case 1:
      if (bosx<n-1)
      {
	git[bosy][bosx]=git[bosy][bosx+1];
	git[bosy][bosx+1]=0;
	return 1;
      }
      break;
    case 2:
      if (bosy>0)
      {
	git[bosy][bosx]=git[bosy-1][bosx];
	git[bosy-1][bosx]=0;
	return 1;
      }
      break;
    case 3:
      if (bosy<n-1)
      {
	git[bosy][bosx]=git[bosy+1][bosx];
	git[bosy+1][bosx]=0;
	return 1;
      }
      break;
  }
  return 0;
}

int main()
{
  srand(time(NULL));
  FILE *f=fopen("8puzzle.rnd","w");
  int i,j;

  for (i=0; i<MAX; ++i) hamle(rand()%4);
  for (i=0; i<n; ++i)
  {
    for (j=0; j<n; ++j)
      fprintf(f,"%d ",git[i][j]);
    fprintf(f,"\n");
  }
  fclose(f);
}
