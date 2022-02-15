//
// Created by geanc on 11 ene. 2022.
//

#ifndef DATASTRUCTUREPROJECT_VIEW_H
#define DATASTRUCTUREPROJECT_VIEW_H
#include "Client.h"
#include "Validator.h"
class View {
private:
    Validator* validator;
public:
    explicit View();
    int  mainMenu();
    void showMessage(string s);
    long long int askForId();
    Client* makeClient();
    virtual ~View();
};


#endif //DATASTRUCTUREPROJECT_VIEW_H
