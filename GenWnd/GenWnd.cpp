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
	
	return 0;
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
		
		return (-1);
	}
	
	Registered = true;
	return 0;
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
			
		return (-1);
	}
	
	Created = true;
	return 0;
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
int GenWnd::Set_lpszMenuName(LPCTSTR s)
{
	if(!Registered && !Created)
	{
		wnd->lpszMenuName = s
		return 1;
	}
	
	else
	{
		return 0;
	}
}


///------------------------------------------------------------------------------
int GenWnd::Set_lpszClassName(LPCTSTR s)
{
	if(!Registered && !Created)
	{
		wnd->lpszClassName = s;
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
int GenWnd::Set_hbrBackground(HBRUSH h)
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



/* Setters do refentes aos dados de criação da janela. */
//-------------------------------------------------------------------------------
int GenWnd::Set_dwExStyle(DWORD s)
{
	if(!Registered && !Created)
	{
		dwExStyle = s;
		return 1;
	}
	
	else
	{
		return 0;
	}
}


//-------------------------------------------------------------------------------
int GenWnd::Set_lpClassName(LPCTSTR s)
{
	if(!Registered && !Created)
	{
		lpClassName = s;
		return 1;
	}
	
	else
	{
		return 0;
	}
}


//-------------------------------------------------------------------------------
int GenWnd::Set_lpWindowName(LPCTSTR s)
{
	if(!Registered && !Created)
	{
		lpWindowName = s;
		return 1;
	}
	
	else
	{
		return 0;
	}
}


//-------------------------------------------------------------------------------
int GenWnd::Set_dwStyle(DWORD s)
{
	if(!Registered && !Created)
	{
		dwStyle = s;
		return 1;
	}
	
	else
	{
		return 0;
	}
}


//-------------------------------------------------------------------------------
int GenWnd::Set_x(int _x)
{
	if(!Registered && !Created)
	{
		x = _x;
		return 1;
	}
	
	else
	{
		return 0;
	}
}


//-------------------------------------------------------------------------------
int GenWnd::Set_y(int _y)
{
	if(!Registered && !Created)
	{
		y = _y;
		return 1;
	}
	
	else
	{
		return 0;
	}
}


//-------------------------------------------------------------------------------
int GenWnd::Set_nWidth(int w)
{
	if(!Registered && !Created)
	{
		nWidth = w;
		return 1;
	}
	
	else
	{
		return 0;
	}
}


//-------------------------------------------------------------------------------
int GenWnd::Set_nHeight(int h)
{
	if(!Registered && !Created)
	{
		nHeight = h;
		return 1;
	}
	
	else
	{
		return 0;
	}
}


//-------------------------------------------------------------------------------
int GenWnd::Set_hWndParent(HWND h)
{
	if(!Registered && !Created)
	{
		hWndParent = h;
		return 1;
	}
	
	else
	{
		return 0;
	}
}


//-------------------------------------------------------------------------------
int GenWnd::Set_hMenu(HMENU h)
{
	if(!Registered && !Created)
	{
		hMenu = h;
		return 1;
	}
	
	else
	{
		return 0;
	}
}


//-------------------------------------------------------------------------------
int GenWnd::Set_lpParam(LPVOID l)
{
	if(!Registered && !Created)
	{
		lpParam = l;
		return 1;
	}
	
	else
	{
		return 0;
	}
}



//-------------------------------------------------------------------------------
// Getters.
HWND GenWnd::hWnd(void)
{
	return hWnd;
}


//-------------------------------------------------------------------------------
UINT GenWnd::Get_style(void)
{
	return wnd->style;
}


//-------------------------------------------------------------------------------
UINT GenWnd::Get_cbSize(void)
{
	return wnd->cbSize;
}


//-------------------------------------------------------------------------------
int GenWnd::Get_cbClsExtra(void)
{
	return wnd->cbClsExtra;
}


//-------------------------------------------------------------------------------
int GenWnd::Get_cbWndExtra(void)
{
	return wnd->cbWndExtra;
}


//-------------------------------------------------------------------------------
WNDPROC GenWnd::Get_lpfnWndProc(void)
{
	return wnd->lpfnWndProc; 
}


//-------------------------------------------------------------------------------
LPCTSTR GenWnd::Get_lpszMenuName(void)
{
	return wnd->lpszMenuName;
}


//-------------------------------------------------------------------------------
LPCTSTR GenWnd::Get_lpszClassName(void)
{
	return wnd->lpszClassName;
}


//-------------------------------------------------------------------------------
HINSTANCE GenWnd::Get_hInstance(void)
{
	return wnd->hInstance;
}


//-------------------------------------------------------------------------------
HICON GenWnd::Get_hIcon(void)
{
	return wnd->hIcon;
}


//-------------------------------------------------------------------------------
HICON GenWnd::Get_hIconSm(void)
{
	return wnd->hIconSm;
}


//-------------------------------------------------------------------------------
HCURSOR GenWnd::Get_hCursor(void)
{
	return hCursor;
}


//-------------------------------------------------------------------------------
HBRUSH GenWnd::Get_hbrBackground(void)
{
	return wnd->hbrBackground;
}



//-------------------------------------------------------------------------------
// Getters referente à criação da janela.
DWORD GenWnd::Get_dwExStyle(void)
{
	return dwExStyle;
} 


//-------------------------------------------------------------------------------
LPCTSTR GenWnd::Get_lpClassName(void)
{
	return lpClassName;
}


//-------------------------------------------------------------------------------
LPCTSTR GenWnd::Get_lpWindowName(void)
{
	return lpWindowName;
}


//-------------------------------------------------------------------------------
DWORD GenWnd::Get_dwStyle(void)
{
	return dwStyle;
}


//-------------------------------------------------------------------------------
int GenWnd::Get_x(void)
{
	return x;
}


//-------------------------------------------------------------------------------
int GenWnd::Get_y(void)
{
	return y:
}


//-------------------------------------------------------------------------------
int GenWnd::Get_nWidth(void)
{
	return nWidth;
}


//-------------------------------------------------------------------------------
int GenWnd::Get_nHeight(void)
{
	return nHeight
}


//-------------------------------------------------------------------------------
HWND GenWnd::Get_hWndParent(void)
{
	return hWndParent;
}


//-------------------------------------------------------------------------------
HMENU GenWnd::Get_hMenu(void)
{
	return hMenu;
}


//-------------------------------------------------------------------------------
LPVOID GenWnd::Get_lpParam(void)
{
	return lpParam;
}
