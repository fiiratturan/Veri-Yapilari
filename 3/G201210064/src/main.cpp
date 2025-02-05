/**
* @file G201210064
* @description Bu ödevde bağlı listeler kullanarak gen, kromozom ve DNA işlemleri yapılacaktır.
* @course 2.Ögretim A Grubu
* @assignment 1.Ödev
* @date (20.11.2024 - 25.11.2024)
* @author Necati Babacan- necati.babacan@ogr.sakarya.edu.tr
*/

#include<iostream>
#include<iomanip>
#include "Liste.hpp"
#include "Dosya.hpp"
using namespace std;

int main()
{
    Dosya* dosya = new Dosya();
    dosya->dosyaOku("Dna.txt");
    int secim,caprazlamaBir,caprazlamaIki,mutasyonSatir,mutasyonSutun;

    while(true)
    {
        cout << "1.Caprazlama "<<endl;
        cout << "2.Mutasyon"<<endl;
        cout << "3.Otomatik Islemler"<<endl;
        cout << "4.Ekrana Yaz"<<endl;
        cout << "5.Cikis"<<endl;
        cin>>secim;
        switch (secim) {
        case 1:
            cout<<"Caprazlanacak ilk kromozomu giriniz."<<endl;
            cin>>caprazlamaBir;
            cout<<"Caprazlanacak ikinci kromozomu giriniz."<<endl;
            cin>>caprazlamaIki;
            dosya->caprazlama(caprazlamaBir,caprazlamaIki);
            cout<<"Islem tamamlandi"<<endl<<endl;
            break;
        case 2:
            cout<<"Mutasyon satir giriniz."<<endl;
            cin>>mutasyonSatir;
            cout<<"Mutasyon sutun giriniz."<<endl;
            cin>>mutasyonSutun;
            dosya->mutasyon(mutasyonSatir,mutasyonSutun);
            cout<<"Islem tamamlandi"<<endl<<endl;
            break;
        case 3:
            dosya->otomatikIslemler("Islemler.txt");
            cout<<"Islem tamamlandi"<<endl<<endl;
            break;
        case 4:
            dosya->ekranaYaz();
            cout<<endl;
            break;
        case 5:
             exit(0);
            break;
        default:
            cout << "Gecersiz secim!" << endl;
        }
    }
}