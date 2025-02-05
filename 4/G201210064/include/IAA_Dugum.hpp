/**
* @file G201210064
* @description Bu ödevde tek yönlü bağlı liste ve ikili arama ağacı kullanılarak istenen işlemler gerçekleştirilecektir.
* @course 2.Ögretim A Grubu
* @assignment 2.Ödev
* @date (20.12.2024 - 25.12.2024)
* @author Necati Babacan- necati.babacan@ogr.sakarya.edu.tr
*/

#ifndef IAA_DUGUM_hpp
#define IAA_DUGUM_hpp

class IAA_DUGUM
{
public:
    IAA_DUGUM(char veri);
    char veri;
    IAA_DUGUM* sol;
    IAA_DUGUM* sag;
    int yukseklik;
};

#endif