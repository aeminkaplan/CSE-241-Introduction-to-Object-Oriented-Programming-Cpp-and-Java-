// HW01_AhmetEmin_Kaplan_131044042.cpp
// Reversi oyununun player vs computer seklinde yapay zekali versiyonunu icerir
// 05.10.2015 tarihinde olusturulmustur

#include<iostream>
#include<cstdlib>

using namespace std;

char** CreateTheBoard(int size);
void PrintTheBoard(char** board,int size);
void FillTheBoard(char** board,int size);
void Move(char** board,int size,int locationX,int locationY,char user);
int is_available(char** board,int size,int locationX,int locationY,char user);
int best_move(char** board,int size,int* locationX,int* locationY,char user);
int is_any_available_move(char** board,int size,char user);
void score(char** board,int size,int* xScore,int* oScore);
void GameOver(char** board,int size);

int main()
{	
	char** board;
	int size,res,i,j;
	int turn=0;
	char charOrdinate;

	cout<<"Welcome!\nEnter the size to play Reversi\n";

	do{
		cout<<"The size should be between 4-20 and even number!\n";
		if(!(cin>>size))
		{
			cin.clear();
			cin.ignore(1000,'\n');
			size=-1;
		}
	}while(size<4 || size>20 || size%2==1);

	int locationX,locationY;

	board=CreateTheBoard(size);
	
	FillTheBoard(board,size);

	while(is_any_available_move(board,size,'o') || is_any_available_move(board,size,'x') )
	{	
		
		
		PrintTheBoard(board,size);
		
		if(turn==1 && is_any_available_move(board,size,'x'))
			turn=0;
		else if(turn==0 && is_any_available_move(board,size,'o'))
			turn=1;
	
		if(turn==0)
		{	
			res=best_move(board,size,&locationX,&locationY,'x');
			if(res)
			{
				Move(board,size,locationX,locationY,'x');
				charOrdinate=static_cast<char>(locationX+96);	
				cout<<"Computer Played to "<<locationY<<charOrdinate<<" coordinate\n";
			}
		}

		if(turn==1)
		{	

			do{
				cout<<"User Turn;\n";
			
				while(!(cin>>locationY))
				{
					cin.clear();
					cin.ignore(1000,'\n');
					cout<<"You entered wrong character\n";
				}
				cin>>charOrdinate;
				locationX=static_cast<int>(charOrdinate-96);
				if(locationX>size || locationX<1 || locationY>size || locationY<1)
					res=0;
				else
					res=is_available(board,size,locationX,locationY,'o');			
				if(res)
					Move(board,size,locationX,locationY,'o');
				else
				{
					cout<<"The coordinate is not available to move"<<endl;
					cout<<"Please try again and be sure that you are using small letter"<<endl;		
				}	
			}while(res==0);

		}
	        
	}

	GameOver(board,size);

//Ayrilan dynamic memory burada free edilmektedir

	for(i=0;i<size;++i)
		free(board[i]);	

	free(board);
	
	return 0;
}

//Girilen kullanici icin en cok tas kazanilacak kordinati output parametre olarak return eder
int best_move(char** board,int size,int* locationX,int* locationY,char user)
{
	int i,j,temp,max,temp1,temp2;

	max=0;

	for(i=1;i<=size;++i)
	{
		for(j=1;j<=size;++j)
		{
			temp=is_available(board,size,i,j,user);

			if(temp>max)
			{	
				max=temp;
				temp1=i;
				temp2=j;
			}
		}
	}
	*locationX=temp1;
	*locationY=temp2;
	return max;
}



