#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
#include"lexer.h"
#include"parser.h"
#include"semantic.h"

using namespace std;

int main()
{
	fstream file;
    fstream file2;
    fstream file3;
	fstream file4,file5,file6,file7,file8;
	bool check;

  //  file.open("code.txt");
   // file2.open("tokens.txt");
   // file3.open("tokens.txt");
//	file4.open("tokens.txt");
	file5.open("code.txt");
	file6.open("Semantic Error Log.txt");
	file7.open("code.txt");
	file8.open("code.txt");
//	lexical_analyser(file,file2);

	//bool check = parser(file3);

	//if(!parser(file3))
	//{
	//	cout<<"There are syntactical errors in the code, please open 'Syntactic Error Log.txt' for details of Syntactic errors in code"<<endl;
		//return 0;
	//}
//	else // Now analyse for semantic
//	{
		check = variable_declaration_check(file5,file6);
	//	if(check==false)
//			cout<<"Duplicate Variable/Function Declaration Found .. Open Semeantic Error Log.txt for details" << endl;
//		check=true;
//		file6.open("Semantic Error Log.txt");
		check = variable_initialization_check(file7,file6);
//		if(check==false)
//		cout<<"Variable/Function Declaration is missing .. Open Semeantic Error Log.txt for details" << endl;
//		check=true;
		check = array_declaration_check(file8);



	}



//	cin.get();
	return 0;
}
