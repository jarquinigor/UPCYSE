#pragma once
#ifndef _ARRALFA_H_
#define _ARRALFA_H_

#include"CAlfa.h"
#include<vector>
using namespace std;

class CArrAlfa {
private:
	vector<CAlfa*>arregloAlfas;
public:
	CArrAlfa() {
		arregloAlfas = vector<CAlfa*>();
	}
	int getT() {
		return arregloAlfas.size();
	}
	vector<CAlfa*>getVecAlfa() {
		return arregloAlfas;
	}
	void setVector(vector<CAlfa*>arregloAlfas) {
		this->arregloAlfas = arregloAlfas;
	}
	int eliminarBalaDeUnAlfa(int i) {
		arregloAlfas.at(i)->eliminarBalasEnPos(i);
	}
	void Agregar(int nivel) {
		arregloAlfas.push_back(new CAlfa(nivel));
	}
	void dibujar(Graphics^g, Bitmap^bmpEnemigo) {
		for (int i = 0; i < arregloAlfas.size(); i++)
		{
			arregloAlfas.at(i)->Dibujar(g, bmpEnemigo);
		}
	}
	void eliminarEnPos(int indice) {
		arregloAlfas.erase(arregloAlfas.begin() + indice);
	}
	void mover(Graphics^g, int nivel, int dificultad, Bitmap^imgBala) {
		for (int i = 0; i < arregloAlfas.size(); i++)
		{
			arregloAlfas.at(i)->Mover(g, nivel, dificultad, imgBala);
		}
	}
	void crearBalas() {
		for (int i = 0; i < arregloAlfas.size(); i++)
		{
			arregloAlfas.at(i)->crearBalas();
		}
	}
	/*void eliminarBalaEnPos(int indice) {
	arregloAlfas.at(i)->eli
	}*/
};

#endif // !_ARRALFA_H_

