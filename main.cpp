#include "main.h"

using namespace std;

int Vehiculo :: contador = 0;
int main() {
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



    return 0;
}
