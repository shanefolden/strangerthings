#include <FastLED.h>

#define LED_PIN     5
#define NUM_LEDS    50
#define BRIGHTNESS  255
#define LED_TYPE    WS2811
#define COLOR_ORDER RGB
CRGB leds[NUM_LEDS];
char serialData;
char receivedChars[140];
int pin = 13;

#define UPDATES_PER_SECOND 100
const byte numChars = 140;
//char receivedChars[numChars];   // an array to store the received data
char receivedChar;
boolean newData = false;


CRGBPalette16 currentPalette;
TBlendType    currentBlending;

extern CRGBPalette16 myRedWhiteRedPalette;
extern const TProgmemPalette16 myRedWhiteRedPalette_p PROGMEM;  
char message[140] = "a";

void setup() {
  
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );
  
  Serial.begin(115200);
  Serial.print("<arduino is ready>");
  currentPalette = RainbowColors_p;
  currentBlending = LINEARBLEND;

}


void loop()
{

 String content = "";
 char character;
 static byte ndx = 0;
 char endMarker = '>';
 char rc;
    
    while (Serial.available() > 0 && newData == false) {
        rc = Serial.read();

        if (rc != endMarker) {
            receivedChars[ndx] = rc;
            ndx++;
            content.concat(rc);
            if (ndx >= numChars) {
                ndx = numChars - 1;
            }
        }
        else {
            receivedChars[ndx] = '\0'; // terminate the string
            ndx = 0;
            newData = true;
        }
    }


  if (newData) {
    lights(receivedChars);
    newData=false;
   
  }





}

void recvOneChar() {
    if (Serial.available() > 0) {
        receivedChar = Serial.read();
        newData = true;
    }
}

void showNewData() {
    if (newData == true) {
        Serial.print("test");
        lights('a');
        newData = false;
    }
}

