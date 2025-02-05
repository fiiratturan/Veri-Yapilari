
/**
* @file G201210064
* @description Bu ödevde tek yönlü bağlı liste ve ikili arama ağacı kullanılarak istenen işlemler gerçekleştirilecektir.
* @course 2.Ögretim A Grubu
* @assignment 2.Ödev
* @date (20.12.2024 - 25.12.2024)
* @author Necati Babacan- necati.babacan@ogr.sakarya.edu.tr
*/

#ifndef IkiliAramaAgaci_hpp
#define IkiliAramaAgaci_hpp
#include<iostream>
#include "IAA_DUGUM.hpp"
using namespace std;

class IkiliAramaAgaci
{
public:

	IkiliAramaAgaci();

	~IkiliAramaAgaci();
	bool varmi(char veri);
	void ekle(char veri);
	void sil(char veri);
    friend ostream& operator<<(ostream& os,IkiliAramaAgaci& kuyruk);
	int yukseklik();
	void preOrder();
	void postOrder();
	void inOrder();
	void aynalama();
	int toplamDegerHesapla();

private:
	void levelOrder(IAA_DUGUM* aktif,int level);
	void levelOrder();
	void preOrder(IAA_DUGUM* aktif);
	void postOrder(IAA_DUGUM* index);
	void inOrder(IAA_DUGUM* index);
	int yukseklik(IAA_DUGUM* aktifIAA_DUGUM);
	void ekle(char veri,IAA_DUGUM* aktifIAA_DUGUM);
	bool varmi(char aranan,IAA_DUGUM* aktif);
	void silDonguile(IAA_DUGUM* aktif,IAA_DUGUM* Ebeveyn);
	void sil(char aranan,IAA_DUGUM* &aktif);
	int maxDeger(IAA_DUGUM* aktif);
	int agacYukseklik;
	int toplamDeger;
	void boslukBirak(int adet);
	IAA_DUGUM* kok;
	int toplamDegerHesapla(IAA_DUGUM* aktif);
	void aynalama(IAA_DUGUM* aktif);
};
//diger fonksiyonlar eklenecek
#endif