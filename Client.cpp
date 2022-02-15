//
// Created by geanc on 8 ene. 2022.
//

#include "Client.h"

ostream &operator<<(ostream &os, const Client &client) {
    os << "Name: " << client.name <<"\n"<< "Id: " <<fixed<< client.id<<"\n"<< "With a kid: " << client.withAKid <<"\n"<< "Pregnant: "
       << client.pregnant<< "\n"<<"Elder: " << client.elder<< "\n"<<"Category: " << client.category<<"\n\n";
    return os;
}

Client::~Client() {

}

int Client::influence() {
    int influenceAmount = 0;
    if(isWithAKid()) influenceAmount+=20;
    if(isPregnant()) influenceAmount+=25;
    if(isElder()) influenceAmount+=35;
    if(getCategory()!=3) influenceAmount = (getCategory() ==1) ? influenceAmount+20: influenceAmount+10;
    return influenceAmount;
}

Client::Client(const string &name, long long int id, bool withAKid, bool pregnant, bool elder, int category) : name(
        name), id(id), withAKid(withAKid), pregnant(pregnant), elder(elder), category(category) {
}

const string &Client::getName() const {
    return name;
}

void Client::setName(const string &name) {
    Client::name = name;
}

long long int Client::getId() const {
    return id;
}

void Client::setId(long long int id) {
    Client::id = id;
}

bool Client::isWithAKid() const {
    return withAKid;
}

void Client::setWithAKid(bool withAKid) {
    Client::withAKid = withAKid;
}

bool Client::isPregnant() const {
    return pregnant;
}

void Client::setPregnant(bool pregnant) {
    Client::pregnant = pregnant;
}

bool Client::isElder() const {
    return elder;
}

void Client::setElder(bool elder) {
    Client::elder = elder;
}

int Client::getCategory() const {
    return category;
}

void Client::setCategory(int category) {
    Client::category = category;
}
bool Client::operator>(Client &rhs){
    return influence() > rhs.influence();
}
bool Client::operator<(Client &rhs) {
    return influence() < rhs.influence();
}

Client::operator string() {
    return "Nombre: "+ name+"\nId: "+ to_string(id)+"\nWith a kid: "+ to_string(withAKid)+"\nPregnant: "+ to_string(pregnant)+
    "\nElder: "+ to_string(elder)+"\nCategory: "+ to_string(category)+"\n\n";
}

bool Client::operator==(const Client &rhs) const {
    return name == rhs.name &&
           id == rhs.id &&
           withAKid == rhs.withAKid &&
           pregnant == rhs.pregnant &&
           elder == rhs.elder &&
           category == rhs.category;
}

bool Client::operator!=(const Client &rhs) const {
    return !(rhs == *this);
}
