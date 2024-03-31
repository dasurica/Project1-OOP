#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
class Bon;
class Medicament {

private:
    char  *nume;
    bool  fractie;
    int   numarPastile;
    float pret;
    char  idRaft;

public:
    friend ostream &operator<<(ostream &, const Medicament &);
    friend istream &operator>>(istream &, Medicament &);


//CONSTRUCTORI

    Medicament();                               //constructorul fara parametrii
    Medicament(char*, int, float, bool, char);  //constructorul cu toti parametrii
    Medicament(int, float, bool);               //constructor cu parametrii variabili 1
    Medicament(char*, char );                   //constructor cu parametrii variabili 2
    Medicament(const Medicament &);             //Copy constructer

    //setters

    void setnume(const char*);
    void setpret(float);
    void setnumarpastile(int);
    void setfractie(bool);
    void setidRaft(char);

    //getters
    const char* getnume();
    const float getpret();
    const int getnumarPastile();
    const bool getfractie();
    const char getidRaft();

    //Supraincarcarea operatorilor
    bool operator==(const Medicament &);    //OPERATORUL ==                 //Testeaza daca 2 obiecte de tip Medicament sunt identice
    int operator+(const Medicament& );      //OPERATORUL +                  //Returneaza suma preturilor din 2 medicamente
    int operator-(const Medicament&);       //OPERATORUL -                  //Returneaza diferenta preturilor din 2 medicamente
    Medicament& operator++();               //OPERATORUL ++ Inainte         //Incrementeaza pretul
    Medicament operator++(int);             //OPERATORUL ++ POST            //Incrementeaza pretul dupa
    Medicament operator=(const Medicament &obj); //OPERATORUL =
    bool operator<(const Medicament &obj);  //OPERATORUL <                  //verifica daca apelantul este mai mic decat apelatul
    Bon operator+(Bon);
    operator float();                       //OPERATOR CAST
    char operator[](int);                      //OPERATOR INDEXARE

    //destructor

    ~Medicament(){
        if (this-> nume != NULL)
            delete[] this -> nume;
    }
};

//Constructori
Medicament::Medicament() : numarPastile(0), pret(0), fractie(0), idRaft('X'){                       //constructorul fara parametrii
    nume = new char[strlen("Denumire") + 1];
    strcpy(nume, "Denumire");
}
Medicament::Medicament(char* nume, int numarPastile, float pret, bool fractie, char idRaft) : numarPastile(numarPastile), pret(pret), fractie(fractie), idRaft(idRaft){  //constructorul cu toti parametrii
    this->nume = new char[strlen(nume) + 1];
    strcpy(this->nume, nume);
}
Medicament::Medicament(int numarPastile, float pret, bool fractie) : numarPastile(numarPastile), pret(pret), fractie(fractie), idRaft('X'){     //constructor cu parametrii variabili 1

    this->nume = new char[strlen("Default") + 1];
    strcpy(this->nume, "Default");
}
Medicament::Medicament(char *nume, char idRaft) : numarPastile(0), pret(0), fractie(0), idRaft(idRaft) {    //constructor cu parametrii variabili 2
    this->nume = new char[strlen(nume) + 1];
    strcpy(this->nume, nume);
}
Medicament::Medicament(const Medicament &obj) : pret(obj.pret), numarPastile(obj.numarPastile), fractie(obj.fractie), idRaft(obj.idRaft){   //Copy constructer

    this->nume = new char[strlen(obj.nume) + 1];
    strcpy(this->nume, obj.nume);
}

//setters
void Medicament::setnume(const char* nume){

    if (this -> nume != NULL)
        delete[] this-> nume;
    this -> nume = new char[strlen(nume)+1];
    strcpy(this -> nume, nume);
}
void Medicament::setpret( float pret){
    this -> pret = pret;
}
void Medicament::setnumarpastile( int numarPastile){
    this -> numarPastile = numarPastile;
}
void Medicament::setfractie(bool fractie){
    this -> fractie = fractie;
}
void Medicament::setidRaft( char idRaft){
    this -> idRaft = idRaft;
}

//getters
const char* Medicament::getnume(){
    return this-> nume;
}
const float Medicament::getpret(){
    return this -> pret;
}
const int Medicament::getnumarPastile(){
    return this -> numarPastile;
}
const bool Medicament::getfractie(){
    return this -> fractie;
}
const char Medicament::getidRaft(){
    return this -> idRaft;
}

//Supraincarcarea operatorilor

