/**
* @file G201210046
* @description Tek yönlü bağlı listeler kullanarak tam sayılar üzerinde çeşitli işlemler yapılması
* @course 1.Öğretim C Grubu
* @assignment 1.Ödev
* @date (25.11.2023 - 26.11.2023)
* @author Sefa AKTÜRK - sefa.akturk@ogr.sakarya.edu.tr
*/

#include "Basamak.hpp"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Basamak::Basamak(int veri)
{
    this->veri=veri;
    sonraki = 0;
}
string Basamak::sonUcBasamak()
{
    stringstream ss;
    ss << this;
    string pointerStr =ss.str();
    pointerStr = pointerStr.substr(pointerStr.length()-3, pointerStr.length());
    return pointerStr;
}