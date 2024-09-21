#include<iostream>
#include<math.h>
#include<stdlib.h>
#include <numeric>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include "classes_proyecto.cpp"
#define DATOS_PELICULAS "data_movies.csv"
#define DATOS_SERIES "data_series.csv"
using namespace std;

class MENU{
public:


bool GeneroBool(const vector<string>& GENEROS, const string& genero) {
  //DEFINE SI UN GENERO YA ESTÁ EN EL VECTOR

    int x;
    x = count(GENEROS.begin(), GENEROS.end(), genero);
    if (x!=0){
    return false;
    }
     if (x==0){
    return true;
    }
}


    void mostrarPelis(VIDEO* video[],int SIZE){
        //FUNCION PARA MOSTRAR LAS PELICULAS
        cout<<""<<endl;
        cout<<""<<endl;
        cout << "-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-..-" << endl;
        cout << "-       PELICULAS DISPONIBLES        -" << endl;
        cout << "-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-..-" << endl;
        cout<<""<<endl;
        cout<<""<<endl;
        for (int i=0;i<SIZE;i++){
        VIDEO *current = video[i];
            if(current->getType()== "Pelicula"){
            current->printVIDEO();
        }
      }
    float y;
        int x;
        while(x!=0){
        cout<<"1.- Buscar por calificacion"<<endl;
        cout<<"2.- Buscar por genero"<<endl;
        cout<<"0.- Salir del menu de peliculas"<<endl;
        cin>>x;

        if(x==1){
            cout<<"Ingrese calificacion"<<endl;
            cin>>y;
            if(y>5){
                cout<<"CALIFICACION DEBE SER MENOR O IGUAL A 5"<<endl;
            }
            else{
            for (int i=0;i<SIZE;i++){
        VIDEO *current = video[i];
            if(current->getCalificacion() >= y && current->getType()== "Pelicula"){
            current->printVIDEO();
                                      }
                                    }
                                  }
                                }
        if(x==2){
    mostrarPorGeneroPELIS(video,SIZE);
                                }

                               }
    return;
                               }


