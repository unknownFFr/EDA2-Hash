
void AbrirLinear(string Nome){
  ifstream CasoTeste;
  CasoTeste.open(Nome);
  
  int Modulo, Quantidade;

  CasoTeste >> Quantidade;
  CasoTeste >> Modulo;
  
  int *Keys;
  Keys = new int[Modulo];
  
  for (int i = 0; i < Quantidade; i++) {
    CasoTeste >> Keys[i];
  }

  SondagemLinear h(Modulo);

  for(int i = 0 ; i < Quantidade ; i++){
    h.AddKey(Keys[i]);
  }
  
  h.PrintTable();
  
}

void AbrirDuplo(string Nome){
  ifstream CasoTeste;
  CasoTeste.open(Nome);
  
  int Modulo, Quantidade;

  CasoTeste >> Quantidade;
  CasoTeste >> Modulo;
  
  int *Keys;
  Keys = new int[Modulo];
  
  for (int i = 0; i < Quantidade; i++) {
    CasoTeste >> Keys[i];
  }

  DuploHashing h(Modulo);

  for(int i = 0 ; i < Quantidade ; i++){
    h.AddKey(Keys[i]);
  }

  h.PrintTable();
  
}

void AbrirExplicito(string Nome){
  ifstream CasoTeste;
  CasoTeste.open(Nome);
  
  int Modulo, Quantidade;

  CasoTeste >> Quantidade;
  CasoTeste >> Modulo;
  
  int *Keys;
  Keys = new int[Modulo];
  
  for (int i = 0; i < Quantidade; i++) {
    CasoTeste >> Keys[i];
  }

  EncadeamentoExplicito h(Modulo);

  for(int i = 0 ; i < Quantidade ; i++){
    h.AddKey(Keys[i]);
  }
  
  cout << endl;
  h.PrintTable();
  
  double Media = 0;
  double temp;
  
  for(int i = 0 ; i < Quantidade ; i++){
    temp = h.SearchKey(Keys[i])[1];
    cout << "Chave " << i << " " << temp << endl;
    Media += temp;
  }


  Media /= Quantidade;
  cout << Media << endl;

}

void AbrirExplicitoDinamico(string Nome){
  ifstream CasoTeste;
  CasoTeste.open(Nome);
  
  int Modulo, Quantidade;

  CasoTeste >> Quantidade;
  CasoTeste >> Modulo;
  
  int *Keys;
  Keys = new int[Modulo];
  
  for (int i = 0; i < Quantidade; i++) {
    CasoTeste >> Keys[i];
  }

  EncadeamentoExplicitoDinamico h(Modulo);

  for(int i = 0 ; i < Quantidade ; i++){
    h.AddKey(Keys[i]);
  }
  h.PrintTable();

  double Media = 0;
  double temp;
  
  for(int i = 0 ; i < Quantidade ; i++){
    temp = h.SearchKey(Keys[i])[1];
    cout << "Chave " << i << " " << temp << endl;
    Media += temp;
  }


  Media /= Quantidade;
  cout << Media << endl;
  
}

void TestaCasosDaAula(int HashType){

  string Nome;
  switch(HashType){
    case 1:
       Nome = "testes/testes-especificos/teste-duplo.txt";
       AbrirDuplo(Nome);
      break;
    case 2:
      Nome = "testes/testes-especificos/teste-explicito.txt";
      AbrirExplicito(Nome);
      break;
     case 3:
       Nome = "testes/testes-especificos/teste-sondagem.txt";
       AbrirLinear(Nome);
       break;
      case 4:
        Nome = "testes/testes-especificos/teste-explicito.txt";
        AbrirExplicitoDinamico(Nome);
        break;
  }
  
}

long double *MediaDeAcessosArquivo(long double alfa, int SetAmount){
    
  string Nome;
  int Amount = int(1001*alfa/100);
  int *chaves = new int[Amount];
  
  long double *MediaDeUmArquivo = (long double*) calloc(4,sizeof(long double));//Media de todos as chaves de uma tabela de todas as tabelas de um arquivo de teste
  long double *MediaDeUmConjunto = (long double*) calloc(4,sizeof(long double));//Media de todos as chaves de uma tabela
  ifstream CasoTeste;
  int j, i;
  int buffer;
  //Calcula a media de todos os arquivos

    //abre arquivo
    Nome = "testes/testes-finais/testes-finais-0.txt";
    CasoTeste.open(Nome);
  
    //analisa todo conjunto
    for( j = 0; j < SetAmount; j++){

      //coleta as 1001*alfa/100 chaves a serem inseridas
      for( i = 0; i < 1001 ; i ++){
        
        if (i < Amount){             
          CasoTeste >> chaves[i];
        }
        else{
          CasoTeste >> buffer;
        }
      }
      
      //declara cria as tabelas hash
      EncadeamentoExplicitoDinamico h0(1001);
      EncadeamentoExplicito h1(1001);
      DuploHashing h2(1001);
      SondagemLinear h3(1001);
      
      //adicionas as chaves a suas posições respectivas
      for( i = 0; i < Amount; i ++){
        h0.AddKey(chaves[i]);
        h1.AddKey(chaves[i]);
        h2.AddKey(chaves[i]);
        h3.AddKey(chaves[i]);
      }
      
      MediaDeUmConjunto[0] = 0;
      MediaDeUmConjunto[1] = 0;
      MediaDeUmConjunto[2] = 0;
      MediaDeUmConjunto[3] = 0;

      //calcula media de um conjunto
      for( i = 0; i < Amount; i ++){
        MediaDeUmConjunto[0] += h0.SearchKey(chaves[i])[1];
        MediaDeUmConjunto[1] += h1.SearchKey(chaves[i])[1];
        MediaDeUmConjunto[2] += h2.SearchKey(chaves[i])[1];
        MediaDeUmConjunto[3] += h3.SearchKey(chaves[i])[1];
      }
      
      MediaDeUmConjunto[0] /= Amount;
      MediaDeUmConjunto[1] /= Amount;
      MediaDeUmConjunto[2] /= Amount;
      MediaDeUmConjunto[3] /= Amount;

      
      MediaDeUmArquivo[0] += MediaDeUmConjunto[0];
      MediaDeUmArquivo[1] += MediaDeUmConjunto[1];
      MediaDeUmArquivo[2] += MediaDeUmConjunto[2];
      MediaDeUmArquivo[3] += MediaDeUmConjunto[3];
      
    }
    
    MediaDeUmArquivo[0] /= SetAmount;
    MediaDeUmArquivo[1] /= SetAmount;
    MediaDeUmArquivo[2] /= SetAmount;
    MediaDeUmArquivo[3] /= SetAmount;

  CasoTeste.close();
  
  return MediaDeUmArquivo;
}

