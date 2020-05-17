#include "Abonado.h"


Abonado::Abonado():Persona(){
    strcpy(this->CodA,"");
    this->Cont = new Contador[0];
    this->Cant = 0;
}

Abonado::Abonado(char *Id, std::string Nom, std::string Dir, char *Tel, char *CodA, Contador *Cont, int Cant):Persona(Id,Nom,Dir,Tel){
    strcpy(this->CodA,CodA);
    this->Cont = Cont;
    this->Cant = Cant;
}

Abonado::~Abonado()
{
    this->CodA = NULL;
    this->Cont = NULL;
    delete CodA;
    delete Cont;
}

char *Abonado::getCodA() const
{
    return CodA;
}

void Abonado::setCodA(char *value)
{
    CodA = value;
}

Contador *Abonado::getCont() const
{
    return Cont;
}

void Abonado::setCont(Contador *Cont, int Cant)
{
    int CT = this->Cant + Cant;
    /****************************************** 1 ***********************************************/
    Contador *T = new Contador [CT];

    for(int i=0,j=0; i<CT; i++){
        /****************************************** 2 ***********************************************/
        if(i < this->Cant){
            T[i] = this->Cont[i];
        }else{
            /****************************************** 3 ***********************************************/
            T[i] = Cont[j];
            j++;
        }
    }

    this->Cant = CT;
    this->Cont = T;
}

int Abonado::getCant() const
{
    return Cant;
}

void Abonado::setCant(int value)
{
    Cant = value;
}

void Abonado::Leer()
{
    Persona::Leer();
    cout<<"\nIngrese el Codigo del Abonado: ";
    cin.get(CodA,10);
    cin.ignore();
    cout<<"Ingrese la Cantidad de Contadores: ";
    cin>>Cant;
    cin.ignore();
    this->Cont = new Contador[Cant];
    for(int i=0; i<Cant; i++){
        Cont[i].Leer();
    }
}

void Abonado::ImprimirCLI()
{
    Persona::ImprimirCLI();
    cout<<"|"<<setfill(' ')<<setw(9)<<CodA
             <<"|"<<setfill(' ')<<setw(8)<<Cant<<"|\n";
    cout<<"+---------+----------+----------+---------------+\n"
        <<"|Id Contad|L_Anterior| L_Actual |    Consumo    |\n"
        <<"+---------+----------+----------+---------------+\n";
    for(int i=0; i<Cant; i++){
        Cont[i].ImprimirCLI();
    }
}

void Abonado::Borde()
{
    Persona::Borde();
    cout<<"---------+--------+\n";
}
