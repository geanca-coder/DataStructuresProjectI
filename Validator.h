//
// Created by geanc on 12 ene. 2022.
//

#ifndef DATASTRUCTUREPROJECT_VALIDATOR_H
#define DATASTRUCTUREPROJECT_VALIDATOR_H

#include<iostream>
using  namespace std;
class Validator {
public:
    Validator();
    bool numbersOnly(string s);
    bool lettersOnly(string s);
    bool yesOrNo(string s);
    bool validCategory(string s);
    ~Validator();
};


#endif //DATASTRUCTUREPROJECT_VALIDATOR_H
