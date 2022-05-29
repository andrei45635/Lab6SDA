#include "IteratorColectie.h"
#include "Colectie.h"


IteratorColectie::IteratorColectie(const Colectie& c) : col(c) {
	/* de adaugat */
	//this->index = 0;
	this->index = col.rad->element();
}

TElem IteratorColectie::element() const {
	/* de adaugat */
	if (!valid()) throw std::exception("invalid\n");
	else return col.rad->element();
}

bool IteratorColectie::valid() const {
	/* de adaugat */
	if (this->index < 0) return false;
	else return true;
}

void IteratorColectie::urmator() {
	/* de adaugat */
	if (!valid()) throw std::exception("invalid\n");
	else this->index++;
}

void IteratorColectie::prim() {
	/* de adaugat */
	this->index = col.rad->element();
}
