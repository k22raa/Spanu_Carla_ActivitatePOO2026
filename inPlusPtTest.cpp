#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
////class Telefon
////{
////	private:
////	float rezolutie;
////	float memorie;
////	string model;
////	char* producator;
////	float pret;
////	int nrAplicatii;
////	float* memorieAplicatii;
////	const int id;
////	static int contor;
////	public:
////		Telefon() :id(contor++)
////		{
////			this->rezolutie=5.3;
////			this->memorie=128;
////			this->model="Iphone 17";
////			this->producator=new char[strlen("Aplle")+1];
////			strcpy(this->producator,"Apple");
////			this->pret=4000;
////			this->nrAplicatii=5;
////			this->memorieAplicatii=new float[this->nrAplicatii];
////			this->memorieAplicatii[0] = 2;
////			this->memorieAplicatii[1] = 3;
////			this->memorieAplicatii[2] = 1.4;
////			this->memorieAplicatii[3] = 1.6;
////			this->memorieAplicatii[4] = 2.4;
////
////		}
////		Telefon(float rezolutie, float memorie) :id(contor++)
////		{
////			this->rezolutie = rezolutie;
////			this->memorie = memorie;
////			this->model = "Iphone 17";
////			this->producator = new char[strlen("Aplle") + 1];
////			strcpy(this->producator, "Apple");
////			this->pret = 4000;
////			this->nrAplicatii = 5;
////			this->memorieAplicatii = new float[this->nrAplicatii];
////			this->memorieAplicatii[0] = 2;
////			this->memorieAplicatii[1] = 3;
////			this->memorieAplicatii[2] = 1.4;
////			this->memorieAplicatii[3] = 1.6;
////			this->memorieAplicatii[4] = 2.4;
////		}
////		Telefon(const Telefon& t):id(t.contor++)
////		{
////			this->rezolutie = t.rezolutie;
////			this->memorie = t.memorie;
////			this->model =t.model;
////			this->producator = new char[strlen(t.producator) + 1];
////			strcpy(this->producator, t.producator);
////			this->pret = t.pret;
////			this->nrAplicatii = t.nrAplicatii;
////			this->memorieAplicatii = new float[t.nrAplicatii];
////			if(t.nrAplicatii>0 && t.memorieAplicatii!=nullptr)
////				{for (int i = 0;i < t.nrAplicatii;i++)
////				{
////					this->memorieAplicatii[i]=t.memorieAplicatii[i];
////				}}
////		}
////		~Telefon()
////		{
////			delete[] this->producator;
////			delete[] this->memorieAplicatii;
////		}
////		//operatori: 
////		Telefon& operator=(const Telefon& t)
////		{
////			if (this != &t)
////			{ 
////				this->rezolutie = t.rezolutie;
////				this->memorie = t.memorie;
////				this->model = t.model;
////				if (this->producator != nullptr) { delete[] this->producator; }
////				this->producator = new char[strlen(t.producator) + 1];
////				strcpy(this->producator, t.producator);
////				this->pret = t.pret;
////				this->nrAplicatii = t.nrAplicatii;
////				if (this->memorieAplicatii != nullptr) { delete[] this->memorieAplicatii; }
////				this->memorieAplicatii = new float[t.nrAplicatii];
////				if (t.nrAplicatii > 0 && t.memorieAplicatii != nullptr)
////				{
////					for (int i = 0;i < t.nrAplicatii;i++)
////					{
////						this->memorieAplicatii[i] = t.memorieAplicatii[i];
////					}
////				}
////
////			}
////			return *this;
////		}
////		//operator + sa adaugam o valoare
////		//Telefon operator+(int valoare)
////		//{
////		//	Telefon aux=*this;
////		//	aux.pret=this->pret+valoare;
////		//	return aux;
////		//}
////		friend Telefon operator+(int ,Telefon);
////		float getPret() { return this->pret; }
////		void setPret(float pret);
////		int getNrAplicatii(){return this->nrAplicatii;}
////		char* getProducator(){return this->producator;}
////		void SetProducator(const char* producator)
////		{
////			delete[] this->producator;
////			this->producator=new char [strlen(producator)+1];
////			strcpy(this->producator,producator);
////		}
////		//operator +
////		Telefon operator+(const Telefon& t)
////		{
////			Telefon rez=*this;
////			rez.pret=this->pret+ t.pret;
////			return rez;
////
////		}
////		Telefon operator+(float crestere) const
////		{
////			Telefon rez=*this;
////			rez.pret=this->pret+crestere;
////			return rez;
////		}
////
////		friend Telefon operator+(float crestere,Telefon t) 
////		{ Telefon rez=t;
////		t.setPret(t.getPret() + crestere);
////		return t;
////		}
////		//operator de cast
////		explicit operator float()
////		{
////			float suma=0;
////			if (this->nrAplicatii > 0) {
////			for(int i=0;i<this->nrAplicatii;i++){
////				suma+=this->memorieAplicatii[i];}
////				return suma/this->nrAplicatii;
////			}
////			else return 0;
////		}
////		explicit operator int()
////		{
////			return this->nrAplicatii;
////		}
////		//pre decrementare
////		Telefon &operator--()
////		{
////			this->pret--;
////			return *this;
////		}
////		//post
////		Telefon operator--(int)
////		{
////			Telefon copie=*this;
////			this->pret--;
////			return copie;
////		}
////		//<<
////		friend ostream& operator<<(ostream& out, const Telefon& a)
////		{
////			out << "Id: " << a.id << endl
////				<< "Producator" << a.producator << endl
////				<< "Pret: " << a.pret << endl
////				<< "Memorie: " << a.memorie << endl
////				<< "Nr aplicatii : " << a.nrAplicatii << endl;
////			for (int i = 0;i < a.nrAplicatii;i++)out << a.memorieAplicatii[i] << ", ";
////			out << endl;
////			return out;
////
////		}
////		friend istream& operator >>(istream& in, Telefon& a)
////		{
////			cout<<"producator: ";
////			char buffer[100];
////			in>>buffer;
////			if(a.producator!=nullptr){delete[] a.producator; }
////			a.producator=new char[strlen(buffer)+1]; strcpy(a.producator,buffer);
////			strcpy(a.producator, buffer);
////			cout << "Pret: "; in >> a.pret;
////			cout << "memorie: "; in >> a.memorie;
////			cout << "nr aplicatii: "; in >> a.nrAplicatii;
////			if(a.memorieAplicatii!=nullptr){delete[] a.memorieAplicatii; }
////			a.memorieAplicatii=new float[a.nrAplicatii];
////			cout << "introdu memoria de aplicatii: ";
////			for (int i = 0;i < a.nrAplicatii;i++)
////			{
////				in >> a.memorieAplicatii[i];
////			}
////			return in;
////
////		}
////		//op fct retturneaza pret/nr aplicatii
////		float operator()()
////		{ 
////			if(this->nrAplicatii<=0){return 0;}
////			else
////			{ return this->pret/this->nrAplicatii;
////
////			}
////
////		}
////		float operator()(float TVA)
////		{
////			if (this->nrAplicatii > 0)
////			{
////				return (this->pret+this->pret*TVA)/this->nrAplicatii;
////			}
////			else return 0;
////
////		}
////		//primeasca un discount de 20%
////		float operator()(int discout)
////		{
////			if (this->nrAplicatii > 0)
////			{
////				return ((this->pret - discout/100.0 *this->pret)/100  ) / this->nrAplicatii;
////			}
////			else return 0;
////
////		}
////		//operator ==
////		bool operator==(Telefon t)
////		{
////			if(strcmp(this->producator,t.producator)!=0){return false;}
////			if (this->rezolutie != t.rezolutie) { return false; }
////			if (this->memorie != t.memorie) { return false; }
////			if (this->model != t.model) { return false; }
////			return true;
////		}
////
////
////
////
////};
////void main() {
////
////	Telefon t;
////	Telefon t2(6.3, 512);
////	Telefon t3 = t;
////	float memorieMedie;
////	memorieMedie = (float)t;
////	t3 = --t;
////	t3 = t--;
////	//cin >> t;
////	cout << t;
////	cout << "pretul per aplicatie= " << t3() << endl;
////	cout << "pret cu tot cu tva per aplicatie " << t3(0.21f) << endl;
////	cout << "pretul cu discount per aplicatie " << t3(21) << endl;
////	if (t == t2)cout << "telefoane asemanatoare" << endl;
////	else cout << "telefoane diferite" << endl;
////////folosind atribute friend
//////Telefon operator+(int valoare, Telefon t)
//////{
//////	Telefon aux=t;
//////	aux.pret=t.pret+valoare;
//////	return aux;
//////}
////////getteri si stteri
////
////class Prajitura 
////{ private:
////	char *denumire;
////	float pret;
////	int cantitate;
////	bool dePost;
////	int nrIngrediente;
////	string *ingrediente;
////	const int id;
////	static int contor;
////  public:
////  friend class Student;
////  Prajitura() :id(contor++)
////  {
////	  this->denumire=new char[strlen("tiramisu")+1];
////	  strcpy(this->denumire,"tiramisu");
////	  this->pret=55;
////	  this->cantitate=4;
////	  this->dePost=true;
////	  this->nrIngrediente=3;
////	  this->ingrediente = new string[this->nrIngrediente];
////	  this->ingrediente[0]="piscoturi";
////	  this->ingrediente[1]="mascarpone";
////	  this->ingrediente[2]="cafea";
////  }
////  Prajitura(const char* denumire, float pret) :id(contor++)
////  {
////	  this->denumire=new char[strlen(denumire)+1];
////	  strcpy(this->denumire,denumire);
////	  this->pret=pret;
////	  this->cantitate = 4;
////	  this->dePost = true;
////	  this->nrIngrediente = 3;
////	  this->ingrediente = new string[this->nrIngrediente];
////	  this->ingrediente[0] = "piscoturi";
////	  this->ingrediente[1] = "mascarpone";
////	  this->ingrediente[2] = "cafea";
////  }
////  Prajitura(const Prajitura& p):id(p.contor++)
////  {	
////	
////	this->denumire=new char[strlen(p.denumire)+1];
////	strcpy(this->denumire, p.denumire);
////	this->pret=p.pret;
////	this->cantitate=p.cantitate;
////	this->dePost=p.dePost;
////	this->nrIngrediente=p.nrIngrediente;
////	this->ingrediente= new string[nrIngrediente];
////	this->ingrediente[0]=p.ingrediente[0];
////	this->ingrediente[1] = p.ingrediente[1];
////	this->ingrediente[2]=p.ingrediente[2];
////
////  }
////  ~Prajitura()
////  {
////	  delete[] this->ingrediente;
////	  delete[] this->denumire;
////  }
////  //op =
////  Prajitura& operator=(const Prajitura& p)
////  {
////	  if (this != &p)
////	  {	  if(this->denumire != nullptr){delete[] this->denumire; }
////		  this->denumire = new char[strlen(p.denumire) + 1];
////		  strcpy(this->denumire, p.denumire);
////		  this->pret = p.pret;
////		  this->cantitate = p.cantitate;
////		  this->dePost = p.dePost;
////		  this->nrIngrediente = p.nrIngrediente;
////		  if(this->ingrediente!= nullptr){delete[] this->ingrediente; }
////		  this->ingrediente = new string[nrIngrediente];
////		  this->ingrediente[0] = p.ingrediente[0];
////		  this->ingrediente[1] = p.ingrediente[1];
////		  this->ingrediente[2] = p.ingrediente[2];
////
////	  }
////	  return *this;
////  }
//// //getteri si stteri
//// char * getDenumire(){return this->denumire;}
//// float getPret(){return this->pret;}
//// int getCantitate(){return this->cantitate;}
//// int getNrIngrediente(){return this->nrIngrediente;}
//// static int getContor(){ return contor;}
//// void setPret(float pret);
//// //operatori
//// //op+
//// Prajitura operator+(const Prajitura& p)
//// {
////	 Prajitura rez=*this;
////	 rez.pret=this->pret+p.pret;
////	 rez.cantitate=this->cantitate+p.cantitate;
////	 return rez;
//// }
//// Prajitura operator+(float valoare) const
//// {
////	 Prajitura rez=*this;
////	rez.pret=this->pret+valoare;
////	rez.cantitate=this->cantitate+valoare;
////	return rez;
//// }
//// friend Prajitura operator+(float valoare, Prajitura p)
//// { Prajitura rez=p;
////	p.setPret(p.getPret()+valoare);
////	return rez;
//// }
//// string& operator[](int poz)
//// {
////	 if(poz>0 && poz< this->nrIngrediente)return this->ingrediente[poz];
//// }
//// explicit operator float()
//// {
////	 return this->pret;
//// }
//// explicit operator int()
//// {
////	 return this->cantitate;
//// }
//// float operator()()
//// {
////	 return this->costMediuGram();
//// }
//// float operator()(float TVA)
//// {
////	 return (this->pret +(TVA*this->pret))/this->cantitate;
//// }
//// float operator()(int discount)
//// {
////	return (this->pret - (discount/100.0)*this->pret)/this->cantitate;
//// }
//// bool operator==(Prajitura prajitura)
////	 	{
////	 		if (strcmp(this->denumire, prajitura.denumire) != 0)
////	 			return false;
////	 		if (this->cantitate != prajitura.cantitate)
////	 			return false;
////	 		if (this->dePost != prajitura.dePost)
////	 			return false;
////	 		if (this->nrIngrediente != prajitura.nrIngrediente)
////	 			return false;
////	 		return true;
//// }
////
//// Prajitura& operator-=(const Prajitura& p)
//// {
////	 if(this->pret > p.pret){this->pret=this->pret -p.pret;}
////	 else
////	 {
////		 this->pret =0;
////	 }
////	 return *this;
//// }
//// Prajitura operator +=(string ingredient)
//// {
////	 string *aux= new string[this->nrIngrediente+1];
////	 for (int i = 0;i < this->nrIngrediente;i++)
////	 {
////		 aux[i]=this->ingrediente[i];
////	 }
////	 aux[this->nrIngrediente]=ingredient;
////	 delete[] this->ingrediente;
////	 this->ingrediente=aux;
////	 this->nrIngrediente++;
////	 return *this;
////
//// }
//// void afisare()
//// {
////	 cout << "Denumire: " << this->denumire << endl;
////	 		cout << "Pret: " << this->pret << endl;
////	 		cout << "Cantitate: " << this->cantitate<< endl;
////	 		cout << "De Post: " << (this->dePost ? "DA" : "NU") << endl;
////	 		cout << "Nr ingrediente: " << this->nrIngrediente << endl;
////	 		cout << "Ingredientele sunt: ";
////	 		for (int i = 0;i < this->nrIngrediente;i++)
////	 		{
////	 			cout << this->ingrediente[i] << "; ";
////	 		}
////	 		cout << endl;
//// }
//// void modificareDenumire(const char* denumire)
//// {
////	 delete[] this->denumire;
////	 this->denumire=new char[strlen(denumire)+1];
////	 strcpy(this->denumire, denumire);
////
//// }
//// float costMediuGram()
//// {
////	if (this->cantitate == 0) {
////	 return 0;}
////	else {return this->pret / this->cantitate;}
//// }
////
////};
////int Prajitura::contor=100;
////float calculeazaCantitateaTotala(Prajitura* prajituri, int nrPrajituri)
////{
////	float greutate=0;
////	for (int i = 0;i < nrPrajituri;i++)
////	{
////		greutate+= prajituri[i].getCantitate();
////	}
////	return greutate;
////}
////float calculeazaPretPerGramIngredient(Prajitura p)
////{
////	if (p.getNrIngrediente() != 0)
////	{
////		return p.getPret()/p.getNrIngrediente();
////	}
////	return 0;
////}
////class Student
////{
////	private:
////	string nume;
////	Prajitura prajitura;
////	public:
////	Student()
////	{ this->nume="Alex";
////	}
////	Student(string nume, Prajitura p)
////	{
////		this->nume=nume;
////		this->prajitura =p;
////	}
////	string getNume(){return this->nume;}
////	Prajitura getPrajitura(){return this->prajitura;}
////	void setNume(string nume) 
////	{
////		this->nume=nume;
////	}
////	void setPrajitura(Prajitura p)
////	{
////		this->prajitura=p;
////	}
////	float calculeazaNrTotalDeCalorii(float caloriiPerGram)
////	{	float nrTotal=caloriiPerGram*this->prajitura.getCantitate();
////	return nrTotal;
////
////	}
////	void afiseazaMasa()
////	{ cout<<this->nume<<"mananca prajitura "<<this->prajitura.denumire<<endl;
////
////	}	
////};
////void main()
////{ Prajitura p;
////p.afisare();
////Prajitura::getContor();
////Prajitura p1("amandina",20.6);
////Student s1("cristian", p1);
////cout<<p[1]<<endl;
////p[1] = "frisca";
////cout<<p[1]<<endl;
////float pret;
////pret=(float)p1;
////int cantitate;
////cantitate=(int)p1;
////cout<<"cantitate= "<<cantitate<<endl;
////cout<<" pret per gram : "<<p1()<<endl;
////cout << "Pret cu TVA per gram: " << p1(0.21f) << endl;
////	cout << "Pret cu discount per gram: " << p1(10) << endl;
////	if (p == p1)
////		cout << "Prajituri egale";
////	else cout << "Prajiturile sunt diferite\n";
////	p -= p1;
////	cout << p.getPret();
////	p += "Faina";
////	cout << p[3];
////}
////class Telefon
////{
////	private:
////	float rezolutie;
////	float memorie;
////	string model;
////	char * producator;
////	float pret;
////	int nrAplicatii;
////	float * memorieAplicatii;
////	const int id;
////	static int contor;
////	public:
////	Telefon():id(contor++)
////	{
////		this->rezolutie=55;
////		this->memorie=128;
////		this->model="Iphone 16";
////		this->producator=new char[strlen("Iphone")+1];
////		strcpy(this->producator,"Iphone");
////		this->pret=4000;
////		this->nrAplicatii=2;
////		this->memorieAplicatii= new float[this->nrAplicatii];
////		this->memorieAplicatii[0]=4;
////		this->memorieAplicatii[1]=2;
////	
////	}
////	Telefon(float rezolutie, float memorie) :id(contor++)
////	{
////		this->rezolutie = rezolutie;
////		this->memorie = memorie;
////		this->model = "Iphone 16";
////		this->producator = new char[strlen("Iphone") + 1];
////		strcpy(this->producator, "Iphone");
////		this->pret = 4000;
////		this->nrAplicatii = 2;
////		this->memorieAplicatii = new float[this->nrAplicatii];
////		this->memorieAplicatii[0] = 4;
////		this->memorieAplicatii[1] = 2;
////
////	}
////	Telefon(const Telefon &t) :id(contor++)
////	{
////		this->rezolutie = t.rezolutie;
////		this->memorie = t.memorie;
////		this->model = t.model;
////		this->producator = new char[strlen(t.producator) + 1];
////		strcpy(this->producator, t.producator);
////		this->pret =t.pret;
////		this->nrAplicatii = t.nrAplicatii;
////		this->memorieAplicatii = new float[this->nrAplicatii];
////		if (t.memorieAplicatii != nullptr && t.nrAplicatii > 0)
////		{
////			for (int i = 0;i < t.nrAplicatii;i++)
////			{
////				this->memorieAplicatii[i]=t.memorieAplicatii[i];
////			}
////
////		}
////		else
////
////		{
////			this->memorieAplicatii=nullptr;
////			this->nrAplicatii=0;
////		}
////		
////	}
////	~Telefon()
////	{
////		delete[] this->memorieAplicatii;
////		delete[] this->producator;
////	}
////	Telefon& operator=(const Telefon& t)
////	{
////		if (this != &t)
////		{
////			this->rezolutie = t.rezolutie;
////			this->memorie = t.memorie;
////			this->model = t.model;
////			if(this->producator!= nullptr){delete[] this->producator; }
////			this->producator = new char[strlen(t.producator) + 1];
////			strcpy(this->producator, t.producator);
////			this->pret = t.pret;
////			this->nrAplicatii = t.nrAplicatii;
////			this->memorieAplicatii = new float[this->nrAplicatii];
////			if(this->memorieAplicatii!= nullptr){delete[] this->memorieAplicatii; }
////			if (t.memorieAplicatii != nullptr && t.nrAplicatii > 0)
////			{
////				for (int i = 0;i < t.nrAplicatii;i++)
////				{
////					this->memorieAplicatii[i] = t.memorieAplicatii[i];
////				}
////
////			}
////			else
////
////			{
////				this->memorieAplicatii = nullptr;
////				this->nrAplicatii = 0;
////			}
////
////		}
////		return *this;
////	}
////	float getPret(){return this->pret;}
////	void setPret(float pret);
////	char* getProducator(){return this->producator;}
////	void setProducator(char* producator)
////	{
////		delete[] this->producator;
////		this->producator=new char[strlen(producator)+1];
////		strcpy(this->producator, producator);
////	}
////		int getNrAplicatii()
////		{
////			return this->nrAplicatii;
////		}
////		Telefon operator+(const Telefon& t)
////		{
////			Telefon rez= *this;
////			rez.pret=this->pret+t.pret;
////			return rez;
////		}
////		Telefon operator+(float crestere)
////		{
////			Telefon rez=*this;
////			rez.pret=this->pret+crestere;
////		}
////		friend Telefon operator+(float crestere, Telefon t)
////		{
////			Telefon rez=t;
////			t.setPret(t.getPret()+crestere);
////			return t;
////		}
////		explicit operator float()
////		{
////			float suma=0;
////			if(this->nrAplicatii>0)
////			{
////				for (int i = 0;i < this->nrAplicatii;i++)
////				{
////					suma+=this->memorieAplicatii[i];
////				}
////				return suma/this->nrAplicatii;
////			}
////			else return 0;
////		}
////		explicit operator int()
////		{
////			return this->nrAplicatii;
////		}
////		//preincrementare
////		Telefon& operator++()
////		{
////			this->pret++;
////			return *this;
////		}
////		Telefon operator++(int)
////		{
////			Telefon rez=*this;
////			this->pret++;
////			return rez;
////		}
////		//<<
////		friend ostream& operator<<(ostream& out, const Telefon& actual)
////		{
////			out << "Id: " << actual.id << endl;
////			out << "Producator: " << actual.producator << endl;
////			out << "Pret: " << actual.pret << endl;
////			out << "Memorie: " << actual.memorie << endl;
////			out << "Nr de aplicatii: " << actual.nrAplicatii << endl;
////			out << "Memorie aplicatii: ";
////			for (int i = 0;i < actual.nrAplicatii - 1;i++)
////				out << actual.memorieAplicatii[i] << ", ";
////			out << actual.memorieAplicatii[actual.nrAplicatii - 1] << ".";
////			out << endl;
////			return out;
////
////		}
////		friend istream& operator>>(istream& in, Telefon& t)
////		{
////			cout<<"Producator: ";
////			char buffer[100];
////			in>>buffer;
////			if(t.producator){delete[] t.producator; }
////			t.producator= new char[strlen(buffer)+1];
////			strcpy(t.producator,buffer);
////			cout<<"pret: "; in>>t.pret;
////			cout<<"memorie: "; in>>t.memorie;
////			cout<<"nr aplicatii: ";in>>t.nrAplicatii;
////			if(t.memorieAplicatii){delete[] t.memorieAplicatii; }
////			t.memorieAplicatii=new float[t.nrAplicatii];
////			for (int i = 0;i < t.nrAplicatii;i++)
////			{
////				in>>t.memorieAplicatii[i];
////			}
////			return in;
////		}
////		float operator()()
////		{
////			if (this->nrAplicatii > 0)
////			{
////				return this->pret/this->nrAplicatii;
////			}
////			else return 0;
////		}
////		float operator()(float tva)
////		{
////			if (this->nrAplicatii > 0)
////			{
////				return (this->pret + this->pret*tva)/this->nrAplicatii;
////			}
////			else return 0;
////		}
////
////		float operator()(int discout)
////		{
////
////			if (this->nrAplicatii > 0)
////			{
////				return (this->pret - (discout/100.0*this->pret)) / this->nrAplicatii;
////			}
////			else return 0;
////		}
////		bool operator==(Telefon t)
////		{
////			if(strcmp(this->producator, t.producator)!=0) return false;
////			if (this->rezolutie != t.rezolutie) {
////				return false;
////			}
////			if (this->memorie != t.memorie) {
////				return false;
////			}
////			if (this->model != t.model) {
////				return false;
////			}
////
////			return true;
////
////		}
////		void afisare()
////		{
////			cout << "Rezolutie: " << this->rezolutie << "\n";
////			cout << "Memorie: " << this->memorie << "\n";
////			cout << "Model: " << this->model << "\n";
////			cout << "Producator: " << this->producator << "\n";
////			cout << "Pret: " << this->pret << "\n";
////			cout << "Numar aplicatii: " << this->nrAplicatii << "\n";
////			cout << "Memorie ocupata: ";
////			for (int i = 0; i < this->nrAplicatii; i++)
////				cout << this->memorieAplicatii[i] << "; ";
////			cout << endl;
////		}
////		float calculeazaMemoriaOcupata()
////		{
////			float suma=0;
////			if (this->nrAplicatii > 0)
////			{
////				for (int i = 0;i < this->nrAplicatii;i++)
////				{
////					suma+=this->memorieAplicatii[i];
////				}
////				return suma;
////			}
////			else return 0;
////		}
////		float calcMmemorieLibera()
////		{
////			return this->memorie-calculeazaMemoriaOcupata();
////		}
////		void modificareProducator(char * prod)
////		{
////			delete[] this->producator;
////			this->producator=new char[strlen(prod)+1];
////			strcpy(this->producator,prod);
////
////		}
////		friend class Student;
////
////	};
////	int Telefon::contor=100;
////	float calcularePretTotal(Telefon* v, int nrTlf)
////	{ float s=0;
////		for (int i = 0;i < nrTlf;i++)
////		{
////			s+=v[i].getPret();
////		}
////		return s;
////	}
////	float calcMemorieDisponibila(Telefon* g, int nrTlf)
////	{	float s=0;
////		for (int i = 0;i < nrTlf;i++)
////		{	s+=g[i].calcMmemorieLibera();
////
////		}
////		return s;
////	}
////	float calculeazaPretPerAplicatie(Telefon x)
////	{
////		if (x.getNrAplicatii() > 0)
////		{
////			return x.getPret()/x.getNrAplicatii();
////		}
////		else return 0;
////	}
////	class Student
////	{private:
////		string nume;
////		Telefon telefon;
////		public:
////		Student()
////		{ this->nume="Andrei";
////
////		}
////		Student(string nume, Telefon t)
////		{
////			this->nume = "Andrei";
////			this->telefon=t;
////
////		}
////		string getNume(){return this->nume;}
////		Telefon getTelefon() {
////			return this->telefon;
////		}
////		void setNume(string nume) {
////			this->nume=nume;
////		}
////		void setTelefon(const Telefon& t)
////		{
////			this->telefon=t;
////		}
////		bool poateInstalaAplicatia(float memorieNecesara)
////		{
////			return(memorieNecesara <= this->telefon.calcMmemorieLibera());
////		}
////		void afisareInformatii() {
////			cout << "\n" << this->nume << " are un telefon cu " << this->telefon.memorie << " Giga memorie" << endl;
////		}
////	};
////	void main()
////	{	Telefon t;
////		Telefon t2(6.3,512);
////		Telefon t3=t;
////		float a=6.3;
////		int b=(int)a;
////		float memorieMedie;
////		memorieMedie=(float)t;
////		t3=t++;
////		t3=++t;
////		cin>>t;
////		cout<<t;
////		cout << "Pret per aplicatii: " << t3() << endl;
////		cout << " Pret cu tva per aplicatie: " << t3(0.21f) << endl;
////		cout << " Pret cu discount per aplicatie: " << t3(21);
////
////		if (t == t2) {
////			cout << endl << "Telefoane asemanatoare." << endl;
////		}
////		else {
////			cout << endl << "Telefoane diferite." << endl;
////		}
////
////
////	}
////class Prajitura
////{
////	private:
////	char *denumire;
////	float pret;
////	int cantitate;
////	bool dePost;
////	int nrIngrediente;
////	string * ingrediente;
////	const int id;
////	static int contor;
////	public:
////	friend class Student;
////	Prajitura() :id(contor++)
////	{
////		this->denumire = new char[strlen("Tiramisu") + 1];
////				strcpy(this->denumire, "Tiramisu");
////				this->pret = 15;
////				this->cantitate = 250;
////				this->dePost = true;
////				this->nrIngrediente = 3;
////				this->ingrediente = new string[this->nrIngrediente];
////				this->ingrediente[0] = "piscoturi";
////				this->ingrediente[1] = "vanilie";
////				this->ingrediente[2] = "cafea";
////	}
////	Prajitura(const char* denumire, float pret) :id(contor++)
////	{
////		this->denumire = new char[strlen(denumire) + 1];
////		strcpy(this->denumire, denumire);
////		this->pret =pret;
////		this->cantitate = 250;
////		this->dePost = true;
////		this->nrIngrediente = 3;
////		this->ingrediente = new string[this->nrIngrediente];
////		this->ingrediente[0] = "piscoturi";
////		this->ingrediente[1] = "vanilie";
////		this->ingrediente[2] = "cafea";
////
////	}
////	Prajitura(const Prajitura& p):id(p.contor++)
////	{
////		this->denumire = new char[strlen(p.denumire) + 1];
////		strcpy(this->denumire, denumire);
////		this->pret = p.pret;
////		this->cantitate = p.cantitate;
////		this->dePost = p.dePost;
////		this->nrIngrediente = p.nrIngrediente;
////		this->ingrediente = new string[this->nrIngrediente];
////		if (p.ingrediente > 0 && p.ingrediente != nullptr)
////		{
////			for (int i = 0;i < p.nrIngrediente;i++)
////			{ this->ingrediente[i]=p.ingrediente[i];
////					
////			}
////		}
////		else
////		{
////			this->ingrediente=nullptr;
////			this->nrIngrediente=0;
////		}
////	}
////	~Prajitura()
////	{
////		delete[] this->denumire;
////		delete[] this->ingrediente;
////	}
////	Prajitura& operator=(const Prajitura& p)
////	{
////		if (this != &p)
////		{	if(this->denumire){delete[] this->denumire; }
////			this->denumire = new char[strlen(p.denumire) + 1];
////			strcpy(this->denumire, denumire);
////			this->pret = p.pret;
////			this->cantitate = p.cantitate;
////			this->dePost = p.dePost;
////			this->nrIngrediente = p.nrIngrediente;
////			if(this->ingrediente){delete[] this->ingrediente; }
////			this->ingrediente = new string[this->nrIngrediente];
////			if (p.ingrediente > 0 && p.ingrediente != nullptr)
////			{
////				for (int i = 0;i < p.nrIngrediente;i++)
////				{
////					this->ingrediente[i] = p.ingrediente[i];
////
////				}
////			}
////			else
////			{
////				this->ingrediente = nullptr;
////				this->nrIngrediente = 0;
////			}
////		}
////		return *this;
////	}
////	//getteri si setteri
////	int getCantitate() {
////				return this->cantitate;
////			}
////			int getNrIngrediente() {
////				return this->nrIngrediente;
////			}
////			float getPret() {
////				return this->pret;
////			}
////			void setPret(float pret);
////			static int getContor() {
////				return contor;
////			}
////			Prajitura operator+(const Prajitura& p)
////			{ Prajitura rez=*this;
////			rez.pret=this->pret+p.pret;
////			return rez;
////
////			}
////			Prajitura operator+(float crestere)
////			{
////				Prajitura rez=*this;
////				rez.pret=this->pret + crestere;
////				return rez;
////			}
////			friend Prajitura operator+(float crestere, Prajitura p)
////			{
////				Prajitura rez=p;
////				p.setPret(p.getPret()+ crestere);
////				return rez;
////			}
////			string& operator[](int index)
////			{
////				if (index > 0 && index < this->nrIngrediente)
////				{
////					return this->ingrediente[index];
////				}
////			}
////			explicit operator float()
////			{
////				return  this->pret;
////			}
////			explicit operator int()
////			{
////				return  this->cantitate;
////			}
////			float operator()()
////			{
////				//return this->costMediuGram();
////			}
////			float operator()(float TVA)
////					{
////						return (this->pret + (TVA * this->pret))/this->cantitate;
////					}
////					float operator()(int discount)
////					{
////						return (this->pret - (discount / 100.0)* this->pret)/this->cantitate;
////					}
////					bool operator==(Prajitura prajitura)
////					{
////						if (strcmp(this->denumire, prajitura.denumire) != 0)
////							return false;
////						if (this->cantitate != prajitura.cantitate)
////							return false;
////						if (this->dePost != prajitura.dePost)
////							return false;
////						if (this->nrIngrediente != prajitura.nrIngrediente)
////							return false;
////						return true;
////					}
////					Prajitura& operator-=(const Prajitura &p)
////					{ if(this->pret>p.pret){this->pret-=p.pret;}
////					else this->pret=0;
////					return *this;
////
////					}
////					Prajitura& operator+=(string ingredient)
////					{
////						string* aux = new string[this->nrIngrediente + 1];
////						for (int i = 0;i < this->nrIngrediente;i++) {
////									aux[i] = this->ingrediente[i];
////									}
////									aux[this->nrIngrediente] = ingredient;
////									delete[] this->ingrediente;
////									this->ingrediente = aux;
////									this->nrIngrediente++;
////									return *this;
////
////					}
////
////
////};
//class Telefon
//{
//		private:
//		float rezolutie;
//		float memorie;
//		string model;
//		char * producator;
//		float pret;
//		int nrAplicatii;
//		float * memorieAplicatii;
//		const int id;
//		static int contor;
//		public:
//	Telefon():id(contor++)
//	{ this->rezolutie=44;
//	this->memorie=256;
//	this->model="Iphone 15";
//	this->producator=new char[strlen("Apple")+1];
//	strcpy(this->producator,"Apple");
//	this->pret=4000;
//	this->nrAplicatii=2;
//	this->memorieAplicatii=new float[this->nrAplicatii];
//	this->memorieAplicatii[0]=2;
//	this->memorieAplicatii[1]=4;
//	}
//	Telefon(float pret, const char* producator):id(contor++)
//	{
//		this->rezolutie = 44;
//		this->memorie = 256;
//		this->model = "Iphone 15";
//		this->producator = new char[strlen(producator)+ 1];
//		strcpy(this->producator, producator);
//		this->pret = pret;
//		this->nrAplicatii = 2;
//		this->memorieAplicatii = new float[this->nrAplicatii];
//		this->memorieAplicatii[0] = 2;
//		this->memorieAplicatii[1] = 4;
//	}
//	Telefon(const Telefon& t):id(t.contor++)
//	{
//		this->rezolutie = t.rezolutie;
//		this->memorie = t.memorie;
//		this->model =t.model;
//		this->producator = new char[strlen(t.producator) + 1];
//		strcpy(this->producator, t.producator);
//		this->pret = t.pret;
//		this->nrAplicatii = t.nrAplicatii;
//		this->memorieAplicatii = new float[t.nrAplicatii];
//		if (t.nrAplicatii > 0 && t.memorieAplicatii != nullptr)
//		{
//			for (int i = 0;i < t.nrAplicatii;i++)
//			{
//				this->memorieAplicatii[i]=t.memorieAplicatii[i];
//		}
//
//		}
//		else
//		{
//			this->nrAplicatii=0;
//			this->memorieAplicatii=nullptr;
//		}
//	}
//	Telefon& operator=(const Telefon& t)
//	{
//		if (this != &t)
//		{
//			this->rezolutie = t.rezolutie;
//			this->memorie = t.memorie;
//			this->model = t.model;
//			if(this->producator){delete[] this->producator; }
//			this->producator = new char[strlen(t.producator) + 1];
//			strcpy(this->producator, t.producator);
//			this->pret = t.pret;
//			this->nrAplicatii = t.nrAplicatii;
//			this->memorieAplicatii = new float[t.nrAplicatii];
//			if (this->memorieAplicatii) { delete[] this->memorieAplicatii; }
//			if (t.nrAplicatii > 0 && t.memorieAplicatii != nullptr)
//			{
//				for (int i = 0;i < t.nrAplicatii;i++)
//				{
//					this->memorieAplicatii[i] = t.memorieAplicatii[i];
//				}
//
//			}
//			else
//			{
//				this->nrAplicatii = 0;
//				this->memorieAplicatii = nullptr;
//			}
//
//		}
//		return *this;
//	}
//	~Telefon()
//	{
//		delete[] this->producator;
//		delete[] this->memorieAplicatii;
//	}
//	float getPret(){return this->pret;}
//	void setPret(float pret);
//	char * getProducator(){return this->producator;}
//	void setProducaator(char* producator)
//	{ delete[] this->producator;
//	this->producator= new char[strlen(producator)+1];
//	strcpy(this->producator,producator);
//	}
//	//op+
//	Telefon operator+(const Telefon& t)
//	{
//	  Telefon rez=*this;
//	  rez.pret=this->pret+ t.pret;
//	  return rez;
//	}
//	Telefon operator+(float crestere)
//	{ Telefon rez=*this;
//	rez.pret=this->pret+crestere;
//	return rez;
//	}
//	friend Telefon operator+(float crestere, Telefon t)
//	{	Telefon rez=t;
//		t.setPret(t.getPret()+crestere);
//		return rez;
//	}
//	float operator[](int index)
//	{
//		if (index > 0 && index < this->nrAplicatii) {
//			return this->memorieAplicatii[index];}
//			else return 0;
//	}
//	explicit operator float()
//	{float s=0;
//	if (this->nrAplicatii > 0)
//	{
//		for (int i = 0;i < this->nrAplicatii;i++)
//		{
//			s+=this->memorieAplicatii[i];
//	}
//
//	return s/this->nrAplicatii;
//	}
//	else return 0;
//
//	}
//	float operator()(float tva)
//	{
//		if (this->nrAplicatii > 0)
//		{
//			return (this->pret+this->pret*tva)/this->nrAplicatii;
//		}
//		else return 0;
//	}
//	friend ostream& operator<<(ostream& out, const Telefon& t)
//	{
//		out<<"Producator: "<<t.producator;
//		return out;
//	}
//	friend istream& operator>>(istream& in, Telefon& t)
//	{
//		cout<<"Producator: ";
//		char buffer[100];
//		in>>buffer;
//		t.producator=new char[strlen(buffer)+1];
//		strcpy(t.producator,buffer);
//		return in;
//	}
//	Telefon &operator++()
//	{
//		this->pret++;
//		return *this;
//	}
//	Telefon operator++(int)
//	{
//		Telefon rez=*this;
//		this->pret++;
//		return rez;
//	}
//	bool operator==(Telefon t)
//	{
//		if(strcmp(this->producator,t.producator)!=0)return false;
//		if(this->pret!=t.pret)return false;
//		return true;
//	}
//	//op <=
//	float operator<=(Telefon t)
//	{ float s=0;
//		if (this->pret > t.pret)
//		{ s=this->pret-t.pret;
//			return s;
//		}
//		else
//		{
//			this ->pret =0;
//			return 0;
//		}
//	}
//	void main()
//	{ Telefon t;
//	Telefon t2(4000, "Apple");
//	Telefon t3 = t;
//	float a = 6.3;
//	int b = (int)a;
//	float memorieMedie;
//	memorieMedie = (float)t;//cast explicit
//	t3 = t++;
//	t3 = ++t;
//	/*cin >> t;*/
//	cout << t;
//	//cout << "Pret per aplicatii: " << t3(1) << endl;
//	cout << " Pret cu tva per aplicatie: " << t3(0.21f) << endl;
//	cout << " Pret cu discount per aplicatie: " << t3(21);
//
//	if (t == t2) {
//		cout << endl << "Telefoane asemanatoare." << endl;
//	}
//	else {
//		cout << endl << "Telefoane diferite." << endl;
//	}
//
//	}
//
//
//
//};
class ContBancar
{
	private:
	static int numarConturi;
	const int idCont;
	string titularCont;
	double* istoricTranzactii;
	int nrTranzactii;
	public:
	ContBancar() :idCont(numarConturi)
	{
		this->titularCont="Alex";
		this->nrTranzactii=2;
		this->istoricTranzactii=new double[this->nrTranzactii];
		this->istoricTranzactii[0]=100;
		this->istoricTranzactii[1]=12;
	}
	ContBancar(const string titularCont, int nrTranzactii,const double* istoricTranzactii,static int numarConturi) :idCont(numarConturi)
	{
		this->titularCont = titularCont;
		this->nrTranzactii = nrTranzactii;
		this->istoricTranzactii = new double[nrTranzactii];
		if (nrTranzactii > 0)
		{
			for (int i = 0;i < nrTranzactii;i++)
			{
				this->istoricTranzactii[i]=istoricTranzactii[i];
			}
		}

	}
	ContBancar(const ContBancar& b):idCont(b.numarConturi)
	{ 
		this->titularCont = b.titularCont;
		this->nrTranzactii = b.nrTranzactii;
		this->istoricTranzactii = new double[b.nrTranzactii];
		if (b.nrTranzactii > 0 && b.istoricTranzactii!=nullptr)
		{
			for (int i = 0;i < b.nrTranzactii;i++)
			{
				this->istoricTranzactii[i] = b.istoricTranzactii[i];
			}
		}

	}
	ContBancar& operator=(const ContBancar& b)
	{
		if (this != &b)
		{

			this->titularCont = b.titularCont;
			this->nrTranzactii = b.nrTranzactii;
			if(this->istoricTranzactii!=nullptr){delete[] this->istoricTranzactii; }
			this->istoricTranzactii = new double[b.nrTranzactii];
			if (b.nrTranzactii > 0 && b.istoricTranzactii != nullptr)
			{
				for (int i = 0;i < b.nrTranzactii;i++)
				{
					this->istoricTranzactii[i] = b.istoricTranzactii[i];
				}
			}

	}
	return *this;

	}
	friend ostream& operator<<(ostream& out, const ContBancar& b)
	{
		out<<"titular cont"<<b.titularCont<<endl;
		out<<"nr tranzactii: "<<b.nrTranzactii<<endl;
		out<<"istoric tranzactii: ";
		for (int i = 0;i < b.nrTranzactii;i++)
		{
			out<<b.istoricTranzactii[i]<<", ";
		}
		return out;
	}
	int operator[](int index) 
	{	if(index>0 && index < this->nrTranzactii){return this->istoricTranzactii[index]; }
		else return 0;

	}
	explicit operator double()
	{ double s=0;
		if (this->nrTranzactii > 0)
		{
			for(int i=0;i<this->nrTranzactii;i++){s+=this->istoricTranzactii[i]; }
			return s;
		}
		else return 0;
	}

	
};