/**
* @file G201210064
* @description Bu ödevde bağlı listeler kullanarak gen, kromozom ve DNA işlemleri yapılacaktır.
* @course 2.Ögretim A Grubu
* @assignment 1.Ödev
* @date (20.11.2024 - 25.11.2024)
* @author Necati Babacan- necati.babacan@ogr.sakarya.edu.tr
*/

#include "ListeDugum.hpp"

ListeDugum::ListeDugum(Kromozom* kromozom)
{
    this->kromozom = kromozom;

    onceki = sonraki = 0;
}
ListeDugum::~ListeDugum()
{
    cout<<this<<":adresindeki ListeDugum Silindi"<<endl;
}