/* 
 * File:   directory.h
 * Author: aek
 *
 * Created on December 19, 2015, 2:18 PM
 */

#ifndef DIRECTORY_H
#define	DIRECTORY_H
#include"file.h"
#include<vector>
using namespace std;
namespace AEminKaplan{
class directory:public file
{
public:
    directory(string _name,string _owner,string _lastmodification,string _size):file(_name,_owner,_lastmodification,_size)
    {
    /*Empty*/
    }
    virtual void ls(const string mode)const;
    virtual file& cd(const string name); 
    virtual bool cp(const file& cpfile);

    protected:
     vector<file*> subfiles;
        
};
}
#endif	/* DIRECTORY_H */

