int const MAX=10;
#define _grade[0] Physics
#define _grade[1] 

class student{
	private:
		char _classNum[MAX];
		char _studentNum[MAX];
		char _name[MAX];
		double _grade[4];
	public:
		student();
		student(char c[MAX],char s[MAX],char n[MAX],double g[4]);
		student(student& );
		~student();
		//set
		//get
		//isE
};

class BANJI{
	private:
		student _student[MAX_STUDENT];
		int _size_student;
	public:
		search
		add
		delete
		sort
};

bool student::isEmpty(void)
{
	if(!_classNum[0]&&!_studentNum[0]&&!_name[0]&&_grade[0]==-1)
	return 1;
}

student::student(student &s)
{
	strcpy(_classNum,s._classNum);
	strcpy(_studentNum,s._studentNum);
	strcpy(_classNum,s._classNum);
	for(int i=0;i<=4-1;i++)
	{
		_grade[i]=s._grade[i];
	}
}
