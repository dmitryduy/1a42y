#include <stdio.h>
#include <regex.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char* sentence = malloc(100*sizeof(char));
    char* regex = "([A-Za-z0-9_]+)@[A-Za-z0-9_-]+: ?~ ?# (.+)";
    size_t max_group = 3;
    regex_t compRegex;
    regmatch_t groupArray[max_group];
    if (regcomp(&compRegex, regex, REG_EXTENDED)){
        return 0;
    }
    while (strcmp(sentence, "Fin.")!=0){
         fgets(sentence, 100, stdin);
        if (regexec(&compRegex, sentence, max_group, groupArray, 0) ==0){
             for(int i = 1; i<max_group; i++)
             {
                  for (int j = groupArray[i].rm_so; j< groupArray[i].rm_eo;j++) printf("%c", sentence[j]); 
                  if (i == 1) printf(" - ");
             }
        }
        
    }
    free(sentence);
    regfree(&compRegex);
    return 0;
}
