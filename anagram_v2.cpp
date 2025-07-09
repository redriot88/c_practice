#include<stdio.h>
#include<string.h>
int main() {
  int counter1[] = {0,0,0,0};
  int counter2[] = {0,0,0,0};

  char s1[] = "dbb cccccaacb cdbababdcdcdab dcdad";
  char s2[] = "bbbcc bdddccccad cdbbaaacaccdabdd";
//count characters in s1
  int len1 = strlen(s1);
  int len 2 = strlen(s2);
  for (int i = 0; i < len1; i++){
    if (s1[0] == 'a'){
      counter1[0]++;
    }
    if (s1[1] == 'b'){
      counter1[1]++;
    }
    if (s1[2] == 'c'){
      counter1[2]++;
    }
    if (s1[3] == 'd'){
      counter1[3]++;
    } 
    if (s1[i] == ' '){
      continue;
    }
  //count characters in s2
  for (int j = 0; j < len2; j++){
    if (s2[0] == 'a'){
      counter2[0]++;
    }
    if (s2[1] == 'b'){
      counter2[1]++;
    }
    if (s2[2] == 'c'){
      counter2[2]++;
    }
    if (s2[3] == 'd'){
      counter2[3]++;
    }
    if (s2[j] == ' '){
      continue;
    }
  }
  int flag = 0;
  //compare counters for the 1st 4 elements
  for (int k = 0; k < 4; k++){
    if (counter1[k] != counter2[k]){
      flag = 1;
      printf("Not Anagram!");
      break;
    }
    if (flag == 0){
      printf("Anagram!");
    }
  }
  }
}
