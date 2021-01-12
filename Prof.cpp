#include "Prof.hpp"


std::map<std::string, std::string> prof_messages = {
    { "error", "Sorry, the list of professors is not available right now!!\n"},
    { "list", "\n\t\tThe professors list\n\t(first name, last name, nationality, code, E-mail, position)\n\n"},
    { "emptlist", "***The list is empty!!***\n"},
    { "exists", "==> Ther are "},
    { "pfs", " professors.\n"},
    { "pfinf", "Thank you to insert the professor's information :\n"},
    { "hint", "  **(first name, last name, E-mail are required)**\nThe first name : "},
    { "fnamereq", "The first name is required!\nInsert the professor's first name (or '0' to exit)\n->"},
    { "fname", "The last name : "},
    { "lnamereq", "The last name is also required!\ninsert the professor's last name (or '0' to exit)\n->"},
    { "nat", "The nationality: "},
    { "matr", "The code: "},
    { "mail", "E-Mail: "},
    { "mailreq", "E-Mail is also required!\nInsert the professor's E-mail(or '0' to exit)\n->"},
    { "pos", "The position: "},
    { "success", "Successfully saved\n"},
};

void Prof::set_mail(std::string mail_){mail = mail_;}
void Prof::set_status(std::string status_){status = status_;}

std::string Prof::get_prof() const{
    std::string all_inf;
    all_inf = this->get_person() +" "+ mail +" "+ status;
    return all_inf;
}
void Prof::reg_prof(){
    this->reg_person();
    std::ofstream p_ofile("prof.dat", std::ios::app); //create a file person.dat if it not already exists
    p_ofile<<this->get_prof()<<"\n";
    p_ofile.close();
}
int disp_profs(){
    int n_profs=0;
    std::string p;
    std::ifstream p_ifile("prof.dat");
    if(p_ifile.fail()){ 
        //std::cout<<"error opening 'person.dat' file\n";
        std::cout<<prof_messages["error"];
        return 0;
    }
    std::cout<<prof_messages["list"];
    while (getline(p_ifile, p)) //loop untill EOF
        if(p!=""){
            n_profs++;
            std::cout<<"|"<< p<<".\n";
        }
    p_ifile.close();
    if(n_profs==0)
        std::cout<<prof_messages["emptlist"];
    else{
        std::cout<<prof_messages["exist"]<<n_profs<<prof_messages["pfs"];
    }
    return 1;
}
On_p add_prof(std::string t1,std::string t2,std::string t3,
        std::string t4,std::string t5,std::string t6){
    Prof p;
    std::cout<<prof_messages["pfinf"];
    std::cout<<prof_messages["hint"];
    std::getline(std::cin, t1);
    if(t1=="0") return {0, p.get_f_name(), p.get_l_name()};
    if(t1=="9") return {-1, p.get_f_name(), p.get_l_name()};
    while(t1.size()==0){
        std::cout<<prof_messages["fnamereq"];
        std::getline(std::cin, t1);
        if(t1=="0") return {0, p.get_f_name(), p.get_l_name()};
        if(t1=="9") return {-1, p.get_f_name(), p.get_l_name()};
    }
    std::cout<<prof_messages["fname"];
    std::getline(std::cin, t2);
    if(t2=="0") return {0,p.get_f_name(), p.get_l_name()};
    if(t2=="9") return {-1,p.get_f_name(), p.get_l_name()};
    while(t2.size()==0){
        std::cout<<prof_messages["lnamereq"];
        std::getline(std::cin, t2);
        if(t2=="0") return {0,p.get_f_name(), p.get_l_name()};
        if(t2=="9") return {-1,p.get_f_name(), p.get_l_name()};
    }
    std::cout<<prof_messages["nat"];
    std::getline(std::cin, t3);
    if(t3=="0") return {0,p.get_f_name(), p.get_l_name()};
    if(t3=="9") return {-1,p.get_f_name(), p.get_l_name()};
    std::cout<<prof_messages["matr"];
    std::getline(std::cin, t4);
    if(t4=="0") return {0,p.get_f_name(), p.get_l_name()};
    if(t4=="9") return {-1,p.get_f_name(), p.get_l_name()};
    std::cout<<prof_messages["mail"];
    std::getline(std::cin, t5);
    if(t5=="0") return {0,p.get_f_name(), p.get_l_name()};
    if(t5=="9") return {-1,p.get_f_name(), p.get_l_name()};
    while(t5.size()==0){
        std::cout<<prof_messages["mailreq"];
        std::getline(std::cin, t5);
        if(t5=="0") return {0,p.get_f_name(), p.get_l_name()};
        if(t5=="9") return {-1,p.get_f_name(), p.get_l_name()};
    }
    std::cout<<prof_messages["pos"];
    std::getline(std::cin, t6);
    if(t6=="0") return {0,p.get_f_name(), p.get_l_name()};
    if(t6=="9") return {-1,p.get_f_name(), p.get_l_name()};

    p = Prof(t1,t2,t3,t4,t5,t6);
    p.reg_prof();
    std::cout<<prof_messages["success"];
    return {1,p.get_f_name(), p.get_l_name()};
}