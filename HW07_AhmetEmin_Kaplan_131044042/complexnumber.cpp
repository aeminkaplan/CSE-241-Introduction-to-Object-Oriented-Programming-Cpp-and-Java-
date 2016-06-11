#include"complexnumber.h"
#include<cmath>
#include<iostream>
#include<cstdlib>
using namespace std;
namespace AKaplan {

    int complexnumber::ebob(int n1, int n2)const {
        int e = 1;


        if (n1 < 0)
            n1 = n1*-1;


        if (n2 < 0)
            n2 = n2*-1;


        if (n1 > n2) {
            for (int i = 1; i <= n2; ++i) {
                if (n1 % i == 0 && n2 % i == 0)
                    e = i;
            }
        }
        else {

            for (int i = 1; i <= n1; ++i) {
                if (n1 % i == 0 && n2 % i == 0)
                    e = i;
            }

        }

        return e;
    }

    complexnumber::complexnumber() {
        imaginaryDenom = 1;
        imaginaryNom = 0;
        realpartDenom = 1;
        realpartNom = 0;
    }

    complexnumber::complexnumber(int realpartN, int realpartD, int imaginaryN, int imaginaryD) {
        if (realpartD == 0 || imaginaryD == 0) {
            cout << "Hatali sayi\n";
            exit(1);
        }
        else {

            imaginaryDenom = imaginaryD / ebob(imaginaryD, imaginaryN);
            imaginaryNom = imaginaryN / ebob(imaginaryD, imaginaryN);
            realpartDenom = realpartD / ebob(realpartD, realpartN);
            realpartNom = realpartN / ebob(realpartD, realpartN);

            if (imaginaryDenom < 0 && imaginaryNom < 0) {
                imaginaryDenom = imaginaryDenom*-1;
                imaginaryNom = imaginaryNom*-1;

            }
            if (realpartDenom < 0 && realpartNom < 0) {
                realpartDenom = realpartDenom*-1;
                realpartNom = realpartNom*-1;
            }


            if (realpartDenom < 0 && realpartNom > 0) {
                realpartDenom = realpartDenom*-1;
                realpartNom = realpartNom*-1;
            }


            if (imaginaryDenom < 0 && imaginaryNom > 0) {
                imaginaryDenom = imaginaryDenom*-1;
                imaginaryNom = imaginaryNom*-1;

            }


        }


    }

    int complexnumber::getImaginaryNom()const {
        return imaginaryNom;
    }

    int complexnumber::getImaginaryDenom()const {
        return imaginaryDenom;
    }

    int complexnumber::getRealpartNom()const {
        return realpartNom;
    }

    int complexnumber::getRealpartDenom()const {
        return realpartDenom;
    }

    void complexnumber::setImaginarypartNom(int i) {
        imaginaryNom = i;
    }

    void complexnumber::setImaginarypartDenom(int i) {
        if (i != 0)
            imaginaryDenom = i;
        else {
            cout << "Hatali set etme girisimi!\n";
            exit(1);
        }

    }

    void complexnumber::setRealpartNom(int r) {
        realpartNom = r;

    }

    void complexnumber::setRealpartDenom(int r) {
        if (r != 0)
            realpartDenom = r;
        else {
            cout << "Hatali set etme girisimi!\n";
            exit(1);
        }

    }

    /*Eger gerekliyse payda esitleme islemi sonrasinda toplama islemini yapar*/

    const complexnumber complexnumber::operator+(const complexnumber& other)const {
        int temprealnom;
        int temprealdenom;
        int tempimaginarynom;
        int tempimaginarydenom;

        if (getRealpartDenom() == other.getRealpartDenom()) {
            temprealnom = getRealpartNom() + other.getRealpartNom();
            temprealdenom = getRealpartDenom();
        }

        if (getImaginaryDenom() == other.getImaginaryDenom()) {
            tempimaginarynom = getImaginaryNom() + other.getImaginaryNom();
            tempimaginarydenom = getImaginaryDenom();
        }

        if (getImaginaryDenom() != other.getImaginaryDenom()) {
            int imnom, imdenom;
            imnom = (other.getImaginaryDenom() * getImaginaryNom())+(getImaginaryDenom() * other.getImaginaryNom());
            imdenom = other.getImaginaryDenom() * getImaginaryDenom();
            int e = ebob(imnom, imdenom);
            imnom = imnom / e;
            imdenom = imdenom / e;
            tempimaginarynom = imnom;
            tempimaginarydenom = imdenom;
        }

        if (getRealpartDenom() != other.getRealpartDenom()) {
            int renom, redenom;
            renom = (other.getRealpartDenom() * getRealpartNom())+(getRealpartDenom() * other.getRealpartNom());
            redenom = other.getRealpartDenom() * getRealpartDenom();
            int e = ebob(renom, redenom);

            renom = renom / e;
            redenom = redenom / e;
            temprealnom = renom;
            temprealdenom = redenom;
        }

        return complexnumber(temprealnom, temprealdenom, tempimaginarynom, tempimaginarydenom);
    }

    const complexnumber complexnumber::operator-(const complexnumber& other)const {
        complexnumber temp = other;
        temp.setImaginarypartNom(temp.getImaginaryNom()*-1);
        temp.setRealpartNom(temp.getRealpartNom()*-1);
        return this->operator+(temp);
    }

    /*Complex sayinin orjine uzakligini buyukluk olarak kabul edip kiyaslama yapar*/

    bool complexnumber::operator<(const complexnumber& other)const {

        double first, second, temp1, temp2, temp3, temp4;

        temp1 = pow(getImaginaryNom(), 2);
        temp2 = pow(getImaginaryDenom(), 2);
        temp3 = pow(getRealpartNom(), 2);
        temp4 = pow(getRealpartDenom(), 2);

        first = sqrt((temp1 / temp2)+(temp3 / temp4));

        temp1 = pow(other.getImaginaryNom(), 2);
        temp2 = pow(other.getImaginaryDenom(), 2);
        temp3 = pow(other.getRealpartNom(), 2);
        temp4 = pow(other.getRealpartDenom(), 2);

        second = sqrt((temp1 / temp2)+(temp3 / temp4));

        if (first < second)
            return true;
        else
            return false;
    }

    ostream& operator<<(ostream& out, const complexnumber& other) {
        out << "(";
        if (other.realpartNom == 0 && other.imaginaryNom == 0) {
            out << 0;
            out << ")";
            return out;
        }

        if (other.realpartDenom == 1 && other.realpartNom != 0)
            out << other.realpartNom << " ";

        else if (other.realpartNom != 0 && other.realpartDenom != 1) {
            out << other.realpartNom << "/" << other.realpartDenom << " ";
        }

        if (other.realpartNom != 0 && other.imaginaryNom > 0) {
            out << "+ ";
        }

        if (other.imaginaryDenom == 1 && other.imaginaryNom > 0) {
            out << other.getImaginaryNom() << "i";
        } else if (other.imaginaryDenom == 1 && other.imaginaryNom < 0) {
            out << other.getImaginaryNom() << "i";
        } else if (other.imaginaryDenom != 1 && other.imaginaryNom > 0) {
            out << other.getImaginaryNom() << "/" << other.getImaginaryDenom() << "i";
        } else if (other.imaginaryDenom != 1 && other.imaginaryNom < 0) {
            out << other.getImaginaryNom() << "/" << other.getImaginaryDenom() << "i";
        }
        out << ")";
        return out;
    }
}