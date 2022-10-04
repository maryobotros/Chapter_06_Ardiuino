// Variables to hold reference to pin number for potentiometers and button
const int analogInA0 = A0;
const int analogInA1 = A1;
const int pushButton = 2;

// Holds state of button (0: up, 1: down)
bool lastButtonState = 0;

// Variables to hold current and last values of potentiometers
int a0Value = 0;
int a0LastValue = 0;
int a1Value = 0;
int a1LastValue = 0;

// Reference string for all the interactive components
String a0String = "A0";
String a1String = "A1";
String pushButtonString = "BP";


void setup() {
  Serial.begin(9600);
  pinMode(pushButton, INPUT_PULLUP);

}


void loop() {
  // Current state of the button
  int buttonStateUp = digitalRead(pushButton);

  // Current state of the potentiometers
  a0Value = analogRead(analogInA0);
  a1Value = analogRead(analogInA1);

  // Mapping potentiometer values
  a0Value = map(a0Value, 0, 1023, 0, 10);
  a1Value = map(a1Value, 0, 1023, 0, 10);

  // Sending potentiometer values to CheckValue function
  a0LastValue = CheckValue(a0Value, a0LastValue, a0String);
  a1LastValue = CheckValue(a1Value, a1LastValue, a1String);

  // If the last button state doesn't equal the current one
  if(lastButtonState != buttonStateUp){
    
    // The current one becomes the last button state
    lastButtonState = buttonStateUp;
    
    // If the button is not up (it is pressed)
    if(buttonStateUp == false){

      // Print out both potentiometer values
      Serial.println(pushButtonString + a0Value + "," + a1Value); 
    }
  }

}

// Checks if current pot value doesn't equal last value then updates last value
int CheckValue(int aValue, int aLastValue, String aString){
  
  // If the current value doesn't equal the last value
  if(aValue != aLastValue){
    // Print out the current value and update the last value
    Serial.println(aString + aValue);
    aLastValue = aValue;
  }
  return aLastValue;
}
