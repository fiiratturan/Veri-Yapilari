/**
* @file B201210308
* @description Bir txt dosyasındaki veriler ile dizi gibi davranan bir iki yönlü bağıl liste oluşturma.
* @course 2.Ögretim B Grubu
* @assignment 1.Ödev
* @date (12.11.2021 - 13.11.2021)
* @author Fırat Turan - firat.turan2@ogr.sakarya.edu.tr
*/

#include "Dosya.hpp"
#include "Liste.hpp"
#include<fstream>
#include<string>
#include<iostream>
#include<sstream>


Dosya::Dosya()
{

}
void Dosya::dosyaOku(string dosya)
{
    Liste* liste = new Liste();
    ifstream in;
    in.open(dosya);
    while (!in.eof())
    {
        string line;
        getline(in,line);

        if(line[0]=='E')
        {
            liste->ekle(indeksBul(line),veriBul(line));
        }
        if(line[0]=='S')
        {
            liste->cikar(indeksBul(line));
        }
            

        if(in.fail())
            break;
        
    }
    in.close();
    cout<<*liste;    
}
string Dosya::veriBul(string line)
{
    int sayac=0;
    string veri;
    if(line[0]=='E')
    {
        while (line[sayac]!='#')
        {
            sayac++;
        }
        sayac++;
        while (line[sayac]!=')')
        {
            veri = veri + line[sayac];
            sayac++;      
        } 
    }
    return veri;         
}
int Dosya::indeksBul(string line)
{   
    int sayac=0;
    string veri;   
    while (line[sayac]!='(')
    {
    sayac++;
    }
    sayac++;
    while (line[sayac]!=')' && line[sayac]!='#' ) 
    {
        veri = veri + line[sayac];
        sayac++;      
    }

    return stoi(veri);
         
}