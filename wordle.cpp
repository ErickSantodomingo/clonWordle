#include "funciones.h"
#include <iostream> // Librería para entrada/salida
using namespace std;

int main(){

    srand(time(0));

    vector<string> listado = cargar_listado("listado.txt");

    int numeroRandom = rand() % listado.size() ;
    string palabraSecreta = listado[numeroRandom];

    int intentos = 6;
    
    //Bienvenida al juego

    cout<< "Bienvenido a Wordle"<< endl;

    while ( intentos > 0){
        string palabraIntento;
        cout<<"Escribe aquí tu intento: "<< endl;
        cin>> palabraIntento;
        
        if ( intento_valido(palabraIntento, palabraSecreta, listado) == false ){
            cout << "La palabra que ingresaste no es válida" << endl;
            cout << "Por favor, ingresa un término válido" << endl;
            
            continue;
        }
        if( palabraIntento == palabraSecreta){
            cout<< "Sos un genio, la adivinaste"<< endl;
            break;
        }
        string resultado = respuesta_en_string(evaluar_intento(palabraIntento, palabraSecreta));
        cout<< resultado << endl;
        intentos--;
        cout<<"Ups! No es esa, te quedan "<< intentos<< " intentos"<< endl;
        
       
    }
    if( intentos == 0){
        cout<<"Lamento informarte que perdiste mi buen amigo"<<endl;
        cout << "La palabra secreta era " << palabraSecreta << endl;
    }
    return 0;
}
