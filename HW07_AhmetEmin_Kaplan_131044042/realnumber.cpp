#include"realnumber.h"
#include<iostream>

using namespace std;
namespace AKaplan{
realnumber::realnumber(int realN,int realD):complexnumber(realN,realD,0,1)
{/*Empty*/}

realnumber::realnumber():complexnumber(0,1,0,1)
{/*Empty*/}
        
bool realnumber::operator <(const realnumber& other)const
{
    
    int temp,temp2;
    
    temp=getRealpartNom()*other.getRealpartDenom();
    temp2=other.getRealpartNom()*getRealpartDenom();
    
    if(temp<temp2)
        return true;
    else
        return false;
}
}