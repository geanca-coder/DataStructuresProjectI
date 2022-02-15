//
// Created by geanc on 11 ene. 2022.
//

#ifndef DATASTRUCTUREPROJECT_CONTROLLER_H
#define DATASTRUCTUREPROJECT_CONTROLLER_H

#include "Charge.h"
#include "PriorityQueue.h"
#include "View.h"
#include "Writer.h"
class Controller {
private:
    Tree<Client,long long int> * tree;
    Charge * charger;
    PriorityQueue<Client> queue;
    View* view;
    string allkeys;
    Client * client;
    Writer* writer;
public:
    Controller();

    void main();

    void enqueueThemAll();

    void addClient();

    void showNext();

    void nextFiveCostumers();

    void enqueueACostumer();

    void costumerServiceSimulation();


    ~Controller();

};


#endif //DATASTRUCTUREPROJECT_CONTROLLER_H