bool Medicament::operator==(const Medicament &obj) {        //OPERATORUL ==                 //Testeaza daca 2 obiecte de tip Medicament sunt identice

    if( this -> pret != obj.pret)
        return 0;
    if( this -> fractie != obj.fractie)
        return 0;
    if( this -> idRaft != obj.idRaft)
        return 0;
    if( this -> numarPastile != obj.numarPastile)
        return 0;
    if ( strcmp(this -> nume, obj.nume)!=0)
        return 0;

    return 1;

}
int Medicament::operator+(const Medicament& obj){           //OPERATORUL +  //Returneaza suma preturilor din 2 medicamente

    return this -> pret + obj.pret;
}
int Medicament::operator-(const Medicament& obj){       //OPERATORUL -  //Returneaza diferenta preturilor din 2 medicamente


    if (this -> pret > obj.pret)
        return this -> pret - obj.pret;
    else  return obj.pret - this -> pret;
}
Medicament& Medicament::operator++(){       //OPERATORUL ++ Inainte         //Incrementeaza pretul


    this -> pret ++;
    return *this;

}
Medicament Medicament::operator++(int){     //OPERATORUL ++ POST         //Incrementeaza pretul dupa

    Medicament copie = *this;

    this -> pret ++;

    return copie;

}
Medicament Medicament::operator=(const Medicament &obj){        //OPERATORUL =

    if( this -> nume != NULL)
        delete[]this-> nume;

    this->nume = new char[strlen(obj.nume) + 1];
    strcpy(this->nume, obj.nume);
    this->numarPastile = obj.numarPastile;
    this->pret = obj.pret;
    this->fractie = obj.fractie;
    this->idRaft = obj.idRaft;

    return *this;
}
bool Medicament::operator<(const Medicament &obj){      //OPERATORUL <              //verifica daca apelantul este mai mic decat apelatul


    if(this -> pret < obj.pret)
        return 1;
    else return 0;

}
Medicament::operator float(){                           //OPERATORUL CAST
    return this -> pret;
}


char Medicament::operator[] (int index){                             //OPERATORUL DE INDEXARE
    if(index >=0 && index < strlen(this -> nume))
        return this -> nume[index];
    else throw runtime_error("Index Invalid");
}

ostream& operator<<(ostream &out, const Medicament &obj){
    out << endl;
    out << "Nume medicament: " << obj.nume << endl;
    out << "Pret: " << obj.pret << endl;
    out << "Numar de pastile: " << obj.numarPastile << endl;
    out << "Id raft: " << obj.idRaft << endl;
    out << "Fractie: ";
    if(obj.fractie == 0)
        out << "Nu";
    else out << "Da";
    out << endl;
    return out;
}
istream &operator>> (istream &in, Medicament &obj ){
    string fr;
    cout << "Nume medicament: ";
    in >> obj.nume;
    cout << "Pret: ";
    in >> obj.pret;
    cout << "Numar de pastile: ";
    in >> obj.numarPastile;
    cout << "Id raft: " ;
    in >> obj.idRaft;
    cout << "Fractie: ";
    cin >> fr;
    if(fr == "Da")
        obj.fractie = 1;
    else obj.fractie = 0;

    return in;
}

class Pacient {

private:
    string nume;
    string prenume;
    string cnp;
    int varsta;
    int numarMedicamente;



public:
    friend ostream &operator<<(ostream &, const Pacient &);
    friend istream &operator>>(istream &, Pacient &);

//CONSTRUCTORI

    Pacient();                                                                              //constructorul fara parametrii
    Pacient(string, string, string, int, int);     //constructorul cu toti parametrii
    Pacient(string, string);                                                   //constructorul cu parametrii variabili
    Pacient(string, string, string, int);                           //constructorul cu parametrii variabili
    Pacient(const Pacient &);                                                            //copy constructer

    //setters
    void setnume(string);
    void setprenume(string);
    void setcnp(string);
    void setvarsta(int);
    void setnumarMedicamete(int);

    //getters
    string getnume();
    string getprenume();
    string getcnp();
    int getvarsta();
    int getnumarMedicamente();

