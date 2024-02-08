
#include <stdio.h>
#include "libs/libbmp.h"
#include "libs/imghelpers.h"

int main(){
  //Utilize apenas imagens .bmp com o formato 24 (true color)
  // converta em: https://online-converting.com/image/convert2bmp/
  bmp_img img;
  char filename[] = "lenna.bmp";
  printf("\n");
  IMG_TAM t = pegarTamanho(filename);
  int l = t.qtdLinhas,c = t.qtdColunas;
  int R[l][c];
  int G[l][c];
  int B[l][c];
  carregaImagem(t,R,G,B,filename);
  
//Nosso filtro

  for(int i=0;i<l;i++){
    for(int j=0;j<c;j++){

      // Moldura com centro preto e branco

      
      if(i > 60 && j > 60 && i < c-60 && j < l-60){    
        
        if(B[i][j]>G[i][j] && B[i][j]>R[i][j]){
        B[i][j] += 255;
      }
      else{
        R[i][j] = R[i-l][j+5]; 
        G[i][j] = R[i-l][j];
        B[i][j] = R[i-l][j+5];
      }
         // R[i-l][j+5] = R[i][j];
         // G[i-l][j-5] = G[i][j];
         // B[i-l][j] = B[i][j];
      }
       
      // //Linha de cima externa 
      if (i < 30) {

        R[i][j] += 150;
        G[i][j] += 75;
        B[i][j] += 0;
        
      }

      // //Linha de cima interna
      if ((i >= 30 && i <= 60) && (j >= 30 && j <=  l - 30)) {

        R[i][j] += 150;
        G[i][j] += 0;
        B[i][j] += 0;
        
      }

      // //Linha da esquerda externa 
      if (j < 30) {

        R[i][j] += 0;
        G[i][j] += 150;
        B[i][j] += 0;
        
      }

      // //Linha da esquerda interna
      if ((i >= 30 && i <=  c - 30) && (j >= 30 && j <= 60)) {

        R[i][j] += 0;
        G[i][j] += 0;
        B[i][j] += 150;
        
      }

      // //Linha de baixo externa 
      if (i > c-30) {

        R[i][j] += 150;
        G[i][j] += 0;
        B[i][j] += 0;
        
      }

      // //Linha de baixo interna
      if((i <= c - 30 && i >= c - 60) && (j >= 30 && j <= l - 30)) {

        R[i][j] += 150;
        G[i][j] += 75;
        B[i][j] += 0;
        
      }

      // //Linha da direita externa 
      if (j > l-30) {

        R[i][j] += 0;
        G[i][j] += 0;
        B[i][j] += 150;

        
      }

      // //Linha da direita interna
      if ((i >= 30 && i <= c - 30) && (j <= l - 30 && j >= l - 60)) {

        R[i][j] += 0;
        G[i][j] += 150;
        B[i][j] += 0;
        
      }

     }
    printf("\n");
  }



  salvaImagem(t,R,G,B,"saida.bmp");
  mostrarNoReplit("saida.bmp");
  return 0;
}