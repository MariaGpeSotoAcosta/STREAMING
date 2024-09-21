#include<iostream>
#include<math.h>
#include<stdlib.h>
#include <numeric>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;
//FUNCION PARA HACER CARGA DE ARCHIVOS
class ARCHIVO{
public:
    vector <vector<string>> getDATA(ifstream& file){
    string line;
vector <vector<string>> data;

while (getline(file,line)){
    vector <string> video;
    string cell;
    istringstream row(line);
     while (getline(row, cell, ',')) {
            video.push_back(cell);
        }
    data.push_back(video);

}
return data;
    }


};
//CLASE VIDEO, CLASE PADRE
class VIDEO{
public:
   VIDEO();
   VIDEO(string,string,string,string,string,string,string,string,float,int,float);
    virtual void printVIDEO();
    virtual string getType();
    virtual float getCalificacion(){};
    virtual void setCalificacion(float){};
    virtual string getGenero();
    virtual string getID();
    virtual string getName();
    virtual void printCHAPTERS(string,int){};

    vector<string> vectorcreator();

     virtual void imprimir(ostream& os) const = 0;
    friend ostream& operator<<(ostream& os, const VIDEO& video);
//OPERADOR SOBRECARGADO

protected:
     string nombre;
     string idioma;
     string year;
     string duracion;
     string genero;
     string director;
     string TIPO;
     string ID;
     float calificacion;
     int votantes;
     float total;
     vector<string> vector1;



};
ostream& operator<<(ostream& os, const VIDEO& video) {
    video.imprimir(os);
    return os;
}
//OPERADOR SOBRECARGADO

vector<string> VIDEO::vectorcreator(){
vector1={nombre,idioma,year,duracion,genero,director,TIPO,ID,to_string(calificacion),to_string(votantes),to_string(total)};
return vector1;
}
string VIDEO::getType(){
return TIPO;
}
string VIDEO::getGenero(){
return genero;
}
string VIDEO::getName(){
return nombre;
}
string VIDEO::getID(){
return ID;
}
void VIDEO::printVIDEO(){

}


VIDEO::VIDEO(){}
VIDEO::VIDEO(string _nombre,string _idioma,string _year,string _duracion,string _genero,string _director,string _TIPO,string _ID,float _calificacion,int _votantes,float _total ){
nombre = _nombre;
idioma = _idioma;
year = _year;
duracion = _duracion;
genero = _genero;
director = _director;
TIPO = _TIPO;
ID = _ID;
calificacion = _calificacion;
votantes = _votantes;
total = _total;
}

//CLASE HIJA, PELICULA
class PELICULA: public VIDEO{
public:
PELICULA();
PELICULA(string,string,string,string,string,string,string,string,float,int,float);
void printVIDEO();
void verPeliculas(vector<VIDEO*>& videos);
string getType();
float getCalificacion();
void setCalificacion(float);
string getGenero();
string getID();
string getName();
  void imprimir(ostream& os) const override {
        os << "Pelicula: " << nombre << ", Calificacion: " << calificacion <<endl;
    }


};


string PELICULA::getName(){
return nombre;
}
string PELICULA::getID(){
return ID;
}
string PELICULA::getType(){
return TIPO;
}

float PELICULA:: getCalificacion(){
return calificacion;
}
string PELICULA:: getGenero(){
return genero;
}
void PELICULA:: setCalificacion(float _x){
total = total + _x;
votantes = votantes + 1;
calificacion= (total)/votantes;

}

PELICULA::PELICULA(){}
PELICULA::PELICULA(string _nombre,string _idioma,string _year,string _duracion,string _genero,string _director,string _TIPO,string _ID,float _calificacion,int _votantes,float _total):VIDEO(_nombre,_idioma,_year,_duracion,_genero,_director,_TIPO,_ID,_calificacion,_votantes,_total){
nombre = _nombre;
idioma = _idioma;
year = _year;
duracion = _duracion;
genero = _genero;
director = _director;
TIPO = _TIPO;
ID = _ID;
calificacion = _calificacion;
votantes = _votantes;
total = _total;
}

void PELICULA::printVIDEO(){
cout<<"-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-..-.-.-.-.-.-.-.-.-.-.-.-.-.-.-."<<endl;
cout<<nombre<< "      Idioma Original: "<< idioma<<endl;
cout<<year<<"      "<<duracion << "horas/min    Dirigida por " <<director<<endl;
cout<<"CALIFICACION ACTUAL: "<< calificacion<<endl;
cout<<"ID: "<<ID<<endl;
cout<<genero<<endl;
cout<<"-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-..-.-.-.-.-.-.-.-.-.-.-.-.-.-.-."<<endl;
cout<<""<<endl;
cout<<""<<endl;
}

//CLASE HIJA, SERIE
class SERIE:public VIDEO{
public:
SERIE();
friend ostream& operator<<(ostream& os, const VIDEO& video);
SERIE(string,string,string,string,string,string,string,string,float,int,float,vector <vector<string>>);
void printVIDEO();
string getType();
float getCalificacion();
void setCalificacion(float);
string getGenero();
string getID();
void printCHAPTERS(string,int);
string getName();
  void imprimir(ostream& os) const override {
        os << "Serie: " << nombre << ", Calificacion: " << calificacion <<endl;
    }


private:
     vector <vector<string>> caps;


};



string SERIE::getGenero(){
return genero;
}
string SERIE::getID(){
return ID;
}
string SERIE::getType(){
return TIPO;
}
string SERIE::getName(){
return nombre;
}
float SERIE:: getCalificacion(){
return calificacion;
}
void SERIE::printCHAPTERS(string name,int SIZE){
 for (int i=0;i<caps.size();i++){
        if(name == caps[i][0]){
       cout<<"Temporada "<<caps[i][1]<<" , "<<caps[i][2]<<endl;
        }
      }
}

void SERIE:: setCalificacion(float _x){
total = total + _x;
votantes = votantes + 1;
calificacion= total/votantes;

}

SERIE::SERIE(){}
SERIE::SERIE(string _nombre,string _idioma,string _year,string _duracion,string _genero,string _director,string _TIPO,string _ID,float _calificacion,int _votantes ,float _total,vector <vector<string>> _caps ):VIDEO(_nombre,_idioma,_year,_duracion,_genero,_director,_TIPO,_ID,_calificacion,_votantes,_total){
nombre = _nombre;
idioma = _idioma;
year = _year;
duracion = _duracion;
genero = _genero;
director = _director;
TIPO = _TIPO;
ID = _ID;
calificacion = _calificacion;
votantes = _votantes;
total = _total;
caps = _caps;
}
void SERIE::printVIDEO(){
cout<<"-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-..-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-..-.-.-..-.-."<<endl;
cout<<nombre<< "      Idioma Original: "<< idioma<<endl;
cout<<year<<"      "<<duracion << " Temporadas    Dirigida por " <<director<<endl;
cout<<"CALIFICACION ACTUAL: "<< calificacion<<endl;
cout<<"ID: "<<ID<<endl;
cout<<genero<<endl;
cout<<"-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-..-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-."<<endl;
cout<<""<<endl;
cout<<""<<endl;
}
