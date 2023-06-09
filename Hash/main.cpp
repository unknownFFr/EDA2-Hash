#include <fstream>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

#include "./hashing/Hash.h"
#include "./hashing/encadeamento-explicito-dinamico.h"
#include "./hashing/encadeamento-explicito.h"
#include "./hashing/enderecamento-aberto-duplo-hashing.h"
#include "./hashing/enderecamento-aberto-sondagem-linear.h"
#include "./hashing/linear.h"
#include "./testes/funcoes-de-teste.h"

void Conjuntos(int, int, string, int);
void ArquivoInteiro(int, int);
void ArquivoProfessor(string);



int main()
{
  long double alfa = 2;
  
  string TestFileName;
  int HashSize, SetAmount;
  ofstream Resultados;

  

  cout << "1 - Testes no formato do grupo | 2 - Testes no formato do professor" << endl;
  int a;
  string b;
  getline(cin,b);
  a = stoi(b);

  if (a == 1)
  {
    TestFileName = "testes/testes-finais/testes-finais-0.txt";
    HashSize = 997;
    SetAmount = 100;
    cout << "1 - Por conjunto | 2 - Arquivo inteiro" << endl;
    int Caso;
    cin >> Caso;
    switch (Caso)
    {
    case 1:
      Resultados.open("Saida-explicito-estatico.csv");
      Resultados << "\"Conjunto\",\"Alfa\",\"Acesso-Medio\"" << endl;
      Resultados.close();

      Resultados.open("Saida-explicito-dinamico.csv");
      Resultados << "\"Conjunto\",\"Alfa\",\"Acesso-Medio\"" << endl;
      Resultados.close();

      Resultados.open("Saida-Duplo-hashing.csv");
      Resultados << "\"Conjunto\",\"Alfa\",\"Acesso-Medio\"" << endl;
      Resultados.close();

      Resultados.open("Saida-Sondagem-linear.csv");
      Resultados << "\"Conjunto\",\"Alfa\",\"Acesso-Medio\"" << endl;
      Resultados.close();

      for (int i = 0; i < SetAmount; i++)
      {
        for (int j = 1; j < 50; j++)
        {
          Conjuntos(alfa*j, i, TestFileName, HashSize);
        }
      }

      break;
    
    case 2:

      Resultados.open("Saida-explicito-estatico-total.csv");
      Resultados << "\"Alfa\",\"Acesso-Medio\"" << endl;
      Resultados.close();

      Resultados.open("Saida-explicito-dinamico-total.csv");
      Resultados << "\"Alfa\",\"Acesso-Medio\"" << endl;
      Resultados.close();

      Resultados.open("Saida-Duplo-hashing-total.csv");
      Resultados << "\"Alfa\",\"Acesso-Medio\"" << endl;
      Resultados.close();

      Resultados.open("Saida-Sondagem-linear-total.csv");
      Resultados << "\"Alfa\",\"Acesso-Medio\"" << endl;
      Resultados.close();

      for (int j = 1; j < 50; j++)
      {
        ArquivoInteiro(alfa*j, SetAmount);
      }
      break;

    default:
      break;
    }
  }
  else
  {
    cout << "Nome do arquivo de teste:  ";
    getline(cin,TestFileName);
    ArquivoProfessor(TestFileName);
  }


  //TestaCasosDaAula(4);

  return 0;
}

void Conjuntos(int Alfa, int SetNumber, string TestFileName, int HashSize)
{
  long double *vetor;
  ofstream Resultados;

  vetor = MediaDeAcessosConjunto(Alfa, SetNumber, TestFileName, HashSize);

  cout << fixed << setprecision(5);
  cout << "=-=-=-=-=-=-=-=alfa-" << Alfa << "=-=-=-=-=-=-=-=" << endl;

  cout << "Media de acessos dos metodos para o conjunto " << SetNumber + 1 << endl;

  cout << "Encadeamento explicito dinamico: " << setw(7) << vetor[0] << endl;
  Resultados.open("Saida-explicito-dinamico.csv", ios_base::app);
  Resultados << SetNumber << "," << Alfa << "," << vetor[0] << endl;
  Resultados.close();

  cout << "Encadeamento explicito estatico: " << setw(7) << vetor[1] << endl;
  Resultados.open("Saida-explicito-estatico.csv", ios_base::app);
  Resultados << SetNumber << "," << Alfa << "," << vetor[1] << endl;
  Resultados.close();

  cout << left << setw(31) << "Duplo hashing" << ": " << right << setw(7) << vetor[2] << endl;
  Resultados.open("Saida-Duplo-hashing.csv", ios_base::app);
  Resultados << SetNumber << "," << Alfa << "," << vetor[2] << endl;
  Resultados.close();

  cout << left << setw(31) << "Sondagem linear" << ": " << right << setw(7) << vetor[3] << endl;
  Resultados.open("Saida-Sondagem-linear.csv", ios_base::app);
  Resultados << SetNumber << "," << Alfa << "," << vetor[3] << endl;
  Resultados.close();

  cout << endl;
}

void ArquivoInteiro(int Alfa, int SetAmount)
{
  long double *vetor;
  ofstream Resultados;



  vetor = MediaDeAcessosArquivo(Alfa, SetAmount);
  cout << fixed << setprecision(2);
  cout << "=-=-=-=-=-=-=-=alfa-" << Alfa << "=-=-=-=-=-=-=-=" << endl;
  cout << "=-=-=-Media de acessos dos metodos=-=-=-" << endl;

  cout << "Encadeamento explicito dinamico: " << setw(7) << vetor[0] << endl;
  Resultados.open("Saida-explicito-dinamico-total.csv", ios_base::app);
  Resultados << Alfa << "," << vetor[0] << endl;
  Resultados.close();

  cout << "Encadeamento explicito estatico: " << setw(7) << vetor[1] << endl;
  Resultados.open("Saida-explicito-estatico-total.csv", ios_base::app);
  Resultados << Alfa << "," << vetor[1] << endl;
  Resultados.close();

  cout << left << setw(31) << "Duplo hashing" << ": " << right << setw(7) << vetor[2] << endl;
  Resultados.open("Saida-Duplo-hashing-total.csv", ios_base::app);
  Resultados << Alfa << "," << vetor[2] << endl;
  Resultados.close();

  cout << left << setw(31) << "Sondagem linear" << ": " << right << setw(7) << vetor[3] << endl;
  Resultados.open("Saida-Sondagem-linear-total.csv", ios_base::app);
  Resultados << Alfa << "," << vetor[3] << endl;
  Resultados.close();
}

void ArquivoProfessor(string FileName)
{
  TesteProfessor(FileName);
}