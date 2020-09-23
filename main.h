#ifndef TALLER_MECANICO_MAIN_H
#define TALLER_MECANICO_MAIN_H

///MODIFICAR o File para atuenticação
#define FILE_PATH_AUTENTICATION "/Users/hz/CLionProjects/taller_mecanico/input/user.txt"
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
int userAutenticationAndRedirect(const char *path);
void optionsTaller(string module);

//Admin
void optionsAdm(string);
void requiereId(string);
void menuAnadirTrabajador(string module);
void menuEditarTrabajador(string module);

//Mecanico
void optionsMecanico(string module);

//Atendiente
void optionsAtendiente(string);

void createObjectsToTest(TallerClass *taller); //Cria objetos para teste

#endif //TALLER_MECANICO_MAIN_H
