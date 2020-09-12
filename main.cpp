#include "main.h"


int Vehiculo :: contador = 0;
int main() {
    bool autorized = true;
//    autorized = userAutentication();

    if(autorized){
        int *caso;
        menu(caso);
        switch (*caso) {
            case 0: {
                cout<<"Sliendo... Graciar por utilizar Zii-Programs"<<endl;
                break;
            }
            case 1:{
                cout<<"Bien Venido(a) al Taller Mecánico de Garcia Marquez"<<endl;

                break;
            }
            case 2:{
                cout<<"Hola!, Vas agregar un trabajador nuevo..."<<endl;

                break;
            }
            case 3:{
                cout<<"Hola, Vas agregar/editar un Cliente"<<endl;

                break;
            }
            case 4:{
                cout<<"Que bueno! A crear/modificar una nueva orden de servicio"<<endl;
                break;
            }
            case 5:{
                cout<<"No lo sé"<<endl;

            }
        }
    }
    return 0;
}

void options(){
    cout<<"Elije tu opción:\n"
          "1-Taller Meçanico\n"
          "2-Agregar Trabajador\n"
          "3-Agregar Cliente\n"
          "4-Nueva Orden de Servicio\n"
          "5-Consultar/Modificar Ordenes\n"
          "0-Para salir\n"
        <<endl;
}

void menu(int *input){
    options();
    cin >> *input;
    while(cin.fail()){
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        options();
        cin >> *input;
    }
}

bool userAutentication(){
    string inputUsername, inputPass;
    cout<<"Hola, dime tu user:"<<endl;
    cin >> inputUsername;
    cout<<"Dime tu contraseña "<<inputUsername<<endl;
    cin >> inputPass;

    list<tuple<int, string, string>> usersAndPass = readFile("/Users/hz/CLionProjects/taller_mecanico/input/user.txt");
    bool autorized;
    autorized = login(usersAndPass, inputUsername, inputPass);
    if (autorized){
        cout<<"Bien Venido al Taller Mecánico de Juán Garcia"<<endl;
        return true;
    }else{
        cout<<"Vete a la mierda pinche Hacker!"<<endl;
    }
    return false;
}

list<tuple<int, string, string>> readFile(const char *path){
    list<tuple<int, string, string>> usersAndPass;
    FILE *arq;
    char buffer[BUFSIZ] ;
    char delimiters[]=":\n";
    arq = fopen(path, "r") ;
    int count_lines = 0;

    while(fgets(buffer, BUFSIZ, arq) != NULL) {
        string user = (string) strtok(buffer, delimiters);
        string pass = (string) strtok(NULL, delimiters);
//        cout<<"user:"<<user<<endl;
//        cout<<"pass:"<<pass<<endl;
        tuple<int, string, string> tuple = make_tuple(count_lines, user, pass);
        usersAndPass.emplace_back(tuple);
        count_lines ++;
    }

    fclose(arq);
    return  usersAndPass;
}

bool login(list<tuple<int, string, string>> usersAndPass, string user, string pass){
    if (usersAndPass.empty()) return false;
    string us, ps;
    for (auto& x: usersAndPass) {
        us = std::get<1>(x);
        ps = std::get<2>(x);
        int u, p;
        u = user.compare(us); //user
        p = pass.compare(ps); //pass
        if (u == 0 and p == 0) {
            return true;
        }
    }
    return false;
}
