#include "funciones.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;



vector<string> cargar_listado(const string & nombre_archivo){
    ifstream inFile(nombre_archivo);
    vector<string> listado;

    if (inFile.good() == false){
        cout << "Hubo un error abriendo el archivo"<< endl;
        return listado;
    }
    
    string palabra;

    while (getline(inFile, palabra)){
        listado.push_back(palabra);
        
    }

    inFile.close();

    if (listado.empty()){
        cout<<"La lista está vacía"<< endl;
        return listado;
    }
    return listado;
}

bool intento_valido(const string & intento, const string & palabra_secreta, const vector<string> &listado){
    
    bool mismoLargo = intento.size() == palabra_secreta.size();
    bool palabraValida = false;

    for ( const string &palabra : listado){
        if ( palabra == intento){
            palabraValida = true;
            break;
        }

    }
    
    if ( mismoLargo && palabraValida){
        
        return true;
    } else{
        
        return false;
        
    }
}

vector<EstadoLetra> evaluar_intento(const string & intento, const string & palabra_secreta){
    vector<EstadoLetra> evaluacion (intento.size(), EstadoLetra:: NoPresente);
    for(int i = 0; i < intento.size(); i++){
        if( intento[i] == palabra_secreta[i]){
            evaluacion[i] = EstadoLetra::LugarCorrecto; 
        } else{
            for(int j = 0; j < palabra_secreta.size(); j++ ){
                if(intento[i]==palabra_secreta[j]){
                    evaluacion[i] = EstadoLetra::LugarIncorrecto;
                    break;
                }
            }
        }
    }
    return evaluacion;
}

string respuesta_en_string(const vector<EstadoLetra> & respuesta){
    string resultado= "";

    for (int i = 0; i< respuesta.size(); i++){
        if (respuesta[i] == EstadoLetra::LugarCorrecto){
            resultado.append("+");
        } else if (respuesta[i] == EstadoLetra::LugarIncorrecto){
            resultado.append("-");
        }else{
            resultado.append("X");
        }
    }

    return resultado;
}