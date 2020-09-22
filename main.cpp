#include "main.h"
#include "tallerClass/TallerClass.h"


int TallerClass::quantityAtendientes = 0;
int TallerClass::quantityMecanicos = 0;
int TallerClass::quantityClientes = 0;
int TallerClass::quantityServicios = 0;


int UniqueId::nextID = 0;

int main() {
    setlocale(LC_ALL, nullptr);
    int autorized, option;

    TallerClass *taller = new TallerClass();

/*
 *     Mecanico *m = new Mecanico(0, "guile", "oficina", "testador de motor", false);
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
 * */

    taller->printListElements(CLIENTES);
    taller->printListElements(ORDENES_DE_SERVICIO);
    //TODO PARA TESTAR, apagar depois

    //autorized = userAutenticationAndRedirect();
    autorized = 2;
    if (autorized == -1) return 0;
    while (autorized != -1) {
        switch (autorized) {
            case 1: {
                option = 0;
                while (option != -2) {
                    option = getOption("Adminstración", &optionsAdm);
                    switch (option) {
                        case 0: {
                            cout << "\nCambiando de user" << endl;
                            option = -1;
                            break;
                        }
                        case 1: {
                            option = getOption("Añadir Trabajador", &menuAnadirTrabajador);
                            while (option != -2) {
                                switch (option) {
                                    case 1:{
                                        string nombre, setor, funcion;
                                        cout << "Digita el nombre del Mecanico:" << endl;
                                        cin >> nombre;
                                        cout << "Digita el setor:" << endl;
                                        cin.clear();
                                        cin >> setor;
                                        cout << "Digita la funciona mecánica:" << endl;
                                        cin.clear();
                                        cin >> funcion;
                                        taller->anadirMecanico(nombre, setor, funcion);
                                        cout << "Mecanico adicionado con sucesso..." << endl;
                                        option=-2;
                                        break;

                                    }
                                    case 2:{
                                        string setor, nombre;
                                        cout << "Digita el nombre del Vendedor:" << endl;
                                        cin >> nombre;
                                        cout << "Digita el setor:" << endl;
                                        cin.clear();
                                        cin >> setor;
                                        taller->anadirAtendiente(nombre, setor);
                                        cout << "Atendiente adicionado con sucesso..." << endl;
                                        option=-2;
                                        break;

                                    }
                                    default:{
                                        cout << "Opcion invalida" << endl;
                                        option = getOption("Añadir Trabajador", &menuAnadirTrabajador);
                                    }
                                }
                            }
                            option=-2;
                            break;
                        }
                        case 2: {
                            option = getOption("Editar Trabajador", &menuEditarTrabajador);
                            while (option != -3) {
                                switch (option) {
                                    case 1:{
                                        string nombre, setor, funcion;
                                        int id;
                                        taller->printListElements(EMPLEADOS);
                                        cout << "Digita el ID de quien desea editar:" << endl;
                                        cin.clear();
                                        cin>>id;
                                        auto r = dynamic_cast<Mecanico*>(taller->buscaEmpleado(id));
                                        if(r != nullptr){
                                            try {
                                                cout <<"El nombre antiguo és: "<<r->getNombre()<<endl;
                                                cout << "Digita el NUEVO nombre del Mecanico:" << endl;
                                                cin.clear();
                                                cin >> nombre;
                                                r->setNombre(nombre);
                                                cout <<"El antiguo setor és: "<<r->getSetor()<<endl;
                                                cout << "Digita el NUEVO setor:" << endl;
                                                cin.clear();
                                                cin >> setor;
                                                r->setSetor(setor);
                                                cout <<"El antiguo setor és: "<<r->getFuncion()<<endl;
                                                cout << "Digita la NUEVA función:" << endl;
                                                cin.clear();
                                                cin >> funcion;
                                                r->setFuncion(funcion);
                                            } catch (runtime_error &e) {
                                                cerr<<e.what();
                                            }
                                        }else{
                                            cout<<"Este ID no és de un mecánico!!"<<endl;
                                        }
                                        option=-3;
                                        break;

                                    }
                                    case 2:{
                                        taller->printListElements(EMPLEADOS);
                                        string setor, nombre;
                                        int id, ventas;
                                        cout << "Digita el ID de quien desea editar:" << endl;
                                        cin.clear();
                                        cin>>id;
                                        auto r = dynamic_cast<Atendiente*>(taller->buscaEmpleado(id));
                                        if(r != nullptr){
                                            cout <<"El nombre antiguo és: "<<r->getNombre()<<endl;
                                            cout << "Digita el NUEVO nombre del Vendedor/Atendiente:" << endl;
                                            cin.clear();
                                            cin >> nombre;
                                            r->setNombre(nombre);
                                            cout << "El antíguo setor:" <<r->getSetor()<<endl;
                                            cout << "Digita el NUEVO setor:" << endl;
                                            cin.clear();
                                            cin >> setor;
                                            r->setSetor(setor);
                                            cout << "Hasta ahora sus ventas son:"<<r->getVentasHechas()<< endl;
                                            cout << "Cuantas ventas hizo?:" << endl;
                                            cin>>ventas;
                                            r->setVentasHechas(ventas);

                                        }else{
                                            cout<<"Este ID no és de un Vendedor/Atendiente!!"<<endl;
                                        }
                                        option=-3;
                                        break;

                                    } //Editar Vendedor
                                    default:{
                                        cout << "Opcion invalida" << endl;
                                        option = getOption("Añadir Trabajador", &menuEditarTrabajador);
                                    }
                                }
                            }
                        }
                        case 9: {
                            cout << "\nSaliendo..." << endl;
                            option = -1;
                            autorized = 9;
                            break;
                        }
                        default: {
                            option = getOption("Adminstración", &optionsAdm);
                        }
                    }
                }
                break;
            } //Administración
            case 2: {
                option = 0;
                while (option != -5) {
                    option = getOption("Mecanico", &optionsVendedorYMecanico);
                    switch (option) {
                        case 0: {
                            cout << "\nCambiando de user" << endl;
                            option = -5;
                            break;
                        }
                        case 1: {
                            cout << "Visualisar Ordenes de Servicio Liberadas" << endl;
                            break;
                        }
                        case 2: {
                            cout << "Tomar la orden de servicio" << endl;
                            break;
                        }
                        case 9: {
                            cout << "\nSaliendo..." << endl;
                            option = -1;
                            autorized = 9;
                            break;
                        }
                        default: {
                            cout << "Opção inválida" << endl;
                        }
                    }
                }
                break;
            } //Mecanico
            case 3: {
                option = 0;
                while (option != -1) {
                    option = getOption("Atendiente", &optionsAtendiente);
                    switch (option) {
                        case 0: {
                            cout << "\nCambiando de user" << endl;
                            option = -1;
                            break;
                        }
                        case 1: {
                            cout << "Crear Orden de Servicio" << endl;
                            break;
                        }
                        case 2: {
                            cout << "Editar Servicios" << endl;
                            break;
                        }
                        case 3: {

                        }
                        case 4: {
                            cout << "Crear nuevo cliente" << endl;
                            taller->anadirCliente("Ricochete", "22-2.333333", "kazin", 0.0, "EQK-9999");
                            taller->printListElements(CLIENTES);

                        }
                        case 9: {
                            cout << "\nSaliendo..." << endl;
                            option = -1;
                            autorized = 9;
                            break;
                        }
                        default: {
                            cout << "Opção inválida" << endl;
                            break;
                        }
                    }
                }
                break;
            } //Atendiente
        }
        if (autorized == 9) {
            return 0;
        } else
            autorized = userAutenticationAndRedirect();
    }

    delete taller;
    return 0;
}