    //Supraincarcarea operatorilor
    bool operator==(const Pacient &);                   //OPERATORUL ==                 //Testeaza daca 2 obiecte de tip Pacient sunt identice
    int operator+(int);                                 //OPERATORUL +                  //Returneaza suma preturilor din 2 Paciente
    int operator-(int);                                 //OPERATORUL -                  //Returneaza diferenta preturilor din 2 Paciente
    Pacient& operator++();                              //OPERATORUL ++ Inainte         //Incrementeaza pretul
    Pacient operator++(int);                            //OPERATORUL ++ POST            //Incrementeaza pretul dupa
    Pacient operator=(const Pacient &obj);              //OPERATORUL =
    bool operator<(const Pacient &obj);                 //OPERATORUL <                  //verifica daca apelantul este mai mic decat apelatul
    operator string();                                  //OPERATORUL CAST
    char operator[] (int);                              //OPERATORUL []
    ~Pacient(){}                                         //destructor
};


//CONSTRUCTORI
Pacient::Pacient() : nume("nume"), prenume("prenume"), cnp("cnp"), varsta(0), numarMedicamente(0){} //constructorul fara parametrii
Pacient::Pacient(string nume, string prenume, string cnp, int varsta, int numarMedicamente) : nume(nume), prenume(prenume), cnp(cnp), varsta(varsta), numarMedicamente(numarMedicamente){}//constructorul cu toti parametrii
Pacient::Pacient(string nume, string prenume) : nume(nume), prenume(prenume), cnp("cnp"), varsta(0), numarMedicamente(0) {} //constructor cu parametrii variabili 1
Pacient::Pacient(string nume, string prenume, string cnp, int varsta) : nume(nume), prenume(prenume), cnp(cnp), varsta(varsta), numarMedicamente(0){} //constructor cu parametrii variabili 2
Pacient::Pacient(const Pacient &obj) : nume(obj.nume), prenume(obj.prenume), cnp(obj.cnp), varsta(obj.varsta), numarMedicamente(obj.numarMedicamente){} //Copy constructer

//setters
void Pacient::setnume(string nume){

    this -> nume = nume;
}
void Pacient::setprenume(string prenume){
    this -> prenume = prenume;
}
void Pacient::setcnp(string cnp){
    this ->  cnp = cnp;
}
void Pacient::setvarsta(int varsta){
    this -> varsta = varsta;
}
void Pacient::setnumarMedicamete(int numarMedicamente){
    this -> numarMedicamente = numarMedicamente;
};

//getters
string Pacient::getnume(){
    return this -> nume;
}
string Pacient::getprenume(){
    return this -> prenume;
}
string Pacient::getcnp(){
    return this -> cnp;
}
int Pacient::getvarsta(){
    return this -> varsta;
}
int Pacient::getnumarMedicamente(){
    return this -> numarMedicamente;
}

//Supraincarcarea operatorilor
bool Pacient::operator==(const Pacient &obj) {          //OPERATORUL ==                 //Testeaza daca 2 obiecte de tip Pacient sunt identice

    if( this -> nume != obj.nume)
        return 0;
    if( this -> prenume != obj.prenume)
        return 0;
    if( this -> cnp != obj.cnp)
        return 0;
    if( this -> varsta != obj.varsta)
        return 0;
    if( this -> numarMedicamente != obj.numarMedicamente)
        return 0;
    return 1;

}
int Pacient::operator+(int in_plus){        //OPERATORUL +  //Returneaza suma preturilor din 2 Paciente


    return this -> numarMedicamente = this -> numarMedicamente + in_plus;
}
int Pacient::operator-(int de_scazut){      //OPERATORUL -  //Returneaza diferenta preturilor din 2 Paciente


    return this -> numarMedicamente - de_scazut;
}
Pacient& Pacient::operator++(){     //OPERATORUL ++ Inainte         //Incrementeaza pretul


    this -> numarMedicamente ++;
    return *this;

}
Pacient Pacient::operator++(int){       //OPERATORUL ++ POST        //Incrementeaza pretul dupa

    Pacient copie = *this;

    this -> numarMedicamente ++;

    return copie;

}
Pacient Pacient::operator=(const Pacient &obj){             //OPERATORUL =

    this -> nume = obj.nume;
    this -> prenume = obj.prenume;
    this -> cnp = obj.cnp;
    this -> varsta = obj.varsta;
    this -> numarMedicamente = obj.numarMedicamente;

    return *this;
}
bool Pacient::operator<(const Pacient &obj){        //OPERATORUL <              //verifica daca apelantul este mai mic decat apelatul


    if(this -> varsta < obj.varsta)
        return 1;
    else return 0;

}
Pacient::operator string(){
    return this -> cnp;
}

char Pacient::operator[] (int index){                             //OPERATORUL DE INDEXARE
    if(index >=0 && index < this -> nume.size())
        return this -> nume[index];
    else throw runtime_error("Index Invalid");
}


