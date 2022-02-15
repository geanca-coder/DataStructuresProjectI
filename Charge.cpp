//
// Created by geanc on 11 ene. 2022.
//

#include "Charge.h"

Charge::Charge() {

}

Tree<Client, long long int> *Charge::chargeTree() {
    auto * tree = new Tree<Client, long long int >();
    string name=" ", id= " ", withAkid=" ", pregnant= " ", elder= " ", category= " ";
    fstream  file;
    char lim = ',';
    file.open("../DATABASE/DatosBancoUno.txt", ios::in);
    if(file.is_open()){
        while(!file.eof()) {
            getline(file, name, lim);
            getline(file, id, lim);
            getline(file, withAkid, lim);
            getline(file, pregnant, lim);
            getline(file, elder, lim);
            getline(file, category, '\n');
            tree->insert(new Client(name,stoll(id),(withAkid =="Yes"), (pregnant == "Yes"), (elder== "Yes"), stoi(category)), new long long int(stoll(id)));
        }
    }
    return tree;
}
Charge::~Charge() = default;