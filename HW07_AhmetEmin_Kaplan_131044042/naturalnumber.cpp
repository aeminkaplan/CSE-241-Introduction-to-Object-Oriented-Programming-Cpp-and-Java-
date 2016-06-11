#include"naturalnumber.h"
#include<cstdlib>
namespace AKaplan{
    naturalnumber::naturalnumber(int n)
    {
        if(n>=0)
        {
            setImaginarypartNom(0);
            setImaginarypartDenom(1);
            setRealpartNom(n);
            setRealpartDenom(1);
        }
        
        else{
        
            cout<<"Hatali sayi\n";
            exit(1);
        }
    }
    
    naturalnumber::naturalnumber():integer(0)
    {
    /*Empty*/
    }
    
}   