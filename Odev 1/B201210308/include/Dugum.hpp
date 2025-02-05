/**
* @file B201210308
* @description Bir txt dosyasındaki veriler ile dizi gibi davranan bir iki yönlü bağıl liste oluşturma.
* @course 2.Ögretim B Grubu
* @assignment 1.Ödev
* @date (12.11.2021 - 13.11.2021)
* @author Fırat Turan - firat.turan2@ogr.sakarya.edu.tr
*/

#ifndef Dugum_hpp
#define Dugum_hpp
#include<iostream>
#include<string>
using namespace std;

class Dugum
{
public:
    Dugum(string veri);
    string veri;
    Dugum* sonraki;
    Dugum* onceki;
};

#endif