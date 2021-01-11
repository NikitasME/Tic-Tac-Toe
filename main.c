#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Nikitas Metaxakis
    AEM: 3353
*/

void print(char table[9]){//prints the grid
    system("cls");
    printf("     x\\y  1   2   3\n");
    printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,203,205,205,205,203,205,205,205,187);
    printf("     1  %c %c %c %c %c %c %c\n",186,table[0],186,table[1],186,table[2],186);
    printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c\n",204,205,205,205,206,205,205,205,206,205,205,205,185);
    printf("     2  %c %c %c %c %c %c %c\n",186,table[3],186,table[4],186,table[5],186);
    printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c\n",204,205,205,205,206,205,205,205,206,205,205,205,185);
    printf("     3  %c %c %c %c %c %c %c\n",186,table[6],186,table[7],186,table[8],186);
    printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c\t",200,205,205,205,202,205,205,205,202,205,205,205,188);
}

void resetTable(char table[9]){
    int i;
    for(i=0;i<9;i++){
        table[i]=' ';
    }
}

char menu(){//Prints the menu and returns user's selection
    char s; //selection
    do{
        fflush(stdin);
        system("cls");
        printf("1.New single-player game\n");
        printf("2.New multi-player game\n");
        printf("3.Check player's statistics\n");
        printf("4.Exit\n");
        printf("Select one of the above(1-4):");
        scanf("%c",&s);
    }while(s!='1' && s!='2' && s!='3' && s!='4');

    return s;
}

int firstly(char table[9]){
    if(table[0]==table[1] && table[2]==' ' && table[0]!=' ') table[2]='O';
    else if(table[0]==table[2] && table[1]==' ' && table[0]!=' ') table[1]='O';
    else if(table[1]==table[2] && table[0]==' ' && table[1]!=' ') table[0]='O';
    else if(table[3]==table[4] && table[5]==' ' && table[3]!=' ') table[5]='O';
    else if(table[3]==table[5] && table[4]==' ' && table[3]!=' ') table[4]='O';
    else if(table[4]==table[5] && table[3]==' ' && table[4]!=' ') table[3]='O';
    else if(table[6]==table[7] && table[8]==' ' && table[6]!=' ') table[8]='O';
    else if(table[6]==table[8] && table[7]==' ' && table[6]!=' ') table[7]='O';
    else if(table[7]==table[8] && table[6]==' ' && table[7]!=' ') table[6]='O';
    else if(table[0]==table[3] && table[6]==' ' && table[0]!=' ') table[6]='O';
    else if(table[0]==table[6] && table[3]==' ' && table[0]!=' ') table[3]='O';
    else if(table[3]==table[6] && table[0]==' ' && table[3]!=' ') table[0]='O';
    else if(table[1]==table[4] && table[7]==' ' && table[1]!=' ') table[7]='O';
    else if(table[1]==table[7] && table[4]==' ' && table[1]!=' ') table[4]='O';
    else if(table[4]==table[7] && table[1]==' ' && table[7]!=' ') table[1]='O';
    else if(table[2]==table[5] && table[8]==' ' && table[2]!=' ') table[8]='O';
    else if(table[2]==table[8] && table[5]==' ' && table[2]!=' ') table[5]='O';
    else if(table[5]==table[8] && table[2]==' ' && table[5]!=' ') table[2]='O';
    else if(table[0]==table[4] && table[8]==' ' && table[0]!=' ') table[8]='O';
    else if(table[0]==table[8] && table[4]==' ' && table[0]!=' ') table[4]='O';
    else if(table[4]==table[8] && table[0]==' ' && table[4]!=' ') table[0]='O';
    else if(table[2]==table[4] && table[6]==' ' && table[2]!=' ') table[6]='O';
    else if(table[2]==table[6] && table[4]==' ' && table[2]!=' ') table[4]='O';
    else if(table[4]==table[6] && table[2]==' ' && table[4]!=' ') table[2]='O';
    else return 1;
    return 0;
}

