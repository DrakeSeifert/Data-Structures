/* CS261- Assignment 1 - Q.5*/
/* Name: Drake Seifert
 * Date: 10/9/15
 * Solution description: I used a for loop to iterate through each letter and check if
 * it was in an even or odd place. If the letters place was divisible by two it would 
 * make it into an uppercase letter and vice versa.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

void studly(char* word){
     /*Convert to studly caps*/
     int i;
     for(i = 0; i < strlen(word); i++) {
         if(i % 2 == 0) {
     	     if(word[i] >= 'a' && word[i] <= 'z')
	         word[i] = toUpperCase(word[i]);
         }
	 else {
	     if(word[i] >= 'A' && word[i] <= 'Z')
	         word[i] = toLowerCase(word[i]);
	 }
     }
}

int main(){
    /*Read word from the keyboard using scanf*/
    char word[100];
    printf("Enter a word: ");
    scanf("%s", word);
    /*Call studly*/
    studly(word);
    /*Print the new word*/
    printf("%s\n", word);
    
    return 0;
}
