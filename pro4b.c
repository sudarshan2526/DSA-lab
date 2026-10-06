#include <stdio.h>
#include <stdlib.h>

void TowerofHanoi (int n,char source,char dist,char temp) {
    if(n>1){
        TowerofHanoi (n-1,source,temp,dist);
        printf("\n move %d dist form %c to %c",n,source,dist);
        TowerofHanoi(n-1,temp,dist,source);
    }
    else
        printf("\n move %d disc from %c to %c",n,source,dist);
}
int main(){
        int n;
        printf("\n Read num of disc:");
        scanf("%d",&n);
        TowerofHanoi(n,'S','D','T');
        return 0;
}