      void mostrarSerie(VIDEO* video[],int SIZE){
       //FUNCION PARA MOSTRAR SERIES
        cout<<""<<endl;
        cout<<""<<endl;
        cout << "-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-..-" << endl;
        cout << "-          SERIES DISPONIBLES        -" << endl;
        cout << "-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-..-" << endl;
        cout<<""<<endl;
        cout<<""<<endl;
        for (int i=0;i<SIZE;i++){
        VIDEO *current = video[i];
            if(current->getType()== "Serie"){
            current->printVIDEO();
        }
      }
      int x;
      string y;
    while(x!=0){
        cout<<"1.- Ver capitulos de serie"<<endl;
        cout<<"2.- Ver series con determinada calificacion"<<endl;
        cout<<"3.- Buscar serie por genero"<<endl;
        cout<<"0.- Salir del menu de series"<<endl;
        cin>>x;
        if(x==1){
            cout<<"Ingrese ID de serie"<<endl;
            cin>>y;
            for (int i=0;i<SIZE;i++){
        VIDEO *current = video[i];
            if(current->getID()== y){
            current->printVIDEO();
            current -> printCHAPTERS(current->getName(),SIZE);
        }
      }
        }
        if(x==2){
            float q;
             cout<<"Ingrese calificacion"<<endl;
            cin>>q;
            if(q>5){
                cout<<"CALIFICACION DEBE SER MENOR O IGUAL A 5"<<endl;
            }
            else{
                for (int i=0;i<SIZE;i++){
        VIDEO *current = video[i];
            if(current->getCalificacion() >= q && current->getType()== "Serie"){
            current->printVIDEO();
            }
        }
      }

    }
    if(x==3){
            mostrarPorGeneroSERIE(video,SIZE);
        }

       }
      return;
    }

void mostrarPorGeneroSERIE(VIDEO* video[],int SIZE){
//MOSTRAR SERIES POR GENERO
        vector<string> generos;
        generos.clear();
        string generoProb;
        int x,y;

        for (int i=0;i<SIZE;i++){
        VIDEO *current = video[i];
        generoProb= current->getGenero();

           if(GeneroBool(generos, generoProb)){
            generos.push_back(generoProb);
        }
        }
        for(int i=0;i<generos.size();i++){

            cout<<i+1<<".- "<<generos[i]<<endl;
        }
        cout<<""<<endl;
        cout<<"Que genero te interesa?"<<endl;
        cin>>x;
        y=x-1;
        for (int i=0;i<SIZE;i++){
        VIDEO *current = video[i];
        generoProb= current->getGenero();

           if(generoProb == generos[y] && current->getType()=="Serie"){
            current -> printVIDEO();
        }
      }
    }


void mostrarPorGeneroPELIS(VIDEO* video[],int SIZE){
//MOSTRAR PELICULAS POR GENERO
        vector<string> generos;
        generos.clear();
        string generoProb;
        int x,y;

        for (int i=0;i<SIZE;i++){
        VIDEO *current = video[i];
        generoProb= current->getGenero();

           if(GeneroBool(generos, generoProb)){
            generos.push_back(generoProb);
        }
        }
        for(int i=0;i<generos.size();i++){

            cout<<i+1<<".- "<<generos[i]<<endl;
        }
        cout<<""<<endl;
        cout<<"Que genero te interesa?"<<endl;
        cin>>x;
        y=x-1;
        for (int i=0;i<SIZE;i++){
        VIDEO *current = video[i];
        generoProb= current->getGenero();

           if(generoProb == generos[y] && current->getType()=="Pelicula"){
            current -> printVIDEO();
        }
        }
    }
void writeCSV(const string &filename, const vector<vector<string>> &data) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto &row : data) {
            for (size_t i = 0; i < row.size(); ++i) {

                file << row[i];
                if (i < row.size() - 1) {
                    file << ",";
                }
            }
            file << "\n";
        }
        file.close();
        cout << "ARCHIVO GUARDADO"<<endl;
    } else {
        cerr << "FAIL";
    }
}

    void mostrarPorGenero(VIDEO* video[],int SIZE){
//MOSTRAR CONTENIDO GENERAL POR GENERO
        vector<string> generos;
        generos.clear();
        string generoProb;
        int x,y;

        for (int i=0;i<SIZE;i++){
        VIDEO *current = video[i];
        generoProb= current->getGenero();

           if(GeneroBool(generos, generoProb)){
            generos.push_back(generoProb);
        }
        }
        for(int i=0;i<generos.size();i++){

            cout<<i+1<<".- "<<generos[i]<<endl;
        }
        cout<<""<<endl;
        cout<<"Que genero te interesa?"<<endl;
        cin>>x;
        y=x-1;
        for (int i=0;i<SIZE;i++){
        VIDEO *current = video[i];
        generoProb= current->getGenero();

           if(generoProb == generos[y]){
            current -> printVIDEO();
        }
        }
    }
void calificar(VIDEO* video[],int SIZE){
    //CALIFICAR CONTENIDO
string x;
float y;
cout<<"Ingrese el ID del contenido que desea calificar"<<endl;
cin>>x;
 for (int i=0;i<SIZE;i++){
        VIDEO *current = video[i];
            if(current->getID()== x){
            cout << *current << endl;
            cout<<"INGRESE SU CALIFICACION"<<endl;
            cin>>y;
                if(y<=5 && y>=0){
                   current-> setCalificacion(y);
                   cout<<current-> getCalificacion()<<endl;
                }
                 if(y>5 && y<0){
                    cout<<"NOT VALID"<<endl;
                }

        }

}
}
void mostrarPorCalificacion(VIDEO* video[],int SIZE){
float x;
//MOSTRAR CONTENIDO POR CALIFICACION
cout<<"Ingrese la calificacion deseada"<<endl;
cin>>x;
if(x>5){
                cout<<"CALIFICACION DEBE SER MENOR O IGUAL A 5"<<endl;
            }
else{
for (int i=0;i<SIZE;i++){
    VIDEO *current = video[i];
    if(current->getCalificacion()>=x){
        current->printVIDEO();
    }
}
}
}