ostream& operator<<(ostream &out, const Pacient &obj){      //OPERATORUL DE AFISARE
    out << endl;
    out << "Nume pacient: " << obj.nume << endl;
    out << "Prenume pacient: " << obj.prenume << endl;
    out << "CNP: " << obj.cnp << endl;
    out << "Varsta: " <<obj.varsta << endl;
    out << "Numar medicamente: " << obj.numarMedicamente;
    return out;
}
istream &operator>> (istream &in, Pacient &obj ){       //OPERATORUL DE CITIRE

    string fr;
    cout << "Nume Pacient: ";
    in >> obj.nume;
    cout << "Prenume Pacient: ";
    in >> obj.prenume;
    cout << "CNP: ";
    in >> obj.cnp;
    cout << "Varsta: " ;
    in >> obj.varsta;
    return in;
}

//Class Bon

class Bon{

    static int idBon;
    int numarBon;
    vector <string> arrayMedicamente;
    vector <float> preturi;
    double pretFinal;


public:

    friend ostream &operator<<(ostream &, const Bon &);
    friend istream &operator>>(istream &, Bon &);
    friend Bon Medicament::operator+(Bon);

//CONSTRUCTORI

    Bon();                                  //constructorul fara parametrii
    Bon(int, vector<string>, vector<float>, double); //constructorul cu toti parametrii
    Bon(int, vector<string>, vector<float>);        //constructor cu parametrii variati 1
    Bon(int);                          //constructor cu parametrii variati 2
    Bon(const Bon &);                       //Copy constructer

    //setters

    void setpreturi(vector<float>);
    void setarrayMedicamente(vector<string>);
    void setnumarBon(int);
    void setpretFinal(double);

    //getters
    const int getnumarBon();
    const double getpretFinal();
    const vector<string> getarrayMedicamente();
    const vector<float> getpreturi();

    //Supraincarcarea operatorilor
    bool operator==(const Bon &);            //OPERATORUL ==                 //Testeaza daca 2 obiecte de tip bon au aceleasi medicamente pe ele, ignorand daca numarul de bon e diferit
    int operator+(const Bon& );              //OPERATORUL +  //Returneaza suma preturilor din 2 Bone
    int operator-(const Bon& );              //OPERATORUL -  //Returneaza diferenta preturilor din 2 Bone
    Bon& operator++();                       //OPERATORUL ++ Inainte         //Incrementeaza pretul
    Bon operator++(int);                     //OPERATORUL ++ POST
    Bon& operator=(const Bon &);              //OPERATORUL =
    bool operator<(const Bon &);             //OPERATORUL <              //verifica daca apelantul este mai mic decat apelatul
    Bon& operator+(Medicament);
    operator double();                         //OPERATORUL CAST
    string operator[](int);                    //OPERATORUL []
    //destructor

    ~Bon(){
    }
};

//Constructori
Bon::Bon():numarBon(idBon++),pretFinal(0),preturi(),arrayMedicamente(){}//constructorul fara parametrii
Bon::Bon(int numarBon, vector<string> arrayMedicamente, vector<float> preturi, double pretFinal) : numarBon(numarBon),pretFinal(pretFinal),preturi(preturi),arrayMedicamente(arrayMedicamente){}//constructorul cu toti parametrii
Bon::Bon(int numarBon,  vector<string> arrayMedicamente, vector<float> preturi) : numarBon(numarBon), pretFinal(0),preturi(preturi),arrayMedicamente(arrayMedicamente){}     //constructor cu parametrii variabili 1
Bon::Bon(int numarBon) : numarBon(numarBon), pretFinal(0), preturi(),arrayMedicamente() {}//constructor cu parametrii variabili 2
Bon::Bon(const Bon &obj) : pretFinal(obj.pretFinal), numarBon(obj.numarBon),preturi(obj.preturi),arrayMedicamente(obj.arrayMedicamente) {}       //copy constructor

//setters
void Bon::setpreturi( vector<float> preturi){
    this -> preturi = preturi;

}
void Bon::setarrayMedicamente(vector<string> arrayMedicamente){
    this -> arrayMedicamente = arrayMedicamente;
}
void Bon::setnumarBon( int numarBon){
    this -> numarBon = numarBon;
}
void Bon::setpretFinal(double pretFinal){
    this -> pretFinal = pretFinal;
}

//getters

const int Bon::getnumarBon(){
    return this -> numarBon;
}
const double Bon::getpretFinal(){
    return this -> pretFinal;
}
const vector<string> Bon::getarrayMedicamente(){
    return this -> arrayMedicamente;
}
const vector<float> Bon::getpreturi(){
    return this -> preturi;
}

