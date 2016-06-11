/* 
 * File:   main.cpp
 * Author: aek
 *
 * Created on November 2, 2015, 9:52 PM
 */

/*HW03_AhmetEmin_Kaplan_131044042.cpp*/
/*Triangle sinifi uzerinde islemler yapan programdır*/

#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;


class Triangle
{
    public:
    Triangle();
    Triangle(double value);
    Triangle(double _sideA,double _sideB);
    Triangle(double _sideA,double _sideB,double _sideC);
    
    double GetSideA()const {return sideA;}
    double GetSideB()const {return sideB;}
    double GetSideC()const {return sideC;}
    
    void Setter(double _sideA,double _sideB,double _sideC);
    
    double getAngleA()const;
    double getAngleB()const;
    double getAngleC()const;
    
    void input();
    void output() const;

    double getAreaOfTriangle()const;

    double getPerimeter()const{return GetSideA()+GetSideB()+GetSideC();}
    
    bool isInAnyRightAngle()const;
    
    private:
    
    void SetSideA(double _sideA){sideA=_sideA;}
    void SetSideB(double _sideB){sideB=_sideB;}
    void SetSideC(double _sideC){sideC=_sideC;}
    
    double sideA;
    double sideB;
    double sideC;
};



//Global degisken ve fonksiyon prototipleri
const double pi=3.14159265359;
Triangle TestFunction1(Triangle myTriangle);
void TestFunction2(Triangle& myTriangle);


int main()
{  
    Triangle ucgen1(2.5,2.0);
    Triangle ucgen2;
   ucgen2=TestFunction1(ucgen1);

    TestFunction2(ucgen2);
    
    
}

void TestFunction2(Triangle& myTriangle)
{
    cout<<"\n\n\nTest2 fonksiyonu icindeki myTriangle ucgenine ait fonksiyon testleri\n";
    myTriangle.output();
    cout<<"Ucgenin cevresi : " <<myTriangle.getPerimeter()<<endl;
    cout<<"Ucgenin Alani " <<myTriangle.getAreaOfTriangle()<<endl;
    cout<<"Ucgenin ic acilari sirasiyla A,B,C--> "<<myTriangle.getAngleA()<<"  "<<myTriangle.getAngleB()<<"  "<<myTriangle.getAngleC()<<endl;
    if(myTriangle.isInAnyRightAngle())
    cout<<"Bu ucgen bir dik ucgendir\n";
    else
    cout<<"Bu ucgen bir dik ucgen DEGILDIR\n";
     
    myTriangle.input();
    cout<<"Degerleri basariyla girdiniz\n";
        

}



Triangle TestFunction1(Triangle myTriangle)
{

    cout<<"Test1 fonksiyonu icindeki myTriangle ucgenine ait fonksiyon testleri\n";
    
    myTriangle.output();
    cout<<"Ucgenin cevresi : " <<myTriangle.getPerimeter()<<endl;
    cout<<"Ucgenin Alani " <<myTriangle.getAreaOfTriangle()<<endl;
    cout<<"Ucgenin ic acilari sirasiyla A,B,C--> "<<myTriangle.getAngleA()<<"  "<<myTriangle.getAngleB()<<"  "<<myTriangle.getAngleC()<<endl;
    if(myTriangle.isInAnyRightAngle())
    cout<<"Bu ucgen bir dik ucgendir\n";
    else
    cout<<"Bu ucgen bir dik ucgen DEGILDIR\n";
     
    myTriangle.input();
    cout<<"Degerleri basariyla girdiniz\n";
        
    return myTriangle;
}

