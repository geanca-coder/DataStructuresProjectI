//
// Created by geanc on 12 ene. 2022.
//

#include "Validator.h"

bool Validator::numbersOnly(string s) {
    try{
        int i =0;
        for(char & e : s) {
            if(i==0 && e=='-') {
                i++;
                continue;
            }
            if (!isdigit(e)) {
                throw runtime_error("RUNTIME EXCEPTION, INVALID INPUT, NUMBERS ONLY!!");
            }
        }
    }catch(runtime_error & e){
        cout<<e.what()<<endl;
        return false;
    }
    return true;
}

Validator::Validator() {

}

Validator::~Validator() {

}

bool Validator::lettersOnly(string s) {
    try{
        for(char & e : s) if(isdigit(e)) throw runtime_error("RUNTIME EXCEPTION, INVALID INPUT, LETTERS ONLY!!");
    }catch ( runtime_error & e){
        cout<<e.what()<<endl;
        return false;
    }
    return true;
}

bool Validator::yesOrNo(string s) {
    try{
        for(auto & x:s) x = tolower(x);
        if(s !="yes" && s!="no"&&s!="si") throw runtime_error("RUNTIME EXCEPTION, INVALID INPUT, YES OR NO ONLY!!!");
    }catch (runtime_error & e){
        cout<<e.what()<<endl;
        return false;
    }
    return true;
}

bool Validator::validCategory(string s) {
    try{
        int i = stoi(s);
        if(!(i>0 && i<4)) throw runtime_error("INVALID CATEGORY, CATEGORIES AVAILABLE FROM 1 TO 3");
    }catch (runtime_error & e){
        cout<<e.what()<<endl;
        return false;
    }
    return true;
}
