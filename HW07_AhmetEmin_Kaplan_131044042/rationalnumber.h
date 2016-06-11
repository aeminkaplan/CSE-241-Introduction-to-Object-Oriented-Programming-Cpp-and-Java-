/* 
 * File:   rationalnumber.h
 * Author: aek
 *
 * Created on December 13, 2015, 1:15 PM
 */
#include"realnumber.h"
#include<iostream>
using namespace std;
#ifndef RATIONALNUMBER_H
#define	RATIONALNUMBER_H
namespace AKaplan{
class rationalnumber : public realnumber {
public:
    rationalnumber():realnumber(0,1)
    {/*Empty*/}
    rationalnumber(int rationalN,int rationalD):realnumber(rationalN,rationalD)
    {/*Empty*/}
    
private:

};

}
#endif	/* RATIONALNUMBER_H */

