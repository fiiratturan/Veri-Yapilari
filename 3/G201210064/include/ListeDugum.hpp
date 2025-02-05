/**
* @file G201210064
* @description Bu ödevde bağlı listeler kullanarak gen, kromozom ve DNA işlemleri yapılacaktır.
* @course 2.Ögretim A Grubu
* @assignment 1.Ödev
* @date (20.11.2024 - 25.11.2024)
* @author Necati Babacan- necati.babacan@ogr.sakarya.edu.tr
*/

#ifndef ListeDugum_hpp
#define ListeDugum_hpp
#include<iostream>
#include "Kromozom.hpp"
using namespace std;

class ListeDugum
{
public:
    ListeDugum(Kromozom* kromozom);
    ~ListeDugum();
    Kromozom* kromozom;
    ListeDugum* sonraki;
    ListeDugum* onceki;
};


#endif