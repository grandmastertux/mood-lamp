// This value controls how fast the mood lamp runs...
int pulseSpeed = 5;

// These values are for the UNO
int ldrPin=0;
int redLed = 11; //redLED in DP 10
int greenLed = 10; //greenLED in DP 9
int blueLed = 9; //blueLED in DP 8

//The variable stores the value of the light in the room
int ambientLight;

//This variable control the brightness of the lamp (2-255)
int power=120;

//This is an array used to the store the values of the R B G LED's
float RGB[3];

float CommonMathVariable = 180/PI;

void setup()
{
  Serial.begin(9600);

  //This tells the UNO to send data out to the LED's
  pinMode(redLed,OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed,OUTPUT);

  digitalWrite(redLed,LOW);
  digitalWrite(greenLed, LOW);
  digitalWrite(blueLed,LOW);
}

void loop()
{
  for (float x=0;x<PI;x=x+0.00005)
  {
    //Red LED
    RGB[0] = power * sin(x*(CommonMathVariable));
    //Green LED
    RGB[1] = power * sin((x+PI/2)*(CommonMathVariable));
    //Blue LED
    RGB[2] = power * sin((x+(PI*2/3))*(CommonMathVariable));

    ambientLight=analogRead(ldrPin);

    if(ambientLight > 700)
    {
      if(abs(RGB[0])<10)
      {
        RGB[0] = 0;
      }
      if(abs(RGB[1])<10)
      {
        RGB[1] = 0;
      }
      if(abs(RGB[2])<10)
      {
        RGB[2] = 0;
      }

      if(abs(RGB[0])<40)
      {
        delay(15*pulseSpeed);
      }
      else if(abs(RGB[1])<20)
      {
        delay(10*pulseSpeed);
      }
      else if(abs(RGB[2])<30)
      {
        delay(10*pulseSpeed);
      }
      else {}

     analogWrite(redLed,abs(RGB[0]));
     analogWrite(greenLed, abs(RGB[1]));
     analogWrite(blueLed,abs(RGB[2])); 
    }
    else
    {
      digitalWrite(redLed,LOW);
      digitalWrite(greenLed, LOW);
      digitalWrite(blueLed,LOW);
    }
  }
}
