/**
* @file G201210064
* @description Bu ödevde tek yönlü bağlı liste ve ikili arama ağacı kullanılarak istenen işlemler gerçekleştirilecektir.
* @course 2.Ögretim A Grubu
* @assignment 2.Ödev
* @date (20.12.2024 - 25.12.2024)
* @author Necati Babacan- necati.babacan@ogr.sakarya.edu.tr
*/

#include "IkiliAramaAgaci.hpp"
#include <iomanip>
#include<iostream>
#include<cmath>
#include<queue>
using namespace std;

IkiliAramaAgaci::IkiliAramaAgaci()
{
    kok= 0;
}
IkiliAramaAgaci::~IkiliAramaAgaci()
{

}
bool IkiliAramaAgaci::varmi(char veri) 
{
    varmi(veri,kok);
}
void IkiliAramaAgaci::ekle(char eklenecek)
{
    if(kok==0)
        kok=new IAA_DUGUM(eklenecek);
    else
        ekle(eklenecek,kok);
}
void IkiliAramaAgaci::sil(char veri) 
{
	sil(veri,kok); 
}
int IkiliAramaAgaci::yukseklik() 
{
	return yukseklik(kok);
}
void IkiliAramaAgaci::preOrder() {
    preOrder(kok);
    cout<<endl;
}
void IkiliAramaAgaci::postOrder() {
	postOrder(0);
}
void IkiliAramaAgaci::inOrder() {
    inOrder(0);
}
void IkiliAramaAgaci::levelOrder(IAA_DUGUM* aktif,int level) 
{
	if(aktif)
    {
        if(level==0)
        {
            boslukBirak(aktif->yukseklik);
            cout<<setw(5)<<aktif->veri;
        }
        else
        {

            if(aktif->sol)
                levelOrder(aktif->sol,level-1);
            else
            {
                 boslukBirak(aktif->yukseklik);
                 cout<<setw(5)<<"bos";
            }
                
         

            if(aktif->sag)
                levelOrder(aktif->sag,level-1);
            else
            {
                 boslukBirak(aktif->yukseklik);
                 cout<<setw(5)<<"bos";
            }
            
         
        }
    }
}
void IkiliAramaAgaci::levelOrder()
 {
        if(kok==0)
    return;
	queue<IAA_DUGUM*> kuyruk;

    kuyruk.push(kok);

    int seviye=0;
    int yuksek = yukseklik();
    int kat=0;
    cout<<endl;
    while(!kuyruk.empty()&&seviye<=yuksek)
    {
       
        auto siradaki = kuyruk.front();
        kuyruk.pop();
      
        if(kat==0)
            boslukBirak(yuksek-seviye);
        if(siradaki)
            cout<<setw(1)<<siradaki->veri;
        else
            cout<<setw(1)<<".";
        boslukBirak(yuksek-seviye+1);
        
        if(siradaki)
        {
            kuyruk.push(siradaki->sol);
            kuyruk.push(siradaki->sag);
        } 
        else
        {
            kuyruk.push(0);
            kuyruk.push(0);         
        }
        kat++;
        if(pow(2,seviye)==kat)
        {
            cout<<endl;    
            seviye++;
            kat=0;
             
        }

           
    }
}
void IkiliAramaAgaci::preOrder(IAA_DUGUM* aktif) 
{
    
	if(aktif)
    {
        cout<<aktif->veri<<"  ";
        preOrder(aktif->sol);
        
        preOrder(aktif->sag);
    }
}
void IkiliAramaAgaci::postOrder(IAA_DUGUM* aktif) 
{
	if(aktif)
    {
        
        postOrder(aktif->sol);
        postOrder(aktif->sag);
        cout<<aktif->veri<<"  ";
    }	
}
void IkiliAramaAgaci::inOrder(IAA_DUGUM* aktif) 
{
	if(aktif)
    {
        
        inOrder(aktif->sol);
        cout<<aktif->veri<<"  ";        
        inOrder(aktif->sag);
        
    }	
}
int IkiliAramaAgaci::yukseklik(IAA_DUGUM* aktifIAA_DUGUM) 
{
	if(aktifIAA_DUGUM)
    {
        aktifIAA_DUGUM->yukseklik= 1+max(   yukseklik(aktifIAA_DUGUM->sol),
                        yukseklik(aktifIAA_DUGUM->sag));
        return aktifIAA_DUGUM->yukseklik;
    }
    return -1;
}
void IkiliAramaAgaci::ekle(char veri,IAA_DUGUM* aktifIAA_DUGUM) 
{
	if(aktifIAA_DUGUM->veri>veri)
    {
        if(aktifIAA_DUGUM->sol)
            ekle(veri,aktifIAA_DUGUM->sol);
        else
            aktifIAA_DUGUM->sol = new IAA_DUGUM(veri);
    }
    else if(aktifIAA_DUGUM->veri<veri)
    {
        if(aktifIAA_DUGUM->sag)
            ekle(veri,aktifIAA_DUGUM->sag);
        else
            aktifIAA_DUGUM->sag= new IAA_DUGUM(veri);
    }
    else
        return;
}