char winner(char table[9]){//checks for a winner
    char w = 'N';
    int i;
    for(i=0;i<9;i+=3){
        if(table[i]==table[i+1] && table[i]==table[i+2] && table[i]!=' '){
            w = table[i];
        }

        if(table[i/3]==table[3+i/3] && table[i/3]==table[6+i/3] && table[i/3]!=' '){
            w = table[i/3];
        }

    }
    if(((table[0]==table[4] && table[4]==table[8]) || (table[2]==table[4] && table[4]==table[6])) && table[4]!=' '){
        w = table[4];
    }

    return w;
}

int score(char table[9]){
    char w = winner(table);
    if(w=='X'){
        return -1;
    }else if(w=='O'){
        return 1;
    }else{
        return 0;
    }
}

int count(char table[9],char s){//counts how many s are on the table
    int i,c=0;
    for(i=0;i<9;i++){
        c+=table[i]==s;
    }
    return c;
}

int isFull(char table[9]){//checks if the table in full
    int i;
    for(i=0;i<9;i++){
        if(table[i]==' ') return 0;
    }
    return 1;
}

int f(char table[9]){
    if(isFull(table) || winner(table)!='N'){
        return score(table);
    }else{
        int i,ii,sum = 0;
        char temp[9];
        for(i=0;i<9;i++){
            if(table[i]==' '){
                for(ii=0;ii<9;ii++){
                    temp[ii]=table[ii];
                }

                if(count(table,'X')>count(table,'O')){
                    temp[i]='O';
                }else{
                    temp[i]='X';
                }

                sum+=f(temp);
            }
        }
        return sum;
    }
}

void justPlay(char table[9]){//chooses the best move
    int i,scores[9];
    for(i=0;i<9;i++){
        if(table[i]==' '){
            table[i]='O';
            scores[i] = f(table);
            table[i] = ' ';
        }else{
            scores[i]=-28765;
        }
    }
    int max=0;
    for(i=1;i<9;i++){
        if(scores[i]>scores[max]){
            max=i;
        }
    }
    table[max]='O';
}


void playerTurn(char table[9],char s){//places s in the selected spot
    int a,b;//coordinates
    do{
        print(table);
        printf("Choose an available square(x y):");
        scanf("%d %d",&a, &b);
    }while(table[(a-1)*3+b-1]!=' '|| a<1 || a>3 || b<1 || b>3);

    table[(a-1)*3+b-1] = s;
}


int seek(char *name){//searches for the name in file
    char s=' ';
    int i,d,f=0,index=1;
    FILE *fp;
    if ((fp = fopen("Stats.txt","r"))!=NULL){
        while(!feof(fp)){
            f=1;
            i=0;
            while(s!='\n' && f && i<strlen(name)){
                fscanf(fp,"%c",&s);
                f = s==name[i];
                i++;
            }
            if(s!='\n'){
                while(s!='\n'){
                fscanf(fp,"%c",&s);
                }
            }
            if(f){
                fclose(fp);
                return index;
            }
            fscanf(fp,"%c",&s);
            fscanf(fp,"%d",&d);
            fscanf(fp,"%d",&d);
            fscanf(fp,"%d",&d);

            index++;
        }
    }
    fclose(fp);
    if(!f) return 0;
}

void updateStats(int result){
    fflush(stdin);
    printf("Name:");
    char *name = (char *)malloc(40000);
    if(name==NULL){
        printf("Error tring allocating memory\n");
    }else{
        gets(name);
        name = (char *) realloc(name,strlen(name)+1);
        int index = seek(name);
        FILE *fp;
        if((fp = fopen("Stats.txt","a+"))==NULL){
            printf("Error tring opening file\n");
            system("pause");
        }else{
            if(index){
                //make a copy of the file
                //update the indexth index
                //rewrite the file
                printf("Couldnt update file. Project under construction...");
                system("pause");
            }else{
                fseek(fp,0,SEEK_END);
                fprintf(fp,"%s\n",name);
                switch(result){
                    case 1: fprintf(fp,"%d %d %d\n",1,0,0);
                            break;
                    case 0: fprintf(fp,"%d %d %d\n",0,0,1);
                            break;
                    case -1: fprintf(fp,"%d %d %d\n",0,1,0);
                            break;
                }
            }
        }
        fclose(fp);
    }
}

