#pragma once
#ifndef _BETA_H_
#define _BETA_H_

#include"CUnidad.h"
#include"CArrBala.h"

using namespace System;

class CBeta :public CUnidad {
private:
	Direccion direccion;
	CArrBala*vecBala;
public:
	CBeta(int nivel) {
		Random r;
		switch (nivel)
		{
		case 1:
			this->x = r.Next(472, 1200);
			System::Threading::Thread::Sleep(10);
			this->y = r.Next(50, 300);
			System::Threading::Thread::Sleep(10);
			break;
		case 2:
			this->x = r.Next(800, 1200);
			System::Threading::Thread::Sleep(10);
			this->y = r.Next(180, 500);
			System::Threading::Thread::Sleep(10);
			break;
		case 3:
			this->x = r.Next(20, 450);
			System::Threading::Thread::Sleep(10);
			this->y = r.Next(360, 700);
			System::Threading::Thread::Sleep(10);
			break;
		default:
			break;
		}
		this->dy = 12;
		this->dx = 0;
		indiceX = 0;
		indiceY = 0;
		vecBala = new CArrBala(); //Inicializamos el arreglo de balas
	}
	Rectangle getRectangulo() // Rectangulos que usaremos en el intersectWith para las colisiones 
	{
		return Rectangle(x, y, W * 2, H * 2);
	}
	Direccion getDireccion() {
		return direccion;
	}
	void setDireccion(Direccion direccion) {
		this->direccion = direccion;
	}

	void Dibujar(Graphics^g, Bitmap^img) {
		H = img->Height / 4;
		W = img->Width / 3;

		Rectangle seccion = Rectangle(indiceX*W, indiceY*H, W, H);
		Rectangle canvas = Rectangle(x, y, W * 2, H * 2);

		g->DrawImage(img, canvas, seccion, GraphicsUnit::Pixel);
	}
	void ControlarBordes(Graphics^g, int nivel) {
		switch (nivel)
		{
		case 1: //MUNDO DELINCUENCIA
				///EVITA QUE CHOQUE CON EL EDIFICIO EN EL MUNDO DELINCUENCIA
			break;
		case 2:
			//PARA LOS BORDES
			if (y + dy<125 || y + dy + (H * 2) > g->VisibleClipBounds.Height - 25) dy = dy*-1;
			break;
		case 3:
			if (y + dy<320 || y + dy + (H * 2) > g->VisibleClipBounds.Height ) dy = dy*-1;
			break;
		default:
			break;
		}
	}


	void Mover(Graphics^g, int nivel, int dificultad, Bitmap^img) {
		if (dificultad == 2)//DIFICULTAD AVANZADO
		{
			///SOLO SE MUEVEN Y DIBUJAN LAS BALAS SI LA DIFICULTAD ES 2 (AVANZADO)
			moverBalas(g);
			dibujarBalas(g, img);
		}

		switch (direccion)
		{
		case Arriba:
			indiceY = 3;
			dx = 0, dy = -12;
			if (indiceX >= 0 && indiceX < 2)indiceX++;
			else indiceX = 0;
			break;
		case Abajo:
			indiceY = 0;
			dx = 0, dy = 12;
			if (indiceX >= 0 && indiceX < 2)indiceX++;
			else indiceX = 0;
			break;
		default:
			break;
		}

		//EVITA QUE CHOQUE CON LOS BORDES
		if (y + dy<0 || y + dy + (H * 2) > g->VisibleClipBounds.Height) dy = dy*-1;

		ControlarBordes(g,nivel);

		if (dy < 0)setDireccion(Arriba);
		else if (dy > 0)setDireccion(Abajo);

		y += dy;
	}

	//PARA MANEJAR LAS BALAS
	void crearBalas() {
		vecBala->crearBala(x, y, indiceY, 40, 35);
	}
	void moverBalas(Graphics^g) {
		vecBala->mover(g);
	}
	void dibujarBalas(Graphics^g, Bitmap^img) {
		vecBala->dibujar(g, img);
	}
	void eliminarBalasEnPos(int indice) {
		vecBala->eliminarBala(indice);
	}
	int getTBalasB() {
		return vecBala->getT();
	}
	vector<CBala*>getVecBalas() {
		return vecBala->getVecBala();
	}
};

#endif // !_BETA_H_
