//---------------------------------------------------------------------------
#ifndef uCSMemoriaH
#define uCSMemoriaH
//---------------------------------------------------------------------------
#include <Vcl.Graphics.hpp>
//---------------------------------------------------------------------------
const int MAX = 20;
const int NULO = -1;

typedef int direccion;

struct NodoSM {
	int dato;
	AnsiString id;
	direccion link;
};

class CSMemoria {
	private: // Atributos:
		NodoSM mem[MAX];
		direccion libre;
	private: //Metodos privados:
		int numero_ids(AnsiString cadena);
		void eliminar_flecha(AnsiString &cadena_id);
		AnsiString obtener_id(AnsiString cadena, int pos);
	public: //Metodos publicos:
		CSMemoria();
		direccion new_espacio(AnsiString cadena);
		void delete_espacio(direccion dir);
		void poner_dato(direccion dir, AnsiString cadena_id, int valor);
		int obtener_dato(direccion dir, AnsiString cadena_id);
		int espacio_disponible();
		int espacio_ocupado();
		bool dir_libre(direccion dir);
		void Mostrar(TCanvas *canvas, int desde, int hasta);
};

#endif
