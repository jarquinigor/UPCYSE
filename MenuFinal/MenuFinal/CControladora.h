#pragma once
#ifndef _CONTROLADORA_H_
#define _CONTROLADORA_H_
#include"CPersonaje.h"
#include"CArrAlfa.h"
#include"CArrGamma.h"
#include"CArrBeta.h"

using namespace System::Windows::Forms;

ref class CControladora {
private:
	//NIVEL 1
	///JUGADOR
	int vidasPJ, AuxDatos;
	int AuxDatos2;
	CPersonaje*pj;
	Bitmap^Personaje1;
	Bitmap^ProyectiPJ1;
	///MAPA1
	Bitmap^Mapa1;
	///ADVERSARIOS ALFA
	CArrAlfa*vecAlfa;
	Bitmap^Alfa1;
	Bitmap^ProyectilA1;
	///ADVERSARIOS BETA
	CArrBeta*vecBeta;
	Bitmap^Beta1;
	Bitmap^ProyectilB1;
	///ADVERSARIOS GAMMA
	CArrGamma*vecGamma;
	Bitmap^Gamma1;
	Bitmap^ProyectilG1;

	Bitmap^gameOver;
	int nivel;
	int dificultad;
	int tiempo;
	//
	bool auxInicializar;

public:
	CControladora() {
		//OBJETOS
		pj = new CPersonaje();
		vecAlfa = new CArrAlfa();
		vecGamma = new CArrGamma();
		vecBeta = new CArrBeta();
		gameOver = gcnew Bitmap("Perdiste.png");
		//IMAGENES
		///SPRITES Y MAPA
		Personaje1 = gcnew Bitmap("TheBatman.png");
		Mapa1 = gcnew Bitmap("Mapa1.png");
		Alfa1 = gcnew Bitmap("Ladron.png");
		Gamma1 = gcnew Bitmap("Guason.png");
		Beta1 = gcnew Bitmap("LadronArmado.png");
		///PROYECTILES
		ProyectiPJ1 = gcnew Bitmap("Batarang.png");
		ProyectilA1 = gcnew Bitmap("Proyectil1.png");
		ProyectilG1 = gcnew Bitmap("Proyectil1.png");
		ProyectilB1 = gcnew Bitmap("Proyectil1.png");
	
	
		//AUXILIAR QUE SIRVE PARA CAMBIAR TODOS LAS INICIALIZACIONES DE BITMAPS (IMAGENES)
		auxInicializar = true;

		//NIVEL
		nivel = 1;

		//CREAMOS A LOS ENEMIGOS DEL PRIMER NIVEL
		CrearAlfas(8);
		CrearGammas(8);
		CrearBeta(8);

		vidasPJ = 5;
		dificultad = 1;

		AuxDatos2 = 1; //IMPORTANTE PORQUE PERMITE USAR EL MENU DE CONFIGURACION Y PASAR LOS DATOS
	}
	int getNivel() {
		return nivel;
	}
	void setNivel(int nivel) {
		this->nivel = nivel;
	}
	int getVidas() {
		return vidasPJ;
	}
	int getDificultad() {
		return dificultad;
	}
	void setVidas(int vidasPJ) {
		this->vidasPJ = vidasPJ;
	}

	void CrearAdversarios() {
		CrearAlfas(10);
		CrearGammas(10);
		CrearBeta(8);
	}
	//PARA CAMBIAR NIVELES
	void CambiarNivel() {
		switch (nivel)
		{
		case 1:
			///SPRITES Y MAPA
			Personaje1 = gcnew Bitmap("TheBatman.png");
			Mapa1 = gcnew Bitmap("Mapa1.png");
			Alfa1 = gcnew Bitmap("Ladron.png");
			Gamma1 = gcnew Bitmap("Guason.png");
			Beta1 = gcnew Bitmap("LadronArmado.png");
			///PROYECTILES
			ProyectiPJ1 = gcnew Bitmap("Batarang.png");
			ProyectilA1 = gcnew Bitmap("Proyectil1.png");
			ProyectilG1 = gcnew Bitmap("Proyectil1.png");
			ProyectilB1 = gcnew Bitmap("Proyectil1.png");
			break;
		case 2:
			pj->setX(200);
			pj->setY(300);
			Personaje1 = gcnew Bitmap("Personaje.png");
			Mapa1 = gcnew Bitmap("Mapa2.png");
			Alfa1 = gcnew Bitmap("Contaminador.png");
			Gamma1 = gcnew Bitmap("Cientifico.png");
			Beta1 = gcnew Bitmap("Leñador.png");
			///PROYECTILES
			ProyectiPJ1 = gcnew Bitmap("Verde.png");
			ProyectilA1 = gcnew Bitmap("BolsaBasura.png");
			ProyectilG1 = gcnew Bitmap("Aerosol.png");
			ProyectilB1 = gcnew Bitmap("BolsaBasura.png");
			break;
		case 3:
			pj->setX(200);
			pj->setY(300);
			///SPRITES Y MAPA
			Personaje1 = gcnew Bitmap("TheBatman.png");
			Mapa1 = gcnew Bitmap("Mapa3.png");
			Alfa1 = gcnew Bitmap("Policia.png");
			Gamma1 = gcnew Bitmap("Congresista.png");
			Beta1 = gcnew Bitmap("Congresista2.png");
			///PROYECTILES
			ProyectiPJ1 = gcnew Bitmap("Batarang.png");
			ProyectilA1 = gcnew Bitmap("Proyectil1.png");
			ProyectilG1 = gcnew Bitmap("Dinero.png");
			ProyectilB1 = gcnew Bitmap("Dinero.png");
			break;
		default:
			break;
		}
	}

	//METODOS DEL JUGADOR
	void MoverPJ(Graphics^g)
	{
		pj->Mover(g, nivel/*, detectaBoss, PosEnBoss*/);
	}
	void DibujarPJ(Graphics^g, Bitmap^img) {
		pj->Dibujar(g, img);
	}
	void setDirPJ(Direccion direccion) {
		pj->setDireccion(direccion);
	}
	///BALAS DEL PERSONAJE
	void crearBalasPJ() {
		pj->crearBalas();
	}
	void moverBalasPJ(Graphics^g) {
		pj->moverBalas(g);
	}
	void dibujarBalasPJ(Graphics^g, Bitmap^img) {
		pj->dibujarBalas(g, img);
	}

	//METODOS DEL ARREGLO ALFA
	void CrearAlfas(int n) {
		for (int i = 0; i < n; i++)
		{
			vecAlfa->Agregar(nivel);
		}
	}
	void MoverAlfas(Graphics^g) {
		vecAlfa->mover(g, nivel, dificultad, ProyectilA1);
	}
	void DibujarAlfas(Graphics^g, Bitmap^img) {
		vecAlfa->dibujar(g, img);
	}
	void crearBalasAlfa() {
		vecAlfa->crearBalas();
	}

	//METODOS DE ARREGLO GAMMA
	void CrearGammas(int n) {
		for (int i = 0; i < n; i++)
		{
			vecGamma->Agregar(nivel);
		}
	}
	void MoverGammas(Graphics^g) {
		vecGamma->mover(g, nivel, dificultad, ProyectilG1);
	}
	void DibujarGammas(Graphics^g, Bitmap^img) {
		vecGamma->dibujar(g, img);
	}
	void crearBalasGamma() {
		vecGamma->crearBalas();
	}
	void CambiarDireccionGamma() {
		vecGamma->cambiarDirecc();
	}
	//METODOS DEL ARREGLO BETA
	void CrearBeta(int n) {
		for (int i = 0; i < n; i++)
		{
			vecBeta->Agregar(nivel);
		}
	}
	void MoverBetas(Graphics^g) {
		vecBeta->mover(g, nivel, dificultad, ProyectilB1);
	}
	void DibujarBetas(Graphics^g, Bitmap^img) {
		vecBeta->dibujar(g, img);
	}
	void crearBalasBeta() {
		vecBeta->crearBalas();
	}
	//COLISIONES
	void ColisionBalasPJA() {
		for (int i = 0; i < pj->getTBalas(); i++) //BALAS
		{
			vector<CBala*>vecBalas = pj->getVecBala();
			for (int k = 0; k < vecAlfa->getT(); k++) //ENEMIGO
			{
				vector<CAlfa*>vecA = vecAlfa->getVecAlfa();
				if (vecBalas.at(i)->getRectangulo().IntersectsWith(vecA.at(k)->getRectangulo()))
				{
					vecAlfa->eliminarEnPos(k);
					pj->eliminarBalaEnPos(i);
					break;
				}
			}
		}
	}
	void ColisionBalasPJG() {
		for (int i = 0; i < pj->getTBalas(); i++) //BALAS
		{
			vector<CBala*>vecBalas = pj->getVecBala();
			for (int k = 0; k < vecGamma->getT(); k++) //ENEMIGO
			{
				vector<CGamma*>vecG = vecGamma->getVecGamma();
				if (vecBalas.at(i)->getRectangulo().IntersectsWith(vecG.at(k)->getRectangulo()))
				{
					vecGamma->eliminarEnPos(k);
					pj->eliminarBalaEnPos(i);
					break;
				}
			}
		}
	}
	void ColisionBalasPJB() {
		for (int i = 0; i < pj->getTBalas(); i++) //BALAS
		{
			vector<CBala*>vecBalas = pj->getVecBala();
			for (int k = 0; k < vecBeta->getT(); k++) //ENEMIGO
			{
				vector<CBeta*>vecB = vecBeta->getVecBeta();
				if (vecBalas.at(i)->getRectangulo().IntersectsWith(vecB.at(k)->getRectangulo()))
				{
					vecBeta->eliminarEnPos(k);
					pj->eliminarBalaEnPos(i);
					break;
				}
			}
		}
	}
	///COLISIONES ENEMIGOS - PJ
	void ColisionBalasAPJ() {
		vector<CAlfa*>vA = vecAlfa->getVecAlfa(); //ENEMIGOS ALFAS
		for (int i = 0; i < vecAlfa->getT(); i++)
		{
			vector<CBala*>vBalas = vA.at(i)->getVecBalas();
			for (int k = 0; k < vA.at(i)->getTBalas(); k++) //BALAS DE UN ALFA
			{
				if (vBalas.at(k)->getRectangulo().IntersectsWith(pj->getRectangulo()))
				{
					vA.at(i)->eliminarBalasEnPos(k);
					vecAlfa->setVector(vA);
					vidasPJ--;
					break;
				}
			}
		}
	}
	void ColisionBalasBPJ() {
		vector<CBeta*>vB = vecBeta->getVecBeta(); //ENEMIGOS ALFAS
		for (int i = 0; i < vecBeta->getT(); i++)
		{
			vector<CBala*>vBalas = vB.at(i)->getVecBalas();
			for (int k = 0; k < vB.at(i)->getTBalasB(); k++) //BALAS DE UN ALFA
			{
				if (vBalas.at(k)->getRectangulo().IntersectsWith(pj->getRectangulo()))
				{
					vB.at(i)->eliminarBalasEnPos(k);
					vecBeta->setVector(vB);
					vidasPJ--;
					break;
				}
			}
		}
	}
	void ColisionBalasGPJ() {
		vector<CGamma*>vG = vecGamma->getVecGamma(); //ENEMIGOS ALFAS
		for (int i = 0; i < vecGamma->getT(); i++)
		{
			vector<CBala*>vBalas = vG.at(i)->getVecBalas();
			for (int k = 0; k < vG.at(i)->getTBalas(); k++) //BALAS DE UN ALFA
			{
				if (vBalas.at(k)->getRectangulo().IntersectsWith(pj->getRectangulo()))
				{
					vG.at(i)->eliminarBalasEnPos(k);
					vecGamma->setVector(vG);
					vidasPJ--;
					break;
				}
			}
		}
	}

	void TimerG(Graphics^g, int vidas, int tiempo, int dificultad, Timer^timer,int AuxDatos) {
		int anchoForm = g->VisibleClipBounds.Width;
		int altoForm = g->VisibleClipBounds.Height;

		for (int i = 0; i < 1 && AuxDatos2==1; i++)
		{
			this->AuxDatos = AuxDatos; //PARA PODER USAR LA CONFIGURACION 1 VEZ
			AuxDatos2 = 2;
		} 

		for (int i = 0; i < 1 && this->AuxDatos == 1; i++)
		{
			///AL USAR LA CONFIGURACION
			this->vidasPJ = vidas;
			this->dificultad = dificultad;
			this->AuxDatos = 2;
		}

		if (vecAlfa->getT() + vecBeta->getT() + vecGamma->getT() == 0)
		{
			nivel++;
			CrearAdversarios();
			auxInicializar = true;
		}

		switch (nivel)
		{
		case 1:
			if (auxInicializar == true)
			{
				CambiarNivel();
				auxInicializar = false;

			}
			//DIBUJAMOS EL MAPA
			g->DrawImage(Mapa1, 0, 0, anchoForm, altoForm);
			//JUGADOR
			MoverPJ(g);
			DibujarPJ(g, Personaje1);
			///BALAS DEL JUGADOR
			moverBalasPJ(g);
			dibujarBalasPJ(g, ProyectiPJ1);
			//ENEMIGOS
			///ALFAS
			MoverAlfas(g);
			DibujarAlfas(g, Alfa1);
			///GAMMAS
			MoverGammas(g);
			DibujarGammas(g, Gamma1);
			///BETAS
			MoverBetas(g);
			DibujarBetas(g, Beta1);
			//COLISIONES 
			///DEL JUGADOR A ADVERSARIOS
			ColisionBalasPJA();
			ColisionBalasPJG();
			ColisionBalasPJB();
			///DE ADVERSARIOS AL JUGADOR
			if (vidasPJ != 0)
			{
				ColisionBalasAPJ();
				ColisionBalasBPJ();
				ColisionBalasGPJ();
			}
			break;
		case 2:
			if (auxInicializar == true)
			{
				CambiarNivel();
				auxInicializar = false;
			}
			//DIBUJAMOS EL MAPA
			g->DrawImage(Mapa1, 0, 0, anchoForm, altoForm);
			//JUGADOR
			MoverPJ(g);
			DibujarPJ(g, Personaje1);
			///BALAS DEL JUGADOR
			moverBalasPJ(g);
			dibujarBalasPJ(g, ProyectiPJ1);
			//ENEMIGOS
			///ALFAS
			MoverAlfas(g);
			DibujarAlfas(g, Alfa1);
			///GAMMAS
			MoverGammas(g);
			DibujarGammas(g, Gamma1);
			///BETAS
			MoverBetas(g);
			DibujarBetas(g, Beta1);
			//COLISIONES 
			///DEL JUGADOR A ADVERSARIOS
			ColisionBalasPJA();
			ColisionBalasPJG();
			ColisionBalasPJB();
			///DE ADVERSARIOS AL JUGADOR
			if (vidasPJ != 0)
			{
				ColisionBalasAPJ();
				ColisionBalasBPJ();
				ColisionBalasGPJ();
			}
			break;
		case 3:
			if (auxInicializar == true)
			{
				CambiarNivel();
				auxInicializar = false;

			}
			//DIBUJAMOS EL MAPA
			g->DrawImage(Mapa1, 0, 0, anchoForm, altoForm);
			//JUGADOR
			MoverPJ(g);
			DibujarPJ(g, Personaje1);
			///BALAS DEL JUGADOR
			moverBalasPJ(g);
			dibujarBalasPJ(g, ProyectiPJ1);
			//ENEMIGOS
			///ALFAS
			MoverAlfas(g);
			DibujarAlfas(g, Alfa1);
			///GAMMAS
			MoverGammas(g);
			DibujarGammas(g, Gamma1);
			///BETAS
			MoverBetas(g);
			DibujarBetas(g, Beta1);
			//COLISIONES 
			///DEL JUGADOR A ADVERSARIOS
			ColisionBalasPJA();
			ColisionBalasPJG();
			ColisionBalasPJB();
			///DE ADVERSARIOS AL JUGADOR
			if (vidasPJ != 0)
			{
				ColisionBalasAPJ();
				ColisionBalasBPJ();
				ColisionBalasGPJ();
			}
			break;
		default:
			break;
		}
	}

	
};
#endif // !_CONTROLADORA_H_

