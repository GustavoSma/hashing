#include <iostream>
#include <string.h>
#include "palavra.h"

using namespace std;

class Celula{
	public:
		Palavra *palavra;
		Celula *prox;
};

class Lista{
	private:
		Celula *primeiro, *ultimo;
		
	public:
		Lista(){
			primeiro=ultimo=NULL;
		}
		
		void insere(Palavra *p){
			Celula *temp=new Celula;
			temp->palavra=p;
			temp->prox=NULL;
			if(vazia()) {
				primeiro=temp;
				ultimo=temp;
			}
			else{
				ultimo->prox=temp;
				ultimo=temp;
			}
		}
		
		void remove(string palavra){
			if(vazia()) cout<<"ERRO: Lista vazia"<<endl;
			
			else{
				Celula *temp=primeiro;
				if(temp->palavra->getPalavra()==palavra) {
					primeiro=primeiro->prox;
					return;
				}
				
				while (temp->prox->palavra->getPalavra()!=palavra) temp=temp->prox;
				temp->prox=temp->prox->prox;
			}
		}
		
		bool vazia(){
			return primeiro==NULL;
		}
		void imprime(){
			Celula *temp=primeiro;
			while(temp!=NULL){
				cout<<temp->palavra->getPalavra()<<" , ";
				cout<<temp->palavra->getTraducao();
				cout<<endl;
				temp=temp->prox;
			}
			cout<<endl;
			
		}
};

