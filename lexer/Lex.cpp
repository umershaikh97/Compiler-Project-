#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h> 
#include'parser.h'
 
using namespace std;

//Routine for analysing a Keyword
int Keyword_lang(char bufferReg[]){
                          //"auto(automatic)","break"(br),"case(Cse)","char(character)","const(constant)","continue(Cont)","default(def)",
                         //   "do(Dooee)","double(dble)","else(Els)","enum(Nume)","extern(external)","float(fpoint)","for(DoFor) ","goto(Wento)",
                           // "if(IfandOnlyif)","int(integer)","long(VeryLong)","register(Reg)","return(Back)","short(Small)","signed(Sig)",
                            //"sizeof(siz)","static(stat)","struct(Stur)","switch(Plug)","typedef(Deft)","union(Combo)",
                            //"unsigned(SignU)","void(Nothing)","volatile(Vapo)","while(Doif)","cout(Print)","cin(Catchit)"}

    char keywords[34][10] = {"automatic","br","Cse","character","constant","Cont","def"
                            "Dooee","dble","Els","Nume","external","fpoint","DoFor ","Wento",
                            "If&if","integer","VeryLong","Reg","Back","Small","Sig",
                            "siz","stat","Stur","Plug","Deft","Combo",
                            "SignU","Nothing","Vapo","Doif","Print","Catchit"};
    int flag = 0;
    
	//loop for comparing buffer register with each indivisual keyword
    for(int x = 0; x < 34; ++x){
        if(strcmp(keywords[x], bufferReg) == 0){
            flag = 1;
            break;
        }
    }
    
    return flag;
}
 

//Main Program
int main(){
    char ch, buffer[20], operators[] = "+-*/%=";

	//Open file
    ifstream fin("testbench.txt");
	int i,j=0;
   
	//if no file open
    if(!fin.is_open()){
        cout<<"Can not open file...Try Again!!!\n";
        exit(0);
    }
    
	//continue looping till the End Of File
    while(!fin.eof()){
           ch = fin.get();
          
		   //if the ch that we get is an operator
        for(i = 0; i < 6; ++i){
               if(ch == operators[i])
                   cout<<ch<<" ---------------->Operator\n";
           }
           
		// If the ch is Alhpanumeric 
           if(isalnum(ch)){
               buffer[j++] = ch;
           }
		   else if( ch == '>' || ch == '<' ){
			   cout<<ch<<" ---------------->IO Directive\n";
		   }
		   else if( ch == ';'){
			   cout<<ch<<" ---------------->Terminator\n";
		   }
		   //else check if ch is a keyword or an  identifier
           else if((ch == ' ' || ch == '\n') && (j != 0)){
                   buffer[j] = '\0';
                   j = 0;
                                      
                   if(Keyword_lang(buffer) == 1)
                       cout<<buffer<<" ---------------->Keyword\n";
                   else
                       cout<<buffer<<" ---------------->Indentifier\n";
           }
           
    }
    
	//close file 
    fin.close();
    
    return 0;
}

