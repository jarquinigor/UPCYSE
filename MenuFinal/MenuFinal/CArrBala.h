#pragma once
#ifndef _ARRBALA_H_
#define _ARRBALA_H_

#include"CBala.h"
#include<vector>
using namespace std;

class CArrBala {
private:
	vector<CBala*>arregloBalas;
public:
	CArrBala() {
		arregloBalas = vector<CBala*>();
	}
	vector<CBala*>getVecBala() {
		return arregloBalas;
	}
	void setVecBala(vector<CBala*>arregloBalas) {
		this->arregloBalas = arregloBalas;
	}
	int getT() {
		return arregloBalas.size();
	}
	void crearBala(int x, int y, int indiceY, int W, int H) {
		arregloBalas.push_back(new CBala(x + 25, y + 30, indiceY, W, H));
	}
	void eliminarBala(int indice) {
		arregloBalas.erase(arregloBalas.begin() + indice);
	}
	void dibujar(Graphics^g, Bitmap^img) {
		for (int i = 0; i < arregloBalas.size(); i++)
		{
			arregloBalas.at(i)->Dibujar(g, img);
		}
	}
	void mover(Graphics^g) {
		for (int i = 0; i < arregloBalas.size(); i++)
		{
			arregloBalas.at(i)->Mover(g);
		}
		//PARA ELIMINAR SI SE SALE DE LOS LIMITES
		for (int i = 0; i < arregloBalas.size(); i++)
		{
			if (arregloBalas.at(i)->getX() + arregloBalas.at(i)->getDX() < 0 || arregloBalas.at(i)->getX() + arregloBalas.at(i)->getDX() + arregloBalas.at(i)->getW() > g->VisibleClipBounds.Width)
				eliminarBala(i);
			else if (arregloBalas.at(i)->getY() + arregloBalas.at(i)->getDY() < 0 || arregloBalas.at(i)->getY() + arregloBalas.at(i)->getDY() + arregloBalas.at(i)->getW() > g->VisibleClipBounds.Height)
				eliminarBala(i);
		}
	}

};
#endif // !_ARRBALA_H_