int is_available(char** board,int size,int locationX,int locationY,char user)
{

	int dotcount=0;
	int i,j,k,m;
	char enemy;
	int counter=0;

	if(board[locationY-1][locationX-1]!='.' || locationX>size || locationX <1 || locationY>size || locationY<1)	
		return 0;

	if(user=='o')
		enemy='x';

	else
		enemy='o';
	
	//Sag tarafa dogru kazanilabilecek taslari kontrol eder
	if(locationX!=size && board[locationY-1][locationX]==enemy)
	{
		for(i=locationX+1;i<size;++i)
		{
			if(board[locationY-1][i]==user && dotcount==0)
			{	
				k=i-1;
				while(k!=locationX-1)
				{
					++counter;
					--k;
				}				
				i=size;				
			}				
			else if(board[locationY-1][i]=='.')
			++dotcount;
		}	
			dotcount=0;
	
	}	
	

	//Sol tarafa dogru kazanilabilecek taslari kontrol eder
	if(locationX!=1 && board[locationY-1][locationX-2]==enemy)
	{
		for(i=locationX-3;i>=0;--i)
		{			
			if(board[locationY-1][i]==user && dotcount==0)
			{
				k=i+1;	
				while(k<locationX-1)
				{	
					++counter;					
					++k;
				}
				i=-1;			
			}
			else if(board[locationY-1][i]=='.')
			++dotcount;

		}			
			dotcount=0;
	}

	//Asagi yone dogru kazanilabilecek taslari kontrol eder
	if(locationY!=size  && board[locationY][locationX-1]==enemy)
	{
		for(i=locationY+1;i<size;++i)
		{
			if(board[i][locationX-1]==user && dotcount==0)
			{
				k=i-1;
				while(k!=locationY-1)
				{
					++counter;
					--k;
				}
				i=size;			
			}
			else if(board[i][locationX-1]=='.')
			++dotcount;
		}	
	
			dotcount=0;
	}
	
	//Yukari yone dogru kazanilabilecek taslari kontrol eder	
	if(locationY!=1 && board[locationY-2][locationX-1]==enemy)
	{
		for(i=locationY-3;i>=0;--i)
		{
			if(board[i][locationX-1]==user && dotcount==0)
			{
				k=i+1;
				while(k!=locationY-1)
				{
					++counter;					
					++k;
				}
				i=-1;			
			}
			else if(board[i][locationX-1]=='.')
			++dotcount;
		}	
	
			dotcount=0;
	}
	
	//Sag capraz alt yone dogru kazanilabilecek taslari kontrol eder
	if(locationX!=size && locationY!=size && board[locationY][locationX]==enemy)
	{
		for(i=locationX+1,j=locationY+1;i<size && j<size;++i,++j)
		{
			if(board[j][i]==user && dotcount==0)
			{	
				k=i-1;
				m=j-1;
				while(k!=locationX-1 && m!=locationY-1)
				{
					++counter;					
					--k;
					--m;					
				}
				i=size;
				j=size;			
			}
				else if(board[j][i]=='.')
				++dotcount;
		}
				dotcount=0;
	}

	//Sag capraz ust yone dogru kazanilabilecek taslari kontrol eder
	if(locationX!=size && locationY!=1 && board[locationY-2][locationX]==enemy)
	{
		for(i=locationX+1,j=locationY-3;i<size && j>=0;++i,--j)
		{
			if(board[j][i]==user && dotcount==0)
			{
				k=i-1;					
				m=j+1;
				while(k!=locationX-1 && m!=locationY-1)	
				{
					++counter;					
					--k;
					++m;
				}
				i=size;
				j=-1;		
			}
			else if(board[j][i]=='.')
			++dotcount;
		}
				dotcount=0;
	}		
	//Sol capraz alt yone dogru kazanilabilecek taslari kontrol eder
	if(locationX!=1 && locationY!=size && board[locationY][locationX-2]==enemy)	
	{
		for(i=locationX-3,j=locationY+1;i>=0,j<size;--i,++j)
		{				
			if(board[j][i]==user && dotcount==0)
			{
				k=i+1;
				m=j-1;
				while(k!=locationX-1 && m!=locationY-1)				
				{
					++counter;					
					++k;
					--m;
				}
				j=size;
				i=-1;			
			}
			else if(board[j][i]=='.')
			++dotcount;
		}
				dotcount=0;
	}

	
	//Sol capraz ust yone dogru kazanilabilecek taslari kontrol eder
	if(locationX!=1 && locationY!=1 && board[locationY-2][locationX-2]==enemy)		
	{
		for(i=locationX-3,j=locationY-3;i>=0,j>=0;--i,--j)
		{				
			if(board[j][i]==user && dotcount==0)
			{
				k=i+1;
				m=j+1;
				while(k!=locationX-1 && m!=locationY-1)
				{
					++counter;					
					++k;
					++m;					
				}			
				i=-1;
				j=-1;			
			}
				else if(board[j][i]=='.')
				++dotcount;
		}			
	}

	//Toplam yenilebilecek tas sayisi return edilir
	return counter;
}
//Oyun bitiminde cagirilan bu fonksiyon score durumuna gore yorum yapar
void GameOver(char** board,int size)
{
	int oScore,xScore;
	PrintTheBoard(board,size);	

	score(board,size,&xScore,&oScore);
	if(oScore>xScore)
		cout<<"Congratulations You Won! The Score is "<<oScore<<"-"<<xScore<<endl;

	else if(xScore>oScore)
		cout<<"You Lose ! The Score is "<<xScore<<"-"<<oScore<<"\n";

	else if(xScore==oScore)
		cout<<"The game ended with draw!"<<endl;
}
//Girilen hucreye hamle yapilmasi durumunda kazanilacak taslari duzeltir
void Move(char** board,int size,int locationX,int locationY,char user)
{
	board[locationY-1][locationX-1]=user;

	int dotcount=0;
	int i,j,k,m;
	char enemy;

	if(user=='o')
	enemy='x';

	else
	enemy='o';
	
	//Hucrenin sag yone dogru yiyecegi taslari yeme islemini yapan kisim
	if(locationX!=size && board[locationY-1][locationX]==enemy)
	{
		for(i=locationX+1;i<size;++i)
		{
			if(board[locationY-1][i]==user && dotcount==0)
			{	
				k=i-1;
				while(k!=locationX-1)
				{
					board[locationY-1][k]=user;
					--k;
				}				
		
				i=size;
			}				
			else if(board[locationY-1][i]=='.')
			++dotcount;
		}	
			dotcount=0;
	
	}	
	
	//Hucrenin sol yone dogru yiyecegi taslari yeme islemini yapan kisim
	if(locationX!=1 && board[locationY-1][locationX-2]==enemy)
	{
		for(i=locationX-3;i>=0;--i)
		{			
			if(board[locationY-1][i]==user && dotcount==0)
			{
				k=i+1;	
				while(k!=locationX-1)
				{
					board[locationY-1][k]=user;	
					++k;
				}
				i=-1;			
			}
			else if(board[locationY-1][i]=='.')
			++dotcount;

		}			

			dotcount=0;
	}

	//Hucrenin asagi yone dogru yiyecegi taslari yeme islemini yapan kisim
	if(locationY!=size  && board[locationY][locationX-1]==enemy)
	{
		for(i=locationY+1;i<size;++i)
		{
			if(board[i][locationX-1]==user && dotcount==0)
			{
				k=i-1;
				while(k!=locationY-1)
				{
					board[k][locationX-1]=user;
					--k;
				}
				i=size;			
			}
				else if(board[i][locationX-1]=='.')
				++dotcount;
		}	
	
			dotcount=0;
	}
	//Hucrenin yukari yone dogru yiyecegi taslari yeme islemini yapan kisim	
	if(locationY!=1 && board[locationY-2][locationX-1]==enemy)
	{
		for(i=locationY-3;i>=0;--i)
		{
			if(board[i][locationX-1]==user && dotcount==0)
			{
				k=i+1;
				while(k!=locationY-1)
				{
					board[k][locationX-1]=user;	
					++k;
				}
				i=-1;			
			}
				else if(board[i][locationX-1]=='.')
				++dotcount;
		}	
	
			dotcount=0;
	}
	//Hucrenin sag capraz alt yone dogru yiyecegi taslari yeme islemini yapan kisim
	if(locationX!=size && locationY!=size && board[locationY][locationX]==enemy)
	{
		for(i=locationX+1,j=locationY+1;i<size && j<size;++i,++j)
		{
			if(board[j][i]==user && dotcount==0)
			{	
				k=i-1;
				m=j-1;
				while(k!=locationX-1 && m!=locationY-1)
				{
					board[m][k]=user;
					--k;
					--m;					
				}
				i=size;
				j=size;		
			}
				else if(board[j][i]=='.')
				++dotcount;
		}
				dotcount=0;
	}
	//Hucrenin sag capraz ust yone dogru yiyecegi taslari yeme islemini yapan kisim
	if(locationX!=size && locationY!=1 && board[locationY-2][locationX]==enemy)
	{
		for(i=locationX+1,j=locationY-3;i<size && j>=0;++i,--j)
		{
			if(board[j][i]==user && dotcount==0)
			{
				k=i-1;					
				m=j+1;
				while(k!=locationX-1 && m!=locationY-1)	
				{
					board[m][k]=user;
					--k;
					++m;
				}
				i=size;
				j=-1;			
			}
				else if(board[j][i]=='.')
				++dotcount;
		}
				dotcount=0;
	}		
	//Hucrenin sol capraz alt yone dogru yiyecegi taslari yeme islemini yapan kisim
	if(locationX!=1 && locationY!=size && board[locationY][locationX-2]==enemy)
	{
		for(i=locationX-3,j=locationY+1;i>=0,j<size;--i,++j)
		{				
			if(board[j][i]==user && dotcount==0)
			{
				k=i+1;
				m=j-1;
				while(k!=locationX-1 && m!=locationY-1)				
				{
					board[m][k]=user;
					++k;
					--m;
				}
				i=-1;
				j=size;			
			}
				else if(board[j][i]=='.')
				++dotcount;
		}
				dotcount=0;
	}
	//Hucrenin sol capraz ust yone dogru yiyecegi taslari yeme islemini yapan kisim
	if(locationX!=1 && locationY!=1 && board[locationY-2][locationX-2]==enemy)		
	{
		for(i=locationX-3,j=locationY-3;i>=0,j>=0;--i,--j)
		{				
			if(board[j][i]==user && dotcount==0)
			{
				k=i+1;
				m=j+1;
				while(k!=locationX-1 && m!=locationY-1)
				{
					board[m][k]=user;
					++k;
					++m;					
				}			
				i=-1;
				j=-1;			
			}
				else if(board[j][i]=='.')
				++dotcount;
		}			
	}

}

