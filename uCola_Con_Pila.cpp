//---------------------------------------------------------------------------
#pragma hdrstop
#include "uCola_Con_Pila.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

ColaFRC::ColaFRC(CSMemoria *mem) {
//	m = mem;
//	ini = NULO;
//	fin = NULO;
	C = new PilaM(mem);
}

bool ColaFRC::Vacia() {
	return ini == NULO;
}

void ColaFRC::Poner(int elemento) {
//	direccion aux = m->new_espacio("elemento,sig");
//	if (aux != NULO) {
//		m->poner_dato(aux, "->elemento", elemento);
//		m->poner_dato(aux, "->sig", NULO);
//		if (Vacia()) {
//			ini = aux;
//			fin = aux;
//		} else {
//			m->poner_dato(fin, "->sig", aux);
//			fin = aux;
//		}
//	} else {
//		ShowMessage("Error: espacio de memoria insuficiente!");
//	}
//---------------------------------------------------------------------------
	C->Meter(elemento);
//---------------------------------------------------------------------------
}

int ColaFRC::Primero() {
//	if (Vacia()) {
//		ShowMessage("Error: la pila está vacía!"); return -1;
//	} else {
//		return m->obtener_dato(ini, "->elemento");
//	}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
}

void ColaFRC::Sacar(int &elemento) {
//	if (!Vacia()) {
//		elemento = m->obtener_dato(ini, "->elemento");
//		direccion x = ini;
//		ini = m->obtener_dato(ini, "->sig");
//		m->delete_espacio(x);
//	}
//---------------------------------------------------------------------------
	PilaM *x = new PilaM(mem);
	int aux;
	while (!C->Vacia()) {
		C->Sacar(aux);
		x->Meter(aux);
	}
	elemento = aux;
	int inte = 1;
	while (!x->Vacia()) {
		x->Sacar(aux);
		if (inte > 1) {
			C->Meter(aux);
		}
	}
//---------------------------------------------------------------------------
}
