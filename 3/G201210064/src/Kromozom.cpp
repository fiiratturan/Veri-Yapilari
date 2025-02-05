/**
* @file G201210064
* @description Bu ödevde bağlı listeler kullanarak gen, kromozom ve DNA işlemleri yapılacaktır.
* @course 2.Ögretim A Grubu
* @assignment 1.Ödev
* @date (20.11.2024 - 25.11.2024)
* @author Necati Babacan- necati.babacan@ogr.sakarya.edu.tr
*/

#include "Kromozom.hpp"
#include <iostream>
#include<iomanip>

Kromozom::Kromozom()
{
    ilk=0;
}
Kromozom::~Kromozom()
{
    Dugum* gecici = ilk;

    while(gecici!=0)
    {
        Dugum* silinecek = gecici;

        gecici= gecici->sonraki;
        delete silinecek;
    }


}
void Kromozom::ekle(char veri)
{
    Dugum* yeni = new Dugum(veri);
    if(ilk==0)
    {
        ilk = yeni;
    }else
    {
        Dugum* gec = ilk;

        while(gec->sonraki!=0)
        {
            gec=gec->sonraki;
        }

        gec->sonraki = yeni;
        yeni->onceki = gec;
    }
}

int Kromozom::genSayisiToplam()
{
    Dugum* gec = ilk;
    int toplam=0;
    while(gec!=0)
    {
        toplam++;
        gec=gec->sonraki;
    }
    return toplam;
}
int Kromozom::ortaDeger(int toplam)
{
    return toplam / 2;
}

string Kromozom::solTaraf()
{
    Dugum* gec = ilk;
    string solTaraf;
    int toplam = genSayisiToplam();
    int orta = ortaDeger(toplam);

    for(int sayac= 0;sayac<orta;sayac++)
    {
        solTaraf = solTaraf + gec->veri + " ";
        gec=gec->sonraki;
    }
    return solTaraf;
    
}

string Kromozom::sagTaraf()
{
    Dugum* gec = ilk;
    string sagTaraf;
    int toplam = genSayisiToplam();
    int orta = ortaDeger(toplam);

    if(toplam % 2 == 0)
    {
        for(int sayac= 0;sayac<toplam;sayac++)
        {
            if(sayac >= orta)
            {
                sagTaraf = sagTaraf + gec->veri + " ";
            }
            gec=gec->sonraki;
        }
        return sagTaraf;
    }else if(toplam % 2 != 0)
    {
        for(int sayac= 0;sayac<toplam;sayac++)
        {
            if(sayac > orta)
            {
                sagTaraf = sagTaraf + gec->veri + " ";
            }
            gec=gec->sonraki;
        }
        return sagTaraf;
    }
  
}

void Kromozom::mutasyon(int sira)
{
    Dugum* gec = ilk;
    int sayac=0;
    while(gec!=0)
    {
        if(sayac == sira)
        {
            gec->veri = 'X' ; 
            break; 
        }
        sayac++;
        gec=gec->sonraki;
    }

}

char Kromozom::enKucuk()
{
    Dugum* gec = ilk;
    char enKucuk = ilk->veri;
    while(gec->sonraki!=0)
    {  
        gec=gec->sonraki;
    }
    while (gec->onceki!=0)
    {
        if(gec->veri < ilk->veri)
        {
            enKucuk = gec->veri;
            return enKucuk;
        }
        gec = gec->onceki;
    }

    return enKucuk;
    
}