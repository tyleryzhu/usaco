// 8-puzzle (A* ile)

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

#define n 3
#define ESITLE(m1,m2) for (p=0; p<n; ++p) for (r=0; r<n; ++r) m1[p][r]=m2[p][r]
#define max_stc 6000

const int don[9][2]={{0,0},{0,1},{0,2},{1,2},{2,2},{2,1},{2,0},{1,0},{0,0}};

int que[max_stc][n][n],bas[n][n],son[n][n],git[n][n],tmp[n][n];
int baba[max_stc],dpt[max_stc],olu[max_stc],hes[max_stc],last,btut;
int p,r,exp_node,lpath,yerx[n*n],yery[n*n];

void doku(void)
{
  FILE *f;
  int i,j;

  f=fopen("8puzzle.in","r");

  for (i=0; i<n; ++i)
    for (j=0; j<n; ++j)
      fscanf(f,"%d",&git[i][j]);

  for (i=0; i<n; ++i)
    for (j=0; j<n; ++j)
      fscanf(f,"%d",&son[i][j]);

  fclose(f);

  ESITLE(bas,git);
  for (i=0; i<n; ++i)
    for (j=0; j<n; ++j)
      yery[son[i][j]]=i,yerx[son[i][j]]=j;
}

void rec_yaz(int k)
{
  int i,j;

  if (k>0) rec_yaz(baba[k]);
  ++lpath;
  for (i=0; i<n; ++i)
  {
    for (j=0; j<n; ++j)
      printf("%d ",que[k][i][j]);
    printf("\n");
  }
  printf("\n");
  getch();
}

void dyaz(int x)
{
  int i;

  rec_yaz(x);

  printf("Nodes Generated: %d\n",last);
  for (i=0; i<last; ++i)
    if (olu[i]) ++exp_node;

  printf("Nodes Expanded: %d\n",exp_node);
  printf("Length of path: %d\n",lpath-1);
  exit(0);
}

// Hamle
int hamle(int no)
{
  int bosx,bosy;

  // bosyer bul
  for (p=0; p<n; ++p)
    for (r=0; r<n; ++r)
      if (!git[p][r]) bosy=p,bosx=r;

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

// Heuristic hesap fonksiyonu
int hesap (int x)
{
  int i,j,h=0,s=0;

  // Manhattan distance
  for (i=0; i<n; ++i)
    for (j=0; j<n; ++j)
      if (que[x][i][j])
	h=h+abs(yery[que[x][i][j]]-i)+abs(yerx[que[x][i][j]]-j);

  // s(n): square score => check around the noncentral squares in turn,
  // assign 2 for every tile not followed by its proper successor and
  // add 1 if there is a tile in center {not admissible}
  for (i=0; i<n*n-1; ++i)
    if (que[x][don[i][0]][don[i][1]])
      for (j=0; j<n*n-1; ++j)
	if (que[x][don[i][0]][don[i][1]]==son[don[j][0]][don[j][1]])
	  if (que[x][don[i+1][0]][don[i+1][1]]!=son[don[j+1][0]][don[j+1][1]]) s+=2;
  if (que[x][n/2][n/2]) ++s;

  return h;+3*s;
}

int ara()
{
  int i,j,k,t;

  for (i=0; i<last; ++i)
  {
    for (j=0,t=1; j<n; ++j)
    {
      for (k=0; k<n; ++k)
	    if (git[j][k]!=que[i][j][k])
	    {
          t=0;
	      break;
	    }
	  if (!t) break;
    }
    if (t) return i;
  }
  return -1;
}

// OPEN & CLOSE queue
void ekle()
{
  ESITLE(que[last],git);
  baba[last]=btut;
  hes[last]=hesap(last);
  dpt[last++]=dpt[btut]+1;
}

// A star ile tarama
void a_star()
{
  int i,j,minf=10000,yer=0,varmi;

  for (i=0; i<last; ++i)
    if (!olu[i])
    {
      if (!hes[i]) dyaz(i);
      if (minf>hes[i]+dpt[i]) minf=hes[i]+dpt[i],yer=i;
    }

  ESITLE(git,que[yer]);
  ESITLE(tmp,git);
  btut=yer,olu[yer]=1;

  for (i=0; i<4; ++i)
  {
    if (hamle(i))
    {
      varmi=ara();
      if (varmi>=0)
      {
	if (baba[varmi]>btut)
	  olu[varmi]=0,baba[varmi]=btut;
      }
      else ekle();
    }
    ESITLE(git,tmp);
  }
}

void tara(void)
{
  btut=-1;
  ekle();
  while (1==1)
  {
    a_star();
//    printf("%d\n",last);
    if (last>=max_stc-4)
    {
      printf("\nnot enough memory!");
      exit(1);
    }
  }
}

int main()
{
  doku();
  tara();
}
