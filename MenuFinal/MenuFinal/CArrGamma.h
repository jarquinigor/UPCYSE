#pragma once
#ifndef _ARRGAMMA_H_
#define _ARRGAMMA_H_
#include"CGamma.h"

class CArrGamma {
private:
	vector<CGamma*>arregloGammas;
public:
	CArrGamma() {
		arregloGammas = vector<CGamma*>();
	}
	vector<CGamma*>getVecGamma() {
		return arregloGammas;
	}
	void setVector(vector<CGamma*>arregloGammas) {
		this->arregloGammas = arregloGammas;
	}
	int getT() {
		return arregloGammas.size();
	}
	void Agregar(int nivel) {
		arregloGammas.push_back(new CGamma(nivel));
	}
	void dibujar(Graphics^g, Bitmap^bmpEnemigo) {
		for (int i = 0; i < arregloGammas.size(); i++)
		{
			arregloGammas.at(i)->Dibujar(g, bmpEnemigo);
		}
	}
	void eliminarEnPos(int indice) {
		arregloGammas.erase(arregloGammas.begin() + indice);
	}
	void mover(Graphics^g, int nivel, int dificultad, Bitmap^imgBala) {
		for (int i = 0; i < arregloGammas.size(); i++)
		{
			arregloGammas.at(i)->Mover(g, nivel, dificultad, imgBala);
		}
	}
	void crearBalas() {
		for (int i = 0; i < arregloGammas.size(); i++)
		{
			arregloGammas.at(i)->crearBalas();
		}
	}
	void cambiarDirecc() {
		for (int i = 0; i < arregloGammas.size(); i++)
		{
			arregloGammas.at(i)->cambiarDireccion();
		}
	}
};

#endif // !_ARRGAMMA_H_

