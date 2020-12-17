#include <iostream>
#include <cstdlib>
#include <ctime>
//#include <windows.h>
#include <vector>
using namespace std;
//Counting with natural number
int main()
{
unsigned int dl=1; int dolna=0; int dgorna=0;
//HANDLE hOut = GetStdHandle( STD_OUTPUT_HANDLE );
//SetConsoleTextAttribute( hOut, 0x008 );system("cls");
srand( time( NULL ) ); //random set
bool losowanie =true; // set randomization
bool kolejne=true; unsigned long int Petla=1;
std ::vector <unsigned int> P;
for (int y=0;y<=dl+3;y++){P.push_back(0);}
std::vector<unsigned int> Lp; //Lp number
int wskaznik=0;int D=0;unsigned int s=0,i=0;
unsigned long int pozycjaLp=0;// position in Lp number
std::cout<<"\n Random\n";
do{//-------------------------Next position----------------
if (losowanie)// Randomization
{ int zakres=10; int ilosc=10, a=0;
int cyfry[zakres+1],tablosowa[ilosc+1];
do{
zakres=10;
for (i=0; i<zakres; i++)
{ cyfry[i]=i;}//set of ten digit
for (i=0; i<ilosc; i++)
{ a=(rand()%zakres);
tablosowa[i]=cyfry[a];
cyfry[a]=cyfry[zakres-1];zakres--;
Lp.push_back( tablosowa[i]);
pozycjaLp++;
}
}while(pozycjaLp<=(dl*10));
}//--------------------------------------------------------------
//SetConsoleTextAttribute( hOut, 0x007 );
std::cout<<"\n----------------------------------------------------------------------------\n";
std::cout<<" Lp= ";// print an auxilary Ln number
s=0;
for(i=0;i<(dl*10);i++)
{ if (!(i%10)&&(i>0)){std::cout<<"'";s=0;}
if (!losowanie){Lp.push_back( s);} // put number Lp as set of ten digit 0-9
s++;std::cout<< Lp[i];
}
//std::cout<<"\n";SetConsoleTextAttribute( hOut, 0x008 );
//change the last colour of new digit in previous counted number digit
// ---------------------Start Algoritm---------------------------------- ;
for(i=1;i<=dl+2;i++){P[i]=0;}
do{
do{
//SetConsoleTextAttribute( hOut, 0x008 );
bool pominzero =true;//ommit the last zero
if ((P[dl]>=1)&&(dl>1)){ SetConsoleTextAttribute( hOut, 0x007 );}//change
the colour for new counted Real numbers
std::cout << "\n A(";
for(i=dl;i>=1;i--){
if ((!P[i])&&(pominzero==true)&&(!(i==1))) {continue;}
std::cout<< P[i];
pominzero=false;
}
std::cout <<") 0,"<<Lp[P[1]];//-----------------------------Print digit---------------
for (D=2;D<=dl;D++)//loop for next digit
{ wskaznik= ((P[D]+P[1])%10)+(D-1)*10; //shift ten times
if (D==dl){ SetConsoleTextAttribute( hOut, 0x007 );}
std::cout<<Lp[wskaznik]; //print next real number
}
std::cout<<"..";
SetConsoleTextAttribute( hOut, 0x008 );
P[Petla]++;
}while (P[Petla]<10);
do
{
Petla++; P[Petla]++;P[Petla-1]=0;
}while (P[Petla]==10);
Petla=1;
} while (P[dl+1]!=1);
dl++;//next digit
P.push_back(0); //save table with 0 at the end
}while((dl<=dgorna)||(kolejne));
//------------------End Algoritm----------------------------------
// Works until limits of memory
}
