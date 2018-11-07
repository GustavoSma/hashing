#include <iostream>
#include "LinkedList.h"
#include <map>
#include <string.h>

using namespace std;

struct dict{
	Lista *ref; // referencia para lista que será inserida na posição
};

void insereLista(dict table[], int tam){
	for(int i=0;i<tam;i++) {
		Lista *l = new Lista;
		table[i].ref=l;
	}
}

void insereDados(dict table[],int pos, Palavra *p){
	table[pos].ref->insere(p);
}

void mostraHash(dict table[]){
	for(int i=0;i<26;i++) {
		table[i].ref->imprime();
		
	}
}
map<char,int> mapLetras(){
	string alfabeto="abcdefghijklmnopqrstuvwxyz";
	char letra;
	map<char,int> mapa;
	for(int i=0;i<26;i++){
		letra=alfabeto[i];
		mapa[letra]=i;
	}
	return mapa;
}

int funcHash(char letraInicial){
	map <char,int> mapa = mapLetras();
	return mapa[letraInicial];
}

int main(){
	string palavra, traducao;
	int pos;
	dict hash[26];
	insereLista(hash,26);
	
	for(int i=0;i<10;i++){
		cout<<"Palavra: ";
		cin>>palavra;
		cout<<"Traducao: ";
		cin>>traducao;
		pos = funcHash(palavra[0]);
		Palavra *p=new Palavra(palavra,traducao);
		insereDados(hash,pos,p);
	}
	
	mostraHash(hash);
	system("pause");
	return 0;
}

