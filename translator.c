#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	
	FILE *f = NULL;
	FILE *o = NULL;
	char l[500], t[] = "title";
	int i,j,k,fg;
	
	f = fopen("mangalist.xml", "r");
	o = fopen("namelist.txt", "w");
	
	if(f == NULL){
		printf("ERRO trying to open Input\n");
		fclose(f);
	}
	
	if(o == NULL){
		printf("ERRO trying to create Output\n");
		fclose(o);
	}
	
	
	while(fgets(l, 500, f )){
		for(i=0;i<strlen(l);i++){
			if(l[i] == 't'){
				fg=1;
				for(j=i, k=0; j<i+5 && k<5; j++, k++){
					if(l[j] != t[k]){fg=0;}
				}
				if(fg && k==5 && l[j-12] == '<' ){
					//printf("\n%s\n",l);
					//printf("%c\n\n",l[j+10]);
					j+=10;
					while(l[j] != ']'){
						fprintf(o,"%c",l[j]);
						j++;	
					}
					fprintf(o,"\n");
				}
			}
		}
	}
	
	
	fclose(o);
	fclose(f);
	return 0;
}
