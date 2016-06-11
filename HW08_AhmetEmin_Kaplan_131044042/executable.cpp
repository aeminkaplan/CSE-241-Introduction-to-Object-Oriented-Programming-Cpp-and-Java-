#include"executable.h"
namespace AEminKaplan{
    void executable::ls(const string mode)const{
    
    
        cout<<"Executable dosya icin ls komutu cagrilamaz\n";  
    }
    file& executable::cd(const string name){
     
         cout<<"Executable dosya icin cd komutu cagrilamaz\n";
     } 
     
     bool executable::cp(const file& cpfile){
         
         cout<<"Executable dosya icin cp komutu cagrilamaz\n";
         
         return false;
     }
}