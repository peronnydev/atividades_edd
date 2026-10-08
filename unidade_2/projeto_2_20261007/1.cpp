#include <iostream>
using namespace std;

string const AQUATICO = "Aquatico";
string const TERRESTRE = "Terrestre";
string const VOADORES = "Voadores";

struct Animal{
	Animal* sucessor;
	string nome;
	string alimentacao;
	string pais;
	int idade;
	string habitat;
};

void buscarTodos(Animal*& head){
	if(head == NULL){
		cout << "Nenhum animal cadastrado!" << endl;
		return;
	}
	cout << "----Mostrando TODOS os animais" << endl;
	for(Animal* aux = head; aux->sucessor != NULL; aux = aux->sucessor){
		cout << "Nome:        " << aux->nome << endl;
		cout << "Alimentacao: " << aux->alimentacao << endl;
		cout << "Pais:        " << aux->pais << endl;
		cout << "Idade:       " << aux->idade << endl;
		cout << "Habitat:     " << aux->habitat << endl; 
		cout << "----" << endl;
	}
}

void buscarPorHabitat(Animal*& head, string habitat){
	if(head == NULL){
		cout << "Nenhum animal cadastrado!" << endl;
		return;
	}
	cout << "----Animais cadastrados no Habitat " << habitat << endl;
	for(Animal* aux = head; aux->sucessor != NULL; aux = aux->sucessor){
		if(aux->habitat == habitat){
			cout << "Nome:        " << aux->nome << endl;
			cout << "Alimentacao: " << aux->alimentacao << endl;
			cout << "Pais:        " << aux->pais << endl;
			cout << "Idade:       " << aux->idade << endl;
			cout << "Habitat:     " << aux->habitat << endl; 
			cout << "----" << endl;
		}
	}
}

void buscarPorNome(Animal*& head, string nome){
	if(head == NULL){
		cout << "Nenhum animal cadastrado!" << endl;
		return;
	}
	cout << "----Mostrando animais com o nome " << nome << endl;
	for(Animal* aux = head; aux->sucessor != NULL; aux = aux->sucessor){
		if(aux->nome == nome){
			cout << "Nome:        " << aux->nome << endl;
			cout << "Alimentacao: " << aux->alimentacao << endl;
			cout << "Pais:        " << aux->pais << endl;
			cout << "Idade:       " << aux->idade << endl;
			cout << "Habitat:     " << aux->habitat << endl; 
			cout << "----" << endl;	
		}
	}
}

void removerPorNomeEHabitat(Animal*& head, string nome, string habitat){
	if(head == NULL){
		cout << "Nenhum animal cadastrado!" << endl;
		return;
	}
	for(Animal* aux = head; aux->sucessor != NULL; aux = aux->sucessor){
		if(
				aux->sucessor->nome == nome && 
				aux->sucessor->habitat == habitat)
			{
			Animal* animalParaRemover = aux->sucessor;
			cout << "----Removendo o animal com as caracteristicas abaixo " << endl;
			cout << "Nome:    " << animalParaRemover->nome << endl;
			cout << "Habitat: " << animalParaRemover->habitat << endl;
			aux->sucessor = animalParaRemover->sucessor;
			return;
		}
	}
}

void adicionarNoFinal(Animal*& head, string nome, string alimentacao, string pais, int idade, string habitat){
	Animal* novoAnimal = new Animal;
	novoAnimal->nome = nome;
	novoAnimal->alimentacao = alimentacao;
	novoAnimal->pais = pais;
	novoAnimal->idade = idade;
	novoAnimal->habitat = habitat;
	novoAnimal->sucessor = NULL;

	if(head == NULL){
		head = novoAnimal;
		return;
	}
	
	Animal* aux = head;
	while(aux->sucessor != NULL){
		aux = aux->sucessor;
	}
	
	aux->sucessor = novoAnimal;
	return;
}

string escolherHabitat(){
	int opcao;
	
	cout << "1 - " << AQUATICO << endl;
	cout << "2 - " << TERRESTRE << endl;
	cout << "3 - " << VOADORES << endl;
	cout << "Escolha o habitat: ";
	cin >> opcao;
	
	if(opcao == 1) return AQUATICO;
	if(opcao == 2) return TERRESTRE;
	return VOADORES;
}

void povoamento(Animal*& head){
	
	adicionarNoFinal(head, "Panda", "Bambu", "Japao", 8, TERRESTRE);
	adicionarNoFinal(head, "Pai do Panda", "Bambu", "Japao", 15, TERRESTRE);
	adicionarNoFinal(head, "Mae do Panda", "Bambu", "Japao", 14, TERRESTRE);
	adicionarNoFinal(head, "Irmao do Panda", "Bambu", "Japao", 6, TERRESTRE);
	adicionarNoFinal(head, "Primo do Panda", "Bambu", "Japao", 4, TERRESTRE);
	
	adicionarNoFinal(head, "Peixe", "Algas Marinhas", "Brasil", 2, AQUATICO);
	adicionarNoFinal(head, "Pai do Peixe", "Algas Marinhas", "Brasil", 5, AQUATICO);
	adicionarNoFinal(head, "Mae do Peixe", "Algas Marinhas", "Brasil", 4, AQUATICO);
	adicionarNoFinal(head, "Irmao do Peixe", "Algas Marinhas", "Brasil", 1, AQUATICO);
	adicionarNoFinal(head, "Primo do Peixe", "Algas Marinhas", "Brasil", 3, AQUATICO);
	
	adicionarNoFinal(head, "Arara", "Sementes", "Peru", 20, VOADORES);
	adicionarNoFinal(head, "Pai da Arara", "Sementes", "Peru", 35, VOADORES);
	adicionarNoFinal(head, "Mae da Arara", "Sementes", "Peru", 32, VOADORES);
	adicionarNoFinal(head, "Irmao da Arara", "Sementes", "Peru", 12, VOADORES);
	adicionarNoFinal(head, "Primo da Arara", "Sementes", "Peru", 9, VOADORES);
	
}

int main(){
	Animal* head = NULL;
	povoamento(head);
	
	int opcao = -1;
	while(opcao != 0){
		cout << endl;
		cout << "----Escolha uma opcao" << endl;
		cout << "1 - Cadastrar novo animal" << endl;
		cout << "2 - Consultar todos os animais" << endl;
		cout << "3 - Buscar animal pelo nome" << endl;
		cout << "4 - Visualizar animais por habitat" << endl;
		cout << "5 - Remover animal" << endl;
		cout << "0 - Sair" << endl;
		cout << "Opcao: ";
		cin >> opcao;
		
		if(opcao == 1){
			string habitat = escolherHabitat();
			string nome, alimentacao, pais;
			int idade;
			cout << "Nome: ";
			cin >> nome;
			cout << "Alimentacao: ";
			cin >> alimentacao;
			cout << "Pais de origem: ";
			cin >> pais;
			cout << "Idade: ";
			cin >> idade;
			adicionarNoFinal(head, nome, alimentacao, pais, idade, habitat);
			cout << "Animal cadastrado com sucesso!" << endl;
		}
		else if(opcao == 2){
			buscarTodos(head);
		}
		else if(opcao == 3){
			string nome;
			cout << "Nome do animal: ";
			cin >> nome;
			buscarPorNome(head, nome);
		}
		else if(opcao == 4){
			string habitat = escolherHabitat();
			buscarPorHabitat(head, habitat);
		}
		else if(opcao == 5){
			string nome;
			cout << "Nome do animal a remover: ";
			cin >> nome;
			string habitat = escolherHabitat();
			removerPorNomeEHabitat(head, nome, habitat);
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