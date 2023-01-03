#include<bits/stdc++.h>
#include <filesystem>
#include <iostream>
#include <string>
#include <sys/stat.h>
using namespace std;
namespace fs = filesystem;

int main()
{
    char cmd[100];
	string path
		= "C:\\Users\\ksaurav\\Desktop\\Files";
	struct stat sb;
    fstream file;
   file.open("C:\\Users\\ksaurav\\Desktop\\Files\\Report.txt",ios::out);
  
   if(!file)
   {
       cout<<"Error in creating file!!!";
       return 0;
   }
  
   cout<<"Report File Created";
	for (const auto& entry : fs::directory_iterator(path)) {

		filesystem::path outfilename = entry.path();
		string outfilename_str = outfilename.string();
		const char* path = outfilename_str.c_str();
        
		if (stat(path, &sb) == 0 && !(sb.st_mode & S_IFDIR)){
            //cout<<path<<endl;
            filesystem::path p(path);
            cout<<p.extension();
           
            strcpy(cmd,"move ");
            strcat(cmd,path);
            strcat(cmd," ");
            if(p.extension()==".pdf"||p.extension()==".txt"){
                file<<p.filename()<<" "<<p.extension()<<" "<<"Document"<<endl;
                strcat(cmd,"C:\\Users\\ksaurav\\Desktop\\Files\\Document");
                system(cmd);
            }
            else if(p.extension()==".mp4"){
                file<<p.filename()<<" "<<p.extension()<<" "<<"Video"<<endl;
                strcat(cmd,"C:\\Users\\ksaurav\\Desktop\\Files\\Video");
                system(cmd);
            }
            else if(p.extension()==".mp3"){
                file<<p.filename()<<" "<<p.extension()<<" "<<"Music"<<endl;
                strcat(cmd,"C:\\Users\\ksaurav\\Desktop\\Files\\Music");
                system(cmd);
            }
            else{
                continue;
                cout<<"Wrong File Format";
            }
        }
	}
}