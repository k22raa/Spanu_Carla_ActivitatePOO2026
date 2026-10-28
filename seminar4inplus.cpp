//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//
////class Clasa
////{
////	public:
////	char *pointer;
////	int atribut;
////	//ne facem un constructor de copiere pt clasa implicit
////	Clasa()
////	{
////		pointer=nullptr;
////		atribut=0;
////	}
////	//acum ne facem un constructor de copiere:
////	Clasa operator=(const Clasa &c)//& ca sa nu intram intr o bucla infinita si const ca sa promitem ca nu modificam valorile
////	{
////		this->atribut=c.atribut;
////		if (this->pointer != NULL)
////		{
////			delete[] this->pointer;
////		}
////		this->pointer=new char[strlen(c.pointer)+1];
////		strcpy(this->pointer,c.pointer);
////		return *this;
////
////	}
////	
////	~Clasa()
////	{
////		delete[] pointer;
////		//daca vrem sa stergem memoria alocata in heap cu un destructor aceasta ne va da eroare
////		//de tip double free deci ne trb un constructor de copiere facut de noi
////	}
////};
////void main()
////{
////	Clasa c1;
////	c1.pointer= new char[strlen("text")+1];
////	strcpy(c1.pointer, "text");
////	c1.atribut=10;
////	Clasa c2=c1;
////	//ptc nu avem un constructor de copiere se creeaza unul implicit care se numeste
////	//shallow copy adc o copiere superficiala de aceea codul nostru va copia si in c1 si in c2 newt:)
////	//dupa ce am creat constructorul de copiere vedem ca c1 ramane text si c2 newt
////	strcpy(c2.pointer, "newt");
////	cout<<c1.pointer;
////	Clasa c2;
////	c2=c1;
////
////}
//// 
////continuam cu clasa prajitura
//class Prajitura
//{
//	private:
//	char *denumire;
//	int pret;
//	float cantitate;
//	bool dePost;
//	int nrIngrediente;
//	string *ingrediente;
//	const int id;
//	static int contor;
//	public:
//	Prajitura():id(contor++)
//	{
//		this->denumire=new char[strlen("tiramisu")+1];
//		strcpy(this->denumire,"tiramisu");
//		this->pret=15;
//		this->cantitate=4;
//		this->dePost=true;
//		this->nrIngrediente=3;
//		this->ingrediente[0]="mascarpone";
//		this->ingrediente[1] = "piscoturi";
//		this->ingrediente[2] = "cafea";
//	}
//	Prajitura(const char* denumire, float pret):id(contor++)
//	{	this->denumire=new char[strlen(denumire)+1];
//	strcpy(this->denumire,denumire);
//	this->pret=pret;
//	cantitate=4;
//	this->dePost = true;
//	this->nrIngrediente = 3;
//	this->ingrediente = new string[this->nrIngrediente];
//	this->ingrediente[0] = "piscoturi";
//	this->ingrediente[1] = "cafea";
//	this->ingrediente[2] = "mascarpone";
//	
//	}
//	void afisare()
//	{
//		cout<<"denumire:"<<this->denumire<<endl;
//		cout << "pret:" << this->pret << endl;
//		cout << "cantitate:" << this->cantitate << endl;
//		cout << "de post:" << (this->dePost ? "DA" : "NU") << endl;
//		cout << "nr ingrediente:" << this->nrIngrediente << endl;
//		cout << "ingredientele sunt:";
//		for (int i = 0;i < this->nrIngrediente;i++)cout << this->ingrediente[i] << ", ";
//		cout << endl;
//	}
//	//modificare denumire:
//	void modificareDenumire(const char* denumire)
//	{
//		if (this->denumire != NULL)
//		{
//			delete[] this->denumire;
//		}
//		else
//		{
//			this->denumire=new char[strlen(denumire)+1];
//			strcpy(this->denumire,denumire);
//		}
//	}
//	
//
//
//
//};
//void main()
//{
//
//}