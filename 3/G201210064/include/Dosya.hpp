/**
* @file G201210064
* @description Bu ödevde bağlı listeler kullanarak gen, kromozom ve DNA işlemleri yapılacaktır.
* @course 2.Ögretim A Grubu
* @assignment 1.Ödev
* @date (20.11.2024 - 25.11.2024)
* @author Necati Babacan- necati.babacan@ogr.sakarya.edu.tr
*/

#ifndef Dosya_hpp
#define Dosya_hpp
#include<string>
#include "Kromozom.hpp"
#include "Liste.hpp"
using namespace std;

class Dosya
{
public:
    Dosya();
    void dosyaOku(string dosya);
    void caprazlama(int ilk, int son);
    void mutasyon(int satir,int sutun);
    void ekranaYaz();
    void otomatikIslemler(string dosya);
    Liste* liste;
};
#endif