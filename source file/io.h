#ifndef IO_H
#define IO_H

#include<iostream>
#include<fstream>
#include<vector>
#include "people.h"
#include "operation.h"
using namespace std;

void WriteTOFile(vector<person> &vect)
{
    fstream file;
    file.open("file.txt",ios::out | ios::trunc );  //open file.txt
    for(int i=0;i<vect.size();i++)  //write all objects to file
    {
        file<<vect[i].give_first() <<endl;  //first name
        file<<vect[i].give_mid() <<endl;    // middile name
        file<< vect[i].give_last() <<endl;  //last name
      	file<< vect[i].give_dob()<<endl;   //Date of DateOfBirth
      	file<< vect[i].give_occ()<<endl;   //occupation
      	file<< vect[i].give_city() <<endl; //city name
        file<< vect[i].give_mobile()<<endl;   //  mobile number
    }
    file.close(); //close the file
}


void LoadData(vector<person> &vect)
{
    fstream file;
    file.open("file.txt",ios::in ); //open file in read mode
    if(!file)
    {
      cout<<"error in file opening "<<endl;
      return ;
    }
    while(file)
    {

        person A;  //object of Class person
        string dd;
        string a,b,c;
        b=" ";
        getline(file, a); //first name

        getline(file, b); //middle Name
        getline(file, c); // last name
        A.set_name(a,b,c); // add to A

        getline(file, a); //DateOfBirth
        A.set_dob(a);   // add to A

        getline(file,dd); // occupation
        A.set_occ(dd);

        getline(file,b); //city
        A.set_city(b);

        getline(file,a); // mobile
        A.set_mob(a);
        SortAndInsert(vect,A); //Sort and Insert it to vecor of objects using insertion sort
    }

// every time a extra element is added so remove it
    vect.erase(vect.begin());
    file.close(); //close the file
}



#endif
