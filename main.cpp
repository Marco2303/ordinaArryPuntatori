/**
* Calcolo differenza di tempo impiegato nell'ordinamento
* di un array usando prima una copia dell'array e poi un
* puntatore ad array
*/

#include <iostream>
#include <string>
#include <ctime>
#include <typeinfo>


using namespace std;
const int MAX_ARRAY = 30000;
const int CHAR_MAX = 500;

void ordinaArray(string strArray2[MAX_ARRAY]);
void ordinaArrayPun(string *strArray3[MAX_ARRAY]);

int main()
{
    cout << endl;
    cout << "=====================================================================" << endl;
    cout << " Questo programma genera un array con i segienti elementi" << endl;
    cout << endl;
    cout << " Numero di elementi array: " << MAX_ARRAY << endl;
    cout << " Char che compongono la riga dell'array: " << CHAR_MAX << endl;
    cout << endl;
    cout << " Prima viene lanciata la funziona di ordinamento in memoria" << endl;
    cout << " che usa una copia dell'array, poi vine lancta una seconda" << endl;
    cout << " funzione che usa sempre lo stesso array ma gli veiene passato" << endl;
    cout << " il puntatore all'array e l'rdimaneto avviene usando i puntatori" << endl;
    cout << " a questo array."  << endl;
    cout << " Alla fine di ogni ordinamento vine visualizzato il tempo impiegato" << endl;
    cout << " per l'ordinamento." << endl;
    cout << "=====================================================================" << endl;
    cout << endl;
    cout << endl;
    string strArray[MAX_ARRAY] = {};
    string* punArray[MAX_ARRAY] = {};


   //GENERO LE TRINGHE PER ARRAY
   cout << " INIZIO generazione array di elementi char" << endl;
   string str = "";
   srand(time(NULL));
    for(int I=0;I<MAX_ARRAY;I++){
        for(int a=0;a<CHAR_MAX;a++){
            //cout << " " << rand()%25+97 << endl;
            strArray[I] = string(CHAR_MAX,'a'+rand()%26);
            }
    }
   cout << " FINE generazione array di elementi char" << endl;

    punArray[MAX_ARRAY] = &strArray[MAX_ARRAY];

    ordinaArray(strArray);
    ordinaArrayPun(punArray);

    return 0;
}

void ordinaArrayPun(string *strArray3[MAX_ARRAY]){
   //ordina array a partire da una copia in memoria
    time_t time_inizio = time(0);
    cout << endl;
    cout << "*********************************************************************" << endl;
    cout << " Inizio SECONDA funzione di ordinamento tramite PUNTATORI AD ARRAY" << endl;
    cout << endl;

    for(int i=0; i<MAX_ARRAY;i++){
        for(int a=1;a<MAX_ARRAY;a++){
            if(strArray3[i]<strArray3[a]){
                string *tmp = strArray3[i];
                strArray3[i] = strArray3[a];
                strArray3[a] = tmp;
            }
        }
    }

    time_t time_fine = time(0);

    cout << "Tempo impiegato ad ordinare lo stesso array passato come punattore SECONDI: ----> " << difftime(time_fine,time_inizio) << endl;
    cout << "*********************************************************************" << endl;
    cout << endl;

}

void ordinaArray(string strArray2[MAX_ARRAY]){
    //ordina array a partire da una copia in memoria
    time_t time_inizio = time(0);
    cout << endl;
    cout << "*********************************************************************" << endl;
    cout << " Inizio prima funzione di ordinamento su COPIA DELL'ARRAY" << endl;
    cout << endl;

    for(int i=0; i<MAX_ARRAY;i++){
        for(int a=1;a<MAX_ARRAY;a++){
            if(strArray2[i]<strArray2[a]){
                string tmp = strArray2[i];
                strArray2[i] = strArray2[a];
                strArray2[a] = tmp;
            }
        }
    }

    time_t time_fine = time(0);

    cout << "Tempo impiegato ad ordinare un copia di array: SECONDI: ----> " << difftime(time_fine,time_inizio) << endl;
    cout << "*********************************************************************" << endl;
    cout << endl;

}