//Kullanicilar icin herhangi bir legal hamle olup olmadigini kontrol eder
//Eger uygun bir hamle bulursa döngüden cikarak 1 return eder
int is_any_available_move(char** board,int size,char user)
{
	int result=0;
	int i,j;
	int temp;

	for(i=1;i<=size;++i)
		for(j=1;j<=size;++j)
		{
			temp=is_available(board,size,i,j,user);	
			if(temp>0)
			{
				result=1;
				i=size+1;
				j=size+1;			
			}			
		}

	return result;
}

//Oyunun baslangicinda olusturulan board kurallara gore doldurulur
void FillTheBoard(char** board,int size)
{
	int i,j;
	
	for(i=0;i<size;++i)
		for(j=0;j<size;++j)
		board[i][j]='.';

	board[size/2][size/2]='x';
	board[(size/2)-1][(size/2)-1]='x';

	board[size/2][(size/2)-1]='o';
	board[(size/2)-1][size/2]='o';

}

//Olusturulan board bu fonksiyonla ekrana basılır
void PrintTheBoard(char** board,int size)
{

	int i,j,k,xScore,oScore;
	char character;

	score(board,size,&xScore,&oScore);


	character=static_cast<char>(97);
	cout<<" ";

	if(size>=10)
		cout<<" ";
	for(i=0;i<size;++i)
	{
		cout<<" ";
		cout<<character;
		++character;
	}	

	 cout<<endl;

	for(i=0;i<size;++i)
	{
		if(size>=10 && i<9)
			cout<<" ";
	
		cout<<i+1;
			
		for(j=0;j<size;++j)
			cout<<" "<<board[i][j];
			if(i==(size/2)-1)
			{
				cout<<"\tx:"<<xScore<<" o:"<<oScore<<endl;
			}
			else
				cout<<endl;	
	}
}	

//Kullanicidan alinan size degeri kadar dinamik iki boyutlu kare matris olusturur
char** CreateTheBoard(int size)
{
	int i;
	char** board;

	board=(char**)malloc(sizeof(char*)*size);	

	for(i=0;i<size;++i)
		board[i]=(char*)malloc(sizeof(char)*size);
		
	return board;
}

//Score bu fonksiyon ile hesaplanir 
void score(char** board,int size,int* xScore,int* oScore)
{
	int i,j;
	int temp=0;
	int temp2=0;
	for(i=0;i<size;++i)
		for(j=0;j<size;++j)
		{
			if(board[i][j]=='o')
			++temp;
			else if(board[i][j]=='x')
			++temp2;	
		}	

	*xScore=temp2;
	*oScore=temp;

}
