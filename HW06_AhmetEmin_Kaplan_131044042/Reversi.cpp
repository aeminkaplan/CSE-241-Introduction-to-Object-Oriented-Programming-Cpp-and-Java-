#include<cstdlib>
#include<fstream>
#include<string>
#include<cmath>
#include"Reversi_Header.h"
using namespace AhmetEminKaplan_Cell;
namespace AhmetEminKaplan{

    bool Reversi::is_bigger_value(Reversi other) {
        if (size > other.size)
            return true;

        else
            return false;
    }

    bool Reversi::is_bigger_reference(Reversi& other) {
        if (size > other.size)
            return true;
        else
            return false;


    }
     Reversi Reversi::operator++(int)
    {
     Reversi temp;
     temp=*this;
     play();
     return  temp;

    }
    //Kod tekrari yapmamak icin bu operatorde print fonksiyonumu cagirdim
    //Aslinda olmasi gereken ostream tipinde girilen degiskene boardun her bir
    //parcasini basmakti.
     ostream& operator<<(ostream& output,const Reversi& game)
     {
         game.Print();
         return output;
     }

    Reversi Reversi::operator++()
    {
      play();  
      return *this;  
    }

    Reversi& Reversi::operator=(const Reversi& other)
    {
        if(this==&other)
            return *this;

        else
        {
            size=other.size;
            maxHeight=other.maxHeight;
            maxWidth=other.maxWidth;
            delete []gameCells;    
            gameCells=new Cell[size];
            for(int i=0;i<size;++i)
            {
                gameCells[i]=other.gameCells[i];
            }

            return *this;
        }    

    }
    Reversi::~Reversi()
    {
        delete [] gameCells;
        --numOfReversiGames;
        cout<<"Destructor cagirildi\n\n";
    }

    Reversi::Reversi(const Reversi& other)
    {
        cout<<"Copy constructer cagirildi\n";
        ++numOfReversiGames;
        size=other.size;
        gameCells=new Cell[size];
        maxWidth=other.maxWidth;
        maxHeight=other.maxHeight;
        for(int i=0;i<size;++i)
        {
            gameCells[i]=other.gameCells[i];
        }

    }

    //Oyun tahtasini dosyaya yazdiran fonskiyondur

    void Reversi::save_game(const char* filename)const {
        ofstream outputfile;
        outputfile.open(filename);

        int i, j, k, l;

        for (i = 0; i < getMaxHeight(); ++i) {
            for (j = 0; j < getMaxWidth(); ++j) {
                outputfile << search(j, i);
            }
            outputfile << endl;
        }
        outputfile.close();

    }
    //iki adet reversi objesini kiyaslayan fonksiyondur

    bool Reversi::is_better(const Reversi& other)const {
        int i, j;
        int counter1 = 0;
        int counter2 = 0;
        int total1 = 0;
        int total2 = 0;
        double temp1, temp2;

        for (i = 0; i < size; ++i)
            {
                ++total1;
                if (gameCells[i].getID() == 'o')
                    ++counter1;
            }

        for (i = 0; i < other.size; ++i){
                ++total2;
                if (other.gameCells[i].getID() == 'o')
                    ++counter2;
            }

        temp1 = (counter1 / 1.0) / total1;
        temp2 = (counter2 / 1.0) / total2;

        if (temp1 > temp2)
            return true;
        else
            return false;
    }

    int Reversi::numberOfGames()
    {
        return numOfReversiGames;

    }

    //Girilen boyuta gore oyunu ayarlayan fonksiyondur oyunu baslangic hamlesine getirmek icin butun hucreleri oldurur
    //Ve yeni board olusturur bu boardu initialize eder

    void Reversi::set_game(int height, int width) {
        if (height < 4 || width < 4) {
            cerr << "Size and Width should be at least 4 ! \n";
            exit(1);
        }

        setMaxHeight(height);
        setMaxWidth(width);
        size=4;

        delete []gameCells;

        gameCells=new Cell[4];
        gameCells[0]=Cell(maxWidth/2-1,maxHeight/2-1,'x');

        gameCells[1]=Cell(maxWidth/2,maxHeight/2,'x');

        gameCells[2]=Cell(maxWidth/2,maxHeight/2-1,'o');

        gameCells[3]=Cell(maxWidth/2-1,maxHeight/2,'o');



    }

