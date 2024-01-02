#include "buzzer.h"

// notes in the melody:
int melody_accept[] = {
    NOTE_F5, NOTE_A5};

int melody_deny[] = {
    NOTE_B2, NOTE_E2};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
    4, 4};

void play(int accepted)
{

    // iterate over the notes of the melody:
    for (int thisNote = 0; thisNote < 2; thisNote++)
    {

        // to calculate the note duration, take one second divided by the note type.
        // e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
        int noteDuration = 1000 / noteDurations[thisNote];

        int melodyNote = (accepted == 0) ? melody_deny[thisNote] : melody_accept[thisNote];

        tone(BUZZER, melodyNote, noteDuration);

        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        int pauseBetweenNotes = static_cast<int>(noteDuration * 1.30);
        delay(pauseBetweenNotes);
        // stop the tone playing:
        noTone(BUZZER);
    }
}
