/**
* @file B201210308
* @description Bir txt dosyasındaki verileri kordinant olarak kuyrugu ekleme ve orjine yakınlığa göre sıralama kordinatlar arası mesafeye göre AVL ağacı oluşturma
* @course 2.Ögretim B Grubu
* @assignment 2.Ödev
* @date (23.12.2021 - 26.12.2021)
* @author Fırat Turan - firat.turan2@ogr.sakarya.edu.tr
*/

#include "DogruKuyrugu.hpp"
#include <math.h>

DogruKuyrugu::DogruKuyrugu()
{
    ilk=son=0;
}

void DogruKuyrugu::ekle(Kordinant* kordinant)
{
    
    if(ilk==0)
    {
        ilk=new KuyrukDugum(kordinant);
        son= ilk;
        sonKordinant=ilk->kordinant;
        toplam=0;
    }
    else
    {
        toplam = toplam + uzunlukHesapla(sonKordinant,kordinant);
        sonKordinant=kordinant;
        if(kordinant->uzaklikHesapla() < ilk->kordinant->uzaklikHesapla())
        {
            KuyrukDugum* yeni = new KuyrukDugum(kordinant);
            yeni->sonraki=ilk;          
            ilk=yeni;
        }
        else 
        {
            KuyrukDugum*gec= ilk->sonraki;
            KuyrukDugum*gecOnceki= ilk;
            bool eklemeKontrol=false;

            while (gec!=0)
            {
                if(kordinant->uzaklikHesapla() < gec->kordinant->uzaklikHesapla())
                {
                    KuyrukDugum* yeni = new KuyrukDugum(kordinant);
                    gecOnceki->sonraki = yeni;
                    yeni->sonraki = gec;
                    eklemeKontrol=true;
                    break;
                }
                gec = gec->sonraki;
                gecOnceki = gecOnceki->sonraki;
            }

            if(eklemeKontrol==false)
            {
                KuyrukDugum* yeni = new KuyrukDugum(kordinant);
                son->sonraki = yeni;
                son = yeni;
            }
            
        }
    }
}

void DogruKuyrugu::Listele()
{
    KuyrukDugum* gec = ilk;
    while(gec!=0)
    {        
        cout<<gec->kordinant->uzaklikHesapla()<<" ";
        gec = gec->sonraki;
    }    
}
int DogruKuyrugu::uzunlukHesapla(Kordinant* kordinant1,Kordinant* kordinant2)
{
    int uzunluk;
    uzunluk=trunc(sqrt(
        (kordinant1->x - kordinant2->x)*(kordinant1->x - kordinant2->x)+
        (kordinant1->y - kordinant2->y)*(kordinant1->y - kordinant2->y)+
        (kordinant1->z - kordinant2->z)*(kordinant1->z - kordinant2->z)));
    return uzunluk;
}

