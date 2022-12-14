#pragma once
#include "frmPrincipal.h"

namespace MenuFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de frmMDI
	/// </summary>
	public ref class frmMDI : public System::Windows::Forms::Form
	{
	public:
		frmMDI(void)
		{
			InitializeComponent();
			//
			//TODO: agregar c�digo de constructor aqu�
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~frmMDI()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(frmMDI::typeid));
			this->SuspendLayout();
			// 
			// frmMDI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(474, 365);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->IsMdiContainer = true;
			this->Name = L"frmMDI";
			this->Text = L"UPCYSE";
			this->Load += gcnew System::EventHandler(this, &frmMDI::frmMDI_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void frmMDI_Load(System::Object^  sender, System::EventArgs^  e) {
		frmPrincipal^menu = gcnew frmPrincipal();
		menu->MdiParent = this;
		menu->Show();
	}
	};
}
