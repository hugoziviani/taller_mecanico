//
// Created by Hugo Ziviani on 9/6/20.
//

#ifndef TALLER_MECANICO_MAIN_H
#define TALLER_MECANICO_MAIN_H

#include "./vehiculo/Vehiculo.h"
#include <iostream>
#include <string>
#include <cstring>
#include <list>
#include <fstream>
#include <tuple>
#include <vector>

#define PROGRAM 1
#define ADD_USER 2

using namespace std;

bool menu();
list<tuple<int, string, string>> readFile(const char *path);
bool login(list<tuple<int, string, string>> usersAndPass, string user, string pass);

#endif //TALLER_MECANICO_MAIN_H
