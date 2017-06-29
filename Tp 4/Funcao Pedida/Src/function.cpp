#include "function.hpp"

void insertInFile(int M, int N, Hash_Arvore_Binaria *h1, Hash_Encadeado *h2, Hash_Enderecamento_Aberto *h3, double *vec1, double *vec2){
	ifstream inserir;
	string s;
	double inicio, total=0;
	int cont = 0;
	inserir.open("../chaves-inserir.txt");
	for (int i=0; i<N; i++){
		getline(inserir, s);
		inicio = high_resolution_clock::now().time_since_epoch().count();
		(*h1).insertElement(s);
		inicio = (high_resolution_clock::now().time_since_epoch().count()-inicio)/1000000;
		total += inicio;
		cont++;
	}
	/*
	cout<<"Colisões = "<<(*h1).colision<<endl;
	cout<<"Tempo total = "<<total<<endl;
	cout<<"Inserções bem sucedidas = "<<cont<<endl;
	cout<<"Tempo médio de inserção Hash_Arvore_Binaria = "<<total<<"/"<<cont<<" = "<<(double)total/cont<<" ms"<<endl<<endl;
	*/
	vec1[0] = (double)(*h1).colision;
	vec2[0] = (double)total/cont;
	total = cont = 0;

	inserir.close();

	inserir.open("../chaves-inserir.txt");
	for (int i=0; i<N; i++){
		getline(inserir, s);
		inicio = high_resolution_clock::now().time_since_epoch().count();
		(*h2).insertElement(s);
		inicio = (high_resolution_clock::now().time_since_epoch().count()-inicio)/1000000;
		total += inicio;
		cont++;
	}
	/*
	cout<<"Colisões = "<<(*h2).colision<<endl;
	cout<<"Tempo total = "<<total<<endl;
	cout<<"Inserções bem sucedidas = "<<cont<<endl;
	cout<<"Tempo médio de inserção Hash_Encadeado = "<<total<<"/"<<cont<<" = "<<(double)total/cont<<" ms"<<endl<<endl;
	*/
	vec1[1] = (double)(*h2).colision;
	vec2[1] = (double)total/cont;
	total = cont = 0;
	inserir.close();

	inserir.open("../chaves-inserir.txt");
	for (int i=0; i<N; i++){
		getline(inserir, s);
		inicio = high_resolution_clock::now().time_since_epoch().count();
		int a = (*h3).insertElement(s);
		inicio = (high_resolution_clock::now().time_since_epoch().count()-inicio)/1000000;
		if(a){
			total += inicio;
			cont++;
		}
	}
	/*
	cout<<"Colisões = "<<(*h3).colision<<endl;
	cout<<"Tempo total = "<<total<<endl;
	cout<<"Inserções bem sucedidas = "<<cont<<endl;
	cout<<"Tempo médio de inserção Hash_Enderecamento_Aberto = "<<total<<"/"<<cont<<" = "<<(double)total/cont<<" ms"<<endl<<endl;
	*/
	vec1[2] = (double)(*h3).colision;
	vec2[2] = (double)total/cont;
	inserir.close();
}

void searchElements(int M, int N, Hash_Arvore_Binaria *h1, Hash_Encadeado *h2, Hash_Enderecamento_Aberto *h3, double *vetor){
	ifstream pesquisar;

	string s;
	double inicio, total=0;
	int cont = 0;
	pesquisar.open("../chaves-pesquisar.txt");
	for (int i=0; i<2000; i++){
		getline(pesquisar, s);
		inicio = high_resolution_clock::now().time_since_epoch().count();
		int a = (*h1).searchFor(s);
		inicio = (high_resolution_clock::now().time_since_epoch().count()-inicio)/1000000;
		if(a!=-1){
			total += inicio;
			cont++;
		}
	}
	/*
	cout<<"Tempo total = "<<total<<endl;
	cout<<"Pesquisas bem sucedidas = "<<cont<<endl;
	cout<<"Tempo médio de pesquisa Hash_Arvore_Binaria = "<<total<<"/"<<cont<<" = "<<(double)total/cont<<" ms"<<endl<<endl;
	*/
	vetor[0] = (double)total/cont;
	total = cont = 0;

	pesquisar.close();

	pesquisar.open("../chaves-pesquisar.txt");
	for (int i=0; i<2000; i++){
		getline(pesquisar, s);
		inicio = high_resolution_clock::now().time_since_epoch().count();
		int a = (*h2).searchFor(s);
		inicio = (high_resolution_clock::now().time_since_epoch().count()-inicio)/1000000;
		if(a!=-1){
			total += inicio;
			cont++;
		}
	}
	/*
	cout<<"Tempo total = "<<total<<endl;
	cout<<"Pesquisas bem sucedidas = "<<cont<<endl;
	cout<<"Tempo médio de pesquisa Hash_Encadeado = "<<total<<"/"<<cont<<" = "<<(double)total/cont<<" ms"<<endl<<endl;
	*/
	vetor[1] = (double)total/cont;
	total = cont = 0;
	
	pesquisar.close();

	pesquisar.open("../chaves-pesquisar.txt");
	for (int i=0; i<2000; i++){
		getline(pesquisar, s);
		inicio = high_resolution_clock::now().time_since_epoch().count();
		int a = (*h3).searchFor(s);
		inicio = (high_resolution_clock::now().time_since_epoch().count()-inicio)/1000000;
		if(a){
			total += inicio;
			cont++;
		}
	}
	/*
	cout<<"Tempo total = "<<total<<endl;
	cout<<"Pesquisas bem sucedidas = "<<cont<<endl;
	cout<<"Tempo médio de pesquisa Hash_Enderecamento_Aberto = "<<total<<"/"<<cont<<" = "<<(double)total/cont<<" ms"<<endl<<endl;
	*/
	vetor[2] = (double)total/cont;
	pesquisar.close();
}

