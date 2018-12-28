#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include<time.h>

int mokh[4]={0};

COORD coord={0,0};
void gotoxy(int x,int y)
 {
   coord.X=x;
 coord.Y=y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

 void drawsen(int disknum)
 {
     int n,x,y;
     for(x=20;x<=60;x+=20)
     {
         for(y=10;y<=20;y++)
         {
   
            gotoxy(x,y);
            printf(".");
         }
         
         gotoxy(x,y);
         printf("_");
     }
     for(n=disknum;n>0;n--)
     {
         gotoxy(20-n,20-(disknum-n));
         drawdisk(n);
     }

 }

 void move_disk(int topNum,int start,int f)
 {
  int i,j,k,r;
  for(i=21-mokh[start];i>10;i--)
  {
    delay(20);
    gotoxy(start*20-topNum,i);
    erased(topNum);
    gotoxy(start*20-topNum,i-1);
    drawdisk(topNum);
  }
  delay(20);
  gotoxy(start*20-topNum,i);
  erased(topNum);
  mokh[start]--;
  if(start<f)
  {  
    for(k=start*20-topNum;k<=f*20-topNum;k++)
    {
        gotoxy(k,9);
        drawdisk(topNum);
        delay(20);
        gotoxy(k,9);
        disapdisk(topNum);
    }
  }
  else
  {
    for(r=start*20-topNum;r>=f*20-topNum;r--)
    {
        gotoxy(r,9);
        drawdisk(topNum);
        delay(20);
        gotoxy(r,9);
        disapdisk(topNum);
    }
  }
  for(j=10;j<20-mokh[f];j++)
  {
    gotoxy(f*20-topNum,j);
    drawdisk(topNum);
    delay(20);
    gotoxy(f*20-topNum,j);
    erased(topNum);
    }
  gotoxy(f*20-topNum,j);  
  drawdisk(topNum);
  mokh[f]++;
 }

void hanoi(int topNum,int source,int aux,int dest) 
{
  if(topNum == 1)

  {  
    move_disk(topNum,source,dest);
  }
  else
  {  
    hanoi(topNum-1,source,dest,aux);
    move_disk(topNum,source,dest);
    hanoi(topNum-1,aux,source,dest);
  }
}

 void drawdisk(int disknum)
 {
     int x=0;
    for( x=0;x<disknum*2+1;x++)
    {
      printf("*");
    }
 }
 void erased(int disknum)
  {int x=0;
    for( x=0;x<disknum*2+1;x++)
    {
      if(x==disknum)
      printf(".");
    else
    printf(" ");
    }
 }

  void disapdisk(int disknum)
  {int x=0;
    for( x=0;x<disknum*2+1;x++)
    {
      printf(" ");
    }
 }
int main()
{
int disknum;
do{
scanf("%d",&disknum);
  
}while(disknum<3 | disknum>9);

mokh[1]=disknum;
drawsen(disknum);
hanoi(disknum,1,2,3);
getch();
return 0;
}