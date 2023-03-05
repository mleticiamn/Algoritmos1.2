#include <iostream>
using namespace std;

// Estrutura para o nó
struct Node {
    string valor;
    Node* next;
    Node(string v) {
        valor = v;
        next = nullptr;
    }
};

//################################################################################################################

// Estrutura da fila
class Queue {
    Node* head;
    Node* tail;
    int size;

public: //Métodos da fila
    Queue() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    // É importante saber se a lista está vazia para criar ou não o head
    bool empty(){
        if (size == 0) {
            return true;
        } else {
            return false;
        }
    }
    

    // Ciando novo nó e inserindo na fila
    void enqueue(string valor) {
        Node* novo_no = new Node(valor);
        if (empty() == true) { //nesse caso, precisa criar o head
            head = novo_no;
            tail = novo_no;
        } else {
            tail->next = novo_no;
            tail = novo_no;
        }
        size++;
    }


    string dequeue() {  // Preciso retornar o elemento deletado da fila e colocar na pilha
        if (empty() == true) {
            return "";
        }
        Node* cur = head;
        string carta_removida;
        if (head == tail) {
            // Caso a fila tenha apenas um elemento, head e tail ficam null
            head = nullptr;
            tail = nullptr;
        } else {
            while (cur->next != tail) {
                cur = cur->next;
            }
            tail = cur;
            cur = cur->next;
            carta_removida = cur->valor;
            tail->next = nullptr;
        }
        delete cur;
        size--;
        return carta_removida;
    }

};


//################################################################################################################
//Analogamente, fazendo a estrutura da pilha
class Stack {
    Node* top;
    int size_s;

public: // Métodos da pilha
    Stack(){
        top = nullptr;
        size_s = 0;
    }

    // É importante saber se a pilha está vazia para criar ou não o topo
    bool empty(){
        if (size_s == 0){
            return true;
        } else {
            return false;
        }
    }

    // Preciso do topo da pilha 
    string top() {
        if (empty()==true) {
            return = "";
        } else {
            return top->valor;
    }
    }

    void push(string valor){
        Node* novo_no = new Node(valor);
        novo_no->next = top;
        top = novo_no;
    }

    void print_pilha(){
        Node* cur = top;
        while (cur->next != nullptr){
            cout << cur->valor << ' ';
            cur = cur->next;
        }
        cout << cur->valor;
        cout << endl;
    }

}


string comparar_cartas(string carta1, string carta2){
    // Separa o valor e o naipe das cartas
    char valor1 = carta1[0];
    char naipe1 = carta1[1];
    char valor2 = carta2[0];
    char naipe2 = carta2[1];

    // Compara o valor das cartas
    if (valor1 > valor2) {
        return carta1;
    } else if (valor2 > valor1) {
        return carta2;
    } else {
        // Se os valores são iguais, compare o naipe
        if (naipe1 > naipe2) {
            return carta1;
        } else {
            return carta2;
        }
    }
}





int main() {
    int n_jogadores;
    cin >> n_jogadores;

    // Cada jogador tem sua própria fila contendo sua sequência de cartas e, como sabemos o nmúmero de jogadores, pode-se criar um array
    Queue filas_jogadores[n_jogadores];

    // Montando pilha que vai receber as cartas dos jogaores
    Stack cuscuz_pilha;

    // Número da rodada;
    int n_rodada = 0;

    // Esse array vai conter todas as cartas na rodada. O índice 0 vai conter a carta do jogador 0
    // Faço isso para ter controle de qual jogador jogou qual carta
    string cartas_rodada = [n_jogadores];

    // Loop
    string comando;
    while (cin >> comando) {

        if (comando == "DEA") { // Comando pra enfileirar
            for (int i = 0; i < n_jogadores; i++) {
                string carta;
                cin >> carta;
                filas_jogadores[i].enqueue(carta);
            }

        } else if (comando == "RND") { // Desenfileira uma carta de cada jogador e joga na pilha 
            for (int i = 0; i < n_jogadores; i++) {
                string carta_colocar_pilha;
                carta_colocar_pilha = filas_jogadores[i].dequeue();
                cuscuz_pilha.push(carta_colocar_pilha);
                cartas_rodada[i] = carta_colocar_pilha
                }

            // Agora tenho todas as cartas que preciso comparar em um array
            int indice_maior = 0;
            for (int i = 0; i < n_jogadores - 1; i++) {
                for (int j = 0; j < n_jogadores - i - 1; j++) {
                    if (comparar_cartas(cartas_rodada[j], cartas_rodada[j+1])) {
                        swap(cartas[j], cartas[j+1]);
                        indice_maior = j;
                        }
                    }
                }
            // Printar o número da rodada e o jogador que ganhou
            cout << n_rodada << ' ';
            cout << indice_maior << endl;

        } else if (comando == "PRT") {  // Agora o PRT printa todas as cartas que estão na pilha
            cuscuz_pilha.print_pilha();

        } else if (comando == "END") { // Finaliza
            break;
        }
    }

    return 0;
}