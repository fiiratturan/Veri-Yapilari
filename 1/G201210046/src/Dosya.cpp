/**
* @file G201210046
* @description Tek yönlü bağlı listeler kullanarak tam sayılar üzerinde çeşitli işlemler yapılması
* @course 1.Öğretim C Grubu
* @assignment 1.Ödev
* @date (25.11.2023 - 26.11.2023)
* @author Sefa AKTÜRK - sefa.akturk@ogr.sakarya.edu.tr
*/

#include "Dosya.hpp"
#include "Sayi.hpp"
#include "SayilarListesi.hpp"
#include<fstream>
#include<string>
#include<iostream>
#include<sstream>

Dosya::Dosya()
{
    sayilarListesi= new SayilarListesi();
}
void Dosya::dosyaOku(string dosya)
{
    ifstream in(dosya);
    
    string line;
    string veri;
    bool ilk=true;
    bool nesneOlustur=true;

    while (!in.eof())
    {    
        getline(in, line);
        
        for(int i=0;i<line.length();++i)
        {
           
            Sayi* sayi= new Sayi();          
            while(line[i]!=' ')
            {
                sayi->ekle(char(line[i]));
                veri = veri + line[i];
                i++;
                if(line.length()==i)
                {
                    break;
                }
            }

            sayilarListesi->ekle(sayi);
            veri=" ";
            
        }
        
    }

    in.close();
}