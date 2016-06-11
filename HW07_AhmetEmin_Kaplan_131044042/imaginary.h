/* 
 * File:   imaginary.h
 * Author: aek
 *
 * Created on December 14, 2015, 7:29 PM
 */
#include"complexnumber.h"
#ifndef IMAGINARY_H
#define	IMAGINARY_H
#include<iostream>
using namespace std;
namespace AKaplan {

    class imaginary : public complexnumber {
    public:

        imaginary() : complexnumber(0, 1, 0, 1) {
            /*Empthy*/
        }

        imaginary(int imaginaryN, int imaginaryD) : complexnumber(0, 1, imaginaryN, imaginaryD) {
            /*Empthy*/
        }

    private:
    };
}
#endif	/* IMAGINARY_H */

