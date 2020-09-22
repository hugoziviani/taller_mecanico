#include "main.h"
#include "tallerClass/TallerClass.h"


int TallerClass :: quantityAtendientes = 0;
int TallerClass :: quantityMecanicos = 0;
int TallerClass :: quantityClientes = 0;
int TallerClass :: quantityServicios = 0;


int UniqueId :: nextID = 0;

int main() {
    int autorized, option;

    TallerClass *taller = new TallerClass();

    Mecanico *m = new Mecanico(0, "guile", "oficina", "testador de motor", false);
    Cliente *c = new Cliente(1, "fila duma", "99.32220-33");
    c->anadirVehiculo(new Vehiculo(99,"OIaaaa",22.3,"DDD-00"));
    taller->crearOrdenServicio(m, c, PRESSUPUESTO);
    taller->crearOrdenServicio(m);

    taller->anadirCliente("jose garcia","22-22222.222", "kazinho", 933.4, "EXS-333");
    taller->anadirCliente("juan garcia","22-22222.222", "kazinho", 933.4, "EXS-333");
    taller->anadirCliente("juan felizx","22-22222.222", "kazinho", 933.4, "EXS-333");
    taller->anadirCliente("feliiii garcia","22-22222.222", "kazinho", 933.4, "EXS-333");

    taller->anadirAtendiente("juan garcia", "importados");
    taller->anadirMecanico("joselito junez", "taller de grassa", "mecánico principal");

    taller->adicionarItemServicioEnOrden(4,"cartos", 99.3);
    taller->adicionarItemServicioEnOrden(2,"cartoshahahahaha", 99.5);

    auto r = taller->buscaPersona(CLIENTES, "juan");

    for(auto & it : r){
        cout<<"ID: "<<it.first;
        cout<<" Nombre: "<<it.second<<endl;

    }

//    taller->printListElements(CLIENTES);
    //taller->printListElements(ORDENES_DE_SERVICIO);
    // TODO PARA TESTAR, apagar depois

//    autorized = userAutenticationAndRedirect();
//    if (autorized == -1) return 0;
//    while (autorized != -1) {
//        switch (autorized) {
//            case 1: {
//                option = 0;
//                while (option != -1) {
//                    option = getOption("Adminstración", &optionsAdm);
//                    switch (option) {
//                        case 0: {
//                            cout << "\nCambiando de user" << endl;
//                            option = -1;
//                            break;
//                        }
//                        case 1: {
//                            cout << "Editar Ventas" << endl;
//                            break;
//                        }
//                        case 2: {
//                            cout << "Editar Servicios" << endl;
//                            break;
//                        }
//                        case 3: {
//                            cout << "Añadir Trabajador" << endl;
//
//                            taller->anadirAtendiente("juan garcia", "importados");
//                            taller->anadirMecanico("joselito junez", "taller de grassa", "mecánico principal");
//                            taller->anadirAtendiente("ximenez KK", "calle testes");
//
//                            taller->printListEmpleados(MECANICO);
//                            taller->printListElements(ATEMDIENTE);
//
//                            break;
//                        }
//                        case 9: {
//                            cout << "\nSaliendo..." << endl;
//                            option = -1;
//                            autorized=9;
//                            break;
//                        }
//                        default: {
//                            cout <<"Opção inválida" << endl;
//                        }
//                    }
//                }
//                break;
//            }
//            case 2: {
//                option = 0;
//                while (option != -1) {
//                    option = getOption("Mecánico", &optionsMecanico);
//                    switch (option) {
//                        case 0: {
//                            cout << "\nCambiando de user" << endl;
//                            option = -1;
//                            break;
//                        }
//                        case 1: {
//                            cout << "Visualisar Ordenes de Servicio Liberadas" << endl;
//                            break;
//                        }
//                        case 2: {
//                            cout << "Tomar la orden de servicio" << endl;
//                            break;
//                        }
//                        case 9: {
//                            cout << "\nSaliendo..." << endl;
//                            option = -1;
//                            autorized=9;
//                            break;
//                        }
//                        default: {
//                            cout << "Opção inválida" << endl;
//                        }
//                    }
//                }
//                break;
//            }
//            case 3: {
//                option=0;
//                while (option != -1) {
//                    option = getOption("Atendiente", &optionsAtendiente);
//                    switch (option) {
//                        case 0: {
//                            cout << "\nCambiando de user" << endl;
//                            option = -1;
//                            break;
//                        }
//                        case 1: {
//                            cout << "Crear Orden de Servicio" << endl;
//                            break;
//                        }
//                        case 2: {
//                            cout << "Editar Servicios" << endl;
//                            break;
//                        }
//                        case 3: {
//
//                        }
//                        case 4: {
//                            cout << "Crear nuevo cliente" << endl;
//                            taller->anadirCliente("Ricochete", "22-2.333333","kazin", 0.0, "EQK-9999");
//                            taller->printListElements(CLIENTES);
//
//                        }
//                        case 9: {
//                            cout << "\nSaliendo..." << endl;
//                            option = -1;
//                            autorized=9;
//                            break;
//                        }
//                        default: {
//                            cout << "Opção inválida" << endl;
//                            break;
//                        }
//                    }
//                }
//                break;
//            }
//        }
//        if(autorized==9){
//            return 0;
//        }else
//            autorized = userAutenticationAndRedirect();
//    }

    delete taller;
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
                    tallerObject->printListElements(ATEMDIENTE);
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
int userAutenticationAndRedirect() {
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
            "2-Editar Venta o Servicio\n"
            "3-Añadir Trabajador\n"
            "0-Cambiar de usuario\n"
            "9-Salir de la Aplicación\n"
    };
    cout<<*options;
}
void optionsMecanico(string module) {
    string options[]={
            "________"+module+"________:\n"+
            "1-Visualizar Ordenes de Servicio\n"+
            "2-Tomar Orden de Servicio\n"
            "0-Cambiar de usuario\n"
            "9-Salir de la Aplicación\n"
    };
    cout<<*options;
}
void optionsAtendiente(string module) {
    string options[]={
            "________"+module+"________:\n"+
            "1-Visualizar Ordenes de Servicio\n"+
            "2-Emitir Orden de Servicio\n"+
            "3-Atualizar Ordenes de Servicio\n"
            "0-Cambiar de usuario\n"
            "9-Salir de la Aplicación\n"
    };
    cout<<*options;
}