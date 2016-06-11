#include<iostream>
#include<vector>
#include<cstdlib>
#include<fstream>
#include<string>
#include<cmath>
#include"Reversi_Header.h"
#include"Cell_Header.h"

using namespace std;

int Cell::numberOfCell = 0;

int main() {
    
    Cell myCell(5,5,'x');
    Cell myCell2(7,5,'o');
    Cell myCell4(5,5,'x');
    Cell myCell5(5,4,'x');
    cout<<"Mycell--->  "<<myCell;
    cout<<"Mycell2-->  "<<myCell2;
    cout<<"Mycell4-->  "<<myCell4;
    cout<<"Mycell5-->  "<<myCell5;
    
    
    if(myCell2>myCell5)
        cout<<"myCell2 hucresi myCell5 den Buyuktur\n";
    if(myCell5>myCell2)
        cout<<"myCell5 hucresi myCell2 den Buyuktur\n";
    if(myCell5==myCell2)
        cout<<"myCell5 hucresi myCell2 hucresine esittir\n";
    if(myCell5!=myCell2)
        cout<<"myCell5 hucresi myCell2 hucresine esit degildir\n";
    
    if(myCell<myCell2)
        cout<<"myCell hucresi myCell2 den Kucuktur\n";
    if(myCell>myCell2)
        cout<<"myCell hucresi myCell2 den buyuktur\n";
    if(myCell==myCell4)
        cout<<"myCell hucresi myCell4 e esittir\n";
    if(myCell!=myCell4)
        cout<<"myCell hucresi myCell4 e esit degildir\n";
    
    if(myCell2>=myCell4)
        cout<<"myCell2 hucresi myCell4 hucresinden buyuk esittir\n";
    if(myCell4<=myCell2)
        cout<<"myCell4 hucresi myCell2 hucresinden kucuk esittir\n";
    cout<<endl<<endl;
    
    cout<<"myCell hucresi: "<<myCell;
    cout<<"Post increment: "<<myCell++;
    cout<<"myCell hucresinin son hali: "<<myCell;
    
    cout<<endl;
    cout<<"myCell2 hucresi: "<<myCell2;
    cout<<"Pre increment: "<<++myCell2;
     cout<<"myCell2 hucresinin son hali: "<<myCell2;
     cout<<endl;
     
     
     cout<<"myCell4 hucresi: "<<myCell4;
     cout<<"Post decrement: "<<myCell4--;
     cout<<"myCell4 hucresinin son hali: "<<myCell4;
     
     cout<<endl;
    cout<<"myCell5 hucresi: "<<myCell5;
    cout<<"Pre decrement: "<<--myCell5;
     cout<<"myCell5 hucresinin son hali: "<<myCell5;
     cout<<endl;
     
     cout<<"Cell sinifi icin overload edilmis stream extraction operatorunu test etmek icin ";
     cout<<"iki integer 1 character giriniz!\n";
     
     cin>>myCell;
     cout<<"myCell hucresi: "<<myCell;
     
     cout<<"------------------------------------------------------------------\n";
     cout<<"------------------------------------------------------------------\n";
   
     string input;
    
    Reversi game1(4,4);
    int num_of_move=0;
    
    cout<<"-----GAME 1------\n";
    cout<<game1;
    while(game1.is_game_not_ended())
    {    
         cout<<"Hamle sirasi sizde\n";
        cin>>input;
        game1+=game1[input.c_str()];
        //cout<<game1.previous_moves[0];
        ++num_of_move;
        cout<<game1<<endl;
        cout<<++game1<<endl;
        ++num_of_move;
    }
   /*Oyun bitince baslangic hamlesine kadar undo ozelligini kullanacaktır*/
    for(int m=0;m<num_of_move;++m)
    {   cout<<num_of_move-m-1<<". hamle"<<endl;
        cout<<--game1;
        cout<<"----------------------------------------\n"<<endl;
    }
    
     cout<<"-----GAME 2------\n";
     
    /*Bir hamle kullanici bir hamle computer oynadiktan sonra undo ozelligini kullanir*/
    Reversi game2(8,8);
    
    //Oyunun baslangicinde ekrana board basma islemi
    cout<<game2;
    
    //Kullanicidan input alinir;
    
    cin>>input;
    
    //Hamle yapilir
    
    game2+=game2[input.c_str()];
    
    
    //Computer icin hamle yapilir post increment ozelligi gosterdigi icin
    
    
    //Ekrana basilan durum hamle oncesidir;
    cout<<game2++;
    
    
    //Hamle sonrasindaki durum ekrana basilir;
    cout<<game2;
  
    cout<<"Hamle sirasi sizde\n";
    cin>>input;
    
    game2+=game2[input.c_str()];
    
    cout<<game2++;
    
    //Hamle sonrasindaki durum ekrana basilir;
    cout<<game2;
  
    //Oyun 1hamle geri alindigindan sonra durum ekrana basilir
    cout<<game2--;
                                        
    //Oyun 1hamle daha geri alinir ama ekrana basilan durum hamleden onceki durum olacaktir
    cout<<game2--;
    
    cout<<--game2;
    
    cout<<--game2;
    
    cout<<"Oyun baslangica donduruldu hamle sirasi sizde\n";
    cin>>input;
    
    game2+=game2[input.c_str()];
    
    cout<<game2++;
    cout<<game2;
   
    
    cout<<"-------------------------------------------------------------\n";
    cout<<"() operatorunu test edilen kisim\n";
    
    cout<<game2(4,"d");
}