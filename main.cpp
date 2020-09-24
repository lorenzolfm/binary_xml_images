#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace std;

static const char LEFT_BRACKET = '<';
static const char RIGHT_BRACKET = '>';
static const char SLASH = '/';
static char BASE_PATH[] = "assets/";

int main (int argc, char *argv[]) {
  char * file_name = argv[1]; // Nome do arquivo
  char * full_path = strcat(BASE_PATH, file_name); // assets/nomeDoArquivo
  ifstream file(full_path); // Abre arquivo

  if(!file.is_open()) { // Verifica se houve erro ao abrir o arquivo
    printf("ERROR: Unable to open file %s", full_path);
    exit(1);
  }

  string line;
  size_t tag_begin; 
  size_t tag_end;
  while(getline(file, line)) { // Enquanto tiver proxima linha, atribue para line
    for(size_t i = 0; i < line.size(); i++) { // Para caracter na linha, faça
      if(line[i] == LEFT_BRACKET) { // Se achar bracket esquerdo, guarda a posicao
        tag_begin = i;
      }

      if(line[i] == RIGHT_BRACKET) { // se for bracket direto, monta substring de tag
        tag_end = i + 1;
        string tag = line.substr(tag_begin, tag_end - tag_begin);
        printf("%s | Inicio: %zu - Fim: %zu \n\n", tag.c_str(), tag_begin, tag_end);
      }
    }
  }

  return 0;
}
