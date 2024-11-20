//---------------------------------------------------------------------------
#ifndef uCola_SMemoriaH
#define uCola_SMemoriaH
//---------------------------------------------------------------------------
#include "uCSMemoria.h"
//---------------------------------------------------------------------------

class ColaSM {
	private:
		CSMemoria *m;
		direccion ini;
		direccion fin;
	public:
		ColaSM(CSMemoria *mem);
		bool Vacia();
		int Primero();
		void Poner(int elemento);
		void Sacar(int &elemento);
};

#endif
