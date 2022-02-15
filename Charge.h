//
// Created by geanc on 11 ene. 2022.
//

#ifndef DATASTRUCTUREPROJECT_CHARGE_H
#define DATASTRUCTUREPROJECT_CHARGE_H

#include "Tree.h"
#include "Client.h"
#include "PriorityQueue.h"
#include <fstream>
class Charge {
public:
    Charge();
    Tree<Client,long long int>* chargeTree();
    ~Charge();
};


#endif //DATASTRUCTUREPROJECT_CHARGE_H
