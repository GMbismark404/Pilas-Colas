object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 779
  ClientWidth = 1028
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object CrearSMemoria: TButton
    Left = 8
    Top = 24
    Width = 113
    Height = 25
    Caption = 'Crear SMemoria'
    TabOrder = 0
    OnClick = CrearSMemoriaClick
  end
  object PonerPila: TButton
    Left = 8
    Top = 86
    Width = 113
    Height = 25
    Caption = 'Poner Pila'
    TabOrder = 1
    OnClick = PonerPilaClick
  end
  object SacarPila: TButton
    Left = 8
    Top = 117
    Width = 113
    Height = 25
    Caption = 'Sacar Pila'
    TabOrder = 2
    OnClick = SacarPilaClick
  end
  object CrearPila: TButton
    Left = 8
    Top = 55
    Width = 113
    Height = 25
    Caption = 'Crear Pila'
    TabOrder = 3
    OnClick = CrearPilaClick
  end
  object CrearCola: TButton
    Left = 8
    Top = 179
    Width = 113
    Height = 25
    Caption = 'Crear Cola'
    TabOrder = 4
    OnClick = CrearColaClick
  end
  object PonerCola: TButton
    Left = 8
    Top = 210
    Width = 113
    Height = 25
    Caption = 'Poner Cola'
    TabOrder = 5
    OnClick = PonerColaClick
  end
  object SacarCola: TButton
    Left = 8
    Top = 241
    Width = 113
    Height = 25
    Caption = 'Sacar Cola'
    TabOrder = 6
    OnClick = SacarColaClick
  end
  object PrimeroCola: TButton
    Left = 8
    Top = 272
    Width = 113
    Height = 25
    Caption = 'Primero Cola'
    TabOrder = 7
    OnClick = PrimeroColaClick
  end
  object CimaPila: TButton
    Left = 8
    Top = 148
    Width = 113
    Height = 25
    Caption = 'Cima Pila'
    TabOrder = 8
    OnClick = CimaPilaClick
  end
  object MostrarSM: TButton
    Left = 8
    Top = 303
    Width = 113
    Height = 25
    Caption = 'Mostrar SM'
    TabOrder = 9
    OnClick = MostrarSMClick
  end
  object Edit1: TEdit
    Left = 127
    Top = 88
    Width = 74
    Height = 23
    TabOrder = 10
    TextHint = 'elemento'
  end
  object Edit2: TEdit
    Left = 127
    Top = 119
    Width = 74
    Height = 23
    TabOrder = 11
    TextHint = 'TextBoxOut'
  end
  object Edit3: TEdit
    Left = 127
    Top = 150
    Width = 74
    Height = 23
    TabOrder = 12
    TextHint = 'TextBoxOut'
  end
  object Edit4: TEdit
    Left = 127
    Top = 211
    Width = 74
    Height = 23
    TabOrder = 13
    TextHint = 'elemento'
  end
  object Edit5: TEdit
    Left = 127
    Top = 242
    Width = 74
    Height = 23
    TabOrder = 14
    TextHint = 'TextBoxOut'
  end
  object Edit6: TEdit
    Left = 127
    Top = 273
    Width = 74
    Height = 23
    TabOrder = 15
    TextHint = 'TextBoxOut'
  end
  object Testeo: TButton
    Left = 8
    Top = 334
    Width = 113
    Height = 25
    Caption = 'Testear proyecto'
    TabOrder = 16
    OnClick = TesteoClick
  end
end