//Supraincarcarea operatorilor
bool Bon::operator==(const Bon &obj) {      //Supraincarcarea operatorului ==

    if( this -> pretFinal != obj.pretFinal)
        return 0;
    if(this -> arrayMedicamente != obj.arrayMedicamente)
        return 0;

    if(this -> preturi != obj.preturi)
        return 0;
    return 1;
}
int  Bon::operator+(const Bon& obj){  //OPERATORUL +

    return this -> pretFinal + obj.pretFinal;
}
int  Bon::operator-(const Bon& obj){      //OPERATORUL -

    if (this -> pretFinal > obj.pretFinal)
        return this -> pretFinal - obj.pretFinal;
    else  return obj.pretFinal - this -> pretFinal;
}
Bon& Bon::operator++(){  //OPERATORUL ++ Inainte

    this -> pretFinal ++;
    return *this;

}
Bon  Bon::operator++(int){     //OPERATORUL ++ POST

    Bon copie = *this;

    this -> pretFinal ++;

    return copie;

}
Bon&  Bon::operator=(const Bon &obj){  //OPERATORUL =

    this -> preturi = obj.preturi;
    this -> arrayMedicamente = obj.arrayMedicamente;
    this -> pretFinal = obj.pretFinal;
    this -> numarBon = obj.numarBon;

    return *this;
}
bool Bon::operator<(const Bon &obj){ //OPERATORUL <

    if(this -> pretFinal < obj.pretFinal)
        return 1;
    else return 0;

}
Bon::operator double(){     //OPERATORUL CAST

    return this -> pretFinal;

}
string Bon::operator[] (int index){                             //OPERATORUL DE INDEXARE
    if(index >=0 && index < this -> arrayMedicamente.size())
        return this -> arrayMedicamente[index];
    else throw runtime_error("Index Invalid");
}

int Bon::idBon = 1124;

ostream& operator<<(ostream &out, const Bon &obj){
    out << endl;
    out << "Numar bon: " << obj.numarBon << endl;
    out << "        Medicamente: " << endl;

    for(int i = 0; i < obj.arrayMedicamente.size(); i++) {
        string dots(50 - obj.arrayMedicamente[i].size(), '.');
        out << obj.arrayMedicamente[i] << dots << obj.preturi[i] << endl;
    }
    out << "Pret final: " << obj.pretFinal << endl;
    out << endl;
    return out;
}
istream &operator>> (istream &in, Bon &obj ){
    cout << "Numar bon: "; in >> obj.numarBon;
    int size;
    string temp;
    float temp2;
    cout << "Numar de medicamente"; in >> size;
    for(int i = 0; i < size; i++){

        cout << "Nume Medicament: "; in >> temp;
        obj.arrayMedicamente.push_back(temp);
        cout << "Pret: "; in >> temp2;
        obj.preturi.push_back(temp2);
        obj.pretFinal += temp2;
    }
    return in;
}


class Farmacie{

    const string adresa;
    string* arrayMedicamente;
    float *preturi;
    int size;
    int angajati;
    static string lantFarmacie;

public:

    friend ostream &operator<<(ostream &, const Farmacie &);
    friend istream &operator>>(istream &, Farmacie &);

//CONSTRUCTORI

    Farmacie();                                  //constructorul fara parametrii
    Farmacie(string, string*, float*, int, int); //constructorul cu toti parametrii
    Farmacie(string);        //constructor cu parametrii variati 1
    Farmacie(string*, float*, int);                          //constructor cu parametrii variati 2
    Farmacie(const Farmacie &);                       //Copy constructer

    //setters

    void setpreturi(float*, int);
    void setarrayMedicamente(string*, int);
    void setangajati(int);

    //getters
    const int getsize();
    const string getadresa();
    const string* getarrayMedicamente();
    const float* getpreturi();
    const int getangajati();

    //Supraincarcarea operatorilor
    bool operator==(const Farmacie &);            //OPERATORUL ==                 //Testeaza daca 2 obiecte de tip Farmacie au aceleasi medicamente pe ele, ignorand daca numarul de Farmacie e diferit
    Farmacie operator=(const Farmacie &);         //OPERATORUL =
    int  operator+(const Farmacie& obj);          //OPERATORUL +
    int  operator-(const Farmacie&);              //OPERATORUL -
    Farmacie& operator++();                       //OPERATORUL ++ INAINTE
    Farmacie  operator++(int);                    //OPERATORUL ++ DUPA
    operator int();                               //OPERATORUL CAST
    string operator[](int);                       //OPERATORUL DE INDEXARE
    //destructor

