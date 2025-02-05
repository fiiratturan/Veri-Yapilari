/**
* @file G201210064
* @description Bu ödevde tek yönlü bağlı liste ve ikili arama ağacı kullanılarak istenen işlemler gerçekleştirilecektir.
* @course 2.Ögretim A Grubu
* @assignment 2.Ödev
* @date (20.12.2024 - 25.12.2024)
* @author Necati Babacan- necati.babacan@ogr.sakarya.edu.tr
*/

#include "BL_Dugum.hpp"
#include "IkiliAramaAgaci.hpp"
BL_Dugum::BL_Dugum(IkiliAramaAgaci veri)
{
    this->veri=veri;
    sonraki = 0;
}