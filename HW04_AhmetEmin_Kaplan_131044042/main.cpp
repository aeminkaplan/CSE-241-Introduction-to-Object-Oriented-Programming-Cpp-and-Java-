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


    //5 farki reversi objesi olusturdum
    Reversi game5(10, 10);

    Reversi game1(6, 7);

    Reversi game2;

    Reversi game3;

    game3.load_game("saved_game.txt");

    Reversi game4(10);




    //playGame fonksiyonu oyun sonlanana kadar oynatmaktadir.
    //Eger kullanici oyunu duraklatip diger oyunlara devam etmek isterse hamle yapmadan once oyunu duraklatma hakki bulunmaktadir
    while (game5.is_game_not_ended() ||
            game1.is_game_not_ended() ||
            game2.is_game_not_ended() ||
            game3.is_game_not_ended() ||
            game4.is_game_not_ended()) {
        cout << "Mevcut oyunlardaki toplam hucre sayisi " << Cell::num_of_cell() << endl;

        cout << "GAME 5" << endl;
        game5.playGame();
        cout << "Mevcut oyunlardaki toplam hucre sayisi " << Cell::num_of_cell() << endl;

        cout << "GAME 1" << endl;
        game1.playGame();
        cout << "Mevcut oyunlardaki toplam hucre sayisi " << Cell::num_of_cell() << endl;

        cout << "GAME 2" << endl;
        game2.playGame();
        cout << "Mevcut oyunlardaki toplam hucre sayisi " << Cell::num_of_cell() << endl;

        cout << "GAME 3" << endl;
        game3.playGame();
        cout << "Mevcut oyunlardaki toplam hucre sayisi " << Cell::num_of_cell() << endl;


        cout << "GAME 4" << endl;
        game4.playGame();
    }


    if (game2.is_better(game5))
        "game2 is better than game5\n";
    else
        "game 5 is better than game2\n";

}
