/* 
 * File:   Cell_Header.h
 * Author: aek
 *
 * Created on November 23, 2015, 11:25 PM
 */

#ifndef CELL_HEADER_H
#define	CELL_HEADER_H
#include<iostream>
namespace AhmetEminKaplan_Cell{
    class Cell {
    public:
        Cell();
        Cell(int _Xcordinate, int _Ycordinate, char _ID);

        int getX()const {
            return Xcordinate;
        }

        int getY()const {
            return Ycordinate;
        }

        char getID()const {
            return ID;
        }

        //Object-oriented kurallarin disina cikmasina ragmen boyle bir fonksiyon
        //tanimlamak zorunda kaldim olusturulmus reversi objelerini set edince olusmus
        //cell sayisi degisecegi icin sifirla isini bu fonksiyonla yaptim
        static void reduce_num_of_cell(){--numberOfCell;}

        static int num_of_cell() {
            return numberOfCell;
        }



        void setID(char newID) {
            ID = newID;
        }
        void output()const;
    private:
        int Xcordinate;
        int Ycordinate;
        char ID;
        static int numberOfCell;
};
}
#endif	/* CELL_HEADER_H */

