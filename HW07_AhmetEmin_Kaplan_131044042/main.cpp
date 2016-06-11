/* 
 * File:   main.cpp
 * Author: aek
 *
 * Created on December 12, 2015, 8:19 PM
 */

#include <cstdlib>
#include<iostream>
#include"naturalnumber.h"
#include"imaginary.h"
#include"irrational.h"

using namespace std;
using namespace AKaplan;
        
/*
 * 
 */
int main(int argc, char** argv) {


    complexnumber comp1(2,3,5,-4);
    complexnumber comp2(3,2,-3,4);

    cout<<"(((()))) TEST FOR COMPLEX NUMBERS (((())))\n";
    cout<<"comp1 ="<<comp1<<endl;
    cout<<"comp2 ="<<comp2<<endl;
    
    cout<<comp1<<"+"<<comp2<<"="<<comp1+comp2<<endl;
   
     cout<<comp1<<"-"<<comp2<<"="<<comp1-comp2<<endl;
   
     if(comp1<comp2)
         cout<<"comp1 sayisi comp2 den kucuktur\n";
     else
         cout<<"comp1 sayisi comp2 den kucuk degildir\n";
     
     
     cout<<endl<<endl;
     
     
     
     imaginary imag1(3,2),imag2(-3,2);
     
        cout<<"(((()))) TEST FOR IMAGINARY NUMBERS (((())))\n";
                
     cout<<"imag1="<<imag1<<endl;
     cout<<"imag2="<<imag2<<endl;
     
     cout<<imag1<<"+"<<imag2<<"="<<imag1+imag2<<endl;
     
     cout<<imag1<<"-"<<imag2<<"="<<imag1-imag2<<endl;
     
     if(imag1<imag2)
         cout<<"imag1 sayisi imag2 den kucuktur\n";
     else
         cout<<"imag1 sayisi imag2 den kucuk degildir\n";
     
     cout<<endl<<endl;
     
     
     
     
     realnumber real1(5,-2),real2(5,4);
         cout<<"(((()))) TEST FOR REAL NUMBERS (((())))\n";
     cout<<"real1="<<real1<<endl;
     cout<<"real2="<<real2<<endl;
     
     cout<<real1<<"+"<<real2<<"="<<real1+real2<<endl;
     
     cout<<real1<<"-"<<real2<<"="<<real1-real2<<endl;
     
     if(real1<real2)
         cout<<"real1 sayisi real2 den kucuktur\n";
     else
         cout<<"real1 sayisi real2 den kucuk degildir\n";
     
     cout<<endl<<endl;
     
     
     
     
     
     rationalnumber rtn1(2,7),rtn2(4,3);
     
         cout<<"(((()))) TEST FOR RATIONAL NUMBERS (((())))\n";
          cout<<"rtn1="<<rtn1<<endl;
     cout<<"rtn2="<<rtn2<<endl;
     
     cout<<rtn1<<"+"<<rtn2<<"="<<rtn1+rtn2<<endl;
     
     cout<<rtn1<<"-"<<rtn2<<"="<<rtn1-rtn2<<endl;
     
     if(rtn1<rtn2)
         cout<<"rtn1 sayisi rtn2 den kucuktur\n";
     else
         cout<<"rtn1 sayisi rtn2 den kucuk degildir\n";
     
     cout<<endl<<endl;
     
     
     
     
     irrational irtn1(1,3),irtn2(22,7);      
         cout<<"(((()))) TEST FOR IRRATIONAL NUMBERS (((())))\n";
     cout<<"irtn1="<<irtn1<<endl;
     cout<<"irtn2="<<irtn2<<endl;
     
     cout<<irtn1<<"+"<<irtn2<<"="<<irtn1+irtn2<<endl;
     
     cout<<irtn2<<"-"<<irtn1<<"="<<irtn2-irtn1<<endl;
     
     if(irtn1<irtn2)
         cout<<"irtn1 sayisi irtn2 den kucuktur\n";
     else
         cout<<"irtn1 sayisi irtn2 den kucuk degildir\n";
     
     
     
     cout<<endl<<endl;
     
     integer int1(-5),int2(8),int3,int4(4);
         cout<<"(((()))) TEST FOR INTEGERS (((())))\n";
     cout<<"int1="<<int1<<endl;
     cout<<"int2="<<int2<<endl;
     cout<<"int3="<<int3<<endl;
      cout<<"int4="<<int4<<endl;
     
     
     
     cout<<int1<<"+"<<int2<<"+"<<int3<<"+"<<int4<<"=";
     cout<<int1+int2+int3+int4<<endl;
     
     cout<<int1<<"+"<<int3<<"-"<<int4<<"-"<<int2<<"=";
     cout<<int1+int3-int4-int2<<endl;
     
     if(int1<int2)
         cout<<"int1 sayisi int2 den kucuktur\n";
     else
         cout<<"int1 sayisi int2 den kucuk degildir\n";
     
     
     cout<<endl<<endl;
     
     naturalnumber ntr1(0),ntr2(7),ntr3(3),ntr4(4);
         cout<<"(((()))) TEST FOR NATURAL NUMBERS (((())))\n";
     cout<<"ntr1="<<ntr1<<endl;
     cout<<"ntr2="<<ntr2<<endl;
     cout<<"ntr3="<<ntr3<<endl;
     cout<<"ntr4="<<ntr4<<endl;
     
     cout<<ntr1<<"+"<<ntr2<<"+"<<ntr3<<"+"<<ntr4<<"=";
     cout<<ntr1+ntr2+ntr3+ntr4<<endl;
     
     cout<<ntr1<<"-"<<ntr2<<"+"<<ntr3<<"-"<<ntr4<<"=";
     cout<<ntr1-ntr2+ntr3-ntr4<<endl;
     
    if(ntr1<ntr2)
         cout<<"ntr1 sayisi ntr2 den kucuktur\n";
     else
         cout<<"ntr1 sayisi ntr2 den kucuk degildir\n";
      
     if(ntr2<ntr3)
         cout<<"ntr2 sayisi ntr3 den kucuktur\n";
     else
         cout<<"ntr2 sayisi ntr3 den kucuk degildir\n";
     
    if(ntr4<ntr2)
         cout<<"ntr4 sayisi ntr2 den kucuktur\n";
     else
         cout<<"ntr4 sayisi ntr2 den kucuk degildir\n";
     
  
     cout<<endl<<endl;
    return 0;
}

