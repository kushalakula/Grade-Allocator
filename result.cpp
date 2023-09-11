#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Student{
    public:
    int roll;
    double internal;
    double mid;
    double end;
    double total;
    char grade;
};
int main(){
     cout<<"PLEASE ENTER THE NUMBER OF STUDENTS IN YOUR CLASS: ";
    int nofs;
    cin>>nofs;
    Student* s= new Student[nofs+1];
     cout<<endl<<"Enter the minimum percentage for Passing (35 or 40):";
    double mi;
    cin>>mi;
    cout<<endl;
    cout<<endl<<"If a Student is ABSENT for END Exam, for END marks please enter -1 and for the rest exams 0"<<endl;
    cout<<endl<<"Provide the data in the format of (ROLL Number - Internal Marks - Mid - End) "<<endl;
        double numsq = 0;
        double sum=0;
        int count=0;
        for(int i=1; i<=nofs; i++){
            cin>>s[i].roll>>s[i].internal>>s[i].mid>>s[i].end;
            
            if(s[i].end==-1){
                double t = s[i].internal+s[i].mid;
                s[i].total=t;
                continue;
            }
            double t = s[i].internal+s[i].mid+s[i].end;
            s[i].total=t;
            numsq += pow(t,2);
            sum += t;
            count++;
        }
        double mean = sum/count;
        double variance = (numsq/count) - pow(mean,2);
        double standev = sqrt(variance);
        cout<<"\tAverage: "<<mean<<endl;
        cout<<"\tStandard Deviation: "<<standev<<endl;
        // cout<<mean<<" "<<standev<<endl;
    double scri;
     cout<<endl<<"For Giving S grade, choose the factor for Standard Deviation(make sure it is between 1.5 - 2): ";
    cin>>scri;
    double subs;
     cout<<endl<<"For the Subsequent Grades , what SD factor you would like to choose (choose between 0.5 - 1): ";
    cin>>subs;
    double ss=mean + (standev*scri);
    double as = mean + (standev*(scri-subs));
    double bs = mean + (standev*(scri-(2*subs)));
    double cs = mean + (standev*(scri-(3*subs)));
    double ds = mean + (standev*(scri-(4*subs)));
    double es = mean + (standev*(scri-(5*subs)));
    double finm = (40*mi)/100;
    // cout<<ss<<" "<<as<<" "<<bs<<" "<<cs<<" "<<ds<<" "<<es<<endl;
    for(int i=1; i<=nofs; i++){
        if(s[i].end == -1 || s[i].total<mi){
            s[i].grade = 'F';
        }else if(s[i].end<finm && s[i].total>=min(mean/2,mi)){
            s[i].grade = 'P';
        }else if(s[i].end<finm && s[i].total<min(mean/2,mi)){
            s[i].grade = 'F';
        }else if(s[i].total>ss){
            s[i].grade = 'S';
        }else if(s[i].total>as){
            s[i].grade = 'A';
        }else if(s[i].total>bs){
            s[i].grade = 'B';
        }else if(s[i].total>cs){
            s[i].grade = 'C';
        }else if(s[i].total>ds){
            s[i].grade = 'D';
        }else if(s[i].total>es){
            s[i].grade = 'E';
        }else{
            s[i].grade = 'F';
        }
    }
    ofstream f;
     f.open("result.txt");
    cout<<endl<<"The output will be  (Roll - Total Marks - Grade Allotated)";
    for(int i=1; i<=nofs; i++){
        cout<<"\t"<<s[i].roll<<" - "<<s[i].total<<" - "<<s[i].grade<<endl;
        f<<s[i].roll<<" - "<<s[i].total<<" - "<<s[i].grade<<endl;
    }
     f.close();
     cout<<endl<<endl<<"Check the folder, from where this cpp file was opened. Now, you will be able to get one more txt file where every assigned Grade is stored in the order(ROLL NO - TOTAL MARKS - ASSIGNED GRADE)"<<endl;
    cout<<endl<<endl<<endl<<" Thank you for using ....";
}