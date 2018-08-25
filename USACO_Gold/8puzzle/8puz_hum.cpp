// Final State
// 1 2 3
// 8 0 4
// 7 6 5

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define n 3
#define max_stc 3000
#define max_dpt 150

int mat[n][n],stc[max_stc][n][n],stop,bul[4],depth,hal[max_stc];

void doku(void)
{
  FILE *f;
  int i,j;

  f=fopen("8puzzle.in","r");

  for (i=0; i<n; ++i)
    for (j=0; j<n; ++j)
      fscanf(f,"%d",&mat[i][j]);
  fclose(f);
}

// Final state ulasilmissa
int dogru(int num)
{
  int i;

  switch (num)
  {
    case 0:
      if (mat[2][0]==7 && mat[2][1]==6 && mat[2][2]==5)
	return 1;
      break;
    case 1:
      if (mat[0][2]==3 && mat[1][2]==4)
	return 1;
      break;
    case 2:
      if (mat[0][1]==2 && mat[1][1]==0)
	return 1;
      break;
    case 3:
      if (mat[0][0]==1 && mat[1][0]==8)
	return 1;
      break;
  }
  return 0;
}

void dyaz(void)
{
  int i,j,k;

  for (k=0; k<3; ++k)
    if (!bul[k] || !dogru(3))
    {
      printf("Cozum yok!");
      exit(0);
    }

  for (k=0; k<stop; ++k)
  {
    for (i=0; i<n; ++i)
    {
      for (j=0; j<n; ++j)
	printf("%d ",stc[k][i][j]);
      printf("\n");
    }
    if (hal[k]) printf("Hallettim!\n");
    printf("\n");
    getch();
  }
  printf("Toplam %d hamle!",stop);
}

// sira ile hamle
int hamle(int num,int no)
{
  int i,j,bosy,bosx;

  for (i=0; i<n; ++i)
    for (j=0; j<n; ++j)
      if (!mat[i][j]) bosy=i,bosx=j;

  switch (no)
  {
    case 0:
      if (bosx>0)
      {
	mat[bosy][bosx]=mat[bosy][bosx-1];
	mat[bosy][bosx-1]=0;
	return 1;
      }
      break;
    case 1:
      if (bosx<n-1 && (bosx!=1 || num<2))
      {
	mat[bosy][bosx]=mat[bosy][bosx+1];
	mat[bosy][bosx+1]=0;
	return 1;
      }
      break;
    case 2:
      if (bosy>0)
      {
	mat[bosy][bosx]=mat[bosy-1][bosx];
	mat[bosy-1][bosx]=0;
	return 1;
      }
      break;
    case 3:
      if (bosy<n-1 && (bosy!=1 || num==0))
      {
	mat[bosy][bosx]=mat[bosy+1][bosx];
	mat[bosy+1][bosx]=0;
	return 1;
      }
      break;
  }
  return 0;
}

// Daha once gidilip gidilmedigi
int ara(void)
{
  int i,j,k,t;

  for (k=0; k<stop; ++k)
  {
    for (i=0,t=1; i<n; ++i)
      for (j=0; j<n; ++j)
	if (stc[k][i][j]!=mat[i][j])
	{
	  t=0;
	  break;
	}
    if (t) return 1;
  }
  return 0;
}

// Her durumu tarama
void dfid(int num,int gir)
{
  int i,j,k,temp[n][n];

  if (stop>depth) return;

  if (!dogru(num))
  {

    for (i=0; i<n; ++i)
      for (j=0; j<n; ++j)
	stc[stop][i][j]=mat[i][j];
    ++stop;

    for (k=0; k<4; ++k)
    {
      if (hamle(num,k) && !ara()) dfid(num,gir+1);
      if (bul[num]) return;
      for (i=0; i<n; ++i)
	for (j=0; j<n; ++j)
	  mat[i][j]=stc[stop-1][i][j];
    }

    if (bul[num]) return;
    for (i=0; i<n; ++i)
      for (j=0; j<n; ++j)
	mat[i][j]=stc[stop-1][i][j];
    --stop;
  }
  else
    bul[num]=1;
}

int main()
{
  int i,j;

  doku();

  for (i=0; i<3; ++i)
  {
    for (depth=1; depth<max_dpt; ++depth)
      if (!bul[i]) dfid(i,0);
    hal[stop]=1;
  }

  for (i=0; i<n; ++i)
    for (j=0; j<n; ++j)
      stc[stop][i][j]=mat[i][j];
  ++stop;

  dyaz();
}
