/**
* @file B201210308
* @description Bir txt dosyasındaki veriler ile dizi gibi davranan bir iki yönlü bağıl liste oluşturma.
* @course 2.Ögretim B Grubu
* @assignment 1.Ödev
* @date (12.11.2021 - 13.11.2021)
* @author Fırat Turan - firat.turan2@ogr.sakarya.edu.tr
*/

#ifndef Dosya_hpp
#define Dosya_hpp
#include<string>
using namespace std;

class Dosya
{
public:
    Dosya();
    void dosyaOku(string dosya);    
private:
    string veriBul(string line);
    int indeksBul(string line);
};
#endif