#include <QCoreApplication>
#include <fstream>
#include <Abonado.h>
#include <vector>//vector
#include <typeinfo>//typeid
using std::string;
using std::cin;
using std::cout;
using std::setfill;
using std::setw;
using std::ofstream;
using std::ios;

char Menu(){
    char Op;
    cout<<"\t\tBienvenido"
        <<"\nA.-> Registro."
        <<"\nB.-> Guardar."
        <<"\nC.-> Eliminar."
        <<"\nD.-> Salir."
        <<"\nLa opcion elegida es: ";
    cin.get(Op);
    cin.ignore();
    Op = toupper(Op);
    if(Op<'A' || Op>'D'){
        cout<<"La Opcion Ingresada NO Existe!!!"
            <<"\nFavor vuelva a Intentarlo!!!\n\n";
        Op = Menu();
    }
    return Op;
}

void Predefinido(Abonado *A){
    Contador *a = new Contador[6];
    a[0]=Contador("00T01",100,150,50);
    a[1]=Contador("00T02",110,140,30);
    a[2]=Contador("00T03",120,180,60);
    a[3]=Contador("00T04",130,200,70);
    a[4]=Contador("00T05",150,170,20);
    a[5]=Contador("00T06",160,180,10);

    A[0] = Abonado(("0801-1989-00214"), "Maria Jose Flores", "Col. Kenndy",("504-2250-3545"),("SANAA0001"),a,6);
    A[1] = Abonado(("1003-1989-00214"), "Annett Perez", "Colomoncagua Intibuca", ("504-2783-3545"),("SANAA0001"),a,6);
    A[2] = Abonado(("0401-2001-00214"), "Alfredo Caballero", "Barrio Villa Belen", ("504-2662-3545"),("SANAA0001"),a,6);
    A[3] = Abonado(("1001-1989-00214"), "Jayro Hernandez", "Barrio Buenos Aires", ("504-2783-3545"),("SANAA0001"),a,6);
    A[4] = Abonado(("1006-1989-00214"), "Kenia Benitez", "Col. Pinares", ("504-2783-3545"),("SANAA0001"),a,6);
    A[5] = Abonado(("0801-2005-00214"), "Juan Jose Lopez", "Col. Miraflores",("504-2250-1312"),("SANAA0001"),a,6);
}

Abonado* Registro(Abonado *A,int Cant, int NC){
    Abonado *T;
    int CA = Cant-NC;
    /****************************************** 1 ***********************************************/
    T = new Abonado [Cant];

    for(int i=0; i<Cant; i++){
        /****************************************** 2 ***********************************************/
        if(i < CA){
            T[i] = A[i];
        }else{
            /****************************************** 3 ***********************************************/
            T[i].Leer();
        }
    }

    /****************************************** 4 ***********************************************/
    return T;
}

void Imprimir(Abonado *A, int Cant){
    cout<<"+--------+---------------+----------------------------------------+----------------------------------------+--------------+---------+--------+\n"
        <<"|Posicion|   Identidad   |             Nombre Completo            |                  Direccion             |   Telefono   |Codigo Ab|Contador|\n"
        <<"+--------+---------------+----------------------------------------+----------------------------------------+--------------+---------+--------+\n";
    for(int i=0; i<Cant; i++){
        cout<<"|"<<setfill(' ')<<setw(8)<<i;
        A[i].ImprimirCLI();
        A[i].Borde();
    }
}

Abonado* Eliminar(Abonado *A, int Cant){
   int Pos;

   /****************************************** 1 ***********************************************/
    /* char *Busq = new char[15];
    bool encontro = false;
    cout<<"Ingrese el Número de Identidad a Eliminar: ";
    cin.get(Busq,16);
    cin.ignore();

    for(int i=0; i<Cant; i++){
        if(strcmp(Id[i],Busq)){
            cout<<"La Identidad Buscada se encuentra en la Posicion: "<<i<<"\n";
            Pos = i;
            encontro = true;
            break;
        }
        cout<<"Comparacion "<<i+1<<"\n";
    }*/

   /****************************************** 2 ***********************************************/
   Abonado *T = new Abonado[Cant-1];

   Imprimir(A,Cant);

   cout<<"Ingrese la Posicion que desea Eliminar: ";
   cin>>Pos;

   for(int i=0; i<Cant; i++){
       /****************************************** 3a ***********************************************/
       if( i<Pos ){
           T[i] = A[i];
           /****************************************** 3b ***********************************************/
       }else if( i>Pos ){
           T[i-1] = A[i];
       }
   }
   /****************************************** 4 ***********************************************/
return T;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    char OpMenu;
    int Cant = 6, NC;
    /*******************Punteros (Utilizar como Arreglo Dinámico)********************/
    Abonado *A;
    string Arch = "Abonados.xls";

    A = new Abonado [Cant];

    Predefinido(A);

    do{
        OpMenu = Menu();
        switch (OpMenu) {
        case 'A':{
            cout<<"\n\nDigite la Cantidad de Abonados a Registrar: ";
            cin>>NC;
            cin.ignore();//Limpieza de Enter

            Cant += NC;

            A = Registro(A, Cant, NC);

            Imprimir(A,Cant);
            break;}
        case 'B':{
            ofstream Archivo(Arch.data(),ios::out|ios::app);
            for(int i=0; i<Cant; i++){
                Archivo<<A[i].getId()<<"\t"<<A[i].getNom()<<"\t"<<A[i].getDir()<<"\t"<<A[i].getTel()<<"\n";
            }
            Archivo.close();
            cout<<"\nGuardado Exitoso!!!\n";
            break;}
        case 'C':{
            A = Eliminar(A,Cant);

            Cant--;
            cout<<"\nEliminacion Exitosa!!!\n";

            Imprimir(A,Cant);
            break;}
        case 'D':
            cout<<"\n\nGracias por su Visita!!!"
                  "\nLe Esperamos Pronto!!!\n";
            break;
        }
    }while(OpMenu != 'D');

    /*************************Limpieza de Punteros*************************************/
    A = NULL;
    delete A;

    return 0;
}
