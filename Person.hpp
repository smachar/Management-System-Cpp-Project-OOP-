
#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>

class Person
{
private:
    std::string f_name;
    std::string l_name;
    std::string nationality;
    std::string code;

public:
    Person()
    {
        //count++;
        f_name = "unknown", l_name = "unknown", code = "unknown", nationality = "unknown";
    }
    //first&last are necessary for this constructor
    Person(std::string f_n, std::string l_n, std::string nat, std::string cod)
    {
        //count++;
        f_name = f_n, l_name = l_n;
        if(nat=="") nationality = "unknown";
        else nationality = nat;
        if(cod=="") code = "unknown";
        else code = cod;
    }

    /*..use these methodes to change the person's inf..*/
    void set_f_name(std::string);
    void set_l_name(std::string);
    void set_code(std::string);
    void set_nationality(std::string);

    /*..use these to access a peron's inf..*/
    std::string get_f_name() const { return f_name; };
    std::string get_l_name() const { return l_name; };
    std::string get_code() const { return code; };
    std::string get_nationality() const { return nationality; };

    std::string get_person() const; //return person's inf in one string

    /*displaying functions/ for the operator '<<' 
    ex: std::cout<<person1 : (f_name, l_name, nation, status)*/
    friend std::ostream &operator<<(std::ostream &os, const Person &p); //operatot <<
    /* friend is used here because of the return type is not a 'Person'.
    this function(operator) will be called from another class(ostream), so it needs access to attributs of the class 'Person' */

    //registering info person.dat (file)
    void reg_person(); //each line represents a person for example:prenom nom marocan 123123123\n

    //get all registred persons
    static int disp_persons(); //display persons in db,returns 0:if something wrong, 1:success
};
#endif