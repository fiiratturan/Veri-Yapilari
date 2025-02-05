/**
* @file G201210046
* @description Tek yönlü bağlı listeler kullanarak tam sayılar üzerinde çeşitli işlemler yapılması
* @course 1.Öğretim C Grubu
* @assignment 1.Ödev
* @date (25.11.2023 - 26.11.2023)
* @author Sefa AKTÜRK - sefa.akturk@ogr.sakarya.edu.tr
*/

#ifndef Dugum_hpp
#define Dugum_hpp
#include "Sayi.hpp"

class Dugum
{
public:
    Dugum(Sayi* veri);
    Sayi* veri;
    Dugum* sonraki;

};

#endif