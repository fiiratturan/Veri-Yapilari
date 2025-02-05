/**
* @file B201210308
* @description Bir txt dosyasındaki veriler ile dizi gibi davranan bir iki yönlü bağıl liste oluşturma.
* @course 2.Ögretim B Grubu
* @assignment 1.Ödev
* @date (12.11.2021 - 13.11.2021)
* @author Fırat Turan - firat.turan2@ogr.sakarya.edu.tr
*/

#ifndef Liste_hpp
#define Liste_hpp
#include<exception>
#include<string>
#include "Dugum.hpp"

class Liste
{
public:
    Liste();
    void ekle(int sira,string veri);
    void cikar(int sira);    
    friend ostream& operator<<(ostream& os,Liste& Liste);

private:
    Dugum* dugumGetir(int sira);
    Dugum* ilk;
    Dugum* son;
    
};

#endif