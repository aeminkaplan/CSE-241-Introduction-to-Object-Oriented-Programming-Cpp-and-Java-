#include<iostream>
#include<vector>
#include<cstdlib>
#include<fstream>
#include<string>
#include<cmath>
#include"Reversi_Header.h"
#include"Cell_Header.h"


using namespace std;
using namespace AhmetEminKaplan;
using namespace AhmetEminKaplan_Cell;


int Reversi::numOfReversiGames=0;
int Cell::numberOfCell = 0;


int main() {

    //5 farki reversi objesi olusturdum
    
    cout<<"Reversi Objesi sayisi"<<Reversi::numberOfGames()<<endl<<endl;
    Reversi game5(10, 10);
    
   cout<<"Reversi Objesi sayisi"<<Reversi::numberOfGames()<<endl<<endl;
    Reversi game1(6, 7);

   cout<<"Reversi Objesi sayisi"<<Reversi::numberOfGames()<<endl<<endl;
    Reversi game2;

   cout<<"Reversi Objesi sayisi"<<Reversi::numberOfGames()<<endl<<endl;
    Reversi game3;

   cout<<"Reversi Objesi sayisi"<<Reversi::numberOfGames()<<endl<<endl;
    Reversi game4(10);
   cout<<"Reversi Objesi sayisi"<<Reversi::numberOfGames()<<endl<<endl;
    
    {
        Reversi game10;
        cout<<"Reversi Objesi sayisi"<<Reversi::numberOfGames()<<endl<<endl;
    }
        cout<<"Reversi Objesi sayisi"<<Reversi::numberOfGames()<<endl<<endl;
        
    cout<<"Assignment yapilmadan onceki game2 objesi\n";
    cout<<game2<<endl;
    
    game2=game1;

    
    
    //assignmen operatoru icin test 
    cout<<"Assignment yapildiktan sonraki game2 objesi\n";
    
    
    cout<<game2;
    
    //CallbyValue olarak kullanilan fonksiyon local obje olustururken
    //copy constructer kullanacaktir ve copy constructer her kullanildiginda
    //ekrana uyari yazisi yazmaktadir
    
   
     
    if(game4.is_bigger_value(game2)==game4.is_bigger_reference(game2))
        cout<<"Call by value ve Call by reference olarak obje alan fonksiyonlarin return degeri aynidir\n";
    
    
    //playGame fonksiyonu oyun sonlanana kadar oynatmaktadir.
    //Eger kullanici oyunu duraklatip diger oyunlara devam etmek isterse hamle yapmadan once oyunu duraklatma hakki bulunmaktadir
    while (game5.is_game_not_ended() ||
            game1.is_game_not_ended() ||
            game2.is_game_not_ended() ||
            game3.is_game_not_ended() ||
            game4.is_game_not_ended()) {
        

        cout << "GAME 5" << endl;
        game5.playGame();
        
  
        cout << "GAME 1" << endl;
        game1.playGame();
      
        

        cout << "GAME 2" << endl;
        game2.playGame();
        

        cout << "GAME 3" << endl;
        game3.playGame();
       


        cout << "GAME 4" << endl;
        game4.playGame();
    }


    if (game2.is_better(game5))
        "game2 is better than game5\n";
    else
        "game 5 is better than game2\n";

    
    
    
}
