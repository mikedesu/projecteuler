#include <stdio.h>
int m[80][80],p[80][80];
int f(int i,int j){
  int v=0,a=0,b=0;
  if(i==79&&j==79)
    p[i][j]=m[i][j];
  else if(j==79)
    p[i][j]=p[i][j]?p[i][j]:m[i][j]+f(i+1,j);
  else if(i==79)
    p[i][j]=p[i][j]?p[i][j]:m[i][j]+f(i,j+1);
  else{
    if(!p[i][j]){
      a=f(i,j+1);
      b=f(i+1,j);
      p[i][j]=(a<b)*a+(a>=b)*b+m[i][j];
    }
  }
  return p[i][j];
}
void main(){
  FILE *a=fopen("matrix.txt","r");
  for(int i = 0;i<80;i++)
    for(int j=0;j<80;j++)
      fscanf(a,"%d",&m[i][j]);
  printf("%d",f(0, 0));
}
