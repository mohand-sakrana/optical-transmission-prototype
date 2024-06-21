# optical-transmission-prototype
wired and wireless optical transmission prototype for the FTTH system.
1. Wired optical transmission
  we designed a semi-optic transmitter and receiver circuit to send a digital signal (square wave) via an optical fiber cable and display it on an oscilloscope,
  using an IC(LM324) to grows and reflects the signal and A set of capacitors, resistors, and variable resistance for transmitter and receiver circuit and using an optical fiber cable as 
  media  to transmied signal between transmiter and receivr.
2. wireless optical transmission.
 we designed a wireless optical transmission using LiFi technology to send data and Voice using an LED as the transmitter and a solar panel (LDR) as the receiver.
   1.Send data(text).
    transmitter circuit consist of arduino uno connected to LED , receiver circuit  consist of solar cell connected to aeduino uno.
    At trnsmitter to send data (text)   convertting the text to ASCII code, each character to 8bit, and send it through the LED into the air. At the receiver, the solar cell receives the 
    change in the brightness of the LED and converts it to bits 0.1. Then we collect these bits again and return them again to text.
   2. send voice.
     transmitter circuit consist of  audio jack connected to led and battary , receiver circuit  consist of solar cell connected to amplifier circiut then connected to speaker
     At transmitter to send voice  the audio jack convert te audio signal tp electical signal transmited by LED to the air . At receiver , the solar cell receiver the change of brightness 
     of LED and convert it to electerical signal but  week signal need to be amplifier then the speaker convert it back to audio signal.
     

Finally, we designed an interface using Tkinter and connected it to an Arduino for data transmission and reception.
