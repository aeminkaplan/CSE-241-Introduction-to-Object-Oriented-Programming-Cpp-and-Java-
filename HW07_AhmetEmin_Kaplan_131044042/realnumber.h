/* 
 * File:   realnumber.h
 * Author: aek
 *
 * Created on December 15, 2015, 12:36 AM
 */

#ifndef REALNUMBER_H
#define	REALNUMBER_H
#include<iostream>

#include "complexnumber.h"
using namespace std;
namespace AKaplan{
class realnumber:public complexnumber{

public:
        realnumber(int realN,int realD);
        realnumber();
        bool operator <(const realnumber& other)const;
        
private:

};

}
#endif	/* REALNUMBER_H */

