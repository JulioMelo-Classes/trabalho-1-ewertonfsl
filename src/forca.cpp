#include <fstream> //<! manipulação de arquivos
#include <sstream> //<! strinstream
#include <algorithm> //<! transform

#include "forca.hpp"

using namespace std;

/**
 * Constructor.
 */
Forca::Forca(){}

/**
 * Constructor.
 * @param palavras arquivo de palavras.
 * @param scores arquivo de scores.
 */
Forca::Forca( string palavras, string scores )
{
    m_arquivo_palavras = palavras;
    m_arquivo_scores = scores;
}

/**
 * Valida os arquivos de entrada de acordo com as especificações.
 * @return {T,""} se os arquivos estiverem válidos, mensagem de erro caso contrário.
 */
pair<bool, string> Forca::eh_valido()
{   
    for ( auto i = 0; i < m_palavras.size(); i++ ) 
    {
        bool validaPalavras = m_palavras.at(i).first.find_first_not_of
        ("aábcçdeéfghiíjklmnoópqrstuúvwxyz-ABCDEFGHIJKLMNOPQRSTUVWXYZ") != string::npos;

        if( validaPalavras ) 
        {
            cout << "O arquivo [" << m_arquivo_palavras << "] contém caracteres inválidos" << endl;
            exit(1);
        }

        if( m_palavras.at(i).second <= 0 )
        {
            cout << "[" << m_arquivo_palavras << "] não contém a frequência de palavras ou a frequência não é um número inteiro positivo" << endl;
            exit(1);
        }

        if( m_palavras.at(i).first.length() < 5 )
        {
            cout << "O arquivo [" << m_arquivo_palavras << "] contém palavras com menos de 5 letras" << endl;
            exit(1);
        }
    }

    return { true, "" };
}
/**
 * Carrega os arquivos de scores e palavras preenchendo a estrutura m_palavras.
 */
void Forca::carrega_arquivos( string palavras, string scores )
{
    m_arquivo_palavras = palavras;
    m_arquivo_scores = scores;

    cout << "Lendo arquivos de palavras [" << palavras << "] e [" << scores << "], por favor aguarde" << endl;
    cout << "-----------------------------------------------------------------------" << endl;

    int frequencia;
    string entrada, palavra;
    
    ifstream arquivo;
    arquivo.open( m_arquivo_palavras );

    if( arquivo.is_open() )
    {
        while( getline( arquivo, entrada ) ) 
        {   
            stringstream ss;
            ss << entrada;
            ss >> palavra;
            ss << entrada;
            ss >> frequencia;

            m_palavras.push_back( make_pair( palavra, frequencia ) );
        }
    }

    else
    {
        cout << "Arquivo [" << palavras << "] não existe" << endl;
        exit(1);
    }

    arquivo.close();

    arquivo.open( m_arquivo_scores );
    if( !arquivo.is_open() )
    {
        cout << "Arquivo [" << scores << "] não existe" << endl;
        exit(1);
    }

    arquivo.close();
}
/**
 * Retorna a próxima palavra de acordo com a dificuldade escolhida.
 * Atualiza o atributo m_palavra_atual e retorna a palavra atual para o sistema.
 * @return a próxima palavra do conjunto de palavras disponível de acordo com a dificuldade atual.
 */
string Forca::proxima_palavra( Dificuldade d )
{
    if( d == 1 )
    {        
        int random = ( rand() % 10 );
        if ( m_palavras.at( random ).second > 35000 )
        {
            m_palavra_atual = m_palavras.at( random ).first;
            m_palavras.at( random ).first.erase(); 
        }
    }

    if( d == 2 )
    {        
        int random = 5 + ( rand() % 10 ) + 5;
        if ( m_palavras.at( random ).second > 10000 and 
             m_palavras.at( random ).second < 35000 )
        {
            m_palavra_atual = m_palavras.at( random ).first;
            m_palavras.at( random ).first.erase();
        }
    }

    if( d == 3 )
    {        
        int random = 10 + ( rand() % 10 ) + 10;
        if ( m_palavras.at( random ).second < 10000 )
        {
            m_palavra_atual = m_palavras.at( random ).first;
            m_palavras.at( random ).first.erase();
        }
    }

    return m_palavra_atual;
}
/**
 * Retorna a palavra atual que está sendo jogada.
 * @return o valor do atributo m_palavra_atual.
 */
string Forca::get_palavra_atual()
{
    transform( m_palavra_atual.begin(), m_palavra_atual.end(), m_palavra_atual.begin(), ::toupper );

    cout << m_palavra_atual << endl;

    return m_palavra_atual;
}

/**
 * Testa se uma letra pertence á palavra atual, retorna true se a letra pertence,
 * false caso contrário.
 * @param palpite uma letra que é testada se pertence à palavra.
 * @return true se a palpite pertence à palavra, false caso contrário.
 */
bool Forca::palpite( string palpite_ )
{
    string palpite = palpite_;
    for(auto i=0; i< m_palavra_atual.length();i++)
    {    
        if( m_palavra_atual.find_first_of( palpite ) != string::npos )
            return true;
    }

    return false;
}

/**
 * Compara se as tentativas restantes chegaram a zero, se sim, retorna true, se não, retorna false.
 * @return ture caso o m_tentativas_restantes do jogo estão igual a 0, false caso contrário.
 */
bool Forca::game_over()
{
    if ( m_tentativas_restantes == 0 )
        return true;
    else
        return false;
}

/**
 * Atualiza o número de tentativas restantes.
 * @param tentativas atualiza o valor da variável m_tentativas_restantes.
 */
void Forca::set_tentativas_restantes(int tentativas_)
{
    m_tentativas_restantes = tentativas_;
}

/**
 * Retorna a quantidade de tentativas restantes.
 * @return a quantidade de tentativas restantes.
 */
int Forca::get_tentativas_restantes()
{
    return m_tentativas_restantes;
}

/**
 * Atualiza a pontuação.
 * @param pontos 
 */
void Forca::set_pontos( int pontos_ )
{
    pontos = pontos_;
}

/**
 * Retorna a pontuação.
 * @return a pontuação. 
 */
int Forca::get_pontos()
{
    return pontos;
}

void Forca::set_acertos( int acertos_ )
{
    acertos = acertos_;
}

int Forca::get_acertos()
{
    return acertos;
}

/**
 * Exibe linhas que representam a quantidade de letras da palavra e encaixa nelas os palpites corretos.
 * @param palpite letra que o jogador considera pertencer à palavra.
 * @return linhas que representam a quantidade de letras da palavra e os palpites corretos. 
 */
string Forca::linhas( string palpite_ )
{
    string caracteres;
    string palpite = palpite_;

    if ( palpite == "" ) 
    {
        for ( auto i = 0; i < m_palavra_atual.length(); i ++ )
        {
            caracteres += "_ ";
        }
    }
    else
    {   
        for ( auto i = 0; i < m_palavra_atual.length(); i ++ )
        {
            caracteres += "_ ";
        
            if ( m_palavra_atual[i] == palpite[0] )
            {
                caracteres[i] = m_palavra_atual[i];
            }        
        }
    }

    cout << caracteres << endl;
    return caracteres;
}

bool Forca::acertou( )
{
    if ( acertos == m_palavra_atual.length() ){
        corretas.push_back( m_palavra_atual );
        return true;
    }
    else
        return false;
}