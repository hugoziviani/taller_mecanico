//
// Created by Hugo Ziviani on 9/6/20.
//

#ifndef TALLER_MECANICO_MAIN_H
#define TALLER_MECANICO_MAIN_H


#include "tallerClass/TallerClass.h"
#include "UniqueId.h"
#include <string>
#include <cstring>
#include <list>
#include <fstream>
#include <tuple>
#include <vector>
#include <iostream>
#include <limits>
#include <clocale>
#include <cstdlib>




using namespace std;


int getOption(string module, void (*func)(string));
void optionsBasic(string);
void optionsMenu(string module);
void programRoutes(string nameTaller, TallerClass *tallerObject);
int loginAndReturnUserType(list<tuple<int, string, string>> usersAndPass, string user, string pass);
list<tuple<int, string, string>> readFile(const char *path);
int userAutenticationAndRedirect();
void optionsTaller(string module);

//Admin
void optionsAdm(string);
void requiereId(string);
void menuAnadirTrabajador(string module);
void menuEditarTrabajador(string module);


void menuCrearTrabajador(string);

//Mecanico
void optionsVendedorYMecanico(string module);

//Atendiente
void optionsAtendiente(string);



#endif //TALLER_MECANICO_MAIN_H
