# SuperSketcherz

This is a running shoe mod that adds switchable lights to your favorite pair of running shoes for better visibility.
The lights are controlled by quickly tapping your feet togeter.  

![ShoeDiagram](https://github.com/TIPConsulting/GemmaM0_SuperSketcherz/blob/master/Diagrams/ShoeDiagram.jpg?raw=true)

## Hardware

- 1 x Left shoe
- 1 x Right shoe
- 2 x [Adafruit Gemma M0](https://www.adafruit.com/product/3501)
- 2x 500mAh Liion battery
- Conductive tape
- Misc wires or conductive thread

## Design

Each shoe has a pair of exposed leads - one shoe has leads on front, the other shoe has leads on the back.  These leads, when closed, will form a closed circuit like clicking a button.  The leads on the shoes are orthogonal to each other, so when you tap the shoes together they will form a \# pattern.  This will close both circuits and instruct the processor to turn on the lights.

## Switch Proof of Concept

As a switch, I am using conductive strips that trigger a "button click" when the circuit is closed.  Here is the [proof of concept video](https://github.com/TIPConsulting/GemmaM0_SuperSketcherz/discussions/2) for the double-tap light control.

## Build Process

The design as pictured is feasible, but cost prohibitve.  First off, I don't have that many LEDs and second, I don't want stick things to my one good pair of running shoes.  Instead, I built a downscaled version with house slippers and the built-in LED of the Gemma M0.

I flashed the code from this repo onto each of the Gemmas.  Then I soldered wires onto the Gemma `D1` and `GND` pints - these will be used for the  switch apparatus.  The other ends of those wires were then soldered onto strips of copper foil tape.  I planned to also attach extra LEDs to the microntrollers, but found that they did not operate well at the voltage supplied by the battery. Since the extra lights weren't very visible, I elected to leave them off.

With the wiring and controller assembled, I mounted the devices onto a pair of slippers.  I applied the tape first, taking special care to make sure that would cross each oterh to close their respective circuits.  Then I used bobby pins to affix the controllers and make small pockets for the batteries.  
