/**
* @file B201210308
* @description Bir txt dosyasındaki verileri kordinant olarak kuyrugu ekleme ve orjine yakınlığa göre sıralama kordinatlar arası mesafeye göre AVL ağacı oluşturma
* @course 2.Ögretim B Grubu
* @assignment 2.Ödev
* @date (23.12.2021 - 26.12.2021)
* @author Fırat Turan - firat.turan2@ogr.sakarya.edu.tr
*/

#include "Dosya.hpp"
#include<fstream>

using namespace std;

void Dosya::dosyaOku(string dosya)
{
    ifstream in;
    in.open(dosya);
    while (!in.eof())
    {
        string line;
        getline(in,line);
        kordinantBul(line);           
        if(in.fail())
            break;
        
    }
    agac.postOrder();
    in.close();  
}
void Dosya::kordinantBul(string line)
{
    int sayac=0;
    int kordinantSayac=0;
    int x,y,z;
    string veri;
    DogruKuyrugu* kuyruk = new DogruKuyrugu();

    for(int i=0;i<line.size();i++)
    {   
        if(line[i]!=' ')
        {    
            veri=veri + line[i];
        }
        else if(line[i]==' ')
        {   
            kordinantSayac++;
            if(kordinantSayac==1)
            {
                x=stoi(veri);
                veri="";
            }
            if(kordinantSayac==2)
            {
                y=stoi(veri);
                veri="";
            }
            if(kordinantSayac==3)
            {
                z=stoi(veri);
                veri="";
                Kordinant* kordinant = new Kordinant(x,y,z);
                kuyruk->ekle(kordinant);
                kordinantSayac=0;
            }    
        }
    }
    agac.ekle(kuyruk);
}