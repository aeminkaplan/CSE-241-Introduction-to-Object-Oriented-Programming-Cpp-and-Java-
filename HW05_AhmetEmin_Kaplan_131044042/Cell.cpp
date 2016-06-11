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

bool Cell::operator>(const Cell& other)const
{
    if(getY()>other.getY())
        return true;
    else if(getY()<other.getY())
    {
        return false;
    }

    else if(getY()==other.getY())
    {
        if(getX()>other.getX())
            return true;
        else
            return false;
    }

}

bool Cell::operator<(const Cell& other)const
{
    if(getY()<other.getY())
        return true;
    
    else if(getY()>other.getY())
    {
        return false;
    }

    else if(getY()==other.getY())
    {
        if(getX()<other.getX())
            return true;
        else
            return false;
    }


}

bool Cell::operator>=(const Cell& other)const
{
    if(getY()>=other.getY())
        return true;

    else if(getY()<other.getY())
    {
        return false;
    }

    else if(getY()==other.getY())
    {
        if(getX()>=other.getX())
            return true;
        else 
            return false;
    }    
}

bool Cell::operator<=(const Cell& other)const
{
    if(getY()<=other.getY())
        return true;

    else if(getY()>other.getY())
    {
        return false;
    }

    else if(getY()==other.getY())
    {
        if(getX()<=other.getX())
            return true;
        else 
            return false;
    }  


}
bool Cell::operator==(const Cell& other)const
{
    if(getY()==other.getY() && getX()==other.getX())
        return true;
    else
        return false;
}

bool Cell::operator!=(const Cell& other)const
{
    if(getY()==other.getY() && getX()==other.getX())
        return false;
    else
        return true;
}
ostream& operator<<(ostream& outputStream ,const Cell& myCell)
{

    outputStream<<"X: "<<myCell.getX()<<" Y: "<<myCell.getY()<<" ID:"<<myCell.getID()<<endl;
    return outputStream;
}

    Cell Cell::operator++(int)
    {
        int oldX,oldY;
        
        oldX=getX();
        oldY=getY();
        
        setX(oldX+1);
        setY(oldY+1);
        
        return Cell(oldX,oldY,getID());
    }
    
    Cell Cell::operator++()
    {
        setX(getX()+1);
        setY(getY()+1);
        
        return *this;
    }
    
    Cell Cell::operator--()
    {
        setX(getX()-1);
        setY(getY()-1);
        return *this;
    
    }
    Cell Cell::operator--(int)
    {
            int oldX,oldY;
        
        oldX=getX();
        oldY=getY();
        
        setX(oldX-1);
        setY(oldY-1);
        
        return Cell(oldX,oldY,getID());
    
    
    }
    
istream& operator>>(istream& inputStream ,Cell& myCell)
{
    int x,y;
    char id;
    inputStream>>x>>y>>id;
    myCell.setX(x);
    myCell.setY(y);
    myCell.setID(id);
    return inputStream;
}