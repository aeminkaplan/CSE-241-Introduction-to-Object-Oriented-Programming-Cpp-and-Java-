/*HW02_131044042_AhmetEmin_Kaplan.cpp*/
/*Data type ayirt etmeksizin butun arraylerin modunun (en cok tekrar eden deger) ilk indexini return eder */
#include<iostream>

using namespace std;

int return_mode (const void * base, size_t num, size_t size,bool (* equals) (const void *, const void *));
bool int_equals(const void* number1,const void* number2);
bool double_equals(const void* number1,const void* number2);
bool char_equals(const void* char1,const void* char2);
bool dayOfYear_equals(const void* day1,const void* day2);
bool people_equals(const void* people1,const void* people2);

struct dayOfYear
{
    int month;
    int day;
};

class people
{
    public:
    people();
    people(int _age,int _length,char _name,char _surname);
    int getAge()const{return age;}
    int getLength()const{return length;}
    char getName()const{return name;}
    char getSurname()const{return surname;}
    void set_members(int _age,int _length,char _name,char _surname);
    
    private:    
    int age;
    int length;
    char name;
    char surname;

};


int main()
{
    /*Rasgele olusturdugum arraylerle yazdigim fonksiyonu denedim */
    
    int array_int[9]={4,8,1,5,8,4,7,8,1};
    
    double array_double[5]={1.05,2.45,2.20,8.45,8.45};
    
    char array_char[6]={'d','e','n','e','m','e'};
    
    dayOfYear days[12]={{9,6},{11,12},{12,12},{2,4},{7,4},{3,5},{1,3},{9,6},{1,3},{21,8},{9,6},{20,9}};
    
    people array_people[7];
    
//Object arrayi olustururken arraydeki object degerleri default constructor a gore belirlendigi icin
//Bazi farkli degerler olusturmak icin degerleri set ettim
    
    array_people[0].set_members(14,150,'e','t');
    array_people[1].set_members(19,170,'k','a');
    array_people[2].set_members(23,200,'n','g');
    array_people[3].set_members(11,175,'k','a');
    array_people[4].set_members(11,150,'k','a');
    array_people[5].set_members(23,200,'n','g');
    array_people[6].set_members(17,170,'k','a');
       
    cout<<"Integer arrayindeki mod elemaninin ilk indexi: "
	    <<return_mode (array_int,9,sizeof(int),int_equals)<<endl<<endl;
	cout<<"Double arrayindeki mod elemaninin ilk indexi:"
	    <<return_mode (array_double,5,sizeof(double),double_equals)<<endl<<endl;
    cout<<"Char arrayindeki mod elemaninin ilk indexi: "
        <<return_mode(array_char,6,sizeof(char),char_equals)<<endl<<endl;
    cout<<"DayOfYear structlarindan olusan arrayin mod elemaninin ilk indexi: "
        <<return_mode(days,12,sizeof(dayOfYear),dayOfYear_equals)<<endl<<endl;
    cout<<"people Classina ait objelerden olusan arrayin mod elemaninin ilk indexi: "
        <<return_mode(array_people,7,sizeof(people),people_equals)<<endl<<endl;
}

int return_mode (const void * base, size_t num, size_t size,bool (* equals) (const void *, const void *))
{
    /*Arrayler uzerinde islem yaparken bilmemiz gereken arrayin boyutu ve baslangic adresini verilen argumanlardan cikartmaliyiz*/
    

 
    int first_index=-1;
    int counter=0;
    int mode_counter=0;
    unsigned char* temp;

    unsigned char* first=(unsigned char*)base;

    unsigned char* end=(unsigned char*)(first+(num*size));

    for(unsigned char* i=first;i<end;i=i+size)
    {
        for(unsigned char* j=first;j<end;j=j+size)
           {
                if(equals(i,j))
                    ++counter;
           }        
            if(counter>mode_counter)
           { 
           /*Eger kontrol edilen eleman dizinin modu ise bu elemanin tekrar sayisi ve adresi kopyalanir*/
                mode_counter=counter;
                temp=i;
           }
        counter=0;
    }
    
    //mod olarak belirlenen elemanin ilk bulundugu indexi belirlemek icin
    //arrayin baslangic adresinden modun baslangic adresini cikartiyorum
    //boylece iki kisim arasindaki toplam byte sayisini bulmus oluyorum
    //ardindan bu degeri her bir elemanin size degerine bolunce indexi elde ediyorum
    first_index=(temp-first)/size;

    return first_index;
}


//Default constructor
//Object arrayi olustururken default degerleri iceren objelerden bir array olusacaktir
people::people()
{
    age=20;
    length=180;
    name='a';
    surname='k';
}

people::people(int _age,int _length,char _name,char _surname)
{
    age=_age;
    length=_length;
    name=_name;
    surname=_surname;
}


void people::set_members(int _age,int _length,char _name,char _surname)
{
    age=_age;
    length=_length;
    name=_name;
    surname=_surname;


}

bool dayOfYear_equals(const void* day1,const void* day2)
{
    dayOfYear* first= (dayOfYear*) day1;
    dayOfYear* second=(dayOfYear*) day2;
    
    if(first->day==second->day && first->month==second->month)
        return true;
        
    else 
        return false;


}
bool int_equals(const void* number1,const void* number2)
{
    int* i_ptr=(int*)number1;
    int* i2_ptr=(int*)number2;
    
    if(*i_ptr==*i2_ptr)
        return true;
    else
        return false;    
}

bool double_equals(const void* number1,const void* number2)
{
    double* d_ptr=(double*)number1;
    double* d2_ptr=(double*)number2;
    
    if(*d_ptr==*d2_ptr)
        return true;
    else
        return false;    
}
bool char_equals(const void* char1,const void* char2)
{
    char* c1_ptr=(char*)char1;
    char* c2_ptr=(char*)char2;

    if(*c1_ptr==*c2_ptr)
        return true;
    else
        return false;
}

bool people_equals(const void* people1,const void* people2)
{
    people* first=(people*) people1;
    people* second=(people*) people2;
    
     if(first->getAge()==second->getAge() && first->getLength()==second->getLength() &&
        first->getName()==second->getName() && first->getSurname()==second->getSurname())
        return true;
        
    else 
        return false;
}