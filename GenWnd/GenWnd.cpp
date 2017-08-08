//-------------------------------------------------------------------------------
//  Classe que ontém funções comum à todos controles que possam ser criados.
//  Desta forma, todos a "extenderão", de modo a herdar seus dados.
//
//  Ela também pode ser usada para o susário criar algum tipo de controle per-
//  sonalizado, que tenha como base, a estrutura de janela (WNDCLASSEX),
//  atributos como tamanho, posição, estilos, entre outras variávels, e a fun-
//  ção para criação de Janelas (CreateWindow()).
//
//  Criado por Gabriel Grechuk da Silva Oliveira.
//    <gabrielgrechuk@outlook.com>
//
//  Data: 17:58 06/08/2017
//


//-------------------------------------------------------------------------------
// Bibliotecas para inclusão.
#include "GenWnd.h"


//-------------------------------------------------------------------------------
// Contrutor e destrutor.
GenWnd::GenWnd()
{
	Registered = false;
	Created = false;
	
	
	dwExStyle = 0;
    lpClassName = _T("MAIN_WINDOW");
    lpWindowName = _T("WINDOW");
    dwStyle = WS_OVERLAPPEDWINDOW;
	nWidth = 500;
    nHeight = 500;
    x = (GetSystemMetrics(SM_CXSXREEN) - nWidth) / 2;
    y = (GetSystemMetrics(SM_CYSXREEN) - nHeight) / 2;
    hWndParent = HWND_DESKTOP;
    hMenu = NULL;
    hInstance = GetModule(NULL);
    lpParam = NULL;
}


GenWnd::~GenWnd()
{
	DestroyWindow(hWnd);
}


//-------------------------------------------------------------------------------
// Funções para iniciações.

// Iniciador estrutura.
int GenWnd::Init_Struct(void)
{
	wnd->cbSize = sizeof(WNDCLASSEX);
	wnd->cbClsExtra = 0;
	wnd->cbWndExtra = 0;

	wnd->lpszClassName = _T("MAIN_WINDOW");
	wnd->lpszMenuName = NULL;
	wnd->lpfnWndProc = NULL;

	wnd->hInstance = GetModule(NULL);
	wnd->hCursor = LoadCursor(NULL, IDC_ARROW);
	wnd->hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wnd->hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	wnd->style = CS_HREDRAW | CS_VREDRAW;
	wnd->hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
}


//-------------------------------------------------------------------------------
// Registrando a WNDCLASSEX.
int GenWnd::_RegisterClassEx(void)
{
	if(!RegisterClassEx(&wnd))
	{
		MessageBox(NULL,
			_T("ERROR ao registrar classe da janela"),
			_T("ERROR DA WIN32 API"),
			MB_ICONERROR | MB_OK);
		
		exit(-1);
	}
}


//-------------------------------------------------------------------------------
// Criando a janela.
int GenWnd::Create(void)
{
	hWnd = CreateWindowEx(dwExStyle,
		lpClassName,
		lpWindowName,
		dwStyle,
		x,
		y,
		nWidth,
		nHeight,
		hWndParent,
		hMenu,
		hInstance,
		lpParam);
		
	if(!hWnd)
	{
		MessageBox(NULL,
			_T("ERROR ao criar a janela principal"),
			_T("ERROR DA WIN32 API"),
			MB_ICONERROR | MB_OK);
			
		exit(-1);
	}
}


//-------------------------------------------------------------------------------
// Funções para settar dados referentes às janelas e etc...
int GenWnd::Set_style(UINT s)
{
	if(!Registered && !Created)
	{
		wnd->style = s;
		return 1;
	}
	
	else
	{
		return 0;
	}
}


//-------------------------------------------------------------------------------
int GenWnd::Set_cbSize(UINT c)
{
	if(!Registered && !Created)
	{
		wnd->cbSize = c;
		return 1;
	}
	
	else
	{
		return 0;
	}
}


//-------------------------------------------------------------------------------
int GenWnd::Set_cbClsExtra(int c)
{
	if(!Registered && !Created)
	{
		wnd->cbClsExtra = c;
		return 1;
	}
	
	else
	{
		return 0;
	}
}


//-------------------------------------------------------------------------------
int GenWnd::Set_cbWndExtra(int c)
{
	if(!Registered && !Created)
	{
		wnd->cbWndExtra = c;
		return 1;
	}
	
	else
	{
		return 0;
	}
}


//-------------------------------------------------------------------------------
int GenWnd::Set_lpfnWndProc(WNDPROC f)
{
	if(!Registered && !Created)
	{
		wnd->lpfnWndProc = f;
		return 1;
	}
	
	else
	{
		return 0;
	}
}


///------------------------------------------------------------------------------
int GenWnd::Set_lpszMenuName(LPCTSTR *s)
{
	if(!Registered && !Created)
	{
		// TODO.
		return 1;
	}
	
	else
	{
		return 0;
	}
}


///------------------------------------------------------------------------------
int GenWnd::Set_lpszClassName(LPCTSTR *s)
{
	if(!Registered && !Created)
	{
		// TODO.
		return 1;
	}
	
	else
	{
		return 0;
	}
}


//-------------------------------------------------------------------------------
int GenWnd::Set_hInstance(HINSTANCE h)
{
	if(!Registered && !Created)
	{
		wnd->hInstance = h;
		return 1;
	}
	
	else
	{
		return 0;
	}
}


//-------------------------------------------------------------------------------
int GenWnd::Set_hIcon(HICON h)
{
	if(!Registered && !Created)
	{
		wnd->hIcon = h;
		return 1;
	}
	
	else
	{
		return 0
	}
}


//-------------------------------------------------------------------------------
int GenWnd::Set_hIconSm(HICON h)
{
	if(!Registered && !Created)
	{
		wnd->hIconSm = h;
		return 1;
	}
	
	else
	{
		return 0;
	}
}


//-------------------------------------------------------------------------------
int GenWnd::Set_hCursor(HCURSOR h)
{
	if(!Registered && !Created)
	{
		wnd->hCursor = h;
		return 1;
	}
	
	else
	{
		return 0;
	}
}


//-------------------------------------------------------------------------------
int GenWnd::hbrBackground(HBRUSH h)
{
	if(!Registered && !Created)
	{
		wnd->hbrBackground = h;
		return 1;
	}
	
	else
	{
		return 0;
	}
}
