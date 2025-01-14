//---------------------------------------------------------------------------

#ifndef uFPrincipalH
#define uFPrincipalH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "uCSMemoria.h"
#include "uPila_SMemoria.h"
#include "uCola_SMemoria.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *CrearSMemoria;
	TButton *PonerPila;
	TButton *SacarPila;
	TButton *CrearPila;
	TButton *CrearCola;
	TButton *PonerCola;
	TButton *SacarCola;
	TButton *PrimeroCola;
	TButton *CimaPila;
	TButton *MostrarSM;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit5;
	TEdit *Edit6;
	TButton *Testeo;
	void __fastcall CrearSMemoriaClick(TObject *Sender);
	void __fastcall CrearPilaClick(TObject *Sender);
	void __fastcall PonerPilaClick(TObject *Sender);
	void __fastcall SacarPilaClick(TObject *Sender);
	void __fastcall CimaPilaClick(TObject *Sender);
	void __fastcall CrearColaClick(TObject *Sender);
	void __fastcall PonerColaClick(TObject *Sender);
	void __fastcall SacarColaClick(TObject *Sender);
	void __fastcall MostrarSMClick(TObject *Sender);
	void __fastcall PrimeroColaClick(TObject *Sender);
	void __fastcall TesteoClick(TObject *Sender);
private:	// User declarations
	CSMemoria *mem;
    int elemento;
	PilaM *pila;
	ColaSM *cola;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
