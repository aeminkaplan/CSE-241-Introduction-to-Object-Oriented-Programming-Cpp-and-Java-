#include"Cell_Header.h"
using namespace std;


namespace AhmetEminKaplan_Cell{
//Cell class inin fonksiyonlarinin buyuk bir bolumu inlinedir.

    void Cell::output()const {
        cout << "X:" << getX() << " Y:" << getY() << " ID:" << getID() << endl;

    }

    //Cell objelerini initialize eden constructor

    Cell::Cell(int _Xcordinate, int _Ycordinate, char _ID) {
        Xcordinate = _Xcordinate;
        Ycordinate = _Ycordinate;
        ID = _ID;
        ++numberOfCell;
    }
    Cell::Cell()
    {
        Xcordinate=-1;
        Ycordinate=-1;
        ID='.';
    }

}