    ~Farmacie(){
        if (this-> arrayMedicamente != NULL)
            delete[] this -> arrayMedicamente;
        if( this -> preturi!=NULL)
            delete[]this->preturi;
    }


};

//Constructori
Farmacie::Farmacie():adresa("adresa"),size(0),preturi(NULL),arrayMedicamente(NULL), angajati(0){}//constructorul fara parametrii
Farmacie::Farmacie(string adresa, string* arrayMedicamente, float* preturi, int size, int angajati) : adresa(adresa),size(size), angajati(angajati){//constructorul cu toti parametrii
    this->preturi = new float[size];
    for(int i = 0; i < size; i++)
        this->preturi[i] = preturi[i];
    this -> arrayMedicamente = new string[size];
    for(int i = 0; i < size; i++)
        this -> arrayMedicamente[i] = arrayMedicamente[i];
}
Farmacie::Farmacie(string adresa) : adresa(adresa),size(0),preturi(NULL),arrayMedicamente(NULL), angajati(0) {}     //constructor cu parametrii variabili 1

Farmacie :: Farmacie(string* arrayMedicamente, float* preturi, int size) : adresa("adresa"), size(size), angajati(0){//constructor cu parametrii variabili 2
    this->preturi = new float[size];
    for(int i = 0; i < size; i++)
        this->preturi[i] = preturi[i];
    this -> arrayMedicamente = new string[size];
    for(int i = 0; i < size; i++)
        this -> arrayMedicamente[i] = arrayMedicamente[i];
}
Farmacie::Farmacie(const Farmacie &obj) : size(obj.size), adresa(obj.adresa){       //copy constructor
    this->preturi = new float[size];
    for(int i = 0; i < size; i++)
        this -> preturi[i] = obj.preturi[i];

    this -> arrayMedicamente = new string[size];
    for(int i = 0; i < size; i++)
        this -> arrayMedicamente[i] = obj.arrayMedicamente[i];
}

//setters
void Farmacie::setpreturi( float* preturi, int size){

    if (this -> preturi != NULL)
        delete[] this-> preturi;
    this->size = size;
    this -> preturi = new float[this->size];
    for(int i = 0; i < size; i++)
        this -> preturi[i] = preturi[i];
}
void Farmacie::setarrayMedicamente( string* arrayMedicamente, int size){
    if(this->arrayMedicamente!=NULL)
        delete [] this -> arrayMedicamente;

    this -> arrayMedicamente = new string[size+1];
    for(int i = 0; i < size; i++)
        this -> arrayMedicamente[i] = arrayMedicamente[i];
}
void Farmacie::setangajati(int angajati){
    this -> angajati = angajati;
}


//getters
const int Farmacie::getsize(){
    return this-> size;
}
const string Farmacie::getadresa(){
    return this -> adresa;
}
const string* Farmacie::getarrayMedicamente(){
    return this -> arrayMedicamente;
}
const float* Farmacie::getpreturi(){
    return this -> preturi;
}
const int Farmacie::getangajati(){
    return this -> angajati;
}
//Supraincarcarea operatorilor
bool Farmacie::operator==(const Farmacie &obj) {      //Supraincarcarea operatorului ==         //verifica daca stocul este la fel in 2 farmacii diferite

    if( this -> size != obj.size)
        return 0;
    for(int i = 0; i < size; i++)
        if(this -> arrayMedicamente[i] != obj.arrayMedicamente[i])
            return 0;
    for(int i = 0; i < size; i++)
        if(this -> preturi[i] != obj.preturi[i])
            return 0;
    return 1;
}

Farmacie  Farmacie::operator=(const Farmacie &obj){  //OPERATORUL =

    if( this -> preturi != NULL)
        delete[]this-> preturi;
    if( this -> arrayMedicamente != NULL)
        delete[]this->arrayMedicamente;

    this -> size = obj.size;

    this->preturi = new float[size];
    for(int i = 0; i < size; i++)
        this -> preturi[i] = obj.preturi[i];

    this -> arrayMedicamente = new string[size];
    for(int i = 0; i < size; i++)
        this -> arrayMedicamente[i] = obj.arrayMedicamente[i];

    return *this;
}
int  Farmacie::operator+(const Farmacie& obj){  //OPERATORUL +

    return this -> angajati + obj.angajati;
}
int  Farmacie::operator-(const Farmacie& obj){      //OPERATORUL -

    if (this -> angajati > obj.angajati)
        return this -> angajati - obj.angajati;
    else  return obj.angajati - this -> angajati;
}
Farmacie& Farmacie::operator++(){  //OPERATORUL ++ Inainte

    this -> angajati ++;
    return *this;

}
Farmacie  Farmacie::operator++(int){     //OPERATORUL ++ POST

    Farmacie copie = *this;

    this -> angajati ++;

    return copie;

}
Farmacie::operator int(){                                           //OPERATORUL CAST
    return this -> angajati;
}

