//---------------------------------------------------------------------------
#pragma hdrstop
#include "uCola_SMemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

ColaSM::ColaSM(CSMemoria *mem) {
	m = mem;
	ini = NULO;
	fin = NULO;
}

bool ColaSM::Vacia() {
	return ini == NULO;
}

void ColaSM::Poner(int elemento) {
	direccion aux = m->new_espacio("elemento,sig");
	if (aux != NULO) {
		m->poner_dato(aux, "->elemento", elemento);
		m->poner_dato(aux, "->sig", NULO);
		if (Vacia()) {
			ini = aux;
			fin = aux;
		} else {
			m->poner_dato(fin, "->sig", aux);
			fin = aux;
        }
	} else {
		ShowMessage("Error: espacio de memoria insuficiente!");
    }
}

int ColaSM::Primero() {
	if (Vacia()) {
		ShowMessage("Error: la pila est� vac�a!"); return -1;
	} else {
		return m->obtener_dato(ini, "->elemento");
    }
}

void ColaSM::Sacar(int &elemento) {
	if (!Vacia()) {
		elemento = m->obtener_dato(ini, "->elemento");
		direccion x = ini;
		ini = m->obtener_dato(ini, "->sig");
		m->delete_espacio(x);
	}
}
