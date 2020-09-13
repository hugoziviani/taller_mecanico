#include "main.h"

int Vehiculo :: contador = 0;

int main() {
    bool autorized = true;
    int *caso;

    autorized = userAutentication();

    if(autorized){
        programRoutes("Hzii");
    }
    return 0;
}

int getOption(string module, void (*func)(string)) {
    if (func== nullptr)return-1;
    func(module);
    int input;
    cin >> input;
    while(cin.fail()){
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        func(module);
        cin >> input;
    }
    if (input>=0 and input <=N_OPTION){
        return input;
    }else return -1;
}
void optionsBasic(string module) {
    string options[]={
            "________"+module+"________:\n"+
            "1-Registrar Nuevo " + module + "\n"+
            "2-Editar " + module + "\n"+
            "3-Consultar "+ module +"\n"};
    cout<<*options;
}
void optionsMenu(string module) {
    string options[]={
            "________Taller " + module + "________:\n"+
            "[Crear/Editar/Consultar]\n"+
            "0-Sair\n"+
            "1-Cliente\n"+
            "2-Servicio\n"+
            "3-Vehiculo\n"+
            "4-Empleado\n"+
            "5-Taller Administración \n"
    };
    cout<<*options;
}
void programRoutes(string nameTaller) {

    int caso;
    auto n = nameTaller;
    caso = getOption(n, &optionsMenu);
    switch (caso) {
        case 0: {
            cout<<"Sliendo... Graciar por utilizar Zii-Programs"<<endl;
            break;
        }
        case 1:{

            caso = getOption("Cliente", &optionsBasic);
            switch (caso) {
                case 1:{

                }
                case 2:{}
                case 3:{}
                default:{
                    programRoutes(n);
                }

            }
            break;
        }
        case 2:{

            caso = getOption("Servicio", &optionsBasic);
            switch (caso) {
                case 1:{

                }
                case 2:{}
                case 3:{}
                default:{
                    programRoutes(n);
                }

            }

            break;
        }
        case 3:{
            caso = getOption("Vehiculo", &optionsBasic);
            switch (caso) {
                case 1:{

                }
                case 2:{}
                case 3:{}
                default:{
                    programRoutes(n);
                }

            }

            break;
        }
        case 4:{
            caso = getOption("Empleado", &optionsBasic);
            switch (caso) {
                case 1:{

                }
                case 2:{}
                case 3:{}
                default:{
                    programRoutes(n);
                }

            }
            break;
        }
        case 5:{
            cout<<"Bien Venido(a) al Taller Mecánico de "<<nameTaller<<endl;
            caso = getOption("Taller", &optionsBasic);
            switch (caso) {
                case 1:{

                }
                case 2:{}
                case 3:{}
                default:{
                    programRoutes(n);
                }

            }
            break;
        }
        default:{
            cout<<"Tente otra opcion..."<<endl;
            programRoutes(n);
            break;
        }
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
