//24K-0673
//HATIM MUSTAFA

#include <iostream>
#include <string>
using namespace std;

class Ghost {
    public:
    string nameOfFirstWorker;
    string nameOfSecondWorker;
    int scareLvl;
    string label;

    Ghost (string n, int s, string l): nameOfFirstWorker(n), scareLvl(s), nameOfSecondWorker(""), label(l) {}

    virtual void Haunt () {
        cout << "Booooooooo\n";
    }

    friend ostream& operator<<(ostream& stream, const Ghost& g) {
        stream << g.label <<  " (" << g.nameOfFirstWorker << ") - scare: " << g.scareLvl;
        return stream;
    }

    void operator + (Ghost& other) {
        nameOfSecondWorker = other.nameOfFirstWorker;
        if (scareLvl + other.scareLvl > 10) {
            scareLvl = 10;
        }
        else {
            scareLvl += other.scareLvl;
        }
    }
};

class Poltergeist: public Ghost {
    public:
    Poltergeist (string n, int s, string l): Ghost(n,s,l) {}

    void Haunt () override {
        cout << "Objects Moving\n";
    }
};

class Banshee: public Ghost {
    public:
    Banshee (string n, int s, string l): Ghost(n,s,l) {}

    void Haunt () override {
        cout << "Loud Screams\n";
    }
};

class ShadowGhost: public Ghost {
    public:
    ShadowGhost (string n, int s, string l): Ghost(n,s,l) {}

    void Haunt () override {
        cout << "Creepy Whispers\n";
    }
};

class ShadowPoltergeist: public Ghost {
    public:
    ShadowPoltergeist (string n, int s, string l): Ghost(n,s,l) {}

    void Haunt () override {
        cout << "Moving Objects and Creepy Whispers\n";
    }
};

class HauntedHouse {
    public:
    string name;
    Ghost** ghosts;

    HauntedHouse () {}

    HauntedHouse (string n, Ghost** g): name(n), ghosts(g) {}
};

class Visitor {
    public:
    string name;
    char bravery;

    Visitor () {}

    Visitor (string n, char b): name(n), bravery(b) {}

    void ScareReaction (Ghost* g) {
        switch(bravery) {
            case 'C':
            if (g->scareLvl >= 1 && g->scareLvl <= 4) {
                cout << "Shaky Voice\n";
            }
            else {
                cout << "Screams and Runs\n";
            }
            break;

            case 'A':
            if (g->scareLvl >= 1 && g->scareLvl <= 4) {
                cout << "Laughs and Taunts\n";
            }
            else if (g->scareLvl >= 5 && g->scareLvl <= 7) {
                cout << "Shaky Voice\n";
            }
            else {
                cout << "Screams and Runs\n";
            }
            break;

            case 'F':
            if (g->scareLvl >= 1 && g->scareLvl <= 7) {
                cout << "Laughs and Taunts\n";
            }
            else {
                cout << "Shaky Voice\n";
            }
        }
    }
};

void Visit (HauntedHouse* house, Visitor* v, int numOfVisitors) {
    for (int i = 0; i < numOfVisitors; i++) {
        cout << v[i].name << "'s Reactions\n";
        for (int j = 0; j < 3; j++) {
            cout << *(house->ghosts[j]) << endl;
            house->ghosts[j]->Haunt();
            v[i].ScareReaction(house->ghosts[j]);
        }
        cout << endl;
    }
}

int main () {
    Visitor* visitors = new Visitor[3];
    visitors[0] = Visitor("George", 'A');
    visitors[1] = Visitor("Allen", 'C');
    visitors[2] = Visitor("Josh", 'F');

    Poltergeist p("Albert", 6, "Poltergeist");
    Banshee b("Emma", 8, "Banshee");
    ShadowGhost sg("Robert", 2, "Shadow Ghost");
    ShadowPoltergeist sp("William", 8, "Shadow Poltergeist");

    Ghost* ghosts1[] = {&sp, &sg, &p};
    Ghost* ghosts2[] = {&sg, &b, &p};

    HauntedHouse* houses = new HauntedHouse[2];
    houses[0] = HauntedHouse("Barren Creek", ghosts1);
    houses[1] = HauntedHouse("Hallway of Death", ghosts2);

    cout << houses[0].name << endl;
    Visit(&houses[0], visitors, 3);
    cout << houses[1].name << endl;
    Visit(&houses[1], visitors, 3);

    delete [] visitors;
    delete [] houses;
}