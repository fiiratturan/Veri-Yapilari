/**
* @file G201210064
* @description Bu ödevde bağlı listeler kullanarak gen, kromozom ve DNA işlemleri yapılacaktır.
* @course 2.Ögretim A Grubu
* @assignment 1.Ödev
* @date (20.11.2024 - 25.11.2024)
* @author Necati Babacan- necati.babacan@ogr.sakarya.edu.tr
*/

#ifndef Liste_hpp
#define Liste_hpp
#include<exception>
#include<iostream>
#include "ListeDugum.hpp"
class Liste
{
public:
    Liste();
    ~Liste();
    void ekle(Kromozom* kromozom);
    ListeDugum* ilkGetir();
    ListeDugum* ListeDugumGetir(int sira);
private:
    ListeDugum* ilk;

};

#endif