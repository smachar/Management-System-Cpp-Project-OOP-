
#include "Person.hpp"
//defining insert funnctions
void Person::set_f_name(std::string f_n){ f_name = f_n;}
void Person::set_l_name(std::string l_n){ l_name = l_n;}
void Person::set_nationality(std::string nat){ nationality = nat;}
void Person::set_code(std::string cod){ code = cod;}

std::map<std::string, std::string> person_messages = {
    { "error", "Can't open the 'person.dat' file\n"},
};

std::string Person::get_person() const{
    std::string all_inf_person;
    all_inf_person = f_name +" "+ l_name +" "+ nationality +" "+ code;
    return all_inf_person;
}

//the friend method.
std::ostream& operator<<(std::ostream &os, const Person &p)
{ 
    os<<"("<<p.get_f_name()<<" "<<p.get_l_name()<<", "
    <<p.get_nationality()<<", "<<p.get_code()<<")";
    return os;
}
void Person::reg_person(){
    //add the person to db
    std::ofstream p_ofile("person.dat", std::ios::app); //create a file person.dat if it doesn't exist
    p_ofile<<this->get_person()<<"\n";
    p_ofile.close();
}
int Person::disp_persons(){
    std::string p;
    std::ifstream p_ifile("person.dat");
    if(p_ifile.fail()){ 
        std::cout<<person_messages["error"];
        return 0;
    }
    while (getline(p_ifile, p)) //loop untill EOF
        std::cout << p<<"\n";
    p_ifile.close();
    return 1;
}