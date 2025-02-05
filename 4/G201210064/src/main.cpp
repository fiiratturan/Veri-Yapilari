/**
* @file G201210064
* @description Bu ödevde tek yönlü bağlı liste ve ikili arama ağacı kullanılarak istenen işlemler gerçekleştirilecektir.
* @course 2.Ögretim A Grubu
* @assignment 2.Ödev
* @date (20.12.2024 - 25.12.2024)
* @author Necati Babacan- necati.babacan@ogr.sakarya.edu.tr
*/

#include<iostream>
#include<iomanip>
#include "Dosya.hpp"
using namespace std;

int main()
{
    Dosya* dosya = new Dosya();
    
    char secim;
    int sira =1;
    int listeSira=0;
    int baslangic=1,son=10;
    dosya->dosyaOku("agaclar.txt");
    BL_Dugum* gecici = dosya->liste->ilk;
    dosya->liste->yazdir(baslangic,son,sira);
    cout<<gecici->veri;

    while (true)
    {
        cin>>secim;
        switch (secim) {
        case 'a':
            if(gecici==dosya->liste->ilk)
            {
                system("cls");
                dosya->liste->yazdir(baslangic,son,sira);
                cout<<gecici->veri;
                break;
            }else
            {
                sira--;
                listeSira--;
            }
            if(sira%11==0)          
            {
                baslangic-=10;
                son-=10;
                sira = 10;
            }
            gecici=dosya->liste->dugumGetir(listeSira);
            dosya->liste->yazdir(baslangic,son,sira);
            cout<<gecici->veri;    
            break;
        case 'd':
            if(gecici->sonraki==0)
            {
                system("cls");
                dosya->liste->yazdir(baslangic,son,sira);
                cout<<gecici->veri;
                break;
            }else
            {
                sira++;
                listeSira++;
            }     
            
            if(sira%11==0)
            {
                baslangic+=10;
                son+=10;
                sira = 1;
            }
            dosya->liste->yazdir(baslangic,son,sira);
            gecici= gecici->sonraki;
            cout<<gecici->veri;
            break;
        case 'w':
            gecici->veri.aynalama();
            dosya->liste->yazdir(baslangic,son,sira);
            cout<<gecici->veri;
            break;
        case 's':    
            
            if(gecici->sonraki==0 )
            {
                dosya->liste->cikar(listeSira);
                if(dosya->liste->ilk==0)
                {
                    system("cls");
                    break;
                } 
                if((dosya->liste->dugumGetir(listeSira-1))!=0)
                {
                    gecici=dosya->liste->dugumGetir(listeSira-1);
                }
                listeSira--;
                sira--;
                if(sira%11==0)
                {
                    baslangic-=10;
                    son-=10;
                    sira = 10;
                }
                
            }else{
                dosya->liste->cikar(listeSira);
                gecici= gecici->sonraki;
            }
            if(dosya->liste->ilk !=0)
            {
                dosya->liste->yazdir(baslangic,son,sira);
                cout<<gecici->veri;
            }  
            break;
        default:
            cout << "Gecersiz secim!" << endl;
        }
    }
    

}