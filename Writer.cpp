//
// Created by geanc on 13 ene. 2022.
//

#include "Writer.h"

void Writer::write(const string& content, const string& file) {
    myfile.open(file, ios::app);
    myfile<<endl;
    myfile<<content;
    myfile.close();
}
