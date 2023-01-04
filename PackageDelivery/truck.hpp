#pragma once
#include<iostream>
using namespace std;
#include <fstream>


class Truck
{
    private:
    string driver;
    double petrol;
    int fullMileage;
    int emptyMileage;
    string regNo;

    public:
    
    Truck()
    {
        this->driver = "";
        this->petrol = 0;
        this->regNo = "";
        this->fullMileage  = 0;
        this->emptyMileage = 0; 
    }

    Truck(string driver, double petrol, string regNo, int fullMileage, int emptyMileage)
    {
        this->driver = driver;
        this->petrol = petrol;
        this->regNo = regNo;
        this->fullMileage  = fullMileage;
        this->emptyMileage = emptyMileage; 
    }

    void print_info()
    {
        std::cout<< driver << endl;
        std::cout<< petrol << endl;
        std::cout<< regNo << endl; 
        std::cout<< fullMileage << endl;
        std::cout<< emptyMileage << endl;
    }

    string get_regNo()
    {
        return regNo;
    }
    string get_driver()
    {
        return driver;
    }
    double get_petrol()
    {
        return petrol;      
    }
    int get_emptyMileage()
    {
        return emptyMileage;
    }
    int get_fullMileage(){
        return fullMileage;
    }
    
    void calculate(){
        double required_petrol = float(60)/float(fullMileage) + float(60)/float(emptyMileage);
        if (required_petrol < petrol){
            petrol =  petrol - required_petrol;
        }
    }

};

