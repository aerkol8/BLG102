
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void oku(int wall_size){
    for(int k=0; k<wall_size; k++){
        if(k==wall_size-1){
            printf("^");
            printf("\n");
            for(int x=0; x<wall_size-1; x++)
                printf(" ");
            printf("|\n");
        }
         else if(k<wall_size)
             printf(" ");

    }
}
void okd(int wall_size){
    for(int k=0; k<wall_size; k++){
        if(k==wall_size-1){
            printf("|");
            printf("\n");
            for(int x=0; x<wall_size-1; x++)
                printf(" ");
            printf("v\n");
        }
         else if(k<wall_size)
             printf(" ");

    }
}
void duvar(int wall_size, int medium, bool end_c, char direction) {
    char wall_c;
    if (end_c)
        wall_c = '$';
    else
        wall_c = '#';
    if  (direction=='d')  
        okd(wall_size);  
    for (int i = 1; i <= wall_size; i++) {
        
        if(i!=medium && direction=='r')
            printf("  ");
        if(i==medium && direction=='r'){
            printf("->");
        }    
        for (int k = 1; k <= wall_size+1; k++) {
             if (i == wall_size || i == 1 || k == 1 || k == wall_size){
                if (!(k==wall_size+1))
                    printf("%c ",wall_c);
             }
            else if(i==medium && k==wall_size+1 && direction=='l')
                printf("<-");    
            else if (k == medium && i == medium)
                printf("A ");
            else
                printf("  ");
        }       
        printf("\n");
    }
    if (direction=='u')
    {
        oku(wall_size);
    }
    
}
int main() {
    srand(time(NULL));
    int tekrar = 0;
    int wall_size;
    char direction;
    printf("Which way do you want to go?('u' for up, 'd' for down, 'r' for right, 'l' for left): ");
    scanf(" %c",&direction);
    do {
        printf("Please enter next room wall size (the wall size can not be less than 5 and should be an odd number): ");
        scanf("%d", &wall_size);
    } while (wall_size < 5 || wall_size % 2 == 0);

    int gerekli_adim = rand() % 5 + 4;
    
    while (tekrar != gerekli_adim) {

        int medium = wall_size / 2 + 1;
        
        tekrar++;

        if (tekrar == gerekli_adim) {
            duvar(wall_size, medium, 1, direction);
            printf("Congratulations! You have reached the treasure room. Press any key to exit...");
            break;
        } else {
            if (wall_size >= 5 && wall_size % 2 == 1){
                duvar(wall_size, medium, 0, direction);
                printf("Which way do you want to go?('u' for up, 'd' for down, 'r' for right, 'l' for left): ");
                scanf(" %c",&direction);
                 do {
                    printf("Please enter next room wall size (the wall size can not be less than 5 and should be an odd number): ");
                    scanf("%d", &wall_size);
                } while (wall_size < 5 || wall_size % 2 == 0);
            }  

        }  
    }


    return 0;
}
