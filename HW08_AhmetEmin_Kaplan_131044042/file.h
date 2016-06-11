/* 
 * File:   file.h
 * Author: aek
 *
 * Created on December 18, 2015, 7:16 PM
 */
#include<iostream>
#include<string>

using namespace std;
#ifndef FILE_H
#define	FILE_H
namespace AEminKaplan{
class file{

public:
    file();
    file(string _name,string _owner,string _lastmodification,string _size);
    string get_name()const;
    string get_owner()const;
    string get_last_modification()const;
    string get_size()const;
    void set_name(string _name);
    void set_owner(string _owner);
    void set_last_modification(string _lastmdfctn);
    void set_size(string _size);
    void set_fpath(string _fpath);
    string path()const;
    virtual void ls(const string mode)const=0;
    virtual file& cd(const string name)=0; 
    virtual bool cp(const file& cpfile)=0;
    
private:
    string name;
    string owner;
    string lastmodification;
    string fpath;
    string size;
    

};

}
#endif	/* FILE_H */

