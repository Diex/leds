#include <MIDI.h>

int blue = 8;
int green = 9;
int red = 10;




struct MySettings : public midi::DefaultSettings
{
  static const unsigned SysExMaxSize = 1024; // Accept SysEx messages up to 1024 bytes long.
  static const bool UseRunningStatus = true; // My devices seem to be ok with it.
};

// Create a 'MIDI' object using MySettings bound to Serial2.
MIDI_CREATE_CUSTOM_INSTANCE(HardwareSerial, Serial1, MIDI, MySettings);

void setup()
{
  MIDI.begin(MIDI_CHANNEL_OMNI);
  Serial.begin(115200);
  MIDI.setHandleNoteOn(handleNoteOn);
  MIDI.setHandleNoteOff(handleNoteOff);
}
void loop()
{
  MIDI.read();
}

int colors[] = {
  0, 0, 0,
  255, 0, 0,
  0, 255, 0,
  0, 0, 255,
  255, 255, 0,
  255, 0, 255,
  0, 255, 255,
  255, 255, 255
};

void handleNoteOn(byte channel, byte note, byte velocity) {

  int pos = note - 60;

  Serial.print(channel);
  Serial.print(':');
  Serial.print(note);
  Serial.print(':');
  Serial.print(velocity);
  Serial.print('\n');

  if(note == 72) analogWrite(green, 255 - (velocity * 2));
//  Serial.print(colors[pos * 3]);
//  Serial.print(':');
//  Serial.print(colors[(pos * 3) + 1]);
//  Serial.print(':');
//  Serial.print(colors[(pos * 3) + 2]);
//  Serial.print('\n');

//  analogWrite(red, 255 - colors[pos * 3]);
//  analogWrite(green, 255 - colors[(pos * 3) + 1]);
//  analogWrite(blue, 255 - colors[(pos * 3) + 2]);
}

void handleNoteOff(byte channel, byte note, byte velocity) {
  if(note == 72) analogWrite(green, 255);
  Serial.println("off");
  analogWrite(red, 255);
  analogWrite(green, 255);
  analogWrite(blue, 255);
}
