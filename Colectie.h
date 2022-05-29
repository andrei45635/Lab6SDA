#pragma once
#include <vector>
#define NULL_TELEM -1
typedef int TElem;

using std::vector;

class IteratorColectie;

class Nod {
public:
	TElem elem;
	TElem* st;
	TElem* dr;
	//Nod* st;
	//Nod* dr;
	int cap;

	Nod(TElem elem, TElem* st, TElem* dr);
	TElem stanga(int index);
	TElem dreapta(int index);
	TElem element();
	void resize();
};

class Colectie
{
	friend class IteratorColectie;
	friend class Nod;

private:
	/* aici e reprezentarea */
	Nod* rad;
	int size;
public:
	//constructorul implicit
	Colectie();

	Nod createNode(TElem e);

	//adauga un element in colectie
	void adauga(TElem e);

	Nod* adauga_rec(Nod* p, TElem e);

	Nod* minim(Nod* p);

	//sterge o aparitie a unui element din colectie
	//returneaza adevarat daca s-a putut sterge
	bool sterge(TElem e);

	Nod* sterge_rec(Nod* p, TElem e);

	//verifica daca un element se afla in colectie
	bool cauta(TElem elem) const;

	//returneaza numar de aparitii ale unui element in colectie
	int nrAparitii(TElem elem) const;

	//intoarce numarul de elemente din colectie;
	int dim() const;

	//verifica daca colectia e vida;
	bool vida() const;

	//returneaza un iterator pe colectie
	IteratorColectie iterator() const;

	void destroy_rec(Nod* p);

	// destructorul colectiei
	~Colectie();
};

