
#ifndef PROF_HPP
#define PROF_HP

#include <iostream>
#include <fstream>
#include <string>
#include <map>

#include "Person.hpp"


class Prof: public Person{
    private:
    std::string mail;
    std::string status;

    public:
    Prof(std::string t1,std::string t2,std::string t3,
        std::string t4,std::string t5,std::string t6):Person(t1,t2,t3,t4){
            mail = t5; 
            if(t6!="") status=t6;
            else status="unknown";
        }
    Prof():Person()
    { 
        mail = "unknown", status="unknown";
    }

    void set_mail(std::string);
    void set_status(std::string);

    std::string get_mail() const{return mail;};
    std::string get_status() const{return status;};    
    std::string get_prof() const; //return all prof's info in one string
    void reg_prof(); //register the prof in db!!(file called prof.dat)
};

int disp_profs(); //display profs in db, 0:something wrong, 1:success
struct On_p {
    int on;
    std::string prenom;
    std::string nom;
};
On_p add_prof(std::string,std::string,std::string,
        std::string,std::string,std::string);
#endif