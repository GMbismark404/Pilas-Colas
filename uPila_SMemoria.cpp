//---------------------------------------------------------------------------
#pragma hdrstop
#include "uPila_SMemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

PilaM::PilaM(CSMemoria *mem){
	tope = NULO;
	m = mem;
}

bool PilaM::Vacia(){
	return tope == NULO;
}

void PilaM::Meter(int elemento){
	direccion x = m->new_espacio("elemento,sig");
	if (x != NULO) {
		m->poner_dato(x, "->elemento", elemento);
		m->poner_dato(x, "->sig", tope);
		tope = x;
	} else {
		ShowMessage("Error: espacio de memoria insuficiente!");
	}
}

void PilaM::Sacar(int &elemento){
	if (Vacia()) {
		ShowMessage("Error: la pila est� vac�a!");
        elemento = -1;
	} else {
		direccion x = tope;
		elemento = m->obtener_dato(tope, "->elemento");
		tope = m->obtener_dato(tope, "->sig");
		m->delete_espacio(x);
	}
}

int PilaM::Cima(){
	if (Vacia()) {
		ShowMessage("Error: la pila est� vac�a!");
	} else {
		return (m->obtener_dato(tope,"->elemento"));
	}
}

bool PilaM::EsDigito(AnsiString infija, int pos) {
	for (int i = 0; i < 10; i++) {
		if (StrToInt(infija.c_str()[pos]) == i) {
			return true;
		}
	}
	return false;
}

bool PilaM::EsOperador(AnsiString infija, int pos) {
	AnsiString operador = "^*/+-()";
	for (int i = 0; i < operador.Length(); i++) {
		if (infija.c_str()[pos] == operador.c_str()[i]) {
			return true;
		}
	}
	return false;
}

int PilaM::PrioridadInfija(char c) {
	switch (c) {
		case '^': {
			return 4;
		} break;
		case '*': {
			return 2;
		} break;
		case '/': {
			return 2;
		} break;
		case '+': {
			return 1;
		} break;
		case '-': {
			return 1;
		} break;
		case '(': {
			return 5;
		} break;
	default:
		;
	}
}

int PilaM::PrioridadPila(char c) {
	switch (c) {
		case '^': {
			return 3;
		} break;
		case '*': {
			return 2;
		} break;
		case '/': {
			return 2;
		} break;
		case '+': {
			return 1;
		} break;
		case '-': {
			return 1;
		} break;
		case '(': {
			return 0;
		} break;
	default:
		;
	}
}

bool PilaM::ParentesisOk(AnsiString expresion) {
	int aux = Cima();
	for (int i = 0; i < expresion.Length(); i++) {
		if (expresion.c_str()[i] == '(') {
			Meter(expresion.c_str()[i]);
		}

		if (expresion.c_str()[i] == ')') {
			Sacar(aux);
		}
	}
	return (Vacia());
}

AnsiString PilaM::InfijaToPostFija(AnsiString infija) {
	AnsiString postfija = ""; int aux = Cima();
	for (int i = 0; i < infija.Length(); i++) {
		if (EsDigito(infija, i)) {
			postfija = postfija + infija.c_str()[i];
		} else {
			if (EsOperador(infija, i)) {
				bool salir = false;
				while (!salir) {
					if (Vacia() || PrioridadInfija(infija.c_str()[i]) > PrioridadPila(IntToStr(aux).c_str()[0])) {
						Meter(StrToInt(infija.c_str()[i]));
						salir = true;
					} else {
						Sacar(aux);
						postfija = postfija + IntToStr(aux);
					}
				}
			} else {
				if (infija.c_str()[i] == ')') {
					do {
						Sacar(aux);
						if (IntToStr(aux).c_str()[0] != '(') {
							postfija = postfija + aux;
						}
					} while (IntToStr(aux).c_str()[0] == '(');

				}
			}
        }
	}

	while (!Vacia()) {
		Sacar(aux);
		postfija = postfija + IntToStr(aux);
	}

	return postfija;
}

double PilaM::Evalua(double op1, char operador, double op2) {
	switch (operador) {
		case '^': {
			return pow(op1, op2);
		} break;
		case '*': {
			return op1*op2;
		} break;
		case '/': {
			return op1*op2;
		} break;
		case '+': {
			return op1*op2;
		} break;
		case '-': {
			return op1*op2;
		} break;
	default:
		;
	}
}

double PilaM::EvaluarPostfija(AnsiString expPostfija) {
	for (int i = 0; i < expPostfija.Length(); i++) {
		if (EsOperador(expPostfija, i)) {
			Meter(expPostfija.c_str()[i]);
		} else {
			int op1;
			int op2;
			Sacar(op1);
			Sacar(op2);
			char sim_operacion = expPostfija.c_str()[i];
			int z = Evalua(op1, sim_operacion, op2);
			Meter(z);
        }
	}
	return Cima();
}

bool PilaM::DibujarCeldas(TCanvas *canvas, bool &dibujar, int cantCeldas) {
	if (!dibujar) {
		int x1, x2, y1, y2;
		x1 = 850; x2 = 900; y1 = 800; y2 = 850;

		canvas->Font->Name = L"Comic Sans MS";
		canvas->Font->Size = 12;
		canvas->Font->Color = clBlack;

		canvas->Pen->Color = clBlack; // Color del borde
		canvas->Brush->Color = clLime; // Color de fondo
		canvas->Rectangle(x1, y1, x2 + 50, y2); // Dibujar la celda
		canvas->TextOutW(x1 + 35, y1 + 12, L"Pila");
		y1 -= 50; y2 -= 50;

		canvas->Brush->Color = clYellow; // Actualizar color de fondo

		for (int i = 0; i < cantCeldas; i++) {
			canvas->Rectangle(x1, y1, x2 + 50, y2); // Dibujar la celda
			y1 -= 50; y2 -= 50;
		}
		dibujar = true;
	} else {
		dibujar = true;
	}
	return dibujar;
}

void PilaM::MostrarPila(TCanvas *canvas, int x, int y) {
//	int y = 850;
//	int elemento = 0;
//	bool dibujar = false;
//	if (DibujarCeldas(canvas, dibujar, 13)) {
//		if (!Vacia()) {
//			elemento = Cima();
//			canvas->TextOutW(850 + 35, y + 12, IntToStr(elemento));
//			y -= 50;
//		}
//	}

AnsiString cad = "<| ";
	for (direccion p = tope; p != NULO; p = m->obtener_dato(p, "->sig")) {
		if (!Vacia()) {
			cad =  cad + AnsiString(IntToStr(m->obtener_dato(p, "->exp"))) + ", ";
			cad =  cad + AnsiString(IntToStr(m->obtener_dato(p, "->coef"))) + ", ";
		} else
			cad = "La lista est� vac�a!";
	}

	canvas->Font->Size = 38;
	canvas->TextOutW(x, y, cad.Delete(cad.Length() - 1, 2) + L" |>");
}

