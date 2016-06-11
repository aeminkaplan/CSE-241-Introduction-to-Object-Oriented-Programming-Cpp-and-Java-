    
#include"file.h"

namespace AEminKaplan{

file::file()
{
    set_name("systemfile");
    set_fpath("root");
    set_owner("system");
    set_size("111");
}

file::file(string _name,string _owner,string _lastmodification,string _size)
{
    set_name(_name);
    set_owner(_owner);
    set_fpath("root");
    set_size(_size);
    set_last_modification(_lastmodification);

}


string file::get_name()const
{
    return name;
}
string file::get_owner()const
{
    return owner;
}
string file::get_last_modification()const
{
    return lastmodification;
}
string file::get_size()const
{
    return size;
}

void file::set_name(string _name) {
        name=_name;
}

void file::set_owner(string _owner)
{
    owner=_owner;
}
   
void file::set_last_modification(string _lastmdfctn) 
{
    lastmodification=_lastmdfctn;
}

void file::set_size(string _size) {
    size=_size;
}

void file::set_fpath(string _fpath)
{
    fpath=_fpath;
}
string file::path()const
{
    return fpath;
}
}