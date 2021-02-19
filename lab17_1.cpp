#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string filename,vector<string> &names,vector<int> &scores,vector<char> &grades){


   ifstream file(filename);
   char format[] = "%[^:]:%d %d %d ";
   int a,b,c;
   string data;
   char namelist[100];
   while(getline(file,data)){
     sscanf(data.c_str(),format,namelist,&a,&b,&c);
      names.push_back(namelist);
      scores.push_back(a+b+c);



      if(a+b+c>=80){grades.push_back('A');}
      else if(a+b+c>=70&&a+b+c<=79){grades.push_back('B');}
      else if(a+b+c>=60&&a+b+c<=69){grades.push_back('C');}
      else if(a+b+c>=50&&a+b+c<=59){grades.push_back('D');}
      else if(a+b+c<50){grades.push_back('F');}

   }
}

void getCommand(string &command,string &key){
cout << "Please input your command: ";

string input;
string usertype;
getline(cin,usertype);
int length = usertype.length();
int end = usertype.find_first_of(" ");
command = usertype.substr(0,end);
key = usertype.substr(end+1,length);

}

void searchName(vector<string> &names,vector<int> scores,vector<char> grades,string key){
cout << "---------------------------------\n";
int found = 0;
  for(unsigned int i =0;i<names.size();i++ ){
   if(key==toUpperStr(names.at(i))){

     cout << names.at(i) <<"'s score = " << scores.at(i) <<  "\n";
     cout << names.at(i) <<"'s grade = " << grades.at(i)<<  "\n";
     found++;
   }


  }
   if(found==0){cout << "Cannot found.\n";}
  cout << "---------------------------------\n";
}

void searchGrade(vector<string> names,vector<int> scores,vector<char> grades,string key){
cout << "---------------------------------\n";
int found = 0;
  for(unsigned int i =0;i<names.size();i++ ){
  char searchKEY = key[0];
   if(searchKEY==grades.at(i)){

     cout << names.at(i) <<" (" << scores.at(i) <<")"<<  "\n";
   found++;
   }


  }
  if(found==0){cout << "Cannot found.\n";}

  cout << "---------------------------------\n";
}



int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades;
    importDataFromFile(filename, names, scores, grades);

    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);

    return 0;
}
