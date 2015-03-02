#pragma once

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<Math.h>
#include<iostream>
#include<fstream>
#include<cmatrix>
#include<vector>
#include <string.h>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <functional>
#include <time.h>

using namespace std;

typedef techsoft::matrix<double> Matrix;
typedef std::valarray<double>    Vector;
typedef std::valarray<int>   iVector;

//stores vector/matrix size received from user
int vectorLength = 3;
//stores positions for v and b received from user
int firstPos, secondPos;
//stores converted String^ values
string fromString = "convert";
//checks whether graph is visible
bool graph = false;
//stores the number of times the button to increase database size has been clicked
int doubleDBCount = 0;

//Unit Vector, Noise and scalar Vector V1, Noise Vector B, Encrypted Vector V, Encrypted Vector B
Vector U(vectorLength), V(vectorLength), B(vectorLength), Ev(vectorLength), Eb(vectorLength);
//Identity Matrix, Matrix to be used as Encryption/Decryption key, Inverse of key Matrix, Transpose of key Matrix
Matrix I(vectorLength, vectorLength, 0.0), M(vectorLength, vectorLength), Minv(vectorLength, vectorLength), Mt(vectorLength, vectorLength);
//Used for Indexing
Vector B1(vectorLength), EB1(vectorLength);

namespace frmLES{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::Sql;
	using namespace System::Data::SqlClient;
	using namespace System::Configuration;
	using namespace System::Data::Odbc;
	using namespace System::IO;
	
	/// <summary>
	/// Summary for Form
	/// </summary>

