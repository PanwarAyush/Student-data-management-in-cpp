#include<iostream>
#include<fstream>
#include<vector>
#include<cstring>
#include<iomanip>
#include<algorithm>
using namespace std;
void clear_screen()
{
    system("cls");    //This method is used to clear the screen of the console
}
void first_page()  //For loops are used to display the first page and basic info.
{
    string str="Student Data Management in c++";
    string view="PRESS ENTER TO VIEW THE PROJECT";
    string info="Developed by ayush panwar (section A)";
    cout<<"\n\n\n";
    for(int i=0;i<20;i++)
    {
      cout<<"   ";
      for(int j=0;j<70;j++)
      {
          if(j==0||j==69||i==19||i==0)cout<<"*";
          else cout<<" ";
          if(i==7&&j==17)
          {
              cout<<str;
              j+=str.size();
          }
          if(i==0&&j==15)
          {
              cout<<view;
              j+=view.size();
          }
          if(i==18&&j==15)
          {
              cout<<info;
              j+=info.size();
          }
      }
      cout<<endl;
    }
    getchar();
    clear_screen(); //Clear screen method is invoked to clear the screen  
}
void thankyou_page()
{
    string str="THANKYOU TO OBSERVE HOW STUDENT DATA MANAGEMENT WORKS IN C++";
    cout<<"\n\n\n";
    for(int i=0;i<20;i++)
    {
      cout<<"   ";
      for(int j=0;j<70;j++)
      {
          if(j==0||j==69||i==19||i==0)cout<<"*";
          else cout<<" ";
          if(i==7&&j==4)
          {
              cout<<str;
              j+=str.size();
          }
      }
      cout<<endl;
    }
    getchar();
    clear_screen();
}
char menu_page()
{    clear_screen();
     vector<string>s(9);
     char ch;
     s[0]="Welcome to Student Data Management system";
     s[1]="(1) PRESS 1 TO ENTER NEW STUDENT DETAILS";
     s[2]="(2) PRESS 2 TO EDIT STUDENT DETAIL";
     s[3]="(3) PRESS 3 TO DISPLAY ALL STUDENT DETAILS";  
     s[4]="(4) PRESS 4 TO DISPLAY  DETAIL OF A PARTICULAR STUDENT";
     s[5]="(5) PRESS 5 to DELETE STUDENT DETAIL";
   	 s[6]="(6) PRESS 6 TO ALIGN IN INCREASING ORDER OF ROLL NUMBER";
	 s[7]="(7) PRESS 7 TO ALIGN IN DESCENDING ORDER OF MARKS";
	 s[8]="(8) PRESS 8 TO EXIT";
     cout<<"\n\n\n";
     for(int i=0;i<20;i++)
     {
      cout<<"   ";
      for(int j=0;j<70;j++)
      {
          if(j==0||j==69||i==19||i==0)cout<<"*";
          else cout<<" ";
          if((i<=16) && (i%2==0) &&(j==10))
          {
              cout<<s[i/2];
              j+=s[i/2].size();
          }
      }
      cout<<endl;
    }
    cout<<"PLease Enter your choice : ";
    cin>>ch;
    getchar();
    clear_screen();
    return ch;
}
class student
{
public:
char name[30];
int roll_no;
char course[30];
int grades;
string college_name[40];
void set_value();
void display_details();
void display_all_details(int);
bool check(int r)
{
    return r==roll_no;
}
};
void student::set_value()
{
    string s="Enter student details";
    for(int i=0;i<6;i++)
    {cout<<string(5,' ');
        for(int j=0;j<45;j++)
        {
            if(j==0||j==44||i==0||i==5)
            cout<<"*";
            else
            cout<<" ";
            if(i==3&&j==14)
            {
                cout<<s;
                j+=s.size();
            }
        }
        cout<<endl;
    }
	
    cout<<"\n    course that student opted : ";
    cin.getline(course,30);
	cout<<"\n    student roll number : ";
    cin>>roll_no;
    cout<<"\n    Enter student name : ";
	cin.ignore();
    cin.getline(name,30);
    cout<<"\n    grades/marks of student : ";
    cin>>grades;
    clear_screen();
}
void student::display_details()
{
cout<<"**********************************"<<endl;
cout<<"student name="<<name<<"\nRoll nuber="<<roll_no<<"\nCourse="<<course<<"\nGrades="<<grades<<endl;
cout<<"***********************************"<<endl;
getchar();
getchar();
clear_screen();
}
void student::display_all_details(int i)
{
    cout<<left<<setw(5)<<i<<setw(30)<<name<<setw(30)<<course<<setw(30)<<roll_no<<setw(30)<<grades<<endl;
}
bool cmp(student x,student y)
{
	return x.roll_no<y.roll_no;
}
bool marks(student x,student y)
{
	return x.grades>y.grades;
}
int main()
{
  vector<student>st;
  student temp;
	ifstream file("studentFile.txt",ios::binary);
	if(file)
	{
    while(file.read((char*)&temp,sizeof(temp)))
     {
		st.push_back(temp);
	 }
	}
	file.close();
    char ch;
    first_page();
    while(1)
     {
        ch=menu_page();
        if(ch=='8')
          break;
        if(ch=='1')
          {
           student obj;
		   obj.set_value();
           st.push_back(obj);
		   int ind=-1;
           for( int i=0;i<st.size()-1;i++)
             {
               if(st[i].roll_no==st.back().roll_no)
                 {
                 cout<<"Student roll number already  exists!\n";
                 ind=i;
				 getchar();
				 getchar();
				 clear_screen();
                 break;
                 }
             }
			 if(ind==-1){
				 cout<<"Information successfully added";
				 getchar();
				 clear_screen();
			 }
          }
        else if(ch=='2')
          {
           cout<<"To modify the data Please Enter the roll number of the student:";
           int roll;
           cin>>roll;
           int ind=-1;
           for( int i=0;i<st.size();i++)
             {
               if(st[i].roll_no==roll)
                 {
                 cout<<"Student data found!\n";
                 ind=i;
                 break;
                 }
             }
            if(ind>=0)
            { 
		      getchar();
			  cout<<"Old details:\n";
			  st[ind].display_details();
			  cout<<"New details:\n";
              temp.set_value();
              st[ind]=temp;
            }
           else{
            cout<<"\nStudent data not found!";
		    getchar();
		    getchar();
		    clear_screen();
		   }
          } 
         else if(ch=='3')
           {
			 cout<<left<<setw(7)<<"Index "<<setw(30)<<"student name"<<setw(25)<<"Course"<<setw(30)<<"Roll Number"<<setw(25)<<"Grades"<<endl;
			 cout<<string(110,'*')<<endl;
            for(int i=0;i<st.size();i++)
            st[i].display_all_details(i+1);
            cout<<"Press any key to continue";
            getchar();
           clear_screen();
           }
         else if(ch=='4')
           {
            cout<<"\nTo display the data Please Enter the roll number of the student:";
            int roll;
            cin>>roll;
            bool check=0;
            for( int i=0;i<st.size();i++)
              {
               if(st[i].check(roll))
                {
                cout<<"Student data found!\n";
                st[i].display_details();
                check=1;
                break;
                }
              }
        if(check==0)
          {
             cout<<"Student data not found!\n";
             getchar();
			 getchar();
			 clear_screen();
          }
      }
	  else if(ch=='5')
	  {
		cout<<"\nTo delete the data Please Enter the roll number of the student:";
            int roll;
            cin>>roll;
            bool check=0;
            for( int i=0;i<st.size();i++)
              {
               if(st[i].check(roll))
                {
			    st.erase(st.begin()+i);
                cout<<"Student data found and successfully deleted!\n";
                check=1;
                break;
                }
              }
        if(check==0)
          {
             cout<<"Student data not found!\n";
             getchar();
			 getchar();
			 clear_screen();
          }
	  }
	  else if(ch=='6')
	  {
		  sort(st.begin(),st.end(),cmp);
	  }
	  else if(ch=='7')
	  {
		  sort(st.begin(),st.end(),marks);
	  }
  }
 
thankyou_page(); 
  ofstream fi("studentFile.txt",ios::binary);
  for(int i=0;i<st.size();i++)
  {
	  fi.write((char*)&st[i],sizeof(st[i])); 
  }
  fi.close();
return 0;
}





