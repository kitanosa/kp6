/*
#include <stdio.h>
int main(int argc, char *argv[])
{
if(argc!=2) // если есть более чем ОДИН аргумент или нет вовсе аргементов то выведет что ты забыл.  argc всегда равен, по крайней мере, 1, поскольку имя программы квалифицируется как первый аргумент
{
printf ("You forgot to type your name\n");
return 0;
}
printf("Hello %s \n", argv[1]); // argc = 2 и argv[1] равно че надо по заданию. мол p тогда вывести таблицуесли есть ОДИН аргумент в данном случае после ./a.out 2 то тебе выведет Hello 2
printf("______________________________________________________________________________\n");

while (!feof(input))
{
fread(&buf, sizeof(student), 1, input);
if (!feof(input))
{
printf("|%-10s|%-10s|%-5d|%-2s|%-3d|%-2d|%-2d|%-2d|%-2d|%-2d|%-2d|%-2d|%-2d|%-2d|%-10s|%-2d|\n", buf.name, buf.surname, buf.extrap, buf.done, buf.age, buf.m1, buf.m2, buf.m3, buf.m4, buf.m5,buf.m6, buf.m7, buf.m8, buf.m9, buf.subject, buf.code);
return 0;
}
*/
#include <stdio.h>
#include <string.h>
#include "person.h"
// потом надо сделать чтобы по два разные параметра было. Один параметр выводил бы всех просто. Другой отборочно
/*
gcc persons_dump.c
cat database.txt | ./a.out output
gcc main.c
./a.out output app
*/
void usage(){
    printf("Usage: program filename \n");
	printf("use 'all' or 'found'\n");
}

void up(){
    printf(" ___________________________________________________________________\n");
	printf("|Фамилия:       |Процессор:       |Платформа:  |Память:  |ОС:       | \n");
}

void end(){
	printf("|               |                 |            |         |          | \n");
	printf(" ___________________________________________________________________ \n");	
}

int main(int argc, char* argv[]){
    if(argc!=3){
        usage();
        return 1;
    }
    computer pc;
    FILE *in = fopen(argv[1],"r");
    if(!in){
        perror("Can't open file. ");
        return 2;
    }
    int quantity = 0;
	if (strcmp(argv[2],"all")==0){
	    up();
	    while(fread(&pc,sizeof(pc), 1,in)==1){
			printf("|%-12s \t|%-10s\t  |%-10s  |%-8d |%-10s| \n", pc.name,pc.cpu, pc.platform, pc.video_memory ,pc.os );
			quantity++;    
	    }
		end();
    }

    else if (strcmp(argv[2],"found")==0){
	    up();
	    while(fread(&pc,sizeof(pc), 1,in)==1){
	        if(strncmp(pc.platform,"server",5)==0){ // strncmp сравнивает два слова по 5 символов
				printf("|%-12s \t|%-10s\t  |%-10s  |%-8d |%-10s| \n", pc.name,pc.cpu, pc.platform, pc.video_memory ,pc.os );
				quantity++;
	        }
	    }
		end();
    }

    if(quantity==0){
        printf("No people \n");
    }
    return 0;
}
