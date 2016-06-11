/* 
 * File:   main.cpp
 * Author: aek
 *
 * Created on December 18, 2015, 7:16 PM
 */

#include <cstdlib>
#include"executable.h"
#include"directory.h"
#include "textfile.h"
#include<vector>

using namespace std;
using namespace AEminKaplan;

/*
 * 
 */
int main(int argc, char** argv) {

    executable exe1("exe1", "ahmet", "20/12/2015", "752", "gcc");
    executable exe2("exe2", "mehmet", "19/12/2015", "925", "g++");
    executable exe3("exe3", "mahmut", "18/12/2015", "256", "CINT");
    executable exe4("exe4", "recep", "17/12/2015", "333", "PGCPP");
    executable exe5("exe5", "ayse", "16/12/2015", "2512", "Clang");

    textfile text1("text1", "yusuf", "15/12/2015", "612", "ASCII");
    textfile text2("text2", "fatma", "11/12/2015", "2512", "UNICODE");
    textfile text3("text3", "merve", "14/12/2015", "475", "UNICODE2");


    directory dir1("dir1", "sevket", "10/12/2015", "6546");

    directory dir2("dir2", "sefa", "09/12/2015", "8765");

    directory dir3("dir3", "yasin", "08/12/2015", "9765");

    directory dir4("dir4", "ali", "07/12/2015", "8765");

    vector<file*> Allfiles;

    Allfiles.push_back(&exe1);
    Allfiles.push_back(&exe2);
    Allfiles.push_back(&exe3);
    Allfiles.push_back(&exe4);
    Allfiles.push_back(&exe5);
    Allfiles.push_back(&text1);
    Allfiles.push_back(&text2);
    Allfiles.push_back(&text3);
    Allfiles.push_back(&dir1);
    Allfiles.push_back(&dir2);
    Allfiles.push_back(&dir3);
    Allfiles.push_back(&dir4);




    dir4.cp(exe4);
    dir4.cp(exe5);

    dir3.cp(dir4);
    dir3.cp(exe2);
    dir3.cp(exe3);

    dir2.cp(dir3);
    dir2.cp(exe1);

    dir1.cp(dir2);
    dir1.cp(text1);


    dir1.ls("laR"); /*

      //  dir3.ls("R");
       
        
   /*  (dir3.cd(".dir4")).cp(exe3);
     (dir3.cd(".dir4")).ls("l");*/


    executable exe99test("exe99test", "test", "test", "text", "text");

   
    /*Polymorphic Cagri*/
    cout<<"\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";

    for (int j = 0; j < Allfiles.size(); ++j) {

        cout << "(((())))" << Allfiles[j]->get_name() << "(((())))" << endl;

        if (Allfiles[j]->cp(exe99test)) {
            cout << "Kopyalama basarili\n";
        } else
            cout << "Kopyalama basarisiz\n";
        cout << "-----------------------------------------------\n";

    }


    /*Polymorphic Cagri*/

    cout << endl << endl << endl;
    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    for (int i = 0; i < Allfiles.size(); ++i) {
        cout << "(((())))" << Allfiles[i]->get_name() << "(((())))" << endl;

        /*Farkli parametrelerle asagidaki fonksiyonu cagirabilirsiniz*/
        /* R ,a,l,al,aR,Rl,aRl muhtemel parametrelerdir*/
        Allfiles[i]->ls("al");

        cout << "-----------------------------------------------\n";
    }

    cout<<endl<<endl<<"(((())))CD fonksiyonu ve gizli dosyalar icin Test((())))"<<endl<<endl;
    
    directory testdir("testdir","test","test","test");
    
    executable exec00("exec00","test","test","test","test");
    /*Gizli dosya*/
    textfile secrettext(".secrettext","test","test","test","test");
    
    /*Gizli klasor*/
    directory secrettestdir(".secrettestdir","test","test","test");
    executable testexec("testexec","test","test","test","test");
    
    testdir.cp(exec00);
    testdir.cp(secrettext);
    testdir.cp(secrettestdir);
    
    /*cd fonksiyonunun test kismi*/
    
    file& fileRef=testdir.cd(".secrettestdir");
    fileRef.cp(testexec);       
    
    cout<<"ls -l for testdir\n";
    testdir.ls("l");
    cout<<endl;
    cout<<"*********************************\n";
    cout<<"ls -al for testdir\n";
    testdir.ls("al");

    cout<<"*********************************\n";
    cout<<"ls -Ral for testdir\n";
    testdir.ls("Ral");
            
    cout<<"*********************************\n";
    cout<<"ls -Rl for testdir\n";
        testdir.ls("Rl");
        
    cout<<"*********************************\n";
    cout<<"ls -a for testdir\n";
    testdir.ls("a");
    
    
    
    cout<<"*********************************\n";
    cout<<"ls -aR for testdir\n";
    testdir.ls("aR");
    
    cout<<"*********************************\n";
    cout<<"ls -R for testdir\n";
    testdir.ls("R");
    
    return 0;
}

