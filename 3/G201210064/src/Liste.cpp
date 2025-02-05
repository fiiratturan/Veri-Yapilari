/**
* @file G201210064
* @description Bu ödevde bağlı listeler kullanarak gen, kromozom ve DNA işlemleri yapılacaktır.
* @course 2.Ögretim A Grubu
* @assignment 1.Ödev
* @date (20.11.2024 - 25.11.2024)
* @author Necati Babacan- necati.babacan@ogr.sakarya.edu.tr
*/

#include "Liste.hpp"
#include "ListeDugum.hpp"
#include<iomanip>

Liste::Liste()
{
    ilk=0;
}
Liste::~Liste()
{
    ListeDugum* gec =ilk;
    while(gec!=0)
    {
        ListeDugum* silinecek = gec;
        gec=gec->sonraki;

        delete silinecek;
    }
}
void Liste::ekle(Kromozom* kromozom)
{
    ListeDugum* yeniListeDugum = new ListeDugum(kromozom);
    if(ilk==0)
    {
        ilk = yeniListeDugum;
    }
    else
    {
        ListeDugum* gec = ilk;

        while(gec->sonraki!=0)
        {
            gec=gec->sonraki;
        }

        gec->sonraki = yeniListeDugum;
        yeniListeDugum->onceki = gec;
    }
}
ListeDugum* Liste::ilkGetir()
{
    if(ilk!=0)
        return ilk;
    throw std::out_of_range("Liste::ilkGetir(): Liste bos Hatasi");
}

ListeDugum* Liste::ListeDugumGetir(int sira)
{
    ListeDugum* gec = ilk;

    while(sira>=0&&gec!=0)
    {
       
        if(sira==0)
            return gec;
        gec=gec->sonraki;

        sira--;
    }

    return 0;
}
