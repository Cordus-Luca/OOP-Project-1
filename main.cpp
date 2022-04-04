#include <bits/stdc++.h>

using namespace std;

class Animal
{
    string nume_animal;
    double marime_animal;

public:

    Animal() : nume_animal("-"), marime_animal(-1) {}
    Animal(string nume, int marime) : nume_animal(nume), marime_animal(marime) {}
    Animal(const Animal& a) : nume_animal(a.nume_animal), marime_animal(a.marime_animal) {}

    friend istream& operator>> (istream&, Animal& a);
    friend ostream& operator<< (ostream&, const Animal& a);
    Animal& operator=(const Animal& a);

    ~Animal()
    {
        nume_animal = "-";
        marime_animal = -1;
    }

    virtual void afisare ()
    {
        cout << "Nume animal: " << this->nume_animal << "\nMarime animal: " << this->marime_animal << "\n";
    }

    virtual void citire ()
    {
        cout << "Nume animal: ";
        cin >> this->nume_animal;
        cout << "Marime animal (m): ";
        cin >> this->marime_animal;
    }

    const int get_marime()
    {
        return this->marime_animal;
    }
};

istream& operator>> (istream& in, Animal& a)
{
    cout << "Nume animal: ";
    cin.ignore(1, '\n');
    getline(cin, a.nume_animal);
    cout << "Marime animal (m): ";
    cin >> a.marime_animal;
}

ostream& operator<<(ostream& out, const Animal& a)
{
    cout << "Nume animal: " << a.nume_animal << "\nMarime animal: " << a.marime_animal << "\n";
}

Animal& Animal::operator=( const Animal& a)
{
    nume_animal = a.nume_animal;
    marime_animal = a.marime_animal;
    return *this;
}

class Nevertebrate : public Animal
{
    string regn;

public:
    Nevertebrate() : Animal(), regn("-") {}
    Nevertebrate(string n_a, int m_a, string rgn) : Animal(n_a, m_a), regn(rgn) {}
    Nevertebrate(const Nevertebrate& n) : Animal((Animal&) n), regn(n.regn) {}

    friend istream& operator>> (istream&, Nevertebrate& n);
    friend ostream& operator<< (ostream&, const Nevertebrate& n);
    Nevertebrate& operator=(const Animal& n)
    {
        return *this;
    };

    ~Nevertebrate()
    {
        regn = "-";
    }

    void afisare()
    {
        cout << *this;
    }

    void citire()
    {
        cin >> *this;
    }
};

istream& operator>> (istream& in, Nevertebrate& n)
{
    cout << "NEVERTEBRATA\n";
    cin >> (Animal&) n;
    cout << "Regn nevertebrata: ";
    cin.ignore(1, '\n');
    getline(cin, n.regn);
    cout << endl;
}

ostream& operator<<(ostream& out, const Nevertebrate& n)
{
    cout << (Animal&) n;
    cout << "Regn nevertebrata: " << n.regn << "\n";
}

class Vertebrate : public Animal
{
    string regn;

public:
    Vertebrate() : Animal(), regn("-") {}
    Vertebrate(string n_a, int m_a, string rgn) : Animal(n_a, m_a), regn(rgn) {}
    Vertebrate(const Vertebrate& n) : Animal((Animal&) n), regn(n.regn) {}

    friend istream& operator>> (istream&, Vertebrate& n);
    friend ostream& operator<< (ostream&, const Vertebrate& n);
    Vertebrate& operator=(const Animal& n)
    {
        return *this;
    };

    ~Vertebrate()
    {
        regn = "-";
    }

    virtual void afisare()
    {
        cout << *this;
    }

    void citire()
    {
        cin >> *this;
    }
};

istream& operator>> (istream& in, Vertebrate& n)
{
    cin >> (Animal&) n;
    cout << "Regn vertebrata: ";
    cin.ignore(1, '\n');
    getline(cin, n.regn);
}

ostream& operator<<(ostream& out, const Vertebrate& n)
{
    cout << (Animal&) n;
    cout << "Regn vertebrata: " << n.regn << "\n";
}

