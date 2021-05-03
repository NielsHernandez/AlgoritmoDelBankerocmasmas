#include <iostream>
#include <fstream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//funcion para realizar restas segun sea necesario
int resta(int a, int b)
{
    int c = a - b;

    return c;
}
//funcion para realizar sumas segun sea necesario
int suma(int a, int b)
{
	int c = a - b;
	
	return c;
}

int main(int argc, char** argv)
{

    //Estado Inicial del algoritmo del bankero
    cout << "_________________________________________________________________________________________________________" << endl;
    cout << "                                       PROYECTO SISTEMAS OPERATIVOS                                   " << endl;
    cout << "                                          ALGORITMO DEL BANKERO $$                                    " << endl;
    //guadar salida en un archivo txt
    ofstream myfile("salida.txt");
    if (myfile.is_open()) {
        //declarar variables auxiliares para los procesos y recurso
        int n = 0; //procesos filas
        int m = 0; //recursos columnas
        //leer desde la consola para asignarle un valor inicial a las variables n, m
        cout << "ingre el Numero de Procesos P:";
        cin >> n;
        cout << "ingre el Numero de Recursos R:";
        cin >> m;
        //imprimir el tamanio seleccionado
        cout << "Tamanio de la matriz a procesar: " << n << " X " << m << endl;
        //declarar las matrices del tamanio deaseado a procesar
        //matriz
        //Matriz A
        int matrizA[n][m];
        //
        //Matriz C
        int matrizC[n][m];
        //Matriz C-A
        int matrizCmenosA[n][m];
        //Declarar Vectores para almacenar el total de los recurso y los recursos disponibles
        //Total Recursos
        int totalRecursos[m];
        //Recursos Disponibles
        int disponibles[m];
        //Crear matrices para asignarles las sumas ya sea de las columnas o de las filas
        int sumaColumnas[m];
        //Asignar los valores a la matriz C en el estado inicial
        //usar un bucle for para llenar los indices de la matriz C desde consola
        //indicar el tipo de matriz a la que se ingresaran los datos
        cout << "Matriz C" << endl;
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                cout << "fila: " << i << "columna: " << j << endl;
                cin >> matrizC[i][j];
            }
        }
        //usar un bucle for para llenar los indices de la matriz A desde consola
        //indicar el tipo de matriz a al que se ingresan los datos
        cout << "Matriz A" << endl;
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                cout << "fila: " << i << "columna: " << j << endl;
                cin >> matrizA[i][j];
            }
        }

        //Asignar total de recurso al vector totalRecursos
        //utilizando un bucle for para asginar los valores correspondientes desde consola
        cout << "Total recursos" << endl;
        for (int i = 0; i < m; i++) {
            cout << "R" << i << ":" << endl;
            cin >> totalRecursos[i];
        }

        //Asignar Recurso Disponibles al vector disponibles
        //utilizando un bucle for para asginar los valores correspondientes desde consola
        cout << "Recursos Disponibles" << endl;
        for (int i = 0; i < m; i++) {
            cout << "R" << i << ":" << endl;
            cin >> disponibles[i];
        }

        //Realizar la suma de las columnas (recursos) para comparar si no exceden los limites
        for (int columna = 0; columna < m; columna++) {
            int suma = 0;
            for (int fila = 0; fila < n; fila++) {
                suma += matrizA[fila][columna];
            }

            sumaColumnas[columna] = suma;
        }

        //total de recursos asignados segun la matriz A

        cout << "Recuros en uso" << endl;

        for (int i = 0; i < m; i++) {
            if (sumaColumnas[i] > totalRecursos[i]) {

                cout << "ERROR NO SE PUEDE CONTINUAR RECURSOS DISPONIBLES EXEDEN LOS ASIGNADOS" << endl;
                cout << "TOTAL RECURSO R=" << totalRecursos[i] << " RECURSO ASIGNADO=" << sumaColumnas[i];
                break;
            }

            cout << "R" << i << " = " << sumaColumnas[i] << " ";
        }

        cout << endl;
        //proceder hacer la resta de la matriz C-A
        cout << "PROCESANDO MATRIZ C-A" << endl;
        cout << ".........." << endl;
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                //cout << "fila: " << i << "columna: " << j <<endl;
                //declaracion de variables para almacenar los enteros de la matriz C y A
                //realizacion de la resta y posteriormente agregarlo a la matrix C-A

                int a = matrizC[i][j];
                int b = matrizA[i][j];
                matrizCmenosA[i][j] = resta(a, b);
            }
        }

        cout << "RESTA DE MATRIZ C-A COMPLETADA" << endl;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << "|" << matrizCmenosA[i][j] << "|";
            }
            cout << endl;
        }
        cout << "------------------------------------" << endl;
        cout << "SOLUCIONANDO EL PROBLEMA:" << endl;
        myfile << "SOLUCIONANDO EL PROBLEMA:"
               << "\n";

        //validar Proceso por proceso para validar si los recursos que disponemos cumplen
        //de encontrar alguno se procesara

        //bucle while se termina esta que los procesos queden completados

        int matrizFila[m];
        int filaMatrizA[m];
        int recursosTemp[m];
        int restaRecursos[m];
        // array para almacenar el orden en el que los procesos se resolvieron
        int orderProcesos[n];
        //int matrizCrecurso[m];
        //sumar la fila C-A completada para validar que ya estan acero todos los recuros y para liberarlos
        int recursosLiberados;
        int numeroIteracion = 0;
        //while(n>0)
        //{

        for (int i = 0; i < n; i++) {
            int procesoResuelto = i;
            //variable boolena para evaluar si un recurso requerido cumple con el recurso disponible
            bool cumple = true;

            cout << "-> ANALIZANDO PROCESO P" << i << endl;

            myfile << "ANALIZANDO PROCESO P:" << i << "\n";
            //escribiendo en pantalla el numero de iteracion

            cout << "-> Iteracion: " << numeroIteracion << endl;

            myfile << "-> Iteracion: " << numeroIteracion << "\n";
            for (int j = 0; j < m; j++) {
                //

                int recursoDisponible = disponibles[j];
                int matrizCrecurso = matrizCmenosA[i][j];
                recursosTemp[j] = disponibles[j];
                //al macenar la fila de los recursos temportalmente para utilizarlo si cumplen con las requerimientos
                matrizFila[j] = matrizCmenosA[i][j];
                filaMatrizA[j] = matrizA[i][j];

                if ((recursoDisponible - matrizCrecurso) < 0) {

                    //cout << "NO CUMPLE=" << recursoDisponible-matrizCrecurso ;
                    cumple = false;
                }
                //validar si algun recurso no cumplio para este proceso, este proceso puede efectuarse si y solo si los recursos disponibles cumplen con cada recurso requerid
            }

            //sumar matrizFila que es la fila C-A trabajada para validar si ese proceso ya fue completado
            for (int r = 0; r < m; r++) {
                recursosLiberados += matrizFila[r];
            }
            cout << endl;

            //cout <<"SUMA DE LA FILA RECURSO: "<<recursosLiberados<<endl;

            if (recursosLiberados == 0) {
                cumple = false;
            }

            recursosLiberados = 0;

            if (cumple == false) {

                cout << "->PROCESO P" << i << " NO CUMPLE" << endl;
                myfile << "-> PROCESO P: " << i << " NO CUMPLE"
                       << "\n";
                      
            }
            else {
                cout << "->PROCESO P" << i << " CUMPLE" << endl;
                myfile << "-> PROCESO P: " << i << " CUMPLE"
                       << "\n";
                // si el proceso cumple procesar las peticiones de recursos
                //aumentar el numero de iteracion
                numeroIteracion++;
                //Realizar operaciones de sumas y restas
                //liberar recursos y sumar a los disponibles

                for (int j = 0; j < m; j++) {
                    restaRecursos[j] = recursosTemp[j] - matrizFila[j];
                    matrizCmenosA[i][j] = 0;
                    matrizA[i][j] = filaMatrizA[j] + matrizFila[j];
                    disponibles[j] = restaRecursos[j] + matrizA[i][j];
                }

                cout << endl;

                //Imprimer matrices en cada iteracion
                //imprimir datos almacenados en las matrices
                //usar un bucle for para imprimir en pantalla los datos de las matrices

                for (int k = 0; k < n; k++) {
                    if (k <= 0) {
                        cout << "Matiz C";
                        myfile << "Matiz C";
                        for (int con = 0; con < m; con++) {
                            cout << "  ";
                            myfile << "  ";
                        }
                        cout << "Matriz A";
                        myfile << "Matiz A";
                        for (int con = 0; con < m; con++) {
                            cout << "  ";
                            myfile << "  ";
                        }
                        cout << "Matiz C-A" << endl;
                        myfile << "Matiz C-A"
                               << "\n";
                    }

                    for (int j = 0; j < m; j++) {

                        cout << "|" << matrizC[k][j] << "|";
                        myfile << "|" << matrizC[k][j] << "|";
                    }

                    cout << "	";
                    myfile << "  ";
                    for (int j = 0; j < m; j++) {

                        cout << "|" << matrizA[k][j] << "|";
                        myfile << "|" << matrizA[k][j] << "|";
                    }
                    cout << "	";
                    myfile << "  ";
                    for (int j = 0; j < m; j++) {

                        cout << "|" << matrizCmenosA[k][j] << "|";
                        myfile << "|" << matrizCmenosA[k][j] << "|";
                    }
                    myfile << "\n";
                    cout << endl;
                }

                cout << "Recursos Disponibles" << endl;
                myfile << "Recursos Disponibles"
                       << "\n";
                for (int j = 0; j < m; j++) {
                    cout << "R" << j << "=" << disponibles[j] << " ";
                    myfile << "R" << j << "=" << disponibles[j] << " ";
                }
                // agregar el proceso segun el orden que se resolvio
                orderProcesos[numeroIteracion] = procesoResuelto;

                i = 0;
            }

        } //fin del bucle de iteraciones

        cout << endl;
        cout << "SECUENCIA SEGURA" << endl;
        for (int contador = 0; contador < n; contador++) {
            cout << "P" << orderProcesos[contador] << " ";
            myfile << "P" << orderProcesos[contador] << " ";
        }
        //cerrar el archivo

        myfile.close();
    }

    return 0;
}
