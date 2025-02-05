/**
* @file G201210046
* @description Tek yönlü bağlı listeler kullanarak tam sayılar üzerinde çeşitli işlemler yapılması
* @course 1.Öğretim C Grubu
* @assignment 1.Ödev
* @date (25.11.2023 - 26.11.2023)
* @author Sefa AKTÜRK - sefa.akturk@ogr.sakarya.edu.tr
*/

#include "Sayi.hpp"
#include <iostream>
#include<iomanip>
using namespace std;

Sayi::Sayi()
{
    ilk=0;
}
Sayi::~Sayi()
{
    Basamak* gecici = ilk;

    while(gecici!=0)
    {
        Basamak* silinecek = gecici;

        gecici= gecici->sonraki;
        delete silinecek;
    }


}
void Sayi::ekle(int veri)
{
    Basamak* yeni = new Basamak(veri);
    if(ilk==0)
    {
        ilk = yeni;
        return;
    }
   
    Basamak* gecici = ilk;
    while(gecici->sonraki!=0)
        gecici= gecici->sonraki;
    gecici->sonraki = yeni;
}

int Sayi::veri()
{
    int veri=0;
    Basamak* gecici = ilk;
    bool geciciIlk=true;
    while(gecici!=0)
    {
        if(geciciIlk==true)
        {
            veri=gecici->veri ;
            geciciIlk=false;
        }else{
            veri=veri * 10 + gecici->veri;
        }      
        gecici= gecici->sonraki; 
    }
    return veri;
}

void Sayi::sirala()
{
    Basamak* tek = 0;
    Basamak* cift = 0;
    Basamak* tekKuyruk = 0;
    Basamak* ciftKuyruk = 0;

    Basamak* gecerli = ilk;

    while (gecerli != 0) {
            if (gecerli->veri % 2 != 0) {
                
                if (tek == 0) {
                    tek = gecerli;
                    tekKuyruk = gecerli;
                } else {
                    tekKuyruk->sonraki = gecerli;
                    tekKuyruk = gecerli;
                }
            } else {
               
                if (cift == 0) {
                    cift = gecerli;
                    ciftKuyruk = gecerli;
                } else {
                    ciftKuyruk->sonraki = gecerli;
                    ciftKuyruk = gecerli;
                }
            }
            gecerli = gecerli->sonraki;
        }

        if (tek != 0) {
            ilk = tek;
            tekKuyruk->sonraki = cift;
        } else {
            ilk = cift;
        }

        if (ciftKuyruk != 0) {
            ciftKuyruk->sonraki = 0; 
        }
    
}

void Sayi::tersle()
{
     Basamak* gecerli = ilk;
     Basamak* sonraki = 0;
     Basamak* onceki = 0;

     while (gecerli!=0)
     {
        sonraki = gecerli->sonraki;
        gecerli->sonraki=onceki;
        onceki = gecerli;
        gecerli = sonraki;
     }
     ilk = onceki;
     
}