    //Oyunun bir dongu seklinde sirayla oynanmasini saglayan fonksiyondur
    //Oyunu duraklatma ozelligi vardir

    void Reversi::playGame() {
        int turn = 0;
        int x, y, res;
        bool bir;
        int sayac = 1;
        string input;

        //Oyun devam ettigi surece sirayla user ve computer hamle yapar
        //İki taraftan birinin hamlesi olmamasi durumunda hamle hakki karsi tarafa gecer
        //İki tarafinda hamlesi olmamasi durumunda oyun sonlanir


        Print();
        cout << "Eger oyun tablosu ekrana sigmiyorsa screen.txt dosyasindan oyunu takip edebilirsiniz!\n";

        while (is_game_not_ended()) {



            if (turn == 1 && any_available_move('x'))
                turn = 0;
            else if (turn == 0 && any_available_move('o'))
                turn = 1;

            if (turn == 0) {
                play();
                save_game("saved_game1.txt");

            }

            //3 Hamlede bir kullanicinin oyunu duraklatip diger oyuna gecip gecmemek 
            //istedigi ogrenilir ona gore oyuna ara verilir veya devam edilir.

            if (turn == 1) {

                if (turn == 1 && sayac % 3 == 0) {
                    char temp;
                    cout << "Mevcut oyunu duraklatip sonraki oyuna gecmek istermisiniz? y/n" << endl;

                    cin>>temp;
                    if (temp == 'Y' || temp == 'y')
                        return;
                    cin.clear();
                    cin.ignore(1000, '\n');
                }


                do {
                    cout << "Hamle sirasi sizde;\n";


                    cout << "kordinatlari giriniz!\n";

                    do {
                        cout << "Kucuk harf kullandiginizdan emin olunuz!\n";
                        if (!(cin >> y)) {
                            cin.clear();
                            cin.ignore(1000, '\n');
                        }
                        else
                            bir = false;
                    } while (bir);


                    cin>>input;

                    int temp2 = 0;
                    int temp = input.size() - 1;
                    for (int l = 0; l < input.size(); ++l) {
                        temp2 = temp2 + (((int) input[l]) - 96) * pow(26, temp);

                        --temp;
                    }
                    x = temp2;

                    res = is_available(x - 1, y - 1, 'o');
                    if (res)
                        play(x - 1, y - 1, 'o');
                    else {
                        cout << "Girilen kordinat hamle yapmaya uygun degildir" << endl;
                        cout << "Lutfen yeni bir kordinat giriniz ve kucun harf kullandiginizdan emin olunuz!" << endl;
                    }
                } while (res == 0);


            }
            Print();

            ++sayac;
        }

        Print();

        int num_o = 0, num_x = 0;
        char temp_char;

        for (int i = 0; i < getMaxHeight(); ++i)
            for (int j = 0; j < getMaxWidth(); ++j) {
                temp_char = search(j, i);
                if (temp_char == 'x')
                    ++num_x;
                else if (temp_char == 'o')
                    ++num_o;
            }

        if (num_o > num_x)
            cout << "Oyunu Kazandiniz!\n";
        else if (num_x > num_o)
            cout << "Oyunu Kaybettiniz!\n";
        else if (num_x == num_o)
            cout << "Oyun berabere bitti!\n";
    }
    //Oyunun sonlanip sonlanmadigini return eden fonksiyondur

    bool Reversi::is_game_not_ended()const {
        return any_available_move('x') || any_available_move('o');

    }
    //Herhangi bir olasi hamle olup olmadigini return eden fonksiyondur

    bool Reversi::any_available_move(char id)const {
        int i, j;
        for (i = 0; i < getMaxHeight(); ++i)
            for (j = 0; j < getMaxWidth(); ++j) {
                int temp = is_available(j, i, id);
                if (temp > 0)
                    return true;
            }

        return false;
    }

    //Computer icin en cok tas kazanilacak hamleyi yapan fonksiyondur