void run(vector <vector<string>> _moviesDATA,vector <vector<string>> _seriesDATA, vector <vector<string>> _capsDATA){
int SIZE;
//MENU
PELICULA pelis;
vector <vector<string>> capitulos;
SIZE= _moviesDATA.size()+_seriesDATA.size();

VIDEO *video[SIZE];
//CARGA DE MATRICES A PUNTERO
for(int i=0; i<_moviesDATA.size();i++){
    video[i]= new PELICULA(_moviesDATA[i][0],_moviesDATA[i][1],_moviesDATA[i][2],_moviesDATA[i][3],_moviesDATA[i][4],_moviesDATA[i][5],_moviesDATA[i][6],_moviesDATA[i][7],stof(_moviesDATA[i][8]),stoi(_moviesDATA[i][9]),stof(_moviesDATA[i][10]));
}

for(int i=0; i<_seriesDATA.size();i++){
    capitulos.clear();
    for (int j=0; j < _capsDATA.size();j++){
        if(_seriesDATA[i][0] == _capsDATA[j][0]){
        capitulos.push_back(_capsDATA[j]);
        }
    }

    video[i+(_moviesDATA.size())]= new SERIE(_seriesDATA[i][0],_seriesDATA[i][1],_seriesDATA[i][2],_seriesDATA[i][3],_seriesDATA[i][4],_seriesDATA[i][5],_seriesDATA[i][6],_seriesDATA[i][7],stof(_seriesDATA[i][8]),stoi(_moviesDATA[i][9]),stof(_moviesDATA[i][10]),capitulos);

}
int PARAMETRO;
PARAMETRO=1;
while (PARAMETRO!=0){
cout<<""<<endl;
cout<<""<<endl;
cout<<"-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-..-"<<endl;
cout<<"-      BIENVENIDO A VIDEOS COOL      -"<<endl;
cout<<"-         QUE DESEA VER HOY?         -"<<endl;
cout<<"-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-..-"<<endl;
cout<<""<<endl;
cout<<""<<endl;
cout<<"RECOMENDACION DEL DIA:"<<endl;
video[ (rand()% SIZE + 0)]->printVIDEO();
cout<<""<<endl;
cout<<""<<endl;
cout<<"1.-Ver peliculas"<<endl;
cout<<"2.- Ver series"<<endl;
cout<<"3.- Buscar por genero"<<endl;
cout<<"4.- Buscar por calificacion"<<endl;
cout<<"5.- Calificar contenido"<<endl;
cout<<"0.- Salir"<<endl;
cin>>PARAMETRO;
if(PARAMETRO == 1){
mostrarPelis(video,SIZE);
}
if(PARAMETRO == 2){
mostrarSerie(video,SIZE);
}
if(PARAMETRO == 3){
mostrarPorGenero(video,SIZE);
}
if(PARAMETRO == 4){
mostrarPorCalificacion(video,SIZE);
}

if(PARAMETRO == 5){
calificar(video,SIZE);
}

}
//DESPUES DEL WHILE, SE CARGAN A UN ARCHIVO CSV
for(int i=0; i<_moviesDATA.size();i++){

    _moviesDATA[i]= video[i]->vectorcreator();
cout<<_moviesDATA[i][0]<<endl;
}
writeCSV(DATOS_PELICULAS, _moviesDATA);
for(int i=0; i<_seriesDATA.size();i++){
    _seriesDATA[i]= video[i+(_moviesDATA.size())]->vectorcreator();
cout<<_seriesDATA[i][0]<<endl;
}
writeCSV(DATOS_SERIES, _seriesDATA);


}


};