void deleteElements(int M, int N, Hash_Arvore_Binaria *h1, Hash_Encadeado *h2, Hash_Enderecamento_Aberto *h3, double *vetor){
	ifstream deletar;

	string s;
	double inicio, total=0;
	int cont = 0;
	deletar.open("../chaves-apagar.txt");
	for (int i=0; i<1000; i++){
		getline(deletar, s);
		inicio = high_resolution_clock::now().time_since_epoch().count();
		int a = (*h1).deleteElement(s);
		inicio = (high_resolution_clock::now().time_since_epoch().count()-inicio)/1000000;
		if(a){
			total += inicio;
			cont++;
		}
	}
	/*
	cout<<"Tempo total = "<<total<<endl;
	cout<<"Exclusões bem sucedidas = "<<cont<<endl;
	cout<<"Tempo médio de exclusão Hash_Arvore_Binaria = "<<total<<"/"<<cont<<" = "<<(double)total/cont<<" ms"<<endl<<endl;
	*/
	vetor[0] = (double)total/cont;
	total = cont = 0;

	deletar.close();

	deletar.open("../chaves-apagar.txt");
	for (int i=0; i<1000; i++){
		getline(deletar, s);
		inicio = high_resolution_clock::now().time_since_epoch().count();
		int a = (*h2).deleteElement(s);
		inicio = (high_resolution_clock::now().time_since_epoch().count()-inicio)/1000000;
		if(a){
			total += inicio;
			cont++;
		}
	}
	/*
	cout<<"Tempo total = "<<total<<endl;
	cout<<"Exclusões bem sucedidas = "<<cont<<endl;
	cout<<"Tempo médio de exclusão Hash_Encadeado = "<<total<<"/"<<cont<<" = "<<(double)total/cont<<" ms"<<endl<<endl;
	*/
	vetor[1] = (double)total/cont;
	total = cont = 0;
	
	deletar.close();


	deletar.open("../chaves-apagar.txt");
	for (int i=0; i<1000; i++){
		getline(deletar, s);
		inicio = high_resolution_clock::now().time_since_epoch().count();
		int a = (*h3).deleteElement(s);
		inicio = (high_resolution_clock::now().time_since_epoch().count()-inicio)/1000000;
		if(a){
			total += inicio;
			cont++;
		}
	}
	/*
	cout<<"Tempo total = "<<total<<endl;
	cout<<"Exclusões bem sucedidas = "<<cont<<endl;
	cout<<"Tempo médio de exclusão Hash_Enderecamento_Aberto = "<<total<<"/"<<cont<<" = "<<(double)total/cont<<" ms"<<endl<<endl;
	*/
	vetor[2] = (double)total/cont;
	deletar.close();
}

void magicFunction(int M, int N){
	Hash_Arvore_Binaria        h1 = Hash_Arvore_Binaria(M);
	Hash_Encadeado             h2 = Hash_Encadeado(M);
	Hash_Enderecamento_Aberto  h3 = Hash_Enderecamento_Aberto(M);

	string s[3] = {"Hash_Arvore_Binaria", "Hash_Encadeado", "Hash_Enderecamento_Aberto"};

	double vec1[3], vec2[3], vec3[3], vec4[3];

	insertInFile(M, N, &h1, &h2, &h3, vec1, vec2);
	searchElements(M, N, &h1, &h2, &h3, vec3);
	deleteElements(M, N, &h1, &h2, &h3, vec4);

	for(int i=0; i<3; i++){
		cout<<s[i]<<endl;
		cout<<"Tamanho da tabela: "<<M<<endl;
		cout<<"Tamanho da entrada: "<<N<<endl;
		cout<<"Numero de colisoes na insercao: "<<vec1[i]<<endl;
		cout<<"Tempo medio para inserir um elemento: "<<vec2[i]<<endl; 
		cout<<"Tempo medio para consultar um elemento: "<<vec3[i]<<endl;
		cout<<"Tempo medio para apagar um elemento da tabela: "<<vec4[i]<<endl<<endl;;
	}

}