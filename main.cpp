#include <iostream>
#include <fstream>
#include <string>
#include <ios> 
#include <limits>
#include <cstdlib>
#include <map>

#include "Classe.hpp"


std::map<std::string, std::string> messages = {
    { "title", "\n          Thank you to choose from these options: \n\n"},
    {"9", "to go back to the home page(this one).\n"},
    {"0", "to exit the program.\n"},
    {"1", "to add a new professor.\n"},
    {"2", "to list all professors.\n"},
    {"3", "to add a new class.\n"},
    {"4", "to list all classes .\n"},

    {"choose", "Thank you to choose from the above options(one choice at a time)\n->"},
    {"yesno", "Thank you to choose 'o'(yes) or 'n'(no)\n->"},

    {"addprofclass", "Do you want to add a class given by this professor?(o/n)\n->"},
    {"addprofclassmore", "Do you want to add another class given by the same professor?(o/n)\n->"},

    {"addprofmore", "Do you want to add another professor?(o/n)\n->"},

    {"addclassmore", "Do you want to add another class?(o/n)\n->"},

};

//using namespace std;
std::string home(){
    std::string ch;
    std::cout<<messages["title"];
    std::cout<<"9 : "+messages["9"];//-1
    std::cout<<"0 : "+messages["0"];
    std::cout<<"1 : "+messages["1"];
    std::cout<<"2 : "+messages["2"];
    std::cout<<"3 : "+messages["3"];
    std::cout<<"4 : "+messages["4"];
    std::cout<<"->";

    std::getline(std::cin, ch);
    while(ch.size()!=1||(ch[0]!='0'&& ch[0]!='1'&&ch[0]!='2'&&ch[0]!='3'&&ch[0]!='4'&&ch[0]!='9')){
        std::cout<<messages["choose"];
        std::getline(std::cin, ch);
    }
    return ch;
}
int add_prof_class(On_p onp,std::string ch){
    int on;
    std::string more_classe;
    std::cout << messages["addprofclass"];
    std::getline(std::cin, more_classe);
    while (more_classe.size() != 1 || (tolower(more_classe[0]) != 'o' && tolower(more_classe[0]) != 'n'))
    {
        std::cout << messages["yesno"];
        std::getline(std::cin, more_classe);
    }
    while (more_classe[0] == 'o')
    {
        on = add_classe(onp);   
        if (on == 0)
            return 0;
        if (on == -1)
        {
            ch = home();
            return -1;//break; 
        }
        std::cout << messages["addprofclassmore"];
        std::getline(std::cin, more_classe);
        while (more_classe.size() != 1 || (tolower(more_classe[0]) != 'o' && tolower(more_classe[0]) != 'n'))
        {
            std::cout << messages["yesno"];
            std::getline(std::cin, more_classe);
        }
    }
    return -1;
}


int main(){
    system("clear");
    std::string ch,t1,t2,t3,t4,t5,t6;
    std::string f_n,s_n,e,year;
    int stds;
    ch = home();
    while (ch[0]!='0')
    {
        std::string more;
        int on;
        On_p onp;
        switch (ch[0])
        {
        case '9':
            ch = home();
            break;
        case '1':
            onp = add_prof(t1,t2,t3,t4,t5,t6);
            if (onp.on==0) return 0;
            if (onp.on==-1){
                ch = home();
                break;
            }
            on=add_prof_class(onp, ch);
            if(on==0) return 0;
            if(on==-1) 
            {   
                ch = home();
                break;
            }
            std::cout<<messages["addprofmore"];
            std::getline(std::cin, more);
            while(more.size()!=1 || (tolower(more[0])!='o' && tolower(more[0])!='n')){
                std::cout<<messages["yesno"];
                std::getline(std::cin, more);
            }
            while(more[0]=='o'){
                t1="",t2="",t3="",t4="",t5="",t6="";
                onp = add_prof(t1,t2,t3,t4,t5,t6);
                if (onp.on==0) return 0;
                if (onp.on==-1){
                    ch = home();
                    break;
                }
                on = add_prof_class(onp, ch);
                if(on==0) return 0;
                if(on==-1) break;
                std::cout<<messages["addprofmore"];
                std::getline(std::cin, more);
                while(more.size()!=1 || (tolower(more[0])!='o' && tolower(more[0])!='n')){
                    std::cout<<messages["yesno"];
                    std::getline(std::cin, more);
                }
            }
            if(more[0]=='n'){
                ch=home();
                break;
            }
        case '2':
            if (disp_profs()==0) return 0;
            ch=home();
            break;
        case '3':
            on = add_classe(onp);
            if (on==0) return 0;
            if (on==-1){
                ch = home();
                break;
            }
            std::cout<<messages["addclassmore"];
            std::getline(std::cin, more);
            while(more.size()!=1 || (tolower(more[0])!='o' && tolower(more[0])!='n')){
                std::cout<<messages["yesno"];
                std::getline(std::cin, more);
            }
            while(more[0]=='o'){
                on = add_classe(onp);
                if(on==0) return 0;
                if(on==-1){
                    ch = home();
                    break;
                }
                std::cout<<messages["addclassmore"];
                std::getline(std::cin, more);
                while(more.size()!=1 || (tolower(more[0])!='o' && tolower(more[0])!='n')){
                    std::cout<<messages["yesno"];
                    std::getline(std::cin, more);
                }
            }
            ch=home();
            break;
        case '4':
            if (disp_classes()==0) return 0;
            ch=home();
            break;
        }
    }
    return 0;
}