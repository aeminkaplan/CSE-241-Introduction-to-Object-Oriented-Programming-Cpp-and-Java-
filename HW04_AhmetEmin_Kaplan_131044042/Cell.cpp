#include"Cell_Header.h"
using namespace std;

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