    void Reversi::play() {
        int temp;
        int max = 0;
        int corX, corY;
        int i, j;
        for (i = 0; i < getMaxHeight(); ++i) {
            for (j = 0; j < getMaxWidth(); ++j) {
                if (search(j, i) == '.') {
                    temp = is_available(j, i, 'x');
                    if (temp > max) {

                        max = temp;
                        corX = j;
                        corY = i;
                    }
                }
            }
        }

        if (max > 0)
            play(corX, corY, 'x');
    }
    void Reversi::setMaxWidth(int w)
    {
        if(w>=4)
            maxWidth=w;

        else{
            cerr<<"Genislik degeri 4 den buyuk olmalidir\n";
            exit(1);

        }
    }    

    void Reversi::setMaxHeight(int h)
    {
        if(h>=4)
            maxHeight=h;

            else{
            cerr<<"Uzunluk degeri 4 den buyuk olmalidir\n";
            exit(1);

        }

    }
    Reversi::Reversi(int param) {

        ++numOfReversiGames;

        setMaxHeight(param);
        setMaxWidth(param);
        size=4;

        gameCells=new Cell[4];
        gameCells[0]=Cell(maxWidth/2-1,maxHeight/2-1,'x');

        gameCells[1]=Cell(maxWidth/2,maxHeight/2,'x');

        gameCells[2]=Cell(maxWidth/2,maxHeight/2-1,'o');

        gameCells[3]=Cell(maxWidth/2-1,maxHeight/2,'o');

    }

    Reversi::Reversi() {
        ++numOfReversiGames;
        setMaxHeight(defaultSize);
        setMaxWidth(defaultSize);
        size=4;
        gameCells=new Cell[4];

        gameCells[0]=Cell(maxWidth/2-1,maxHeight/2-1,'x');

        gameCells[1]=Cell(maxWidth/2,maxHeight/2,'x');

        gameCells[2]=Cell(maxWidth/2,maxHeight/2-1,'o');

        gameCells[3]=Cell(maxWidth/2-1,maxHeight/2,'o');

    }

    Reversi::Reversi(int height, int width) {


        ++numOfReversiGames;
            setMaxHeight(height);
        setMaxWidth(width);
        size=4;
        gameCells=new Cell[4];
        gameCells[0]=Cell(maxWidth/2-1,maxHeight/2-1,'x');

        gameCells[1]=Cell(maxWidth/2,maxHeight/2,'x');

        gameCells[2]=Cell(maxWidth/2,maxHeight/2-1,'o');

        gameCells[3]=Cell(maxWidth/2-1,maxHeight/2,'o');

    }
    //Girilen kordinata hamle yapilmasi durumunda board uzerinde yapilacak degisiklikleri yapar

    void Reversi::play(int x, int y, char id) {
        int i;
        int temp;
        int counter = 0;

        temp = is_right_available(x, y, id);
        for (i = 0; i < temp; ++i)
            changeCell(x + i + 1, y);

        counter += temp;


        temp = is_left_available(x, y, id);
        for (i = 0; i < temp; ++i)
            changeCell(x - i - 1, y);

        counter += temp;

        temp = is_up_available(x, y, id);
        for (i = 0; i < temp; ++i)
            changeCell(x, y - 1 - i);

        counter += temp;


        temp = is_down_available(x, y, id);
        for (i = 0; i < temp; ++i)
            changeCell(x, y + 1 + i);


        counter += temp;

        temp = is_right_down_available(x, y, id);
        for (i = 0; i < temp; ++i)
            changeCell(x + 1 + i, y + 1 + i);


        counter += temp;


        temp = is_right_up_available(x, y, id);
        for (i = 0; i < temp; ++i)
            changeCell(x + 1 + i, y - 1 - i);

        counter += temp;

        temp = is_left_up_available(x, y, id);
        for (i = 0; i < temp; ++i)
            changeCell(x - 1 - i, y - 1 - i);

        counter += temp;

        temp = is_left_down_available(x, y, id);
        for (i = 0; i < temp; ++i)
            changeCell(x - 1 - i, y + 1 + i);


        counter += temp;

        if (counter > 0)
            createCell(x, y, id);

    }


