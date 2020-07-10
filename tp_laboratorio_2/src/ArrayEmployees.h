#define NAME_LEN 50
#define LASTNAME_LEN 20

typedef struct
{
    int id;
    char name [51];
    char lastname[51];
    float salary ;
    int sector;
    int isEmpty;

} eEmployee;


int menu();
int addEmployees(eEmployee* emp,int tam, int indice, int* id);
int imprimir(eEmployee* emp);
int imprimirArray(eEmployee* array,int tam);
int initEmployees(eEmployee* empleado, int tam);
void printEmployeess(eEmployee* empleados, int tam);
int buscarLibre(eEmployee* empleado, int tam);
int findEmployeeById(eEmployee* empleados, int tam, int idAuto );
int modifyEmployee(eEmployee* empleado, int tam);
int removeEmployee(eEmployee* empleados, int tam);
int sortEmployees(eEmployee* empleados, int tam);
void ordenarPorApellido(eEmployee* empleados, int tam );
void ordenarPorSector(eEmployee* empleados, int tam );
void salariosempleado(eEmployee* empleado, int tam);

//float getFloat(char msj[]);
//int getInt(char msj[] );
//char getChar(char msj[]);
//int soloNumero(char str[]);
//int soloLetras(char str[]);
//void getString (char msj[],char input[]);
//int getStringLetras(char msj[],char input[]);
//int getStringNumeros(char mensaje[],char input[]);
//

















