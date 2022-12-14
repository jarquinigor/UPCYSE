#pragma once
#ifndef _GAMMA_H_
#define _GAMMA_H_

#include"CUnidad.h"
#include"CArrBala.h"

using namespace System;

class CGamma :public CUnidad {
private:
	Direccion direccion;
	CArrBala*Balas;
public:
	CGamma(int nivel) {
		Random r;
		switch (nivel)
		{
		case 1:
			this->x = r.Next(472, 1150);
			System::Threading::Thread::Sleep(10);
			this->y = r.Next(50, 300);
			System::Threading::Thread::Sleep(10);
			break;
		case 2:
			this->x = r.Next(830, 1050);
			System::Threading::Thread::Sleep(10);
			this->y = r.Next(100, 600);
			System::Threading::Thread::Sleep(10);
			break;
		case 3:
			this->x = r.Next(500, 1150);
			System::Threading::Thread::Sleep(10);
			this->y = r.Next(10, 180);
			System::Threading::Thread::Sleep(10);
			break;
		default:
			break;
		}
		Balas = new CArrBala();
		dx = 12;
		dy = 0;
		indiceX = 0;
		indiceY = 0;
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
	//PARA MANEJAR LAS BALAS
	void crearBalas() { /// EN UN TIMER
		Balas->crearBala(x, y, indiceY, 40, 35);
	}
	void moverBalas(Graphics^g) {
		Balas->mover(g);
	}
	void dibujarBalas(Graphics^g, Bitmap^img) {
		Balas->dibujar(g, img);
	}
	void eliminarBalasEnPos(int indice) {
		Balas->eliminarBala(indice);
	}
	int getTBalas() {
		return Balas->getT();
	}
	vector<CBala*>getVecBalas() {
		return Balas->getVecBala();
	}
	//
	void cambiarDireccion() {
		int auxCambio;
		Random r;
		auxCambio = r.Next(1, 5);
		System::Threading::Thread::Sleep(10);
		switch (auxCambio)
		{
		case 1:
			setDireccion(Arriba);
			break;
		case 2:
			setDireccion(Abajo);
			break;
		case 3:
			setDireccion(Derecha);
			break;
		case 4:
			setDireccion(Izquierda);
			break;
		default:
			break;
		}
	}

	void ControlarBordes(Graphics^g, int nivel) {
		switch (nivel)
		{
		case 1: //MUNDO DELINCUENCIA
			///EVITA QUE CHOQUE CON EL EDIFICIO EN EL MUNDO DELINCUENCIA
			if (x + dx <= 470 && y + dy <= 290 && direccion == Arriba)dy = dy*-1;
			if (x + dx <= 470 && y + dy <= 290 && direccion == Izquierda)dx = dx*-1;
			break;
		case 2:
			//PARA EL RIO DEL MAPA
			if (x + dx > 400 && x<800 && y >205 && y< 540 && direccion == Derecha)dx = dx*-1;
			if ((x > 400 && x<800) && y + dy<540 && y>205 && direccion == Arriba)dy = dy*-1;
			if (x + dx < 800 && x>400 && y >205 && y< 540 && direccion == Izquierda)dx = dx*-1;
			if ((x > 400 && x<800) && y<540 && y + dy>205 && direccion == Abajo)dy = dy*-1;
			//PARA LOS BORDES
			if (x + dx<25 || x + dx + (W * 2) > g->VisibleClipBounds.Width - 25) dx = dx*-1;
			else if (y + dy<125 || y + dy + (H * 2) > g->VisibleClipBounds.Height - 25) dy = dy*-1;
			break;
		case 3:
			//PARA LA CASA 1
			if (x + dx > 470 && x<770 && y >180 && y< 420 && direccion == Derecha)dx = dx*-1;
			if ((x > 470 && x<770) && y + dy<420 && y>205 && direccion == Arriba)dy = dy*-1;
			if (x + dx < 770 && x>460 && y >180 && y< 420 && direccion == Izquierda)dx = dx*-1;
			if ((x > 470 && x<770) && y<420 && y + dy>180 && direccion == Abajo)dy = dy*-1;
			//PARA LA CASA 2
			if (x + dx > 920 && x<1220 && y >190 && y< 430 && direccion == Derecha)dx = dx*-1;
			if ((x > 920 && x<1220) && y + dy<430 && y>190 && direccion == Arriba)dy = dy*-1;
			if (x + dx < 1220 && x>920 && y >190 && y< 430 && direccion == Izquierda)dx = dx*-1;
			if ((x > 920 && x<1220) && y<430 && y + dy>190 && direccion == Abajo)dy = dy*-1;
			break;
		default:
			break;
		}
	}

	void Mover(Graphics^g, int nivel, int dificultad, Bitmap^img) {
		if (dificultad == 2) //PARA AVANZADO
		{
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

		if (x + dx<0 || x + dx + W * 2>g->VisibleClipBounds.Width)dx = dx*-1;
		else if (y + dy<0 || y + dy + H * 2>g->VisibleClipBounds.Height)dy = dy*-1;

		ControlarBordes(g, nivel);
		if (dx < 0)
			setDireccion(Izquierda);
		else if (dx > 0)
			setDireccion(Derecha);
		else if (dy > 0)
			setDireccion(Abajo);
		else if (dy < 0)
			setDireccion(Arriba);

		x += dx;
		y += dy;
	}

};

#endif // !_GAMMA_H_
