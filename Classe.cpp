#include "Classe.hpp"

void Classe::set_full_name(std::string f_n){full_name = f_n;}
void Classe::set_short_name(std::string s_n){short_name = s_n;}
void Classe::set_mail(std::string e){mail = e;}
void Classe::set_stds_number(int stds){stds_number = stds;}
void Classe::set_start_year(std::string year){start_year = year;}

std::map<std::string, std::string> classe_messages = {
    { "stds", "students"},
    { "classprof", "given by"},
    { "error", "Sorry, the list of classes is not available right now!\n"},
    { "classlist", "\n\t\tThe classes list\n\t(short name, e-mail,number of students, start year)\n\n"},
    { "emptlist", "***The list is empty!!***\n"},
    { "tillnow", "==> There are "},
    { "classes", " classes.\n"},
    { "classinf", "Thank you to insert the class information : \n"},
    { "hint", "\nFull name* : "},
    { "fnamereq", "The full name is required!\nInsert the class's full name (or 0 to exit)\n->"},
    { "sname", "Short name : "},
    { "mail", "E-Mail: "},
    { "stdsnum", "\n(! 0 will stop the program, let it empty if you don't know the number)\nThe students count: "},
    { "stdsnumlong", "Could you please insert a valid number \n(! 0 will stop the program, insert '00' if you don't know the number or let it empty)\nThe students count: "},
    { "syear", "Start year (ex:2018-2019): "},
    { "success", "Successfully saved\n"},

};

std::string Classe::get_classe() const{
    std::string all_inf;
    if(stds_number!=0)
        all_inf = full_name+"(."+short_name+") "+mail+" "+std::to_string(stds_number)+" "+classe_messages["stds"]+" "+start_year;
    else all_inf = full_name+"(."+short_name+") "+mail+" "+"-- "+classe_messages["stds"]+" "+start_year;
    return all_inf;
}
void Classe::reg_classe(std::string prenom, std::string nom){
    std::ofstream p_ofile("classe.dat", std::ios::app);
    if(prenom=="unknown" || prenom=="unknown"){
        p_ofile<<this->get_classe()<<"\n";
        p_ofile.close();
    }
    else{
        p_ofile<<this->get_classe()<<" : "+classe_messages["classprof"]+"("<<prenom<<","<<nom<<")\n";
        p_ofile.close();
    }
}
//return indice of symbol in a line
int indice_par(std::string line){
    for(int i=0; i<line.size()-1; i++){
        if(line.at(i)=='(' && line.at(i+1)=='.'){
            return i;
        }
    }
    //std::cout<<"error finding '('\n";
    return line.size();
}

int disp_classes()
{
    int n_classes = 0,total_stds, index;
    std::string cl;
    std::ifstream p_ifile("classe.dat");
    if (p_ifile.fail())
    {
        //std::cout<<"error opening 'classe.dat' file\n";
        std::cout<<classe_messages["error"];
        return 0;
    }
    std::cout << classe_messages["classlist"];
    while (getline(p_ifile, cl)) //loop untill EOF
        if (cl != "")
        {
            n_classes++;
            index = indice_par(cl);
            std::cout << "|" << cl.substr(0,index)<<":\n\t"<<cl.substr(index,cl.size())<<"\n";

        }
    p_ifile.close();
    if (n_classes == 0)
        std::cout <<classe_messages["emptlist"];
    else
    {
        std::cout <<classe_messages["tillnow"]<< n_classes << classe_messages["classes"];
    }
    return 1;
}
int add_classe(On_p onp){
    std::string stds_in, f_n, s_n, e, year;
    int stds=0;
    std::cout<<classe_messages["classinf"];
    std::cout<<classe_messages["hint"];
    std::getline(std::cin, f_n);
    if(f_n=="0") return 0;
    if(f_n=="9") return -1;
    while(f_n.size()==0){
        std::cout<<classe_messages["fnamereq"];
        std::getline(std::cin, f_n);
        if(f_n=="0") return 0;
        if(f_n=="9") return -1;
    }
    std::cout<<classe_messages["sname"];
    std::getline(std::cin, s_n);
    if(s_n=="0") return 0;
    if(s_n=="9") return -1;
    // while(s_n.size()==0){
    //     std::cout<<"le Nom court est necessaire!\ndonner le nom court de la classe, svp(ou ecrire '0' pour quiter)\n->";
    //     std::getline(std::cin, s_n);
    //     if(s_n=="0") return 0;
    //     if(s_n=="9") return -1;
    // }
    std::cout<<classe_messages["mail"];
    std::getline(std::cin, e);
    if(e=="0") return 0;
    if(e=="9") return -1;
    std::cout<<classe_messages["stdsnum"];
    std::getline(std::cin, stds_in);
    if(stds_in=="0")return 0;
    //if(stds_in=="9") return -1;
    //stoi only supported in c++11 and above
    if(stds_in.size()!=0){
        while(stds==0){
            try{
                stds = std::stoi(stds_in);
                stds = abs(stds);
                if(stds==0) break;
            }
            catch(...){
                std::cout<<classe_messages["stdsnumlong"];
                std::getline(std::cin, stds_in);
                if(stds_in.size()==0) break;
                if(stds_in=="0")return 0;
                //if(stds_in=="9") return -1;
            }
        }
    }
    std::cout<<classe_messages["syear"];
    std::getline(std::cin, year);
    if(year=="0") return 0;
    if(year=="9") return -1;
    //if(onp.nom!="unknown")
    Classe cl(f_n,s_n,e,stds,year);
    cl.reg_classe(onp.prenom, onp.nom);
    std::cout<<classe_messages["success"];
    return 1;
}

