#include "Colectie.h"
#include "IteratorColectie.h"
#include <exception>
#include <iostream>

using namespace std;

Nod::Nod(TElem e, TElem* st, TElem* dr) {
	this->cap = 8;
	this->elem = e;
	this->st = new TElem[cap];
	this->dr = new TElem[cap];
}

TElem Nod::stanga(int index) {
	return this->st[index];
}

TElem Nod::dreapta(int index) {
	return this->dr[index];
}

TElem Nod::element() {
	return this->elem;
}

void Nod::resize() {
	int new_cap = cap * 2;
	TElem* newSt = new TElem[new_cap];
	TElem* newDr = new TElem[new_cap];
	cap = new_cap;
	for (int i = 0; i < new_cap; i++) {
		newSt[i] = this->st[i];
		newDr[i] = this->dr[i];
	}
	delete[] this->st;
	this->st = newSt;
	delete[] this->dr;
	this->dr = newDr;
}

Colectie::Colectie() {
	/* de adaugat */
	this->rad = nullptr;
	this->size = 0;
}

Nod Colectie::createNode(TElem e) {
	/* de adaugat
	 *  CF: 0(cap)
	 *  CD: 0(cap)
	 *  CG: 0(cap)
	 *  CM: 0(cap)
	 */
	auto p = Nod(e, nullptr, nullptr);
	p.elem = e;
	for (int i = 0; i < p.cap; i++) {
		p.st[i] = 0;
		p.dr[i] = 0;
	}
	return p;
}

Nod* Colectie::adauga_rec(Nod* p, TElem elem) {
	/* de adaugat
	 *  CF: 0(1)
	 *  CD: 0(this->size)
	 *  CG: O(this->size)
	 *  CM: O(this->size)
	 */
	for (int i = 0; i < p->cap; i++) {
		if (p == nullptr) p = new Nod(elem, p->st, p->dr);
		else if (elem <= p->elem) adauga_rec(p, elem);
		else adauga_rec(p, elem);
	}
	return p;
}

//adauga un element in colectie
void Colectie::adauga(TElem elem) {
	/* de adaugat
	 *  CF: 0(1)
	 *  CD: 0(this->size)
	 *  CG: O(this->size)
	 *  CM: O(this->size)
	 */
	this->rad = adauga_rec(this->rad, elem);
}

Nod* Colectie::minim(Nod* p) {
	for (int i = 0; i < p->cap; i++) {
		while (p->st[i] != 0) {
			p->st[i] = p->st[i];
		}
	}
	return p;
}

Nod* Colectie::sterge_rec(Nod* p, TElem e) {
	/* de adaugat
	 *  CF: 0(1)
	 *  CD: 0(this->size)
	 *  CG: O(this->size)
	 *  CM: O(this->size)
	 */
	if (p == nullptr) sterge_rec(p, e);
	else if (e < p->elem) sterge_rec(p, e);
	else if (e > p->elem) sterge_rec(p, e);
	else if (p != nullptr) {
		auto temp = minim(p);
		p->elem = temp->elem;
		sterge_rec(p, p->elem);
	}
	else {
		auto temp = p;
		if (p->st == nullptr) {
			auto repl = p->dr;
		}
		else auto repl = p->st;
	}
	return p;
}

//sterge o aparitie a unui element din colectie
//returneaza adevarat daca s-a putut sterge
bool Colectie::sterge(TElem elem) {
	/* de adaugat
	 *  CF: 0(1)
	 *  CD: 0(this->size)
	 *  CG: O(this->size)
	 *  CM: O(this->size)
	 */
	this->rad = sterge_rec(this->rad, elem);
	if (this->rad != nullptr) return true;
	else return false;
}

//verifica daca un element se afla in colectie
bool Colectie::cauta(TElem elem) const {
	/* de adaugat
	 *  CF: 0(1)
	 *  CD: 0(this->size)
	 *  CG: O(this->size)
	 *  CM: O(this->size)
	 */
	auto p = this->rad;
	for (int i = 0; i < this->size; i++) {
		while (p != nullptr && p->elem != elem) {
			if (elem < p->elem) p->elem = p->st[i];
			else p->elem = p->dr[i];
		}
		return true;
	}
	return false;
}

//returneaza numar de aparitii ale unui element in colectie
int Colectie::nrAparitii(TElem elem) const {
	/* de adaugat
	 * CF: 0(1)
	 *  CD: 0(this->size)
	 *  CG: O(this->size)
	 *  CM: O(this->size)
	 */
	int cnt = 0;
	auto it = this->iterator();
	it.prim();
	while (it.valid()) {
		if (it.element() == elem) cnt++;
		it.urmator();
	}
	return cnt;
}

int Colectie::dim() const {
	/* de adaugat */
	return this->size;
}

bool Colectie::vida() const {
	/* de adaugat */
	if (this->size == 0) return true;
	else return false;
}

IteratorColectie Colectie::iterator() const {
	return  IteratorColectie(*this);
}

void Colectie::destroy_rec(Nod* p) {
	for (int i = 0; i < p->cap; i++) {
		if (p != nullptr) {
			destroy_rec(p);
			delete p;
		}
	}
}

Colectie::~Colectie() {
	/* de adaugat */
	destroy_rec(this->rad);
}
