/**
* @file B201210308
* @description Bir txt dosyasındaki verileri kordinant olarak kuyrugu ekleme ve orjine yakınlığa göre sıralama kordinatlar arası mesafeye göre AVL ağacı oluşturma
* @course 2.Ögretim B Grubu
* @assignment 2.Ödev
* @date (23.12.2021 - 26.12.2021)
* @author Fırat Turan - firat.turan2@ogr.sakarya.edu.tr
*/

#ifndef Kuyruk_hpp
#define Kuyruk_hpp

#include "KuyrukDugum.hpp"

class DogruKuyrugu
{
public:
	DogruKuyrugu();
	void ekle(Kordinant* kordinant);
	void Listele();
	Kordinant* sonKordinant;
	int toplam;
private:
	int uzunlukHesapla(Kordinant* kordinant1,Kordinant* kordinant2);
	KuyrukDugum* ilk;
	KuyrukDugum* son;
};

#endif