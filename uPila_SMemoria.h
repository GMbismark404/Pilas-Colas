//---------------------------------------------------------------------------
#ifndef uPila_SMemoriaH
#define uPila_SMemoriaH
//---------------------------------------------------------------------------
#include <Vcl.Dialogs.hpp>
#include <Graphics.hpp>
#include "uCSMemoria.h"
#include <cmath>
#include <Vcl.Graphics.hpp>
//---------------------------------------------------------------------------
struct Nodofil{
	int elemento;
	int sig;
};

class PilaM{
	private:
		CSMemoria* m;
		direccion tope;
	public:
		PilaM(CSMemoria *mem);
		bool Vacia();
		void Meter(int elemento);
		void Sacar(int &elemento);
		int Cima();
		bool EsDigito(AnsiString infija, int pos);
		bool EsOperador(AnsiString infija, int pos);
		int PrioridadInfija(char c);
		int PrioridadPila(char c);
		bool ParentesisOk(AnsiString expresion);
		AnsiString InfijaToPostFija(AnsiString infija);
		double Evalua(double op1, char operador, double op2);
		double EvaluarPostfija(AnsiString expPostfija);
		bool DibujarCeldas(TCanvas *canvas, bool &dibujar, int cantCeldas);
		void MostrarPila(TCanvas *canvas, int x, int y);
};

#endif
