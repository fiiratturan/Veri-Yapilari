/**
* @file B201210308
* @description Bir txt dosyasındaki verileri kordinant olarak kuyrugu ekleme ve orjine yakınlığa göre sıralama kordinatlar arası mesafeye göre AVL ağacı oluşturma
* @course 2.Ögretim B Grubu
* @assignment 2.Ödev
* @date (23.12.2021 - 26.12.2021)
* @author Fırat Turan - firat.turan2@ogr.sakarya.edu.tr
*/

#ifndef AVLAgaci_hpp
#define AVLAgaci_hpp
#include "AVLDugum.hpp"

class AVLAgaci
{
public:

	AVLAgaci();
	~AVLAgaci();
	void ekle(DogruKuyrugu* kuyruk);
	int yukseklik();
	void postOrder();
private:
	AVLDugum* solaDondur(AVLDugum* AVLDugum);
	AVLDugum* sagaDondur(AVLDugum* AVLDugum);
	int yukseklik(AVLDugum* aktifAVLDugum);
	AVLDugum* ekle(DogruKuyrugu* kuyruk,AVLDugum* aktifAVLDugum);
	void postOrder(AVLDugum* aktif);
	AVLDugum* kok;
};
#endif