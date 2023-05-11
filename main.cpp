#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <limits>

using namespace std;
ifstream in(R"(C:\Users\sumur\Documents\GitHub\SD-TEMA2\intrare)");
/*
Clasa SkipList (este implemnta ca un skipList random (folosind un coinflip))
 Aceasta este ordonata dupa value
*/
class SkipList{
private:
    // Clasa Node  reprezinta elementele dint lista
    struct Node{
        int value;//Valoarea pe care nodul o tine
        std::vector<Node*> next; // Urmatoarele noduri dupaa acesta (defera in functie de nivel) , inital sunt nullptr
        Node(int const v, int level):
                value(v),next(level,nullptr)
        {}
    };
    //Genereaza un now Level care urmeaza a fi folosit , Am incercat sa fac un coiflip , acesta este afectat de sansa
    int randomLevel() const;
    //Intoarce nivelul nodului v
    static int nodeLevel(const Node* v);
    //Creaza un nou nod
    static Node* createNode( int val, int level);
    //Returneaza primul nod pentru ca conditia  ca valuarea < searchValue nu este adevarata
    Node* lower_bound(int searchValue) const ;


    std::vector<Node*> predecesori(int searchValue) const ;

    const float sansa; // probabilitatea ca un nod sa creasca in level (initial 0.5 == 50%)
    const int maxLevel;// nivelul maxim care poate sa il aiba un nod (este folosit ca un nod sa nu treaca de cap / coada ca nivel)
    Node* cap; // Nodul de inceput , Header
    Node* coada;//Nodel de final , Tail


public:
    SkipList();
    ~SkipList();
    //Afiseaza elementele nodului
    void Print() const;
    //Cauta ul element cu valoarea = value
    int find(int value) const;
    //Insereaza un element
    void insert(const int newValue);
    //Elimina primul element (pe care il gaseste) cu valoarea  = value
    void pop(int Value);

    void afisare() const;
};
SkipList::SkipList() :
        sansa(0.5),
        maxLevel(16)
{
    //Initializam primul nod cu valoarea minima din int
    cap = new Node(std::numeric_limits<int>::min(), maxLevel);
    //Initializam ultimul nod cu valoarea maxima din int
    coada = new Node( std::numeric_limits<int>::max(), maxLevel);

    //'legam' primul nod de ultimul (acesta se va  schimba cand apar elemente )
    std::fill(cap->next.begin(), coada->next.end(), coada);
}

SkipList::~SkipList() {
    auto aux1 = cap;//icepem de la inceput
    while (aux1->next[0]) { // cat timp mai avem elemente
        auto aux2 = aux1; // salvam nodul curent ca sa il stergem
        aux1 = aux2->next[0]; // trecem la urmatorul nod
        delete aux2; // stergem vechiul nod
    }
    delete aux1; // stergem ultimul nod
}
int SkipList::find(int searchValue) const {
    int res = NULL;
    if (auto x = lower_bound(searchValue)) {
        if (x->value == searchValue && x!=coada) {
            res = x->value;
        }
    }
    return res;
}
void SkipList::afisare() const {
    Node* list = cap->next[0];

    while (list != coada) {
        cout << list->value<<' ';

        list = list->next[0];

    }
    cout << endl;
}
void SkipList::Print() const {
    Node* list = cap->next[0];


    while (list != coada) {
        cout << "value: " << list->value
                  << ", level: " << nodeLevel(list);

        list = list->next[0];

         cout << "\n";
    }
    cout << endl;
}
void SkipList::insert( const int newValue) {
    //Gasim predecesori pentru serchValue ()
    auto prede = predecesori( newValue);



    // Cream un nou nod
    const int newNodeLevel = randomLevel();
    auto newNode = createNode( newValue, newNodeLevel);

    // Conectam predecesori si sucesori la nodul creat
    for (int i = 0; i < newNodeLevel; ++i) {
        newNode->next[i] = prede[i]->next[i];
        prede[i]->next[i] = newNode;
    }
    prede.clear();
}
void SkipList::pop(int searchValue) {
    auto prede = predecesori(searchValue);

    //Verificam daca nodul exista ,altfel nu avem ce face si iesim
    auto node = prede[0]->next[0];
    if (node->value != searchValue || node == coada) {
        return;
    }

    // Updatam pointere si stergem nodul
    for (size_t i = 0; i < nodeLevel(node); ++i) {
        prede[i]->next[i] = node->next[i];
    }
    delete node;
    prede.clear();
}
//Functiile node-lor
int SkipList::nodeLevel(const Node* v) {
    return v->next.size(); // Nivelul unui nod este egal cu cate elemente sunt in next
}
//Facem un nou nod
SkipList::Node* SkipList::createNode( int val, int level)  {
    return new Node( val, level);
}
//Generam un nou level (sper ca este un random egal (din incercarile mele este destul de corect ) sansele ca un nod sa aiba levelul 16 este de 1/(2^16) sau 1/65536)
int SkipList::randomLevel() const {
    int v = 1;
    while (((double)std::rand() / RAND_MAX) < sansa &&
           v < maxLevel) {
        v++;
    }
    return v;
}

SkipList::Node* SkipList::lower_bound(int searchValue) const{
    Node* x = cap;

    for (unsigned int i = nodeLevel(cap); i-- > 0;) {
        while ( x->next[i]->value < searchValue) {
            x = x->next[i];
        }
    }
    return x->next[0];
}

vector<SkipList::Node*> SkipList::predecesori(int searchValue) const {
    auto prede = new vector<Node*>(maxLevel);
    auto x = cap;

    for (int i = nodeLevel(coada) - 1; i >= 0; --i) {
        while (x->next[i]->value < searchValue) {
            x = x->next[i];
        }
        (*prede)[i] = x;
    }

    return *prede;
}

int main(){
   int aux;
   SkipList s;
   //while(in>>aux)
   cin >> aux;
       s.insert(aux);
    cin >> aux;
    s.insert(aux);
    cin >> aux;
    s.insert(aux);
   s.Print();
//   s.pop(2);
//   s.Print();
//   s.insert(-10000000);
//   s.Print();
//   s.afisare();
   return 0;
}