void Triangle::Setter(double _sideA,double _sideB,double _sideC)
{

    //Ucgenin herhangi bir kenarinin uzunlugu eksi veya sifir olamaz eger eksiyse programdan cikilir
    if(_sideA <=0 || _sideB <=0 || _sideC <=0)
    {   cerr<<"Gecersiz ucgen degerleri\n";
        exit(1);
    }
    // C kenarinin uzunlugu A+B ve A-B arasinda olmalidir aksi taktirde programdan cikilir.
    if(!((_sideA + _sideB > _sideC ) && (_sideC>fabs(_sideA-_sideB))))
    {   cerr<<"Gecersiz ucgen degerleri\n";
        exit(1);
    }
    // B kenarinin uzunlugu A+C ve A-C arasinda olmalidir aksi taktirde programdan cikilir.
    if(!((_sideA + _sideC > _sideB ) && (_sideB>fabs(_sideA-_sideC))))
    {   cerr<<"Gecersiz ucgen degerleri\n";
        exit(1);
    }
    // A kenarinin uzunlugu B+C ve B-C arasinda olmalidir aksi taktirde programdan cikilir.
    if(!((_sideB + _sideC > _sideA ) && (_sideA>fabs(_sideB-_sideC))))
    {   cerr<<"Gecersiz ucgen degerleri\n";
        exit(1);
    } 
   // Eger yukardaki kosullar saglanmiyorsa ucgen objemiz kurallara uymaktadir.  
   
   SetSideA(_sideA);
   SetSideB(_sideB);
   SetSideC(_sideC);


}
//Sinusun alan formulunden iki kenarin carpiminin yarisi ile o iki kenar arasindaki acinin carpimi alani verir
double Triangle::getAreaOfTriangle()const
{
    return 0.5 * GetSideA() * GetSideB() * sin(getAngleC()*pi/180.0);
}

//Pisagor teoremi ile dik ucgen olup olmadigi hesaplanir
bool Triangle::isInAnyRightAngle()const
{
    bool temp=false;
    

    if((GetSideA()*GetSideA())+(GetSideB()*GetSideB())==(GetSideC()*GetSideC()))
     temp=true;
    else if((GetSideB()*GetSideB())+(GetSideC()*GetSideC())==(GetSideA()*GetSideA()))
     temp=true;
    else if((GetSideA()*GetSideA())+(GetSideC()*GetSideC())==(GetSideB()*GetSideB()))
     temp=true;
    
    return temp;            
}


//Cosinus teoremi kullanilarak aci degerleri hesaplanir

double Triangle::getAngleA() const
{
    
    double angle;
    double a,b,c;
    
    a=GetSideA();
    b=GetSideB();
    c=GetSideC();
    
    angle=acos(((b*b)+(c*c)-(a*a))/(2*b*c));

    angle=angle*180/pi;

    return angle;
}

double Triangle::getAngleB() const
{
    
    double angle;
    double a,b,c;
    
    a=GetSideA();
    b=GetSideB();
    c=GetSideC();
    
    angle=acos(((a*a)+(c*c)-(b*b))/(2*a*c));
    
    angle=angle*180/pi;
    
    return angle;
}

double Triangle::getAngleC() const
{
    double angle;
    double a,b,c;
    a=GetSideA();
    b=GetSideB();
    c=GetSideC();
    
    angle=acos(((a*a)+(b*b)-(c*c))/(2*a*b));
    
    angle=angle*180/pi;
    
    return angle;
}
void Triangle::input()
{   
    double a,b,c;
    cout<<"Ucgenin yeni kenar uzunluklarini sirasiyla giriniz A,B,C)"<<endl;
    cin>>a;
    cin>>b;
    cin>>c;
    
    Setter(a,b,c);
    
}

void Triangle::output() const
{
        cout<<"A:"<<GetSideA()<<" B: "<<GetSideB()<<" C: "<<GetSideC()<<endl;
}

Triangle::Triangle()
{
    Setter(1.0,1.0,1.0);
}

Triangle::Triangle(double value)
{
    Setter(value,value,value);
}

Triangle::Triangle(double _sideA,double _sideB)
{   
    Setter(_sideA,_sideB,1.0);
}

Triangle::Triangle(double _sideA,double _sideB,double _sideC)
{
    Setter(_sideA,_sideB,_sideC);
}