void programRoutes(string nameTaller, TallerClass *tallerObject) {

    int caso;
    auto n = nameTaller;
    caso = getOption(n, &optionsMenu);
    switch (caso) {
        case 0: {
            cout << "Sliendo... Graciar por utilizar Zii-Programs" << endl;
            break;
        }
        case 1: {

            caso = getOption("Cliente", &optionsBasic);
            switch (caso) {
                case 1: {

                }
                case 2: {
                }
                case 3: {
                }
                default: {
                    programRoutes(n, nullptr);
                }

            }
            break;
        }
        case 2: {

            caso = getOption("Servicio", &optionsBasic);
            switch (caso) {
                case 1: {

                }
                case 2: {
                }
                case 3: {
                }
                default: {
                    programRoutes(n, nullptr);
                }

            }

            break;
        }
        case 3: {
            caso = getOption("Vehiculo", &optionsBasic);
            switch (caso) {
                case 1: {

                }
                case 2: {
                }
                case 3: {
                }
                default: {
                    programRoutes(n, nullptr);
                }

            }

            break;
        }
        case 4: {
            caso = getOption("Empleado", &optionsBasic);
            switch (caso) {
                case 1: {

                }
                case 2: {
                }
                case 3: {
                }
                default: {
                    programRoutes(n, nullptr);
                }

            }
            break;
        }
        case 5: {
            cout << "Bien Venido(a) al Taller Mecánico de " << nameTaller << endl;
            caso = getOption("Taller", &optionsTaller);

            switch (caso) {
                case 1: { //
                    tallerObject->printListElements(ATEMDIENTE);
                }
                case 2: {

                }
                case 3: {

                }
                default: {
                    programRoutes(n, nullptr);
                }

            }
            break;
        }
        default: {
            cout << "Tente otra opcion..." << endl;
            programRoutes(n, nullptr);
            break;
        }
    }
}

