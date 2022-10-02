/*****************************************************
******************************************************
******************************************************
** File: d3dUltility.h                              **
** Authors: André Guilherme and Frank De Luma       **
** License: None                                    **
** Place: Rio de Janeiro, Brazil                    **
** Description:                                     ** 
** header for the namespaces and classes to         **
** store d3d ultilities.                            **
** Note:                                            **
** based on the Book Called:                        **
** Introduction to 3D GAME Programming with Directx **
** 9.0 by Frank De Luma                             **
******************************************************
******************************************************/

//Inclusion of the DirectD3D9 and XTL header files.
/***********************************************
************************************************
** Warning:                                   **
** These headers cannot be inverted like this **
** #include <d3d9.h>                          **
** #include <xtl.h>                           **
** It will be get a compilation error.        **
************************************************
************************************************/
#include <xtl.h> //First.
#include <d3d9.h> //Second.


/************************************
*************************************
** NOTE:                           **
** Namespace in d3d is equal to N  **
** Class in d3d is equal to C      **
**                                 **
** EXAMPLE:                        **
** namespace NWhat                 **
** {                               **
**    class CClass                 **
**	  {                            **
**       CClass();                 **
**	    ~CClass();                 **
**	  };                           **
** }                               **
*************************************
**************************************/
namespace ND3D
{
	class CD3DUtil
	{
	public:
	//Constructors and Destructors
	    CD3DUtil();
		~CD3DUtil();		
		bool InitD3D(HINSTANCE hInstance, int iwidth, int iheight, D3DDEVTYPE deviceType, IDirect3DDevice9** d3ddevice);
	/**********************************************************************************
	***********************************************************************************	
	**  NOTE: These files are unused because on                                      **        
	**  the book Frank was working with Window stuff on Windows xp,                  ** 	
	**  XBOX 360 Doesn´t support window parameters.                                  **
	**	int EnterMSGLoop(bool (*ptr_display) (float timeDelta));                     **
	**	LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam); **
	**	template<class T>                                                            **
	**	void Release(T t);                                                           **
	**	template<class T>                                                            **
	**	void Delete(T t);                                                            **
	***********************************************************************************
	************************************************************************************/	
		void Clear();
		bool Display();
	private:
		IDirect3D9* p_d3d9; //Directx9
		D3DCAPS9 d3d9caps; //Directx9 CAPS
		D3DPRESENT_PARAMETERS d3d9param; //Parameters
		IDirect3DDevice9* p_D3DDevice9; //Directx9 Device...
	};
	extern CD3DUtil d3dutil; //Util
} //namespace //ND3DUtil

