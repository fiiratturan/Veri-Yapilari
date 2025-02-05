/**
* @file B201210308
* @description Bir txt dosyasındaki verileri kordinant olarak kuyrugu ekleme ve orjine yakınlığa göre sıralama kordinatlar arası mesafeye göre AVL ağacı oluşturma
* @course 2.Ögretim B Grubu
* @assignment 2.Ödev
* @date (23.12.2021 - 26.12.2021)
* @author Fırat Turan - firat.turan2@ogr.sakarya.edu.tr
*/

#include "AVLAgaci.hpp"

AVLAgaci::AVLAgaci()
{
    kok= 0;
}
AVLAgaci::~AVLAgaci()
{

}
void AVLAgaci::ekle(DogruKuyrugu* kuyruk)
{
    kok = ekle(kuyruk,kok);
}
int AVLAgaci::yukseklik() 
{
	return yukseklik(kok);
}

void AVLAgaci::postOrder() {
    postOrder(kok);
    cout<<endl;
}

void AVLAgaci::postOrder(AVLDugum* aktif) 
{
	if(aktif)
    {       
        postOrder(aktif->sol);
        postOrder(aktif->sag);
        aktif->kuyruk->Listele();
        cout<<endl;
    }	  
}

int AVLAgaci::yukseklik(AVLDugum* aktifDugum) 
{
	if(aktifDugum)
    {
        return 1+max(   yukseklik(aktifDugum->sol),
                        yukseklik(aktifDugum->sag));
    }
    return -1;
}
AVLDugum* AVLAgaci::ekle(DogruKuyrugu* kuyruk,AVLDugum* aktifDugum ) 
{
    if(aktifDugum==0)
        return new AVLDugum(kuyruk);

	else if(aktifDugum->veri<kuyruk->toplam)
    {
        
        aktifDugum->sag=ekle(kuyruk,aktifDugum->sag);
        if(yukseklik(aktifDugum->sag)-yukseklik(aktifDugum->sol)>1)
        {   
            if(kuyruk->toplam>aktifDugum->sag->veri)
                aktifDugum = solaDondur(aktifDugum);
                
            else
            {
                aktifDugum->sag = sagaDondur(aktifDugum->sag);
                aktifDugum =solaDondur(aktifDugum);
            }
        }
    }
    else if(aktifDugum->veri>kuyruk->toplam)
    {
         
        aktifDugum->sol = ekle(kuyruk,aktifDugum->sol);
        if(yukseklik(aktifDugum->sol)-yukseklik(aktifDugum->sag)>1)
        {

            if(kuyruk->toplam<aktifDugum->sol->veri)
                aktifDugum = sagaDondur(aktifDugum);
            else
            {
                aktifDugum->sol = solaDondur(aktifDugum->sol);
                aktifDugum =sagaDondur(aktifDugum);
            }
        }

    }
    return aktifDugum;
}
AVLDugum* AVLAgaci::solaDondur(AVLDugum* buyukEbeveyn) 
{
	AVLDugum* sagCocuk = buyukEbeveyn->sag;
    buyukEbeveyn->sag = sagCocuk->sol;
    sagCocuk->sol = buyukEbeveyn;
    return sagCocuk;
}
AVLDugum* AVLAgaci::sagaDondur(AVLDugum* buyukEbeveyn) 
{
	AVLDugum* solCocuk = buyukEbeveyn->sol;
    buyukEbeveyn->sol = solCocuk->sag;
    solCocuk->sag = buyukEbeveyn;
    return solCocuk;
}

