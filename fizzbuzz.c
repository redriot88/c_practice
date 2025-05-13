#include <stdio.h> //how i would solve the fizz buzz question
int main(){
for (int i = 1; i <= 100; i++){
  if (i % 15 == 0) {
  printf("FizzBuzz\n");
  continue;
  }
  if (i % 3 == 0){
    printf("Fizz\n");
    continue;
  }
  if (i % 5 == 0){
    printf("Buzz\n");
    continue;
  }
  printf("%d\n",i);
}
}
