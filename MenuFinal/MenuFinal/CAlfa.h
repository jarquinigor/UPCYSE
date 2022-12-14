#pragma once
#ifndef _ALFA_H_
#define _ALFA_H_

#include"CUnidad.h"
#include"CArrBala.h"

using namespace System;
using namespace System::Drawing;

class CAlfa :public CUnidad {
private:
	Direccion direccion;
	CArrBala*vecBala;
public:
	CAlfa(int nivel) {
		Random r;
		switch (nivel)
		{
		case 1:
			this->x = r.Next(800, 1150);
			System::Threading::Thread::Sleep(10);
			this->y = r.Next(320, 650);
			System::Threading::Thread::Sleep(10);
			break;
		case 2:
			this->x = r.Next(800, 1150);
			System::Threading::Thread::Sleep(10);
			this->y = r.Next(550, 650);
			System::Threading::Thread::Sleep(10);
			break;
		case 3:
			this->x = r.Next(800, 1150);
			System::Threading::Thread::Sleep(10);
			this->y = r.Next(550, 650);
			System::Threading::Thread::Sleep(10);
			break;
		default:
			break;
		}
		
		this->dx = 12;
		this->dy = 0;
		indiceX = 0;
		indiceY = 0;
		vecBala = new CArrBala();
	}

	Rectangle getRectangulo() {
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
			break;
		case 2:
			if (x + dx<70 || x + dx + W * 2>g->VisibleClipBounds.Width - 70)dx = dx*-1;

			break;
		default:
			break;
		}
	}
	void Mover(Graphics^g, int nivel, int dificultad, Bitmap^img) {

		if (dificultad == 2) // DIFICULTAD AVANZADO
		{
			/*crearBalas();*/
			moverBalas(g);
			dibujarBalas(g, img);
		}

		switch (direccion)
		{
		case Izquierda:
			indiceY = 1;
			dx = -12, dy = 0;
			if (indiceX >= 0 && indiceX < 2)indiceX++;
			else indiceX = 0;
			break;
		case Derecha:
			indiceY = 2;
			dx = 12, dy = 0;
			if (indiceX >= 0 && indiceX < 2)indiceX++;
			else indiceX = 0;
			break;
		default:
			break;
		}

		//EVITA QUE CHOQUE CON LOS BORDES DEL FORMULARIO
		if (x + dx<0 || x + dx + (W * 2)> g->VisibleClipBounds.Width)dx = dx*-1;
		ControlarBordes(g, nivel);

		if (dx < 0)setDireccion(Izquierda);
		else if (dx > 0)setDireccion(Derecha);

		x += dx;
	}

	//PARA MANEJAR LAS BALAS
	void crearBalas() {   ///IRA EN UN TIMER
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
	int getTBalas() {
		return vecBala->getT();
	}
	vector<CBala*>getVecBalas() {
		return vecBala->getVecBala();
	}

};

#endif // !_ALFA_H_
