#include<stdio.h>
#include<array>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
//wpisanie 20 pansw, posortowanie alfabetyczne w grupach, grpa mistrzowska powstanie z pierwszych miejsc w innych grupach

int main()
{
    std::cout<<"podaj 20 panstw: ";
  std::array<std::array<std::string,4>,5>grupa; // utworzenie tablicy dwuwymiarowej

  for(int i=0;i<grupa.size();i++) // wczytanie panstw
      {

        std::cout<<std::endl;
        //system("clear");
        for(int j=0;j<grupa[i].size();j++)
        {
          std::cin>>grupa[i][j];
        //  system("clear");
        }
      }


  for(int i=0;i<grupa.size();i++)
  {
  std::sort(begin(grupa[i]), end(grupa[i]));  //sortowanie
  }
  for(int i=0;i<grupa.size();i++)
  {
    std::cout<<std::endl;
    std::cout<<"grupa nr : "<<i+1;
    std::cout<<std::endl;
    for(int j=0;j<grupa[i].size();j++)
    {
      std::cout<<grupa[i][j];
      std::cout<<std::endl;
    }
  }

  std::array<std::string, grupa.size()>mistrzowie; //utworzenie nowej tablicy
  std::cout<<std::endl;
  std::cout<<"Grupa mistrzowska : ";

  std::cout<<std::endl;

  for(int i=0; i<grupa.size() ;i++)
  {

    mistrzowie[0] = grupa[i][0];
    std::cout<<mistrzowie[0];
    std::cout<<std::endl;
  }



  return 0;
}
