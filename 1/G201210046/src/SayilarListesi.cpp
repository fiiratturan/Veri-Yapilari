/**
* @file G201210046
* @description Tek yönlü bağlı listeler kullanarak tam sayılar üzerinde çeşitli işlemler yapılması
* @course 1.Öğretim C Grubu
* @assignment 1.Ödev
* @date (25.11.2023 - 26.11.2023)
* @author Sefa AKTÜRK - sefa.akturk@ogr.sakarya.edu.tr
*/

#include "SayilarListesi.hpp"
#include <iostream>
#include<iomanip>
SayilarListesi::SayilarListesi()
{
    ilk=0;
}
SayilarListesi::~SayilarListesi()
{
    Dugum* gecici = ilk;

    while(gecici!=0)
    {
        Dugum* silinecek = gecici;

        gecici= gecici->sonraki;
        delete silinecek;
    }


}
void SayilarListesi::ekle(Sayi* veri)
{
    Dugum* yeni = new Dugum(veri);
    if(ilk==0)
    {
        ilk = yeni;
        return;
    }
   
    Dugum* gecici = ilk;
    while(gecici->sonraki!=0)
        gecici= gecici->sonraki;
    gecici->sonraki = yeni;
}
void SayilarListesi::yazdir()
{
    using namespace std;
    Dugum* geciciD = ilk;
    Basamak* geciciB;
   
    while (geciciD!=0)
    {  
        geciciB = geciciD->veri->ilk;  
        cout<<"###########"<<"  ";
        while (geciciB!=0)
        {
            cout<<"*******"<<" ";
            geciciB= geciciB->sonraki; 
        }
        cout<<endl;
        geciciB = geciciD->veri->ilk;

        cout<<"#"<<setw(9)<<geciciD<<"#"<<"  ";
        while (geciciB!=0)
        {
            cout<<"*"<<setw(5)<<geciciB->sonUcBasamak()<<"*"<<" ";
            geciciB= geciciB->sonraki; 
        }
        cout<<endl;
        geciciB = geciciD->veri->ilk;

        cout<<"#---------#"<<"  ";
        while (geciciB!=0)
        {
            cout<<"*******"<<" ";
            geciciB= geciciB->sonraki; 
        }
        cout<<endl;
        geciciB = geciciD->veri->ilk;

        cout<<"#"<<setw(9)<<geciciD->veri->veri()<<"#"<<"  ";
        while (geciciB!=0)
        {
            cout<<"*"<<setw(5)<<geciciB->veri<<"*"<<" ";
            geciciB= geciciB->sonraki; 
        }
        cout<<endl;
        geciciB = geciciD->veri->ilk;

        cout<<"###########"<<"  ";
        while (geciciB!=0)
        {
            cout<<"*******"<<" ";
            geciciB= geciciB->sonraki; 
        }
        cout<<endl;
       
        cout<<endl;

        geciciD= geciciD->sonraki;
    }
          
}

void SayilarListesi::cikar()
{
    if(ilk==0)  return;

    Dugum* gecici = ilk;
    int enBuyuk = 0;

    while(gecici != 0 )
    {
        if(gecici->veri->veri() >= enBuyuk)
        {
            enBuyuk = gecici->veri->veri();
        }
        gecici=gecici->sonraki;
    }

    if(ilk->sonraki==0)
    {
        delete ilk;
        ilk=0;
    }
    else
    {
        Dugum* gecici = ilk;
        Dugum* geciciOnceki;

        

        while(gecici->veri->veri()!=enBuyuk)
        {
            geciciOnceki=gecici;
            gecici=gecici->sonraki;
        }

        if(gecici==ilk)
        {
            ilk=gecici->sonraki;
        }else{
            geciciOnceki->sonraki = gecici->sonraki;
            gecici->veri->~Sayi();
        }
        delete gecici;
        
    }


}

void SayilarListesi::sirala()
{
     Dugum* geciciD = ilk;

     while(geciciD!=0)
     {
        geciciD->veri->sirala();
        geciciD= geciciD->sonraki;
     }

     
}
void SayilarListesi::tersle()
{
     Dugum* geciciD = ilk;

     while(geciciD!=0)
     {
        geciciD->veri->tersle();
        geciciD= geciciD->sonraki;
     }

     
}