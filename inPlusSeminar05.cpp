//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <cstring>
//
//using namespace std;

// 1. Definim mai întâi clasa Jucator
//class Jucator
//{
//private:
//	char* nume;
//	float salariu;
//	int varsta;
//public:
//	 Constructor fără parametri
//	Jucator()
//	{
//		this->nume = new char[strlen("Messi") + 1];
//		strcpy(this->nume, "Messi");
//		this->salariu = 1000.5f;
//		this->varsta = 41;
//	}
//
//	 Constructor cu parametri
//	Jucator(const char* nume, float salariu, int varsta)
//	{
//		this->nume = new char[strlen(nume) + 1];
//		strcpy(this->nume, nume);
//		this->salariu = salariu;
//		this->varsta = varsta;
//	}
//
//	 Constructor de copiere
//	Jucator(const Jucator& j)
//	{
//		this->nume = new char[strlen(j.nume) + 1];
//		strcpy(this->nume, j.nume);
//		this->salariu = j.salariu;
//		this->varsta = j.varsta;
//	}
//
//	 Operatorul =
//	Jucator& operator=(const Jucator& j)
//	{
//		if (this != &j)
//		{
//			delete[] this->nume;
//			this->nume = new char[strlen(j.nume) + 1];
//			strcpy(this->nume, j.nume);
//			this->salariu = j.salariu;
//			this->varsta = j.varsta;
//		}
//		return *this;
//	}
//
//	 Destructor
//	~Jucator()
//	{
//		delete[] this->nume;
//	}
//
//	 Getteri (Atenție la const de la sfârșit!)
//	float getSalariu() const { return this->salariu; }
//	int getVarsta() const { return this->varsta; }
//	const char* getNume() const { return this->nume; }
//};
//
// 2. Apoi definim clasa EchipaDeFotbal care folosește Jucator
//class EchipaDeFotbal
//{
//private:
//	char* denumire;
//	int nrJucatori;
//	Jucator* jucatori; // Relație has-a
//	bool activ;
//	const int anInfintare;
//	static float primaMeci;
//
//public:
//	 1. Constructor fără parametri
//	EchipaDeFotbal() : anInfintare(1947)
//	{
//		this->denumire = new char[strlen("FCSB") + 1];
//		strcpy(this->denumire, "FCSB");
//		this->nrJucatori = 0;
//		this->jucatori = nullptr;
//		this->activ = true;
//	}
//
//	 2. Constructor cu parametri (5 parametri)
//	EchipaDeFotbal(const char* denumire, int nrJucatori, const Jucator* jucatori, bool activ, int anInfintare) : anInfintare(anInfintare)
//	{
//		this->denumire = new char[strlen(denumire) + 1];
//		strcpy(this->denumire, denumire);
//
//		this->nrJucatori = nrJucatori;
//		this->activ = activ;
//
//		if (nrJucatori > 0 && jucatori != nullptr)
//		{
//			this->jucatori = new Jucator[nrJucatori];
//			for (int i = 0; i < nrJucatori; i++)
//				this->jucatori[i] = jucatori[i];
//		}
//		else
//		{
//			this->nrJucatori = 0;
//			this->jucatori = nullptr;
//		}
//	}
//
//	 3. Constructor de copiere
//	EchipaDeFotbal(const EchipaDeFotbal& e) : anInfintare(e.anInfintare)
//	{
//		this->denumire = new char[strlen(e.denumire) + 1];
//		strcpy(this->denumire, e.denumire);
//
//		this->nrJucatori = e.nrJucatori;
//		this->activ = e.activ;
//
//		if (e.nrJucatori > 0 && e.jucatori != nullptr)
//		{
//			this->jucatori = new Jucator[e.nrJucatori];
//			for (int i = 0; i < e.nrJucatori; i++)
//				this->jucatori[i] = e.jucatori[i];
//		}
//		else
//		{
//			this->nrJucatori = 0;
//			this->jucatori = nullptr;
//		}
//	}
//
//	 4. Operatorul = (Atribuire)
//	EchipaDeFotbal& operator=(const EchipaDeFotbal& e)
//	{
//		if (this != &e)
//		{
//			delete[] this->denumire;
//			this->denumire = new char[strlen(e.denumire) + 1];
//			strcpy(this->denumire, e.denumire);
//
//			this->activ = e.activ;
//			this->nrJucatori = e.nrJucatori;
//
//			delete[] this->jucatori;
//			if (e.jucatori != nullptr && e.nrJucatori > 0)
//			{
//				this->jucatori = new Jucator[this->nrJucatori];
//				for (int i = 0; i < this->nrJucatori; i++)
//					this->jucatori[i] = e.jucatori[i];
//			}
//			else
//			{
//				this->jucatori = nullptr;
//				this->nrJucatori = 0;
//			}
//		}
//		return *this;
//	}
//
//	 5. Destructorul
//	~EchipaDeFotbal()
//	{
//		delete[] denumire;
//		delete[] jucatori;
//	}
//
//	 Supraîncărcare operator de indexare []
//	Jucator& operator[](int index)
//	{
//		if (index >= 0 && index < this->nrJucatori) {
//			return this->jucatori[index];
//		}
//		throw "Index out of bounds!";
//	}
//
//	 Supraîncărcare operator +
//	float operator+(float bonusExtra)
//	{
//		float totalSalarii = 0;
//		for (int i = 0; i < this->nrJucatori; i++)
//		{
//			totalSalarii += this->jucatori[i].getSalariu();
//		}
//		return totalSalarii + bonusExtra;
//	}
//
//	 Operator friend <<
//	friend ostream& operator<<(ostream& out, const EchipaDeFotbal& e)
//	{
//		out << "Echipa: " << (e.denumire ? e.denumire : "N/A") << ", An infiintare: " << e.anInfintare
//			<< ", Nr jucatori: " << e.nrJucatori << endl;
//		out << "Lista de jucatori: " << endl;
//		for (int i = 0; i < e.nrJucatori; i++)
//		{
//			out << " - " << e.jucatori[i].getNume() << " | Salariu: " << e.jucatori[i].getSalariu()
//				<< " | Varsta: " << e.jucatori[i].getVarsta() << endl;
//		}
//		return out;
//	}
//
//	 Metodă de afișare clasică
//	void afisare()
//	{
//		cout << "Denumirea echipei: " << this->denumire << endl;
//		cout << "Nr. jucatori: " << this->nrJucatori << endl;
//		cout << "Echipa activa: " << (this->activ ? "DA" : "NU") << endl;
//		cout << "An infiintare: " << this->anInfintare << endl;
//	}
//
//	 Calcul fond salarii (Corectat: adunăm salariul, nu obiectul Jucator)
//	float suma()
//	{
//		if (this->jucatori == nullptr || this->nrJucatori == 0) return 0;
//		float s = 0;
//		for (int i = 0; i < nrJucatori; i++)
//			s += this->jucatori[i].getSalariu();
//		return s;
//	}
//
//	 Getteri
//	const char* getDenumire() const { return this->denumire; }
//	int getNrJucatori() const { return this->nrJucatori; }
//	bool getActiv() const { return this->activ; }
//	int getAnInfiintare() const { return this->anInfintare; }
//
//	static float getPrimaMeci() { return primaMeci; }
//	static void setPrimaMeci(float valoare) { primaMeci = valoare; }
//};
//
// Inițializarea membrului static
//float EchipaDeFotbal::primaMeci = 1000.0f;
//
//void main() {
//	Jucator j1("Coman", 4000.0f, 25);
//	Jucator j2("Tanase", 5000.0f, 28);
//	Jucator listaJucatori[2] = { j1, j2 };
//
//	 Apel corect cu 5 parametri: denumire, nrJucatori, vector, activ, anInfiintare
//	EchipaDeFotbal echipa("FCSB", 2, listaJucatori, true, 1947);
//
//	cout << echipa << endl;
//
//	 2. Testăm operatorul [] (indexare)
//	cout << "Jucatorul de pe pozitia 0 este: " << echipa[0].getNume() << endl;
//
//	 3. Testăm operatorul +
//	cout << "Fond salarii + bonus de 1000: " << echipa + 1000.0f << endl;
//	cout << "Fond total salarii simplu (metoda suma): " << echipa.suma() << endl;
//}

