/**
* @file B201210308
* @description Bir txt dosyasındaki verileri kordinant olarak kuyrugu ekleme ve orjine yakınlığa göre sıralama kordinatlar arası mesafeye göre AVL ağacı oluşturma
* @course 2.Ögretim B Grubu
* @assignment 2.Ödev
* @date (23.12.2021 - 26.12.2021)
* @author Fırat Turan - firat.turan2@ogr.sakarya.edu.tr
*/

#ifndef KuyrukDugum_hpp
#define KuyrukDugum_hpp

#include "Kordinant.hpp"

class KuyrukDugum
{
public:
    KuyrukDugum(Kordinant* kordinant);
    Kordinant* kordinant;
    KuyrukDugum* sonraki;
};

#endif