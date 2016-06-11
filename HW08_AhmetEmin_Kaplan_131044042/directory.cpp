#include"directory.h"
#include"executable.h"
#include"textfile.h"

/*Herhangi bir klasorun sahip oldugu File* vectorune eleman ekler*/
/*Parametre olarak gelen dosya referansiyle ayni tipte bir dosya olusturarak kopyalar*/
/*Kopyalama yaparken recursive cagri ile alt klasorleri de kopyalar*/
namespace AEminKaplan{
bool directory::cp(const file& cpfile) {
    
    
    for (int i = 0; i < subfiles.size(); ++i) {
        if (subfiles[i]->get_name() == cpfile.get_name()) {
            cout << "Belirtilen dizinde ayni isimli dosya mevcut\n";
            return false;

        }
    }
    
    
    const executable* tempexec= dynamic_cast<const executable*> (&cpfile);
    
    if (tempexec !=NULL) {
        
        executable* temp1 = new executable(tempexec->get_name(),
                tempexec->get_owner(),
                tempexec->get_last_modification(),
                tempexec->get_size(),tempexec->get_compiler());
        
        temp1->set_fpath(path() + "/" + get_name());
        subfiles.push_back(temp1);
    }
    
    
    const textfile* temptext= dynamic_cast<const textfile*> (&cpfile);
    
    
    if (temptext!=NULL) {
        textfile* temp2 = new textfile(temptext->get_name(),
                temptext->get_owner(),
                temptext->get_last_modification(),
                temptext->get_size(),temptext->get_texttype());
        
        temp2->set_fpath(path() + "/" + get_name());
        subfiles.push_back(temp2);
    }

    
    const directory* tempdirectory=dynamic_cast<const directory*> (&cpfile);
    
    
    if (NULL != tempdirectory ) {
        directory* temp3 = new directory(tempdirectory->get_name(),
                tempdirectory->get_owner(),
                tempdirectory->get_last_modification(),
                tempdirectory->get_size());
        
        temp3->set_fpath(path() + "/" + get_name());
        subfiles.push_back(temp3);

        for (int i = 0; i < tempdirectory->subfiles.size(); ++i) {
            
           /*RECURSIVE cagri buradadir*/
            
            temp3->cp(*(tempdirectory->subfiles[i]));

        }


    }
    return true;
}
/* Linux terminal "ls" komutuna esdeger bir sekilde calisir*/
/*Recursive arama yaparken ekstra olarak dosya pathlerini de basar*/
/*onun haricinde ls komutundan bir fazlaligi yoktur*/

void directory::ls(const string mode)const {

    file* temp;
    
    /*Gizli klasorler haric alt klasorler dahil butun dosyalarin isimlerini
     *  ve pathlerini ekrana basan mode*/
    
    if (mode == "R") {

        for (int i = 0; i < subfiles.size(); ++i) {


            if (subfiles[i]->get_name()[0] != '.') {
                temp = subfiles[i];

                if (dynamic_cast<directory*> (temp) != NULL) {
                    cout << temp->get_name() << " ";
                    cout<<temp->path()<<endl;
                    temp->ls("R");

                } else if (dynamic_cast<executable*> (temp) != NULL) {
                    cout << temp->get_name() << " ";
                                        cout<<temp->path()<<endl;
                } else if (dynamic_cast<textfile*> (temp) != NULL) {
                    cout << temp->get_name() << " ";
                                        cout<<temp->path()<<endl;
                }
            }
        }
       


    } 
    
    /*Gizli dosyalar dahil alt klasorler haric butun dosyalarin isimlerini ekrana basar*/
   
    else if (mode == "a") {
       
        for (int i = 0; i < subfiles.size(); ++i) {
            cout << subfiles[i]->get_name() << " ";
        }
        cout << endl;
    } 
    
    /*Gizli dosyalar ve alt klasorler haric butun dosyalari listeleyerek ekrana basar*/
    
    else if (mode == "l") {
       
        for (int i = 0; i < subfiles.size(); ++i) {
            if (subfiles[i]->get_name()[0] != '.') {

                cout << subfiles[i]->get_name() << " ";

                if (NULL != dynamic_cast<executable*> (subfiles[i]))
                    cout << "-rwx ";

                else if (NULL != dynamic_cast<textfile*> (subfiles[i]))
                    cout << "-rw ";
                else if (NULL != dynamic_cast<directory*> (subfiles[i]))
                    cout << "-rw ";


                cout << subfiles[i]->get_owner() << " ";
                cout << subfiles[i]->get_size() << " ";
                cout << subfiles[i]->get_last_modification() << " ";
            }
            cout << endl;
        }
        cout << endl;
    } 
    
    
    /*Gizli dosyalar dahil butun dosyalari ekrana listeleyerek basar*/
    /*Alt klasorleri basmaz*/
   
    else if (mode == "al" || mode == "la") {

        
        for (int i = 0; i < subfiles.size(); ++i) {


            cout << subfiles[i]->get_name() << " ";

            if (NULL != dynamic_cast<executable*> (subfiles[i]))
                cout << "-rwx ";

            else if (NULL != dynamic_cast<textfile*> (subfiles[i]))
                cout << "-rw ";
            else if (NULL != dynamic_cast<directory*> (subfiles[i]))
                cout << "-rw ";

            cout << subfiles[i]->get_owner() << " ";
            cout << subfiles[i]->get_size() << " ";
            cout << subfiles[i]->get_last_modification() << " ";

            cout << endl;
        }
        cout << endl;
    } 
    
    
    /*Gizli dosyalar haric butun dosyalari alt klasorleriyle beraber
     *  listeleyerek  ekrana basan mode  */
   
    else if (mode == "Rl" || mode == "lR") {

        for (int i = 0; i < subfiles.size(); ++i) {
            temp = subfiles[i];
            if (subfiles[i]->get_name()[0] != '.') {
                if (dynamic_cast<directory*> (temp) != NULL) {

                    cout << subfiles[i]->get_name() << " ";
                    cout << "-rw ";
                    cout << subfiles[i]->get_owner() << " ";
                    cout << subfiles[i]->get_size() << " ";
                    cout << subfiles[i]->get_last_modification() << " \n";
                    
                    /*RECURSIVE cagri*/
                    
                    temp->ls("Rl");

                } else if (dynamic_cast<executable*> (temp) != NULL) {

                    cout << subfiles[i]->get_name() << " ";
                    cout << "-rwx ";
                    cout << subfiles[i]->get_owner() << " ";
                    cout << subfiles[i]->get_size() << " ";
                    cout << subfiles[i]->get_last_modification() << " ";
                } else if (dynamic_cast<textfile*> (temp) != NULL) {

                    cout << subfiles[i]->get_name() << " ";
                    cout << "-rw ";
                    cout << subfiles[i]->get_owner() << " ";
                    cout << subfiles[i]->get_size() << " ";
                    cout << subfiles[i]->get_last_modification() << " ";
                }

                cout << endl;
            }
        }
    }
    
    /*Gizli dosyalar ve alt klasorler dahil butun dosyalari listeleyerek ekrana basar*/
    
    else if (mode == "Ral" || mode == "alR" || mode == "Rla" || mode == "laR" || mode == "aRl" || mode == "lRa") {


        for (int i = 0; i < subfiles.size(); ++i) {
            temp = subfiles[i];

            if (dynamic_cast<directory*> (temp) != NULL) {

                cout << subfiles[i]->get_name() << " ";
                cout << "-rw ";
                cout << subfiles[i]->get_owner() << " ";
                cout << subfiles[i]->get_size() << " ";
                cout << subfiles[i]->get_last_modification()<<" ";
                cout << subfiles[i]->path()<<endl;
                
                /*RECURSIVE cagri*/
                
                temp->ls("Ral");

            } else if (dynamic_cast<executable*> (temp) != NULL) {

                cout << subfiles[i]->get_name() << " ";
                cout << "-rwx ";
                cout << subfiles[i]->get_owner() << " ";
                cout << subfiles[i]->get_size() << " ";
                cout << subfiles[i]->get_last_modification() << " ";
                cout << subfiles[i]->path()<<endl;
            } else if (dynamic_cast<textfile*> (temp) != NULL) {

                cout << subfiles[i]->get_name() << " ";
                cout << "-rw ";
                cout << subfiles[i]->get_owner() << " ";
                cout << subfiles[i]->get_size() << " ";
                cout << subfiles[i]->get_last_modification() << " ";
                cout << subfiles[i]->path()<<endl;
            }

         //   cout << endl;
        }



    }

/*Gizli dosyalar dahil butun dosyalari recursive olarak arayip sadece isimlerini */
/* ve pathlerini basan mode*/
    
    else if (mode == "Ra" || mode == "aR") {

        for (int i = 0; i < subfiles.size(); ++i) {
            temp = subfiles[i];

            if (dynamic_cast<directory*> (temp) != NULL) {
                cout << temp->get_name() << "  ";
                                    cout<<temp->path()<<endl;
                
              /*RECURSIVE cagri*/
                                    
              temp->ls("Ra");

            } else if (dynamic_cast<executable*> (temp) != NULL) {
                cout << temp->get_name() << " ";
                                    cout<<temp->path()<<endl;
            } else if (dynamic_cast<textfile*> (temp) != NULL) {
                cout << temp->get_name() << " ";
                                    cout<<temp->path()<<endl;
            }

        }

    }


}

/*Bir directory nin sahip oldugu klasorler arasinda arama yapar */
/*Eger aranan isimde bir klasor varsa bulunan klasorun referansini return eder*/
/*Eger bos parametre olarak cagirilmissa kendi referansini return eder*/
/*Eger aranan isimde dosya bulunamamissa kendi referansini return eder*/

file& directory::cd(const string name="default"){
    
    
    if(name=="default")
        return *this;
    
    for(int i=0;i<subfiles.size();++i)
    {
        if(subfiles[i]->get_name()==name)
        {
            return *subfiles[i];
        }
    }
    
    return *this;
}
}