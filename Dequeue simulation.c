#include<conio.h>
#include<graphics.h>
#include<ctype.h>
#include<dos.h>
#include<string.h>
#include<stdio.h>

//functions
void graphicspointer(int);
void showindex(void);
void graphicsinsertrear(int);
void graphicsinsertfront(int);
void graphicsdeletrear(int);
void graphicsdeletfront(int);
void graphicsboxmax(int);
void graphicsdefault(void);
char title[50];
int f=0,r=-1,max,ele,j=0,d=0,i,p,flag;
int dq[100];
void insertfront(void);
void insertrear(void);
void deletfront(void);
void deletrear(void);
void main()
{

int gd=DETECT,gm,l,p;
initgraph (&gd,&gm, "C:\\TURBOC3\\BGI");
cleardevice();
settextstyle(0,0,0);
setbkcolor(0);
strcpy(title,"DEQUEUE SIMULATION");
gotoxy(30,2);
printf("%s",title);
printf("\n\n\nEnter the maximum number of elements-\n");
scanf("%d",&max);
cleardevice();
graphicsdefault();
}
void graphicsdefault(void)
{
strcpy(title,"DEQUEUE SIMULATION");
gotoxy(30,2);
printf("%s",title);
printf("\n\nHere's your Deueue\n");
graphicsboxmax(max);
graphicspointer(max);
setcolor(15);
printf("\nOperations : 1.Insertfront    2.insertrear   3.deletfront  4.deletrear 5.Exit\n\n\n\n\n\n\n\n");
do
{
setfillstyle(SOLID_FILL,0);
bar(0,192,1000,800);
scanf("%d",&p);
switch(p)
{
case 1: if(f!=0)
{
insertfront();
}
else
{
  printf("insertfront not feasible\n");
  getch();
}
break;
case 2:if(r>=max-1)
{
printf("insertion from rear not possible as queue is full\n");
}
else
{
  insertrear();
getch();
}
break;
case 3: if(r!=-1)
	    deletfront();
      else
	{
	  printf("deletion from front not possible\n");
	  sleep(2);
	}
  break;
case 4:  if(r!=-1)
	     deletrear();
	else
	{
	   printf("deletion from rear not possible\n");
	  sleep(2);
	}
	 break;
case 5: break;
}
}while(p!=5);
}
void graphicsboxmax(int n)
{
int i,x1;
x1=0;
for(i=1;i<=n;i++)
{
rectangle(x1,150,x1+60,180);
x1=x1+60;
}
}

void graphicspointer(int n)
{
int i,x1;
x1=0;
for(i=1;i<=n;i++)
{
setcolor(0);
rectangle(x1,130,x1+60,140);
x1=x1+60;
}
x1=0;
for(i=1;i<=n;i++)
{
setcolor(0);
rectangle(x1,120,x1+60,130);
x1=x1+60;
}
}
void insertfront(void)
{
printf("Enter the element to insert: ");
scanf("%d",&ele);
f=f-1;
dq[f]=ele;
graphicsinsertfront(ele);
sleep(3);
graphicsdefault();
}
void graphicsinsertfront(int a)
{
  sprintf(title,"%d",a);
setfillstyle(SOLID_FILL,d);
bar(60*(d-1),151,60*(d)-1,179);
outtextxy(30+60*(d-1),160,title);
 outtextxy(30+60*(d-1),124,"f");
  setfillstyle(SOLID_FILL,0);
  bar(60*d,121,60*(d+1),129);
d=d-1;
}
void insertrear(void)

{
  printf("Enter the element to insert: ");
scanf("%d",&ele);
 r=r+1;
 dq[r]=ele;
 graphicsinsertrear(ele);
sleep(3);
graphicsdefault();
}
void graphicsinsertrear(int a)
{
sprintf(title,"%d",a);
setfillstyle(SOLID_FILL,j+1);
bar(60*j+1,151,60*(j+1)-1,179);
outtextxy(30+60*j,160,title);
showindex();
if(f==0&&r!=max)
{
  outtextxy(30+60*d,124,"f");
  setfillstyle(SOLID_FILL,0);
bar(60*(d-1)+1,121,60*d,129);
setfillstyle(SOLID_FILL,0);
bar(60*(j-1)+1,131,60*j,139);
//rear pointer
outtextxy(30+60*j,134,"r");
}
j=j+1;
}
void showindex(void)
{
sprintf(title,"%d",j);
outtextxy(30+60*j,185,title);
}
void deletfront(void)
{
   int x;
   flag=r+f;
   if(f==r)
   {
x=dq[f];
f=0;
r=-1;
   }
   else
   {
x=dq[f];
f=(f+1);
   }
   graphicsdeletfront(x);
   graphicsdefault();
}
void graphicsdeletfront(int x)
{
  setfillstyle(SOLID_FILL,0);
  bar(60*d+1,151,60*(d+1)-1,179);
      outtextxy(30+60*(d+1),124,"f");
       setfillstyle(SOLID_FILL,0);
  bar(60*d,121,60*(d+1),129);
  d=d+1;
   printf("%d is deleted\n(Enter any key to continue)\n",x);
  getch();
}
void deletrear(void)
{
   int x;
   flag=r+f;
   if(f==r)
   {
x=dq[f];
f=0;
r=-1;
   }
   else
   {
x=dq[r];
r=(r-1);
   }
   graphicsdeletrear(x);
   graphicsdefault();
}
void graphicsdeletrear(int x)
{
  setfillstyle(SOLID_FILL,0);
     bar(60*(j-1),151,60*j,179);
       outtextxy(30+60*(j-2),134,"r");
      j=j-1;
	setfillstyle(SOLID_FILL,0);
      bar(60*(j),131,60*(j+1),139);
   printf("%d is deleted\n(Enter any key to continue)\n",x);
  getch();
}

