/**
* @file G201210046
* @description Tek yönlü bağlı listeler kullanarak tam sayılar üzerinde çeşitli işlemler yapılması
* @course 1.Öğretim C Grubu
* @assignment 1.Ödev
* @date (25.11.2023 - 26.11.2023)
* @author Sefa AKTÜRK - sefa.akturk@ogr.sakarya.edu.tr
*/

#ifndef Dosya_hpp
#define Dosya_hpp
#include<string>
#include "SayilarListesi.hpp"
using namespace std;

class Dosya
{
public:
    Dosya();
    void dosyaOku(string dosya);
    SayilarListesi* sayilarListesi;
};
#endif