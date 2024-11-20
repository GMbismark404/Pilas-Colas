//---------------------------------------------------------------------------
#pragma hdrstop
#include "uCSMemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

CSMemoria::CSMemoria()
{
	for (int i = 0; i < MAX - 1; i++) {
		mem[i].link = i + 1;
		mem[i].dato = 0;
//		mem[i].id= " ";
	}
	mem[MAX - 1].link = NULO;
	mem[MAX - 1].dato = 0;
//	mem[MAX - 1].id= " ";
	this->libre = 0;
}

int CSMemoria::new_espacio(AnsiString cad) { // añade los ids y devuelve una direccion
	int cant = numero_ids(cad);         // cad = "ci,fono,edad" -> 3
	int dir = libre;
	int d = libre;
	for (int i = 0; i < cant - 1; i++) {
		mem[d].id = obtener_id(cad,i);
		d = mem[d].link;
	}

	libre = mem[d].link;
	mem[d].link = -1;
	mem[d].id = obtener_id(cad, cant - 1);
return dir;
}

void CSMemoria::delete_espacio(direccion dir) {
	direccion x = dir;
	while (mem[x].link != NULO) {
		x = mem[x].link;
	}
	mem[x].link = libre;
	libre = dir;
}

void CSMemoria::poner_dato(direccion dir, AnsiString cadena_id, int valor) {
	direccion z = dir;
	eliminar_flecha(cadena_id);
	while (z != NULO) {
		if (mem[z].id == cadena_id) {
			mem[z].dato = valor;
		}
		z = mem[z].link;
	}
}

int CSMemoria::obtener_dato(direccion dir, AnsiString cadena_id) {
	direccion z = dir; bool ex = false;
	eliminar_flecha(cadena_id);
	while (z != NULO) {
		if (mem[z].id == cadena_id) {
			return mem[z].dato;
		}
		z = mem[z].link;
	}
    return NULO;
}

int CSMemoria::espacio_disponible() {
int contador = 0;
	for (direccion x = libre; (x < MAX) && (x != NULO) ; x = mem[x].link) {
		contador++;
	}
return contador;
}

int CSMemoria::espacio_ocupado() {
	return MAX - espacio_disponible();
}

bool CSMemoria::dir_libre(direccion dir)
{
	direccion x = libre; bool c = false;
	while (x != NULO && c == false) {
		if (x == dir) {
			c = true;
		}
		x = mem[x].link;
	}
    return c;
}

//---------------------------Metodos privados--------------------------------

int CSMemoria::numero_ids(AnsiString id) { // "dia,mes,año"
int c = 0;
	if (id.c_str() == ""){
		return c;
	}else{
		for (int i = 0; i < id.Length() - 1; i++)
			if ((id.c_str()[i] != ',') && (id.c_str()[i+1] == ','))
				c++;

		if (id[id.Length() - 1] != ',')
			c++;
	}
return c;
}


AnsiString CSMemoria::obtener_id(AnsiString cad, int pos) {  // "ci,fono,edad"
int p = 0; AnsiString s = ""; int c = 0;

	while (cad.c_str()[c] == ',')
		c++;

	for (int i = c; i < cad.Length(); i++) {
		if (cad.c_str()[i] == ',') {
			i++; p++;
		}

		if (p == pos) {
			s = s + AnsiString(cad.c_str()[i]);
		}
	}
return s;
}

void CSMemoria::eliminar_flecha(AnsiString &cadena_id) {
	if (cadena_id.Pos("->") == 1) { // Si la posición de "->" es 1 (al inicio)
		cadena_id = cadena_id.Delete(1, 2); // Elimina los primeros 2 caracteres
	}
}

//---------------------------Mostrar Memoria---------------------------------

void CSMemoria::Mostrar(TCanvas *canvas, int desde, int hasta)
{
int x1, x2, y1, y2;
x1 = 450; x2 = 500; y1 = 50; y2 = 100;

canvas->Font->Name = L"Comic Sans MS";
canvas->Font->Size = 12;
canvas->Font->Color = clBlack;

	for (int i = 0; i < 4; i++) {
		canvas->Brush->Color = clWhite;
		switch (i) {
			case 0: {
				canvas->TextOutW(x1 - 50, y1 - 50 + 15, L"dir");
			} break;
			case 1: {
				canvas->TextOutW(x1 - 70, y1 - 50 + 15, L"datos");

			} break;
			case 2: {
				canvas->TextOutW(x1 - 60, y1 - 50 + 15, L"id");
			} break;
			case 3: {
				canvas->TextOutW(x1 - 60, y1 - 50 + 15, L"link");
			} break;
		}
		x1 += 100;
	}

	x1 = 450; x2 = 500;

	for (int fila = desde; fila <= hasta; ++fila) {
		for (int columna = 0; columna < 4; ++columna) {
			switch (columna) {
				case 0: {
					canvas->Brush->Color = clWhite;
					canvas->TextOutW(x1 - 50, y1 + 15, L"" + IntToStr(fila));
				} break;
				case 1: {
					canvas->Pen->Color = clBlack; // Color del borde
					canvas->Brush->Color = clLime; // Color de fondo
					canvas->Rectangle(x1, y1, x2 + 50, y2); // Dibujar la celda
//					if (mem[fila].dato != 0) {
						canvas->TextOutW(x1 + 45, y1 + 15, L"" + IntToStr(mem[fila].dato));
//					} else {
//						canvas->TextOutW(x1 + 45, y1 + 15, L"");
//					}
					x1 += 100; x2 += 100;
				} break;
				case 2: {
					canvas->Pen->Color = clBlack; // Color del borde
					canvas->Brush->Color = clYellow; // Color de fondo
					canvas->Rectangle(x1, y1, x2 + 50, y2); // Dibujar la celda

					canvas->TextOutW(x1 + 30, y1 + 15, AnsiString(mem[fila].id.c_str()));
					x1 += 100; x2 += 100;
				} break;
				case 3: {
					canvas->Pen->Color = clBlack; // Color del borde
					canvas->Brush->Color = clYellow; // Color de fondo
					canvas->Rectangle(x1, y1, x2 + 50, y2); // Dibujar la celda

					canvas->TextOutW(x1 + 50, y1 + 15, IntToStr(mem[fila].link));
					x1 += 100; x2 += 100;
				}
			}
		}
			x1 = 450; x2 = 500;
			y1 += 50; y2 += 50;
	}
	TRect rect(x1, y1, x2, y2); // Limpia todo el formulario
	canvas->Brush->Color = clWhite; // Color de fondo (blanco)
	canvas->FillRect(rect); // Rellena el área con el color de fondo
	canvas->TextOutW(x1 + 30, y1 + 15, L"Libre = " + IntToStr(libre));
}
