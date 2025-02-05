/**
* @file B201210308
* @description Bir txt dosyasındaki verileri kordinant olarak kuyrugu ekleme ve orjine yakınlığa göre sıralama kordinatlar arası mesafeye göre AVL ağacı oluşturma
* @course 2.Ögretim B Grubu
* @assignment 2.Ödev
* @date (23.12.2021 - 26.12.2021)
* @author Fırat Turan - firat.turan2@ogr.sakarya.edu.tr
*/

#include "AVLDugum.hpp"

AVLDugum::AVLDugum(DogruKuyrugu* kuyruk)
{
    this->kuyruk = kuyruk;
    this->veri = kuyruk->toplam;
    sol=sag=0;
}