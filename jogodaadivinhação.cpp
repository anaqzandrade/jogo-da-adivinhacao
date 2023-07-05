////Jogo criado a partir das aulas de c++ da plataforma Alura.
////Alguns pontos foram aprimorados.
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

////Cabecalho de apresentacao.
void cabecalho() {
    cout << "******************************************************" << endl
         << "* Sera que voce consegue adivinhar o numero secreto? *" << endl
         << "******************************************************" << endl
         << "Escolha o ni­vel de dificuldade." << endl
         << "Facil (F), Medio (M), Difi­cil (D) ou Impossi­vel (I)." << endl;
}

int main() { 
    cabecalho();
    
////Escolha do ni­vel e verificao se o ni­vel escolhido e valido.
    char nivel;
    cin >> nivel;

    while (nivel != 'F' and nivel != 'M' and nivel != 'D' and nivel != 'I') {
        cout << "Nivel invalido, tente novamente." << endl;
        cin >> nivel;
    }

    int qtd_tentativas;

    if (nivel == 'F') {
        qtd_tentativas = 20;
    } else if (nivel == 'M') {
        qtd_tentativas = 10;
    } else if (nivel == 'D') {
        qtd_tentativas = 6;
    } else if (nivel == 'I') {
        qtd_tentativas = 4;
    }
    
    cout << "Voce escolheu: " << nivel << endl;

////I­nicio das tentativas para acertar o numero secreto.
    srand(time(NULL));
    const int NUMERO_SECRETO = (rand() % 100);
    int tentativas = 1;
    double pontos = 1000.0;
    bool nao_acertou = true;

    while (tentativas <= qtd_tentativas and nao_acertou == true) {
             int chute;
             cout << "Tentativa " << tentativas << endl;
             cout << "Qual seu chute? " << endl;
             cin >> chute;

        double pontos_perdidos = abs(chute - NUMERO_SECRETO) / 2.0;
        pontos = pontos - pontos_perdidos;
        bool maior = chute > NUMERO_SECRETO;

        if (chute == NUMERO_SECRETO) {
            cout << "Parabens, esse e o numero secreto! " << endl;
            nao_acertou = false;
        } else if (maior) {
            cout << "O numero secreto e menor. " << endl;
        } else {
            cout << "O numero secreto e maior." << endl;
        }

        tentativas++;
    }
    
    cout << "Fim de jogo!" << endl;

    if (nao_acertou) {
        cout << "Suas tentativas acabaram, tente novamente." << endl;
        cout << "O numero secreto era: " << NUMERO_SECRETO << endl;
    } else if (nao_acertou == false) {
        cout << "Voce acertou o numero secreto em " << tentativas - 1 << " tentativas." << endl;
        cout << "Sua pontuacao foi " << fixed << setprecision(2) << pontos << " pontos." << endl;
    }
    return 0;
}