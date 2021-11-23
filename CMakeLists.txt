
cmake_minimum_required(VERSION 3.5)
project(forca VERSION 0.1 LANGUAGES CXX )


### Executável
# Diretório contendo os .hpp
include_directories( include )

# Cria um executável com nome "forca", adiciona neste executável os arquivos src/main.cpp src/forca.cpp
add_executable( forca
                src/main.cpp
                src/forca.cpp )

# The end