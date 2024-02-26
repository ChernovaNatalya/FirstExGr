#pragma once

namespace FirstEx {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();

			//
			//TODO: добавьте код конструктора
			//
			g = this->CreateGraphics();
	
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DomainUpDown^ domainUpDown1;

	protected: Graphics^ g;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	protected:  Image^ ChImage;
	protected:  Bitmap^ InterpImage;
	private: System::Windows::Forms::TrackBar^ trackBar1;
	protected:

	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->domainUpDown1 = (gcnew System::Windows::Forms::DomainUpDown());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->SuspendLayout();
			// 
			// domainUpDown1
			// 
			this->domainUpDown1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->domainUpDown1->Items->Add(L"»нтенсивность");
			this->domainUpDown1->Items->Add(L"Ѕинаризаци€");
			this->domainUpDown1->Items->Add(L"ќттенки серого");
			this->domainUpDown1->Items->Add(L"\?\?\?\?\?");
			this->domainUpDown1->Location = System::Drawing::Point(247, 515);
			this->domainUpDown1->Name = L"domainUpDown1";
			this->domainUpDown1->Size = System::Drawing::Size(272, 44);
			this->domainUpDown1->TabIndex = 0;
			this->domainUpDown1->Text = L"–ежим";
			this->domainUpDown1->SelectedItemChanged += gcnew System::EventHandler(this, &MyForm::domainUpDown1_SelectedItemChanged);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(34, 515);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(184, 72);
			this->button1->TabIndex = 2;
			this->button1->Text = L"¬џЅ–ј“№ ‘ј…Ћ";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(30, 601);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(224, 20);
			this->label1->TabIndex = 3;
			this->label1->Text = L"пожалуйста выберите файл";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(541, 518);
			this->trackBar1->Maximum = 128;
			this->trackBar1->Minimum = -128;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(407, 69);
			this->trackBar1->TabIndex = 4;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar1_Scroll);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(978, 644);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->domainUpDown1);
			this->MaximumSize = System::Drawing::Size(1000, 700);
			this->MinimumSize = System::Drawing::Size(1000, 700);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void domainUpDown1_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e) {
		if (InterpImage == nullptr) return;
		int a;
		try {
			a = (domainUpDown1->SelectedIndex);
			switch (a)
			{
			case 0: { New_Intens(); break; }
			case 1: { New_Binaris(); break; }
			case 2: { Ott_Ser(); break; }
			case 3: { Proba(); break; }
			default:
				break;
			}
		}
		catch (...) {}

		
	}
	private: void New_Intens() {
		try {
			InterpImage = gcnew Bitmap(ChImage);
			int a = trackBar1->Value;
			for (int j=0;j< InterpImage->Height;j++)
			for (int i = 0; i < InterpImage->Width; i++) {
				Color cl = InterpImage->GetPixel(i, j);
				int R = cl.R, G = cl.G, B = cl.B;
				R += a; if (R > 255) R = 255; if (R < 0) R = 0;
				G += a; if (G > 255) G = 255; if (G < 0) G = 0;
				B += a; if (B > 255) B = 255; if (B < 0) B = 0;
				InterpImage->SetPixel(i,j,Color::FromArgb(R,G,B));
			}
			g->DrawImage(InterpImage, 30 + 280 + 40, 30, 280, 280);

		}
		catch (...) {}
	}
	private: void New_Binaris() {
			   try {
				   InterpImage = gcnew Bitmap(ChImage);
				   int a = trackBar1->Value;
				   a += 127;
				   for (int j = 0; j < InterpImage->Height; j++)
					   for (int i = 0; i < InterpImage->Width; i++) {
						   Color cl = InterpImage->GetPixel(i, j);
						   int R = cl.R, G = cl.G, B = cl.B;

						   if ((R + G + B) / 3 < a) { R = 255; G = 255; B = 255;}
						   
						   else {
							   R = 0;
							   G = 0;
							   B = 0;
						   }
						   InterpImage->SetPixel(i, j, Color::FromArgb(R, G, B));
					   }
				   g->DrawImage(InterpImage, 30 + 280 + 40, 30, 280, 280);

			   }
			   catch (...) {}

		   }

		   private: void Ott_Ser() {
			   try {
				   InterpImage = gcnew Bitmap(ChImage);
				   int a = 0;
				   for (int j = 0; j < InterpImage->Height; j++)
					   for (int i = 0; i < InterpImage->Width; i++) {
						   Color cl = InterpImage->GetPixel(i, j);
						   int R = cl.R, G = cl.G, B = cl.B;
						   a = (R + G + B)/3;
						    R = a; G = a; B = a; 
						   InterpImage->SetPixel(i, j, Color::FromArgb(R, G, B));
					   }
				   g->DrawImage(InterpImage, 30 + 280 + 40, 30, 280, 280);

			   }
			   catch (...) {}

		   }
			private: void Proba() {
				try {
					InterpImage = gcnew Bitmap(ChImage);
					int a = trackBar1->Value;
					//a += 127;
					int ob = 0;
					for (int j = 0; j < InterpImage->Height; j++)
						for (int i = 0; i < InterpImage->Width; i++) {
							Color cl = InterpImage->GetPixel(i, j);
							int R = cl.R, G = cl.G, B = cl.B;
							ob = (R + G + B) / 3;
							R += ((R-ob)*a)/127; if (R > 255) R = 255; if (R < 0) R = 0;
							G += ((G - ob) * a) / 127; if (G > 255) G = 255; if (G < 0) G = 0;
							B += ((B - ob) * a) / 127; if (B > 255) B = 255; if (B < 0) B = 0;

								  
							InterpImage->SetPixel(i, j, Color::FromArgb(R, G, B));
						}
					g->DrawImage(InterpImage, 30 + 280 + 40, 30, 280, 280);

				}
				catch (...) {}
			}

	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		domainUpDown1_SelectedItemChanged(sender, e);
	}
private: System::Void fileSystemWatcher1_Changed(System::Object^ sender, System::IO::FileSystemEventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	openFileDialog1->Filter = "Image Files(*.bmp;*.jpg;*.png)|*.bmp;*.jpg;*.png";
	openFileDialog1->ShowDialog();
	ChImage = Image::FromFile(openFileDialog1->FileName);
	InterpImage = gcnew Bitmap(openFileDialog1->FileName, true);
	g->DrawImage(ChImage,30,30,280,280);
	label1->Text= openFileDialog1->FileName;
	domainUpDown1_SelectedItemChanged(sender, e);
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e) {
	if (domainUpDown1->SelectedIndex!=2) domainUpDown1_SelectedItemChanged(sender, e);
}
};
};

