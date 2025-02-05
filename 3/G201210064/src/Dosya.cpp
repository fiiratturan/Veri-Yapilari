/**
* @file G201210064
* @description Bu ödevde bağlı listeler kullanarak gen, kromozom ve DNA işlemleri yapılacaktır.
* @course 2.Ögretim A Grubu
* @assignment 1.Ödev
* @date (20.11.2024 - 25.11.2024)
* @author Necati Babacan- necati.babacan@ogr.sakarya.edu.tr
*/

#include "Dosya.hpp"
#include "Kromozom.hpp"
#include "Liste.hpp"
#include<fstream>
#include<string>
#include<iostream>
#include<sstream>

Dosya::Dosya()
{
    liste = new Liste();
}
void Dosya::dosyaOku(string dosya)
{
    ifstream in(dosya);
    
    string line;

    while (!in.eof())
    {    
        getline(in, line);
        Kromozom* kromozom = new Kromozom();
        for(int i=0;i<line.length();++i)
        {        
            while(line[i]!=' ')
            {                
                kromozom->ekle(char(line[i]));
                i++;
                if(line.length()==i)
                {                   
                    break;
                }
            }
        }
        liste->ekle(kromozom);
        
    }

    in.close();
}

void Dosya::caprazlama(int ilk, int son)
{
    ListeDugum* gec = liste->ilkGetir();
    string yeniKromozomBir,yeniKromozomIki,ilkSolTaraf,ilkSagTaraf,sonSolTaraf,sonSagTaraf;
    int sayac= 0;
    while(gec!=0)
    {
        if(sayac == ilk)
        {
            ilkSolTaraf = gec->kromozom->solTaraf();
            ilkSagTaraf = gec->kromozom->sagTaraf();
        }
        if(sayac == son)
        {
            sonSolTaraf = gec->kromozom->solTaraf();
            sonSagTaraf = gec->kromozom->sagTaraf();
        }
        sayac++;
        gec=gec->sonraki;
    }
    Kromozom* kromozomBir = new Kromozom();
    yeniKromozomBir = ilkSolTaraf + sonSagTaraf;
    for(int i=0;i<yeniKromozomBir.length();++i)
    {        
        while(yeniKromozomBir[i]!=' ')
        {                
            kromozomBir->ekle(char(yeniKromozomBir[i]));
            i++;
            if(yeniKromozomBir.length()==i)
            {                   
                break;
            }
        }
    }
    liste->ekle(kromozomBir);

    Kromozom* kromozomIki = new Kromozom();
    yeniKromozomIki = ilkSagTaraf + sonSolTaraf;
    for(int i=0;i<yeniKromozomIki.length();++i)
    {        
        while(yeniKromozomIki[i]!=' ')
        {                
            kromozomIki->ekle(char(yeniKromozomIki[i]));
            i++;
            if(yeniKromozomIki.length()==i)
            {                   
                break;
            }
        }
    }
    liste->ekle(kromozomIki);
    
}

void Dosya::mutasyon(int satir,int sutun)
{
    ListeDugum* gec = liste->ilkGetir();
    int sayac= 0;
    while(gec!=0)
    {
        if(sayac == satir)
        {
            gec->kromozom->mutasyon(sutun);
            break;
        }
        sayac++;
        gec=gec->sonraki;
    }

}

void Dosya::ekranaYaz()
{
    ListeDugum* gec = liste->ilkGetir();
    while(gec!=0)
    {
        cout<<gec->kromozom->enKucuk()<<" ";
        gec=gec->sonraki;
    }
    cout<<endl;
}

void Dosya::otomatikIslemler(string dosya) 
{
    ifstream in(dosya);

    if (!in.is_open()) {
        cerr << "Dosya açilamadi: " << dosya << endl;
        return;
    }

    string line;
    while (getline(in, line)) 
    {
        stringstream ss(line);
        char operation;
        int ilkDeger, ikinciDeger;

        if (ss >> operation >> ilkDeger >> ikinciDeger) 
        {
            if (operation == 'C') {
                caprazlama(ilkDeger, ikinciDeger);
            } else if (operation == 'M') {
                mutasyon(ilkDeger, ikinciDeger);
            } else {
                cerr << "Geçersiz işlem türü: " << operation << endl;
            } 
        } else {
            cerr << "Hatali satir formati: " << line << endl;
        }
    }

    in.close();
}