    //Herhangi bir hamle sonucunda taraf degistiren hucrelerin kimligini degistirir

    void Reversi::changeCell(int x, int y) {
        char enemy;
        char temp = search(x, y);

        if (temp == 'x')
            enemy = 'o';
        else if (temp == 'o')
            enemy = 'x';

        else if (temp == '.')
            exit(1);


        int i, j;

        for (i = 0; i < size; ++i) {
                if (gameCells[i].getX() == x && gameCells[i].getY() == y) {
                    gameCells[i].setID(enemy);
                }
        }
    }

    //Yapilan hamle sonucunda olusmasi gereken hucreyi olusturur

    void Reversi::createCell(int x, int y, char id) {
        if (search(x, y) == '.')
        {
            Cell* temp;
            temp=new Cell[size+1];
            int i=0;
            for(i=0;i<size;++i)
            {
                temp[i]=gameCells[i];
            }    
            temp[size]=Cell(x,y,id);
            delete [] gameCells;

            gameCells=temp;
            ++size;
        }
    }
    //Girilen kordinata hamle yapilmasi durumunda sol ust capraz tarafa dogru kazanilacak tas sayisini return eder
    //Calisma mantigi ise surekli bir sol ust capraz hucreyi kontrol etmeye dayalidir

    int Reversi::is_left_up_available(int x, int y, char id)const {
        int enemy;
        if (id == 'o')
            enemy = 'x';
        else
            enemy = 'o';

        int dotcounter = 0;
        int counter = 0;
        int i, j, k, l;
        char temp;

        if (search(x, y) != '.') {
            return 0;
        }
        if (search(x - 1, y - 1) == enemy) {

            for (i = y - 1, j = x - 1; i >= 0, j >= 0; --i, --j) {

                if (search(j - 1, i - 1) == id && dotcounter == 0) {
                    k = i;
                    l = j;
                    while (k != y && l != x) {
                        ++counter;
                        ++k;
                        ++l;
                    }
                    i = -1;
                    j = -1;
                } else if (search(j - 1, i - 1) == '.')
                    ++dotcounter;
            }
        }
        return counter;
    }
    //Girilen kordinata hamle yapilmasi durumunda sol alt capraz tarafa dogru kazanilacak tas sayisini return eder
    //Calisma mantigi ise surekli bir sol alt capraz hucreyi kontrol etmeye dayalidir

    int Reversi::is_left_down_available(int x, int y, char id)const {
        int enemy;
        if (id == 'o')
            enemy = 'x';
        else
            enemy = 'o';

        int dotcounter = 0;
        int counter = 0;
        int i, j, k, l;
        char temp;

        if (search(x, y) != '.')
            return 0;


        if (search(x - 1, y + 1) == enemy) {

            for (i = y + 1, j = x - 1; i < getMaxHeight(), j >= 0; ++i, --j) {

                if (search(j - 1, i + 1) == id && dotcounter == 0) {
                    k = i;
                    l = j;
                    while (k != y && l != x) {
                        ++counter;
                        --k;
                        ++l;
                    }
                    i = getMaxHeight();
                    j = -1;
                } else if (search(j - 1, i + 1) == '.')
                    ++dotcounter;
            }
        }
        return counter;
    }
    //Girilen kordinata hamle yapilmasi durumunda sag ust capraz tarafa dogru kazanilacak tas sayisini return eder
    //Calisma mantigi ise surekli bir sag ust caprazdaki hucreyi kontrol etmeye dayalidir