//EXERCITIUL 2:
//Creează un program în C++ care conține două clase: Pacient și Spital
//
//class Pacient
//{
//	private:
//	char *nume;
//	int varsta;
//	float greutate;
//	public:
//	//constructor fara parametri
//	Pacient()
//	{
//		this->nume=new char[strlen("Ana")+1];
//		strcpy(this->nume,"Ana");
//		this->varsta=22;
//		this->greutate=55.5f;
//
//	}
//	//constructor cu parametri
//	Pacient(const char* nume, int varsta, float greutate)
//	{
//		this->nume=new char[strlen(nume)+1];
//		strcpy(this->nume,nume);
//		this->varsta=varsta;
//		this->greutate=greutate;
//	}
//	//constructor de copiere
//	Pacient(const Pacient& p)
//	{
//		this->nume=new char[strlen(p.nume)+1];
//		strcpy(this->nume,p.nume);
//		this->varsta=p.varsta;
//		this->greutate=p.greutate;
//	}
//	//operatorul egal
//	Pacient& operator=(const Pacient& p)
//	{
//		if (this != &p)
//		{
//			this->nume=new char[strlen(p.nume)+1];
//			strcpy(this->nume,p.nume);
//			this->varsta=p.varsta;
//			this->greutate=p.greutate;
//		}
//		return *this;
//	}
//	//destructor
//	~Pacient()
//	{
//		delete[] this->nume;
//	}
//	//getteri
//	const char* getNume() const{return this->nume;}
//	int getVarsta() const {return this->varsta;}
//	float getGreutate() const {return this->greutate;}
//};
//class Spital
//{	private:
//
//	char *denumire;
//	int nrPacienti;
//	Pacient *pacienti;//vectorul alocat dinamic de obiectul de tip pacient-relatia de has a
//	const int codUnic;
//	static int bugetTotal; //membrul static car e comun spitalelor
//
//	public:
//		static int getBugetTotal() {
//			return bugetTotal;}
//	//constructor fara parametri
//	Spital():codUnic(codUnic)
//	{	this->denumire=new char[strlen("spital")+1];
//		strcpy(this->denumire,"spital");
//		this->nrPacienti=0;
//		this->pacienti=nullptr;
//	}
//	//constructor cu paraametri
//	Spital(const char *denumire, int nrPacienti, const Pacient*pacienti,int codUnic) :codUnic(codUnic)
//	{
//		this->denumire = new char[strlen(denumire) + 1];
//		strcpy(this->denumire, "denumire");
//		this->nrPacienti = nrPacienti;
//		if (nrPacienti > 0 && pacienti != nullptr)
//		{
//			this->pacienti=new Pacient[nrPacienti];
//			for(int i=0;i<nrPacienti;i++){this->pacienti[i]=pacienti[i];}
//
//		}
//		else
//		{ 
//		 this->pacienti=nullptr;
//		 this->nrPacienti=0;
//		}
//	}
//	//constructor de copiere
//	Spital(const Spital& s) :codUnic(s.codUnic)
//	{
//		this->denumire=new char[strlen(s.denumire)+1];
//		strcpy(this->denumire,s.denumire);
//		this->nrPacienti=s.nrPacienti;
//		this->pacienti=new Pacient[nrPacienti];
//		if (s.nrPacienti > 0 && s.pacienti != nullptr)
//		{
//			for (int i = 0;i < s.nrPacienti;i++)
//			{
//				this->pacienti[i]=s.pacienti[i];
//			}
//		}
//		else
//		{
//			this->pacienti=nullptr;
//			this->nrPacienti=0;
//		}
//
//	}
//	//operatorul =
//	Spital& operator=(const Spital& s)
//	{
//		if (this != &s)
//		{	delete[] this->denumire;
//			this->denumire=new char[strlen(s.denumire)+1];
//			strcpy(this->denumire,s.denumire);
//			this->nrPacienti=s.nrPacienti;
//			delete[] this->pacienti;
//			this->pacienti=new Pacient[this->nrPacienti];
//			if(s.pacienti!=nullptr && s.nrPacienti>0)
//			{
//			for(int i=0;i<this->nrPacienti;i++){this->pacienti[i]=s.pacienti[i]; }
//			}
//			else
//			{
//			this->pacienti=nullptr;
//			this->nrPacienti=0;
//			}
//		}
//		return *this;
//	}
//	//destructor
//	~Spital()
//	{
//		delete[] denumire;
//		delete[] pacienti;
//	}
//	//metoda: calc greutatea medie a pacientilor
//	float calculeazaGreutateaMedie() const
//	{ if(this->nrPacienti==0 || this->pacienti==nullptr)return 0;
//	float suma=0;
//	for (int i = 0;i < this->nrPacienti;i++)
//	{
//		suma+=this->pacienti[i].getGreutate();
//	}
//	return suma/this->nrPacienti;
//	}
//	//supraincarcare operatorului de indexare []
//	Pacient& operator[](int index)
//	{
//		if(index>=0 && index < this->nrPacienti){return this->pacienti[index]; }
//		throw "Index în afara limitelor!";
//	}
//	//supraincarcarea operatorului << (friend) pt afisare
//	friend ostream& operator<<(ostream& out, const Spital& s)
//	{
//	out<<" spitalul: "<<(s.denumire ? s.denumire:"N/A")<<", cod unic "<<s.codUnic<<", buget total "<<bugetTotal<< " ron "<<", nr pacienti "<<s.nrPacienti<<endl;
//	out<<"lista pacienti internati: "<<endl;
//	for (int i = 0;i < s.nrPacienti;i++)
//	{
//		out<<" - "<<s.pacienti[i].getNume()<<" varsta: "<< s.pacienti[i].getVarsta()<<"greutate "<< s.pacienti[i].getGreutate() << endl;
//	}
//		return out;
//
//	}
//	//functie friend care modifica o data privata
//	friend void actualizareBuget(Spital &s,int bonus);
//	
//};
////init membru static in afara clasei
//int Spital::bugetTotal=50000;
////implementam fct friend
//void actualizareBuget(Spital& s, int bonus)
//{
//	Spital::bugetTotal+=bonus;
//}
//void main()
//{
//	//creez pacientii
//	Pacient p1("Ion Popescu", 45, 82.5f);
//	Pacient p2("Maria Ionesc", 29, 62.5f);
//	Pacient p3("Andrei Vasile", 52, 82.5f);
//	Pacient listaPacienti[3]={p1,p2,p3};
//	//cream un spital
//	Spital spital("Spitalul Universitar", 3, listaPacienti, 2045);
//	//operator de supraincarcare
//	cout<<"afisare spital initial:"<<endl;
//	cout<< spital<<endl;
//	cout<<"greutatea medie a pacientilor este :"<<spital.calculeazaGreutateaMedie()<<" kg"<<endl;
//	cout<<"pacientul de pe pozitia 1 este :"<< spital[1].getNume()<<endl;
//	actualizareBuget(spital,15000);
//	cout<<"dupa acyualizarea bugetului ="<<endl;
//	cout<<"noul buget total: "<< Spital::getBugetTotal() <<"ron"<<endl;
//}