string Farmacie::operator[] (int index){                             //OPERATORUL DE INDEXARE
    if(index >=0 && index < this -> size)
        return this -> arrayMedicamente[index];
    else throw runtime_error("Index Invalid");
}
string Farmacie :: lantFarmacie = "Catena";

ostream& operator<<(ostream &out, const Farmacie &obj){
    out << endl;
    out << "Farmacia de la adresa: " << obj.adresa << endl;
    out << "Numar de angajati: " << obj.angajati << endl;
    out << "Medicamente: " << endl;
    for(int i = 0; i < obj.size; i++)
        out << obj.arrayMedicamente[i] << "           " << obj.preturi[i] << " lei" << endl;
    return out;
}
istream &operator>> (istream &in, Farmacie &obj ){
    cout << "Farmacia de la adresa: " << obj.adresa << endl;
    cout << "Numar de angajati: " ; in >>  obj.angajati;
    cout << endl <<"Numar de medicamente: "; in >> obj.size;

    if (obj.arrayMedicamente != NULL)
        delete[] obj.arrayMedicamente;
    if (obj.preturi != NULL)
        delete[] obj.preturi;

    obj.preturi = new float[obj.size];
    obj. arrayMedicamente = new string[obj.size];

    for(int i = 0; i< obj.size; i++){

        cout << "Nume Medicament: "; in >> obj.arrayMedicamente[i];
        cout << "Pret: "; in >> obj.preturi[i];
    }
    return in;
}

//De aici incepe functionalitate

Bon& Bon::operator+(Medicament medicament) {

    //Pune numele intr-o variabila temporara pe care o pune la capatul araryului de nume
    string temp = medicament.getnume();
    this -> arrayMedicamente.push_back(temp);

    // Adauga pretul la finalul arrayului de preturi
    this -> preturi.push_back(medicament.getpret());

    // Calculeaza noul pret final
    this -> pretFinal += medicament.getpret();

    return *this;
}


Bon Medicament::operator+(Bon bonvechi) {

    //Pune numele intr-o variabila temporara pe care o pune la capatul araryului de nume
    string temp = this -> nume;
    bonvechi.arrayMedicamente.push_back(temp);

    // Adauga pretul la finalul arrayului de preturi
    bonvechi.preturi.push_back(this -> pret);

    // Calculeaza noul pret final
    bonvechi.pretFinal += this -> pret;

    return bonvechi;
}



