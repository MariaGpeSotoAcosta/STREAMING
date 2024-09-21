#include <iostream>
#include<sstream>
#include<vector>
#include<fstream>
#include <string>
#define DATOS_PELICULAS "data_movies.csv"
#define DATOS_SERIES "data_series.csv"
#define DATOS_SERIESCAPS "data_serieschapters.csv"
#include "classesPP.cpp"

using namespace std;

int main()
{
    //CARGA DE ARCHIVOS
ARCHIVO data;
MENU menu;
ifstream archivoMOVIES(DATOS_PELICULAS);
ifstream archivoSERIES(DATOS_SERIES);
ifstream archivoSERIESCAPS(DATOS_SERIESCAPS);

vector <vector<string>> dataMovies, dataSeries, dataCaps;
dataMovies = data.getDATA(archivoMOVIES);
dataSeries = data.getDATA(archivoSERIES);
dataCaps = data.getDATA(archivoSERIESCAPS);


menu.run(dataMovies,dataSeries,dataCaps);
system ("pause");
return 0;
}

