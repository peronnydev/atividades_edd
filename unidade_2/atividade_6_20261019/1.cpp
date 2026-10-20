# include <iostream>
using namespace std;

struct fila{
fila* sucessor;
string valor;
};

int size(fila*& ultimo){
if(ultimo == NULL){
return 0;
}
int tamanho = 1;
for(fila* aux = ultimo -> sucessor; aux != ultimo; aux = aux -> sucessor){
tamanho++;
}
return tamanho;
}

void push(fila*& ultimo, string valorNovo){
fila* novoNo = new fila;
novoNo -> valor = valorNovo;
if(ultimo == NULL){
novoNo -> sucessor = novoNo;
} else {
novoNo -> sucessor = ultimo -> sucessor;
ultimo -> sucessor = novoNo;
}
ultimo = novoNo;
}

string pop(fila*& ultimo){
fila* removido = ultimo -> sucessor;
string v = removido -> valor;
if(removido == ultimo){
ultimo = NULL;
} else {
ultimo -> sucessor = removido -> sucessor;
}
delete removido;
return v;
}

void enfileirar(fila*& ultimo, string valorNovo){
push(ultimo, valorNovo);
}

string desenfileirar(fila*& ultimo){
return pop(ultimo);
}

void printar(fila*& ultimo){
if(ultimo != NULL){
fila* aux = ultimo -> sucessor;
do{
cout << "[" << aux -> valor << "]";
aux = aux -> sucessor;
} while(aux != ultimo -> sucessor);
}
cout << endl;
}

int main(){
fila* ultimo = NULL;
enfileirar(ultimo, "a");
enfileirar(ultimo, "b");
push(ultimo, "c");
printar(ultimo);
cout << size(ultimo) << endl;
desenfileirar(ultimo);
pop(ultimo);
printar(ultimo);
}
