/* 
 * File:   textfile.h
 * Author: aek
 *
 * Created on December 19, 2015, 8:37 PM
 */

#ifndef TEXTFILE_H
#define	TEXTFILE_H

#include "file.h"
namespace AEminKaplan{
class textfile:public file{


    public:

     file& cd(const string name);

     void ls(const string mode) const;

     bool cp(const file& cpfile);



        textfile(string _name,string _owner,string _lastmodification,string _size,string _texttype)
        :file(_name,_owner,_lastmodification,_size){
            
            texttype=_texttype;
        }
        
        textfile():file(){
            
            set_texttype("unicode");
        }
        string get_texttype()const{
            return texttype;
        }
                
        void set_texttype(string _texttype){
            texttype=_texttype;
        }        


    private:
        string texttype;
};
}

#endif	/* TEXTFILE_H */

