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

String   questions [][5]={{"Scotland","Edinburgh","Glasgow","Aberdeen","1"},
                  {"India","Mumbai","Delhi","Banglaore","2"},
                  {"Syria","Latakia","Aleppo","Damascus","3"}
                  };  
int numOfQuestions=3;
int key=-1;
int player1Score=0;
int player2Score=0;
int i=0;
boolean isPlayer1=true;

void setup() {
  // initialize the Robot, SD card, speaker, and display
  Robot.begin();
  Robot.beginTFT();
  Robot.beginSD();
  Robot.beginSpeaker();
  char aTinyMelody[] = "4gbag2d-4dgb2a4agab";// This is what we will play
  Robot.playMelody(aTinyMelody);// Play the melody
}

void loop() {
   initailiseGame();
     play();
}

void initailiseGame(){
  // Display Redwing Logo when you start- Commented out for memory issues
  //  Robot.drawBMP("intro.bmp", 0, 0);
  // Display a welcome text on the screen
  Robot.stroke(0,0,0);
  Robot.text("Welcome to our game!",5,5);
}

void play(){
  // Display some instructions
  Robot.stroke(0,0,0);
  Robot.text("2-player Game",5,80);
  Robot.text("All you have to do",5,100);
  Robot.text("Guess the capitals!! ",10,110);
  Robot.text("Mode-2 ",10,130);
  delay(10000);
  Robot.clearScreen();
  Robot.stroke(0, 0, 0);
  char buf[10];
  int  len=10;
  String correctAnswer="-1";
  while(i<numOfQuestions){
        questions[i][0].toCharArray(buf, len) ;
        Robot.text(buf,5,10);
        questions[i][1].toCharArray(buf, len) ;
        Robot.text(buf,10,20);
        questions[i][2].toCharArray(buf, len) ;
        Robot.text(buf,10,30);
        questions[i][3].toCharArray(buf, len) ;
        Robot.text(buf,10,40);                
       
        correctAnswer=questions[i][4];

        if (isPlayer1==true){
          Robot.text("Player1",20,120);
        }else{
          Robot.text("Player2",20,120);
        }
  
        for (int k = 0; k < 1;) {
          key = Robot.keyboardRead();
          if (key == BUTTON_MIDDLE) { 
            break;
          } else if (key == BUTTON_NONE) {
            continue;
            }
           k++;
          }
        delay(1000);
        if(key == BUTTON_UP && correctAnswer=="1")
          {
            rightAnswer();
          }
          else if (key == BUTTON_LEFT && correctAnswer=="2"){
            rightAnswer();
          }
          else if (key == BUTTON_RIGHT && correctAnswer=="3"){
            rightAnswer();
          }
          else {
            wrongAnswer();
          }                 
        i++;
        Robot.clearScreen();
        if (isPlayer1==1){
          isPlayer1=false;
        }else{
          isPlayer1=true;
        }

        if(player1Score==2){
          Robot.text("Congrats Player1",10,1000);
          dance();
          break;
         }else if(player2Score==2){
           Robot.text("Congrats Player2",10,1000);
           dance();
           break;
          }
    }
}

void dance(){
  //Play music
  Robot.playFile("melody.sqm");
  //Get the led blinking
  ledOn();
  ledOn();
  ledOn();
  // Dance :)
  Robot.motorsWrite(255,-255);
  delay(1000);
  Robot.motorsWrite(-255,255);
  delay(1000);
  Robot.motorsWrite(255,-255);
  delay(1000);
  Robot.motorsWrite(-255,255);
  delay(1000);
  Robot.motorsWrite(0,0);
  delay(5000);
}
  
void ledOn(){
  pinMode(LED1, OUTPUT);
  digitalWrite(LED1,HIGH);
  delay(1000);
  digitalWrite(LED1,LOW);
  delay(1000);
}

void rightAnswer(){
    Robot.text("TRUE",10,70);
    Robot.beep(BEEP_DOUBLE);
    if (isPlayer1==true){
        Robot.motorsWrite(150, 150);
        delay(3000);
        Robot.motorsWrite(0,0);
        player1Score++;
    }else{
        Robot.motorsWrite(-150, -150);
        delay(3000);
        Robot.motorsWrite(0,0);
        player2Score++;
    }

}

void wrongAnswer(){
    Robot.text("WRONG!!!!!!!!!!!!",10,70);
    Robot.beep(BEEP_LONG);
    if (isPlayer1==true){
        Robot.motorsWrite(+150, +150);
        delay(3000);
        Robot.motorsWrite(0,0);
        player1Score--;
    }else{
        Robot.motorsWrite(-150, -150);
        delay(3000);
        Robot.motorsWrite(0,0);
        player2Score--;
    }
}   
