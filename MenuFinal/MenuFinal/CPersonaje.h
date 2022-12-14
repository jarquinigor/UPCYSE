#pragma once
#ifndef _PERSONAJE_H_
#define _PERSONAJE_H_
#include"CUnidad.h"
#include"CArrBala.h"

using namespace System::Drawing;

class CPersonaje :public CUnidad
{
private:
	Direccion ultimaTecla;
	Direccion direccion;
	CArrBala*BalasPJ;
public:
	CPersonaje() {
		BalasPJ = new CArrBala();
		x = 300;
		y = 500;
		dx = dy = 0;
		ultimaTecla = Direccion::Abajo;
		direccion = Direccion::Ninguna;
	}
	~CPersonaje() {}
	void Dibujar(Graphics^g, Bitmap^img) {
		H = img->Height / 4;
		W = img->Width / 3;

		Rectangle seccion = Rectangle(indiceX*W, indiceY*H, W, H);
		Rectangle canvas = Rectangle(x, y, W * 2, H * 2);

		g->DrawImage(img, canvas, seccion, GraphicsUnit::Pixel);
	}
	//RECTANGULO PARA LAS BALAS
	Rectangle getRectangulo() {
		return Rectangle(x, y, 2 * W, 2 * H);
	}
	Direccion getDireccion() {
		return direccion;
	}
	void setDireccion(Direccion direccion) {
		this->direccion = direccion;
	}
	void ControlarBordes(Graphics^g, int nivel) {
		switch (nivel)
		{
		case 1: //MUNDO DELINCUENCIA
			if (x + dx <= 470 && y + dy <= 290 && direccion == Arriba)dy = dy*-1;
			if (x + dx <= 470 && y + dy <= 290 && direccion == Izquierda)dx = dx*-1;
			break;
		case 2:
			//PARA EL RIO DEL MAPA
			if (x + dx > 400 && x<800 && y >205 && y< 540 && direccion == Derecha)dx = dx*-1;
			if ((x > 400 && x<800) && y+dy<540 && y>205 && direccion == Arriba)dy = dy*-1;
			if (x + dx < 800 && x>400 && y >205 && y< 540 && direccion == Izquierda)dx = dx*-1;
			if ((x > 400 && x<800) && y<540 && y+dy>205 && direccion == Abajo)dy = dy*-1;
			//LIMITES
			if (x + dx<25 || x + dx + (W * 2) > g->VisibleClipBounds.Width - 25) dx = dx*-1;
			else if (y + dy<125 || y + dy + (H * 2) > g->VisibleClipBounds.Height - 25) dy = dy*-1;
			break;
		case 3:
			//PARA LA CASA 1
			if (x + dx > 470 && x<770 && y >180 && y< 420 && direccion == Derecha)dx = dx*-1;
			if ((x > 470 && x<770) && y + dy<420 && y>180 && direccion == Arriba)dy = dy*-1;
			if (x + dx < 770 && x>470 && y >180 && y< 420 && direccion == Izquierda)dx = dx*-1;
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
	void Mover(Graphics^g, int nivel/*, int boss, bool bossB*/) {
		switch (direccion)
		{
		case Arriba:
			indiceY = 3;
			dx = 0, dy = -18;
			if (indiceX >= 0 && indiceX < 2) indiceX++;
			else indiceX = 0;
			ultimaTecla = Arriba;
			break;
		case Abajo:
			indiceY = 0;
			dx = 0, dy = 18;
			if (indiceX >= 0 && indiceX < 2)indiceX++;
			else indiceX = 0;
			ultimaTecla = Abajo;
			break;
		case Izquierda:
			indiceY = 1;
			dx = -18, dy = 0;
			if (indiceX >= 0 && indiceX < 2)indiceX++;
			else indiceX = 0;
			ultimaTecla = Izquierda;
			break;
		case Derecha:
			indiceY = 2;
			dx = 18, dy = 0;
			if (indiceX >= 0 && indiceX < 2)indiceX++;
			else indiceX = 0;
			ultimaTecla = Derecha;
			break;
		case Ninguna:
			dx = 0, dy = 0;
			switch (ultimaTecla)
			{
			case Arriba:
				indiceX = 0, indiceY = 3;
				break;
			case Abajo:
				indiceX = 0, indiceY = 0;
				break;
			case Izquierda:
				indiceX = 0, indiceY = 1;
				break;
			case Derecha:
				indiceX = 0, indiceY = 2;
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
		if (x + dx<0 || x + dx + (W * 2) > g->VisibleClipBounds.Width) dx = dx*-1;
		else if (y + dy<0 || y + dy + (H * 2) > g->VisibleClipBounds.Height) dy = dy*-1;

		ControlarBordes(g, nivel/*, boss, bossB*/);

		y += dy;
		x += dx;
	}
	//BALAS
	void crearBalas() {
		BalasPJ->crearBala(x, y, indiceY, 40, 35);
	}
	void moverBalas(Graphics^g) {
		BalasPJ->mover(g);
	}
	void dibujarBalas(Graphics^g, Bitmap^img) {
		BalasPJ->dibujar(g, img);
	}
	void eliminarBalaEnPos(int indice) {
		BalasPJ->eliminarBala(indice);
	}
	int getTBalas() {
		return BalasPJ->getT();
	}
	vector<CBala*>getVecBala() {
		return BalasPJ->getVecBala();
	}

};


#endif // !_PERSONAJE_H_
