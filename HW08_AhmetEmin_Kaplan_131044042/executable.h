/* 
 * File:   executable.h
 * Author: aek
 *
 * Created on December 19, 2015, 2:34 PM
 */

#ifndef EXECUTABLE_H
#define	EXECUTABLE_H
#include"file.h"
namespace AEminKaplan{
class executable:public file{

    public:
        
     void ls(const string mode)const;
     file& cd(const string name); 
     bool cp(const file& cpfile);
     string get_compiler()const{ return name_of_compiler; }
        executable();
        executable(string _name,string _owner,string _lstmdfctn,string _size,string _namecompiler)
        {
            set_name(_name);
            set_owner(_owner);
            set_last_modification(_lstmdfctn);
            set_size(_size);
            name_of_compiler=_namecompiler;
                    
        }
   
        private:
            
        string name_of_compiler;

};
}

#endif	/* EXECUTABLE_H */

