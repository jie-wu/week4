#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//readprint -i inputfile -o outputfile
//readprint < inputfile > outputfile
int main(int argc, char *argv[]){
	FILE *inputfp=stdin;
	FILE *outputfp=stdout;
	char *files[2]={0,0};
	if(argc > 5){
		fprintf(stderr,"line 12 readprint -i inputfile -o outputfile\n");
		exit(0);
	}
	int i=1;
	while(i < argc){
		if( strcmp(argv[i],"-i") == 0){
			files[0]=argv[i+1];
			i+=2;
		}	
		else if(strcmp(argv[i],"-o")==0){
			files[1]=argv[i+1];
			i+=2;
		}
		else{
			fprintf(stderr,"line 26 readprint -i inputfile -o outputfile\n");
		 exit(0);
		}		
	}	
 if(files[0])fprintf(stderr,"reading in from %s\n",files[0]);
 else fprintf(stderr,"reading from stdin\n");
 if(files[1])fprintf(stderr,"writing to %s\n",files[1]);
 else fprintf(stderr,"writing to stdout\n");
 
 char buffer[4];
 char *line = malloc(sizeof(buffer)+1);
 int lineSize = sizeof(buffer)+1;
 line[0] = '\0';
 while(fgets(buffer,sizeof(buffer),inputfp)){
 	while(strlen(buffer) + strlen(line) +1 < LineSize) {
 		line = realloc(line,lineSize*2);
 		lineSize = lineSize*2;
 	}
 	strcat(line,buffer);
 	if (buffer[strlen(buffer)-1] == '\n' || strlne(buffer) < sizeof(buffer)-1) {
 		fprint(outputfp, "%s\n", line);
 		 line[0] = '\0';
 	}
 	
 }
 if(line)free(line);



 char line[4096];
 if(files[0]){
		inputfp=fopen(files[0],"r");
		if(!inputfp)exit(0);
}
if(files[1]){
	outputfp=fopen(files[1],"w");
	if(!outputfp)exit(0);
}
char *pch;
char delim[] = " \n";
pch = strotok(line, delim);
// kirk captain   1234\n
 int nRecords = 0;
 while(pch) {
 	if(nRecords %3 == 2) {
 		fprintf(outputfp,"serial number is %d\n",atoin(pch));
 	}
 	pch = strtok(0, delim);
 	nRecords++;
 }
 }
while(fgets(line,sizeof(line),inputfp)){
	//parse a line for name rank and serialnumber
	char name[4096], rank[4096];
	int serialNumber;
	if(sscanf(line,"%s %s %d", name, rank, &serialNumber) == 3) {
		fprintf(outputfp,"name is %s\n", name);
		fprintf(outputfp,"rank is %s\n", rank);
		fprintf(outputfp,"Serial number is %d\n", serialNumber);
		
	}
//	fprintf(outputfp,"%s",line);
}			
 if(inputfp!=stdin)fclose(inputfp);
 if(outputfp!=stdout)fclose(outputfp);
 return 0;
}
