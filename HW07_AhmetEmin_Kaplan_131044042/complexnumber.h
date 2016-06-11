/* 
 * File:   complexnumber.h
 * Author: aek
 *
 * Created on December 14, 2015, 6:15 PM
 */
#include<iostream>
using namespace std;
#ifndef COMPLEXNUMBER_H
#define	COMPLEXNUMBER_H
namespace AKaplan{
class complexnumber{

public:
    int ebob(int n1,int n2)const;
    complexnumber();
    complexnumber(int realpartN,int realpartD,int imaginaryN,int imaginaryD);
    int getImaginaryNom()const;
    int getImaginaryDenom()const;
    int getRealpartNom()const;
    int getRealpartDenom()const;
    void setImaginarypartNom(int i);
    void setImaginarypartDenom(int i);
    void setRealpartNom(int r);
    void setRealpartDenom(int r);
    const complexnumber operator+(const complexnumber& other)const;
    const complexnumber operator-(const complexnumber& other)const;
    bool operator<(const complexnumber& other)const;
    friend ostream& operator<<(ostream& out,const complexnumber& other);
    
private:
    int imaginaryNom;
    int imaginaryDenom;
    int realpartNom;
    int realpartDenom;
};
}

#endif	/* COMPLEXNUMBER_H */