	public ref class Form1 : public System::Windows::Forms::Form
	{
		OdbcConnection^ myConnection;
		//stores user selected tablename to be encrypted
		String^ tableToEncrypt="";
		//stores the name of the encrypted table selected by user
		String^ encrptedTable="";
		//stores the name of the attribute used in the range query selected by user. 
		String^ queryAttribute="";
		//stores the relational operator(<,>,=,<=,>=) selected by user. 
		String^ rangeOperator="";
		//stores the query on the encrypted table entered by the user
		String^ queryString="";			

	private: System::Windows::Forms::GroupBox^  groupDBView;
	private: System::Windows::Forms::DataGridView^  dataGridDBView;
	private: System::Windows::Forms::RichTextBox^  richText;
	private: System::Windows::Forms::ComboBox^  comboRange;

	private: System::Windows::Forms::Label^  labelValue;

	private: System::Windows::Forms::Label^  labelRange;
	private: System::Windows::Forms::TextBox^  textQueryValue;
	private: System::Windows::Forms::LinkLabel^  linkFile;
	private: System::Windows::Forms::Label^  labelNotify;
	private: System::Windows::Forms::Label^  labelTime;
	private: System::Windows::Forms::GroupBox^  groupStat;
	private: System::Windows::Forms::GroupBox^  groupNotify;
	private: System::Windows::Forms::LinkLabel^  linkLabel1;
	private: System::Windows::Forms::Button^  buttonGraph;

	private: System::Windows::Forms::GroupBox^  groupProcessView;


	private: System::Windows::Forms::GroupBox^  groupGraphVector;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chartVector;
	private: System::Windows::Forms::DataGridView^  dataGridViewProcess;
	private: System::Windows::Forms::Button^  buttonDoubleDB;


	private: System::Windows::Forms::Label^  label1;
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	protected:

	protected:

	private: System::Windows::Forms::GroupBox^  groupEncrypt;
	private: System::Windows::Forms::ComboBox^  comboEncrypt;
	private: System::Windows::Forms::Label^  labelSize;
	private: System::Windows::Forms::Label^  labelEncrypt;
	private: System::Windows::Forms::NumericUpDown^  numericSize;
	private: System::Windows::Forms::Button^  buttonEncrypt;
	private: System::Windows::Forms::GroupBox^  groupQuery;
	private: System::Windows::Forms::ComboBox^  comboQuery;
	private: System::Windows::Forms::ComboBox^  comboAttributes;
	private: System::Windows::Forms::Button^  buttonRunQuery;
	private: System::Windows::Forms::Label^  labelAttributes;
	private: System::Windows::Forms::Label^  labelQuery;

	private: System::Windows::Forms::NotifyIcon^  notifyIcon;

	private: System::Windows::Forms::Label^  labelPos;
	private: System::Windows::Forms::NumericUpDown^  numericPos2;
	private: System::Windows::Forms::NumericUpDown^  numericPos1;
	private: System::ComponentModel::IContainer^  components;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea3 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea4 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->groupEncrypt = (gcnew System::Windows::Forms::GroupBox());
			this->buttonDoubleDB = (gcnew System::Windows::Forms::Button());
			this->labelPos = (gcnew System::Windows::Forms::Label());
			this->numericPos2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericPos1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->buttonEncrypt = (gcnew System::Windows::Forms::Button());
			this->numericSize = (gcnew System::Windows::Forms::NumericUpDown());
			this->labelSize = (gcnew System::Windows::Forms::Label());
			this->labelEncrypt = (gcnew System::Windows::Forms::Label());
			this->comboEncrypt = (gcnew System::Windows::Forms::ComboBox());
			this->groupQuery = (gcnew System::Windows::Forms::GroupBox());
			this->buttonGraph = (gcnew System::Windows::Forms::Button());
			this->textQueryValue = (gcnew System::Windows::Forms::TextBox());
			this->buttonRunQuery = (gcnew System::Windows::Forms::Button());
			this->comboRange = (gcnew System::Windows::Forms::ComboBox());
			this->labelValue = (gcnew System::Windows::Forms::Label());
			this->labelRange = (gcnew System::Windows::Forms::Label());
			this->comboQuery = (gcnew System::Windows::Forms::ComboBox());
			this->comboAttributes = (gcnew System::Windows::Forms::ComboBox());
			this->labelAttributes = (gcnew System::Windows::Forms::Label());
			this->labelQuery = (gcnew System::Windows::Forms::Label());
			this->richText = (gcnew System::Windows::Forms::RichTextBox());
			this->notifyIcon = (gcnew System::Windows::Forms::NotifyIcon(this->components));
			this->groupDBView = (gcnew System::Windows::Forms::GroupBox());
			this->dataGridDBView = (gcnew System::Windows::Forms::DataGridView());
			this->linkFile = (gcnew System::Windows::Forms::LinkLabel());
			this->labelNotify = (gcnew System::Windows::Forms::Label());
			this->labelTime = (gcnew System::Windows::Forms::Label());
			this->groupStat = (gcnew System::Windows::Forms::GroupBox());
			this->groupNotify = (gcnew System::Windows::Forms::GroupBox());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupProcessView = (gcnew System::Windows::Forms::GroupBox());
			this->dataGridViewProcess = (gcnew System::Windows::Forms::DataGridView());
			this->groupGraphVector = (gcnew System::Windows::Forms::GroupBox());
			this->chartVector = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->groupEncrypt->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericPos2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericPos1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericSize))->BeginInit();
			this->groupQuery->SuspendLayout();
			this->groupDBView->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridDBView))->BeginInit();
			this->groupStat->SuspendLayout();
			this->groupNotify->SuspendLayout();
			this->groupProcessView->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewProcess))->BeginInit();
			this->groupGraphVector->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartVector))->BeginInit();
			this->SuspendLayout();
			// 
			// groupEncrypt
			// 
			this->groupEncrypt->Controls->Add(this->buttonDoubleDB);
			this->groupEncrypt->Controls->Add(this->labelPos);
			this->groupEncrypt->Controls->Add(this->numericPos2);
			this->groupEncrypt->Controls->Add(this->numericPos1);
			this->groupEncrypt->Controls->Add(this->buttonEncrypt);
			this->groupEncrypt->Controls->Add(this->numericSize);
			this->groupEncrypt->Controls->Add(this->labelSize);
			this->groupEncrypt->Controls->Add(this->labelEncrypt);
			this->groupEncrypt->Controls->Add(this->comboEncrypt);
			this->groupEncrypt->Font = (gcnew System::Drawing::Font(L"Calibri", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupEncrypt->Location = System::Drawing::Point(10, 10);
			this->groupEncrypt->Margin = System::Windows::Forms::Padding(2);
			this->groupEncrypt->Name = L"groupEncrypt";
			this->groupEncrypt->Padding = System::Windows::Forms::Padding(2);
			this->groupEncrypt->Size = System::Drawing::Size(319, 115);
			this->groupEncrypt->TabIndex = 1;
			this->groupEncrypt->TabStop = false;
			this->groupEncrypt->Text = L"ENCRYPT DATABASE";
			// 
			// buttonDoubleDB
			// 
			this->buttonDoubleDB->Location = System::Drawing::Point(108, 81);
			this->buttonDoubleDB->Name = L"buttonDoubleDB";
			this->buttonDoubleDB->Size = System::Drawing::Size(100, 24);
			this->buttonDoubleDB->TabIndex = 8;
			this->buttonDoubleDB->Text = L"Double DB Size";
			this->buttonDoubleDB->UseVisualStyleBackColor = true;
			this->buttonDoubleDB->Click += gcnew System::EventHandler(this, &Form1::buttonDoubleDB_Click);
			// 
			// labelPos
			// 
			this->labelPos->AutoSize = true;
			this->labelPos->Location = System::Drawing::Point(146, 54);
			this->labelPos->Name = L"labelPos";
			this->labelPos->Size = System::Drawing::Size(61, 15);
			this->labelPos->TabIndex = 7;
			this->labelPos->Text = L"Positions:";
			// 
			// numericPos2
			// 
			this->numericPos2->BackColor = System::Drawing::SystemColors::ControlLight;
			this->numericPos2->Location = System::Drawing::Point(266, 52);
			this->numericPos2->Maximum = this->numericPos1->Maximum;
			this->numericPos2->Name = L"numericPos2";
			this->numericPos2->Size = System::Drawing::Size(48, 23);
			this->numericPos2->TabIndex = 6;
			this->numericPos2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// numericPos1
			// 
			this->numericPos1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->numericPos1->Location = System::Drawing::Point(214, 52);
			this->numericPos1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			this->numericPos1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericPos1->Name = L"numericPos1";
			this->numericPos1->Size = System::Drawing::Size(55, 23);
			this->numericPos1->TabIndex = 5;
			this->numericPos1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericPos1->ValueChanged += gcnew System::EventHandler(this, &Form1::numericPos1_ValueChanged);
			// 
			// buttonEncrypt
			// 
			this->buttonEncrypt->Location = System::Drawing::Point(214, 81);
			this->buttonEncrypt->Name = L"buttonEncrypt";
			this->buttonEncrypt->Size = System::Drawing::Size(100, 24);
			this->buttonEncrypt->TabIndex = 4;
			this->buttonEncrypt->Text = L"Encrypt";
			this->buttonEncrypt->UseVisualStyleBackColor = true;
			this->buttonEncrypt->Click += gcnew System::EventHandler(this, &Form1::buttonEncrypt_Click);
			// 
			// numericSize
			// 
			this->numericSize->BackColor = System::Drawing::SystemColors::ControlLight;
			this->numericSize->Location = System::Drawing::Point(90, 50);
			this->numericSize->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			this->numericSize->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			this->numericSize->Name = L"numericSize";
			this->numericSize->Size = System::Drawing::Size(51, 23);
			this->numericSize->TabIndex = 3;
			this->numericSize->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			this->numericSize->ValueChanged += gcnew System::EventHandler(this, &Form1::numericSize_ValueChanged);
			// 
			// labelSize
			// 
			this->labelSize->AutoSize = true;
			this->labelSize->Location = System::Drawing::Point(5, 52);
			this->labelSize->Name = L"labelSize";
			this->labelSize->Size = System::Drawing::Size(68, 15);
			this->labelSize->TabIndex = 2;
			this->labelSize->Text = L"Vector Size:";
			// 
			// labelEncrypt
			// 
			this->labelEncrypt->AutoSize = true;
			this->labelEncrypt->Location = System::Drawing::Point(5, 24);
			this->labelEncrypt->Name = L"labelEncrypt";
			this->labelEncrypt->Size = System::Drawing::Size(62, 15);
			this->labelEncrypt->TabIndex = 1;
			this->labelEncrypt->Text = L"Database:";
			// 
			// comboEncrypt
			// 
			this->comboEncrypt->BackColor = System::Drawing::SystemColors::ControlLight;
			this->comboEncrypt->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->comboEncrypt->FormattingEnabled = true;
			this->comboEncrypt->Location = System::Drawing::Point(90, 21);
			this->comboEncrypt->Name = L"comboEncrypt";
			this->comboEncrypt->Size = System::Drawing::Size(224, 23);
			this->comboEncrypt->Sorted = true;
			this->comboEncrypt->TabIndex = 0;
			this->comboEncrypt->Text = L"Select";
			this->comboEncrypt->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboEncrypt_SelectedIndexChanged_1);
			// 
			// groupQuery
			// 
			this->groupQuery->Controls->Add(this->buttonGraph);
			this->groupQuery->Controls->Add(this->textQueryValue);
			this->groupQuery->Controls->Add(this->buttonRunQuery);
			this->groupQuery->Controls->Add(this->comboRange);
			this->groupQuery->Controls->Add(this->labelValue);
			this->groupQuery->Controls->Add(this->labelRange);
			this->groupQuery->Controls->Add(this->comboQuery);
			this->groupQuery->Controls->Add(this->comboAttributes);
			this->groupQuery->Controls->Add(this->labelAttributes);
			this->groupQuery->Controls->Add(this->labelQuery);
			this->groupQuery->Font = (gcnew System::Drawing::Font(L"Calibri", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupQuery->Location = System::Drawing::Point(12, 129);
			this->groupQuery->Margin = System::Windows::Forms::Padding(2);
			this->groupQuery->Name = L"groupQuery";
			this->groupQuery->Padding = System::Windows::Forms::Padding(2);
			this->groupQuery->Size = System::Drawing::Size(319, 162);
			this->groupQuery->TabIndex = 5;
			this->groupQuery->TabStop = false;
			this->groupQuery->Text = L"QUERY DATABASE";
			// 
			// buttonGraph
			// 
			this->buttonGraph->Location = System::Drawing::Point(77, 106);
			this->buttonGraph->Name = L"buttonGraph";
			this->buttonGraph->Size = System::Drawing::Size(131, 24);
			this->buttonGraph->TabIndex = 13;
			this->buttonGraph->Text = L"Show/Hide Graph";
			this->buttonGraph->UseVisualStyleBackColor = true;
			this->buttonGraph->Click += gcnew System::EventHandler(this, &Form1::buttonGraph_Click);
			// 
			// textQueryValue
			// 
			this->textQueryValue->Location = System::Drawing::Point(183, 77);
			this->textQueryValue->Name = L"textQueryValue";
			this->textQueryValue->Size = System::Drawing::Size(131, 23);
			this->textQueryValue->TabIndex = 12;
			// 
			// buttonRunQuery
			// 
			this->buttonRunQuery->Location = System::Drawing::Point(214, 106);
			this->buttonRunQuery->Name = L"buttonRunQuery";
			this->buttonRunQuery->Size = System::Drawing::Size(100, 24);
			this->buttonRunQuery->TabIndex = 4;
			this->buttonRunQuery->Text = L"Run Query";
			this->buttonRunQuery->UseVisualStyleBackColor = true;
			this->buttonRunQuery->Click += gcnew System::EventHandler(this, &Form1::buttonRunQuery_Click);
			// 
			// comboRange
			// 
			this->comboRange->AllowDrop = true;
			this->comboRange->BackColor = System::Drawing::SystemColors::ControlLight;
			this->comboRange->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->comboRange->FormattingEnabled = true;
			this->comboRange->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"<", L">", L"<=", L">=", L"=" });
			this->comboRange->Location = System::Drawing::Point(88, 77);
			this->comboRange->MaxDropDownItems = 100;
			this->comboRange->Name = L"comboRange";
			this->comboRange->Size = System::Drawing::Size(43, 23);
			this->comboRange->TabIndex = 11;
			this->comboRange->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboRange_SelectedIndexChanged);
			// 
			// labelValue
			// 
			this->labelValue->AutoSize = true;
			this->labelValue->Location = System::Drawing::Point(139, 80);
			this->labelValue->Name = L"labelValue";
			this->labelValue->Size = System::Drawing::Size(40, 15);
			this->labelValue->TabIndex = 10;
			this->labelValue->Text = L"Value:";
			// 
			// labelRange
			// 
			this->labelRange->AutoSize = true;
			this->labelRange->Location = System::Drawing::Point(7, 81);
			this->labelRange->Name = L"labelRange";
			this->labelRange->Size = System::Drawing::Size(43, 15);
			this->labelRange->TabIndex = 9;
			this->labelRange->Text = L"Range:";
			// 
			// comboQuery
			// 
			this->comboQuery->BackColor = System::Drawing::SystemColors::ControlLight;
			this->comboQuery->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->comboQuery->FormattingEnabled = true;
			this->comboQuery->Location = System::Drawing::Point(88, 20);
			this->comboQuery->Name = L"comboQuery";
			this->comboQuery->Size = System::Drawing::Size(226, 23);
			this->comboQuery->Sorted = true;
			this->comboQuery->TabIndex = 8;
			this->comboQuery->Text = L"Select";
			this->comboQuery->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboQuery_SelectedIndexChanged_1);
			// 
			// comboAttributes
			// 
			this->comboAttributes->AllowDrop = true;
			this->comboAttributes->BackColor = System::Drawing::SystemColors::ControlLight;
			this->comboAttributes->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->comboAttributes->FormattingEnabled = true;
			this->comboAttributes->Location = System::Drawing::Point(88, 48);
			this->comboAttributes->MaxDropDownItems = 100;
			this->comboAttributes->Name = L"comboAttributes";
			this->comboAttributes->Size = System::Drawing::Size(226, 23);
			this->comboAttributes->TabIndex = 5;
			this->comboAttributes->Text = L"Select";
			this->comboAttributes->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboAttributes_SelectedIndexChanged);
			// 
			// labelAttributes
			// 
			this->labelAttributes->AutoSize = true;
			this->labelAttributes->Location = System::Drawing::Point(5, 52);
			this->labelAttributes->Name = L"labelAttributes";
			this->labelAttributes->Size = System::Drawing::Size(64, 15);
			this->labelAttributes->TabIndex = 2;
			this->labelAttributes->Text = L"Attributes:";
			// 
			// labelQuery
			// 
			this->labelQuery->AutoSize = true;
			this->labelQuery->Location = System::Drawing::Point(5, 24);
			this->labelQuery->Name = L"labelQuery";
			this->labelQuery->Size = System::Drawing::Size(62, 15);
			this->labelQuery->TabIndex = 1;
			this->labelQuery->Text = L"Database:";
			// 
			// richText
			// 
			this->richText->AutoWordSelection = true;
			this->richText->Location = System::Drawing::Point(18, 284);
			this->richText->Name = L"richText";
			this->richText->ReadOnly = true;
			this->richText->Size = System::Drawing::Size(308, 57);
			this->richText->TabIndex = 11;
			this->richText->Text = L"";
			// 
			// notifyIcon
			// 
			this->notifyIcon->Visible = true;
			// 
			// groupDBView
			// 
			this->groupDBView->Controls->Add(this->dataGridDBView);
			this->groupDBView->Font = (gcnew System::Drawing::Font(L"Calibri", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupDBView->Location = System::Drawing::Point(356, 129);
			this->groupDBView->Margin = System::Windows::Forms::Padding(2);
			this->groupDBView->Name = L"groupDBView";
			this->groupDBView->Padding = System::Windows::Forms::Padding(2);
			this->groupDBView->Size = System::Drawing::Size(530, 226);
			this->groupDBView->TabIndex = 10;
			this->groupDBView->TabStop = false;
			this->groupDBView->Text = L"DATABASE VIEW";
			// 
			// dataGridDBView
			// 
			this->dataGridDBView->BackgroundColor = System::Drawing::SystemColors::ControlLight;
			this->dataGridDBView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::ControlLight;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Calibri", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridDBView->DefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridDBView->GridColor = System::Drawing::SystemColors::ControlLight;
			this->dataGridDBView->Location = System::Drawing::Point(6, 19);
			this->dataGridDBView->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->dataGridDBView->Name = L"dataGridDBView";
			this->dataGridDBView->RowHeadersVisible = false;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::ControlLight;
			this->dataGridDBView->RowsDefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridDBView->Size = System::Drawing::Size(518, 196);
			this->dataGridDBView->TabIndex = 0;
			// 
			// linkFile
			// 
			this->linkFile->AutoSize = true;
			this->linkFile->Location = System::Drawing::Point(112, 2);
			this->linkFile->Name = L"linkFile";
			this->linkFile->Size = System::Drawing::Size(0, 15);
			this->linkFile->TabIndex = 12;
			// 
			// labelNotify
			// 
			this->labelNotify->AutoSize = true;
			this->labelNotify->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->labelNotify->Font = (gcnew System::Drawing::Font(L"Calibri", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelNotify->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->labelNotify->Location = System::Drawing::Point(10, 19);
			this->labelNotify->Name = L"labelNotify";
			this->labelNotify->Size = System::Drawing::Size(2, 17);
			this->labelNotify->TabIndex = 9;
			// 
			// labelTime
			// 
			this->labelTime->AutoSize = true;
			this->labelTime->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->labelTime->Font = (gcnew System::Drawing::Font(L"Calibri", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelTime->ForeColor = System::Drawing::Color::Black;
			this->labelTime->Location = System::Drawing::Point(9, 17);
			this->labelTime->Name = L"labelTime";
			this->labelTime->Size = System::Drawing::Size(2, 17);
			this->labelTime->TabIndex = 13;
			// 
			// groupStat
			// 
			this->groupStat->BackColor = System::Drawing::SystemColors::ControlLight;
			this->groupStat->Controls->Add(this->linkFile);
			this->groupStat->Controls->Add(this->labelTime);
			this->groupStat->ForeColor = System::Drawing::Color::Black;
			this->groupStat->Location = System::Drawing::Point(362, 356);
			this->groupStat->Name = L"groupStat";
			this->groupStat->Size = System::Drawing::Size(312, 64);
			this->groupStat->TabIndex = 14;
			this->groupStat->TabStop = false;
			this->groupStat->Text = L"STATISTICS";
			// 
			// groupNotify
			// 
			this->groupNotify->BackColor = System::Drawing::SystemColors::ControlLight;
			this->groupNotify->Controls->Add(this->linkLabel1);
			this->groupNotify->Controls->Add(this->labelNotify);
			this->groupNotify->Controls->Add(this->label1);
			this->groupNotify->ForeColor = System::Drawing::Color::Black;
			this->groupNotify->Location = System::Drawing::Point(19, 356);
			this->groupNotify->Name = L"groupNotify";
			this->groupNotify->Size = System::Drawing::Size(312, 64);
			this->groupNotify->TabIndex = 15;
			this->groupNotify->TabStop = false;
			this->groupNotify->Text = L"NOTIFICATIONS";
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->Location = System::Drawing::Point(112, 2);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(0, 15);
			this->linkLabel1->TabIndex = 12;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Calibri", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label1->Location = System::Drawing::Point(16, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 15);
			this->label1->TabIndex = 9;
			// 
			// groupProcessView
			// 
			this->groupProcessView->Controls->Add(this->dataGridViewProcess);
			this->groupProcessView->Font = (gcnew System::Drawing::Font(L"Calibri", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupProcessView->Location = System::Drawing::Point(356, 11);
			this->groupProcessView->Margin = System::Windows::Forms::Padding(2);
			this->groupProcessView->Name = L"groupProcessView";
			this->groupProcessView->Padding = System::Windows::Forms::Padding(2);
			this->groupProcessView->Size = System::Drawing::Size(530, 114);
			this->groupProcessView->TabIndex = 9;
			this->groupProcessView->TabStop = false;
			this->groupProcessView->Text = L"PROCESS OVERVIEW";
			// 
			// dataGridViewProcess
			// 
			this->dataGridViewProcess->BackgroundColor = System::Drawing::SystemColors::ControlLight;
			this->dataGridViewProcess->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridViewProcess->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::ControlLight;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Calibri", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridViewProcess->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridViewProcess->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewProcess->ColumnHeadersVisible = false;
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle4->BackColor = System::Drawing::SystemColors::ControlLight;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Calibri", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle4->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridViewProcess->DefaultCellStyle = dataGridViewCellStyle4;
			this->dataGridViewProcess->Location = System::Drawing::Point(9, 18);
			this->dataGridViewProcess->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->dataGridViewProcess->Name = L"dataGridViewProcess";
			this->dataGridViewProcess->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			this->dataGridViewProcess->RowHeadersVisible = false;
			dataGridViewCellStyle5->BackColor = System::Drawing::SystemColors::ControlLight;
			this->dataGridViewProcess->RowsDefaultCellStyle = dataGridViewCellStyle5;
			this->dataGridViewProcess->Size = System::Drawing::Size(515, 96);
			this->dataGridViewProcess->TabIndex = 0;
			// 
			// groupGraphVector
			// 
			this->groupGraphVector->Controls->Add(this->chartVector);
			this->groupGraphVector->Font = (gcnew System::Drawing::Font(L"Calibri", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupGraphVector->Location = System::Drawing::Point(336, 10);
			this->groupGraphVector->Margin = System::Windows::Forms::Padding(2);
			this->groupGraphVector->Name = L"groupGraphVector";
			this->groupGraphVector->Padding = System::Windows::Forms::Padding(2);
			this->groupGraphVector->Size = System::Drawing::Size(567, 382);
			this->groupGraphVector->TabIndex = 10;
			this->groupGraphVector->TabStop = false;
			this->groupGraphVector->Text = L"STATISTICS";
			// 
			// chartVector
			// 
			chartArea1->Name = L"ChartAreaVector Encrypt";
			chartArea2->Name = L"ChartAreaVectorQuery";
			chartArea3->Name = L"ChartAreaDBEncrypt";
			chartArea4->AlignmentOrientation = static_cast<System::Windows::Forms::DataVisualization::Charting::AreaAlignmentOrientations>((System::Windows::Forms::DataVisualization::Charting::AreaAlignmentOrientations::Vertical | System::Windows::Forms::DataVisualization::Charting::AreaAlignmentOrientations::Horizontal));
			chartArea4->Name = L"ChartAreaDBQuery";
			this->chartVector->ChartAreas->Add(chartArea1);
			this->chartVector->ChartAreas->Add(chartArea2);
			this->chartVector->ChartAreas->Add(chartArea3);
			this->chartVector->ChartAreas->Add(chartArea4);
			legend1->Name = L"Legend1";
			this->chartVector->Legends->Add(legend1);
			this->chartVector->Location = System::Drawing::Point(0, 19);
			this->chartVector->Name = L"chartVector";
			series1->ChartArea = L"ChartAreaVector Encrypt";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->Legend = L"Legend1";
			series1->Name = L"Encr(Vector Size, Time:sec)";
			series2->ChartArea = L"ChartAreaVectorQuery";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series2->Legend = L"Legend1";
			series2->Name = L"Encr(DB Size, Time:sec)";
			series3->ChartArea = L"ChartAreaDBEncrypt";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series3->Legend = L"Legend1";
			series3->Name = L"Query(Vector Size, Time:sec)";
			series4->ChartArea = L"ChartAreaDBQuery";
			series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series4->Legend = L"Legend1";
			series4->Name = L"Query(DB Size, Time:sec)";
			this->chartVector->Series->Add(series1);
			this->chartVector->Series->Add(series2);
			this->chartVector->Series->Add(series3);
			this->chartVector->Series->Add(series4);
			this->chartVector->Size = System::Drawing::Size(560, 363);
			this->chartVector->TabIndex = 0;
			this->chartVector->Text = L"chart1";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLight;
			this->ClientSize = System::Drawing::Size(897, 424);
			this->Controls->Add(this->groupGraphVector);
			this->Controls->Add(this->groupNotify);
			this->Controls->Add(this->richText);
			this->Controls->Add(this->groupDBView);
			this->Controls->Add(this->groupProcessView);
			this->Controls->Add(this->groupQuery);
			this->Controls->Add(this->groupEncrypt);
			this->Controls->Add(this->groupStat);
			this->Font = (gcnew System::Drawing::Font(L"Calibri", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->Name = L"Form1";
			this->ShowIcon = false;
			this->Text = L"Light Weight Encryption Scheme";
			this->Load += gcnew System::EventHandler(this, &Form1::Form_Load);
			this->groupEncrypt->ResumeLayout(false);
			this->groupEncrypt->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericPos2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericPos1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericSize))->EndInit();
			this->groupQuery->ResumeLayout(false);
			this->groupQuery->PerformLayout();
			this->groupDBView->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridDBView))->EndInit();
			this->groupStat->ResumeLayout(false);
			this->groupStat->PerformLayout();
			this->groupNotify->ResumeLayout(false);
			this->groupNotify->PerformLayout();
			this->groupProcessView->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewProcess))->EndInit();
			this->groupGraphVector->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartVector))->EndInit();
			this->ResumeLayout(false);

		}

#pragma endregion
	private: System::Void Form_Load(System::Object^  sender, System::EventArgs^  e) {
				 srand(time(NULL));
				 groupGraphVector->Visible = false;
				 connectDatabase(0);
	}

	/*********************************************Encrypting a table******************************************************************************/

			 //Stores database name that has been selected to encrypt
	private: System::Void comboEncrypt_SelectedIndexChanged_1(System::Object^  sender, System::EventArgs^  e) {
				 tableToEncrypt = comboEncrypt->GetItemText(comboEncrypt->SelectedItem);
	}

			 //Ensures that the positions selected lie within the vector size
	private: System::Void numericSize_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
				 this->numericPos1->Maximum = System::Decimal::ToUInt32(this->numericSize->Value) - 1;
				 this->numericPos2->Maximum = this->numericPos1->Maximum;
	}

			 //Ensures that the value of the second position selected will always be greater than the first
	private: System::Void numericPos1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
				 this->numericPos2->Minimum = System::Decimal::ToUInt32(this->numericPos1->Value) + 1;
	}

	//Starts the encryption process after verifying the inputs
	private: System::Void buttonEncrypt_Click(System::Object^  sender, System::EventArgs^  e) {
					String^ str = "The Database to encrypt is " + tableToEncrypt + "\nVector length is " + numericSize->Value.ToString() + "\nPositions are " + numericPos1->Value.ToString() + " and " + numericPos2->Value.ToString();
					if (MessageBox::Show(str, "Confirm Selection", MessageBoxButtons::OKCancel, MessageBoxIcon::Information) == System::Windows::Forms::DialogResult::OK) {
						vectorLength = Int32(numericSize->Value);
						DeleteRecords();
						//arrays are indexed from 0. Therefore, 1 is subtracted from the actual value
						firstPos = Int32(numericPos1->Value) - 1;
						secondPos = Int32(numericPos2->Value) - 1;
						clock_t startEncrypt = clock();
						generateVectorU();
						generateMatrix();
						plainResults(startEncrypt);
						StoreKeyinFile();						
					}
	}

	//Connects to the database
	void connectDatabase(int mode){
		myConnection = gcnew OdbcConnection("Dsn=ODBCFORDB2;uid=db2admin;dbalias=SAMPLE;pwd=db2admin");
		switch (mode){
			//Loads 'Database' comboboxes by retrieving list of tables in specified database
		case 0:{
				//Selects tables belonging to the corresponding database. All these tables are unencrypted.
				array<String^>^ restrictions = gcnew array<String^>(3);
				restrictions[1] = "DBLIGHTCRYPT";
				myConnection->Open();
				comboEncrypt->DataSource = myConnection->GetSchema("Tables", restrictions);
				comboEncrypt->DisplayMember = "TABLE_NAME";
				restrictions[1] = "DBENCRYPTED";
				comboQuery->DataSource = myConnection->GetSchema("Tables", restrictions);
				comboQuery->DisplayMember = "TABLE_NAME";
				myConnection->Close();
		}
			//Loads 'select attribute' combobox by retrieving list of columns in selected table
		case 1:{
				array<String^>^ restrictions = gcnew array<String^>(4);
				//Selects tables belonging to the corresponding database. All these tables are unencrypted.
				restrictions[1] = "DBENCRYPTED";
				restrictions[2] = encrptedTable;
				myConnection->Open();
				comboAttributes->DataSource = myConnection->GetSchema("Columns", restrictions);
				comboAttributes->DisplayMember = "COLUMN_NAME";
				myConnection->Close();
		}
		}
	}

	// generates the Unit Vector
	void generateVectorU() {
		//Resizing the unit Vector
		U.resize(vectorLength - 2);
		for (int count = 0; count < U.size(); count++) U[count] = getValue(0);
	}

	//generates a matrix that has an inverse
	void generateMatrix() {
		//Resizing all matrices
		I.resize(vectorLength, vectorLength), Minv.resize(vectorLength, vectorLength), Mt.resize(vectorLength, vectorLength), M.resize(vectorLength, vectorLength);
		int i, j;
		I.diag() = 1;
		int count = 0;
		while (count == 0){
			for (i = 0; i<vectorLength; i++){
				for (j = 0; j<vectorLength; j++){
					if(i==j) M[i][j] = getValue(0);
					else M[i][j] = getValue(1);
					Mt[j][i] = M[i][j];
				}
			}
			//if M multiplied by its inverse equals identity matrix, matrix has an inverse
			if (M*!M == I){
				Minv = !M;
				count = 1;
			}
		}
	}

	//Create File
	void StoreKeyinFile(){
		String^ fileName = "C:\\XML File\\" + tableToEncrypt+ ".xml";
		StreamWriter^ sw = gcnew StreamWriter(fileName);
		sw->WriteLine("Vector Length: ");
		sw->WriteLine(vectorLength);
		sw->WriteLine("Position for v: ");
		sw->WriteLine(firstPos);
		sw->WriteLine("Position for b: ");
		sw->WriteLine(secondPos);
		sw->Write("Unit Vector U: " + gcnew String(doubleToString(U[0]).c_str()));
		for (int i = 1; i < vectorLength - 2; i++) sw->Write(", " + gcnew String(doubleToString(U[i]).c_str()));
		sw->WriteLine();
		sw->WriteLine("Matrix M:");
		for (int i = 0; i < vectorLength; i++){
			sw->Write(gcnew String(doubleToString(M[i][0]).c_str()));
			for (int j = 1; j < vectorLength; j++) sw->Write(", " + gcnew String(doubleToString(M[i][j]).c_str())); 
			sw->WriteLine();
		}
		sw->WriteLine("Matrix Minv:");
		for (int i = 0; i < vectorLength; i++){
			sw->Write(gcnew String(doubleToString(Minv[i][0]).c_str()));
			for (int j = 1; j < vectorLength; j++) sw->Write(", " + gcnew String(doubleToString(Minv[i][j]).c_str()));
			sw->WriteLine();
		}
		sw->WriteLine("Matrix MTranspose:");
		for (int i = 0; i < vectorLength; i++){
			sw->Write(gcnew String(doubleToString(Mt[i][0]).c_str()));
			for (int j = 1; j < vectorLength; j++) sw->Write(", " + gcnew String(doubleToString(Mt[i][j]).c_str()));
			sw->WriteLine();
		}
		sw->Close();
	}

	//retrieve results from unencrypted table
	void plainResults(clock_t startEncrypt){
		myConnection = gcnew OdbcConnection("Dsn=ODBCFORDB2;uid=db2admin;dbalias=SAMPLE;pwd=db2admin");
		//number of rows and numeric columns in the database
		int columns, rows = 0;
		//counter for rows and columns
		int	colCount, rowCount = 0;
		//identifies integer columns in matrix records(rows,columns)
		int *integerCols;
		//stores database records
		string **records;
		String^ mySelectQuery = "SELECT COUNT(*) FROM DBLIGHTCRYPT." + tableToEncrypt + ";SELECT * FROM DBLIGHTCRYPT." + tableToEncrypt;
		myConnection->Open();
		OdbcCommand^ myCommand = gcnew OdbcCommand(mySelectQuery, myConnection);
		OdbcDataReader^ myReader = myCommand->ExecuteReader();
		myReader->Read();
		rows = myReader->GetDouble(0);
		//Advances to the next query
		myReader->NextResult();
		columns = myReader->FieldCount;
		records = new string*[rows];
		integerCols = new int[columns];
		dataGridDBView->ColumnCount = columns;
		while (myReader->Read()) {
			records[rowCount] = new string[columns];
			for (colCount = 0; colCount <columns; colCount++){
				if (myReader->GetDataTypeName(colCount) == gcnew String("BIGINT")) integerCols[colCount] = 1;
				dataGridDBView->Columns[colCount]->HeaderText = myReader->GetName(colCount);
				MarshalString(myReader->GetString(colCount), fromString);
				records[rowCount][colCount] = fromString;
			}
			rowCount++;
		}
		myReader->Close();
		myConnection->Close();		
		generateVectorV(records, rows, columns, integerCols, startEncrypt);
	}

	//deletes records from encrypted table
	void DeleteRecords(){
		String ^ deleteStmt = "TRUNCATE TABLE DBENCRYPTED." + tableToEncrypt + " IMMEDIATE";
		myConnection = gcnew OdbcConnection("Dsn=ODBCFORDB2;uid=db2admin;dbalias=SAMPLE;pwd=db2admin");
		myConnection->Open();
		OdbcTransaction^ myTrans = myConnection->BeginTransaction();
		OdbcCommand^ myCommand = gcnew OdbcCommand(deleteStmt, myConnection, myTrans);
		myTrans->Commit();
		myCommand->ExecuteNonQuery();
	}

	//Encrypts each numeric value from the selected database and stores into another database in this encrypted form
	void generateVectorV(string **records, int rows, int columns, int *integerCols, clock_t startEncrypt){
		//counts the number of columns to be encrypted		
		int encryptColCount=0;
		myConnection = gcnew OdbcConnection("Dsn=ODBCFORDB2;uid=db2admin;dbalias=SAMPLE;pwd=db2admin");
		myConnection->Open();
		//Resizing Vector V, Encrypted Vector V
		V.resize(vectorLength);
		Ev.resize(vectorLength);
		string insertStmt="";
		Vector Vscale;
		array<String^>^  vgridValue = gcnew array<String^>(6);		
		bool show = false;
		clock_t showTime;
		MarshalString(tableToEncrypt, fromString);
		System::Text::StringBuilder^ sb = gcnew System::Text::StringBuilder("");
		for (int rowCount = 0; rowCount < rows; rowCount++){			
			insertStmt = "INSERT INTO DBENCRYPTED." + fromString + " VALUES(";
			for (int colCount = 0; colCount < columns; colCount++){
				if (integerCols[colCount] == 1){
					if (rowCount == rows - 1) encryptColCount++;					
					/****************** start of E1(v)***********************/
					double value = getValue(0);
					V[firstPos] = atof(records[rowCount][colCount].c_str());
					V[secondPos] = -1;
					//generates Vector V collinear to the unit vector and multiplies it by a scalar quantity
					for (int count = 0; count < V.size(); count++){
						if (count<firstPos) V[count] = U[count] * value;
						if (count>firstPos && count<secondPos) V[count] = U[count - 1] * value;
						if (count>secondPos) V[count] = U[count - 2] * value;
					}
					//multiply by a scalar quantity
					int x = abs(tan(stoi(records[rowCount][colCount])));
					double scalar = x % 100;
					if (scalar == 0||scalar==1) scalar = 2;
					Vscale = V * scalar;
					//encrypts vector V
					Ev = Minv * Vscale;
					/****************** end of E1(v)***********************/
					if (show == false) {
					clock_t startShow = clock();
					vgridValue = gcnew array<String^>{ gcnew String((records[rowCount][colCount]).c_str()),
							gcnew String((vectorToString(V, vectorLength, 0)).c_str()),
							gcnew String((vectorToString(Vscale, vectorLength, 0)).c_str()),
							gcnew String((vectorToString(Ev, vectorLength, 0)).c_str()), "","" };
						    show = true;
							clock_t endShow = clock();
							showTime = endShow - startShow;
					}
					records[rowCount][colCount] = vectorToString(Ev, vectorLength);		
				}
				if (colCount == columns - 1) insertStmt = insertStmt + "'" + records[rowCount][colCount] + "'";
				else insertStmt = insertStmt + "'" + records[rowCount][colCount] + "'" + ", ";
			}
			insertStmt = insertStmt + ");";
			sb->Append(gcnew String(insertStmt.c_str()));
		}
		try{
			OdbcTransaction^ myTrans = myConnection->BeginTransaction();
			OdbcCommand^ myCommand = gcnew OdbcCommand(sb->ToString(), myConnection, myTrans);
			myTrans->Commit();
			myCommand->ExecuteNonQuery();
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     		}
		catch (Exception^ e){
			MessageBox::Show("Invalid Query Entered", "Invalid Entry", MessageBoxButtons::OK, MessageBoxIcon::Information);
			return;
		}
		clock_t EndEncrypt = clock();
		clock_t EncryptTime = ((EndEncrypt - startEncrypt) - showTime) / CLOCKS_PER_SEC;
		labelNotify->Text = "DATABASE ENCRYPTION COMPLETE.\nKEY IN: C:\\XML FILE\\" + tableToEncrypt + ".xml";
		labelTime->Text = "DATABASE SIZE: " + rows + " Records, " + encryptColCount + " Encrypted Columns\nTIME TAKEN: "+ gcnew String((doubleToString(EncryptTime,0)).c_str()) + " seconds";
		showEncryptDBProcess(vgridValue);
		ShowEncryptedDatabase(records, rows, columns);
		System::Windows::Forms::DataVisualization::Charting::DataPoint^  dp1 = (gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint());
		dp1->SetValueXY(vectorLength, EncryptTime);
		chartVector->Series[gcnew String("Encr(Vector Size, Time:sec)")]->Points->Add(dp1);
		System::Windows::Forms::DataVisualization::Charting::DataPoint^  dp2 = (gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint());
		array<String^>^ strSize = { "S", "2S", "4S", "8S", "16S" };
		dp2->SetValueXY(strSize[doubleDBCount], EncryptTime);
		chartVector->Series[gcnew String("Encr(DB Size, Time:sec)")]->Points->Add(dp2);
		cleanMemory(records, rows);
	}
	
	/*********************************************End of Encrypting a table******************************************************************************/
	/***************************************Retrieving Results from Encrypted Table******************************************************/

	private: System::Void comboQuery_SelectedIndexChanged_1(System::Object^  sender, System::EventArgs^  e) {
				 encrptedTable = comboQuery->GetItemText(comboQuery->SelectedItem);
				 connectDatabase(1);
	}

	private: System::Void comboAttributes_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
				 queryAttribute = comboAttributes->GetItemText(comboAttributes->SelectedItem);
	}

	private: System::Void comboRange_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
				 rangeOperator = comboRange->GetItemText(comboRange->SelectedItem);
	}

	private: System::Void buttonRunQuery_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (rangeOperator->Equals("") == true) {
					 MessageBox::Show("Select an Operator", "Invalid Entry", MessageBoxButtons::OK, MessageBoxIcon::Information);
					 return;
				 }
				 MarshalString(textQueryValue->Text, fromString);
				 if (fromString.find_first_not_of("0123456789-+.e_") != std::string::npos) {
					 MessageBox::Show("Enter a Valid Value", "Invalid Entry", MessageBoxButtons::OK, MessageBoxIcon::Information);
					 return;
				 }
				 queryString = "SELECT * FROM DBENCRYPTED." + encrptedTable + " WHERE " + queryAttribute + rangeOperator + textQueryValue->Text;
				 if (MessageBox::Show(queryString, "Confirm Entry", MessageBoxButtons::OKCancel, MessageBoxIcon::Information) == System::Windows::Forms::DialogResult::OK) {
					 richText->Text = queryString;
					 MarshalString(textQueryValue->Text, fromString);
					 generateVectorB(atof(fromString.c_str()));
				 }
	}			 
			 
	/************* start of E2(b)***************************/
	void generateVectorB(double queryValue){
		clock_t retrieveStart = clock();
		//Resizing Vector B, Encrypted Vector B
		B.resize(vectorLength);
		Eb.resize(vectorLength);
		int lastValue;
		int count;
		double totalValue = 0.0;
		B[firstPos] = 1;
		B[secondPos] = queryValue;
		array <String^>^ bgridValue = gcnew array<String^>(6);
		//generates Vector B orthogonal to U
		for (count = 0; count<B.size(); count++){
			if (count<firstPos) {
				B[count] = getValue(0);
				totalValue = totalValue + (U[count] * B[count]);
				lastValue = count;
			}
			if (count>firstPos && count<secondPos){
				B[count] = getValue(0);
				totalValue = totalValue + (U[count - 1] * B[count]); 
				lastValue = count; 
			}
			if (count>secondPos) {
				B[count] = getValue(0);
				totalValue = totalValue + (U[count - 2] * B[count]);
				lastValue = count;
			}
		}
		totalValue = totalValue - (U[vectorLength - 3] * B[lastValue]);
		B[lastValue] = (totalValue / U[vectorLength - 3]) * -1;
		//Encrypts vector B
		Eb = Mt * B;
		//populate grid
		clock_t showStart = clock();
		bgridValue[0] = queryValue.ToString();
		bgridValue[1] = gcnew String((vectorToString(B,vectorLength,0)).c_str());
		bgridValue[2] = gcnew String((vectorToString(Eb, vectorLength, 0)).c_str());
		clock_t showEnd = clock();
		clock_t showTime = showEnd - showStart;
		encryptedResults(bgridValue, retrieveStart,showTime);		
	}
	/************* end of E2(b)***************************/

	/*************E1(b)***************************/
	void generateVectorB1(string **records, int rows, int columns, int *integerCols){
		//Resizing Vector B1, Encrypted Vector B1
		B1.resize(vectorLength), EB1.resize(vectorLength);
		for (int rowCount = 0; rowCount < rows; rowCount++){
			for (int colCount = 0; colCount < columns; colCount++){
				if (integerCols[colCount] == 1){
					/****************** start of E1(b)***********************/
					double value = getValue(0);
					B1[firstPos] = atof(records[rowCount][colCount].c_str());
					B1[secondPos] = -1;
					//generates Vector B1 collinear to the unit vector and multiplies it by a scalar quantity
					for (int count = 0; count < B1.size(); count++){
						if (count<firstPos) B1[count] = U[count] * value;
						if (count>firstPos && count<secondPos) B1[count] = U[count - 1] * value;
						if (count>secondPos) B1[count] = U[count - 2] * value;
					}
					//multiply by a scalar quantity
					int x = abs(tan(stoi(records[rowCount][colCount])));
					double scalar = x % 100;
					if (scalar == 0||scalar ==1) scalar = 2;
					B1 = B1 * scalar;
					//encrypts vector B1
					EB1 = Minv * B1;
					/****************** E1(b)***********************/
					records[rowCount][colCount] = vectorToString(EB1, vectorLength);
				}
			}
			rowCount++;
		}
	}
	/************* end of E1(b)***************************/

	//retrieve encrypted results
	void encryptedResults(array<String^>^ bgridvalue, clock_t retrieveStart, clock_t showTime){
		bool show = false;
		myConnection = gcnew OdbcConnection("Dsn=ODBCFORDB2;uid=db2admin;dbalias=SAMPLE;pwd=db2admin");
		//number of rows and numeric columns in the database
		int ecolumns, erows = 0;
		//counter for rows and columns
		int colCount, rowCount = 0;
		//identifies integer columns in matrix records(rows,columns)
		int *integerCols;
		//stores encrypted database records
		string **encrRecords;
		//database size
		int size;
		//int decryptColCount=0;
		myConnection->Open();
		string Ebx = doubleToString(Eb[0]);
		String^ Ebstring = gcnew String(Ebx.c_str());
		String^ mySelectQuery = "SELECT count(*) FROM DBENCRYPTED." + encrptedTable + ";SELECT * FROM DBENCRYPTED." + encrptedTable + " where ";
		mySelectQuery = mySelectQuery + "(" + Ebstring + " * (substr(" + queryAttribute + ", 1, (LOCATE_IN_STRING(" + queryAttribute + ", '_', 1, 1)) - 1)))";
		for (int i = 1; i < vectorLength; i++){
			int j = i + 1;
			string Ebx = doubleToString(Eb[i]);
			String^ Ebstring = gcnew String(Ebx.c_str());
			mySelectQuery = mySelectQuery +
				"+ (" + Ebstring + " * ((substr(" + queryAttribute + ", (LOCATE_IN_STRING(" + queryAttribute + ", '_', 1," + i + ")) + 1, (LOCATE_IN_STRING(" + queryAttribute + ", '_', 1, " + j + ")) - ((LOCATE_IN_STRING(" + queryAttribute + ", '_', 1," + i + ")) + 1)))))";
		}
		mySelectQuery = mySelectQuery + rangeOperator + 0;
		MarshalString(mySelectQuery, fromString);
		try{
			OdbcCommand^ myCommand = gcnew OdbcCommand(mySelectQuery, myConnection);
			OdbcDataReader^ myReader = myCommand->ExecuteReader();
			myReader->Read();
			erows = myReader->GetDouble(0);
			size = erows;
			myReader->NextResult();
			ecolumns = myReader->FieldCount;
			encrRecords = new string*[erows];
			integerCols = new int[ecolumns];
			dataGridDBView->ColumnCount = ecolumns;
			while (myReader->Read()) {
				encrRecords[rowCount] = new string[ecolumns];
				for (colCount = 0; colCount <ecolumns; colCount++){
					MarshalString(myReader->GetString(colCount), fromString);
					//set integerCols[colCount] to 1 if the value is a string
					if (fromString.find_first_not_of("0123456789-+.e_") != std::string::npos) {
						integerCols[colCount] = 1; 
						//decryptColCount++;
					}
					dataGridDBView->Columns[colCount]->HeaderText = myReader->GetName(colCount);
					encrRecords[rowCount][colCount] = fromString;
					if (show == false && integerCols[colCount]!=1){
						clock_t showStart = clock();
						show = true;
						Vector EbEv= Eb * stringtoVector(encrRecords[rowCount][colCount]);
						bgridvalue[3] = gcnew String((doubleToString(EbEv[0])).c_str());
						clock_t showEnd = clock();
						showTime = showTime + (showEnd - showStart);
					}
				}
				rowCount++;
			}
			erows = rowCount;
			myReader->Close();
		}
		catch (Exception^ e){
			MessageBox::Show("Invalid Query Entered", "Invalid Entry", MessageBoxButtons::OK, MessageBoxIcon::Information);
			return;
		}
		myConnection->Close();	
		//Querying: Time to Retrieve Records
		/*clock_t retrieveEnd = clock();
		clock_t retrieveTime = ((retrieveEnd - retrieveStart) - showTime) / CLOCKS_PER_SEC;
		labelTime->Text = "DATABASE SIZE: " + size + " Records " + ecolumns - decryptColCount + " Decrypted Columns\nTIME TAKEN : " + gcnew String((doubleToString(retrieveTime, 0)).c_str()) + " seconds";
		System::Windows::Forms::DataVisualization::Charting::DataPoint^  dp2 = (gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint());
		array<String^>^ strSize = { "S", "2S", "4S", "8S", "16S" };
		dp2->SetValueXY(strSize[doubleDBCount], retrieveTime);
		chartVector->Series[gcnew String("Query(DB Size, Time:sec)")]->Points->Add(dp2);*/
		decryptV(encrRecords, erows, ecolumns, integerCols, retrieveStart, showTime, bgridvalue, size);
	}

	//Decrypts Values returned from the database
	void decryptV(string **encrRecords, int erows, int ecolumns, int *integerCols, clock_t retrieveStart, clock_t showTime, array <String^>^ bgridvalue, int size){
		//stores the number of columns to be decrypted
		int decryptColCount=0;
    	bool show = false;
		for (int rowCount = 0; rowCount < erows; rowCount++){
			for (int colCount = 0; colCount < ecolumns; colCount++){
				if (integerCols[colCount] != 1){
					if(rowCount==erows-1) decryptColCount++;
					Ev = M * stringtoVector(encrRecords[rowCount][colCount]); 
					double result = convertDouble((Ev[firstPos] / Ev[secondPos]) *-1);
					encrRecords[rowCount][colCount] = doubleToString(result);
					if (show == false ){
						clock_t showStart = clock();
						bgridvalue[4] = gcnew String((vectorToString(Ev, vectorLength, 0)).c_str());
						bgridvalue[5] = gcnew String((encrRecords[rowCount][colCount]).c_str());						
						show = true;
						clock_t showEnd = clock();
						showTime = showTime + (showEnd - showStart);
					}
				}
			}
		}		
		clock_t retrieveEnd = clock();
		clock_t retrieveTime = ((retrieveEnd - retrieveStart) - showTime) / CLOCKS_PER_SEC;
		storeResultsinFile(encrRecords, erows,ecolumns);		
		labelTime->Text = "DATABASE SIZE: " + size + " Records " + decryptColCount + " Decrypted Columns\nTIME TAKEN : " + gcnew String((doubleToString(retrieveTime,0)).c_str()) + " seconds";
		showQueryDBProcess(bgridvalue);
		ShowDecryptedResults(encrRecords, erows, ecolumns);
		System::Windows::Forms::DataVisualization::Charting::DataPoint^  dp1 = (gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint());
		dp1->SetValueXY(vectorLength, retrieveTime);
		chartVector->Series[gcnew String("Query(Vector Size, Time:sec)")]->Points->Add(dp1);
		//Querying: Time to Retrieve and Decrypt Records
		System::Windows::Forms::DataVisualization::Charting::DataPoint^  dp2 = (gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint());
		array<String^>^ strSize = { "S", "2S", "4S", "8S", "16S" };
		dp2->SetValueXY(strSize[doubleDBCount], retrieveTime);
		chartVector->Series[gcnew String("Query(DB Size, Time:sec)")]->Points->Add(dp2);
		cleanMemory(encrRecords, erows);
	}

	//Stores decrypted plaintext results in file
	void storeResultsinFile(string **encrRecords, int erows, int ecolumns){
		String^ fileName = "C:\\XML File\\QueryResults.xml";
		StreamWriter^ sw = gcnew StreamWriter(fileName);
		sw->WriteLine(richText->Text);
		for (int i = 0; i < erows; i++){
			sw->Write(gcnew String((encrRecords[i][0]).c_str()));
			for (int j = 1; j < ecolumns; j++) sw->Write(", " + gcnew String((encrRecords[i][j]).c_str()));
			sw->WriteLine();
		}
		sw->Close();
		labelNotify->Text = "QUERY RESULTS:" + fileName;
	}

	/***************************************End of Retrieving Results from Encrypted Table******************************************************/

	/***************************************Display on Interface******************************************************/

	void showEncryptDBProcess(array<String^>^ gridValue){
		dataGridViewProcess->ColumnCount = 2;
		dataGridViewProcess->RowCount = 4;
		groupProcessView->Text = groupProcessView->Text + "->Encrypt Data";
		array<String^>^  gridLabels = { "v:", "nv:", "scale V:", "E(v):Minv*scale V" };
		for (int i = 0; i < 4; i++) {
			dataGridViewProcess->Rows[i]->Cells[0]->Value = gridLabels[i];
			dataGridViewProcess->Rows[i]->Cells[1]->Value = gridValue[i];
		}
	}

	void showQueryDBProcess(array<String^>^ gridValue){	
		dataGridViewProcess->ColumnCount = 4;
		dataGridViewProcess->RowCount = 4;
		groupProcessView->Text = groupProcessView->Text + "->Query Database";
		array<String^>^  gridLabels = { "b:", "nb:", "E(b):Minv*scale V", "E(b).E(v)", "scale V: [M * E(v)]", "v:[firstPos/secondPos]*-1" };
		for (int i = 0; i < 4; i++) {
			dataGridViewProcess->Rows[i]->Cells[0]->Value = gridLabels[i];
			dataGridViewProcess->Rows[i]->Cells[1]->Value = gridValue[i];
		}
		dataGridViewProcess->Rows[0]->Cells[2]->Value = gridLabels[4];
		dataGridViewProcess->Rows[1]->Cells[2]->Value = gridLabels[5];
		dataGridViewProcess->Rows[0]->Cells[3]->Value = gridValue[4];
		dataGridViewProcess->Rows[1]->Cells[3]->Value = gridValue[5];
	}

	void ShowEncryptedDatabase(string **records, int rows, int columns){
		groupDBView->Text = "DATABASE VIEW->Encrypted Database";
		dataGridDBView->RowCount = rows;
		for (int rowCount = 0; rowCount < rows; rowCount++){
			for (int colCount = 0; colCount < columns; colCount++){
				if (rowCount > 10) break;
				dataGridDBView->Rows[rowCount]->Cells[colCount]->Value = gcnew String((records[rowCount][colCount]).c_str());
			}
		}
	}

	void ShowDecryptedResults(string **encrRecords, int rows, int columns){
		if (rows == 0) MessageBox::Show("No records match the selected query, Zero results returned", "", MessageBoxButtons::OK, MessageBoxIcon::Information);
		else{
			groupDBView->Text = "DATABASE VIEW->Query Results";
			dataGridDBView->RowCount = rows;
			for (int rowCount = 0; rowCount < rows; rowCount++){
				for (int colCount = 0; colCount < columns; colCount++){
					dataGridDBView->Rows[rowCount]->Cells[colCount]->Value = gcnew String((encrRecords[rowCount][colCount]).c_str());
				}
			}
		}
	}

	/***************************************End of Display on Interface******************************************************/

	/***************************************SubFunctions***************************************************************************************/

	//generates random numbers in the range 0.2 to 5
	double getValue(int mode){
		double value;
		if (mode == 0){
			value = 0.2 + 4.8*(rand() % 1000) / (double)1000;
			return value;
		}
		if (mode == 1){
			value = 2 - 4 * (rand() % 1000) / (double)1000;
			return value;
		}
	}
	
	//Converts from System::String^ to std::string
	void MarshalString(String ^ s, string& os) {
		using namespace Runtime::InteropServices;
		const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}

	//concatenates vector values and returns a string
	string vectorToString(Vector v, int size)
	{
		string vectorString = "";
		for (int i = 0; i<size; i++) {
			vectorString += doubleToString(v[i]);
			vectorString += "_";
		}
		return vectorString;
	}

	//concatenates vector values and returns a string. Used for displaying the vector in a grid
	string vectorToString(Vector v, int size, int mode)
	{
		string vectorString = "";
		for (int i = 0; i<size; i++) {
			vectorString += doubleToString(v[i]);
			vectorString += " ";
		}
		return vectorString;
	}

	Vector stringtoVector(string strInput){
		double vect[20];
		stringstream ss(strInput);
		double i;
		int k = 0;
		while (ss >> i)
		{
			vect[k] = i;
			k++;
			if (ss.peek() == '_')
				ss.ignore();
		}
		Vector v1(vect, k);
		return v1;
	}

	//round the value of double
	double convertDouble(double i){
		if (i == -0.00000) return 0.00000;
		if (i < 0) return  (floor(i * 10 + 0.5) / 10) * -1;
		if (i > 0) return  (floor(i * 10 + 0.5) / 10);
	}

	//retuns a double as string
	string doubleToString(double val) {
		std::ostringstream out;
		out.setf(ios::fixed);
		out.precision(8);
		out << val;
		return out.str();
	}

	//Return a double as string, with precision =2, is used to display the time
	string doubleToString(double val, int mode)
	{
		std::ostringstream out;
		out.setf(ios::fixed);
		out.precision(2);
		out << val;
		return out.str();
	}

	//Cleans up the memory allocated for the array
	void cleanMemory(string **records, int rows)
	{
		for (int i = 0; i < rows; i++)
			delete[] records[i];
		delete[] records;
	}

	/***************************************End of SubFunctions***************************************************************************************/

