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

Each shoe has a pair of exposed leads - one shoe has leads on front, the other shoe has leads on the back.  These leads, when closed, will form a closed circuit like clicking a button.  The leads on the shoes are orthognal to each other, so when you tap the shoes together they will form a \# pattern.  This will close both circuits and instruct the processor to turn on the lights.

## Switch Proof of Concept

As a switch, I am using conductive strips that trigger a "button click" when the circuit is closed.  Here is the [proof of concept video](https://github.com/TIPConsulting/GemmaM0_SuperSketcherz/discussions/2) for the double-tap light control.
