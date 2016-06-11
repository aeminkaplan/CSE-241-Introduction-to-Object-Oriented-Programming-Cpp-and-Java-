/* 
 * File:   integer.h
 * Author: aek
 *
 * Created on December 12, 2015, 9:02 PM
 */

#include<iostream>
using namespace std;

#ifndef INTEGER_H
#define	INTEGER_H
#include "rationalnumber.h"
#include<iostream>
using namespace std;
namespace AKaplan{

class integer:public rationalnumber{


public:
    integer():rationalnumber(0,1)
    {/*Empty*/}
    integer(int i):rationalnumber(i,1)
    {/*Empty*/}
    
private:
   
};
}
#endif	/* INTEGER_H */

