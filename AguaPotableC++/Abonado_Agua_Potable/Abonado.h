#ifndef ABONADO_H
#define ABONADO_H
#include <Persona.h>
#include <contador.h>

//Anonymous. (2012, septiembre 3). Diferencias entre C++ y Java. Recuperado 13 de mayo de 2020, de Historia De Java website: http://jahistory.blogspot.com/

class Abonado : public Persona
{
private:
    char *CodA = new char[9];
    Contador *Cont; //es un arreglo de contadores (Composición)

    int Cant;
    void setCant(int value);

public:
    Abonado();
    Abonado(char*, string, string, char*, char*,Contador*,int);
    ~Abonado();

    char *getCodA() const;
    void setCodA(char *value);
    Contador *getCont() const;
    void setCont(Contador *Cont, int Cant);
    int getCant() const;

    void Leer();
    void ImprimirCLI();
    void Borde();
};

#endif // ABONADO_H
