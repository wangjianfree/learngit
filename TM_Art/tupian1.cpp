#include <iostream>
#include<stdio.h>
#include<cmath>
#include<cstdlib>
#define DIM 1024
#define DM1 (DIM-1)
#define _sq(x) ((x)*(x))
#define _cb(x) abs((x)*(x)*(x))
#define _cr(x) (unsigned char)(pow((x),1.0/3.0))
unsigned char GR(int,int);
unsigned char BL(int,int);
unsigned char RD(int i,int j){
//return (char)(_sq(cos(atan2(j-512,i-512)/2))*255);
/*#define r(n)(rand()%n)
static char c[1024][1024];
return !c[i][j]?c[i][j]=!r(999)?r(256):RD((i+r(2))%1024,(j+r(2))%1024):c[i][j];*/
/*float x=0,y=0;
int k;
for (k=0;k++<256;){
  float a=x*x-y*y+(i-768.0)/512;
	y=2*x*y+(j-512.0)/512;
	x=a;
	if(x*x+y*y>4) break;
}
return log(k)*47;*/
}
unsigned char GR(int i,int j){
//return (char)(_sq(cos(atan2(j-512,i-512)/2-2*acos(-1)/3))*255);
/*static char c[1024][1024];
return !c[i][j]?c[i][j]=!r(999)?r(256):GR((i+r(2))%1024,(j+r(2))%1024):c[i][j];*/
/*float x=0,y=0;
int k;
for (k=0;k++<256;){
  float a=x*x-y*y+(i-768.0)/512;
	y=2*x*y+(j-512.0)/512;
	x=a;
	if(x*x+y*y>4) break;
}
return log(k)*47;*/
}
unsigned char BL(int i,int j){
//return (char)(_sq(cos(atan2(j-512,i-512)/2+2*acos(-1)/3))*255);
/*static char c[1024][1024];
return !c[i][j]?c[i][j]=!r(999)?r(256):BL((i+r(2))%1024,(j+r(2))%1024):c[i][j];*/
/*float x=0,y=0;
int k;
for (k=0;k++<256;){
  float a=x*x-y*y+(i-768.0)/512;
	y=2*x*y+(j-512.0)/512;
	x=a;
	if(x*x+y*y>4) break;
}
return log(k)*47;*/
}
void pixel_write(int,int);
FILE *fp;
int main(){
fp=fopen("MathPic2.ppm","wb");
fprintf(fp,"P6\n%d %d\n255\n",DIM,DIM);
for(int j=0;j<DIM;j++)
	for(int i=0;i<DIM;i++)
		pixel_write(i,j);
fclose(fp);
return 0;
}
void pixel_write(int i,int j){
static unsigned char color[3];
color[0]=RD(i,j)&255;
color[1]=GR(i,j)&255;
color[2]=BL(i,j)&255;
fwrite(color,1,3,fp);
}
