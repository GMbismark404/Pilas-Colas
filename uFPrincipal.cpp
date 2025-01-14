//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uFPrincipal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CrearSMemoriaClick(TObject *Sender)
{
    mem = new CSMemoria;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CrearPilaClick(TObject *Sender)
{
	pila = new PilaM(mem);
	elemento = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PonerPilaClick(TObject *Sender)
{
	pila->Meter(StrToInt(Edit1->Text));
	elemento = StrToInt(Edit1->Text);
	Edit2->Text = IntToStr(elemento);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SacarPilaClick(TObject *Sender)
{
	elemento = StrToInt(Edit2->Text);
	pila->Sacar(elemento);
	Edit2->Text = pila->Cima();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CimaPilaClick(TObject *Sender)
{
	Edit3->Text = IntToStr(pila->Cima());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CrearColaClick(TObject *Sender)
{
	cola = new ColaSM(mem);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PonerColaClick(TObject *Sender)
{
	cola->Poner(StrToInt(Edit4->Text));
	elemento = StrToInt(Edit4->Text);
    Edit5->Text = IntToStr(elemento);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SacarColaClick(TObject *Sender)
{
	elemento = StrToInt(Edit5->Text);
	cola->Sacar(elemento);
	Edit5->Text = cola->Primero();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PrimeroColaClick(TObject *Sender)
{
    Edit6->Text = cola->Primero();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MostrarSMClick(TObject *Sender)
{
	mem->Mostrar(Form1->Canvas, 0, 13);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TesteoClick(TObject *Sender)
{
	cola->Poner(5);
	cola->Poner(6);
}
//---------------------------------------------------------------------------

