//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
USEFORM("UnitFormSimulacion.cpp", FormSimulacion);
USEFORM("UnitFormFormulas.cpp", FormFormulas);
USEFORM("UnitFormDosificador.cpp", FormDosificador);
USEFORM("UnitFormConfigDepositos.cpp", FormConfigDepositos);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TFormDosificador), &FormDosificador);
		Application->CreateForm(__classid(TFormSimulacion), &FormSimulacion);
		Application->CreateForm(__classid(TFormFormulas), &FormFormulas);
		Application->CreateForm(__classid(TFormConfigDepositos), &FormConfigDepositos);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
