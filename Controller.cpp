//
// Created by geanc on 11 ene. 2022.
//

#include "Controller.h"

Controller::Controller() {
    charger = new Charge();
    tree = charger->chargeTree();
    view = new View();
    allkeys = tree->allkeys();
    client  = nullptr;
    writer = new Writer;
}

Controller::~Controller() {
    delete tree;
    delete charger;
    delete view;
    delete writer;
}

void Controller::main() {

    int option = view->mainMenu();
    do {
        switch (option) {
            case 1:

                enqueueThemAll();
                view->showMessage("ALL ELLEMENTS FROM THE TREE HAVE BEEN ENQUEUED\n");
                break;
            case 2:
                enqueueACostumer();
                break;
            case 3:

                nextFiveCostumers();
                break;
            case 4:

                showNext();
                break;
            case 5:

                costumerServiceSimulation();
                break;
            case 6:
                addClient();
                break;

            case 0:
                /*
                 SE BUSCO OPTIMIZAR EL CODIGO
                 YA QUE UNA RECONSTRUCCION DEL ARCHIVO TXT APARTIR DEL ARBOL
                 TOMARIA O(n), LA ESTRATEGIA QUE SE TOMO ES QUE
                 A LA HORA QUE EL CLIENTE CORRESPONDIENTE
                 SE INGRESA EN EL ARBOL, SE HACE LA ESCRITURA DEL MISMO
                 TOMANDO O(1), ESTA  OPTIMIZACION SE CONSULTO CON EL PROFESOR,
                 Y EL NOS DIO EL VISTO BUENO, DE LO MENCIONADO ANTERIORMENTE.

                 LA ESCRITURA DE LOS NUEVOS CLIENTES AGREGADOS SIGUE SIENDO CORRECTA

                 POR LO TANTO LA OPCION SALIR OMITE ESO Y SOLAMENTE SE SALE DEL PROGRAMA
                 */
                view->showMessage("THANK YOU FOR COMING!!!\n\n");
                break;

            default:
                view->showMessage("INCORRECT OPTION\n\n");
                break;
        }
        if(option!=0){
            option = view->mainMenu();
        }
    } while (option!=0);

}

void Controller::enqueueThemAll() {
    string tempKey;
    for(char allkey : allkeys)
    {
        if(allkey==','){
           queue.insert(tree->search( new long long int(stoll(tempKey))));
           tempKey="";
           continue;
        }
        tempKey+=allkey;
    }
}

void Controller::addClient() {
    client  = view->makeClient();
    if(!client) return;
    string tempKey;
    int i = 0;
    for(char allkey : allkeys)
    {
        if(allkey==','){
            i++;
            if(tempKey == to_string(client->getId())){
                view->showMessage("ERROR A CUSTOMER WITH THAT ID "+ to_string(client->getId())+" ALREADY EXISTS!!!\n");
                client = nullptr;
                return;
            }
            tempKey="";
            continue;
        }
        tempKey+=allkey;
    }

    allkeys+= to_string(client->getId())+",";
    tree->insert(client, new long long int(client->getId()));
    view->showMessage("SUCCESFUL INSERTION\n");

    string withAKid="No", pregnant="No", elder="No";
    if(client->isWithAKid()) withAKid="Yes";
    if(client->isPregnant()) pregnant="Yes";
    if(client->isElder()) elder ="Yes";
    string content = client->getName()+","+ to_string(client->getId())+","+withAKid+","+pregnant+","+elder+","+
            to_string(client->getCategory());
    writer->write(content,"../DATABASE/DatosBancoUno.txt");
    client = nullptr;
}

void Controller::showNext() {

    if(queue.quantity()<0){
        view->showMessage("PRIORITY QUEUE IS EMPTY PLEASE ENQUEUE A COSTUMER!!\n");
        return;
    }
    view->showMessage("NEXT CUSTOMER TO BE SERVED\n");
    view->showMessage(*queue.getMax());
    view->showMessage("\n");
}

void Controller::nextFiveCostumers() {

    if(queue.quantity()<0)
    {
        view->showMessage("PRIORITY QUEUE IS EMPTY\n");
        view->showMessage("TRY AGAIN LATER\n");
        return;
    }
    int size = queue.quantity();
    if(size>4) size = 4;
    for(int i = 0; i <=size; i++)
    {
        view->showMessage(*queue.extractMax());
        view->showMessage("\n");
    }
}

void Controller::enqueueACostumer() {

    long long int variable = view->askForId();
    if(variable ==-1) return;
    client = tree->search(new long long int(variable));
    if(!client){
        view->showMessage("COSTUMER DOES NOT EXIST IN THE TREE\n");
        return;
    }
    if(!queue.insert(client))
    {
        view->showMessage("COSTUMER ALREADY EXISTS IN THE PRIORITY QUEUE\n");
        return;
    }
    queue.insert(client);
    view->showMessage("SUCCESFUL INSERTION INTO THE PRIORITY QUEUE\n");
    cout<<queue.quantity()<<endl;
    client = nullptr;

}

void Controller::costumerServiceSimulation() {

    if(queue.quantity()<0){
        view->showMessage("PRIORITY QUEUE IS EMPTY\n");
        return;
    }
    view->showMessage("SERVING ALL COSTUMERS\n");
    int size = queue.quantity();
    for(int i = 0; i <=size; i++)
    {
        view->showMessage(*queue.extractMax());
    }

}
