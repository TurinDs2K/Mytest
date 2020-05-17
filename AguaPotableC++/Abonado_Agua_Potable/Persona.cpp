#include "Persona.h"
using std::string;
using std::cout;
using std::cin;
using std::setfill;
using std::setw;

/*Persona::Persona(QWidget *parent) : QMainWindow(parent)
{

}*/

Persona::Persona()
{
    strcpy(this->Id,"");
    this->Nom = "";
    this->Dir = "";
    strcpy(this->Tel,"");
}

Persona::Persona(char *Id, string Nom, string Dir, char * Tel)
{
    strcpy(this->Id,Id);
    this->Nom = Nom;
    this->Dir = Dir;
    strcpy(this->Tel,Tel);
}

Persona::~Persona()
{
    this->Id = NULL;
    this->Tel = NULL;
    delete this->Id;
    delete this->Tel;
}

char *Persona::getId() const
{
    return Id;
}

void Persona::setId(char *value)
{
    Id = value;
}

string Persona::getNom() const
{
    return Nom;
}

void Persona::setNom(const string &value)
{
    Nom = value;
}

string Persona::getDir() const
{
    return Dir;
}

void Persona::setDir(const string &value)
{
    Dir = value;
}

char *Persona::getTel() const
{
    return Tel;
}

void Persona::setTel(char *value)
{
    Tel = value;
}

void Persona::Leer()
{
    cout<<"\nIngrese el Numero de Identidad: ";
    cin.get(Id,16);
    cin.ignore();
    cout<<"Ingrese el Nombre Completo: ";
    getline(cin,Nom);
    cout<<"Ingrese la Direccion: ";
    getline(cin,Dir);
    cout<<"Ingrese el Numero de Telefono: ";
    cin.get(Tel,15);
    cin.ignore();
}

void Persona::ImprimirCLI()
{
    cout<<"|"<<setfill(' ')<<setw(15)<<Id
        <<"|"<<setfill(' ')<<setw(40)<<Nom
        <<"|"<<setfill(' ')<<setw(40)<<Dir
        <<"|"<<setfill(' ')<<setw(14)<<Tel;
}

void Persona::Borde()
{
    cout<<"+--------+---------------+----------------------------------------+----------------------------------------+--------------+";
}
