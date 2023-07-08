#include <stdlib.h>
#include <stdio.h>

int max(int a,int b);
int**courage(int n,int**tab,int c);
int trouver_max(int**m,int**tab,int i,int j,int c);
int*solution(int**m,int**tab,int n,int c,int mx);
int main(){
  int n,i,j,c,mx=0;
  int **tab;
  int **resultat;
  printf("Quelle est le nombre de minute ?\n");
  scanf("%d",&n);
  printf("Combien de calculateur?\n");
  scanf("%d",&c);
  tab=malloc(sizeof(int*)*c);
  for(i=0;i<c;i++){
    tab[i]=malloc(sizeof(int)*n);
  }
  for(i=0;i<c;i++){
    for(j=0;j<n;j++){
      printf("Entrez la donnée pour t=%d du tableau A%d\n",j+1,i+1);
      scanf("%d",&tab[i][j]);
    }
  }
  resultat=courage(n,tab,c);
  printf("La matrice M :\n");
  for(i=0;i<c;i++){
    for(j=0;j<n;j++){
      printf(" %d ",resultat[i][j]);
    }
    printf("\n");
  }
  for(i=0;i<c;i++){
    mx=max(mx,resultat[i][n-1]);
  }
  int*s=solution(resultat,tab,n,c,mx);
  printf("Le gain max est %d\n",mx);
  for(i=0;i<c;i++){
    free(resultat[i]);
    free(tab[i]);
  }
  printf("La solution:");
  for(i=0;i<n;i++){
    if(s[i]==-1)printf(" R ");
    else printf(" A%d ",s[i]+1);
  }
  printf("\n");
  free(s);
  free(resultat);
  free(tab);
}

int**courage(int n,int**tab,int c){
  int i,j;
  int**m=malloc(sizeof(int*)*c);
  for(i=0;i<c;i++){
    m[i]=malloc(sizeof(int)*n);
  }
  for(i=0;i<c;i++){
    m[i][0]=tab[i][0];
    m[i][1]=m[i][0]+tab[i][1];
  }
  for(i=2;i<n;i++){
    for(j=0;j<c;j++){
      m[j][i]=trouver_max(m,tab,i,j,c);
    }
  }
  return m;
}
int max(int a,int b){
  if(a<b)
    return b;
  else
    return a;
}
int trouver_max(int**m,int**tab,int i,int j,int c){
  int k,mx=0;
  for(k=0;k<c;k++){
    if(k==j){
      mx=max(mx,m[j][i-1]+tab[j][i]);
    }else{
      if(i-abs(j-k)-1>=0){
        mx=max(mx,m[k][i-abs(j-k)-1]+tab[j][i]);
      }
    }
  }
  return mx;
}
int*solution(int**m,int**tab,int n,int c,int mx){
  int*s=malloc(sizeof(int)*n);
  int k,l;
  for(int j=0;j<c;j++){
    if(m[j][n-1]==mx){
      k=j;
      s[n-1]=j;
      break;
    }
  }
  for(int i=n-1;i>=0;i--){
    for(int j=0;j<c;j++){
      if(i-abs(k-j)-1>=0&&m[k][i]==m[j][i-abs(k-j)-1]+tab[k][i]){
        l=abs(k-j);
        while(l>0){
          i--;
          s[i]=-1;
          l--;
        }
        i--;
        s[i]=j;
        k=j;
        i++;
        break;
      }
    }
  }
  return s;
}
