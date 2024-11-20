//---------------------------------------------------------------------------
#ifndef uCola_Con_PilaH
#define uCola_Con_PilaH
//---------------------------------------------------------------------------
#include "uPila_SMemoria.h"

class ColaFRC {
	private:
		PilaM *C;
	public:
		ColaFRC(CSMemoria *mem);
		bool Vacia();
		int Primero();
		void Poner(int elemento);
		void Sacar(int &elemento);
};

#endif
