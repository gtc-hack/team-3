/*
  - Two player game
  - Country capital questions
  - Different tones if you get a question wrong
  - Interactive – the robo moves towards you if you get a question right
  - It moves away from you if you get something wrong
  - The winner is the first person to get to 10 points
  - It plays music and dances for the winner
 * 
 * Circuit: Arduino Robot
 * 
 * created 4 September 2015
   by N. Awad, P. Jeyakumar, and D. Prescott
 */

#include <ArduinoRobot.h>
#include <Wire.h>
#include <SPI.h>

// Define how you want to store the questions, answers, and the right answer
// Define variables for scores
//How would you manage whose turn it is?

void setup() {
  // Initialize the Robot, SD card, speaker, and display
  // Play some song! How about the first some seconds of your national anthem? :)
}

void loop() {
   initailiseGame();
     play();
}

void initailiseGame(){
  // Print some welcoming messages...
}

void play(){
  // Show some instructions
  // Show a question and options
  // if the player gives the right answer then call the function rightAnswer() 
  // if one of the players reaches 10 points then show the player name and call the dance() function
}

void dance(){
  //Play music
  //Get the led blinking
  // Dance- rotate the robo 360degree to the right then 360degree to the left :)
}
  
void ledOn(){
 //Get the led blinking
}

void rightAnswer(){
  // Give a double beep, add 1 to the score, and move toward the player who gives the right answer
}

void wrongAnswer(){
  // Give a long beep, remove 1 from the score, and move towards the other player
}
}   
