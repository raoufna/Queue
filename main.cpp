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
void printArray(const T (&arr)[N])
{
    std::cout << "[ ";
    for (size_t i = 0; i < N; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << " ]" << std::endl;
}

/*     INT     */
void test_enqueue_e_dequeue()
{
    std::cout << "******** Test enqueue e dequeue su CODA (int)********" << std::endl;

    Queue<int> q;

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
    try
    {
        std::cout << "dequeue su coda vuota: " << std::endl;
        q.dequeue();
        // Tentativo di rimuovere da una coda vuota
        std::cout << "coda vuota: " << q << '\n';
    }
    catch (...)
    {
        std::cerr << "la coda è vuota" << std::endl;
    }

    separator_lines();
}

void test_enqueue_e_dequeue_HARD()
{
    std::cout << "******** Test ENQUEUE e DEQUEUE randomici su CODA (int) ********" << std::endl;

    long n_volte = 3000;
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
            try
            {
                q.dequeue();
                std::cout << "DEQUEUE, SCELTA " << scelta << ",numero: " << numeroCasuale << std::endl;
            }
            catch (...)
            {
                std::cerr << "IMPOSSIBILE FARE DEQUEUE: la coda è vuota" << std::endl;
            }
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

    // lettura elementi
    //  std::cout << "elemento più vecchio di q: " << q.read_first() << std::endl; //old
    //  std::cout << "elemento più recente di q: " << q.read_last() << std::endl;//recent

    separator_lines();
} // ~Queue()

void test_iter_ctor()
{

    std::cout << "******** Test costruttore tramite due iteratori ********" << std::endl;

    int a[5] = {20, 10, 5, 100, 80};

    Queue<int> q(a, a + 5); // ctor iterator

    std::cout << "stampa array: ";
    printArray(a);
    std::cout << "stampa queue: " << q << std::endl;

    separator_lines();
}
void test_read_write()
{
    std::cout << "******** Test azioni di lettura su CODA ********" << std::endl;
    int a[5] = {1, 2, 3, 4, 5};
    Queue<int> q(a, a + 5);

    std::cout << "q: " << q << std::endl;
    std::cout << "elemento più vecchio: " << q.first() << std::endl;
    std::cout << "elemento più recente: " << q.last() << std::endl;

    std::cout << "******** Test azioni di lettura su CODA VUOTA ********" << std::endl;
    try
    {
        Queue<int> q_empty;

        std::cout << "elemento più vecchio: " << q_empty.first() << std::endl;
        std::cout << "elemento più recente: " << q_empty.last() << std::endl;
    }
    catch (...)
    {
        std::cout << "ERRORE: la coda è vuota" << std::endl;
    }

    separator_lines();
}

template <typename T>
struct equals_primitivi
{
    bool operator()(const T &a, const T &b) const
    {
        return a == b;
    }
};
void test_find()
{
    equals_primitivi<int> e;
    std::cout << "******** Test ricerca elemento nella CODA ********" << std::endl;

    int a[5] = {1, 2, 3, 4, 5};
    Queue<int> q(a, a + 5);
    std::cout << "q: " << q << std::endl;

    std::cout << "->5 in q: " << q.find(5, e) << std::endl;
    std::cout << "->9 in q: " << q.find(9, e) << std::endl;

    Queue<int> q_empty;
    std::cout << "q_empty: " << q_empty << std::endl;

    std::cout << "->5 in q_empty: " << q_empty.find(5, e) << std::endl;
    std::cout << "->9 in q_empty: " << q_empty.find(9, e) << std::endl;

    separator_lines();
}

/*    STRING    */

/*void test_read_write_s(){
    std::cout << "******** Test azioni di lettura su CODA ********" << std::endl;

    std::string a[3] = {"testa","corpo","coda"};
    Queue<std::string> q(a,a+3); //iter ctor
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
struct Punto
{
    int x, y;

    // Costruttore per comodità
    Punto(int _x = 0, int _y = 0) : x(_x), y(_y) {}

    // Operatore di uguaglianza (necessario per il find)
    bool operator==(const Punto &other) const
    {
        return x == other.x && y == other.y;
    }

    // Operatore di stream per la stampa
    friend std::ostream &operator<<(std::ostream &os, const Punto &p)
    {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

// funtore di uguaglianza per Punto
struct compare_Punto
{
    bool operator()(const Punto &p1, const Punto &p2) const
    {
        return (p1.x == p2.x) && (p1.y == p2.y); // Confirsta x e y
    }
};

/*     PUNTO     */

void test_enqueue_e_dequeue_struct()
{
    std::cout << "******** Test enqueue e dequeue su CODA (Punto) ********" << std::endl;
    Queue<Punto> q;

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

    try
    {
        std::cout << "dequeue su coda vuota: " << std::endl;
        q.dequeue();

        // unreachable
        std::cout << "coda vuota: " << q << '\n';
    }
    catch (...)
    {
        std::cerr << "la coda è vuota" << std::endl;
    }

    separator_lines();
}

void test_enqueue_e_dequeue_random_struct()
{
    std::cout << "******** Test ENQUEUE e DEQUEUE randomici su CODA (Punto) ********" << std::endl;

    long n_volte = 3000;
    Queue<Punto> q;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribuzione(1, 100);

    int scelta, xCasuale, yCasuale;

    std::cout << q << "\n"
              << std::endl;
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
            try
            {
                q.dequeue();
                std::cout << "DEQUEUE" << std::endl;
            }
            catch (...)
            {
                std::cerr << "ERRORE DEQUEUE: la coda è vuota" << std::endl;
            }
        }
        std::cout << q << "\n"
                  << std::endl;
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

    Queue<Punto> q2(q); //copy ctor

    std::cout << "Stampa di q2 dopo copy constructor:" << std::endl;
    std::cout << "q2: " << q2 << std::endl;

    Queue<Punto> q3;
    q3 = q;

    std::cout << "Stampa di q3 dopo assegnamento:" << std::endl;
    std::cout << q3 << std::endl;

    
    std::cout << "lettura elementi: " << std::endl;
    std::cout << "first: " << q3.first() << std::endl;
    std::cout << "last: " << q3.last() << std::endl;

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

    try
    {
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
    }
    catch (...)
    {
        std::cerr << "la coda è vuota" << std::endl;
    }

    separator_lines();
}

