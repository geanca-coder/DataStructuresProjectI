//
// Created by geanc on 13 ene. 2022.
//

#ifndef DATASTRUCTUREPROJECT_WRITER_H
#define DATASTRUCTUREPROJECT_WRITER_H
#include <fstream>
using namespace std;
class Writer {
private:
    ofstream myfile;
public:

    void write(const string& content, const string& file);

};


#endif //DATASTRUCTUREPROJECT_WRITER_H
