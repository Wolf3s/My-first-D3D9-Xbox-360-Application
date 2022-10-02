/*****************************************************
******************************************************
******************************************************
** File: main.cpp                                   **
** Authors: André Guilherme and Frank De Luma       **
** License: None                                    **
** Place: Rio de Janeiro, Brazil                    **
** Description:                                     ** 
**   Main file to initialize the application.        **
** Note:                                            **
** based on the Book Called:                        **
** Introduction to 3D GAME Programming with Directx **
** 9.0 by Frank De Luma                             **
******************************************************
******************************************************/

#include "d3dUltility.h"
#include <iostream>

ND3D::CD3DUtil d3dutil;

HINSTANCE instance;
IDirect3DDevice9 *device;

void __cdecl main()
{
	if(!d3dutil.InitD3D(instance, 1280, 720, D3DDEVTYPE_HAL, &device))
	{
		std::cerr << "CD3DUtil::InitD3D FAILED";
	}
	d3dutil.Clear();
}

