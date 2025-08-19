#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Structures section
//whole race structure with lap numbers, current lap, 1st place driver and car
struct Race {
  int numberOfLaps;
  int currentLap;
  char firstPlaceDriverName[40];
  char firstPlaceRaceCarColour[20];
};
//raceCar structure, prepped to store driver, race car and total lap time
struct RaceCar {
  char driverName[40];
  char raceCarColour[20];
  int totalLapTime;
};

// Print functions section

//introfuction function
void printIntro(){
  printf("Welcome all! There are 7 magnificiant racers at today's Digital Monaco Grand Prix!\n");
  printf("These legendary racers that will battle it out for the Driver's Championship!\n");
};

//countdown function
void printCountdown(){
  printf("Drivers ready! In...\n");
  printf("5\n 4\n 3\n 2\n 1\n");
  printf("Aaaand we're off!\n");
};

//4 great drivers!
// struct RaceCar Mick = {"Michael Schumacher", "red Ferrari"};
// struct RaceCar Louis = {"Louis Hamilton", "black Mercedes"};
// struct RaceCar Oscar = {"Oscar Piastri", "orange McLaren"};
// struct RaceCar Max = {"Max Verstappen", "blue Redbull"};

//first place function
void printFirstPlaceAfterLap(struct Race race){
  printf("After lap 2\n");
  printf("First place is: %s in the %s car!\n", race.firstPlaceDriverName, race.firstPlaceRaceCarColour);
};

//Congratulations function for the winner
void printCongratulations(struct RaceCar raceCar1){
printf("Let's all congratulate %s in the %s car an amazing performance.\n", raceCar1.driverName, raceCar1.raceCarColour);
printf("It was truly a great race and everybody have a goodnight!");
};

int calculateTimeToCompleteLap(int speed, int acceleration, int nerves){
  speed = (rand() % 3) + 1;
  acceleration = (rand() % 3) + 1;
  nerves = (rand() % 3) + 1;
  //calculate lapt time, sum of 3 values
  return speed + acceleration + nerves;
//(rand() % 3) + 1; //random numbers between 1-3
};

void updateRaceCar(struct RaceCar* raceCar){
  int lapTime = calculateTimeToCompleteLap(0, 0, 0); //get lap time
  raceCar->totalLapTime += lapTime; //access member variable 'lapTime'
  printf("%s completed a lap in %d seconds (Total: %d)\n", raceCar->driverName, lapTime, raceCar->totalLapTime);
};
void updateFirstPlace(struct Race* racePointer, struct RaceCar* raceCar1Pointer, struct RaceCar* raceCar2Pointer, struct RaceCar* raceCar3Pointer, struct RaceCar* raceCar4Pointer){
  //find the race with the lowest lap time
  struct RaceCar* leader = raceCar1Pointer;
  if (raceCar2Pointer->totalLapTime < leader->totalLapTime){
    leader = raceCar2Pointer;
  } else if (raceCar3Pointer->totalLapTime < leader->totalLapTime){
    leader = raceCar3Pointer;
  } else if (raceCar4Pointer->totalLapTime < leader->totalLapTime){
    leader = raceCar4Pointer;
  }
  //update race structure with current leader
  strcpy(racePointer->firstPlaceDriverName, leader->driverName);
  strcpy(racePointer->firstPlaceRaceCarColour, leader->raceCarColour);
};

void startRace(struct RaceCar* raceCar1, struct RaceCar* raceCar2, struct RaceCar* raceCar3, struct RaceCar* raceCar4){
  
  //create race structure
  struct Race grandPrix ={
  .numberOfLaps = 5,
  .currentLap = 1,
  .firstPlaceDriverName = "",
  .firstPlaceRaceCarColour = "",
  };

  //simulate race
  for (int lap = 1; lap <= grandPrix.numberOfLaps; lap++){
    grandPrix.currentLap = lap;
    printf("LAP %d\n", lap);

    //each racer completes a lap
    updateRaceCar(raceCar1);
    updateRaceCar(raceCar2);
    updateRaceCar(raceCar3);
    updateRaceCar(raceCar4);

    //update and show first place
    updateFirstPlace(&grandPrix, raceCar1, raceCar2, raceCar3, raceCar4);
    printFirstPlaceAfterLap(grandPrix);
  }

  //find winner with lowest total time
  struct RaceCar* winner = raceCar1;
  if (raceCar2->totalLapTime < winner->totalLapTime) winner = raceCar2;
  if (raceCar3->totalLapTime < winner->totalLapTime) winner = raceCar3;
  if (raceCar4->totalLapTime < winner->totalLapTime) winner = raceCar4;

  printf("RACE FINISHED!\n");
  printCongratulations(*winner);

}
