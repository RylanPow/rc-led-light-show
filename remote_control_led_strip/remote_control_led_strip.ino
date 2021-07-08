#include "IRremote.h"
#include <FastLED.h>
#include <Wire.h>
#include "Adafruit_TCS34725.h" 

#define LED_PIN 12
#define NUM_LEDS 60

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);


int receiver = 11; // pin 1 of IR receiver to Arduino digital pin 11
IRrecv irrecv(receiver);           // create instance of 'irrecv'
decode_results results;            // create instance of 'decode_results'

CRGB leds[NUM_LEDS];
void setup() {
  // IR set up
  Serial.begin(9600);
  Serial.println("IR Receiver Data and button IDs");
  irrecv.enableIRIn(); // Start the receiver
  // LED set up
  FastLED.addLeds<WS2812, LED_PIN, RGB>(leds, NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 500);
  FastLED.clear();
  FastLED.show();
  }

void loop() {
  if (irrecv.decode(&results)) //if IR signal received

  {
    Serial.println(results.value, HEX); 

    translateIR(); 
    irrecv.resume(); // receive next value
  }  

}

void translateIR(){ // takes action based on IR code received
  switch(results.value){

  case 0xFFA857:  
    break;
    Serial.println(" VOL+"); 
    break;

   case 0xFF42BD:  //The Lightshow!  Button 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7
   for(int i = 0; i < 60; i++) {
  
    //Varying color, one loop
    leds[i] = CRGB(0, 4*i, 255-i);
    FastLED.setBrightness(50);
 
    delay(abs(30-i));
    FastLED.show();
  } 
     


  //Sections of solid colors(halves, thirds, fourths)
  for (int i=0; i<NUM_LEDS/2; i++) { //green, red, blue
    leds[i] = CRGB(0, 255, 0);
    FastLED.setBrightness(50);
    FastLED.show();
    delay(10);
  }  
  for (int i = 30; i < NUM_LEDS; i++) {
    leds[i] = CRGB(255, 255, 255);
    FastLED.show();
    delay(10);
  }
    delay(350);
  for (int i = 0; i < NUM_LEDS/3; i++) {
    leds[i] = CRGB(255, 0, 0);
    FastLED.show();
    delay(10);
  }
  for (int i = 20; i < 40; i++) {
    leds[i] = CRGB(50, 0, 255);
    FastLED.show();
    delay(10);
  }
  for (int i = 40; i < 60; i++) {
    leds[i] = CRGB(0, 255, 0);
    FastLED.show();
    delay(10);
  }
    delay(250);
    for (int i = 0; i <15; i++) {
    leds[i] = CRGB(150, 255, 0);
    FastLED.show();
    delay(10);
  }
   for (int i = 15; i < 30; i++) {
    leds[i] = CRGB(0, 0, 255);
    FastLED.show();
    delay(10);
  }
   for (int i = 30; i <45; i++) {
    leds[i] = CRGB(0, 175, 255);
    FastLED.show();
    delay(10);
  }
  for(int i = 45; i<60; i++) {
    leds[i] = CRGB(255, 0, 0);
    FastLED.show();
    delay(10);
  }
  delay(250);


  //Random color loops 
  for (int i=0; i <= NUM_LEDS; i++) {
 
    leds[i] = CRGB(random(random(255)), random(random(255)), random(random(255)));
    FastLED.setBrightness(50);
    
    FastLED.show();
    delay(12);
   }
  
   for(int k = 0; k <= NUM_LEDS; k++) {
    leds[k] = CRGB(255, 0, 0); //setting each rgb value to random(255) produced white light much of the time.  
    FastLED.show();          //what really gets the random lights is for the UPPER LIMIT for each possible
    delay(5);               //random RGB value to ALSO be random!
   }
    for (int i=0; i <= NUM_LEDS; i++) {
 
    leds[i] = CRGB(random(random(255)), random(random(255)), random(random(255)));
    FastLED.setBrightness(50);
    
    FastLED.show();
    delay(12);
   }

   for(int k = 0; k <= NUM_LEDS; k++) {
    leds[k] = CRGB(0, 255, 255); //setting each rgb value to random(255) produced white light much of the time.  
    FastLED.show();          //what really gets the random lights is for the UPPER LIMIT for each possible
    delay(5);               //random RGB value to ALSO be random!
   }
    for (int i=0; i <= NUM_LEDS; i++) {
  
    leds[i] = CRGB(random(random(255)),random(random(255)), random(random(255)));
    FastLED.setBrightness(50);
    
    FastLED.show();
    delay(12);
   }
   
   for(int k = 0; k <= NUM_LEDS; k++) {
    leds[k] = CRGB(0, 0, 255); //setting each rgb value to random(255) produced white light much of the time.  
    FastLED.show();          //what really gets the random lights is for the UPPER LIMIT for each possible
    delay(5);               //random RGB value to ALSO be random!
   }
    for (int i=0; i <= NUM_LEDS; i++) {
  
    leds[i] = CRGB(random(random(255)), random(random(255)), random(random(255)));
    FastLED.setBrightness(50);
    
    FastLED.show();
    delay(12);
   }
 
   for(int k = 0; k <= NUM_LEDS; k++) {
    leds[k] = CRGB(100, 255, 0); //setting each rgb value to random(255) produced white light much of the time.  
    FastLED.show();          //what really gets the random lights is for the UPPER LIMIT for each possible
    delay(5);               //random RGB value to ALSO be random!
   }





  //Rotating "segment" of light
  
  for (int i=0; i <= NUM_LEDS; i++) {
   int a1 = random(0, random(255));
   int b1 = random(0, random(255));
   int c1 = random(0, random(255));
    leds[i] = CRGB(a1, b1, c1);
    FastLED.setBrightness(50);
    
    FastLED.show();
    delay(5);
   }
   for(int i = 0; i < 60; i++) {
    leds[i] = CRGB(0, 0, 0);
    FastLED.show();
   }
   
   
  
   for (int i = 0; i <= NUM_LEDS; i++) {
     int w = 20;
      FastLED.setBrightness(50);
      leds[i] = CRGB(255, 0, 0);
      leds[i-1] = CRGB(255, 0, 0);
      leds[i-2] = CRGB(255, 0, 0);
      FastLED.show();
      delay(5);
      leds[i] = CRGB(w, w, w);
      leds[i-1] = CRGB(w, w, w);
      leds[i-2] = CRGB(w, w, w);
    }
    for (int k = 57; k > 0; k--) {
      FastLED.setBrightness(50);
      leds[k] = CRGB(0, 255, 0);
      leds[k+1] = CRGB(0, 255, 0);
      leds[k+2] = CRGB(0, 255, 0);
      FastLED.show();
      delay(5);
       int w = 20;
      //leds[k] = CRGB(w, w, w);
      leds[k+1] = CRGB(w, w, w);
      //leds[k+2] = CRGB(w, w, w);
    }
    
     for (int i = 0; i <= NUM_LEDS; i++) {
      FastLED.setBrightness(50);
      leds[i] = CRGB(0, 0, 255);
      leds[i-1] = CRGB(0, 0, 255);
      leds[i-2] = CRGB(0, 0, 255);
      FastLED.show();
      delay(5);
       int w = 20;
      leds[i] = CRGB(w, w, w);
      leds[i-1] = CRGB(w, w, w);
      leds[i-2] = CRGB(w, w, w);
    }
     for (int k = 57; k > 0; k--) {
      FastLED.setBrightness(50);
      leds[k] = CRGB(0, 255, 100);
      leds[k+1] = CRGB(0, 255, 100);
      leds[k+2] = CRGB(0, 255, 100);
      FastLED.show();
      delay(5);
       int w = 20;
      leds[k] = CRGB(w, w, w);
      leds[k+1] = CRGB(w, w, w);
      leds[k+2] = CRGB(w, w, w);
    }
     for (int i = 0; i <= NUM_LEDS; i++) {
      FastLED.setBrightness(50);
      leds[i] = CRGB(75, 255, 0);
      leds[i-1] = CRGB(75, 255, 0);
      leds[i-2] = CRGB(75, 255, 0);
      FastLED.show();
      delay(5);
       int w = 20;
      leds[i] = CRGB(w, w, w);
      leds[i-1] = CRGB(w, w, w);
      leds[i-2] = CRGB(w, w, w);
    }

    
    for(int j = 0; j < 5; j++) {
      for(int j = 0; j < 52; j++) {
        leds[j] = CRGB(random(random(255)), random(random(255)), random(random(255)));
        leds[j+8] = CRGB(random(random(255)), random(random(255)), random(random(255)));
        leds[j-1] = CRGB(0, 0, 0);
        FastLED.setBrightness(50);
        FastLED.show();
        delay(5);
      }
      for(int i = 51; i < 61; i++) {
        leds[i] = CRGB(0, 0, 0);
        FastLED.show();
        delay(5);
      }

    }



   //Rotating solid colors.  First type causes lights 0-30 AND 30-60 to become the SAME color at the same time,
   //so the 60 lights are not 50/50 colors 1 and 2.  Second type iterates 0-30 color 1 and 30-60 color 2, and since
   //they increment at the same time, it gives the illusion of 2 rotating half circles!
   for(int i = 0; i < 3; i++) {
     for(int i = 0; i < 30; i++) {
      leds[i] = CRGB(0,255,0);
      leds[i+30] = CRGB(0, 255, 0);
      FastLED.show();
      delay(12);
    }
      for(int j = 0; j < 30; j++) {
        leds[j] = CRGB(255, 255, 255);
        leds[j+30] = CRGB(255, 255, 255);
        FastLED.setBrightness(50);
        FastLED.show();
        delay(12);
      }
   }


                                 
   for(int i = 0; i < 4; i++) {               
      for(int j = 0; j < 30; j++) {
        leds[j] = CRGB(0, 255, 0);
        leds[j+30] = CRGB(255, 255, 255);
        FastLED.setBrightness(50);
        FastLED.show();
        delay(12);
      }
   for(int j = 0; j < 30; j++) {
        leds[j] = CRGB(255, 255, 255);
        leds[j+30] = CRGB(0, 255, 0);
        FastLED.setBrightness(50);
        FastLED.show();
        delay(12);
      }
      
   }

     for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 30; j++) {
        leds[j] = CRGB(255, 0, 0);
        leds[j+30] = CRGB(0, 0, 255);
        FastLED.setBrightness(50);
        FastLED.show();
        delay(12);
      }
   for(int j = 0; j < 30; j++) {
        leds[j] = CRGB(0, 0, 255);
        leds[j+30] = CRGB(255, 0, 0);
        FastLED.setBrightness(50);
        FastLED.show();
        delay(12);
      }
      
   }

   for(int i = 0; i < 2; i++) {
     for(int i = 0; i < 30; i++) {
      leds[i] = CRGB(120,255,0);
      leds[i+30] = CRGB(120, 255, 0);
      FastLED.show();
      delay(12);
    }
      for(int j = 0; j < 30; j++) {
        leds[j] = CRGB(0, 255, 255);
        leds[j+30] = CRGB(0, 255, 255);
        FastLED.setBrightness(50);
        FastLED.show();
        delay(12);
      }
   }
   



   
   //  for(int i = 0; i < 3; i++) {
      for(int j = 60; j >= 30; j--) {
        leds[j] = CRGB(0, 0, 255);
        leds[60-j] = CRGB(0, 0, 255);
        FastLED.setBrightness(50);
        FastLED.show();
        delay(12);
      }

       for(int j = 60; j >= 30; j--) {
        leds[j] = CRGB(0, 255, 0);
        leds[60-j] = CRGB(0, 255, 0);
        FastLED.setBrightness(50);
        FastLED.show();
        delay(12);
      }

        for(int j = 60; j >= 30; j--) {
        leds[j] = CRGB(255, 0, 0);
        leds[60-j] = CRGB(255, 0, 0);
        FastLED.setBrightness(50);
        FastLED.show();
        delay(12);
      }
      //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
      for(int i = 0; i < 2; i++) {
       for(int j = 60; j >= 30; j--) {
        leds[j] = CRGB(0, 0, 255);
        leds[60-j] = CRGB(100, 200, 0);
        FastLED.setBrightness(50);
        FastLED.show();
        delay(12);
      }

       for(int j = 60; j >= 30; j--) {
        leds[j] = CRGB(255, 0, 255);
        leds[60-j] = CRGB(0, 255, 0);
        FastLED.setBrightness(50);
        FastLED.show();
        delay(12);
      }

        for(int j = 60; j >= 30; j--) {
        leds[j] = CRGB(255, 0, 0);
        leds[60-j] = CRGB(0, 255, 255);
        FastLED.setBrightness(50);
        FastLED.show();
        delay(12);
      }
      }

      for(int i = 0; i < 25; i++) {
        for(int j = 0; j < 60; j++) { 
        leds[j] = CRGB(random(random(255)),random(random(255)),random(random(255)));
        FastLED.setBrightness(50);
      }
      FastLED.show();
      delay(120);
      }
      for(int i = 60; i > 0; i--) {
        leds[i] = CRGB(255, 255, 255);
        FastLED.show();
        delay(15);
      }
    
    
    ////////////////////////////////////////////////////////////////////////////////////////////////// 7777777777777777777777777777777
    
    Serial.println(" 7              "); 
    break;





    
  case 0xFF906F:  
    Serial.println(" UP ARROW"); //rotating solid lights
   
   for(int i = 0; i < 3; i++) {
     for(int i = 0; i < 30; i++) {
      leds[i] = CRGB(0,255,0);
      leds[i+30] = CRGB(0, 255, 0); 
      FastLED.show();
      delay(12);
    }
      for(int j = 0; j < 30; j++) {
        leds[j] = CRGB(255, 255, 255);
        leds[j+30] = CRGB(255, 255, 255);
        FastLED.setBrightness(50);
        FastLED.show();
        delay(12);
      }
   }
   //The pattern above does not actually cause the 2 solid colors to rotate!  It causes the first color to start at index 0 and separately at
   //index 30, then they both separately iterate up to 30 and 60, meaning the ratio of color 1 and color 2 aren't always 50/50.
   
                           
   for(int i = 0; i < 2; i++) {
      for(int j = 0; j < 30; j++) {
        leds[j] = CRGB(0, 255, 0);
        leds[j+30] = CRGB(255, 255, 255);
        FastLED.setBrightness(50);
        FastLED.show();
        delay(12);
      }
   for(int j = 0; j < 30; j++) {
        leds[j] = CRGB(255, 255, 255);
        leds[j+30] = CRGB(0, 255, 0);
        FastLED.setBrightness(50);
        FastLED.show();
        delay(12);
      }
      
   } //having the iteration at j and j+30 be different colors means each colors will iterate "after each other", giving the 
     //appearance of heaving 2 spinning solid colors.

     for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 30; j++) {
        leds[j] = CRGB(255, 0, 0);
        leds[j+30] = CRGB(0, 0, 255);
        FastLED.setBrightness(50);
        FastLED.show();
        delay(12);
      }
   for(int j = 0; j < 30; j++) {
        leds[j] = CRGB(0, 0, 255);
        leds[j+30] = CRGB(255, 0, 0);
        FastLED.setBrightness(50);
        FastLED.show();
        delay(12);
      }
      
   }

   for(int i = 0; i < 2; i++) {
     for(int i = 0; i < 30; i++) {
      leds[i] = CRGB(120,255,0);
      leds[i+30] = CRGB(120, 255, 0);
      FastLED.show();
      delay(12);
    }
      for(int j = 0; j < 30; j++) {
        leds[j] = CRGB(0, 255, 255);
        leds[j+30] = CRGB(0, 255, 255);
        FastLED.setBrightness(50);
        FastLED.show();
        delay(12);
      }
   }
   



   
   //  for(int i = 0; i < 3; i++) {
      for(int j = 60; j >= 30; j--) {
        leds[j] = CRGB(0, 0, 255);
        leds[60-j] = CRGB(0, 0, 255);
        FastLED.setBrightness(50);
        FastLED.show();
        delay(12);
      }

       for(int j = 60; j >= 30; j--) {
        leds[j] = CRGB(0, 255, 0);
        leds[60-j] = CRGB(0, 255, 0);
        FastLED.setBrightness(50);
        FastLED.show();
        delay(12);
      }

        for(int j = 60; j >= 30; j--) {
        leds[j] = CRGB(255, 0, 0);
        leds[60-j] = CRGB(255, 0, 0);
        FastLED.setBrightness(50);
        FastLED.show();
        delay(12);
      }
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
      for(int i = 0; i < 2; i++) {
       for(int j = 60; j >= 30; j--) {
        leds[j] = CRGB(0, 0, 255);
        leds[60-j] = CRGB(100, 200, 0);
        FastLED.setBrightness(50);
        FastLED.show();
        delay(12);
      }

       for(int j = 60; j >= 30; j--) {
        leds[j] = CRGB(255, 0, 255);
        leds[60-j] = CRGB(0, 255, 0);
        FastLED.setBrightness(50);
        FastLED.show();
        delay(12);
      }

        for(int j = 60; j >= 30; j--) {
        leds[j] = CRGB(255, 0, 0);
        leds[60-j] = CRGB(0, 255, 255);
        FastLED.setBrightness(50);
        FastLED.show();
        delay(12);
      }
      }


      for(int i = 0; i < 25; i++) {
        for(int j = 0; j < 60; j++) { 
        leds[j] = CRGB(random(random(255)),random(random(255)),random(random(255)));
        FastLED.setBrightness(50);
      }
      FastLED.show();
      delay(120);
      } 
      //the 2 separate colors coalesce towards the middle with these looops
      break;

  case 0xFFA25D: //Back up remote
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB(255, 0, 0);
      FastLED.setBrightness(20);
      FastLED.show();
      delay(10);
    }
    break;
   case 0xFF629D: //Back up remote
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB(0, 255, 0);
      FastLED.setBrightness(20);
      FastLED.show();
      delay(10);
    }
    break;
   case 0xFFE21D: //Back up remote
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB(0, 0, 255);
      FastLED.setBrightness(20);
      FastLED.show();
      delay(10);
    }
    break;
  
  case 0xFF6897: //this one turns off all the lights
   Serial.println(" 0 ");   
   for (int i=0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(0, 0, 0);
    FastLED.setBrightness(0);
    FastLED.show();
    delay(10);
  }
    
    break;

 



  case 0xFF30CF: 
  Serial.println(" 1 "); 
  for (int i=0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(255, 0, 255);
    FastLED.setBrightness(i);
    FastLED.show();
    delay(40);
  }
  for (int i=NUM_LEDS; i>0; i--) {
    leds[i] = CRGB(255-20*i, 5*i, 255-40*i);
    FastLED.setBrightness(75-2*i);
    FastLED.show();
    delay(20);
  }  
 
    break;
    
  
  case 0xFF18E7:
  Serial.println("2"); //Christmas lights!  Alternating red and green interlace
  for(int k = 0; k < 9; k++) {
  for(int i = 0; i < 60; i+=2) {
    FastLED.setBrightness(12);
    leds[i] = CRGB(0, 255, 0);
  }
  delay(150);
  for(int i = 1; i < 60; i+=2) {
    FastLED.setBrightness(12);
    leds[i] = CRGB(255, 0, 0);   
  }
  FastLED.show();
   delay(150);
   for(int i = 0; i < 60; i+=2) {
    FastLED.setBrightness(40);
    leds[i] = CRGB(255, 0, 0);
  }
  delay(150);
  for(int i = 1; i < 60; i+=2) {
    FastLED.setBrightness(40);
    leds[i] = CRGB(0, 255, 0);
  }
  FastLED.show();
  delay(150);
  }
   break;





  case 0xFF7A85:  //random random lights and solid light segments
     for (int i=0; i <= NUM_LEDS; i++) {
    Serial.println(" 3 "); 
    leds[i] = CRGB(random(random(255)), random(random(255)), random(random(255)));
    //using CRBG(random(255), random(255), random(255)); causes all 3 RGB values to, on average, come out to be too
    //close to each other, causing the strip to look mostly white.  The workaround here is to not use random(255),
    //but to use random(random(255))!  This creates a random, maximum value for which the maximum value of the 
    //random value determing the R/G/B can be, resulting in DISTINCTLY different colors! :D
    
    FastLED.setBrightness(40);
    FastLED.show();
    delay(12);
  }
  for (int i=0; i<NUM_LEDS/2; i++) { //green, red, blue
    leds[i] = CRGB(255, 50, 0);
    FastLED.setBrightness(40);
    FastLED.show();
    delay(10);
  }  
  for (int i = 30; i < NUM_LEDS; i++) {
    leds[i] = CRGB(50, 255, 0);
    FastLED.show();
    delay(10);
  }
  for (int i = 0; i < NUM_LEDS/2; i++) {
    leds[i] = CRGB(0, 50, 255);
    FastLED.show();
    delay(10);
  }
  for (int i = 30; i < NUM_LEDS; i++) {
    leds[i] = CRGB(50, 255, 50);
    FastLED.show();
    delay(10);
  }
  for (int i = 0; i < NUM_LEDS/2; i++) {
    leds[i] = CRGB(255, 255, 0);
    FastLED.show();
    delay(10);
  }
  for (int i = 30; i < NUM_LEDS; i++) {
    leds[i] = CRGB(50, 0, 255);
    FastLED.show();
    delay(10);
  }
  for (int i = 0; i < NUM_LEDS/2; i++) {
    leds[i] = CRGB(0, 255, 0);
    FastLED.show();
    delay(10);
  }
    for (int i = 30; i < NUM_LEDS/2; i++) {
    leds[i] = CRGB(255, 0, 50);
    FastLED.show();
    
    delay(10);
  }
    break;




  case 0xFF10EF: //"Sporadic" white lights 
   Serial.println(" 4  "); 
   FastLED.setBrightness(25);
   for(int j=0; j <= 15; j++) {
   for (int i=0; i <= NUM_LEDS; i++) {
   int a = random(random(255));
    leds[i] = CRGB(a, a, a);
   }
   FastLED.show();
   delay(100);
   }
    break;






  case 0xFF38C7: //Purple is a pretty color
  Serial.println(" 5 "); 
  for (int i=0; i <= NUM_LEDS; i++) {
    leds[i] = CRGB(0, 75, 255);
    FastLED.setBrightness(75);
    FastLED.show();
    delay(15);
   }
   for (int i=0; i<=NUM_LEDS/4; i++) {
    leds[i] = CRGB(255, 0, 0);
    FastLED.setBrightness(75);
    FastLED.show();
    delay(10);
   }  
    for (int i=NUM_LEDS/4; i<=NUM_LEDS/2; i++) {
    leds[i] = CRGB(0, 255, 0);
    FastLED.setBrightness(75);
    FastLED.show();
    delay(10);
   }  
   
    for (int i=NUM_LEDS/2; i<= 0.75*NUM_LEDS; i++) {
    leds[i] = CRGB(255, 255, 0);
    FastLED.setBrightness(75);
    FastLED.show();
    delay(10);
    }
     for (int i= 0.75*NUM_LEDS; i <= NUM_LEDS; i++) {
    leds[i] = CRGB(0, 255, 255);
    FastLED.setBrightness(75);
    FastLED.show();
    delay(10);
     }
    for (int i= 0; i < NUM_LEDS; i+= 2) {
    leds[i] = CRGB(255, 255 , 255);
    FastLED.setBrightness(75);
    FastLED.show();
    delay(25);
    }

    break;



  case 0xFF5AA5:  //Random Color test: write the show() after a loop so all the relevant LEDs change at oncce, instead of one by one
  Serial.println(" 6              "); 
  for (int j=0; j < 4; j++) {
  for (int i=0; i <= NUM_LEDS; i++) {
   int a1 = random(0, random(255));
   int b1 = random(0, random(255));
   int c1 = random(0, random(255));
    leds[i] = CRGB(a1, b1, c1);
    FastLED.setBrightness(25);
    
    FastLED.show();
    delay(15);
   }
   int a = random(0, random(255));
   int b = random(0, random(255));
   int c = random(0, random(255));
   for(int k = 0; k <= NUM_LEDS; k++) {
    leds[k] = CRGB(a, b, c); //setting each rgb value to random(255) produced white light much of the time.  
    FastLED.show();          //what really gets the random lights is for the UPPER LIMIT for each possible
    delay(12);               //random RGB value to ALSO be random!
   }
  }
  for (int i=0; i <= NUM_LEDS; i++) {
   int a1 = random(0, random(255));
   int b1 = random(0, random(255));
   int c1 = random(0, random(255));
    leds[i] = CRGB(a1, b1, c1);
    FastLED.setBrightness(25);
    
    FastLED.show();
    delay(12);
   }
    break;


    




  case 0xFF4AB5:  
    
    for(int j = 0; j < 5; j++) {
    for (int i = 2; i <= NUM_LEDS; i++) {
      FastLED.setBrightness(50);
      leds[i] = CRGB(random(random(255)), random(random(255)), random(random(255)));
      leds[i-1] = CRGB(random(random(255)), random(random(255)), random(random(255)));
      leds[i-2] = CRGB(random(random(255)), random(random(255)), random(random(255)));
      leds[i-3] = CRGB(random(random(255)), random(random(255)), random(random(255)));
      leds[i-4] = CRGB(random(random(255)), random(random(255)), random(random(255)));
      FastLED.show();
      delay(9);
      leds[i] = CRGB(0, 0, 0);
      leds[i-1] = CRGB(0, 0, 0);
      leds[i-2] = CRGB(0, 0, 0);
      leds[i-3] = CRGB(0, 0, 0);
      leds[i-4] = CRGB(0, 0, 0);
      FastLED.setBrightness(20);
       FastLED.show();
    }
     
    }
    break;


  case 0xFF52AD:  
    
    leds[0] = CRGB(255, 0, 0); //green
    leds[5] = CRGB(0, 255, 0); //red
    leds[10] = CRGB(0, 0, 255); //blue
    leds[15] = CRGB(255, 255, 0); //red + green = yellow
    leds[20] = CRGB(0, 255, 255); //red + blue = purple
    leds[25] = CRGB(255, 0, 255); //green + blue = turqoise
    leds[30] = CRGB(50, 255, 0); //heavy red medium green = orange?
    FastLED.setBrightness(20);
    FastLED.show();
  
    break;

    case 0x7E7E58A7: //increase brightness button
     Serial.println("Increase Brightness");
  
     for(int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB(0, 255, 255);
      
      FastLED.setBrightness(20);
      FastLED.show();

      leds[i] = CRGB(0, 255, 255);
      leds[i-1] = CRGB(0, 255, 255);
      leds[i-2] = CRGB(0, 255, 255);
      leds[i-3] = CRGB(0, 255, 255);
      FastLED.show();
      delay(30);
      leds[i] = CRGB(0, 0, 0);
      leds[i-1] = CRGB(0, 0, 0);
      leds[i-2] = CRGB(0, 0, 0);
      leds[i-3] = CRGB(0, 0, 0);
     }
     leds[57] = CRGB(0, 0, 0);
     leds[58] = CRGB(0, 0, 0);
     leds[59] = CRGB(0, 0, 0);
     FastLED.show();

   
     break;

    


  default: 
    Serial.println(" other button   ");

  }

  delay(500);

} //END translateIR
