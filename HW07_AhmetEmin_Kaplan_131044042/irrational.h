/* 
 * File:   irrational.h
 * Author: aek
 *
 * Created on December 15, 2015, 9:27 PM
 */

#ifndef IRRATIONAL_H
#define	IRRATIONAL_H
#include "realnumber.h"

#include<iostream>
using namespace std;

namespace AKaplan {

    class irrational : public realnumber {
    public:

        irrational() : realnumber(0, 1) {

        }

        irrational(int irrationalN, int irrationalD) : realnumber(irrationalN, irrationalD) {

        }
    private:

    };
}
#endif	/* IRRATIONAL_H */

