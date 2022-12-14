#pragma once
#ifndef _UNIDAD_H_
#define _UNIDAD_H_

enum Direccion { Arriba, Abajo, Izquierda, Derecha, Ninguna };

class CUnidad {
protected:
	int x, y;
	int dx, dy;
	int indiceX, indiceY;
	int W, H;
public:
	void setX(int x) {
		this->x = x;
	}
	void setY(int y) {
		this->y = y;
	}
	void setDX(int dx) {
		this->dx = dx;
	}
	void setDY(int dy) {
		this->dy = dy;
	}
	void setIndiceX(int indiceX) {
		this->indiceX = indiceX;
	}
	void setIndiceY(int indiceY) {
		this->indiceY = indiceY;
	}
	void setW(int W) {
		this->W = W;
	}
	void setH(int H) {
		this->H = H;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	int getDX() {
		return dx;
	}
	int getDY() {
		return dy;
	}
	int getIX() {
		return indiceX;
	}
	int getIY() {
		return indiceY;
	}
	int getW() {
		return W;
	}
	int getH() {
		return H;
	}
};

#endif // !_UNIDAD_H_
