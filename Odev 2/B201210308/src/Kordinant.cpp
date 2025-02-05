/**
* @file B201210308
* @description Bir txt dosyasındaki verileri kordinant olarak kuyrugu ekleme ve orjine yakınlığa göre sıralama kordinatlar arası mesafeye göre AVL ağacı oluşturma
* @course 2.Ögretim B Grubu
* @assignment 2.Ödev
* @date (23.12.2021 - 26.12.2021)
* @author Fırat Turan - firat.turan2@ogr.sakarya.edu.tr
*/

#include "Kordinant.hpp"
#include <math.h>


Kordinant::Kordinant(int x,int y, int z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}
int Kordinant::uzaklikHesapla()
{
    int orjineUzaklik=0;

    orjineUzaklik=trunc(sqrt(sqrt(x*x+y*y)*sqrt(x*x+y*y)+z*z));

    return orjineUzaklik;   
}