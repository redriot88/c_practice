#include<stdio.h>
#include<string.h>
 
void copy(char* dst, char* src){ //creating copy function
  while(*src != '\0') {
    *dst = *src; //dereference both
    dst++;//increment by 1
    src++;//increment by 1
  }
  *dst = '\0';//once src = 0; dst needs to = 0
}
 
int main(){
  char srcString[] = "We promptly judged antique ivory buckles for the next prize!";
  
  char dstString[100]; //declared
  copy(dstString, srcString);
 
  printf("%s\n", dstString);
  return 0;
}
