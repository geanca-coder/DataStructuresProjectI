//
// Created by geanc on 11 ene. 2022.
//

#include "View.h"

View::View() {
    validator = new Validator;

}

View::~View() {
    delete validator;
}

int View::mainMenu() {
    int opcion =0;
    cout<<"1-To enqueue all costumers: "<<endl;
    cout<<"2-To enqueue a customer: "<<endl;
    cout<<"3-To serve the next 5 customers: "<<endl;
    cout<<"4-To show the next customer to be served: "<<endl;
    cout<<"5-Customer service simulation: "<<endl;
    cout<<"6-Add a new client: "<<endl;
    cout<<"0-Exit: "<<endl;
    cout<<"Select a option: "<<endl;
    cin>>opcion;
    while(cin.fail()){
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<"1-To enqueue all costumers: "<<endl;
        cout<<"2-To enqueue a costumer: "<<endl;
        cout<<"3-To serve the next 5 customers:"<<endl;
        cout<<"4-To show the next client to be attended: "<<endl;
        cout<<"5-Costumer service simulation: "<<endl;
        cout<<"6-Add a new client: "<<endl;
        cout<<"0-Exit: "<<endl;
        cout<<"Select a option: "<<endl;
        cin>>opcion;
    }
    return opcion;
}

void View::showMessage(string s) {
    cout<<s;
}
long long int View::askForId() {
    string id;
    cout<<"INSERT THE ID NUMBER: ";
    cin.ignore(); getline(cin,id);
    if(not validator->numbersOnly(id)){
        cout<<"TRY AGAIN LATER!!!"<<endl;
        return -1;
    }
    return stoll(id);
}

Client *View::makeClient() {
    string name, withAkid, pregnant, elder; string id,category;
    cout<<"<---ADDING A CLIENT TO THE SYSTEM--->"<<endl;
    cout<<"INSERT ALL THE INFORMATION REQUESTED PLEASE"<<endl;
    cout<<"NAME:";
    cin.ignore();getline(cin,name);
    if(not validator->lettersOnly(name)){
        cout<<"TRY AGAIN LATER!!!"<<endl;
        return nullptr;
    }
    cout<<"ID:";
    getline(cin,id);
    if(not validator->numbersOnly(id)){
        cout<<"TRY AGAIN LATER!!!"<<endl;
        return nullptr;
    }

    cout<<"DO YOU COME WITH A KID? (YES OR NO):";
    getline(cin,withAkid);

    if(not validator->lettersOnly(withAkid)){
        cout<<"TRY AGAIN LATER!!!"<<endl;
        return nullptr;
    }
    if(not validator->yesOrNo(withAkid)){
        cout<<"TRY AGAIN LATER!!!"<<endl;
        return nullptr;
    }
    cout<<"ARE YOU PREGNANT (YER OR NO):";
    getline(cin, pregnant);
    if(not validator->lettersOnly(pregnant)){
        cout<<"TRY AGAIN LATER!!!"<<endl;
        return nullptr;
    }
    if(not validator->yesOrNo(pregnant)){
        cout<<"TRY AGAIN LATER!!!"<<endl;
        return nullptr;
    }
   
    cout<<"ARE YOU A SENIOR? (YES OR NO):";
    getline(cin,elder);
    if(not validator->lettersOnly(elder)){
        cout<<"TRY AGAIN LATER!!!"<<endl;
        return nullptr;
    }
    if(not validator->yesOrNo(elder)){
        cout<<"TRY AGAIN LATER!!!"<<endl;
        return nullptr;
    }
    cout<<"CATEGORY:";
    getline(cin, category);
    if(not validator->numbersOnly(category)){
        cout<<"TRY AGAIN LATER!!!"<<endl;
        return nullptr;
    }
    if(not validator->validCategory(category)){
        cout<<"TRY AGAIN LATER!!!"<<endl;
        return nullptr;
    }
    return new Client(name, stoll(id), (withAkid=="yes"),(pregnant=="yes"),(elder=="yes" ),stoi(category));
}
