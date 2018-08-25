// 8-puzzle (A* ile)
// + HASHing

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define ESITLE(m1,m2) for (p=0; p<3; ++p) for (r=0; r<3; ++r) m1[p][r]=m2[p][r]
#define max_stc 5000
#define DMAX 365000
#define BOS 250

const int HASH=max_stc/(BOS+1);
const int don[9][2]={{0,0},{0,1},{0,2},{1,2},{2,2},{2,1},{2,0},{1,0},{0,0}};

int que[max_stc][3][3],bas[3][3],son[3][3],git[3][3],tmp[3][3];
unsigned char drm[DMAX];
int baba[max_stc],dpt[max_stc],olu[max_stc],hes[max_stc],last,btut;
int p,r,exp_node,lpath,yerx[3*3],yery[3*3];

void doku(void)
{
  FILE *f;
  long i,j;

  f=fopen("8puzzle.in","r");

  for (i=0; i<3; ++i)
    for (j=0; j<3; ++j)
      fscanf(f,"%d",&git[i][j]);

  for (i=0; i<3; ++i)
    for (j=0; j<3; ++j)
      fscanf(f,"%d",&son[i][j]);

  fclose(f);

  ESITLE(bas,git);
  for (i=0; i<3; ++i)
    for (j=0; j<3; ++j)
      yery[son[i][j]]=i,yerx[son[i][j]]=j;
  for (i=0; i<DMAX; ++i) drm[i]=BOS;
}

void rec_yaz(int k)
{
  int i,j;

  if (k>0) rec_yaz(baba[k]);
  ++lpath;
  for (i=0; i<3; ++i)
  {
    for (j=0; j<3; ++j)
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
  for (p=0; p<3; ++p)
    for (r=0; r<3; ++r)
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
      if (bosx<2)
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
      if (bosy<2)
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
  int h=0,s=0;

  // Manhattan distance
  for (p=0; p<3; ++p)
    for (r=0; r<3; ++r)
      if (que[x][p][r])
	h=h+abs(yery[que[x][p][r]]-p)+abs(yerx[que[x][p][r]]-r);

  // s(n): square score => check around the noncentral squares in turn,
  // assign 2 for every tile not followed by its proper successor and
  // add 1 if there is a tile in center {not admissible}
  for (p=0; p<8; ++p)
    if (que[x][don[p][0]][don[p][1]])
      for (r=0; r<8; ++r)
	if (que[x][don[p][0]][don[p][1]]==son[don[r][0]][don[r][1]])
	  if (que[x][don[p+1][0]][don[p+1][1]]!=son[don[r+1][0]][don[r+1][1]]) s+=2;
  if (que[x][1][1]) ++s;
  return h;+3*s;
}

// tablo hash degeri hesaplama
const long fak[8]={1,2,6,24,120,720,5040,40320};
long mat_hes()
{
  int sira;
  long tp=0;
  // kombinasyon sirasini bul
  for (p=7; p>=0; tp+=(long)sira*fak[7-p],--p)
    for (sira=0,r=p+1; r<9; ++r) if ((*git)[p]>(*git)[r]) ++sira;
  return tp;
}

// tablo arama fonksiyonu
long varmi;
int ara()
{
  int k,t,mh=((int)drm[varmi]+1)*HASH;

  for (p=(int)drm[varmi]*HASH; p<last && p<mh; ++p)
  {
    for (r=0,t=1; r<3; ++r)
    {
      for (k=0; k<3; ++k)
	if (git[r][k]!=que[p][r][k])
	{
	  t=0;
	  break;
	}
      if (!t) break;
    }
    if (t) return p;
  }
  return -1;
}

// OPEN & CLOSE queue
void ekle()
{
  ESITLE(que[last],git);
  baba[last]=btut,drm[varmi]=last/HASH,hes[last]=hesap(last),dpt[last++]=dpt[btut]+1;
}

// A star ile tarama
void a_star()
{
  int i,j,minf=20000,yer=0,var;

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
      varmi=mat_hes();
      if (drm[varmi]!=BOS)
      {
	var=ara();
	if (baba[var]>btut) olu[var]=0,baba[var]=btut;
      }
      else ekle();
    }
    ESITLE(git,tmp);
  }
}

void tara(void)
{
  btut=-1,varmi=mat_hes();
  ekle();
  while (1==1)
  {
    a_star();
//    printf("%d",last);
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
