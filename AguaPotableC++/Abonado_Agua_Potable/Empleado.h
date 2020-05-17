#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <Persona.h>

class Empleado : public Persona
{
private:
    char *Tal = new char[5];
    string Dep;
    float Sal;

public:
    Empleado();
    Empleado(char*, string, string, char*,char*,string,float);
    ~Empleado();

    char *getTal() const;
    void setTal(char *value);
    string getDep() const;
    void setDep(const string &value);
    float getSal() const;
    void setSal(float value);

    void Leer();
    void ImprimirCLI();
    void Borde();
};

#endif // EMPLEADO_H
