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

7. nada feito.

8.a) atualizar informações do jogo no arquivo de scores.

9. nada feito.
```

## Limitações
Tive problemas em conciliar o projeto com as outras disciplinas e o trabalho, demorei um pouco para pegar o ritmo.
