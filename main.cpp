#include <iostream>
#include <locale.h>
#include <windows.h>

#include <ctime>

using namespace std;
int main()
{
    setlocale(LC_ALL, "Portuguese");// Configura o idioma para português
    system("Color E0");// Define a cor de fundo e do texto no console
    cout << "******************************" << endl;
    cout << "* Bem vindo ao jogo da velha *" << endl;
    cout << "******************************" << endl;
    string Seletor, Seletor1, Peca1, Peca2, Jogador1, Jogador2, Posicao1, Posicao2, N1, N2, Matriz [3][3]{"A", "B", "C", "D" , "E", "F", "G", "H", "I"};
    int Aleatorio, Select = 0, Menor = 1, Maior = 50, Cont = 0, Cont1 = 0, Cont2 = 0;
    cout << "1 para ir direto para o jogo, 2 para ver tutorial" << endl;
    cin >> Seletor;
    // Exibe tutorial se o jogador selecionar a opção 2
    if (Seletor == "2"){
        cout << "Tutorial" << endl;
        cout << "1ª Escolha a letra na tabela\n2ª Se escolher uma letra já mercada perdeu a vez \n3ª Se escolher uma letra que não tenha na tabela perdeu a vez\n" << endl;
        cout << "1 para ir direto para o jogo, 2 sair" << endl;
        cin >> Seletor;
    }
    if(Seletor == "1")// Inicia o jogo se o jogador selecionar a opção 1
    {
        cout << "Digite o nome do jogor 1ª jogador" << endl;
        cin >> Jogador1;
        cout << "Digite o nome do jogor 2ª jogador" << endl;
        cin >> Jogador2;
        srand((unsigned)time(0));// Inicializa o gerador de números aleatórios com a hora atual
        Aleatorio = rand()%(Maior-Menor+1) + Menor;// Gera um número aleatório entre Maior e Menor
        // Define quem começa o jogo com base no número aleatório gerado
        if(Aleatorio > 25){
            cout << Jogador2 << " começa," ;
            N1 = Jogador1;
            N2 = Jogador2;
            Jogador2 = N1;
            Jogador1 = N2;
        }else{
            cout << Jogador1 << " começa," ;
        }
        // Define aleatoriamente qual jogador jogará com cada peça
        Maior = 100;
        Menor = 50;
        srand((unsigned)time(0));
        Aleatorio = rand()%(Maior-Menor+1) + Menor;
        if(Aleatorio > 75){
            Peca1 = "O";
            Peca2 = "X";
        }else{
            Peca1 = "X";
            Peca2 = "O";
        }
        // Informa qual peça cada jogador utilizará
        cout << " você vai jogar com a peça " << Peca1 << endl;
        cout << Jogador2 << " você vai jogar com a peça " << Peca2 << endl;
        // Loop principal do jogo
        do{
            Cont ++;
            // Exibe a tabela de jogo
            cout << "                                  " << Matriz[0][0] << "  -  " << Matriz[0][1] << "  -  " << Matriz[0][2] << endl;
            cout << "                                 ----+-----+----" << endl;
            cout << "                                  " << Matriz[1][0] << "  -  " << Matriz[1][1] << "  -  " << Matriz[1][2] << endl;
            cout << "                                 ----+-----+----" << endl;
            cout << "                                  " << Matriz[2][0] << "  -  " << Matriz[2][1] << "  -  " << Matriz[2][2] << endl;
            // Lógica para alternar entre os jogadores e fazer as jogadas
            // Condição para determinar qual jogador deve fazer a jogada
            if((Cont == 1) || (Cont == 3) || (Cont == 5) || (Cont == 7) || (Cont == 9) || (Cont == 11) || (Cont == 13) || (Cont == 15)){
                cout << "Escolha a letra " << Jogador1 << endl;
                cin >> Seletor1;
            }else if((Cont == 2) || (Cont == 4) || (Cont == 6) || (Cont == 8) || (Cont == 10) || (Cont == 12) || (Cont == 14) || (Cont == 16)){
                    cout << "Escolha a letra " << Jogador2 << endl;
                    cin >> Seletor1;
            }
             // Lógica para validar a jogada e atualizar a matriz de jogo
            // Condições para verificar a jogada do jogador 1
            if(Seletor1 == "a"){
                // Verifica se a posição já está ocupada
                if((Matriz[0][0] == "O") || (Matriz[0][0] == "X")){
                    cout << "Essa posição já foi marcado, perdeu a vez !" << endl;
                    Select ++;
                }else{
                    // Atualiza a matriz com a jogada do jogador 1
                    if((Cont == 1) || (Cont == 3) || (Cont == 5) || (Cont == 7) || (Cont == 9) || (Cont == 11) || (Cont == 13) || (Cont == 15)){
                        Matriz[0][0] = Peca1;
                    }else if((Cont == 2) || (Cont == 4) || (Cont == 6) || (Cont == 8) || (Cont == 10) || (Cont == 12) || (Cont == 14) || (Cont == 16)){
                            Matriz[0][0] = Peca2;
                    }
                }// Continue com a lógica para as outras posições
            }else if(Seletor1 == "b"){
                if((Matriz[0][1] == "O") || (Matriz[0][1] == "X")){
                    cout << "Essa posição já foi marcado, perdeu a vez !" << endl;
                    Select ++;
                }else{
                    if((Cont == 1) || (Cont == 3) || (Cont == 5) || (Cont == 7) || (Cont == 9) || (Cont == 11) || (Cont == 13) || (Cont == 15)){
                        Matriz[0][1] = Peca1;
                    }else if((Cont == 2) || (Cont == 4) || (Cont == 6) || (Cont == 8) || (Cont == 10) || (Cont == 12) || (Cont == 14) || (Cont == 16)){
                        Matriz[0][1] = Peca2;
                    }
                }
            }else if(Seletor1 == "c"){
                if((Matriz[0][2] == "O") || (Matriz[0][2] == "X")){
                    cout << "Essa posição já foi marcado, perdeu a vez !" << endl;
                    Select ++;
                }else{
                    if((Cont == 1) || (Cont == 3) || (Cont == 5) || (Cont == 7) || (Cont == 9) || (Cont == 11) || (Cont == 13) || (Cont == 15)){
                        Matriz[0][2] = Peca1;
                    }else if((Cont == 2) || (Cont == 4) || (Cont == 6) || (Cont == 8) || (Cont == 10) || (Cont == 12) || (Cont == 14) || (Cont == 16)){
                        Matriz[0][2] = Peca2;
                    }
                }
            }else if(Seletor1 == "d"){
                if((Matriz[1][0] == "O") || (Matriz[1][0] == "X")){
                    cout << "Essa posição já foi marcado, perdeu a vez !" << endl;
                    Select ++;
                }else{
                    if((Cont == 1) || (Cont == 3) || (Cont == 5) || (Cont == 7) || (Cont == 9) || (Cont == 11) || (Cont == 13) || (Cont == 15)){
                        Matriz[1][0] = Peca1;
                    }else if((Cont == 2) || (Cont == 4) || (Cont == 6) || (Cont == 8) || (Cont == 10) || (Cont == 12) || (Cont == 14) || (Cont == 16)){
                        Matriz[1][0] = Peca2;
                    }
                }
            }else if(Seletor1 == "e"){
                if((Matriz[1][1] == "O") || (Matriz[1][1] == "X")){
                    cout << "Essa posição já foi marcado, perdeu a vez !" << endl;
                    Select ++;
                }else{
                    if((Cont == 1) || (Cont == 3) || (Cont == 5) || (Cont == 7) || (Cont == 9) || (Cont == 11) || (Cont == 13) || (Cont == 15)){
                        Matriz[1][1] = Peca1;
                    }else if((Cont == 2) || (Cont == 4) || (Cont == 6) || (Cont == 8) || (Cont == 10) || (Cont == 12) || (Cont == 14) || (Cont == 16)){
                        Matriz[1][1] = Peca2;
                    }
                }
            }else if(Seletor1 == "f"){
                if((Matriz[1][2] == "O") || (Matriz[1][2] == "X")){
                    cout << "Essa posição já foi marcado, perdeu a vez !" << endl;
                    Select ++;
                }else{
                    if((Cont == 1) || (Cont == 3) || (Cont == 5) || (Cont == 7) || (Cont == 9) || (Cont == 11) || (Cont == 13) || (Cont == 15)){
                        Matriz[1][2] = Peca1;
                    }else if((Cont == 2) || (Cont == 4) || (Cont == 6) || (Cont == 8) || (Cont == 10) || (Cont == 12) || (Cont == 14) || (Cont == 16)){
                        Matriz[1][2] = Peca2;
                    }
                }
            }else if(Seletor1 == "g"){
                if((Matriz[2][0] == "O") || (Matriz[2][0] == "X")){
                    cout << "Essa posição já foi marcado, perdeu a vez !" << endl;
                    Select ++;
                }else{
                    if((Cont == 1) || (Cont == 3) || (Cont == 5) || (Cont == 7) || (Cont == 9) || (Cont == 11) || (Cont == 13) || (Cont == 15)){
                        Matriz[2][0] = Peca1;
                    }else if((Cont == 2) || (Cont == 4) || (Cont == 6) || (Cont == 8) || (Cont == 10) || (Cont == 12) || (Cont == 14) || (Cont == 16)){
                        Matriz[2][0] = Peca2;
                    }
                }
            }else if(Seletor1 == "h"){
                if((Matriz[2][1] == "O") || (Matriz[2][1] == "X")){
                    cout << "Essa posição já foi marcado, perdeu a vez !" << endl;
                    Select ++;
                }else{
                    if((Cont == 1) || (Cont == 3) || (Cont == 5) || (Cont == 7) || (Cont == 9) || (Cont == 11) || (Cont == 13) || (Cont == 15)){
                        Matriz[2][1] = Peca1;
                    }else if((Cont == 2) || (Cont == 4) || (Cont == 6) || (Cont == 8) || (Cont == 10) || (Cont == 12) || (Cont == 14) || (Cont == 16)){
                        Matriz[2][1] = Peca2;
                    }
                }
            }else if(Seletor1 == "i"){
                if((Matriz[2][2] == "O") || (Matriz[2][2] == "X")){
                    cout << "Essa posição já foi marcado, perdeu a vez !" << endl;
                    Select ++;
                }else{
                    if((Cont == 1) || (Cont == 3) || (Cont == 5) || (Cont == 7) || (Cont == 9) || (Cont == 11) || (Cont == 13) || (Cont == 15)){
                        Matriz[2][2] = Peca1;
                    }else if((Cont == 2) || (Cont == 4) || (Cont == 6) || (Cont == 8) || (Cont == 10) || (Cont == 12) || (Cont == 14) || (Cont == 16)){
                        Matriz[2][2] = Peca2;
                    }
                }
            }else{//verifica se a posição está correta
                cout << "Não tem " << Seletor1 << " na tabela, perdeu a ver !" << endl;
            }// Lógica para verificar se há um vencedor
            // Condições para verificar outras possibilidades de vitória
            if((Matriz[0][0] == Matriz[0][1]) && (Matriz[0][1] == Matriz[0][2]) && (Matriz[0][2] == Matriz[0][0]) ||
               (Matriz[1][0] == Matriz[1][1]) && (Matriz[1][1] == Matriz[1][2]) && (Matriz[1][2] == Matriz[1][0]) ||
               (Matriz[2][0] == Matriz[2][1]) && (Matriz[2][1] == Matriz[2][2]) && (Matriz[2][2] == Matriz[2][0]) ||
               (Matriz[0][0] == Matriz[1][0]) && (Matriz[1][0] == Matriz[2][0]) && (Matriz[2][0] == Matriz[0][0]) ||
               (Matriz[0][1] == Matriz[1][1]) && (Matriz[1][1] == Matriz[2][1]) && (Matriz[2][1] == Matriz[0][1]) ||
               (Matriz[0][2] == Matriz[1][2]) && (Matriz[1][2] == Matriz[2][2]) && (Matriz[2][2] == Matriz[0][2]) ||
               (Matriz[0][0] == Matriz[1][1]) && (Matriz[1][1] == Matriz[2][2]) && (Matriz[2][2] == Matriz[1][1]) ||
               (Matriz[2][0] == Matriz[1][1]) && (Matriz[1][1] == Matriz[0][2]) && (Matriz[0][2] == Matriz[2][0])){
                cout << "                                ################### " << endl;
                cout << "                                #  " << Matriz[0][0] << "  -  " << Matriz[0][1] << "  -  " << Matriz[0][2] << "  # " << endl;
                cout << "                                # ----+-----+---- # " << endl;
                cout << "                                #  " << Matriz[1][0] << "  -  " << Matriz[1][1] << "  -  " << Matriz[1][2] << "  # " << endl;
                cout << "                                # ----+-----+---- # " << endl;
                cout << "                                #  " << Matriz[2][0] << "  -  " << Matriz[2][1] << "  -  " << Matriz[2][2] << "  # " << endl;
                cout << "                                ################### " << endl;
                // Exibe a mensagem de vitória e atualiza o placar
                if((Cont == 1) || (Cont == 3) || (Cont == 5) || (Cont == 7) || (Cont == 9) || (Cont == 11) || (Cont == 13) || (Cont == 15)){
                    Cont1 ++;
                    cout << Jogador1 << " Ganhou " << endl;
                    cout << "Placar" << endl;
                    cout << Jogador1 << " tá com " << Cont1 << " e " << Jogador2 << " tá com " << Cont2 << endl;
                }else if((Cont == 2) || (Cont == 4) || (Cont == 6) || (Cont == 8) || (Cont == 10) || (Cont == 12) || (Cont == 14) || (Cont == 16)){
                    Cont2 ++;
                    cout << Jogador2 << " Ganhou " << endl;
                    cout << "Placar" << endl;
                    cout << Jogador2 << " tá com " << Cont2 << " e " << Jogador1 << " tá com " << Cont1 << endl;
                }
                Cont = 0;
            }else{
                // Verifica se houve empate
                if((Select + 9) == Cont){
                    cout << "Ninquem ganhou !" << endl;
                    Cont = 0;
                }
            }
            // Limpa a matriz para reiniciar o jogo
            if(Cont == 0){
                Matriz [0][0] = "A";
                Matriz [0][1] = "B";
                Matriz [0][2] = "C";
                Matriz [1][0] = "D";
                Matriz [1][1] = "E";
                Matriz [1][2] = "F";
                Matriz [2][0] = "G";
                Matriz [2][1] = "H";
                Matriz [2][2] = "I";
                // Verifica se os jogadores desejam jogar novamente
                cout << "Deseja jogar novamente S para sim N para não" << endl;
                cin >> Seletor;
            }
            // Exibe o placar final e encerra o jogo se os jogadores optarem por sair
            if(Seletor == "n"){
                if(Cont1 > Cont2){
                    cout << Jogador1 << " venceu de " << Cont1 << " a " << Cont2;
                }else{
                    cout << Jogador2 << " venceu de " << Cont2 << " a " << Cont1;
                }
            }
        }while(Seletor != "n");
    }
    return 0;
}
