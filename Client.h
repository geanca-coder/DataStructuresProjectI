//
// Created by geanc on 8 ene. 2022.
//

#ifndef DATASTRUCTUREPROJECT_CLIENT_H
#define DATASTRUCTUREPROJECT_CLIENT_H

#include <iostream>
using namespace std;

class Client {
private:
    string name;
    long long int id;
    bool withAKid;
    bool pregnant;
    bool elder;
    int category;
public:
    explicit Client(const string &name="", long long int id=0, bool withAKid=false, bool pregnant=false, bool elder=false, int category=0);

    const string &getName() const;

    void setName(const string &name);

    long long int getId() const;

    void setId(long long int id);

    bool isWithAKid() const;

    void setWithAKid(bool withAKid);

    bool isPregnant() const;

    void setPregnant(bool pregnant);

    bool isElder() const;

    void setElder(bool elder);

    int getCategory() const;

    void setCategory(int category);

    friend ostream &operator<<(ostream &os, const Client &client);

    virtual ~Client();

    bool operator<(Client &rhs) ;

    bool operator>(Client &rhs);

    operator string();

    bool operator==(const Client &rhs) const;

    bool operator!=(const Client &rhs) const;

    int influence();

};


#endif //DATASTRUCTUREPROJECT_CLIENT_H
