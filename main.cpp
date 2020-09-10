//Benjamin Guillermo López Salinas A01383127
//Programación Orientada a Objetos
//7 de Septiembre del 2020
//Proyecto 1

#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sstream>

using namespace std;

void buscar_reemplazarCLIENTE (string& linea, string buscar, string reemplazar)
{
    int posicion = linea.find(buscar);
    if (posicion!= -1)
    {
        linea.replace (posicion, 9, reemplazar);
    }
    int posicion2 = linea.find(buscar);
    if (posicion2 != -1)
    {
        linea.replace (posicion2, 9, reemplazar);
    }

}

void buscar_reemplazarSALDO (string& linea, string buscar, string reemplazar)
{
    int posicion = linea.find(buscar);
    if (posicion!= -1)
    {
        linea.replace (posicion, 7, reemplazar);
    }
    int posicion2 = linea.find(buscar);
    if (posicion2 != -1)
    {
        linea.replace (posicion2, 7, reemplazar);
    }
}

void buscar_reemplazarFECHA (string& linea, string buscar, string reemplazar)
{
    int posicion = linea.find(buscar);
    if (posicion!= -1)
    {
        linea.replace (posicion, 7, reemplazar);
    }
    int posicion2 = linea.find(buscar);
    if (posicion2 != -1)
    {
        linea.replace (posicion2, 7, reemplazar);
    }
}

void buscar_reemplazarCUENTA (string& linea, string buscar, string reemplazar)
{
    int posicion = linea.find(buscar);
    if (posicion!= -1)
    {
        linea.replace (posicion, 8, reemplazar);
    }
    int posicion2 = linea.find(buscar);
    if (posicion2 != -1)
    {
        linea.replace (posicion2, 8, reemplazar);
    }

}

void buscar_reemplazarDIRECCION (string& linea, string buscar, string reemplazar)
{
    int posicion = linea.find(buscar);
    if (posicion!= -1)
    {
        linea.replace (posicion, 11, reemplazar);
    }
    int posicion2 = linea.find(buscar);
    if (posicion2 != -1)
    {
        linea.replace (posicion2, 11, reemplazar);
    }

}

void buscar_reemplazarEMPRESA (string& linea, string buscar, string reemplazar)
{
    int posicion = linea.find(buscar);
    if (posicion!= -1)
    {
        linea.replace (posicion, 9, reemplazar);
    }
    int posicion2 = linea.find(buscar);
    if (posicion2 != -1)
    {
        linea.replace (posicion2, 9, reemplazar);
    }

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    string cliente;
    string saldo;
    string fecha;
    string cuenta;
    string direccion;
    string empresa;
    string getmyFileName;
    string getSalidaName;
    string getPlantillaName;

string line1[30];
string line2[30];
string line3[30];
string line4[30];
string line5[30];
string line6[30];



  int a = 0;
  int b = 0;
  int c = 0;
  int d = 0;
  int e = 0;
  int f = 0;

    cout << "Dame el nombre del archivo Plantilla : ";
	cin >> getPlantillaName;
	cout<<endl;
	ifstream archivoPlantilla( getPlantillaName.c_str() );

    cout << "Dame el nombre del archivo con los datos del cliente : ";
	cin >> getmyFileName;
	cout<<endl<<endl;
	ifstream myfile( getmyFileName.c_str() );

	cout << "Como quieres que se llame el archivo de Salida? : ";
	cin >> getSalidaName;
	cout<<endl<<endl;
	ofstream archivoSalida(getSalidaName.c_str());




  if(!myfile)
  {
    cout<<"Error opening output file"<<endl;
    return -1;
  }
  while(!myfile.eof())
  {
    getline(myfile,line1[a],'\n');
    cliente=line1[a];

    getline(myfile,line2[b],'\n');
    saldo=line2[b];

    getline(myfile,line3[c],'\n');
    fecha=line3[c];

    getline(myfile,line4[d],'\n');
    cuenta=line4[d];

    getline(myfile,line5[e],'\n');
    direccion=line5[e];

    getline(myfile,line6[f],'\n');
    empresa=line6[f];
  }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    int busco;
    busco=cliente.find(" ");
    cliente=cliente.substr(busco);
    cliente.erase(0,1);

    busco=saldo.find(" ");
    saldo=saldo.substr(busco);
    saldo.erase(0,1);

    busco=fecha.find(" ");
    fecha=fecha.substr(busco);
    fecha.erase(0,1);

    busco=cuenta.find(" ");
    cuenta=cuenta.substr(busco);
    cuenta.erase(0,1);

    busco=direccion.find(" ");
    direccion=direccion.substr(busco);
    direccion.erase(0,1);

    busco=empresa.find(" ");
    empresa=empresa.substr(busco);
    empresa.erase(0,1);

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    string linea;

	while (getline(archivoPlantilla, linea))
	{
        buscar_reemplazarCLIENTE(linea, "<cliente>", cliente);
        buscar_reemplazarSALDO(linea, "<saldo>", saldo);
        buscar_reemplazarFECHA(linea, "<fecha>", fecha);
        buscar_reemplazarCUENTA(linea, "<cuenta>", cuenta);
        buscar_reemplazarDIRECCION(linea, "<direccion>", direccion);
        buscar_reemplazarEMPRESA(linea, "<empresa>", empresa);
        archivoSalida<<linea<<endl;
		cout<<linea<<endl;

	}

    archivoSalida.close();
	archivoPlantilla.close();
	myfile.close();
	return 0;

}
