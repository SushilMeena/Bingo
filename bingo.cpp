#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include<conio.h>
using namespace std;
int getRandom();
class Bingo{
     int A[5][5],B[5][5],bingo[5][5];
    public:
    int bingooA,bingooB;
         Bingo(){
        int i,j,t=0,list[25];
        srand(time(0));
           fillMat(A);
           fillMat(B);
        for(i=0;i<25;i++)
           list[i]=i+1;
     for(i=0;i<5;i++)
        for(j=0;j<5;j++){
           bingo[i][j]=list[t];
            t++;
            }
       Display();
        }

  bool isExists(int x[][5],int);
  void cancel(int);
  void fillMat(int Y[][5]);
  void Display();
  void isFull();
  void rowFull(int row){
       int a=0,b=0,j;
    for(j=0;j<5;j++){
       if(A[row][j]==0)
            a++;
       if(B[row][j]==0)
            b++;
    if(a==5)  bingooA++;
        if(b==5) bingooB++;
    }
}
   void colFull(int col){
      int at=0,bt=0,i;
    for(i=0;i<5;i++){
       if(A[i][col]==0)
            at++;
       if(B[i][col]==0)
            bt++;
    if(at==5)  bingooA++;
        if(bt==5) bingooB++;
    }
 }
   void digFull(){
        int x=0,y=0,i;
      for(i=0;i<5;i++){
          if(A[i][i]==0) x++;
          if(B[i][i]==0) y++;
        if(x==5)  bingooA++;
        if(y==5) bingooB++;
            }
    }

};
int main() // main() func
{

    int i,op;
    Bingo b2;
    b2.bingooA=b2.bingooB=0;
    for(i=1;i<625;i++){
       if(i%2==0)
        {cout<<"\t*Player AI choice*"<<endl; op=getRandom();}
        else
        {cout<<"\t*Player 1 choice*"<<endl;
   cout<<"Enter any number from 1 to 25 cut: ";
    cin>>op;}
       b2.cancel(op);
       b2.Display();
       b2.isFull();
      cout<<"val: "<<b2.bingooA<<b2.bingooB;
       if(b2.bingooA>4){
    cout<<"\t BINGO! Player A wins!\n";
        break;}
       if(b2.bingooB>4){
    cout<<"\t BINGO! Player B wins!\n";
            break; }
 }


    return 0;
}
bool Bingo::isExists(int x[][5],int key)  //functtion
{
    int i,j,count=0;
     for(i=0;i<5;i++)
       for(j=0;j<5;j++)
         if(key==x[i][j])
           count++;
    if(count==0)
       return false;
    else return true;
}
int getRandom(){
    return 1+((rand())%25);
}
void Bingo::cancel(int key){
    int i,j;
  if(isExists(bingo,key)){

  if(isExists(A,key)||isExists(B,key)){
    for(i=0;i<5;i++)
      for(j=0;j<5;j++){
        if(A[i][j]==key){
           A[i][j]=0;
           }
       if(B[i][j]==key){
            B[i][j]=0;
        }
      if(bingo[i][j]==key){
            bingo[i][j]=0;
        }
   }
}

}
}
void Bingo::fillMat(int Y[][5]){
   int i,j;

    for(i=0;i<5;i++)
      for(j=0;j<5;j++){
         Y[i][j]=0;
      while(Y[i][j]==0){
    int temp=getRandom();
        if(!isExists(Y,temp)){
            Y[i][j]=temp;
        }
     }
}
}
void Bingo::isFull(){
    bingooA=0;
    bingooB=0;
     for(int i=0;i<5;i++)
         rowFull(i);
     for(int j=0;j<5;j++)
         colFull(j);
     digFull();
}
void Bingo::Display(){
    int i,j; system("CLS");
     cout<<"Player 1 matrix is:\n "<<endl;
    for(i=0;i<5;i++){
      for(j=0;j<5;j++)
        cout<<setw(2)<<A[i][j]<<"   ";
      cout<<endl;
   }
   cout<<"\n\n\n\n\n";
 cout<<"Player 2 matrix is: \n"<<endl;
    for(i=0;i<5;i++){
      for(j=0;j<5;j++)
        cout<<setw(2)<<B[i][j]<<"   ";
      cout<<endl;
   }
cout<<"\n\n\n\n\n";

}
