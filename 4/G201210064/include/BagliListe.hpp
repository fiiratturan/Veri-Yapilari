/**
* @file G201210064
* @description Bu ödevde tek yönlü bağlı liste ve ikili arama ağacı kullanılarak istenen işlemler gerçekleştirilecektir.
* @course 2.Ögretim A Grubu
* @assignment 2.Ödev
* @date (20.12.2024 - 25.12.2024)
* @author Necati Babacan- necati.babacan@ogr.sakarya.edu.tr
*/

#ifndef BagliListe_hpp
#define BagliListe_hpp
#include "IAA_Dugum.hpp"
#include "IkiliAramaAgaci.hpp"
#include "BL_Dugum.hpp"
class BagliListe
{
public:
    BagliListe();
    ~BagliListe();
    void ekle(IkiliAramaAgaci veri);
    
    void yazdir(int baslangic,int son,int secilenSira);
    void cikar();
    void cikar(int sira);
    BL_Dugum* dugumGetir(int sira);
//private:
    BL_Dugum* ilk;
};

#endif