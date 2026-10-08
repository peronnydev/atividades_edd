#include <iostream>
using namespace std;

struct Jogador{
	int id;
	string nome;
	bool vezDeJogar;
	Jogador* anterior;
	Jogador* sucessor;
};

Jogador* buscarPorId(Jogador*& head, int id){
	if(head == NULL){
		return NULL;
	}
	Jogador* aux = head;
	while(aux->sucessor != head && aux->id != id){
		aux = aux->sucessor;
	}
	if(aux->id == id){
		return aux;
	}
	return NULL;
}

Jogador* buscarVez(Jogador*& head){
	if(head == NULL){
		return NULL;
	}
	Jogador* aux = head;
	while(aux->sucessor != head && aux->vezDeJogar == false){
		aux = aux->sucessor;
	}
	if(aux->vezDeJogar){
		return aux;
	}
	return NULL;
}

void cadastrarJogador(Jogador*& head, int id, string nome){
	if(buscarPorId(head, id) != NULL){
		cout << "Ja existe um jogador com o identificador " << id << "!" << endl;
		return;
	}
	
	Jogador* novoJogador = new Jogador;
	novoJogador->id = id;
	novoJogador->nome = nome;
	
	if(head == NULL){
		novoJogador->vezDeJogar = true;
		novoJogador->anterior = novoJogador;
		novoJogador->sucessor = novoJogador;
		head = novoJogador;
		cout << "Primeiro jogador cadastrado! Ele inicia a partida." << endl;
		return;
	}
	
	Jogador* ultimo = head->anterior;
	novoJogador->vezDeJogar = false;
	novoJogador->anterior = ultimo;
	novoJogador->sucessor = head;
	ultimo->sucessor = novoJogador;
	head->anterior = novoJogador;
	cout << "Jogador cadastrado com sucesso!" << endl;
}

void removerPorId(Jogador*& head, int id){
	if(head == NULL){
		cout << "Nenhum jogador cadastrado!" << endl;
		return;
	}
	
	Jogador* atual = buscarPorId(head, id);
	if(atual == NULL){
		cout << "Jogador nao encontrado!" << endl;
		return;
	}
	
	cout << "----Removendo o jogador com as caracteristicas abaixo " << endl;
	cout << "Nome: " << atual->nome << endl;
	cout << "ID:   " << atual->id << endl;
	
	if(atual->sucessor == atual){
		head = NULL;
		delete atual;
		return;
	}
	if(atual->vezDeJogar){
		atual->sucessor->vezDeJogar = true;
	}
	if(atual == head){
		head = atual->sucessor;
	}
	
	Jogador* anteriorAoRemovido = atual->anterior;
	Jogador* sucessorAoRemovido = atual->sucessor;
	anteriorAoRemovido->sucessor = sucessorAoRemovido;
	sucessorAoRemovido->anterior = anteriorAoRemovido;
	delete atual;
}

void exibirJogadores(Jogador*& head){
	if(head == NULL){
		cout << "Nenhum jogador cadastrado!" << endl;
		return;
	}
	cout << "----Mostrando TODOS os jogadores" << endl;
	Jogador* aux = head;
	while(true){
		cout << "Nome: " << aux->nome << endl;
		cout << "ID:   " << aux->id << endl;
		if(aux->vezDeJogar){
			cout << "<< VEZ DE JOGAR >>" << endl;
		}
		cout << "----" << endl;
		
		if(aux->sucessor == head){
			return;
		} else {
			aux = aux->sucessor;
		}
	}
}

void mostrarVez(Jogador*& head){
	Jogador* jogadorDaVez = buscarVez(head);
	if(jogadorDaVez == NULL){
		cout << "Nenhum jogador cadastrado!" << endl;
		return;
	}
	cout << "----Vez de jogar" << endl;
	cout << "Nome: " << jogadorDaVez->nome << endl;
	cout << "ID:   " << jogadorDaVez->id << endl;
}

void avancarVez(Jogador*& head){
	Jogador* jogadorDaVez = buscarVez(head);
	if(jogadorDaVez == NULL){
		cout << "Nenhum jogador cadastrado!" << endl;
		return;
	}
	jogadorDaVez->vezDeJogar = false;
	jogadorDaVez->sucessor->vezDeJogar = true;
	cout << "A vez passou para " << jogadorDaVez->sucessor->nome << " (ID " << jogadorDaVez->sucessor->id << ")" << endl;
}

int main(){
	Jogador* head = NULL;
	
	int opcao = -1;
	while(opcao != 0){
		cout << endl;
		cout << "----Escolha uma opcao" << endl;
		cout << "1 - Cadastrar jogador" << endl;
		cout << "2 - Remover jogador pelo ID" << endl;
		cout << "3 - Exibir jogadores" << endl;
		cout << "4 - Ver de quem e a vez" << endl;
		cout << "5 - Avancar para o proximo jogador" << endl;
		cout << "0 - Sair" << endl;
		cout << "Opcao: ";
		cin >> opcao;
		
		if(opcao == 1){
			string nome;
			int id;
			cout << "Nome: ";
			cin >> nome;
			cout << "ID: ";
			cin >> id;
			cadastrarJogador(head, id, nome);
		}
		else if(opcao == 2){
			int id;
			cout << "ID do jogador a remover: ";
			cin >> id;
			removerPorId(head, id);
		}
		else if(opcao == 3){
			exibirJogadores(head);
		}
		else if(opcao == 4){
			mostrarVez(head);
		}
		else if(opcao == 5){
			avancarVez(head);
		}
		else if(opcao == 0){
			cout << "Encerrando o sistema..." << endl;
		}
		else{
			cout << "Opcao invalida!" << endl;
		}
	}
	
	return 0;
}