long double *MediaDeAcessosConjunto(long double alfa, int NumeroConjunto, string TestFileName, int HashSize){
  
  int Amount = int(HashSize*alfa/100);
  int chaves[Amount];

  long double *MediaDeUmConjunto = (long double*) calloc(4,sizeof(long double));//Media de todos as chaves de uma tabela

  
  ifstream CasoTeste;
  int i;
  int buffer;
  //Calcula a media de todos os arquivos

  //abre arquivo
  CasoTeste.open(TestFileName);

  //ineficiente ? Sim, mas funciona
  for(int i = 0 ; i < NumeroConjunto*HashSize; i++){
    CasoTeste >> buffer;
  }

  //analisa todo conjunto

  //coleta as 1001*alfa/100 chaves a serem inseridas
  for( i = 0; i < HashSize ; i ++){
     if (i < Amount){             
       CasoTeste >> chaves[i];
     }
     else{
       CasoTeste >> buffer;
     }
   }

  // //declara cria as tabelas hash
  EncadeamentoExplicitoDinamico h0(HashSize);
  EncadeamentoExplicito h1(HashSize);
  DuploHashing h2(HashSize);
  SondagemLinear h3(HashSize);
  
  // //adicionas as chaves a suas posições respectivas
  for( i = 0; i < Amount; i++){
    h0.AddKey(chaves[i]);
    h1.AddKey(chaves[i]);
    h2.AddKey(chaves[i]);
    h3.AddKey(chaves[i]);
  }
  
  //
  
  //calcula media de um conjunto
  for( i = 0; i < Amount; i ++){
    MediaDeUmConjunto[0] += h0.SearchKey(chaves[i])[1];
    MediaDeUmConjunto[1] += h1.SearchKey(chaves[i])[1];
    MediaDeUmConjunto[2] += h2.SearchKey(chaves[i])[1];
    MediaDeUmConjunto[3] += h3.SearchKey(chaves[i])[1];
  }
  
  MediaDeUmConjunto[0] /= (Amount);
  MediaDeUmConjunto[1] /= (Amount);
  MediaDeUmConjunto[2] /= (Amount);
  MediaDeUmConjunto[3] /= (Amount); 
  

  CasoTeste.close();
  
  return MediaDeUmConjunto;
}

void TesteProfessor(string FileName)
{
  ifstream CasoTeste;
  CasoTeste.open(FileName);
  int HashSize;
  CasoTeste >> HashSize;

  EncadeamentoExplicitoDinamico h0(HashSize);
  EncadeamentoExplicito h1(HashSize);
  DuploHashing h2(HashSize);
  SondagemLinear h3(HashSize);
  Linear h4(80);

  int Key;
  vector<int> Keys;

  while (CasoTeste >> Key) 
  {
    Keys.push_back(Key);
    h0.AddKey(Key);
    h1.AddKey(Key);
    h2.AddKey(Key);
    h3.AddKey(Key);
    h4.AddKey(Key);
  }

  long double Media0 = 0, Media1 = 0, Media2 = 0, Media3 = 0, Media4 = 0;

  for(auto k : Keys)
  {
    Media0 += h0.SearchKey(k)[1];
    Media1 += h1.SearchKey(k)[1];
    Media2 += h2.SearchKey(k)[1];
    Media3 += h3.SearchKey(k)[1];
    Media4 += h4.SearchKey(k)[1];
  }

  Media0 /= Keys.size();
  Media1 /= Keys.size();
  Media2 /= Keys.size();
  Media3 /= Keys.size();
  Media4 /= Keys.size();

  cout << "Tabela para o Encadeamento Explicito Dinamico:" << endl;
  h0.PrintTable();
  cout << "Media de acesos para o Encadeamento Explicito Dinamico: " << Media0 << endl << endl;

  cout << "Tabela para o Encadeamento Explicito Estatico:" << endl;
  h1.PrintTable();
  cout << "Media de acesos para o Encadeamento Explicito Estatico: " << Media1 << endl << endl;

  cout << "Tabela para o Duplo Hashing:" << endl;
  h2.PrintTable();
  cout << "Media de acesos para o Duplo Hashing: " << Media2 << endl << endl;

  cout << "Tabela para a Sondagem Linear:" << endl;
  h3.PrintTable();
  cout << "Media de acesos para a Sondagem Linear: " << Media3 << endl << endl;

  cout << "Tabela para a Hashing Linear com 2 numeros por pagina e alfa maximo igual a 80%:" << endl;
  h4.PrintTable();
  cout << "Media de acesos para a Hashing Linear com 2 numeros por pagina e alfa maximo igual a 80%: " << Media4 << endl << endl;
}