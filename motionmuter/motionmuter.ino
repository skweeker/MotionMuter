 // Preferences
int audio1_state = 1;               // Turn audio 1 on by default
int audio1_mode = 1;                // Mode 1 = mute if no motion, 2 = mute always, 3 = never mute

int audio2_state = 1;               // Turn audio 2 on by default
int audio2_mode = 1;                // Mode 1 = mute if no motion, 2 = mute always, 3 = never mute

int audio3_state = 1;               // Turn audio 3 on by default
int audio3_mode = 1;                // Mode 1 = mute if no motion, 2 = mute always, 3 = never mute

long motionDelay = 600000;          // Delay in ms between no motion and muting of audio. In ms!

// Hardware setup
int ledPin = 13;                // Pin for the Status LED
int inputPin = 2;               // Pin for Input from the PIR sensor
int pirState = LOW;             // Assume no motion at first.

// You don't need to worry about these
int motionTimer = 0;            // DO NOT set this, it's just a default and gets set later.
int val = 0;                    // variable for reading the pin status

void setup() {
	pinMode(ledPin, OUTPUT);      // declare LED as output
	pinMode(inputPin, INPUT);     // declare sensor as input
	
	Serial.begin(9600);
}

void loop(){
	val = digitalRead(inputPin);  // read input value
	
	
	if (val == HIGH) // HIGH if motion is detected.
	{
		digitalWrite(ledPin, HIGH);  // turn LED ON
		
		if (pirState == LOW)
		{
		        Serial.println("Someone is in the room!");
			pirState = HIGH;
			
			// If we have motion, keep re-defining our motionTimer
			motionTimer = millis() + motionDelay;
		}
	}
	else // No motion detected
	{
		digitalWrite(ledPin, LOW); // turn LED OFF
		
		if (pirState == HIGH)
		{
			Serial.println("I don't see anyone...");
			
			pirState = LOW;
		}
	}
	
	if ((motionTimer != -1) && (motionTimer <= millis())) // we havent seen motion in a while.
	{
		Serial.println("Nobody is home. Time to be quiet.");

                // set motionTimer to -1 so we know we've already performed our motion muting functions.
		motionTimer = -1;
	}
}
