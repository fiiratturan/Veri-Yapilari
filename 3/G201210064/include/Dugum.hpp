/**
* @file G201210064
* @description Bu ödevde bağlı listeler kullanarak gen, kromozom ve DNA işlemleri yapılacaktır.
* @course 2.Ögretim A Grubu
* @assignment 1.Ödev
* @date (20.11.2024 - 25.11.2024)
* @author Necati Babacan- necati.babacan@ogr.sakarya.edu.tr
*/

#ifndef Dugum_hpp
#define Dugum_hpp
#include<iostream>
using namespace std;

class Dugum
{
public:
    Dugum(char veri);
    ~Dugum();
    char veri;
    Dugum* sonraki;
    Dugum* onceki;
};


#endif