#pragma once
#include"CControladora.h"
#include<fstream>

namespace MenuFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de frmJuego
	/// </summary>
	public ref class frmJuego : public System::Windows::Forms::Form
	{
	public:
		frmJuego(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			Game = gcnew CControladora();
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmJuego()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		int n = 1; //NOS PERMITE LEER LA VIDA ACTUAL
		int n1 = 1; //NOS PERMITE LEER EL NIVEL ACTUAL
		CControladora^Game;
		int vidas, tiempo, dificultad;
		int AuxDatos;
		Bitmap^gameOver = gcnew Bitmap("Perdiste.png");
		Bitmap^youWin = gcnew Bitmap("Ganaste.png");

	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Timer^  Disparador;
	private: System::Windows::Forms::Timer^  GammaDirecc;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;

	private: System::ComponentModel::IContainer^  components;
			 /// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
			 void InitializeComponent(void)
			 {
				 this->components = (gcnew System::ComponentModel::Container());
				 System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(frmJuego::typeid));
				 this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
				 this->Disparador = (gcnew System::Windows::Forms::Timer(this->components));
				 this->GammaDirecc = (gcnew System::Windows::Forms::Timer(this->components));
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->label2 = (gcnew System::Windows::Forms::Label());
				 this->label3 = (gcnew System::Windows::Forms::Label());
				 this->label4 = (gcnew System::Windows::Forms::Label());
				 this->SuspendLayout();
				 // 
				 // timer1
				 // 
				 this->timer1->Enabled = true;
				 this->timer1->Tick += gcnew System::EventHandler(this, &frmJuego::timer1_Tick);
				 // 
				 // Disparador
				 // 
				 this->Disparador->Interval = 2500;
				 this->Disparador->Tick += gcnew System::EventHandler(this, &frmJuego::Disparador_Tick);
				 // 
				 // GammaDirecc
				 // 
				 this->GammaDirecc->Enabled = true;
				 this->GammaDirecc->Interval = 3000;
				 this->GammaDirecc->Tick += gcnew System::EventHandler(this, &frmJuego::GammaDirecc_Tick);
				 // 
				 // label1
				 // 
				 this->label1->AutoSize = true;
				 this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label1->Location = System::Drawing::Point(13, 9);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(64, 20);
				 this->label1->TabIndex = 0;
				 this->label1->Text = L"Vidas: ";
				 // 
				 // label2
				 // 
				 this->label2->AutoSize = true;
				 this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label2->Location = System::Drawing::Point(76, 9);
				 this->label2->Name = L"label2";
				 this->label2->Size = System::Drawing::Size(0, 20);
				 this->label2->TabIndex = 1;
				 // 
				 // label3
				 // 
				 this->label3->AutoSize = true;
				 this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label3->Location = System::Drawing::Point(189, 9);
				 this->label3->Name = L"label3";
				 this->label3->Size = System::Drawing::Size(0, 20);
				 this->label3->TabIndex = 3;
				 // 
				 // label4
				 // 
				 this->label4->AutoSize = true;
				 this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label4->Location = System::Drawing::Point(131, 9);
				 this->label4->Name = L"label4";
				 this->label4->Size = System::Drawing::Size(52, 20);
				 this->label4->TabIndex = 2;
				 this->label4->Text = L"Nivel:";
				 // 
				 // frmJuego
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(1284, 761);
				 this->Controls->Add(this->label3);
				 this->Controls->Add(this->label4);
				 this->Controls->Add(this->label2);
				 this->Controls->Add(this->label1);
				 this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
				 this->Name = L"frmJuego";
				 this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
				 this->Text = L"frmJuego";
				 this->Load += gcnew System::EventHandler(this, &frmJuego::frmJuego_Load);
				 this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &frmJuego::frmJuego_KeyDown);
				 this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &frmJuego::frmJuego_KeyUp);
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion
	private: System::Void frmJuego_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		switch (e->KeyCode)
		{
		case Keys::Left:
			Game->setDirPJ(Izquierda);
			break;
		case Keys::Right:
			Game->setDirPJ(Derecha);
			break;
		case Keys::Up:
			Game->setDirPJ(Arriba);
			break;
		case Keys::Down:
			Game->setDirPJ(Abajo);
			break;
		case Keys::Space:
			Game->crearBalasPJ();
			break;
		default:
			break;
		}
	}
	private: System::Void frmJuego_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		Game->setDirPJ(Ninguna);
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		Graphics^g = this->CreateGraphics();
		BufferedGraphicsContext^espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^buffer = espacio->Allocate(g, this->ClientRectangle);
		
		fstream archivo;
		int vidasCargadas;
		int nivelCargado;


		//ACTIVAREMOS EL TIMER DE BALAS SI LA DIFICULTAD ES AVANZADA
		if (Game->getDificultad() == 2) Disparador->Enabled = true;


		//METODO DONDE SE ENCUENTRAN TODOS LOS DATOS DEL JUEGO
		Game->TimerG(buffer->Graphics, vidas, tiempo, dificultad, timer1, AuxDatos);

		if (Game->getVidas() == 0)
		{
			g->DrawImage(gameOver, 350, 150, 550, 550);
			System::Threading::Thread::Sleep(4000);
			Application::Exit();
		}

		if (Game->getNivel() == 4)
		{
			g->DrawImage(youWin, 350, 120,550,550);
			System::Threading::Thread::Sleep(4000);
			Application::Exit();
		}

		this->label2->Text = Convert::ToString(Game->getVidas());
		this->label3->Text = Convert::ToString(Game->getNivel());


		buffer->Render(g);

		delete buffer;
		delete espacio;
	}
	private: System::Void Disparador_Tick(System::Object^  sender, System::EventArgs^  e) {
		Game->crearBalasAlfa();
		Game->crearBalasGamma();
		Game->crearBalasBeta();
	}
	private: System::Void GammaDirecc_Tick(System::Object^  sender, System::EventArgs^  e) {
		Game->CambiarDireccionGamma();
	}

	public:
		void setVidas(int vidas) {
			this->vidas = vidas;
		}
		void setTiempo(int tiempo) {
			this->tiempo = tiempo;
		}
		void setDificultad(int dificultad) {
			this->dificultad = dificultad;
		}
		void setAuxDatos(int AuxDatos) {
			this->AuxDatos = AuxDatos;
		}


private: System::Void frmJuego_Load(System::Object^  sender, System::EventArgs^  e) {
}
};
}
