/*****************************************************
******************************************************
******************************************************
** File: d3dUltility.cpp                            **
** Authors: André Guilherme and Frank De Luma       **
** License: None                                    **
** Place: Rio de Janeiro, Brazil                    **
** Description:                                     ** 
**   Place to store some Directx9 utils             **
** Note:                                            **
** based on the Book Called:                        **
** Introduction to 3D GAME Programming with Directx **
** 9.0 by Frank De Luma                             **
******************************************************
******************************************************/

#include "d3dUltility.h" //Header File
#include <iostream>

namespace ND3D 
{
    IDirect3D9* p_d3d9;
	D3DCAPS9 d3d9caps;
	D3DPRESENT_PARAMETERS d3d9param;
	IDirect3DDevice9* p_D3DDevice9;
   
	/*****************************
	******************************
	** ND3D::CD3DUtil::CD3DUtil **
	** Description:             **
	** Store only the d3d vars. **
	******************************
	******************************/
	CD3DUtil::CD3DUtil()
	{
	  p_d3d9 = nullptr;
	  p_D3DDevice9 = nullptr;
	}
	
	/******************************
	*******************************
	** ND3D::CD3DUtil::~CD3DUtil **
	** Description:              **
	** None.                     **
	*******************************
	*******************************/
	CD3DUtil::~CD3DUtil()
	{
	
	}

	/***********************************
	************************************
	** bool ND3D::CD3DUtil::InitD3D() **
	** Description:                   **
	** Load the whole D3D Interface.  **
	************************************
	************************************/
	bool CD3DUtil::InitD3D(HINSTANCE hInstance, int iwidth, int iheight, D3DDEVTYPE deviceType, IDirect3DDevice9** d3ddevice)
	{
	   p_d3d9 = Direct3DCreate9(D3D_SDK_VERSION); //Create The DIRECTX9
	   p_d3d9->GetDeviceCaps(D3DADAPTER_DEFAULT, deviceType, &d3d9caps); //Get The caps
	   int vp = 0;
	   if(d3d9caps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT) 
	   {
	      vp = D3DCREATE_HARDWARE_VERTEXPROCESSING; //Ignored on xbox 360?
	   }
	   HWND hwnd; //TODO?
	   //Parameters initialization.
	   d3d9param.BackBufferWidth = iwidth; //WIDTH Screen
	   d3d9param.BackBufferHeight = iheight; //Height
	   d3d9param.BackBufferFormat = D3DFMT_A8R8G8B8; //Format
	   d3d9param.EnableAutoDepthStencil = true; //Is Windowed
	   d3d9param.Flags = 0;
	   //Creation of the device.
	   HRESULT hr = p_d3d9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3d9param, &p_D3DDevice9);  
	   if( FAILED(hr) )
	   {
		std::cout << "Failed to load the device";
		return 0;
	   }
	}

/****************************
*****************************
**	template<class T>      **
**	CD3DUtil::Release(T t) **
**	{                      **
**		if(t)              **
**		{                  **
**			t->Release(t); **
**			t = 0;         **
**		}                  **
**	}                      **
**                         **
**	template<class T>      **
**	CD3DUtil::Delete(T t)  **
**	{                      **
**		if(t)              **
**		{                  **
**		   delete t;       **
**		   t = 0;          **             
**		}                  **           
**	}                      **
*****************************	
*****************************/   
 
	/***********************************
	************************************
	** void ND3D::CD3DUtil::Clear()   **
	** Description:                   **
	** Frees the D3D9 Interface       **
	************************************
	************************************/
	void CD3DUtil::Clear()
	{
		if(p_d3d9)
			p_d3d9->Release();
	}

	/***********************************
	************************************
	** void ND3D::CD3DUtil::Display() **
	** Description:                   **
	** Display The Screen?            **
	************************************
	************************************/
	bool CD3DUtil::Display()
	{
		if( p_D3DDevice9 )
		{
			p_D3DDevice9->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0x000000000, 1.0f, 0); //CLEAR BUFFER
			p_D3DDevice9->Present(0, 0, 0, 0); //Make D3D Present
		}
		return true;
	}
}