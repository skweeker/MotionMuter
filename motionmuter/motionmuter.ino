 // Preferences
int audio1_state = 1;               // Turn audio 1 on by default
int audio1_mode = 1;                // Mode 1 = mute if no motion, 2 = mute always, 3 = never mute

int audio2_state = 1;               // Turn audio 2 on by default
int audio2_mode = 1;                // Mode 1 = mute if no motion, 2 = mute always, 3 = never mute

int audio3_state = 1;               // Turn audio 3 on by default
int audio3_mode = 1;                // Mode 1 = mute if no motion, 2 = mute always, 3 = never mute

long motionDelay = 1000000000;      // Delay in ms between no motion and muting of audio.

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
			
			// If we have motion, keep our motion timer the same as our motion delay setting.
			motionTimer = motionDelay;
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
		
		// If we don't have motion, we want to decrement our motion timer
		if (motionTimer >= 2)
		{
			motionTimer--;
		}
	}
	
	if (motionTimer == 1) // We haven't seen anyone in a long time
	{
		// Using an if statement and performing these actions before decrementing the timer
		// one last time, so that these actions are only performed once.
		
		Serial.println("Nobody is home. Time to be quiet.");
		motionTimer--;
	}
}
