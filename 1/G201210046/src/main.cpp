/**
* @file G201210046
* @description Tek yönlü bağlı listeler kullanarak tam sayılar üzerinde çeşitli işlemler yapılması
* @course 1.Öğretim C Grubu
* @assignment 1.Ödev
* @date (25.11.2023 - 26.11.2023)
* @author Sefa AKTÜRK - sefa.akturk@ogr.sakarya.edu.tr
*/

#include "Dosya.hpp"
#include<string>
#include<iostream>

using namespace std;


int main()
{  
    Dosya* veriOkuma=new Dosya();

    veriOkuma->dosyaOku("Veri.txt");

    int secim;

    while(true)
    {
        veriOkuma->sayilarListesi->yazdir();
        cout << "1.Tek Basamaklari Basa Al "<<endl;
        cout << "2.Basamaklari Tersle"<<endl;
        cout << "3.En Buyuk Cikar"<<endl;
        cout << "4.Cikis"<<endl;
        cin>>secim;
        switch (secim) {
        case 1:
             veriOkuma->sayilarListesi->sirala();
            break;
        case 2:
             veriOkuma->sayilarListesi->tersle();
            break;
        case 3:
             veriOkuma->sayilarListesi->cikar();
            break;
        case 4:
             exit(0);
            break;
        default:
            cout << "Gecersiz secim!" << endl;
    }
    }

}
    