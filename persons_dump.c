#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "person.h"
// тупая прога которая приводит в мусор эти данные. И из мусора как то можно склепать таблицу. Ну да и похуй. Раз надо так пусть будет
/*

output это бинарный файл
*/
void usage(){
    printf("Usage: program filename \n");
}
/*
int readcomputer(computer* comp){
	return scanf("%s\t %s\t %s\t %d\n %s\t",comp->name,comp->cpu,comp->platform,&(comp->video_memory),comp->os) == 5;
}
*/
int readcomputer(computer* comp){
    int a = scanf("%s\t %s\t %s\t %d\n %s\t",comp->name,comp->cpu,comp->platform,&(comp->video_memory),comp->os) == 5;
     printf("%s\n",comp->name);
     printf("%s\n",comp->cpu);
     printf("%s\n",comp->platform);
     printf("%d\n",comp->video_memory);
     printf("%s\n",comp->os);
    return a;
}

int main(int argc, char* argv[]){
    if(argc!=2){
        usage();
        return 0;
    }
    computer pc;
    FILE* out = fopen(argv[1],"w");
    if(!out){
        perror("Can't open file");
        return 2;
    }
    while(readcomputer(&pc)){
        fwrite(&pc,sizeof(pc),1,out);
    }
    return 0;
}
