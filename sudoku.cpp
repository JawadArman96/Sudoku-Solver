#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
int ans_x[200];
int ans_y[200];
int fina=0;
class matrix{
public:
    int column[10];
};
matrix arr[10];
int check_quad(int r,int c,int num,matrix *arra){
    int st_r,en_r,st_c,en_c;
    if(r<4){st_r=1;en_r=3;}
    else if(r>3 && r<7){st_r=4;en_r=6;}
    else if(r>6){st_r=7;en_r=9;}

    if(c<4){st_c=1;en_c=3;}
    else if(c>3 && c<7){st_c=4;en_c=6;}
    else if(c>6){st_c=7;en_c=9;}

    for(int i=st_r;i<=en_r;i++){
        for(int j=st_c;j<=en_c;j++){
            if(arra[i].column[j]==num && !(i==r && j==c)) {
                //printf("%d %d 3--\n",i,j);
                return 0;
            }
        }
    }
    return 1;
}

int check_if_valid(int r,int c,int num,matrix *arra){
    for(int i=1;i<10;i++) {
        if(arra[i].column[c]==num && i!=r) {return 0;}
        if(arra[r].column[i]==num && i!=c) {return 0;}
    }
    int p=check_quad(r,c,num,arra);
    return p;
}
int make(matrix *arra,int ro,int co){
    if(fina) return 1;
    int filled=1;
    for(int i=1;i<10;i++)for(int j=1;j<10;j++){
        if(arra[i].column[j]==0) filled=0;
    }
    if(filled) {
        printf("Solution is:\n");
        for(int i=1;i<10;i++){
            for(int j=1;j<10;j++) printf("%d ",arra[i].column[j]);
            printf("\n");
        }
        //printf("-------\n");

    int A=arra[ans_x['A']].column[ans_y['A']];
    int B=arra[ans_x['B']].column[ans_y['B']];
    int C=arra[ans_x['C']].column[ans_y['C']];
    int D=arra[ans_x['D']].column[ans_y['D']];

    // printf("A %d,B %d,C %d,D %d\n",A,B,C,D);

            fina=1;return 1;
    }
    if(ro>9) return 1;
    matrix arra1[10];
    for(int i=1;i<10;i++)for(int j=1;j<10;j++){
        arra1[i].column[j]=arra[i].column[j];
    }
    //if(ro==9 && co==9) cout<<"this is\n";
    if(arra1[ro].column[co]==0) {
        for(int i=1;i<10;i++){
            if(!check_if_valid(ro,co,i,arra1)) continue;
            arra1[ro].column[co]=i;
            int a,b;
            if(co<9) {a=ro;b=co+1;}
            else {a=ro+1;b=1;}
            make(arra1,a,b);
        }
    }
    else {
        int a,b;
        if(co<9) {a=ro;b=co+1;}
        else {a=ro+1;b=1;}
        make(arra1,a,b);
    }
    return 1;
}
int main(){
    freopen("sudoku.txt","r",stdin);

    //freopen("output.txt","w",stdout);
    char p;
    for(int i=1;i<10;i++)
        for(int j=1;j<10;j++) {
            scanf(" %c",&p);
            if(p=='A' || p=='B' || p=='C' || p=='D') {
                //printf("%c\n",p);
                ans_x[p]=i;
                ans_y[p]=j;
                p=0;
            }
            else p=p-'0';
            arr[i].column[j]=p;
    }
    //cout<<check_if_valid(9,9,9,arr);
    make(arr,1,1);
}
