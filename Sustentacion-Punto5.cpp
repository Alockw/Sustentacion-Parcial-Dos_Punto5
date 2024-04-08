#include <iostream>
#include <Vector>
#include <string>
#include <list>
#include <algorithm>
using namespace std;
class Videojuego
{
public:
    // variables a utilizar
    string nombre;
    vector<string> categorias;
    string desarrollador;
    int añoLanzamiento;
    string plataforma;
    int vecesJugado;
    int tiempoJugado;
    // estructura de videojuego
    Videojuego(string nombre, vector<string> categorias, string desarrollador, int añoLanzamiento, string plataforma)
        : nombre(nombre), categorias(categorias), desarrollador(desarrollador), añoLanzamiento(añoLanzamiento), plataforma(plataforma), vecesJugado(0), tiempoJugado(0) {}
};
// funcion para agregar o metodo para agregar un juego
class Ejecucion
{
private:
    vector<Videojuego> coleccion;

public:
    // metodo para agregar un juego
    void agregarJuego()
    {
        // variables autilizar
        string nombre;
        vector<string> categorias;
        string desarrollador;
        int añoLanzamiento;
        string plataforma;
        // pedir informacion a el usario
        cout << "Ingrese el nombre del videojuego: ";
        cin >> nombre;
        cout << "Ingrese las categorias del videojuego (separadas por comas): ";
        string categoriasStr;
        cin >> categoriasStr;
        // asumimos una sola categoría.
        categorias.push_back(categoriasStr);
        cout << "Ingrese el desarrollador del videojuego: ";
        cin >> desarrollador;
        cout << "Ingrese el ano de lanzamiento del videojuego: ";
        cin >> añoLanzamiento;
        cout << "Ingrese la plataforma del videojuego: ";
        cin >> plataforma;
        // se ingresa un push_back para poder ingresar a la coleccion del usario con la estructura de videojuego
        // ya predefinida

        coleccion.push_back(Videojuego(nombre, categorias, desarrollador, añoLanzamiento, plataforma));
    }
    // ordenamiento por titulo de a para abajo
    void mostrarJuegosOrdenadosPorTitulo()
    {
        // recorre la coleccion del el suario de el primero a el ultimo pasando de orden para organizar de forma
        // acendente de a a b y asi susecivamente tomando solo como pareamentro para odernar
        // la variable de nombre
        sort(coleccion.begin(), coleccion.end(), [](const Videojuego &a, const Videojuego &b)
             { return a.nombre < b.nombre; });
        // y se toma el ciclo for para que duevuelva ya los juegos ordenados por titulo
        for (const auto &juego : coleccion)
        {
            cout << juego.nombre << endl;
        }
    }
    // mostrar por año de lazamiento
    void mostrarJuegosOrdenadosPorAñoLanzamiento()
    {
        // lo mismo que en por titulo sino que esta es por numero en vez de tomar el ordemanieto por las
        // letras de colecciontomando solo la varibale de año de lanazmieitno
        sort(coleccion.begin(), coleccion.end(), [](const Videojuego &a, const Videojuego &b)
             { return a.añoLanzamiento < b.añoLanzamiento; });
        // ciclo para que muestre los juegos ordenados por año de lanzamiento despues de su ordenamiento
        for (const auto &juego : coleccion)
        {
            cout << juego.nombre << " (" << juego.añoLanzamiento << ")" << endl;
        }
    }
    void agregarCategoria(){
        string nombre;
        vector<string> categorias;
        cout << "Ingrese el nombre del a el cual agregara o modificara su categoria videojuego: ";
        cin >> nombre;
        cout << "Ingrese las categorias del videojuego (separadas por comas): ";
        string categoriasStr;
        cin >> categoriasStr;
    }
    // orden de juegos por su plataforma
    void mostrarJuegosPorPlataforma(const string &plataforma)
    {
        // se toma un ciclo for con parametros sencillos el cual tome como un parametro que  si el juego.plataforma
        //  es igual a una platafrma ingresada esta misma se ponga con esta haciendo que sea ordenado por
        // plataforma (nose como explicarlo bien perdon)
        for (const auto &juego : coleccion)
        {
            if (juego.plataforma == plataforma)
            {
                cout << juego.nombre << endl;
            }
        }
    }
    // mostrar juegos mas juegador
    void mostrarJuegosMasJugados()
    {
        // se toma como un ordenamiento de mayar a menor catidad de veces juegadas tomando esta vez
        // como parametro se tomaria encuenta las veces jugadas envez de otro parametro repitiendo el mismo metodo
        // de los demas ordenamientos
        sort(coleccion.begin(), coleccion.end(), [](const Videojuego &a, const Videojuego &b)
             { return a.vecesJugado > b.vecesJugado; });
        // la misma forma de poder hacer que aparesca ya los juegos mas jugados despues de el ordenameinto
        for (const auto &juego : coleccion)
        {
            cout << juego.nombre << " (" << juego.vecesJugado << " veces jugado)" << endl;
        }
    }
    // metodo de ejecucion para el menu que deje interactuar al usuario
    void menu()
    {
        int opcion;
        string plataforma;
        string nombreJugador;
        // do while para que sea un menu que sirva hasta que el usario ponga la opcion de salir de este y no
        // ponga problema con una opcino de las que no aparesca sino que vuelva a pedir otra opcion
        do
        {
            cout << "--menu--" << endl;
            cout << "1) Agregar un videojuego" << endl;
            cout << "2) Mostrar juegos ordenados por titulo" << endl;
            cout << "3) Mostrar juegos ordenados por ano de lanzamiento" << endl;
            cout << "4) Mostrar juegos por plataforma" << endl;
            cout << "5) Mostrar juegos mas jugados" << endl;
            cout << "6) Modificar categoria o agregar categoria a juego " << endl;
            cout << "7) Salir" << endl;
            cin >> opcion;
            // menu con un witch opcion para que dependienco de lo que haga el usario o la opcion que escoja
            //
            switch (opcion)
            {
            case 1:
                agregarJuego();
                break;
            case 2:
                mostrarJuegosOrdenadosPorTitulo();
                break;
            case 3:
                mostrarJuegosOrdenadosPorAñoLanzamiento();
                break;
            case 4:
                cout << "Ingrese la plataforma: "<<endl;
                cin >> plataforma;
                mostrarJuegosPorPlataforma(plataforma);
                break;
            case 5:
                cout << "porfavor ingrese su nombre de usario para ver sus juegos mas jugados " << endl;
                mostrarJuegosMasJugados();
                break;
            case 6:
                agregarCategoria
                break;
            case 7:
                cout << "Saliendo..." << endl;
            break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
                break;
            }
        } while (opcion != 6);
    }
};
int main()
{
    Ejecucion ejecucion;
    ejecucion.menu();
    return 0;
}