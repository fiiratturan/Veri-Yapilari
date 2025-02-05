/**
* @file G201210064
* @description Bu ödevde tek yönlü bağlı liste ve ikili arama ağacı kullanılarak istenen işlemler gerçekleştirilecektir.
* @course 2.Ögretim A Grubu
* @assignment 2.Ödev
* @date (20.12.2024 - 25.12.2024)
* @author Necati Babacan- necati.babacan@ogr.sakarya.edu.tr
*/

#include "BagliListe.hpp"
#include <iostream>
#include<iomanip>
#include "IkiliAramaAgaci.hpp"
#include"BL_Dugum.hpp"
BagliListe::BagliListe()
{
    ilk=0;
}
BagliListe::~BagliListe()
{
    BL_Dugum* gecici = ilk;

    while(gecici!=0)
    {
        BL_Dugum* silinecek = gecici;

        gecici= gecici->sonraki;
        delete silinecek;
    }


}
void BagliListe::ekle(IkiliAramaAgaci veri)
{
    BL_Dugum* yeni = new BL_Dugum(veri);
    if(ilk==0)
    {
        ilk = yeni;
        return;
    }
   
    BL_Dugum* gecici = ilk;
    while(gecici->sonraki!=0)
        gecici= gecici->sonraki;
    gecici->sonraki = yeni;
}

void BagliListe::yazdir(int baslangic,int son,int secilenSira)
{
    system("cls");
    using namespace std;
    BL_Dugum* gecici = ilk;
    int sira=0;
    int listeSira=1;
    int imlecSira=0;
    while(gecici!=0)
    {
        sira++;
        if (sira >= baslangic && sira <= son) 
        {
            imlecSira++;
            if(listeSira == 1)
                cout<<setw(9)<<"........."<<setw(2)<<"  ";
            if(listeSira == 2)
                cout<<setw(9)<<gecici<<setw(2)<<"  ";;
            if(listeSira == 3)
                cout<<setw(9)<<"........."<<setw(2)<<"  ";;
            if(listeSira == 4)
                cout<<setw(9)<<gecici->veri.toplamDegerHesapla()<<setw(2)<<"  ";;
            if(listeSira == 5)
                cout<<setw(9)<<"........."<<setw(2)<<"  ";;
            if(listeSira == 6)
                cout<<setw(9)<<gecici->sonraki<<setw(2)<<"  ";;
            if(listeSira == 7)
                cout<<setw(9)<<"........."<<setw(2)<<"  ";;
            if((listeSira == 8 && secilenSira==sira) || (listeSira == 8 && imlecSira==secilenSira ))
                cout<<setw((secilenSira*11) - 2)<<"^^^^^^^^^"<<setw(2)<<"  ";;
            if((listeSira == 9 && secilenSira==sira) || (listeSira == 9 && imlecSira==secilenSira ))
                cout<<setw((secilenSira*11) - 2)<<"|||||||||"<<setw(2)<<"  ";;
            
        }
        gecici= gecici->sonraki;
        if(gecici==0 && listeSira<=9)
        {
            listeSira++;
            gecici=ilk;
            sira =0;
            imlecSira=0;
            cout<<endl;
        }
        
    }
    cout<<endl;
          
}

BL_Dugum* BagliListe::dugumGetir(int sira)
    {
        if(sira<0)
            return 0;
        BL_Dugum* gec= ilk;
        int sayac=0;
        while(gec!=0)
        {
            if(sayac==sira)
                return gec;
            gec=gec->sonraki;
            sayac++;
        }
        return gec;
    }

void BagliListe::cikar()
{
    if(ilk==0)  return;

    if(ilk->sonraki==0)
    {
        delete ilk;
        ilk=0;
    }
    else
    {
        BL_Dugum* gecici = ilk;

        while(gecici->sonraki->sonraki!=0)
        {
            gecici=gecici->sonraki;
        }

        delete gecici->sonraki;
        gecici->sonraki = 0;
    }
}

void BagliListe::cikar(int sira)
{
    if (ilk == nullptr)
        return;

    if (sira == 0)
    {
        BL_Dugum* temp = ilk;
        ilk = ilk->sonraki;
        delete temp;
        return;
    }

    BL_Dugum* gecici = ilk;
    int sayac = 0;

    while (gecici != nullptr && sayac < sira - 1)
    {
        gecici = gecici->sonraki;
        sayac++;
    }

    if (gecici == nullptr || gecici->sonraki == nullptr)
        return;

    BL_Dugum* silinecekDugum = gecici->sonraki;
    gecici->sonraki = silinecekDugum->sonraki;
    silinecekDugum->veri.~IkiliAramaAgaci();
    delete silinecekDugum;
}