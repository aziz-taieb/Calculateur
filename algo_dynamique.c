#include <stdlib.h>
#include <stdio.h>

int max(int a,int b);
int**m_d(int n,int**tab);

int main(){
  int n,i,j;
  int **tab;
  int **resultat;
  printf("Quelle est le nombre de minute ? \n");
  scanf("%d",&n);
  tab=malloc(sizeof(int*)*2);
  tab[0]=malloc(sizeof(int)*n);
  tab[1]=malloc(sizeof(int)*n);
  for(i=0;i<n;i++){
    printf("Entrer la donnée du temps %d de la calculatrice A \n",i+1);
    scanf("%d",&tab[0][i]);
  }
  for(i=0;i<n;i++){
    printf("Entrer la donnée du temps %d de la calculatrice B \n",i+1);
    scanf("%d",&tab[1][i]);
  }
  resultat=m_d(n,tab);
  printf("La matrice M :\n");
  for(i=0;i<2;i++){
    for(j=0;j<n;j++){
      printf(" %d ",resultat[i][j]);
    }
    printf("\n");
  }
  printf("Le meilleur score possible est %d\n",max(resultat[0][n-1],resultat[1][n-1]));
  for(i=0;i<2;i++){
    free(resultat[i]);
  }
  free(resultat);
  free(tab[0]);
  free(tab[1]);
  free(tab);
}
int**m_d(int n,int**tab){
  int**m=malloc(sizeof(int*)*2);
  int*s=malloc(sizeof(int)*n);
  int i;
  for(i=0;i<2;i++){
    m[i]=malloc(sizeof(int)*n);
  }
  for(i=0;i<n;i++){
    if(i==0){//t=1
      m[0][0]=tab[0][0];
      m[1][0]=tab[1][0];
    }else if(i==1){//t=2
      m[0][1]=m[0][0]+tab[0][1];
      m[1][1]=m[1][0]+tab[1][1];
    }else{
      m[0][i]=max(m[0][i-1],m[1][i-2])+tab[0][i];
      m[1][i]=max(m[1][i-1],m[0][i-2])+tab[1][i];
    }
  }
  for(i=n-1;i>=0;i--){
    if(i==n-1){
      if(m[0][n-1]==max(m[0][n-1],m[1][n-1])){
        s[i]=0;
      }else{
        s[i]=1;
      }
    }else{
      if(s[i+1]==0){
        if(m[0][i+1]==m[0][i]+tab[0][i+1]){
          s[i]=0;
        }else{
          s[i]=2;
          }
      }else if(s[i+1]==1){
        if(m[1][i+1]==m[1][i]+tab[1][i+1]){
          s[i]=1;
        }else{
          s[i]=2;
          }
      }else{
        if(s[i+2]==0){
          s[i]=1;
        }else{
          s[i]=0;
        }
      }
    }
  }
  printf("La solution:");
  for(i=0;i<n;i++){
    if(s[i]==0)
    printf(" A ");
    if(s[i]==1)
    printf(" B ");
    if(s[i]==2)
    printf(" R ");
  }
  printf("\n");
  free(s);
  return m;
}
int max(int a,int b){
  if(a<b)
    return b;
  else
    return a;
}