class Peste : public Vertebrate
{
    string tip_peste, culoare;

public:
    Peste() : Vertebrate(), tip_peste("-"), culoare("-") {}
    Peste(string n_a, int m_a, string rgn, string tip, string cul) : Vertebrate(n_a, m_a, rgn), tip_peste(tip), culoare(cul) {}
    Peste(const Peste& n) : Vertebrate((Vertebrate&) n), tip_peste(n.tip_peste), culoare(n.culoare) {}

    friend istream& operator>> (istream&, Peste& n);
    friend ostream& operator<< (ostream&, const Peste& n);
    Peste& operator=(const Vertebrate& n)
    {
        return *this;
    };

    ~Peste()
    {
        tip_peste = "-";
        culoare = "-";
    }

    void afisare()
    {
        cout << *this;
    }

    void citire()
    {
        cin >> *this;
    }

    string get_tip()
    {
        return this->tip_peste;
    }
};

istream& operator>> (istream& in, Peste& n)
{
    cout << "PESTE \n";
    cin >> (Vertebrate&) n;
    cout << "Tip peste(rapitor, non-rapitor): ";
    cin >> n.tip_peste;
    cout << "Culoare peste: ";
    cin >> n.culoare;
    cout << endl;
}

ostream& operator<<(ostream& out, const Peste& n)
{
    cout << (Vertebrate&) n;
    cout << "Tip peste: " << n.tip_peste << "\nCuloare peste: " << n.culoare << "\n";
}

class Pasari : public Vertebrate
{
    string tip_pasare, culoare;

public:
    Pasari() : Vertebrate(), tip_pasare("-"), culoare("-") {}
    Pasari(string n_a, int m_a, string rgn, string tip, string cul) : Vertebrate(n_a, m_a, rgn), tip_pasare(tip), culoare(cul) {}
    Pasari(const Pasari& n) : Vertebrate((Vertebrate&) n), tip_pasare(n.tip_pasare), culoare(n.culoare) {}

    friend istream& operator>> (istream&, Pasari& n);
    friend ostream& operator<< (ostream&, const Pasari& n);
    Pasari& operator=(const Vertebrate& n)
    {
        return *this;
    };

    ~Pasari()
    {
        tip_pasare = "-";
        culoare = "-";
    }

    void afisare()
    {
        cout << *this;
    }

    void citire()
    {
        cin >> *this;
    }
};

istream& operator>> (istream& in, Pasari& n)
{
    cout << "PASARE\n";
    cin >> (Vertebrate&) n;
    cout << "Tip pasare: ";
    cin >> n.tip_pasare;
    cout << "Culoare pasare: ";
    cin >> n.culoare;
    cout << endl;
}

ostream& operator<<(ostream& out, const Pasari& n)
{
    cout << "PASARE \n";
    cout << (Vertebrate&) n;
    cout << "Tip pasare: " << n.tip_pasare << "\nCuloare pasare: " << n.culoare << "\n";
}

class Mamifere : public Vertebrate
{
    string rasa_mamifer, culoare;
    int nr_picioare;

public:
    Mamifere() : Vertebrate(), rasa_mamifer("-"), nr_picioare(-1), culoare("-") {}
    Mamifere(string n_a, int m_a, string rgn, string rasa, int nr_p, string cul) : Vertebrate(n_a, m_a, rgn), rasa_mamifer(rasa), nr_picioare(nr_p), culoare(cul) {}
    Mamifere(const Mamifere& n) : Vertebrate((Vertebrate&) n), rasa_mamifer(n.rasa_mamifer), nr_picioare(n.nr_picioare), culoare(n.culoare) {}

    friend istream& operator>> (istream&, Mamifere& n);
    friend ostream& operator<< (ostream&, const Mamifere& n);
    Mamifere& operator=(const Vertebrate& n)
    {
        return *this;
    };

    ~Mamifere()
    {
        rasa_mamifer = "-";
        nr_picioare = -1;
        culoare = "-";
    }

    void afisare()
    {
        cout << *this;
    }

    void citire()
    {
        cin >> *this;
    }
};

istream& operator>> (istream& in, Mamifere& n)
{
    cout << "MAMIFER\n";
    cin >> (Vertebrate&) n;
    cout << "Rasa mamifer: ";
    cin >> n.rasa_mamifer;
    cout << "Numar picioare: ";
    cin >> n.nr_picioare;
    cout << "Culoare mamifer: ";
    cin >> n.culoare;
    cout << endl;
}