//exercitiul 3: bilet si zbor
//class Bilet
//{
//	private:
//	char *destinatie;
//	float pret;
//	int clasaBilet;
//	public:
//	//constructor cu parametri:
//	Bilet()
//	{ this->destinatie=new char[strlen("Paris")+1];
//	strcpy(this->destinatie,"Paris");
//	this->pret=200;
//	this->clasaBilet=1;
//	}
//	//constructori cu parametri
//	Bilet(const char* destinatie, float pret, int clasaBilet)
//	{
//		this->destinatie=new char[strlen(destinatie)+1];
//		strcpy(this->destinatie,destinatie);
//		this->pret=pret;
//		this->clasaBilet=clasaBilet;
//	}
//	//constructor de copiere
//	Bilet(const Bilet& b)
//	{ 
//		this->destinatie=new char[strlen(b.destinatie)+1];
//		strcpy(this->destinatie,b.destinatie);
//		this->pret=b.pret;
//		this->clasaBilet=b.clasaBilet;
//
//	}
//	//operator =
//	Bilet& operator=(Bilet& b)
//	{
//		if (this != &b)
//		{	if(this->destinatie!=nullptr){delete[] this->destinatie;}
//			this->destinatie = new char[strlen(b.destinatie) + 1];
//			strcpy(this->destinatie, b.destinatie);
//			this->pret = b.pret;
//			this->clasaBilet = b.clasaBilet;
//		}
//		return *this;
//	}
//	//destructor
//	~Bilet()
//	{
//		delete[] this->destinatie;
//	}
//	//getteri
//	const char* getDestinatie() const
//	{
//		return this->destinatie;
//	}
//	float getPret() const
//	{
//		return this->pret;
//	}
//	int getClasaBilet()
//	{
//		return this->clasaBilet;
//	}
//	void setPret(float pretNou)
//	{
//		if (pretNou > 0) {
//			this->pret = pretNou;
//		}
//	}
//
//	void setClasaBilet(int clasaNoua)
//	{
//		this->clasaBilet = clasaNoua;
//	}
//
//	void setDestinatie(const char* destinatieNoua)
//	{
//		if (destinatieNoua != nullptr) {
//			delete[] this->destinatie; 
//			this->destinatie = new char[strlen(destinatieNoua) + 1];
//			strcpy(this->destinatie, destinatieNoua);
//		}
//	}
//};
//class Zbor
//{	private:
//	char *companie;
//	int nrBilete;
//	Bilet *bilete;
//	const int idZbor;
//	static int nrZboruriTotale;
//	public:
//		static int getNrZboruriTotale() 
//		{return nrZboruriTotale;}
//	//constructor fara parametri
//	Zbor():idZbor(1)
//	{ this->companie=new char[strlen("Wizz")+1];
//		strcpy(this->companie,"Wizz");
//	  this->nrBilete=0;
//	  this->bilete=nullptr;
//	  nrZboruriTotale++;
//	}
//	//constructor cu parametri
//	Zbor(const char* companie, int nrBilete, Bilet* bilete, int idZbor) :idZbor(idZbor)
//	{
//		this->companie=new char[strlen(companie)+1];
//		strcpy(this->companie,companie);
//		this->nrBilete=nrBilete;
//		this->bilete = new Bilet[nrBilete];
//		if(nrBilete!=0 && bilete != nullptr)
//		{
//			for(int i=0;i<this->nrBilete;i++)
//			{ this->bilete[i]=bilete[i]; }
//		}
//		else
//		{
//			this->nrBilete=0;
//			this->bilete=nullptr;
//		}
//		nrZboruriTotale++;
//	}
//	//constructor de copiere
//	Zbor(const Zbor& z):idZbor(z.idZbor)
//	{
//		this->companie=new char[strlen(z.companie)+1];
//		strcpy(this->companie,z.companie);
//		this->nrBilete=z.nrBilete;
//		bilete= new Bilet[nrBilete];
//		if (z.nrBilete != 0 && z.bilete != nullptr)
//		{
//			for(int i=0;i<nrBilete;i++){this->bilete[i]=z.bilete[i]; }
//		}
//		else
//		{
//			this->nrBilete=0;
//			this->bilete=nullptr;
//		}
//		nrZboruriTotale++;
//	}
//	//operator =
//	Zbor& operator=(Zbor& z)
//	{
//		if (this != &z)
//		{
//			if(this->companie!=nullptr){delete[] this->companie;}
//			if (this->bilete != nullptr) { delete[] this->bilete; }
//
//			this->companie=new char[strlen(z.companie)+1];
//			strcpy(this->companie,z.companie);
//			this->nrBilete=z.nrBilete;
//			bilete=new Bilet[nrBilete];
//			if (z.nrBilete != 0 && z.bilete != nullptr)
//			{ for(int i=0;i<nrBilete;i++){this->bilete[i]=z.bilete[i]; }
//			 
//			}
//			else
//			{
//				this->bilete=nullptr;
//				this->nrBilete=0;
//			}
//		} return *this;
//	}
//	//destructor
//	~Zbor()
//	{
//		delete[] this->companie;
//		delete[] this->bilete;
//	}
//	//o metoda care returneaza suma preturilor tuturor biletelor din zbor
//	float calculeazaIncasariTotale() const
//	{
//		if(this->nrBilete==0 || this->bilete ==nullptr)return 0;
//		float suma = 0;
//		for(int i=0;i<this->nrBilete;i++){suma+=this->bilete[i].getPret(); }
//		return suma;
//	}
//	//operatorul de indexare[]
//	Bilet &operator[](int index)
//	{ 
//		if(index>=0 && index< this->nrBilete){ return this->bilete[index];}
//
//	}
//	// operatorul <<
//	friend ostream& operator<<(ostream& out, const Zbor& z)
//	{ out<<" numele companiei : "<<z.companie<<", numarul de bilete este: "<<z.nrBilete<<", biletele sunt: "<<endl;
//		for(int i=0;i<z.nrBilete;i++){out<<"destinatie: "<<z.bilete[i].getDestinatie()<<" pret: "<<z.bilete[i].getPret()<<" clasa bilet: "<< z.bilete[i].getClasaBilet()<<endl;}
//		return out;
//	}
//	void SetPret(float pret)
//	{
//	}
//	friend void aplicaDiscount(Zbor &z, float procent);
//
//};
//int Zbor::nrZboruriTotale = 0;
//void aplicaDiscount(Zbor& z, float procent)
//{
//	for (int i = 0;i < z.nrBilete;i++)
//	{
//		float pretVechi=z.bilete[i].getPret();
//		float pretNou=pretVechi-(pretVechi*procent/100);
//		z.bilete[i].getPret();
//	}
//}
//
//void main()
//{	
//	Bilet b1("Londra", 500.0, 1);
//	Bilet b2("Madrid", 350.0, 2);
//	Bilet lista[2] = { b1, b2 };
//
//	Zbor z1("Tarom", 2, lista, 105);
//	cout << z1 << endl;
//	cout << "Incasari totale: " << z1.calculeazaIncasariTotale() << " RON" << endl;
//
//}
//curs 6 cu supraincarcare de operatori
