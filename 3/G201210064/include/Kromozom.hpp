/**
* @file G201210064
* @description Bu ödevde bağlı listeler kullanarak gen, kromozom ve DNA işlemleri yapılacaktır.
* @course 2.Ögretim A Grubu
* @assignment 1.Ödev
* @date (20.11.2024 - 25.11.2024)
* @author Necati Babacan- necati.babacan@ogr.sakarya.edu.tr
*/

#ifndef Kromozom_hpp
#define Kromozom_hpp
#include "Dugum.hpp"
class Kromozom
{
public:
    Kromozom();
    ~Kromozom();
    void ekle(char veri);
    int genSayisiToplam();
    int ortaDeger(int toplam);
    char enKucuk();
    string solTaraf();
    string sagTaraf();
    void mutasyon(int sira);
    Dugum* ilk;
};

#endif