int userAutenticationAndRedirect() {
    string inputUsername, inputPass;
    cout << "Hola, dime tu user:" << endl;
    cin >> inputUsername;
    cout << "Dime tu contraseña " << inputUsername << endl;
    cin >> inputPass;

    list<tuple<int, string, string>> usersAndPass = readFile("/Users/hz/CLionProjects/taller_mecanico/input/user.txt");
    int autorized;
    autorized = loginAndReturnUserType(usersAndPass, inputUsername, inputPass);
    if (autorized != -99) {
        cout << "Bien Venido al Taller Mecánico" << endl;
        return autorized;
    } else {
        cout << "Vete a la mierda pinche Hacker!" << endl;
        return -99;
    }

}

list<tuple<int, string, string>> readFile(const char *path) {
    list<tuple<int, string, string>> usersAndPass;
    FILE *arq;
    char buffer[BUFSIZ];
    char delimiters[] = ":\n";
    arq = fopen(path, "r");

    while (fgets(buffer, BUFSIZ, arq) != NULL) {
        int type = atoi(strtok(buffer, delimiters));
        string user = (string) strtok(NULL, delimiters);
        string pass = (string) strtok(NULL, delimiters);
        tuple<int, string, string> tuple = make_tuple(type, user, pass);
        usersAndPass.emplace_back(tuple);
    }
    fclose(arq);
    return usersAndPass;
}

int loginAndReturnUserType(list<tuple<int, string, string>> usersAndPass, string user, string pass) {
    if (usersAndPass.empty()) return false;
    int ty;
    string us, ps;
    for (auto &x: usersAndPass) {
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
    if (func == nullptr)return -1;
    func(module);
    int input;
    cin >> input;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        func(module);
        cin >> input;
    }
    return input;
}

void optionsBasic(string module) {
    string options[] = {
            "________" + module + "________:\n" +
            "1-Registrar Nuevo " + module + "\n" +
            "2-Editar " + module + "\n" +
            "3-Consultar " + module + "\n"};
    cout << *options;
}

void optionsMenu(string module) {
    string options[] = {
            "________Taller " + module + "________:\n" +
            "[Crear/Editar/Consultar]\n" +
            "0-Sair\n" +
            "1-Cliente\n" +
            "2-Servicio\n" +
            "3-Vehiculo\n" +
            "4-Empleado\n" +
            "5-Taller Administración \n"
    };
    cout << *options;
}

void optionsTaller(string module) {
    string options[] = {
            "________" + module + "________:\n" +
            "1-Consultar todos los empleados\n" +
            "2-Consultar todos los clientes\n" +
            "3-Consultar todos los servicios\n"};
    cout << *options;
}


//Admin
void optionsAdm(string module) {
    string options[] = {
            "________" + module + "________:\n" +
            "1-Añadir Trabajador\n"
            "2-Editar Trabajador\n"
            "0-Cambiar de usuario\n"
            "9-Salir de la Aplicación\n"
    };
    cout << *options;
}

void menuAnadirTrabajador(string module) {
    string options[] = {
            "________" + module + "________:\n" +
            "1-Añadir Mecánico\n" +
            "2-Añadir Vendedor\n" +
            "9-Salir\n"
    };
    cout << *options;
}
void menuEditarTrabajador(string module) {
    string options[] = {
            "________" + module + "________:\n" +
            "1-Editar Mecanico\n" +
            "3-Editar Vendedor\n" +
            "9-Salir\n"
    };
    cout << *options;
}

void requiereId(string module) {
    string options[] = {
            "________" + module + "________:\n" +
            "1-Buscar por ID de quien desea editar\n" +
            "2-Consultar ID por nombre\n" +
            "9-Salir\n"
    };
    cout << *options;
}

void menuCrearTrabajador(string module) {
    string options[] = {
            "________" + module + "________:\n" +
            "1-Crear Mecánicos\n" +
            "2-Crear Vendedores\n"
            "9-Salir\n"
    };
    cout << *options;
}

//Mecanico
void optionsVendedorYMecanico(string module) {
    string options[] = {
            "________" + module + "________:\n" +
            "1-Cadastrar cliente e veículo\n" +
            "2-Gerar ordem de serviço\n"
            "3-Visualizar y modificar ordenes de servicio\n"
            "4-Tomar orden de servicio pelo ID\n"
            "0-Cambiar de usuario\n"
            "9-Salir de la Aplicación\n"
    };
    cout << *options;
}

//Atendiente
void optionsAtendiente(string module) {
    string options[] = {
            "________" + module + "________:\n" +
            "1-Visualizar Ordenes de Servicio\n" +
            "2-Emitir Orden de Servicio\n" +
            "3-Atualizar Ordenes de Servicio\n"
            "0-Cambiar de usuario\n"
            "9-Salir de la Aplicación\n"
    };
    cout << *options;
}