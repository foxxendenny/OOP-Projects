#include <conio.h>
#include <iostream>
#define TipI   int
using namespace std;

class Lista_Circulara;
class Nod
{
public:
    TipI info;
    Nod *next;
public:
    Nod(int val=0);
    friend class Lista_Circulara;
};

Nod::Nod(int val)
{
    info=val;
    next=NULL;
}

class Lista_Circulara
{
private:
    Nod *prim;
    Nod *ultim;

public:
    Lista_Circulara();
    ~Lista_Circulara();
    void addElement(TipI);
    int lung();
    void stergere(int);
    void inversare();
    Nod* getLast();
    Nod* getFirst();
    void conc(Lista_Circulara&);
    friend Lista_Circulara operator+(Lista_Circulara& lista);
    friend istream& operator>>(istream& input, Lista_Circulara&);
    friend ostream& operator<<(ostream& out, Lista_Circulara&);
};

Lista_Circulara::Lista_Circulara()
{
    ultim=NULL;
}
Lista_Circulara::~Lista_Circulara()
{
    Nod* p;
    //se elibereaza spatiul de memorie rezervat elementelor listei/
    if(ultim!=NULL)
    {
        while(ultim->next!=ultim)
        {
            p=ultim->next;
            ultim->next=ultim->next->next;
            delete p;
        }
        delete ultim;
    }

}
/** Adauga un nod la sfarsitul listei*/
void Lista_Circulara::addElement(TipI val)
{
    Nod* p=new Nod(val);
    if(ultim)
    {
        prim=p;
        p->next=ultim->next;
        ultim->next=p;
        ultim=p;
    }
    else
    {
        ultim = p;
        p->next=p;
    }

}

Nod* Lista_Circulara::getFirst()
{
    return prim;
}
Nod* Lista_Circulara::getLast()
{
    return ultim;
}
int Lista_Circulara::lung()
{
    Nod* curent = ultim;
    int count = 0;
    if (ultim == NULL) {
        return 0;
    }

    else {
        do {
            curent = curent->next;
            count++;
        } while (curent != ultim);
    }
    return count;
}

void Lista_Circulara::stergere(int pozitie)
{
    int count=1;
    Nod* curent=prim->next;
    Nod* prev=prim;
    while(count!=pozitie)
    {
        curent=curent->next;
        prev=prev->next;
        count++;
    }
    prev->next=curent->next;

}
void Lista_Circulara::inversare()
{
    Nod *curent,*prev,*urm;
    curent=prim;
    prev=NULL;
    while(curent!=NULL)
    {
        urm=curent->next;
        curent->next=prev;
        prev=curent;
        curent=urm;
    }
    prim=prev;

}
void Lista_Circulara::conc(Lista_Circulara& lista2)
{
    Nod *X,*Y,*Uni;
    X=prim;
    Y=lista2.prim;
    while(X->next!=NULL)
    {
        X=X->next;
    }
    X->next=Y;
    Uni=X;
}

istream& operator>>(istream& input, Lista_Circulara& lista)
{
    TipI x;
    input>> x;
    lista.addElement(x);
    return input;

}
ostream& operator<<(ostream& out, Lista_Circulara& lista)
{
    Nod* p=lista.getLast();
    if (lista.getLast()==NULL)
        cout << "\n Lista este vida! \n";
    else
    {
        while (p->next!=lista.getLast())
        {
            p=p->next;
            cout << p->info<<" ";
        }
        cout<< p->next->info<<" ";
        cout<<lista.getLast()->next->info;
        cout<<"\n";
    }
    return out;
}


int main()
{
    Lista_Circulara A,B,C;
    Nod* p;
    TipI i,x,n,j;
    cout<<"introduceti cate elemente doriti in lista ";
    cin>>n;
    cout<<endl<<"introduceti elementele ";
    for(i=1; i<=n; i++)
    {
        cin>>A;
    }
    cout<<A;
    cout<<"introduceti pozitia elementului sters";
    cin>>x;
    A.stergere(x);
    cout<<endl<<A<<endl;
    cout<<"dupa inversare lista este : ";
    A.inversare();
    cout<<A;


}
