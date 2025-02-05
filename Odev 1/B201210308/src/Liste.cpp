/**
* @file B201210308
* @description Bir txt dosyasındaki veriler ile dizi gibi davranan bir iki yönlü bağıl liste oluşturma.
* @course 2.Ögretim B Grubu
* @assignment 1.Ödev
* @date (12.11.2021 - 13.11.2021)
* @author Fırat Turan - firat.turan2@ogr.sakarya.edu.tr
*/

#include "Liste.hpp"
#include <iomanip>
#include<string>

Liste::Liste()
{
    ilk=0;
    son=0;
}

void Liste::ekle(int sira,string veri)
{
    Dugum* yeniDugum = new Dugum(veri);


    if(ilk==0)
    {
        ilk= yeniDugum;
        son =yeniDugum;
    }
    else
    {
        Dugum* secilenDugum = dugumGetir(sira);
        if(secilenDugum)
        {  
            Dugum* yedekSon = son;                 
            yeniDugum->onceki= son;
            yeniDugum->veri=son->veri;

            yedekSon->sonraki  = yeniDugum;           
           
            son=yeniDugum;
            
            while (secilenDugum!=yedekSon)
            {
                yedekSon->veri=yedekSon->onceki->veri;
                yedekSon = yedekSon->onceki;              
            }
            secilenDugum->veri=veri;

        }else
        {
            yeniDugum->onceki= son;
            son->sonraki=yeniDugum;
            son=yeniDugum;
        }
    }


}
void Liste::cikar(int sira)
{
    Dugum* secilenDugum = dugumGetir(sira);
    Dugum* yedekSon= son;
    if(ilk==son)
    {
        ilk=0;
        son=0;
        delete secilenDugum;
    }else if(secilenDugum)
    {
        while (secilenDugum!=yedekSon)
        {
        secilenDugum->veri=secilenDugum->sonraki->veri;

        secilenDugum =secilenDugum ->sonraki;
        }
        son = son->onceki;
        son->sonraki= 0;
        delete secilenDugum->sonraki;
    }else
    {
        son = son->onceki;
        son->sonraki=0;
        delete yedekSon;
    }
}
Dugum* Liste::dugumGetir(int sira)
{
     Dugum* gec  = ilk;
     int sayac=0;
        while (gec!=0)
        {
            if(sayac==sira)                
                return gec;

            gec=gec->sonraki;
            sayac++;
        }
    return 0;
}

ostream& operator<<(ostream& os,Liste& Liste)
{
    using namespace std;

    Dugum* gec=Liste.ilk;
    Dugum* son = Liste.son;

    while (gec!=0)
    {
        if(gec == son)
            os<<gec->veri;
        else
            os<<gec->veri<<" <--> ";
            
        gec=gec->sonraki;
    }

    return os;
    
}