ostream& operator<<(ostream& out, const Mamifere& n)
{
    cout << "MAMIFER \n";
    cout << (Vertebrate&) n;
    cout << "Rasa mamifer: " << n.rasa_mamifer << "\nNumar picioare: " << n.nr_picioare << "\nCuloare mamifer: " << n.culoare << "\n";
}

class Reptile : public Vertebrate
{
    string tip_reptila;
    int nr_picioare;

public:
    Reptile() : Vertebrate(), tip_reptila("-"), nr_picioare(-1) {}
    Reptile(string n_a, int m_a, string rgn, string rasa, int nr_p) : Vertebrate(n_a, m_a, rgn), tip_reptila(rasa), nr_picioare(nr_p) {}
    Reptile(const Reptile& n) : Vertebrate((Vertebrate&) n), tip_reptila(n.tip_reptila), nr_picioare(n.nr_picioare) {}

    friend istream& operator>> (istream&, Reptile& n);
    friend ostream& operator<< (ostream&, const Reptile& n);
    Reptile& operator=(const Vertebrate& n)
    {
        return *this;
    };

    ~Reptile()
    {
        tip_reptila = "-";
        nr_picioare = -1;
    }

    void afisare()
    {
        cout << *this;
    }

    void citire()
    {
        cin >> *this;
    }
};

istream& operator>> (istream& in, Reptile& n)
{
    cout << "REPTILA\n";
    cin >> (Vertebrate&) n;
    cout << "Tip reptila: ";
    cin >> n.tip_reptila;
    cout << "Numar picioare: ";
    cin >> n.nr_picioare;
    cout << endl;
}

ostream& operator<<(ostream& out, const Reptile& n)
{
    cout << "REPTILA \n";
    cout << (Vertebrate&) n;
    cout << "Tip reptila: " << n.tip_reptila << "\nNumar picioare: " << n.nr_picioare << "\n";
}

template <typename T>
class AtlasZoologic
{
    list <T*> lista_animale;
    int nr_animale;
    static int id_atlas;

public:

    AtlasZoologic(): nr_animale(0)
    {
        id_atlas++;
    }
    AtlasZoologic(list <T> lista, int nr) : lista_animale(lista), nr_animale(nr)
    {
        id_atlas++;
    }
    AtlasZoologic(const AtlasZoologic& a) : lista_animale(a.lista_animale), nr_animale(a.nr_animale)
    {
        id_atlas++;
    }

    friend istream& operator>> (istream& in, AtlasZoologic<T>& a)
    {
        cout << "Numar animale: ";
        cin >> a.nr_animale;
        for (int i = 1; i <= a.nr_animale; i++)
        {
            cout << "Tip animal(nevertebrat = 1, peste = 2, pasare = 3, mamifer = 4, reptila = 5): ";
            int op;
            in >> op;
            switch (op)
            {
            case 1:
            {
                Nevertebrate *n = new Nevertebrate;
                n->citire();
                Animal *anim = dynamic_cast<Animal*>(n);
                a.lista_animale.push_front(anim);
            }
            break;
            case 2:
            {
                Peste *n = new Peste;
                n->citire();
                a.lista_animale.push_front(n);
            }
            break;
            case 3:
            {
                Pasari *n = new Pasari;
                n->citire();
                Animal *anim = dynamic_cast<Animal*>(n);
                a.lista_animale.push_front(anim);
            }
            break;
            case 4:
            {
                Mamifere *n = new Mamifere;
                n->citire();
                Animal *anim = dynamic_cast<Animal*>(n);
                a.lista_animale.push_front(anim);
            }
            break;
            case 5:
            {
                Reptile *n = new Reptile;
                n->citire();
                Animal *anim = dynamic_cast<Animal*>(n);
                a.lista_animale.push_front(anim);
            }
            break;
            default:
                cout << "\nTip inserat gresit!\n";
                break;
            }
        }
    }

    friend ostream& operator<< (ostream& out, const AtlasZoologic<T>& n)
    {
        cout << "Numar animale: " << n.nr_animale << "\n";
        cout << endl;
        list <T*> cl;
        cl = n.lista_animale;
        typename list <T*> :: iterator it;
        for(it = cl.begin(); it != cl.end(); ++it)
        {
            Animal *anim = new Animal;
            anim = *it;
            anim->afisare();
            cout << endl;
        }
    }
    AtlasZoologic& operator=(const AtlasZoologic& a)
    {
        lista_animale = a.lista_animale;
        nr_animale = a.nr_animale;
    };

