// 12 phone number

#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
const int MAX=255;

class Note
{
	private:
		char _name[MAX];
		char _number[MAX];
	public:
		Note();
		Note(char name[MAX], char number[MAX]);
		Note(Note& );
		~Note();
		bool setName(void);
		bool setName(char name[MAX]);
		bool setNumber(void);
		bool setNumber(char number[MAX]);
		char* getName(void);
		char* getNumber(void);
		bool isEmpty(void);
};

Note::Note()
{
	_name[0]='\0';
	_number[0]='\0';
}
Note::Note(char name[MAX], char number[MAX])
{
	strcpy(_name,name);
	strcpy(_number,number);
}
Note::Note(Note &note)
{
	strcpy(note._name,_name);
	strcpy(note._number,_number);
}
Note::~Note()
{
	//cout<<"Deconstructing a NOTE ..."<<endl;
}
bool Note::setName(void)
{
	char buf[MAX];
	cout<<"Input the name:"<<endl;
	cin>>buf;
	strcpy(_name,buf);
	return 1;
}
bool Note::setName(char name[MAX])
{
	strcpy(_name,name);
	return 1;
}
bool Note::setNumber(void)
{
	char buf[MAX];
	cout<<"Input the number:"<<endl;
	cin>>buf;
	strcpy(_number,buf);
	return 1;
}
bool Note::setNumber(char number[MAX])
{
	strcpy(_number,number);
	return 1;
}
char* Note::getName(void)
{
	return _name;
}
char* Note::getNumber(void)
{
	return _number;
}
bool Note::isEmpty(void)
{
	if(!_name[0] && !_number[0])
		return 1;
	return 0;
}
class Book
{
	private:
		Note _notes[MAX];
		int _size;
	public:
		Book(int size=0);
		Book(Book& );
		~Book();
		bool searchNum(char name[MAX],char (&buf_number)[MAX]);
		bool deleteNote(char name[MAX]);
		bool printBook(void);
		bool appendNote(int num);
		bool saveBook(char* fileName);
		bool loadBook(char* fileName);
};

Book::Book(int size)
{
	_size=size;
	for(int i=0; i<=_size-1; i++)
	{
		_notes[i].setName();
		_notes[i].setNumber();
	}
}
Book::Book(Book &book)
{
	_size=book._size;
	for(int i=0; i<=_size-1; i++)
	{
		_notes[i]=book._notes[i];
	}
}
Book::~Book()
{
	//cout<<"Deconstructing a BOOK... "<<endl;
}
bool Book::searchNum(char name[MAX],char (&buf_number)[MAX])
{
	for(int i=0; i<=_size-1; i++)
	{
		if(!strcmp(_notes[i].getName(),name))
		{
			strcpy(buf_number,_notes[i].getNumber());
			return 1;
		}
	}
	strcpy(buf_number,"NULL");
	return 0;
}
bool Book::deleteNote(char name[MAX])
{
	Note blankNote;
	int count=0;
	for(int i=0; i<=_size-1; i++)
	{
		if(!strcmp(name,_notes[i].getName()))
		{
			_notes[i]=blankNote;
			count++;
		}
	}
	if(count) return 1;
	return 0;
}
bool Book::printBook(void)
{
	int count=1;
	cout<<"------teleBook------"<<endl;
	for(int i=0; i<=_size-1; i++)
	{
		if(!_notes[i].isEmpty())
		{
			cout<<"No."<<count++<<endl;
			cout<<"Name:"<<_notes[i].getName()<<endl;
			cout<<"Number:"<<_notes[i].getNumber()<<endl;
		}
	}
	cout<<"-------------------"<<endl;
	return 1;
}
bool Book::appendNote(int num)
{
	char name[MAX],number[MAX];
	for(int i=0; i<=num-1; i++)
	{
		cout<<"Name(ADD):"<<endl;
		cin>>name;
		cout<<"Number(ADD)"<<endl;
		cin>>number;
		_notes[_size].setName(name);
		_notes[_size].setNumber(number);
		_size++;
	}

	return 1;
}
bool Book::saveBook(char* fileName)
{
	ofstream inFile(fileName);
	if(inFile.is_open())
	{
		for(int i=0; i<=_size-1; i++)
		{
			if(!_notes[i].isEmpty())
			{
				inFile<<_notes[i].getName()<<":"<<_notes[i].getNumber()<<endl;
			}
		}
		inFile.close();
	}
	else return 0;
	return 1;
}
bool divLine(char source[MAX],char (&name)[MAX],char (&number)[MAX])
{
	int i=0;
	while(source[i]!=':')
	{
		name[i]=source[i];
		i++;
	}
	name[i++]='\0';
	int j=0;
	while(source[i])
	{
		number[j]=source[i];
		i++;
		j++;
	}
	number[j]='\0';
	return 1;
}
bool Book::loadBook(char* fileName)
{
	ifstream sourceFile(fileName);
	char buf_name[MAX],buf_number[MAX];
	char buf[MAX];

	Note blankNote;
	cout<<"Warning: cur teleBook will be cleaned."<<endl;
	for(int i=0; i<=_size-1; i++)
	{
		_notes[i]=blankNote;
	}
	if(sourceFile.is_open())
	{
		int count=0;
		while(!sourceFile.eof())
		{
			sourceFile.getline(buf,MAX);
			divLine(buf,buf_name,buf_number);
			_notes[count].setName(buf_name);
			_notes[count].setNumber(buf_number);
			count++;
		}
		_size=count;
	}
	else return 0;
	sourceFile.close();
	return 1;
}


int main(void)
{
	char buf_name[MAX];
	char buf_number[MAX];
	char destFile[25];
	char sourceFile[25];
	const int size=2;
	int addNum;
	char ch;
	cout<<"INIT"<<endl;
	Book book(size);
	book.printBook();
	getchar();
	while((ch=getchar())!=EOF)
	{
		cout<<"1.APPEND\n2.SEARCH\n3.DELETE\n4.LOAD\n5.SAVE\nEOF to QUIT\n"<<endl;
		switch(ch)
		{
			case'1':
				cout<<"APPEND:"<<endl;
				cout<<"addNum=?"<<endl;
				cin>>addNum;
				book.appendNote(addNum);
				book.printBook();
				break;
			case'2':
				cout<<"SEARCH:"<<endl;
				cin>>buf_name;
				book.searchNum(buf_name,buf_number);
				cout<<"The result:"<<buf_number<<endl;
				break;
			case'3':
				cout<<"DELETE:"<<endl;
				cout<<"Name?"<<endl;
				cin>>buf_name;
				book.deleteNote(buf_name);
				cout<<"The result:"<<endl;
				book.printBook();
				break;
			case'4':
				cout<<"LOAD"<<endl;
				cout<<"File name?"<<endl;
				getchar();
				gets(sourceFile);//source_teleBook.txt
				book.loadBook(sourceFile);
				book.printBook();
				break;
			case'5':
				cout<<"SAVE"<<endl;
				cout<<"File name?"<<endl;
				getchar();
				gets(destFile);//dest_teleBook.txt
				book.saveBook(destFile);
				break;
			default:
				cout<<" "<<endl;
				break;
		}//switch
	}//while
	return 0;
}
