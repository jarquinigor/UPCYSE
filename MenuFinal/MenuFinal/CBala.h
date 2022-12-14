#pragma once
#ifndef _BALA_H_
#define _BALA_H_
#include"CUnidad.h"

using namespace System::Drawing;

class CBala :public CUnidad
{
private:

public:
	CBala() {
		x = 0;
		y = 0;
		dx = 0;
		dy = 0;
		W = 0;
		H = 0;
	}
	CBala(int x, int y, int indiceY, int W, int H) {
		this->x = x;
		this->y = y;
		this->indiceY = indiceY;
		this->W = W;
		this->H = H;
	}
	void Dibujar(Graphics^g, Bitmap^img) {
		Rectangle canvas = Rectangle(x, y, W, H);
		g->DrawImage(img, canvas);
	}

	void Mover(Graphics^g) {
		if (indiceY == 3) //ARRIBA
		{
			dx = 0, dy = -30;
		}
		if (indiceY == 0) //ABAJO
		{
			dx = 0, dy = 30;
		}
		if (indiceY == 2) //DERECHA
		{
			dx = 30, dy = 0;
		}
		if (indiceY == 1) //IZQUIERDA
		{
			dx = -30, dy = 0;
		}

		x += dx;
		y += dy;
	}

	Rectangle getRectangulo() {
		return Rectangle(x, y, W, H);
	}
};

#endif // !_BALA_H_
