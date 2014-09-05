MotionMuter
===========

An Arduino project to mute audio sources when a room is empty.

I'm a ham radio guy. I have my radios on all the time. A problem arises when I neglect to turn down the volume on the radio before I go to bed, and then someone kerchunks the repeater at midnight and I get a nice wake-up call in morse code.

One solution to this problem is to create a timer of sorts, one based on motion. If I leave the room for a period of time, the audio will mute.

Hardware Setup
--------------

I'm using an Arduino Uno and a RadioShack PIR sensor (Cat 2760347).

Output of the PIR is going to pin 2 on the Arduino

Eventual Features
-----------------

* Use of a relay/transistor to "mute" audio source by interrupting the circuit between the source and the output speaker
* Support for up to 3 audio sources
* Ability to toggle the muting of each individual source via a button
* Ability to enable sources to override the motion timer (always on, or always muted)
* Ability to quickly mute/unmute all sources
* LED indicators for the status of muting for each source
