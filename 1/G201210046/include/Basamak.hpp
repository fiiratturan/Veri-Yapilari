/**
* @file G201210046
* @description Tek yönlü bağlı listeler kullanarak tam sayılar üzerinde çeşitli işlemler yapılması
* @course 1.Öğretim C Grubu
* @assignment 1.Ödev
* @date (25.11.2023 - 26.11.2023)
* @author Sefa AKTÜRK - sefa.akturk@ogr.sakarya.edu.tr
*/
#ifndef Basamak_hpp
#define Basamak_hpp
#include <string>
using namespace std;

class Basamak
{
public:
    Basamak(int veri);
    int veri;
    Basamak* sonraki;
    string sonUcBasamak();

};

#endif