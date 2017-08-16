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
//  Data: 10:33 02/08/2017
//

#ifndef _GENWND_H_
#define _GENWND_H_	

//-------------------------------------------------------------------------------
// Aquivos para inclusão.
#include "../CWin32.h"


//-------------------------------------------------------------------------------
// Classe GenWnd.
//
class GenWnd
{
    private:

    //---------------------------------------------------------------------------
    // Declarações referentes à um controle.
    WNDCLASSEX  wnd;
    HWND        hWnd;

    BOOL        Registered;    // Para Verificar se a WNDCLASSEX foi registrada.
    BOOL        Created;       // Para verificar se foi criado a janela.


    // Variáveis para a riação de janela com CreateWindowEx().
    DWORD       dwExStyle;
    LPCTSTR     lpClassName;
    LPCTSTR     lpWindowName;
    DWORD       dwStyle;
    int         x;
    int         y;
    int         nWidth;
    int         nHeight;
    HWND        hWndParent;
    HMENU       hMenu;
    HINSTANCE   hInstance;
    LPVOID      lpParam;


    public:

    //---------------------------------------------------------------------------
    // Contrutor e destrutor.
    GenWnd();
    ~GenWnd();



    //---------------------------------------------------------------------------
    // Demais funções.
    //
    // Alguns métodos serão chamados pelos próprios construtores da classe, pois,
    // as função são as melhores formas de economisar espaço em memória, já que
    // estas poderão atuar sobre as estruturas, sem afetar a usabilidade da clas-
    // se.
    //
    
    // Função para iniciar a estrutura da janela (WNDCLASSEX).
    // Não recebe argumentos, pois esta poderá ser sobrecarregada posteriormente
    // para a criação de estilos específicos de botôes, ou labels, por exemplo.
    int Init_Struct(void);

    // Função para registrar a classe da janela.
    int _RegisterClassEx(void);


    // Função para criar a janela / controle.
    int Create(void);



    //---------------------------------------------------------------------------
    // -SETTERS
    // Encerrada a sessão de iniciação, vamos à sessão de modificação, como os í-
    // cones, cor, tamanhos, posições etc.

    // Função para alterar o estilo da janela.
    int Set_style(UINT s);


    // Função para alternar o n° de bytes que a Janela ocupa.
    int Set_cbSize(UINT c);


    // Função para alterar o n° de bytes extras que a Classe ocupará.
    int Set_cbClsExtra(int c);


    // Função para alterar o n° de bytes extras que a Janela ocupará.
    int Set_cbWndExtra(int c);


    // Função para definir a fução de processamento de mensagens da janela.
    int Set_lpfnWndProc(WNDPROC f);


    // Função para alterar o nome do menu da janela.
    // NOTA: Lembrar de utilizar algo como strcpy, para evitar alocar memó-
    //       dinâmicamente. Se não existir tal função, crie uma você memso.
    int Set_lpszMenuName(LPCTSTR s);


    // Função para alterar o nome da classe da janela.
    int Set_lpszClassName(LPCTSTR s);


    // Função para mudar a hisntância da janela.
    int Set_hInstance(HINSTANCE h);


    // Função para alterar o ícone da janela.
    int Set_hIcon(HICON h);


    // Função para alterar o ícone secundário (hIconSm) da janela.
    int Set_hIconSm(HICON h);


    // Função para alterar o cursos da classe da janela.
    int Set_hCursor(HCURSOR h);


    // Função para alterar a cor da janela.
    int Set_hbrBackground(HBRUSH h);




    /* Alteração referente à CreateWindowEx(). */

    // Funão para alternar o estilo extra padrão da janela.
    int Set_dwExStyle(DWORD s);


    // Função para alterar o nome da classe da janela.
    int Set_lpClassName(LPCTSTR s);


    // Função para alterar o nome da janela.
    int Set_lpWindowName(LPCTSTR s);


    // Função para alterar o estilo da janela.
    int Set_dwStyle(DWORD s);


    // Função para alterar a posição horizontal (inicial) da janela.
    int Set_x(int _x);


    // Função para alterar a posição vertical (inicial) da janela.
    int Set_y(int _y);


    // Função para alterar a largura (inicial) da janela.
    int Set_nWidth(int w);


    // Função para alterar a altura (inicial) da janela.
    int Set_nHeight(int h);


    // Função para adicionar uma janela pai à janela.
    int Set_hWndParent(HWND h);


    // Função para adicionar um menu (ou id para WM_COMAND) à janela.
    int Set_hMenu(HMENU h);


    // Função para alteram o prarâmetro lp.
    int Set_lpParam(LPVOID l);



    //---------------------------------------------------------------------------
    // -GETTERS
    // Estes retornam todos os valores solicitados.
	HWND hWnd(void);


    // Retorna o estilo da janela
    UINT Get_style(void);


    // Retorna o tamanho da janela.
    UINT Get_cbSize(void);


    // Retorna os Bytes extras da classe.
    int Get_cbClsExtra(void);


    // retorna os Bytex extras da janela.
    int Get_cbWndExtra(void);


    // Retorna o valor do mponteiro da função de processamento de mensagens.
    WNDPROC Get_lpfnWndProc(void);


    // Escreve o nome do menu na variável entrada.
    LPCTSTR Get_lpszMenuName(void);


    // Escreve o nome da classe na variável entrada.
    LPCTSTR Get_lpszClassName(void);


    // Retorna a instância da janela.
    HINSTANCE Get_hInstance(void);


    // Retorna o Ícone da dajanela.
    HICON Get_hIcon(void);


    // Retorna o Ícone Sm da janela.
    HICON Get_hIconSm(void);


    // Retorna o cursor da janela.
    HCURSOR Get_hCursor(void);


    // Retorna a cor da janela.
    HBRUSH Get_hbrBackground(void);




    /* Retornos referentes à CreateWindowEx(). */

    // Retorna o estilo Ex da janela.
    DWORD Get_dwExStyle(void);


    // Escreve o nome da classe da janela na variável entrada.
    LPCTSTR Get_lpClassName(void);


    // Escreve o nome da janela na variável entrada.
    LPCTSTR Get_lpWindowName(void);


    // Retorna o Estilo da janela.
    DWORD Get_dwStyle(void);


    // Retorna a posição horizontal (inicial).
    int Get_x(void);


    // Retorna a posição vertical (inicial).
    int Get_y(void);


    // Retorna a largura (inical) da janela.
    int Get_nWidth(void);


    // Retorna a altura (inical) da janela.
    int Get_nHeight(void);


    // Retorna a janela pai.
    HWND Get_hWndParent(void);


    // Retorna o menu ou o Id da janela.
    HMENU Get_hMenu(void);


    // Retorna o prâmeto lp. lpParam.
    LPVOID Get_lpParam(void);
	
	
	
	//---------------------------------------------------------------------------
	// Funções para manipulação dos estado da jaela enquanto esta está sendo exe-
	// cutada, como grayed, unactive, destroy, GetWndText etc...
	
	/*TODO */
};


#endif  // _GENWND_H_
