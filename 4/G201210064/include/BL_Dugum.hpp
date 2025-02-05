/**
* @file G201210064
* @description Bu ödevde tek yönlü bağlı liste ve ikili arama ağacı kullanılarak istenen işlemler gerçekleştirilecektir.
* @course 2.Ögretim A Grubu
* @assignment 2.Ödev
* @date (20.12.2024 - 25.12.2024)
* @author Necati Babacan- necati.babacan@ogr.sakarya.edu.tr
*/

#ifndef BL_Dugum_hpp
#define BL_Dugum_hpp

#include "IkiliAramaAgaci.hpp"

class BL_Dugum
{
public:
    BL_Dugum(IkiliAramaAgaci veri);
    IkiliAramaAgaci veri;
    BL_Dugum* sonraki;

};

#endif