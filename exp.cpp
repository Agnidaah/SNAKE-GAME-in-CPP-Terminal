#include<iostream>
#include<windows.h>
#include<string.h>
#include<ctime>
#include <pthread.h>
#include<conio.h>
#include <cstdlib>
using namespace std; 
class Test{public:
int speed=10;int l=1;int *x=new int[l];int *y=new int[l];
int fruitx=50,fruity=15;char dir='d';int facex=49,facey=15,tailx=49,taily=15;
char a[30][100];
Test(){for(int i=0;i<30;i++){
   for(int j=0;j<100;j++){
      if(i==0||j==0||j==99||i==29){
      a[i][j]='O';}
      else{
         a[i][j]=' ';
      }}}a[fruity][fruitx]='0';x[0]=49;y[0]=15;a[y[0]][x[0]]='o';
   }
void status(){for(int i=0;i<30;i++){
   for(int j=0;j<100;j++){
      cout<<a[i][j];
   }cout<<endl;
}}
boolean turner(){
switch(dir){
case 'd':
   facex++;
   break;
case 'a':
   facex--;
   break;
case 'w':
   facey--;
   break;
case 's':
   facey++;
   break;
}
if(a[facey][facex]=='O' || a[facey][facex]=='o'){
    return true;
}else{return false;}
}
void runner(){
   a[facey][facex]='o';
   if(fruitx!=facex || fruity!=facey){
      a[taily][tailx]=' ';int tempx=x[0];int tempy=y[0];x[0]=facex;y[0]=facey;
      for(int i=1;i<l;i++){
         int temx=x[i];int temy=y[i];
         x[i]=tempx;y[i]=tempy;
         tempx=temx;tempy=temy;
      }tailx=x[l-1];taily=y[l-1];
   }else{
       l++;int xx[l];int yy[l];xx[0]=facex;yy[0]=facey;
   for(int i=0;i<l-1;i++){
      xx[i+1]=x[i];yy[i+1]=y[i];
   }
   x=new int[l];y=new int[l];
   for(int i=0;i<l;i++){
      x[i]=xx[i];y[i]=yy[i];
   }
   while(true){
       //srand((unsigned) time(0));
      fruitx= 4 + (rand() % 90);
      fruity=(rand() % 24)+2;
      if(a[fruity][fruitx]!='o'){a[fruity][fruitx]='0';
         break;
      }}}}
char get_char(){ 
    clock_t time_req;
	time_req = clock(); //start the clock 
	while(!kbhit()){ 
		/*compare the clock with current time, if it exceeds return -1;*/ 
		if(speed<clock() - time_req)  
			return dir; 
	} 
	//else return the value stored in keyboard buffer. 
	return getch(); 
} };
int main(){
system("color 64");
      Test t;
         while(true){
    system("cls");
      t.status();
      if(t.turner()){system("cls");cout<<"GAME OVER!!";
          break;
      }
      t.runner();char c=t.dir;
      t.dir=t.get_char();
      if((t.dir!='w'&&t.dir!='a'&&t.dir!='s'&&t.dir!='d')||(t.dir=='a'&&c=='d')||(t.dir=='w'&&c=='s')||(t.dir=='s'&&c=='w')||(t.dir=='d'&&c=='a')){t.dir=c;}}
      return 0;}
