#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

struct Registro{
    char nombre[6];
    char descripcion[30];
};
int main(){

    Registro Agenda,LeerAgenda;

    ofstream file("bd.dat", ios::binary);

    strcpy(Agenda.nombre,"gripe");
    strcpy(Agenda.descripcion,"esunaenfermedad");

    file.write((char*)(&Agenda), sizeof(Registro));
    file.close();

    //LEER
    ifstream leerfile("db.dat",ios::binary);
    leerfile.read((char*)&LeerAgenda, sizeof(Registro));
    cout<<"Nombre: "<<LeerAgenda.nombre<<endl;
    cout<<"Descripcion: "<<LeerAgenda.descripcion<<endl;

    return 0;
}
