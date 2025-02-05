/**
* @file G201210064
* @description Bu ödevde tek yönlü bağlı liste ve ikili arama ağacı kullanılarak istenen işlemler gerçekleştirilecektir.
* @course 2.Ögretim A Grubu
* @assignment 2.Ödev
* @date (20.12.2024 - 25.12.2024)
* @author Necati Babacan- necati.babacan@ogr.sakarya.edu.tr
*/

#include "Dosya.hpp"
#include "IkiliAramaAgaci.hpp"
#include "BagliListe.hpp"
#include<fstream>
#include<string>
#include<iostream>
#include<sstream>

Dosya::Dosya()
{
    liste = new BagliListe();
}
void Dosya::dosyaOku(string dosya)
{
    ifstream in(dosya);
    
    string line;

    while (!in.eof())
    {    
        getline(in, line);
        IkiliAramaAgaci* agac = new IkiliAramaAgaci();
        for(int i=0;i<line.length();++i)
        {        
            while(line[i]!=' ')
            {                
                agac->ekle(char(line[i]));
                i++;
                if(line.length()==i)
                {                   
                    break;
                }
            }
            
        }
        liste->ekle(*agac);
        
    }

    in.close();
}