void IkiliAramaAgaci::silDonguile(IAA_DUGUM* aktif,IAA_DUGUM* ebeveyn) 
{
    
    IAA_DUGUM* yeniIAA_DUGUM;
    if(!aktif->sag&&!aktif->sol)
    {
        yeniIAA_DUGUM = 0;
    }    
	else if(!aktif->sol) //sadece sağ düğüm var ise
    {
        yeniIAA_DUGUM = aktif->sag;
    }
    else if(!aktif->sag)
    {
        yeniIAA_DUGUM = aktif->sol;
    }
    else
    {
        IAA_DUGUM* ebeveyn= aktif;

        IAA_DUGUM* enbuyuk = aktif->sol;

        while(enbuyuk->sag!=0)
        {
            ebeveyn = enbuyuk;
            enbuyuk = enbuyuk->sag;
        }
        aktif->veri = enbuyuk->veri;

        ebeveyn->sag = enbuyuk->sol;
       
        delete enbuyuk;
        return ;
    }

    if(aktif==ebeveyn->sol)
        ebeveyn->sol = yeniIAA_DUGUM;
    else if(aktif==ebeveyn->sag)
    {
        ebeveyn->sag = yeniIAA_DUGUM;
    } 
    delete aktif;
}
void IkiliAramaAgaci::sil(char aranan,IAA_DUGUM* &aktif) 
{
    if(aktif==0)        return;
	if(aktif->veri>aranan)
        sil(aranan,aktif->sol);
    else if(aktif->veri<aranan)
        sil(aranan,aktif->sag);
    else
    {
        if(aktif->sag&&aktif->sol)
        {
            aktif->veri = maxDeger(aktif->sol);
            sil(aktif->veri,aktif->sol);
        }
        else
        {
            IAA_DUGUM* silinecek= aktif;
            if(aktif->sol==0)
                aktif= aktif->sag;
            else if(aktif->sag==0)
                aktif = aktif->sol;
            else 
                aktif =0;
            delete silinecek;      
        }
    }
}
int IkiliAramaAgaci::maxDeger(IAA_DUGUM* aktif) 
{
    if(aktif->sag)
        return maxDeger(aktif->sag);
    
    return aktif->veri;
}
void IkiliAramaAgaci::boslukBirak(int adet) {
     int baslangicBosluk = pow(2,adet)-1;
     for(int i=0;i<baslangicBosluk;i++)
	    cout<<" ";
}
bool IkiliAramaAgaci::varmi(char aranan,IAA_DUGUM* aktif)
{
    if(aktif->veri<aranan)
    {
        if(aktif->sag)
            return varmi(aranan,aktif->sag);
        else
            return 0;
    }
    else if(aktif->veri>aranan)
    {
        if(aktif->sol)
            return varmi(aranan,aktif->sol);
        return 0;
    }
    else
    {
        return aktif;
    }
}

 ostream& operator<<(ostream& os,IkiliAramaAgaci& agac)
{
     agac.levelOrder();  

    return os;  
}

int IkiliAramaAgaci::toplamDegerHesapla()
{
    toplamDeger=kok->veri;
    return toplamDegerHesapla(kok); // Kökten başlayarak hesapla
}

int IkiliAramaAgaci::toplamDegerHesapla(IAA_DUGUM* aktif) {

    if(aktif)
    {
        int solDeger = (aktif->sol) ? aktif->sol->veri * 2 : 0;
        int sagDeger = (aktif->sag) ? aktif->sag->veri : 0;
        toplamDeger += solDeger + sagDeger;
        toplamDegerHesapla(aktif->sol);
        toplamDegerHesapla(aktif->sag);
    }
    return toplamDeger;
}
void IkiliAramaAgaci::aynalama()
{
    aynalama(kok);
}

void IkiliAramaAgaci::aynalama(IAA_DUGUM* aktif)
{
    if(aktif)
    {
        IAA_DUGUM* solDeger = (aktif->sol) ? aktif->sol : 0;
        IAA_DUGUM* sagDeger = (aktif->sag) ? aktif->sag : 0;         
        aynalama(aktif->sol);
        aynalama(aktif->sag);
         if(sagDeger==0 && solDeger!=0)
        {
            aktif->sag = solDeger;
            aktif->sol = NULL;
        }else if(solDeger==0 && sagDeger!=0)
        {
            aktif->sol = sagDeger;
            aktif->sag = NULL;
        }else if (sagDeger!=0 && solDeger!=0)
        {
            aktif->sag = solDeger;
            aktif->sol = sagDeger;
            
        }   
    }
}