void showStats(){
    char c=' ';
    char *name =(char *)malloc(100*sizeof(char));
    system("cls");
    printf("Name:");
    scanf("%s",name);
    int i,d,index = seek(name);
    if(index){
        FILE *fp;
        if((fp = fopen("Stats.txt","r"))== NULL){
            printf("Error opening file\n");
        }else{
            name = (char *) realloc(name,strlen(name)+1);
            for(i=0;i<index-1;i++){
                while(c!='\n'){
                    fscanf(fp,"%c",&c);
                }
                fscanf(fp,"%c",&c);
                fscanf(fp,"%d",&d);
                fscanf(fp,"%d",&d);
                fscanf(fp,"%d",&d);
                c = ' ';
            }
            while(c!='\n'){
                fscanf(fp,"%c",&c);
            }
            fscanf(fp,"%d",&i);
            printf("Wins: %d\n",i);
            fscanf(fp,"%d",&i);
            printf("Losses: %d\n",i);
            fscanf(fp,"%d",&i);
            printf("Draws: %d\n",i);
        }
        fclose(fp);
    }else{
        printf("Could not find this player\n");
    }
    system("pause");
}

void singlePlayerGame(char table[9]){
    while(winner(table)=='N' && !isFull(table)){
        playerTurn(table,'X');
        if(winner(table)=='X'){
            print(table);
            printf("X wins\n");
            system("pause");
            updateStats(1);
        }else if(!isFull(table)){
            if(firstly(table)) justPlay(table);
            if(winner(table)=='O'){
                print(table);
                printf("O wins\n");
                system("pause");
                updateStats(-1);
            }
        }
    }
    if(isFull(table) && winner(table)=='N'){
        print(table);
        printf("Draw\n");
        system("pause");
        updateStats(0);
    }
}

void singlePlayerGameV2(char table[9]){
    while(winner(table)=='N' && !isFull(table)){
        if(firstly(table)) justPlay(table);
        if(winner(table)=='O'){
            print(table);
            printf("O wins\n");
            system("pause");
            updateStats(-1);
        }else if(!isFull(table)){
            playerTurn(table,'X');
            if(winner(table)=='X'){
                print(table);
                printf("X wins\n");
                system("pause");
                updateStats(1);
            }
        }
    }
    if(isFull(table) && winner(table)=='N'){
        print(table);
        printf("Draw\n");
        system("pause");
        updateStats(0);
    }
}

void twoPlayerGame (char table[9]){
    while(winner(table)=='N' && !isFull(table)){
        playerTurn(table,'X');
        if(winner(table)=='X'){
            print(table);
            printf("X wins\n");
            printf("X\n");
            updateStats(1);
            printf("O\n");
            updateStats(-1);
            system("pause");
        }else if(!isFull(table)){
            playerTurn(table,'O');
            if(winner(table)=='O'){
                print(table);
                printf("O wins\n");
                system("pause");
                printf("X\n");
                updateStats(-1);
                printf("O\n");
                updateStats(1);
            }
        }
    }
    if(isFull(table) && winner(table)=='N'){
       print(table);
        printf("Draw\n");
        updateStats(0);
        updateStats(0);
        system("pause");
    }
}

int main()
{
    char table[9];
    resetTable(table);
    char s = menu();
    while(s!='4'){
        if(s=='1'){
            int x;
            do{
                printf("Do you want to play 1st or 2nd?(1 or 2):");
                scanf("%d",&x);
            }while(x!=1 && x!=2);

            if(x-1)singlePlayerGameV2(table);
            else singlePlayerGame(table);

        }else if(s=='2'){
            twoPlayerGame(table);
        }else{
            showStats();
        }

        resetTable(table);
        s = menu();
    }

    return 0;
}
