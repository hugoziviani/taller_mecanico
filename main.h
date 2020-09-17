//
// Created by Hugo Ziviani on 9/6/20.
//

#ifndef TALLER_MECANICO_MAIN_H
#define TALLER_MECANICO_MAIN_H


#include "tallerClass/TallerClass.h"
#include <string>
#include <cstring>
#include <list>
#include <fstream>
#include <tuple>
#include <vector>
#include <iostream>
#include <limits>

#define N_OPTION 5
using namespace std;


int getOption(string module, void (*func)(string));
void optionsBasic(string);
void optionsMenu(string module);
void programRoutes(string nameTaller, TallerClass *tallerObject);
int loginAndReturnUserType(list<tuple<int, string, string>> usersAndPass, string user, string pass);
list<tuple<int, string, string>> readFile(const char *path);
int userAutenticationAndRedirect(int intentos);
void optionsTaller(string module);

void optionsAdm(string);
void optionsMecanico(string);
void optionsAtendiente(string);



#endif //TALLER_MECANICO_MAIN_H
