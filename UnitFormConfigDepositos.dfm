object FormConfigDepositos: TFormConfigDepositos
  Left = 0
  Top = 0
  Caption = 'FormConfigDepositos'
  ClientHeight = 385
  ClientWidth = 689
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 168
    Top = 32
    Width = 359
    Height = 33
    Caption = 'CONFIGURACI'#211'N DEPOSITOS'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object LabelDeposito: TLabel
    Left = 224
    Top = 91
    Width = 46
    Height = 13
    Caption = 'Deposito:'
  end
  object Label2: TLabel
    Left = 56
    Top = 133
    Width = 36
    Height = 13
    Caption = 'Materia'
  end
  object Label3: TLabel
    Left = 292
    Top = 133
    Width = 70
    Height = 13
    Caption = 'Color Deposito'
  end
  object Deposito1: TDeposito
    Left = 512
    Top = 91
    Width = 100
    Height = 168
    Cantidad = 0.700000000000000000
    Color = clOlive
  end
  object ComboBoxDep: TComboBox
    Left = 276
    Top = 88
    Width = 145
    Height = 21
    TabOrder = 0
    OnChange = ComboBoxDepChange
    Items.Strings = (
      'Deposito 1'
      'Deposito 2'
      'Deposito 3'
      'Deposito 4'
      'Deposito 5')
  end
  object ComboBoxMateria: TComboBox
    Left = 56
    Top = 152
    Width = 145
    Height = 21
    TabOrder = 1
    OnChange = ComboBoxMateriaChange
  end
  object LabeledEdit1: TLabeledEdit
    Left = 56
    Top = 208
    Width = 105
    Height = 21
    EditLabel.Width = 89
    EditLabel.Height = 13
    EditLabel.Caption = 'Capacidad M'#225'xima'
    TabOrder = 2
    Text = '1000'
  end
  object ButtonGuardar: TButton
    Left = 48
    Top = 328
    Width = 75
    Height = 25
    Caption = 'Guardar'
    TabOrder = 3
    OnClick = ButtonGuardarClick
  end
  object ButtonExit: TButton
    Left = 568
    Top = 328
    Width = 75
    Height = 25
    Caption = 'Salir'
    TabOrder = 4
    OnClick = ButtonExitClick
  end
  object ColorBox: TColorBox
    Left = 292
    Top = 152
    Width = 145
    Height = 22
    TabOrder = 5
    OnChange = ColorBoxChange
  end
  object ButtonNuevaMateria: TButton
    Left = 207
    Top = 150
    Width = 26
    Height = 25
    Caption = '+'
    TabOrder = 6
    OnClick = ButtonNuevaMateriaClick
  end
end
