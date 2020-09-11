#include "main.h"




int Vehiculo :: contador = 0;
int main() {
    bool autorized;
    autorized = menu();

    if(autorized){
        list <Vehiculo> gqlist1;
        Vehiculo v = Vehiculo(01,"kazin", 112.3, "EXX4551");
        Vehiculo a, b;
        a = v;
        b = v;

        cout<<a << b << endl;
        cout<<(a==b)<<endl;
        cin>>b;

        for (int i = 0; i < 10; i++)
        {
            //int id, const string &modelo, float kilometraje, const string &placa;
            Vehiculo v;
            v = Vehiculo(i,"ford", 199.0+i,"exx");
            gqlist1.push_back(v);

        }
    }
    return 0;
}

bool menu(){
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
        return PROGRAM;
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
