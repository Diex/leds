#include <MIDI.h>

int led = 9;

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

void handleNoteOn(byte channel, byte note, byte velocity){
  Serial.print(channel);
  Serial.print(':');
  Serial.print(note);
  Serial.print(':');
  Serial.print(velocity);
  Serial.print('\n');
 
  if(note == 72){
    analogWrite(led, 255 - (velocity * 2)); // el velocity está entre 0 y 127
  }
}

void handleNoteOff(byte channel, byte note, byte velocity){
  if(note == 72){
    Serial.println("off");
    analogWrite(led, 255);
  }
}
