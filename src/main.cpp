#include <algorithm> //<! transform, find

#include "forca.hpp"

using namespace std;

/**
 * Método utilizado para limpar o terminal.
 */
void limpaTela()
{
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #else
        system("clear");
    #endif    
}

/**
 * Método usado para imprimir a tela inicial.
 * @param opcao um número inteiro representando as opções do jogador.
 */
void telaInicial( int *opcao )
{
    cout << "Bem vindo ao Jogo Forca! Por favor escolha uma das opções" << endl;
    cout << "1 - Iniciar Jogo" << endl;
    cout << "2 - Ver scores anteriores" << endl << endl;
    
    cin >> *opcao;
}

/**
 * Método usado para determinar a dificuldade do jogo.
 * @param dificuldade 
 */
void escolheDificuldade ( int *dificuldade )
{
    cout << "Iniciando. Escolha o nível de dificulade" << endl << endl;
    cout << "1 - Fácil" << endl;
    cout << "2 - Médio" << endl;
    cout << "3 - Difícil" << endl << endl;

    cin >> *dificuldade;   
}

/**
 * Método usado para desenhar o corpo.
 */
void corpo( Forca carregar )
{
    if ( carregar.get_tentativas_restantes() == 6 )
        cout << endl << endl << endl << endl;

    if ( carregar.get_tentativas_restantes() == 5 )
        cout << " O " << endl <<  endl << endl << endl;

    if ( carregar.get_tentativas_restantes() == 4 )
        cout << " O " << endl << "/" << endl << endl << endl;

    if ( carregar.get_tentativas_restantes() == 3 )
        cout << " O " << endl << "/" << "|" << endl << endl << endl;

    if ( carregar.get_tentativas_restantes() == 2 )
        cout << " O " << endl << "/" << "|" << "\\" << endl << endl << endl;

    if ( carregar.get_tentativas_restantes() == 1 )
        cout << " O " << endl << "/" << "|" << "\\"<< endl <<"/ " << endl << endl;

    if ( carregar.get_tentativas_restantes() == 0 )
        cout << " O " << endl << "/" << "|" << "\\"<< endl <<"/ " << "\\" << endl << endl;
}

/**
 * Método usado para transformar letra minúscula em maiúscula.
 * @param letra string de letras minúsculas.
 * @return string convertida em caixa alta.
 */
string maiuscula( string letra )
{
    transform( letra.begin(), letra.end(), letra.begin(), ::toupper );
    return letra;
}

/**
 * Método usado para informar ao jogador que o jogo está iniciando e em qual dificuldade.
 * @param dificuldade a dificuldade escolhida na tela inicial.
 */
void cabecalhoDificuldade( int *dificuldade ) {
    if( *dificuldade == 1 )
        cout << "Iniciando o Jogo no nível fácil, será que você conhece essa palavra?" << endl;
    else if( *dificuldade == 2 )
        cout << "Iniciando o Jogo no nível médio, será que você conhece essa palavra?" << endl;
    else
        cout << "Iniciando o Jogo no nível difícil, será que você conhece essa palavra?" << endl;    
}

/**
 * @brief Método responsável pelo jogo em si.
 */
void iniciaJogo ( Forca carregar, int *dificuldade )
{
    vector<string> chutes; //<! palpites já feitos
    string palpite;

    carregar.set_tentativas_restantes(6);

    cabecalhoDificuldade( dificuldade );

    corpo( carregar );
    
    carregar.proxima_palavra( (Forca::Dificuldade)*dificuldade );

    carregar.linhas( palpite );
    cout << "Pontos: " << carregar.get_pontos() << endl;
    cout << "Palpite: ";

    // Enquanto não for game-over
    while ( !carregar.game_over() )
    {
        cin >> palpite;

        // Confere se há repetição de palpite
        if ( ( find( chutes.begin(), chutes.end(), palpite ) == chutes.end() ) and palpite.length() == 1  )
        {
            // Se é um palpite correto, exibe mensagem de acerto, adiciona a pontuação.  
            if ( carregar.palpite( palpite ) ) 
            {    
                limpaTela();

                cout << "Muito bem! A palavra contém a letra " <<  maiuscula( palpite ) << "!" << endl;
                    
                corpo( carregar );
                carregar.linhas( palpite );
                
                carregar.set_pontos( carregar.get_pontos() + 1 );

                cout << "Pontos: " << carregar.get_pontos() << endl;
                cout << "Palpite: ";

            }
            // Se é um palpite errado, exibe mensagem de erro, subtrai a pontuação.
            else 
            {
                carregar.set_tentativas_restantes( (carregar.get_tentativas_restantes() - 1) );
                
                limpaTela();
                
                cout << "Ih, a palavra não contém a letra " << maiuscula( palpite ) << "!" << endl;

                corpo( carregar );
                carregar.linhas( palpite );

                carregar.set_pontos( carregar.get_pontos() - 1 );
                
                cout << "Pontos: " << carregar.get_pontos() << endl;
                cout << "Palpite: ";
            }
        }

        // Adiciona o novo palpite ao vetor de chutes    
        chutes.push_back( palpite );
    }

    if ( carregar.game_over() )
    {
        cout << endl << "O jogo acabou, a palvra era ";
        carregar.get_palavra_atual();
    }
}

/**
 * @brief método principal responsável por inicializar o projeto
 * @author Ewerton
 * @version 1.0
 * 
 */
int main( int argc, char *argv[] ) 
{
    limpaTela();

    Forca( argv[1], argv[2] );
    
    Forca carregar;
    
    carregar.carrega_arquivos( argv[1], argv[2] );
    carregar.eh_valido();

    int opcao, dificuldade;

    telaInicial( &opcao );

    // Se opção 1, mostra opções de dificuldade e inicia o jogo.
    if( opcao == 1 )
    {
        limpaTela();

        escolheDificuldade( &dificuldade );
        
        limpaTela();        
        
        iniciaJogo(  carregar, &dificuldade );
    }

    // Se opção 2, abre o arquivo de scores.
    if( opcao == 2 )
    {
        limpaTela();
        cout << "scores" << endl;
    }

    return 0;
}