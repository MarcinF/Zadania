#include<stdio.h>
#include<iostream>
#include<array>
#include<time.h>
#include<unistd.h>

//losowy wybor liczb


int main()
{
  int w,los;
  int tab[w];
 srand(time(NULL));

std::cout<<"podaj wielkosc tablicy :";
std::cin>>w;


for(int i =0; i<w; i++)
{
  tab[i]=rand()%100+1;;
  sleep(2);
  std::cout<<i+1<<"."<<tab[i]<<std::endl;
}

for(int i=0; i<w; i++)
{
  if(tab[0]<tab[i])
  {
    tab[0]=tab[i];
  }
}

std::cout<<"najwieksza liczba to : "<<tab[0]<<std::endl;

  return 0;
}
