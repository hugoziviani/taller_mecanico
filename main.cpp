#include "main.h"

int TallerClass::quantityAtendientes = 0;
int TallerClass::quantityMecanicos = 0;
int TallerClass::quantityClientes = 0;
int TallerClass::quantityServicios = 0;
int UniqueId::nextID = 0;

int main() {
    setlocale(LC_ALL, nullptr);
    int autorized, option;

    TallerClass *taller = new TallerClass();

    createObjectsToTest(taller);

    autorized = userAutenticationAndRedirect(FILE_PATH_AUTENTICATION);
    if (autorized == -1) return 0;
    while (autorized != -1) {
        switch (autorized) {
            case 1: {
                option = 0;
                while (option != -10) {
                    option = getOption("Adminstración", &optionsAdm);
                    switch (option) {
                        case 0: {
                            cout << "\nCambiando de user" << endl;
                            option = -10;
                            break;
                        }
                        case 1: {
                            option = getOption("Añadir Trabajador", &menuAnadirTrabajador);
                            while (option != -22) {
                                option = getOption("Añadir Trabajador", &menuAnadirTrabajador);
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
                                    case 9:{
                                        option=-22;
                                        autorized=-1;
                                        cout << "Saliendo..." << endl;
                                    }
                                    default:{
                                        cout << "Opcion invalida" << endl;
                                    }
                                }
                            }
                            option=-1;
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
                            option = -10;
                            autorized = -1;
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
                while (option != -2) {
                    option = getOption("Mecanico", &optionsMecanico);
                    switch (option) {
                        case 0: {
                            cout << "\nCambiando de user" << endl;
                            option = -2;
                            break;
                        }
                        case 1: {
                            string nombre, telefono, modeloVehiculo, placa;
                            float kilometraje;
                            cout << "Cadastrar cliente e veículo" << endl;
                            cout << "Nombre del Cliente:" << endl;
                            cin.clear();
                            cin>>nombre;
                            cout << "Telefono del Cliente:" << endl;
                            cin.clear();
                            cin>>telefono;
                            cout << "Modelo del Vehiculo:" << endl;
                            cin.clear();
                            cin>>modeloVehiculo;
                            cout << "Placa del Vehiculo:" << endl;
                            cin.clear();
                            cin>>placa;
                            cout << "Kilometraje del Vehiculo:" << endl;
                            cin.clear();
                            cin>>kilometraje;
                            taller->anadirCliente(nombre, telefono, modeloVehiculo, kilometraje, placa);
                            taller->printListElements(CLIENTES);
                            break;
                        }
                        case 2: {
                            if(TallerClass::getQuantityClientes()>0 and TallerClass::getQuantityEmpleados(MECANICO)>0 and TallerClass::getQuantityEmpleados(ATEMDIENTE)>0){
                                int id;
                                taller->printListElements(EMPLEADOS);
                                cout << "Crear ordem de servicio" << endl;
                                cout << "Cual és el ID del responsable por la Orden?" << endl;
                                cin.clear();
                                cin>>id;
                                auto empleado = taller->buscaEmpleado(id);
                                if(empleado != nullptr){
                                    taller->printListElements(CLIENTES);
                                    cout << "Cual és el ID del Cliente?" << endl;
                                    cin.clear();
                                    cin>>id;
                                    auto cliente = taller->buscaCliente(id);
                                    if(cliente != nullptr){
                                        taller->crearOrdenServicio(empleado, cliente, PRESSUPUESTO);
                                        cout<<"Orden de servicio creada con sucesso..."<<endl;
                                        taller->printListElements(ORDENES_DE_SERVICIO);
                                    }else{
                                        cout<<"Cliente no existe..."<<endl;
                                        break;
                                    }
                                    break;
                                }else{
                                    cout<<"Empleado no existe..."<<endl;
                                    break;
                                }


                            }else{
                                cout<<"Favor Cadastrar al menos un Cliente, un Mecanico O vendedor antes de crear la Orden"<<endl;
                                break;
                            }
                        }
                        case 3: {
                            if(TallerClass::getQuantityServicios()>0) {
                                int id, op;
                                cout << "Visualizar/Modificar Ordenes de Servicio" << endl;
                                taller->printListElements(ORDENES_DE_SERVICIO);
                                cout << "Cual és el ID de la orden que desea modificar?" << endl;
                                cin.clear();
                                cin >> id;
                                auto orden = taller->buscaOrdenDeServicio(id);
                                if (orden == nullptr) {
                                    cout << "No fue possible localizar orden" << endl;
                                    break;
                                } else {
                                    cout << "Orden del " << (orden->getCliente()->getNombre()) << " con el valor de "
                                         << orden->calculatePrecioTotal() << " fué aceptada? (1)Sí (2)No" << endl;
                                    cin.clear();
                                    cin >> op;
                                    if (op == 1) {
                                        orden->setStatus(AUTORIZADA);
                                        cout << *orden << endl;
                                    }
                                    break;
                                }
                            }else{
                                cout<<"No existen ordenes de servicio cadastradas"<<endl;
                                break;
                            }
                        }
                        case 4: {
                            if(TallerClass::getQuantityServicios()>0){
                                int id;
                                taller->printListElements(EMPLEADOS);
                                cout << "Tomar ordene de servicio" << endl;
                                cout << "Cual és tu ID?" << endl;
                                cin.clear();
                                cin>>id;
                                auto empleado = taller->buscaEmpleado(id);
                                if(empleado!= nullptr){
                                    taller->printListElements(ORDENES_DE_SERVICIO);
                                    cout << "Cual és el ID del  la orden que quieres tomar?" << endl;
                                    cin.clear();
                                    cin>>id;
                                    auto orden = taller->buscaOrdenDeServicio(id);
                                    if(orden != nullptr and empleado != nullptr){
                                        cout<<"Orden de servicio tomada con sucesso..."<<endl;
                                        orden->setStatus(EN_EJECUCION);
                                        taller->printListElements(ORDENES_DE_SERVICIO);
                                    }else{
                                        cout<<"No fue possíble tomar la orden"<<endl;
                                    }
                                    break;

                                }else{
                                    cout << "Empleado no existe..." << endl;
                                    break;
                                }



                            }else{
                                cout<<"Todavia, no existen ordenes cadastradas."<<endl;
                                break;
                            }
                        }
                        case 9: {
                            cout << "\nSaliendo..." << endl;
                            option = -1;
                            autorized = -1;
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
                while (option != -3) {
                    option = getOption("Atendiente", &optionsAtendiente);
                    switch (option) {
                        case 0: {
                            cout << "\nCambiando de user" << endl;
                            option = -3;
                            break;
                        }
                        case 1: {
                            cout << "Visualizar Ordenes de Servicio" << endl;
                            taller->printListElements(ORDENES_DE_SERVICIO);
                            break;
                        }
                        case 2: {
                            if(TallerClass::getQuantityClientes()>0 and TallerClass::getQuantityEmpleados(MECANICO)>0 and TallerClass::getQuantityEmpleados(ATEMDIENTE)>0){
                                int id;
                                taller->printListElements(EMPLEADOS);
                                cout << "Crear ordem de servicio" << endl;
                                cout << "Cual és el ID del responsable por la Orden?" << endl;
                                cin.clear();
                                cin>>id;
                                auto empleado = taller->buscaEmpleado(id);
                                taller->printListElements(CLIENTES);
                                cout << "Cual és el ID del Cliente?" << endl;
                                cin.clear();
                                cin>>id;
                                auto cliente = taller->buscaCliente(id);
                                taller->crearOrdenServicio(empleado, cliente, PRESSUPUESTO);
                                cout<<"Orden de servicio creada con sucesso..."<<endl;
                                taller->printListElements(ORDENES_DE_SERVICIO);
                                break;

                            }else{
                                cout<<"Favor Cadastrar al menos un Cliente, un Mecanico O vendedor antes de crear la Orden"<<endl;
                                break;
                            }
                            break;
                        }
                        case 3: {
                            cout<<"3-Atualizar Ordenes de Servicio"<<endl;
                            if(TallerClass::getQuantityServicios()>0) {
                                int id, op;
                                cout << "Modificar Ordenes de Servicio" << endl;
                                taller->printListElements(ORDENES_DE_SERVICIO);
                                cout << "Cual és el ID de la orden que desea modificar?" << endl;
                                cin.clear();
                                cin >> id;
                                auto orden = taller->buscaOrdenDeServicio(id);
                                if (orden == nullptr) {
                                    cout << "No fue possible localizar orden" << endl;
                                    break;
                                } else {
                                    cout << "Orden del " << *(orden->getCliente()) << " con el valor de "
                                         << orden->calculatePrecioTotal() << " fué aceptada? (1)Sí (2)No" << endl;
                                    cin.clear();
                                    cin >> op;
                                    if (op == 1) {
                                        orden->setStatus(AUTORIZADA);
                                        cout << *orden << endl;
                                    }
                                    break;
                                }
                            }

                        }
                        case 4: {
                            string nombre, telefono, modeloVehiculo, placa;
                            float kilometraje;
                            cout << "Cadastrar cliente e veículo" << endl;
                            cout << "Nombre del Cliente:" << endl;
                            cin.clear();
                            cin>>nombre;
                            cout << "Telefono del Cliente:" << endl;
                            cin.clear();
                            cin>>telefono;
                            cout << "Modelo del Vehiculo:" << endl;
                            cin.clear();
                            cin>>modeloVehiculo;
                            cout << "Placa del Vehiculo:" << endl;
                            cin.clear();
                            cin>>placa;
                            cout << "Kilometraje del Vehiculo:" << endl;
                            cin.clear();
                            cin>>kilometraje;
                            taller->anadirCliente(nombre, telefono, modeloVehiculo, kilometraje, placa);
                            taller->printListElements(CLIENTES);
                            break;
                        }
                        case 9: {
                            cout << "\nSaliendo..." << endl;
                            option = -3;
                            autorized = -1;
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
        autorized = userAutenticationAndRedirect(FILE_PATH_AUTENTICATION);
    }
    delete taller;
    return 0;
}

void programRoutes(string nameTaller, TallerClass *tallerObject) {
//TODO retirar do MAIN e realizar aqui as rotas
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
int userAutenticationAndRedirect(const char *path) {
    string inputUsername, inputPass;
    cout << "Hola, dime tu user:" << endl;
    cin >> inputUsername;
    cout << "Dime tu contraseña " << inputUsername << endl;
    cin >> inputPass;

    list<tuple<int, string, string>> usersAndPass = readFile(path);
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

//Mecanico
void optionsMecanico(string module) {
    string options[] = {
            "________" + module + "________:\n" +
            "1-Cadastrar cliente y vehiculo\n" +
            "2-Crear orden de servicio\n"
            "3-Visualizar y modificar ordenes de servicio\n"
            "4-Tomar orden de servicio por ID\n"
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
            "4-Crear Nuevo Cliente\n"
            "0-Cambiar de usuario\n"
            "9-Salir de la Aplicación\n"
    };
    cout << *options;
}

void createObjectsToTest(TallerClass *taller){
    taller->anadirCliente("jose1 garcia","22-22222.222", "kazinho1", 933.4, "EXS-339993");
    taller->anadirCliente("juan2 garcia","22-22222.222", "kazinho2", 933.4, "EXS-331113");
    taller->anadirCliente("juan3 felizx","22-22222.222", "kazinho3", 933.4, "EXS-33353");
    taller->anadirCliente("feliiii4 garcia","22-22222.222", "kazinho4", 933.4, "EXS-366633");
    taller->anadirAtendiente("juan garcia", "importados");
    taller->anadirMecanico("joselito junez", "taller de grassa", "mecánico principal");
}