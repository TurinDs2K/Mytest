#include "Empleado.h"
using std::cout;
using std::cin;
using std::setfill;
using std::setw;

Empleado::Empleado():Persona()
{
    strcpy(this->Tal,"");
    this-> Dep = "";
    this-> Sal = 0;
}

Empleado::Empleado(char *Id, std::string Nom, std::string Dir, char *Tel, char *Tal, std::string Dep, float Sal):
    Persona(Id,Nom,Dir,Tel)
{
    strcpy(this->Tal,Tal);
    this-> Dep = Dep;
    this-> Sal = Sal;
}

Empleado::~Empleado()
{
    this->Tal = NULL;
    delete Tal;
}

char *Empleado::getTal() const
{
    return Tal;
}

void Empleado::setTal(char *value)
{
    Tal = value;
}

string Empleado::getDep() const
{
    return Dep;
}

void Empleado::setDep(const string &value)
{
    Dep = value;
}

float Empleado::getSal() const
{
    return Sal;
}

void Empleado::setSal(float value)
{
    Sal = value;
}

void Empleado::Leer()
{
    Persona::Leer();

    cout<<"\nIngrese el Numero de Talento: ";
    cin.get(Tal,6);
    cin.ignore();
    cout<<"Ingrese el Departamento: ";
    getline(cin,Dep);
    cout<<"Ingrese el Salario: ";
    cin>>Sal;
    cin.ignore();
}

void Empleado::ImprimirCLI()
{
    Persona::ImprimirCLI();
    cout<<"|"<<setfill(' ')<<setw(7)<<Tal
             <<"|"<<setfill(' ')<<setw(25)<<Dep
             <<"|"<<setfill(' ')<<setw(7)<<Sal<<"|\n";
}

void Empleado::Borde()
{
    Persona::Borde();
    cout<<"+-------+-------------------------+-------+\n";
}
