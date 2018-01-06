#include <iostream>
#include <fstream>

using namespace std;


int main(){
    ofstream file("bd.dat", ios::binary | ios::out);

    char nombre[15] = "Gripe";
    cout << file.write(nombre, sizeof(nombre)) << "\n";
    char buffer1[30] = "SIDA";
    cout<< file.write(buffer1,sizeof(buffer1))<<"\n";
    file.close();

    return 0;
}
