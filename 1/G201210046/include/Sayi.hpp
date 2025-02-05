/**
* @file G201210046
* @description Tek yönlü bağlı listeler kullanarak tam sayılar üzerinde çeşitli işlemler yapılması
* @course 1.Öğretim C Grubu
* @assignment 1.Ödev
* @date (25.11.2023 - 26.11.2023)
* @author Sefa AKTÜRK - sefa.akturk@ogr.sakarya.edu.tr
*/

#ifndef Sayi_hpp
#define Sayi_hpp
#include "Basamak.hpp"
class Sayi
{
public:
    Sayi();
    ~Sayi();
    void ekle(int veri);
    void sirala();
    void tersle();
    int veri();
//private:
    Basamak* ilk;
};

#endif