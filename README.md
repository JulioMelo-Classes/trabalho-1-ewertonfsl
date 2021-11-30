## Como compilar o projeto (em ambiente Linux)
1. Pelo terminal, vá até a pasta do projeto, por exemplo:
```
cd Downloads/trabalho-1-ewertonfsl-master
```
2. Crie e entre na pasta build:
```
mkdir build
cd build
```
3. Execute os comandos do `cmake`, um por vez, e aguarde a conclusão do processamento para prosseguir.

3.1. 
```
cmake ..
```
3.2. 
```
cmake --build .
```

## Para executar
Você deve executar o programa com dois arquivos de entrada, o de palavras e o de scores, por exemplo:
```
./forca ../data/palavras.txt ../data/scores.txt
```


## Para executar o conjunto de testes
Ainda na pasta build, você pode copiar os comandos abaixo e executar o conjunto de testes pré-definido por mim:

```
./forca ../data/inexistente.txt ../data/inexistente.txt
./forca ../data/caracteresInvalidos.txt ../data/scores.txt
./forca ../data/frequenciaInvalida.txt ../data/scores.txt
./forca ../data/palavrasPequenas.txt ../data/scores.txt
```


## Funcionalidades não implementadas
```
3.b) sortear consoantes
para serem mostradas ao usuário.
3.c) regras para sortear palavras e sortear uma vogal para ser mostrada ao
usuário.

4. regras para acabar o jogo ao fim das palavras.

5. algumas regras de pontuação.

8.a) atualizar informações do jogo no arquivo de scores.

9. nada feito.
```

## Limitações
Tive problemas em conciliar o projeto com as outras disciplinas e o trabalho, demorei um pouco para pegar o ritmo.

# Avaliação

## Código | Funcionalidades
1. Classe forca 10/10

2. Interface textual 10/10

3. Execução completa do jogo 6/15
- Faltaram sortear as consoantes/vogais
- A forma como você implementou a dificuldade do jogo não é flexível em relação ao arquivo de entrada
- As letras acertadas desaparecem quando o usuário palpita outra letra
- Quando o usuário digita uma letra que já foi jogada, o jogo não avisa qualquer coisa

4. Validação dos arquivos de texto 3/5
- A validação está ok, vou considerar

5. Arquivos de teste de validação dos casos de erro 5/5

6. Arquivos de teste de validação dos níveis de dificuldade 3/5
- Blz, a ideia aqui era que vc adicionasse arquivos de palavras para testar o game over de cada nível, mas vc
adicionou mais de um arquivo de palavras o que já é um começo.

7. Observações gerais

## Código | Boas práticas

1. Documentação do código e readme 5/10
- Os métodos/funções implementadas não foram documentados

2. Organização e indentação 5/10
- Acho que vc poderia criar mais um .hpp pelo menos para modularizar melhor o main

3. Compilação automatizada 5/5