int main(){


//declar medicamentele
    Medicament nurofen("Nurofen", 24, 36.99, 0, 'N');
    Medicament acc("ACC", 10, 37.49, 0, 'A');
    Medicament hepatosuport("Hepatosuport", 100, 41.49, 0, 'H');
    Medicament defumoxan("Defumoxan", 100, 113.99, 0, 'D');
    Medicament strepsils("Strepsils", 24, 20.99, 1, 'S');
    Medicament tantumverde("Tantum Verde", 20, 23.99, 0, 'T');
    Medicament sinupret("Sinupret", 20, 46.99, 1, 'S');
    Medicament paracetamol("Paracetamol", 20, 2.99, 0, 'P');
    Medicament nospa("No-Spa", 24, 15.99, 1, 'N');
    Medicament coldrex("Coldrex", 16, 19.99, 1, 'C');
    vector <Medicament> vectorMedicamente = {nurofen, acc, hepatosuport, defumoxan, strepsils, tantumverde, sinupret, paracetamol, nospa, coldrex};

// fac 2 arrayuri pentru fiecare locatie. Un array va avea numele medicamentelor, celalalt va avea pretul lor;
    string* medicamenteLaculUrsului;
    medicamenteLaculUrsului = new string[5];
    float* preturiLaculUrsului;
    preturiLaculUrsului = new float[5];

    string * medicamenteFloaredeCais;
    medicamenteFloaredeCais = new string[5];
    float* preturiFloaredeCais;
    preturiFloaredeCais = new float[5];

//copiez din vectorul de medicamente inventarul pentru fiecare farmacie
    for(int i = 0; i<10; i++){
        if(i<5) {
            medicamenteFloaredeCais[i] = vectorMedicamente[i].getnume();
            preturiFloaredeCais[i] = vectorMedicamente[i].getpret();
        }
        else {
            medicamenteLaculUrsului[i - 5] = vectorMedicamente[i].getnume();
            preturiLaculUrsului[i - 5] = vectorMedicamente[i].getpret();
        }
    }
//construiesc farmaciile

    Farmacie laculUrsului("Strada Lacul Ursului nr. 18", medicamenteLaculUrsului, preturiLaculUrsului, 5, 6);
    Farmacie floaredeCais("Strada Floare de Cais nr. 5" , medicamenteFloaredeCais, preturiFloaredeCais , 5, 10);
//start menu

    cout << "Buna ziua! Va rugam sa completati datele dumneavoasta: " << endl;
    Pacient pacient1;
    cin >> pacient1;
    system("cls");
    cout << "Bine ati venit! Selectati adresa farmaciei dorite: " << endl;
    cout << "1) Strada Lacul Ursului nr. 18" << endl;
    cout << "2) Strada Floare de Cais nr. 5" << endl;
    int select;
    cin >> select;
    switch (select) {
        case 1: {
            Bon bon1;
            vector <string> medicamenteSelectate;
            int ok = 1;
            while(ok){
                system("cls");
                cout << "Stocul farmaciei: " << endl;
                for (int i = 0; i < laculUrsului.getsize(); i++) {
                    string dots(50-laculUrsului.getarrayMedicamente()[i].size(), '.');
                    cout << i+1 << ") " << laculUrsului.getarrayMedicamente()[i] << dots << laculUrsului.getpreturi()[i] << " lei" << endl;
                }

                cout << "Alegeti medicamentul: ";
                cin >> select;
                system("cls");
                if(select > 0 && select < 6){
                    medicamenteSelectate.push_back(vectorMedicamente[5+select-1].getnume());
                    bon1 = bon1 + vectorMedicamente[5+select-1];
                    cout << "Medicamentul a fost adaugat in cos. Pretul total este de: " << bon1.getpretFinal() << " lei" << endl;
                    cout << "Doriti sa adaugati alt medicament?" << endl << "1) Da" << endl << "2) Nu" << endl;
                    int select2;
                    cin >> select2;




                    if(select2 == 2) {
                        system("cls");
                        cout << "Pacient: " << pacient1.getnume() << " " << pacient1.getprenume();
                        cout << bon1;
                        cout << "Multumim! O zi buna!";
                        ok = 0;
                    }

                }
                else{
                    cout << "Selectie invalida. Apasati (1) pentru a va intoarce la meniul de selectare" << endl;
                    cin >> select;
                }


            }

            break;
        }

        case 2: {


            Bon bon1;
            vector <string> medicamenteSelectate;
            int ok = 1;
            while(ok){
                system("cls");
                cout << "Stocul farmaciei: " << endl;
                for (int i = 0; i < floaredeCais.getsize(); i++) {
                    string dots(50-floaredeCais.getarrayMedicamente()[i].size(), '.');
                    cout << i+1 << ")" << floaredeCais.getarrayMedicamente()[i] << dots << floaredeCais.getpreturi()[i] << " lei" << endl;
                }
                cout << "Alegeti medicamentul: ";
                cin >> select;
                system("cls");
                if(select > 0 && select < 6){
                    medicamenteSelectate.push_back(vectorMedicamente[select-1].getnume());
                    bon1 = bon1 + vectorMedicamente[select-1];
                    cout << "Medicamentul a fost adaugat in cos. Pretul total este de: " << bon1.getpretFinal() << " lei" << endl;
                    cout << "Doriti sa adaugati alt medicament?" << endl << "1) Da" << endl << "2) Nu" << endl;
                    int select2;
                    cin >> select2;

                    if(select2 == 2) {
                        system("cls");
                        cout << "Pacient: " << pacient1.getnume() << " " << pacient1.getprenume();
                        cout << bon1;
                        cout << "Multumim! O zi buna!";
                        ok = 0;
                    }

                }
                else{
                    cout << "Selectie invalida. Alegeti un medicament din lista: ";
                    cin >> select;
                }


            }

            break;
        }
    }


    //Se elibereaza memoria alocata
    delete[] medicamenteLaculUrsului;
    delete[] preturiLaculUrsului;
    delete[] medicamenteFloaredeCais;
    delete[] preturiFloaredeCais;
    return 0;
}