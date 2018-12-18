#include<iostream>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<string>
#include<algorithm>
#include"lexer.h"
#include"parser.h"
#include"semantic.h"
using namespace std;

vector<string>variables; // vector to store all the variables and making it global so it can be used in multiple functions



bool variable_declaration_check(std::fstream& file_code,std::fstream& file_error)
{
	string temp1;
	string temp; 
	bool ret=true;
	if( (!file_code.is_open() ) )
    {
        exit(EXIT_FAILURE);
    }
	
    while(!file_code.eof())
    {
        getline(file_code,temp);
        int space=0;
		int len=temp.size();

        for(int i=0;i<len;i++)
        {
            if(temp[i]==' ')
            space++;
        }

        int n=space+1;  // n = space + 1 
		string words[10000];
		int counter=0;

        for(int i=0;i<=len;i++){
        if(temp[i]==' ')
        counter++;
        else
        words[counter]+=temp[i];
        }


        for(int i=0;i<n;i++)
        {
             temp1 = words[i];

            if(temp1[0]=='_' && temp1[temp1.size()-1]=='_')
            {
				if(words[i-1]=="num" || words[i-1]=="decision" || words[i-1]=="point" || words[i-1]=="dpoint" || words[i-1]=="symbol" || words[i-1]=="sentence" || words[i-1]=="bignum" || words[i-1]=="empty"  )
					variables.push_back(temp1);
			}
		}
	
	
	}

	for(int i=0;i<variables.size();i++)
	{
		for(int j=i+1;j<variables.size();j++)
		{
			if(variables[i]==variables[j])
			{
				cout << "Duplicate Variable/Function Declaration Found : "<< variables[i]<< endl;
				ret=false; // error found
			}
		}
	}

	return ret;
}







bool variable_initialization_check(std::fstream& file_code,std::fstream& file_error)
{

	
	string temp1;
	string temp; 
	bool ret=true;
	if( (!file_code.is_open() ) )
    {
        exit(EXIT_FAILURE);
    }
	
    while(!file_code.eof())
    {
			//	cout<<"Ffs";
        getline(file_code,temp);
        int space=0;
		int len=temp.size();

        for(int i=0;i<len;i++)
        {
            if(temp[i]==' ')
            space++;
        }

        int n=space+1;  // n = space + 1 
		string words[10000];
		int counter=0;

        for(int i=0;i<=len;i++){
        if(temp[i]==' ')
        counter++;
        else
        words[counter]+=temp[i];
        }


        for(int i=0;i<n;i++)
        {

             temp1 = words[i];

            if(temp1[0]=='_' && temp1[temp1.size()-1]=='_')
			{
				bool ch = false;

				for(int i=0;i<variables.size();i++)
				{ 
					if(variables[i] == temp1)
						ch=true;
				}
				if(ch==false)
				{
					cout << temp1 << " is not declared" << endl;
									//	cout << temp1 << " is not declared" << endl;
					ret=false;
				}

			}

		}
	}





//for(int i=0;i<variables.size();i++)
//	cout<<variables[i]<<endl;
return ret;
}






bool array_declaration_check(std::fstream& file_code) //check whether the declaration of array is valid of not
{
	
	
	string temp1;
	string temp; 
	bool ret=true;
	if( (!file_code.is_open() ) )
    {
        exit(EXIT_FAILURE);
    }
	
    while(!file_code.eof())
    {

        getline(file_code,temp);
        int space=0;
		int len=temp.size();

        for(int i=0;i<len;i++)
        {
            if(temp[i]==' ')
            space++;
        }

        int n=space+1;  // n = space + 1 
		string words[10000];
		int counter=0;

        for(int i=0;i<=len;i++){
        if(temp[i]==' ')
        counter++;
        else
        words[counter]+=temp[i];
        }


        for(int i=0;i<n;i++)
        {

             temp1 = words[i];
		 if(temp1[0]=='_' && temp1[temp1.size()-1]=='_')
            {

				if(words[i-1]=="num" || words[i-1]=="decision" || words[i-1]=="point" || words[i-1]=="dpoint" || words[i-1]=="symbol" || words[i-1]=="sentence" || words[i-1]=="bignum" || words[i-1]=="empty"  )
				{
					if( (words[i+1]=="[") && (words[i+3]=="]") ) 
					{
						int t = stoi(words[i+2]);
						if(t<=0)
						{
							cout<<"Invalid declaration of array "<<temp1<<" "<<endl;
							ret=false;
						}
					
					}			
				}	
		 }


		}

	} //while loop
	

	return ret;
}


