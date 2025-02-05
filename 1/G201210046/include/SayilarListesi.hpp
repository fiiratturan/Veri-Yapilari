/**
* @file G201210046
* @description Tek yönlü bağlı listeler kullanarak tam sayılar üzerinde çeşitli işlemler yapılması
* @course 1.Öğretim C Grubu
* @assignment 1.Ödev
* @date (25.11.2023 - 26.11.2023)
* @author Sefa AKTÜRK - sefa.akturk@ogr.sakarya.edu.tr
*/

#ifndef SayilarListesi_hpp
#define SayilarListesi_hpp
#include "Dugum.hpp"
#include "Sayi.hpp"
class SayilarListesi
{
public:
    SayilarListesi();
    ~SayilarListesi();
    void ekle(Sayi* veri);
    
    void yazdir();
    void cikar();
    void sirala();
    void tersle();
//private:
    Dugum* ilk;
};

#endif