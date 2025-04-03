#include <iostream>
#include <random>
#include "Queue.hpp"

void separator_lines()
{
    std::cout << std::endl;
    for (size_t i = 0; i < 50; i++)
        std::cout << "--";
    std::cout << std::endl;
    std::cout << std::endl;
}

template <typename T, size_t N>
void printArray(const T (&arr)[N]) {
    std::cout << "[ ";
    for (size_t i = 0; i < N; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << " ]" << std::endl;
}

/*     INT     */
void test_enqueue_e_dequeue_EASY()
{
    // Creazione della queue di interi
    Queue<int> q;

    std::cout << "Test enqueue e dequeue EASY:\n";

    // Aggiunta di elementi alla coda
    q.enqueue(10);
    std::cout << q << std::endl;
    q.enqueue(20);
    std::cout << q << std::endl;
    q.enqueue(30);
    std::cout << "Elementi inseriti con successo.\n";
    std::cout << q << std::endl;

    // Tentativo di rimuovere elementi
    std::cout << "\nTest dequeue:\n";
    q.dequeue();
    std::cout << "1 rimozione: " << q << '\n';
    q.dequeue();
    std::cout << "2 rimozione: " << q << '\n';
    q.dequeue();
    std::cout << "3 rimozione: " << q << '\n';

    q.dequeue();
    // Tentativo di rimuovere da una coda vuota
    std::cout << "coda vuota: " << q << '\n';

    separator_lines();
}

void test_enqueue_e_dequeue_HARD()
{
    std::cout << "******** Test ENQUEUE e DEQUEUE randomici, su elementi randomici nella lista di interi ********" << std::endl;

    long n_volte = 30;
    Queue<int> q;

    std::random_device rd;  // Generatore di entropia hardware (se disponibile)
    std::mt19937 gen(rd()); // Inizializza il generatore con un seme casuale

    int scelta, numeroCasuale;
    std::uniform_int_distribution<int> distribuzione(1, 100);

    std::cout << q << "\n"
              << std::endl;
    for (long i = 1; i < n_volte; i++)
    {
        // numeri randomici
        numeroCasuale = distribuzione(gen);
        scelta = distribuzione(gen);

        std::cout << i << ". "; // intestazione

        if ((scelta % 2) == 0)
        {
            q.enqueue(numeroCasuale);
            std::cout << "ENQUEUE, SCELTA " << scelta << ",numero: " << numeroCasuale << std::endl;
        }
        else
        {
            q.dequeue();
            std::cout << "DEQUEUE, SCELTA " << scelta << ",numero: " << numeroCasuale << std::endl;
        }
        std::cout << q << "\n"
                  << std::endl;
    }

    separator_lines();
}

void test_copy_construtor()
{
    Queue<int> q;

    q.enqueue(12);
    q.enqueue(146);

    std::cout << "stampa di q: " << q << std::endl;

    Queue<int> p = q;

    std::cout << "copia fatta!" << std::endl;
    ;

    std::cout << "stampa di p: " << p << std::endl;

    p.enqueue(1);
    q.dequeue();
    std::cout << "aggiunta elemento a p" << std::endl;
    std::cout << "stampa di q: " << q << std::endl;
    std::cout << "stampa di p: " << p << std::endl;

    separator_lines();
}

void test_metodi_fondamentali_int()
{
    std::cout << "******** Test metodi fondamentali della lista di interi ********" << std::endl;

    Queue<int> q; // ctor default

    q.enqueue(5); // enqueue
    q.enqueue(8);
    q.enqueue(1);
    q.enqueue(4);

    std::cout << "Stampa di q dopo inserimenti:" << std::endl;
    std::cout << q << std::endl; // operator<<

    Queue<int> q2(q); // cctor

    std::cout << "Stampa di q2 dopo copy constructor:" << std::endl;
    std::cout << q2 << std::endl; // operator<<

    Queue<int> q3;

    q3 = q; // operator=

    std::cout << "Stampa di q3 dopo assegnamento:" << std::endl;
    std::cout << q3 << std::endl; // operator<<

    //lettura elementi
    // std::cout << "elemento più vecchio di q: " << q.read_first() << std::endl; //old
    // std::cout << "elemento più recente di q: " << q.read_last() << std::endl;//recent

    separator_lines();
} // ~Queue()



void test_iter_ctor(){

    std::cout << "******** Test costruttore tramite due iteratori ********" << std::endl;
    
    int a[5] = {20,10,5,100,80};

    Queue<int> q(a,a+5); //ctor iterator

    std::cout << "stampa array: "; printArray(a);
    std::cout << "stampa queue: " << q << std::endl;

    separator_lines();
}
/*void test_read_write(){
    std::cout << "******** Test azioni di lettura su CODA ********" << std::endl;
    int a[5] = {1,2,3,4,5};
    Queue<int> q(a,a+5);
    
    std::cout << "q: " << q << std::endl;    
    q.read_first();
    q.read_last();
    q.write_first(5);
    q.write_last(10);
    std::cout << "q: " << q << std::endl;
    
    std::cout << "******** Test azioni di lettura su CODA VUOTA ********" << std::endl;
    Queue<int> q_empty;

    std::cout << "q_empty: " << q_empty << std::endl;
    q_empty.read_first();
    q_empty.read_last();
    q_empty.write_first(5);
    q_empty.write_last(5);
    std::cout << "q_empty: " << q_empty << std::endl;

    separator_lines();    
}*/
/*
void test_find(){
    std::cout << "******** Test ricerca elemento nella CODA ********" << std::endl;
    
    int a[5] = {1,2,3,4,5};
    Queue<int> q(a,a+5);
    std::cout << "q: " << q << std::endl;

    
    std::cout << "->5 in q: " << q.find(5) << std::endl;
    std::cout << "->9 in q: " << q.find(9) << std::endl;


    Queue<int> q_empty;    
    std::cout << "q_empty: " << q_empty << std::endl;
    
    std::cout << "->5 in q_empty: " << q_empty.find(5) << std::endl;
    std::cout << "->9 in q_empty: " << q_empty.find(9) << std::endl;

    separator_lines();
}*/


/*    STRING    */


/*void test_read_write_s(){
    std::cout << "******** Test azioni di lettura su CODA ********" << std::endl;

    std::string a[3] = {"testa","corpo","coda"};
    //Queue<std::string> q(a,a+3); //iter ctor
    Queue<std::string> q_empty;

    q_empty.read_first();

    std::cout << "queue: " << q << std::endl;
    std::cout << "elemento più vecchio(head): " << q.read_first() << std::endl;
    std::cout << "elemento più recente(tail): " << q.read_last() << std::endl;

    std::cout << "******** Test azioni di scrittura su CODA ********" << std::endl;
    std::cout << "primo elemento -> banana" << std::endl;
    std::cout << "ultimo elemento -> mela" << std::endl;

    q.write_first("banana");
    q.write_last("mela");
    std::cout << "queue: " << q << std::endl;
    
    separator_lines();
}*/

/*    STRUCT    */
struct Punto {
    int x, y;

    // Costruttore per comodità
    Punto(int _x = 0, int _y = 0) : x(_x), y(_y) {}

    // Operatore di uguaglianza (necessario per il find)
    bool operator==(const Punto& other) const {
        return x == other.x && y == other.y;
    }

    // Operatore di stream per la stampa
    friend std::ostream& operator<<(std::ostream& os, const Punto& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

//funtore di uguaglianza per Punto
struct EqualsPunto {
    bool operator()(const Punto& p1, const Punto& p2) const {
        return (p1.x == p2.x) && (p1.y == p2.y); // Confirsta x e y
    }
};

/*     PUNTO     */

void test_enqueue_e_dequeue_EASY_struct()
{
    Queue<Punto> q;

    std::cout << "Test enqueue e dequeue EASY (Punto):\n";

    q.enqueue(Punto(1, 2));
    std::cout << q << std::endl;
    q.enqueue(Punto(3, 4));
    std::cout << q << std::endl;
    q.enqueue(Punto(5, 6));
    std::cout << "Elementi inseriti con successo.\n";
    std::cout << q << std::endl;

    std::cout << "\nTest dequeue:\n";
    q.dequeue();
    std::cout << "1 rimozione: " << q << '\n';
    q.dequeue();
    std::cout << "2 rimozione: " << q << '\n';
    q.dequeue();
    std::cout << "3 rimozione: " << q << '\n';

    q.dequeue();
    std::cout << "coda vuota: " << q << '\n';

    separator_lines();
}

void test_enqueue_e_dequeue_HARD_struct()
{
    std::cout << "******** Test ENQUEUE e DEQUEUE randomici su Punto ********" << std::endl;

    long n_volte = 3000;
    Queue<Punto> q;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribuzione(1, 100);

    int scelta, xCasuale, yCasuale;

    std::cout << q << "\n" << std::endl;
    for (long i = 1; i < n_volte; i++)
    {
        xCasuale = distribuzione(gen);
        yCasuale = distribuzione(gen);
        scelta = distribuzione(gen);

        std::cout << i << ". ";

        if ((scelta % 2) == 0)
        {
            q.enqueue(Punto(xCasuale, yCasuale));
            std::cout << "ENQUEUE, PUNTO: " << Punto(xCasuale, yCasuale) << std::endl;
        }
        else
        {
            q.dequeue();
            std::cout << "DEQUEUE" << std::endl;
        }
        std::cout << q << "\n" << std::endl;
    }

    separator_lines();
}

void test_copy_construtor_struct()
{
    Queue<Punto> q;

    q.enqueue(Punto(1, 1));
    q.enqueue(Punto(2, 2));

    std::cout << "stampa di q: " << q << std::endl;

    Queue<Punto> p = q;

    std::cout << "copia fatta!" << std::endl;
    std::cout << "stampa di p: " << p << std::endl;

    p.enqueue(Punto(3, 3));
    q.dequeue();
    std::cout << "aggiunto elemento a p" << std::endl;
    std::cout << "stampa di q: " << q << std::endl;
    std::cout << "stampa di p: " << p << std::endl;

    separator_lines();
}

void test_metodi_fondamentali_struct()
{
    std::cout << "******** Test metodi fondamentali della coda di Punto ********" << std::endl;

    Queue<Punto> q;

    q.enqueue(Punto(1, 2));
    q.enqueue(Punto(3, 4));
    q.enqueue(Punto(5, 6));
    q.enqueue(Punto(7, 8));

    std::cout << "Stampa di q dopo inserimenti:" << std::endl;
    std::cout << q << std::endl;

    Queue<Punto> q2(q);

    std::cout << "Stampa di q2 dopo copy constructor:" << std::endl;
    std::cout << q2 << std::endl;

    Queue<Punto> q3;
    q3 = q;

    std::cout << "Stampa di q3 dopo assegnamento:" << std::endl;
    std::cout << q3 << std::endl;

    // std::cout << "elemento più vecchio di q: " << q.read_first() << std::endl;
    // std::cout << "elemento più recente di q: " << q.read_last() << std::endl;

    separator_lines();
}

void test_iter_ctor_struct()
{
    std::cout << "******** Test costruttore tramite due iteratori (Punto) ********" << std::endl;

    Punto a[5] = {Punto(1, 1), Punto(2, 2), Punto(3, 3), Punto(4, 4), Punto(5, 5)};

    Queue<Punto> q(a, a + 5);

    std::cout << "stampa queue: " << q << std::endl;

    separator_lines();
}

void test_read_write_struct()
{
    std::cout << "******** Test azioni di lettura su CODA di Struct ********" << std::endl;
    
    try{
        Punto a[5] = {Punto(1, 1), Punto(2, 2), Punto(3, 3), Punto(4, 4), Punto(5, 5)};
        Queue<Punto> q(a, a + 5);

        std::cout << "q: " << q << std::endl;
        std::cout << "Leggo primo: " << q.first() << std::endl;
        std::cout << "Leggo ultimo: " << q.last() << std::endl;

        q.first() = Punto(9, 9);
        q.last() = Punto(10, 10);

        std::cout << "q dopo scritture: " << q << std::endl;

        std::cout << "******** Test azioni di lettura su CODA VUOTA di Struct ********" << std::endl;
        
        Queue<Punto> q_empty;
        
        std::cout << "q_empty: " << q_empty << std::endl;
        std::cout << "Leggo primo: " << q_empty.first() << std::endl;
        std::cout << "Leggo ultimo: " << q_empty.last() << std::endl;
        
    }catch(...){
        std::cerr << "la coda è vuota" << std::endl;
    }

    
    separator_lines();
}

void test_find_struct()
{
    std::cout << "******** Test ricerca elemento nella CODA di Punto ********" << std::endl;
    EqualsPunto equalsPredicate;

    Punto a[5] = {Punto(1, 1), Punto(2, 2), Punto(3, 3), Punto(4, 4), Punto(5, 5)};
    Queue<Punto> q(a, a + 5);

    std::cout << "q: " << q << std::endl;

    std::cout << "-> Punto (5,5) in q: " << q.find(Punto(5, 5), equalsPredicate) << std::endl;
    std::cout << "-> Punto (9,9) in q: " << q.find(Punto(9, 9), equalsPredicate) << std::endl;

    std::cout << "******** Test ricerca elemento nella CODA VUOTA di Punto ********" << std::endl;
    Queue<Punto> q_empty;
    std::cout << "q_empty: " << q_empty << std::endl;

    std::cout << "-> Punto (5,5) in q_empty: " << q.find(Punto(5, 5), equalsPredicate) << std::endl;
    std::cout << "-> Punto (9,9) in q_empty: " << q.find(Punto(9, 9), equalsPredicate) << std::endl;

    separator_lines();
}

struct Person {
    std::string name;
    int age;

    Person(const std::string& name, int age) : name(name), age(age) {}

    friend std::ostream& operator<<(std::ostream& os, const Person& p) {
        os << "(Nome: " << p.name << ", Età: " << p.age << ")";
        return os;
    }

    const std::string& getName() const { return name; }
    void setName(const std::string& newName) { name = newName; }

    //   Person& operator=(const Person& other) {
    //     if (this != &other) {  
    //         name = other.name; 
    //         age = other.age;  
    //     }
    //     return *this;  
    // }
};
struct age_below_30 
{
    bool operator()(const Person &p )const{
        return p.age<30;
    }
};

struct modified_name
{
    Person operator()(Person& p)const{
        p.setName(p.getName() + "(too young)");
        return p;
    }
};

// Test per la coda di oggetti struct (Person)
void testStructQueue() {
    std::cout << "\n Test: Coda di struct Person\n";

    Queue<Person> q;
    transformIf(q, age_below_30(), modified_name());

    q.enqueue(Person("Alice", 30));
    q.enqueue(Person("Giacomo", 25));
    q.enqueue(Person("Carlo", 35));
    q.enqueue(Person("Andrea", 20));
    q.enqueue(Person("Sara", 40));

    std::cout << "q: " << q << std::endl;
    

    

    // dequeue e visualizzazione
    q.dequeue();
    std::cout << "\nContenuto dopo dequeue: \n";
    std::cout << "q: " << q << std::endl;


    transformIf(q, age_below_30(), modified_name());
    std::cout << "q: " << q << std::endl;

}





int main()
{

    // Test su interi
    // test_enqueue_e_dequeue_EASY();
    // test_enqueue_e_dequeue_HARD();
    // test_copy_construtor();
    // test_metodi_fondamentali_int();
    // test_iter_ctor();
    // test_read_write();
    // test_find();

    // Test su struct Punto
    // test_enqueue_e_dequeue_EASY_struct();
    // test_enqueue_e_dequeue_HARD_struct();
    // test_copy_construtor_struct();
    // test_metodi_fondamentali_struct();
    // test_iter_ctor_struct();
    //test_read_write_struct();
    test_find_struct();


    // testStructQueue();

    return 0;
}
