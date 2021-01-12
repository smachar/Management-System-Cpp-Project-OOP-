#ifndef CLASSE_HPP
#define CLASSE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>

#include "Prof.hpp"

class Classe{
    private:
    std::string full_name;
    std::string short_name;
    std::string mail;
    int stds_number;
    std::string start_year; //(2018-2019)
    public:
    Classe()
    {
        full_name="unknown";
        short_name="unknown";
        mail="unknown";
        stds_number=0;
        start_year="unknown";

    }
    //(nom court,e-mail,#etudiants,annee de debut)
    Classe(std::string f_n,std::string s_n,std::string e,int stds, std::string year){
        full_name=f_n;
        stds_number=stds;

        if(s_n=="") short_name="unknown";
        else short_name=s_n;

        if(e=="") mail="unknown";
        else mail=e;

        if(year=="") start_year="unknown";
        else start_year = year;
    }
    void set_full_name(std::string);
    void set_short_name(std::string);
    void set_mail(std::string);
    void set_stds_number(int);
    void set_start_year(std::string);

    std::string get_full_name(){return full_name;}
    std::string get_short_name(){return short_name;}
    std::string get_mail(){return mail;}
    int get_stds_number(){return stds_number;}
    std::string get_start_year(){return start_year;}    
    std::string get_classe() const;
    void reg_classe(std::string, std::string);
};
int indice_par(std::string);
int disp_classes(); //display classes in db, 0:something wrong, 1:success

int add_classe(On_p);

#endif