    int Reversi::is_right_up_available(int x, int y, char id)const {
        int enemy;
        if (id == 'o')
            enemy = 'x';
        else
            enemy = 'o';

        int dotcounter = 0;
        int counter = 0;
        int i, j, k, l;
        char temp;

        if (search(x, y) != '.') {
            return 0;
        }
        if (search(x + 1, y - 1) == enemy) {

            for (i = y - 1, j = x + 1; i >= 0, j < getMaxWidth(); --i, ++j) {

                if (search(j + 1, i - 1) == id && dotcounter == 0) {
                    k = i;
                    l = j;
                    while (k != y && l != x) {
                        ++counter;
                        ++k;
                        --l;
                    }
                    i = -1;
                    j = getMaxWidth();
                } else if (search(j + 1, i - 1) == '.')
                    ++dotcounter;
            }
        }
        return counter;

    }
    //Girilen kordinata hamle yapilmasi durumunda sag alt capraz tarafa dogru kazanilacak tas sayisini return eder
    //Calisma mantigi ise surekli bir sag alt capraz daki hucreyi kontrol etmeye dayalidir

    int Reversi::is_right_down_available(int x, int y, char id)const {
        int enemy;
        if (id == 'o')
            enemy = 'x';
        else
            enemy = 'o';

        int dotcounter = 0;
        int counter = 0;
        int i, j, k, l;
        char temp;

        if (search(x, y) != '.') {
            return 0;
        }
        if (search(x + 1, y + 1) == enemy) {

            for (i = y + 1, j = x + 1; i < getMaxHeight(), j < getMaxWidth(); ++i, ++j) {

                if (search(j + 1, i + 1) == id && dotcounter == 0) {
                    k = i;
                    l = j;
                    while (k != y && l != x) {
                        ++counter;
                        --k;
                        --l;
                    }
                    i = getMaxHeight();
                    j = getMaxWidth();
                } else if (search(j + 1, i + 1) == '.')
                    ++dotcounter;
            }
        }
        return counter;






    }
    //Girilen kordinata hamle yapilmasi durumunda alt tarafa dogru kazanilacak tas sayisini return eder
    //Calisma mantigi ise surekli bir altdaki hucreyi kontrol etmeye dayalidir

    int Reversi::is_down_available(int x, int y, char id)const {
        int enemy;
        if (id == 'o')
            enemy = 'x';
        else
            enemy = 'o';

        int dotcounter = 0;
        int counter = 0;
        int i, j, k;
        char temp;

        if (search(x, y) != '.')
            return 0;

        if (search(x, y + 1) == enemy) {

            for (i = y + 1; i < getMaxHeight(); ++i) {

                if (search(x, i + 1) == id && dotcounter == 0) {
                    k = i;
                    while (k != y) {
                        ++counter;
                        --k;
                    }
                    i = getMaxHeight();
                } else if (search(x, i + 1) == '.')
                    ++dotcounter;
            }
        }
        return counter;





    }
    //Girilen kordinata hamle yapilmasi durumunda ust tarafa dogru kazanilacak tas sayisini return eder
    //Calisma mantigi ise surekli bir ustteki hucreyi kontrol etmeye dayalidir

    int Reversi::is_up_available(int x, int y, char id)const {

        int enemy;
        if (id == 'o')
            enemy = 'x';
        else
            enemy = 'o';

        int dotcounter = 0;
        int counter = 0;
        int i, j, k;
        char temp;

        if (search(x, y) != '.')
            return 0;

        if (search(x, y - 1) == enemy) {

            for (i = y - 1; i >= 0; --i) {

                if (search(x, i - 1) == id && dotcounter == 0) {
                    k = i;
                    while (k != y) {
                        ++counter;
                        ++k;
                    }
                    i = -1;
                } else if (search(x, i - 1) == '.')
                    ++dotcounter;
            }
        }

        return counter;



    }
    //Girilen kordinata hamle yapilmasi durumunda sag tarafa dogru kazanilacak tas sayisini return eder
    //Calisma mantigi ise surekli bir sagdaki hucreyi kontrol etmeye dayalidir

    int Reversi::is_right_available(int x, int y, char id)const {
        int enemy;
        if (id == 'o')
            enemy = 'x';
        else
            enemy = 'o';

        int dotcounter = 0;
        int counter = 0;
        int i, j, k;
        char temp;

        if (search(x, y) != '.')
            return 0;

        if (search(x + 1, y) == enemy) {

            for (i = x + 1; i < getMaxWidth(); ++i) {

                if (search(i + 1, y) == id && dotcounter == 0) {
                    k = i;
                    while (k != x) {
                        ++counter;
                        --k;
                    }
                    i = getMaxWidth();
                } else if (search(i + 1, y) == '.')
                    ++dotcounter;
            }
        }
        return counter;


    }