void lights(char message[]) {

  for (int i = 0; i < 50; i++)
  {
    int randNumber = random(1, 3);
    if (randNumber == 1)
    {
      leds[i] = CRGB::Red;
    }
    if (randNumber == 2)
    {
      leds[i] = CRGB::Green;
    }


    FastLED.show();
    delay(10);
  }

  for (int i = 0; i < 50; i++)
  {
    leds[i] = CRGB::Black;

    FastLED.show();
    delay(10);
  }
  delay(1000);


  for (int i = 0; i < 50; i++)
  {
    int randNumber2 = random(1, 3);

    if (message[i] == 'a')
    {
      if (randNumber2 == 1)
      {
        leds[49] = CRGB::Red;
      }
      if (randNumber2 == 2)
      {
        leds[49] = CRGB::Green;
      }
      FastLED.show();
      delay(650);

      leds[49] = CRGB::Black;
      FastLED.show();
      delay(650);
    }
    if (message[i] == 'b')
    {
      if (randNumber2 == 1)
      {
        leds[48] = CRGB::Red;
      }
      if (randNumber2 == 2)
      {
        leds[48] = CRGB::Green;
      }
      FastLED.show();
      delay(650);

      leds[48] = CRGB::Black;
      FastLED.show();
      delay(650);
    }
    if (message[i] == 'c')
    {
      if (randNumber2 == 1)
      {
        leds[47] = CRGB::Red;
      }
      if (randNumber2 == 2)
      {
        leds[47] = CRGB::Green;
      }
      FastLED.show();
      delay(650);

      leds[47] = CRGB::Black;
      FastLED.show();
      delay(650);
    }
    if (message[i] == 'd')
    {
      if (randNumber2 == 1)
      {
        leds[46] = CRGB::Red;
      }
      if (randNumber2 == 2)
      {
        leds[46] = CRGB::Green;
      }
      FastLED.show();
      delay(650);

      leds[46] = CRGB::Black;
      FastLED.show();
      delay(650);
    }
    if (message[i] == 'e')
    {
      if (randNumber2 == 1)
      {
        leds[45] = CRGB::Red;
      }
      if (randNumber2 == 2)
      {
        leds[45] = CRGB::Green;
      }
      FastLED.show();
      delay(650);

      leds[45] = CRGB::Black;
      FastLED.show();
      delay(650);
    }
    if (message[i] == 'f')
    {
      if (randNumber2 == 1)
      {
        leds[44] = CRGB::Red;
      }
      if (randNumber2 == 2)
      {
        leds[44] = CRGB::Green;
      }
      FastLED.show();
      delay(650);

      leds[44] = CRGB::Black;
      FastLED.show();
      delay(650);
    }
    if (message[i] == 'g')
    {
      if (randNumber2 == 1)
      {
        leds[43] = CRGB::Red;
      }
      if (randNumber2 == 2)
      {
        leds[43] = CRGB::Green;
      }
      FastLED.show();
      delay(650);

      leds[43] = CRGB::Black;
      FastLED.show();
      delay(650);
    }
    if (message[i] == 'h')
    {
      if (randNumber2 == 1)
      {
        leds[42] = CRGB::Red;
      }
      if (randNumber2 == 2)
      {
        leds[42] = CRGB::Green;
      }
      FastLED.show();
      delay(650);

      leds[42] = CRGB::Black;
      FastLED.show();
      delay(650);
    }
    if (message[i] == 'i')
    {
      if (randNumber2 == 1)
      {
        leds[41] = CRGB::Red;
      }
      if (randNumber2 == 2)
      {
        leds[41] = CRGB::Green;
      }
      FastLED.show();
      delay(650);

      leds[41] = CRGB::Black;
      FastLED.show();
      delay(650);
    }
    if (message[i] == 'j')
    {
      if (randNumber2 == 1)
      {
        leds[40] = CRGB::Red;
      }
      if (randNumber2 == 2)
      {
        leds[40] = CRGB::Green;
      }
      FastLED.show();
      delay(650);

      leds[40] = CRGB::Black;
      FastLED.show();
      delay(650);
    }
    if (message[i] == 'k')
    {
      if (randNumber2 == 1)
      {
        leds[39] = CRGB::Red;
      }
      if (randNumber2 == 2)
      {
        leds[39] = CRGB::Green;
      }
      FastLED.show();
      delay(650);

      leds[39] = CRGB::Black;
      FastLED.show();
      delay(650);
    }
    if (message[i] == 'l')
    {
      if (randNumber2 == 1)
      {
        leds[38] = CRGB::Red;
      }
      if (randNumber2 == 2)
      {
        leds[38] = CRGB::Green;
      }
      FastLED.show();
      delay(650);

      leds[38] = CRGB::Black;
      FastLED.show();
      delay(650);
    }
    if (message[i] == 'm')
    {
      if (randNumber2 == 1)
      {
        leds[37] = CRGB::Red;
      }
      if (randNumber2 == 2)
      {
        leds[37] = CRGB::Green;
      }
      FastLED.show();
      delay(650);

      leds[37] = CRGB::Black;
      FastLED.show();
      delay(650);
    }
    if (message[i] == 'n')
    {
      if (randNumber2 == 1)
      {
        leds[14] = CRGB::Red;
      }
      if (randNumber2 == 2)
      {
        leds[14] = CRGB::Green;
      }
      FastLED.show();
      delay(650);

      leds[14] = CRGB::Black;
      FastLED.show();
      delay(650);
    }
    if (message[i] == 'o')
    {
      if (randNumber2 == 1)
      {
        leds[15] = CRGB::Red;
      }
      if (randNumber2 == 2)
      {
        leds[15] = CRGB::Green;
      }
      FastLED.show();
      delay(650);

      leds[15] = CRGB::Black;
      FastLED.show();
      delay(650);
    }
    if (message[i] == 'p')
    {
      if (randNumber2 == 1)
      {
        leds[16] = CRGB::Red;
      }
      if (randNumber2 == 2)
      {
        leds[16] = CRGB::Green;
      }
      FastLED.show();
      delay(650);

      leds[16] = CRGB::Black;
      FastLED.show();
      delay(650);
    }
    if (message[i] == 'q')
    {
      if (randNumber2 == 1)
      {
        leds[17] = CRGB::Red;
      }
      if (randNumber2 == 2)
      {
        leds[17] = CRGB::Green;
      }
      FastLED.show();
      delay(650);

      leds[17] = CRGB::Black;
      FastLED.show();
      delay(650);
    }
    if (message[i] == 'r')
    {
      if (randNumber2 == 1)
      {
        leds[18] = CRGB::Red;
      }
      if (randNumber2 == 2)
      {
        leds[18] = CRGB::Green;
      }
      FastLED.show();
      delay(650);

      leds[18] = CRGB::Black;
      FastLED.show();
      delay(650);
    }
    if (message[i] == 's')
    {
      if (randNumber2 == 1)
      {
        leds[19] = CRGB::Red;
      }
      if (randNumber2 == 2)
      {
        leds[19] = CRGB::Green;
      }
      FastLED.show();
      delay(650);

      leds[19] = CRGB::Black;
      FastLED.show();
      delay(650);
    }
    if (message[i] == 't')
    {
      if (randNumber2 == 1)
      {
        leds[20] = CRGB::Red;
      }
      if (randNumber2 == 2)
      {
        leds[20] = CRGB::Green;
      }
      FastLED.show();
      delay(650);

      leds[20] = CRGB::Black;
      FastLED.show();
      delay(650);
    }
    if (message[i] == 'u')
    {
      if (randNumber2 == 1)
      {
        leds[21] = CRGB::Red;
      }
      if (randNumber2 == 2)
      {
        leds[21] = CRGB::Green;
      }
      FastLED.show();
      delay(650);

      leds[21] = CRGB::Black;
      FastLED.show();
      delay(650);
    }
    if (message[i] == 'v')
    {
      if (randNumber2 == 1)
      {
        leds[22] = CRGB::Red;
      }
      if (randNumber2 == 2)
      {
        leds[22] = CRGB::Green;
      }
      FastLED.show();
      delay(650);

      leds[22] = CRGB::Black;
      FastLED.show();
      delay(650);
    }
    if (message[i] == 'w')
    {
      if (randNumber2 == 1)
      {
        leds[23] = CRGB::Red;
      }
      if (randNumber2 == 2)
      {
        leds[23] = CRGB::Green;
      }
      FastLED.show();
      delay(650);

      leds[23] = CRGB::Black;
      FastLED.show();
      delay(650);
    }

    if (message[i] == 'x')
    {
      if (randNumber2 == 1)
      {
        leds[24] = CRGB::Red;
      }
      if (randNumber2 == 2)
      {
        leds[24] = CRGB::Green;
      }
      FastLED.show();
      delay(650);

      leds[24] = CRGB::Black;
      FastLED.show();
      delay(650);
    }
    if (message[i] == 'y')
    {
      if (randNumber2 == 1)
      {
        leds[25] = CRGB::Red;
      }
      if (randNumber2 == 2)
      {
        leds[25] = CRGB::Green;
      }
      FastLED.show();
      delay(650);

      leds[25] = CRGB::Black;
      FastLED.show();
      delay(650);
    }
    if (message[i] == 'z')
    {
      if (randNumber2 == 1)
      {
        leds[26] = CRGB::Red;
      }
      if (randNumber2 == 2)
      {
        leds[26] = CRGB::Green;
      }
      FastLED.show();
      delay(650);

      leds[26] = CRGB::Black;
      FastLED.show();
      delay(650);
    }
    if (message[i] == ' ')
    {
      delay(500);
    }
  }
  delay(200);


}


//
// Normally, in computer graphics, the palette (or "color lookup table")
// has 256 entries, each containing a specific 24-bit RGB color.  You can then
// index into the color palette using a simple 8-bit (one byte) value.
// A 256-entry color palette takes up 768 bytes of RAM, which on Arduino
// is quite possibly "too many" bytes.
//
// FastLED does offer traditional 256-element palettes, for setups that
// can afford the 768-byte cost in RAM.
//
// However, FastLED also offers a compact alternative.  FastLED offers
// palettes that store 16 distinct entries, but can be accessed AS IF
// they actually have 256 entries; this is accomplished by interpolating
// between the 16 explicit entries to create fifteen intermediate palette
// entries between each pair.
//
// So for example, if you set the first two explicit entries of a compact
// palette to Green (0,255,0) and Red (0,0,255), and then retrieved
// the first sixteen entries from the virtual palette (of 256), you'd get
// Green, followed by a smooth gradient from green-to-Red, and then Red.
