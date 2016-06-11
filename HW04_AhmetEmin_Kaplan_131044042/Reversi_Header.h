/* 
 * File:   Reversi_Header.h
 * Author: aek
 *
 * Created on November 23, 2015, 11:27 PM
 */

#ifndef REVERSI_HEADER_H
#define	REVERSI_HEADER_H

#include<iostream>
#include<vector>
#include"Cell_Header.h"
using namespace std;

class Reversi {
public:

    Reversi(int height, int width);
    Reversi();
    Reversi(int param);
    Reversi(const char* filename);

    void Print()const;
    int is_available(int x, int y, char id)const;
    void play(int x, int y, char id);
    void play();
    void createCell(int x, int y, char id);
    void playGame();

    int getMaxHeight()const {
        return maxHeight;
    }

    int getMaxWidth()const {
        return maxWidth;
    }
    char search(int x, int y)const;
    bool any_available_move(char id)const;
    bool is_game_not_ended()const;
    void set_game(int height, int width);
    bool is_better(const Reversi& other)const;
    void save_game(const char* filename)const;
    void load_game(const char* filename);
private:

    vector< vector <Cell> > gameCells;
    int maxHeight;
    int maxWidth;
    int is_right_available(int x, int y, char id)const;
    int is_left_available(int x, int y, char id)const;
    int is_up_available(int x, int y, char id)const;
    int is_down_available(int x, int y, char id)const;
    int is_right_down_available(int x, int y, char id)const;
    int is_right_up_available(int x, int y, char id)const;
    int is_left_down_available(int x, int y, char id)const;
    int is_left_up_available(int x, int y, char id)const;
    void changeCell(int x, int y);

};
const int defaultSize = 8;
#endif	/* REVERSI_HEADER_H */