    //Girilen kordinata hamle yapilmasi durumunda sol tarafa dogru kazanilacak tas sayisini return eder
    //Calisma mantigi ise surekli bir soldaki hucreyi kontrol etmeye dayalidir

    int Reversi::is_left_available(int x, int y, char id)const {
        int enemy;
        if (id == 'o')
            enemy = 'x';
        else
            enemy = 'o';

        int dotcounter = 0;
        int counter = 0;
        int i, j, k;
        char temp;

        if (search(x, y) != '.')
            return 0;

        if (search(x - 1, y) == enemy) {

            for (i = x - 1; i >= 0; --i) {

                if (search(i - 1, y) == id && dotcounter == 0) {
                    k = i;
                    while (k != x) {
                        ++counter;
                        ++k;
                    }
                    i = -1;
                } else if (search(i - 1, y) == '.')
                    ++dotcounter;
            }
        }
        return counter;

    }
    //Parametre olarak aldigi kordinata hamle yapilmasi durumunda maksimum kazanilacak tas sayisini return eder

    int Reversi::is_available(int x, int y, char id)const {
        int temp = 0;
        temp += is_right_available(x, y, id);
        temp += is_left_available(x, y, id);
        temp += is_up_available(x, y, id);
        temp += is_down_available(x, y, id);
        temp += is_left_up_available(x, y, id);
        temp += is_left_down_available(x, y, id);
        temp += is_right_up_available(x, y, id);
        temp += is_right_down_available(x, y, id);
        return temp;
    }

    //Girilen kordinattaki hucrenin kimligini return eder

    char Reversi::search(int x, int y)const {
        int i, j;

        for (i = 0; i < size; ++i)
                if (gameCells[i].getX() == x && gameCells[i].getY() == y) {
                    return gameCells[i].getID();
        }
        return '.';
    }

    void Reversi::Print()const {
        ofstream dosya;
        dosya.open("screen.txt");
        int temp, basamak;
        vector<char> sayi;
        int num_of_space = 1;
        int num_of_space2 = 1;
        int temp2, temp3;
        temp2 = getMaxHeight();
        temp3 = getMaxWidth();

        while (temp3 > 26) {
            ++num_of_space2;
            temp3 = temp3 / 26;
        }

        while (temp2 >= 10) {
            ++num_of_space;
            temp2 = temp2 / 10;
        }

        for (int y = 0; y < num_of_space; ++y) {
            dosya << "_";
            cout << "_";
        }
        for (int i = 1; i <= getMaxWidth(); ++i) {
            basamak = 1;
            temp = i;
            while (temp > 26) {
                ++basamak;
                temp = temp / 26;

            }

            temp = i;

            for (int j = basamak - 1; j >= 0; --j) {
                int temp2;
                temp2 = temp / pow(26, j);
                sayi.push_back((char) (temp2 + 96));

                temp = temp - temp2 * pow(26, j);
            }
            //  cout<<i<<":";
            for (int z = 0; z < sayi.size(); ++z) {
                dosya << sayi[z];
                cout << sayi[z];
            }
            for (int r = 0; r < num_of_space2 - sayi.size() + 1; ++r) {
                dosya << "_";
                cout << "_";
            }
            sayi.clear();
        }
        dosya << endl;
        cout << endl;
        for (int j = 0; j < getMaxHeight(); ++j) {
            int temp5 = j + 1;
            int counter = 1;

            while (temp5 >= 10) {
                ++counter;
                temp5 = temp5 / 10;
            }
            for (int z = 0; z < num_of_space - counter; ++z) {
                dosya << "_";
                cout << "_";
            }
            dosya << j + 1;
            cout << j + 1;
            for (int k = 0; k < getMaxWidth(); ++k) {
                dosya << search(k, j);
                cout << search(k, j);

                for (int b = 0; b < num_of_space2; ++b) {
                    dosya << "_";
                    cout << "_";
                }
            }
            dosya << endl;
            cout << endl;
        }
    }
}