    AtlasZoologic& operator+=(T& a)
    {
        nr_animale++;
        lista_animale.push_front(&a);
    }
    ~AtlasZoologic()
    {
        for (int i = 1; i <= nr_animale; i++)
        {
            lista_animale.pop_front();
        }
        nr_animale = 0;
    }

};

template <typename T>
int AtlasZoologic<T>::id_atlas = 0;


template <>
class AtlasZoologic<Peste>
{
    list<Peste*> pesti_r;
    list<Peste*> pesti_n;
    int nr_pesti_r;
    int nr_pesti_n;

public:

    AtlasZoologic() : nr_pesti_r(0), nr_pesti_n(0) {}

    AtlasZoologic(const AtlasZoologic& a) : pesti_r(a.pesti_r), pesti_n(a.pesti_n), nr_pesti_r(a.nr_pesti_r), nr_pesti_n(a.nr_pesti_n) {}
    friend istream& operator>> (istream&, AtlasZoologic& a)
    {
        cout << "Numar pesti rapitori: ";
        cin >> a.nr_pesti_r;
        cout << "Numar pesti non-rapitori: ";
        cin >> a.nr_pesti_n;
        cout << "Dati pestii rapitori:\n";
        cout << endl;
        for (int i = 1; i <= a.nr_pesti_r; i++)
        {
            Peste *n = new Peste;
            n->citire();
            a.pesti_r.push_front(n);
        }
        cout << "\nDati pestii non-rapitori:\n";
        for (int i = 1; i <= a.nr_pesti_n; i++)
        {
            Peste *n = new Peste;
            n->citire();
            a.pesti_n.push_front(n);
        }
    }
    friend ostream& operator<< (ostream&, const AtlasZoologic& a)
    {
        int nr_p_r;
        cout << "Numar pesti rapitori: " << a.pesti_r.size() << "\n";
        cout << "Numar pesti non-rapitori: " << a.pesti_n.size() << "\n";
        cout << endl;
        list <Peste*> cr;
        list <Peste*> cn;
        cr = a.pesti_r;
        cn = a.pesti_n;
        typename list <Peste*> :: iterator it;
        cout << "\n-------------------\nPesti rapitori\n-------------------\n";
        int nr = 0;
        for(it = cr.begin(); it != cr.end(); ++it)
        {
            Animal *anim = new Animal;
            anim = *it;
            anim->afisare();
            if (anim->get_marime() > 1)
                nr++;
            cout << endl;

        }
        cout << "\n-------------------\nPesti non-rapitori\n-------------------\n";
        for(it = cn.begin(); it != cn.end(); ++it)
        {
            Animal *anim = new Animal;
            anim = *it;
            anim->afisare();
            cout << endl;
        }
        cout << endl;
        cout << "Numar pesti rapitori cu lungimea mai mare de 1m: " << nr << "\n";
    }

    AtlasZoologic& operator=(const AtlasZoologic& a)
    {
        pesti_r = a.pesti_r;
        pesti_n = a.pesti_n;
        nr_pesti_r = a.nr_pesti_r;
        nr_pesti_n = a.nr_pesti_n;
    }

    AtlasZoologic& operator+=(Peste& a)
    {
        if (a.get_tip() == "rapitor")
        {
            nr_pesti_r++;
            pesti_r.push_front(&a);
        }
        else
        {
            nr_pesti_n++;
            pesti_n.push_front(&a);
        }
    }

    ~AtlasZoologic()
    {
        pesti_r.clear();
        pesti_n.clear();
        nr_pesti_r = 0;
        nr_pesti_n = 0;
    }
};
int main()
{
    int op;
    cout << "Alege optiunea(atlas animale = 1, atlas pesti = 2): ";
    cin >> op;
    switch(op)
    {
    case 1:
    {
        AtlasZoologic<Animal> x;
        cin >> x;
        cout << x;
    }
    break;
    case 2:
    {
        AtlasZoologic<Peste> x;
        cin >> x;
        cout << x;
    }
    break;
    }
    return 0;
}
