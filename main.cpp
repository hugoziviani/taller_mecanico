#include "main.h"


int TallerClass :: quantityEmpleados = 0;
int TallerClass :: quantityClientes = 0;
int TallerClass :: quantityServicios = 0;


int main() {
    int autorized, option;
    autorized = userAutenticationAndRedirect();
    while (autorized!=-1){
        switch (autorized) {
            case 0:{
                cout<<"Admin Profile"<<endl;
                option = getOption("Adminstración", &optionsAdm);
                while (option!=-1){
                    switch (option) {
                        case 1:{
                            cout<<"Editar Ventas"<<endl;
                            option = -1;
                            break;
                        }
                        case 2:{
                            cout<<"Editar Servicios"<<endl;
                            option = -1;
                            break;
                        }
                        default:{
                            cout<<"Opção inválida"<<endl;
                            option = getOption("Adminstración", &optionsAdm);
                            break;
                        }
                    }
                }
                autorized=-1;
                break;
            }
            case 1:{
                cout<<"Mecanico Profile"<<endl;
                option = getOption("Mecánico", &optionsMecanico);
                while (option!=-1){
                    switch (option) {
                        case 1:{
                            cout<<"Visualisar Ordenes de Servicio Liberadas"<<endl;
                            option = -1;
                            break;
                        }
                        case 2:{
                            cout<<"Tomar la orden de servicio"<<endl;
                            option = -1;
                            break;
                        }
                        default:{
                            cout<<"Opção inválida"<<endl;
                            option = getOption("Adminstración", &optionsAdm);
                            break;
                        }
                    }
                }
                autorized=-1;
                break;
            }
            case 2:{
                cout<<"Atendiente Profile"<<endl;
                option = getOption("Atendiente", &optionsAtendiente);
                while (option!=-1){
                    switch (option) {
                        case 1:{
                            cout<<"Crear Orden de Servicio"<<endl;
                            option = -1;
                            break;
                        }
                        case 2:{
                            cout<<"Editar Servicios"<<endl;
                            option = -1;
                            break;
                        }
                        default:{
                            cout<<"Opção inválida"<<endl;
                            option = getOption("Atendiente", &optionsAtendiente);
                            break;
                        }
                    }
                }
                autorized=-1;
                break;
            }
            default:{
                cout<<"No fué possible acenderte al sistema"<<endl;
                autorized = userAutenticationAndRedirect();
            }

        }
    }


    return 0;
}

void programRoutes(string nameTaller, TallerClass *tallerObject) {

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
                    programRoutes(n, nullptr);
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
                    programRoutes(n, nullptr);
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
                    programRoutes(n, nullptr);
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
                    programRoutes(n, nullptr);
                }

            }
            break;
        }
        case 5:{
            cout<<"Bien Venido(a) al Taller Mecánico de "<<nameTaller<<endl;
            caso = getOption("Taller", &optionsTaller);

            switch (caso) {
                case 1:{ //
                    tallerObject->printListEmpleados();
                }
                case 2:{

                }
                case 3:{

                }
                default:{
                    programRoutes(n, nullptr);
                }

            }
            break;
        }
        default:{
            cout<<"Tente otra opcion..."<<endl;
            programRoutes(n, nullptr);
            break;
        }
    }
}
int userAutenticationAndRedirect(){
    string inputUsername, inputPass;
    cout<<"Hola, dime tu user:"<<endl;
    cin >> inputUsername;
    cout<<"Dime tu contraseña "<<inputUsername<<endl;
    cin >> inputPass;

    list<tuple<int, string, string>> usersAndPass = readFile("/Users/hz/CLionProjects/taller_mecanico/input/user.txt");
    int autorized;
    autorized = loginAndReturnUserType(usersAndPass, inputUsername, inputPass);
    if (autorized !=-99){
        cout<<"Bien Venido al Taller Mecánico"<<endl;
        return autorized;
    }else{
        cout<<"Vete a la mierda pinche Hacker!"<<endl;
        return -99;
    }

}
list<tuple<int, string, string>> readFile(const char *path){
    list<tuple<int, string, string>> usersAndPass;
    FILE *arq;
    char buffer[BUFSIZ] ;
    char delimiters[]=":\n";
    arq = fopen(path, "r") ;
    int count_lines = 0;

    while(fgets(buffer, BUFSIZ, arq) != NULL) {
        int type = atoi(strtok(buffer, delimiters));
        string user = (string) strtok(NULL, delimiters);
        string pass = (string) strtok(NULL, delimiters);
        tuple<int, string, string> tuple = make_tuple(type, user, pass);
        usersAndPass.emplace_back(tuple);
    }
    fclose(arq);
    return  usersAndPass;
}
int loginAndReturnUserType(list<tuple<int, string, string>> usersAndPass, string user, string pass){
    if (usersAndPass.empty()) return false;
    int ty;
    string us, ps;
    for (auto& x: usersAndPass) {
        ty = std::get<0>(x);
        us = std::get<1>(x);
        ps = std::get<2>(x);
        int u, p;
        u = user.compare(us); //user
        p = pass.compare(ps); //pass
        if (u == 0 and p == 0) {
            return ty;
        }
    }
    return -99;
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
    return input;
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
void optionsTaller(string module) {
    string options[]={
            "________"+module+"________:\n"+
            "1-Consultar todos los empleados\n"+
            "2-Consultar todos los clientes\n"+
            "3-Consultar todos los servicios\n"};
    cout<<*options;
}

void optionsAdm(string module) {
    string options[]={
            "________"+module+"________:\n"+
            "1-Consultar Ventas y Servicios\n"+
            "2-Editar Venta o Servicio\n"};
    cout<<*options;
}
void optionsMecanico(string module) {
    string options[]={
            "________"+module+"________:\n"+
            "1-Visualizar Ordenes de Servicio\n"+
            "2-Tomar Orden de Servicio\n"};
    cout<<*options;
}
void optionsAtendiente(string module) {
    string options[]={
            "________"+module+"________:\n"+
            "1-Visualizar Ordenes de Servicio\n"+
            "2-Emitir Orden de Servicio\n"+
            "3-Atualizar Ordenes de Servicio\n"};
    cout<<*options;
}