private: System::Void buttonGraph_Click(System::Object^  sender, System::EventArgs^  e) {
			 //graph invisible. So now display graph
			 if (graph == false){
				 groupDBView->Visible = false;
				 groupProcessView->Visible = false;
				 groupStat->Visible = false;
				 groupGraphVector->Visible = true;
				 graph = true;
			 }
			 //graph already visible. So now hide graph
			 else{
				 groupDBView->Visible = true;
				 groupProcessView->Visible = true;
				 groupStat->Visible = true;
				 groupGraphVector->Visible = false;
				 graph = false;
			 }
}
		 //increases database size
		 private: System::Void buttonDoubleDB_Click(System::Object^  sender, System::EventArgs^  e) {
					if (doubleDBCount > 4){
						MessageBox::Show("Max Size Reached", "Invalid Operation", MessageBoxButtons::OK, MessageBoxIcon::Error);
						return;
					  }
					String^ findColumns = "SELECT COLNAME FROM SYSCAT.COLUMNS WHERE TABSCHEMA = 'DBLIGHTCRYPT' AND TABNAME = '" + tableToEncrypt + "' AND KEYSEQ = 1;SELECT COLNAME,TYPENAME FROM SYSCAT.COLUMNS WHERE TABSCHEMA = 'DBLIGHTCRYPT' AND TABNAME = '" + tableToEncrypt + "' AND KEYSEQ IS NULL";
					myConnection = gcnew OdbcConnection("Dsn=ODBCFORDB2;uid=db2admin;dbalias=SAMPLE;pwd=db2admin");
					myConnection->Open();
					OdbcCommand^ myCommand = gcnew OdbcCommand(findColumns, myConnection);
					OdbcDataReader^ myReader = myCommand->ExecuteReader();
					myReader->Read();
					String^ keyColumn = myReader->GetString(0);
					//Advances to the next query
					myReader->NextResult();
					String^ doubleinsertStmt1 = "INSERT INTO DBLIGHTCRYPT." + tableToEncrypt + " (" + keyColumn;
					String^ doubleinsertStmt2 = " SELECT " + keyColumn + " + (SELECT max(" + keyColumn + ") FROM DBLIGHTCRYPT." + tableToEncrypt + ")";
						while (myReader->Read()) {
						doubleinsertStmt1 = doubleinsertStmt1 + "," + myReader->GetString(0); 

						//for growing result size
						if (myReader->GetString(1) == gcnew String("BIGINT")) doubleinsertStmt2 = doubleinsertStmt2 + ", (SELECT min("
							+ myReader->GetString(0) + ") FROM DBLIGHTCRYPT." + tableToEncrypt + 
							") + ((SELECT max(" + myReader->GetString(0) + ") FROM DBLIGHTCRYPT." + tableToEncrypt +
							") - (SELECT min(" + myReader->GetString(0) + ") FROM DBLIGHTCRYPT." + tableToEncrypt + ")) * rand()";
						
						//for constant result size
						/*if (myReader->GetString(1) == gcnew String("BIGINT"))
						          doubleinsertStmt2 = doubleinsertStmt2 + "," + myReader->GetString(0) + "*2";
						
						else doubleinsertStmt2 = doubleinsertStmt2 + "," + myReader->GetString(0);*/
					}
					doubleinsertStmt1 = doubleinsertStmt1 + ")" + doubleinsertStmt2 + " FROM DBLIGHTCRYPT." + tableToEncrypt;
					myReader->Close();
					OdbcTransaction^ myTrans = myConnection->BeginTransaction();
					myCommand = gcnew OdbcCommand(doubleinsertStmt1, myConnection, myTrans);
					myTrans->Commit();
					myCommand->ExecuteNonQuery();
					myConnection->Close();
					doubleDBCount++;						
}
};

}


