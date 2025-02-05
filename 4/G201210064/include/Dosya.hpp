/**
* @file G201210064
* @description Bu ödevde tek yönlü bağlı liste ve ikili arama ağacı kullanılarak istenen işlemler gerçekleştirilecektir.
* @course 2.Ögretim A Grubu
* @assignment 2.Ödev
* @date (20.12.2024 - 25.12.2024)
* @author Necati Babacan- necati.babacan@ogr.sakarya.edu.tr
*/

#ifndef Dosya_hpp
#define Dosya_hpp
#include<string>
#include "IkiliAramaAgaci.hpp"
#include "BagliListe.hpp"
using namespace std;

class Dosya
{
public:
    Dosya();
    void dosyaOku(string dosya);
    BagliListe* liste;
};
#endif