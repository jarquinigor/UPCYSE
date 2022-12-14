#pragma once
#ifndef _ARRBETA_H_
#define _ARRBETA_H_
#include"CBeta.h"

class CArrBeta {
private:
	vector<CBeta*>arregloBetas;
public:
	CArrBeta() {
		arregloBetas = vector<CBeta*>();
	}
	vector<CBeta*>getVecBeta() {
		return arregloBetas;
	}
	void setVector(vector<CBeta*>arregloBetas) {
		this->arregloBetas = arregloBetas;
	}
	int getT() {
		return arregloBetas.size();
	}
	void Agregar(int nivel) {
		arregloBetas.push_back(new CBeta(nivel));
	}
	void dibujar(Graphics^g, Bitmap^img) {
		for (int i = 0; i < arregloBetas.size(); i++)
		{
			arregloBetas.at(i)->Dibujar(g, img);
		}
	}
	void eliminarEnPos(int indice) {
		arregloBetas.erase(arregloBetas.begin() + indice);
	}
	void mover(Graphics^g, int nivel, int dificultad, Bitmap^imgBala) {
		for (int i = 0; i < arregloBetas.size(); i++)
		{
			arregloBetas.at(i)->Mover(g, nivel, dificultad, imgBala);
		}
	}
	void crearBalas() {
		for (int i = 0; i < arregloBetas.size(); i++)
		{
			arregloBetas.at(i)->crearBalas();
		}
	}

};

#endif // !_ARRBETA_H_