void test_find_struct()
{
    std::cout << "******** Test ricerca elemento nella CODA di Punto ********" << std::endl;
    compare_Punto equalsPredicate;

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

struct in_terzo_quadrante {
    bool operator()(const Punto& p) const {
        return p.x < 0 && p.y < 0;
    }
};

struct porta_in_primo_quadrante {
    Punto operator()(const Punto& p) const {
        if (p.x >= 0 && p.y >= 0)
        {
            return p;
        }
        int new_x = p.x*(-1);
        int new_y = p.y*(-1);
        return Punto(new_x, new_y);
    }
};

void test_struct_Punto() {
    std::cout << "\n Test: Coda di struct Punto\n";

    Queue<Punto> q;

    q.enqueue(Punto(-5, -5));       // TERZO quadrante   
    q.enqueue(Punto(12, -8));       // quarto quadrante
    q.enqueue(Punto(-3, 2));        // secondo quadrante
    q.enqueue(Punto(-15, -20));     // TERZO quadrante
    q.enqueue(Punto(7, 1));         // primo quadrante

    std::cout << "q: " << q << std::endl;

    // Primo transformIf
    transformIf(q, in_terzo_quadrante(), porta_in_primo_quadrante());

    std::cout << "Dopo transformIf: " << std::endl;
    std::cout << "q: " << q << std::endl;

    // dequeue
    q.dequeue();
    std::cout << "Dopo dequeue: " << std::endl;
    std::cout << "q: " << q << std::endl;

    // Secondo transformIf
    transformIf(q, in_terzo_quadrante(), porta_in_primo_quadrante());

    std::cout << "\nDopo secondo transformIf:\n";
    std::cout << "q: " << q << std::endl;
}


int main()
{

    // TEST OK INT
    // test_enqueue_e_dequeue();
    // test_enqueue_e_dequeue_HARD();
    // test_copy_construtor();
    // test_metodi_fondamentali_int();
    // test_iter_ctor();
    // test_read_write();
    // test_find();

    // TEST DA SISTEMARE

    /*
        va tolta person come struct e vanno implementate struct per
        i metodi di transformif con Punto
        in piu ogni test deve essere standard:
            -iniziare con la riga con titolo e asterischi
            -finire con separator lines
    */

    // TEST OK STRUCT
    // test_enqueue_e_dequeue_struct();
    // test_enqueue_e_dequeue_random_struct();
    // test_copy_construtor_struct();
    // test_metodi_fondamentali_struct();
    // test_iter_ctor_struct();
    // test_read_write_struct();
    // test_find_struct();
    // testStructQueue();
    test_struct_Punto();

    return 0;
}
