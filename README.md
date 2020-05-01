# Final Project

[![license](https://img.shields.io/badge/license-MIT-green)](LICENSE)
[![docs](https://img.shields.io/badge/docs-yes-brightgreen)](docs/README.md)

Read [this document](https://cliutils.gitlab.io/modern-cmake/chapters/basics/structure.html) to understand the project
layout.

**Author**: Anonymous - [`example@illinois.edu`](mailto:example@illinois.edu)

# Etch a Sketch

Author: Megha Ganesh

My project will be an Etch-a-Sketch game. The premise of the game is that the user can drag their mouse around to draw anything they want to the GUI, but I will also add additional features such as having the particles the item is drawn with (ex: squares, circles, rectangles) fall to the bottom of the GUI as if they are being subjected to a gravitational force, changing the color of the item being drawn, changing the shape of the particles used to draw the item, and the size of the particles. 

I want to do this project because I used to play with Etch-a-Sketch toys as a child and was fascinated by the fact that you could draw whatever you wanted on the screen and erase everything with such ease. 

I will use the [Box2D](https://github.com/cinder/Cinder/tree/master/blocks/Box2D) CinderBlock, which is a 2D physics engine for games, in order to enhance the graphics of the game and deal with aspects such as gravity (in the case of the particles changing from static bodies to dynamic bodies and falling to the bottom of the GUI with a specific gravity). In order to allow the user to draw items to the GUI using their Trackpad, I will use the MouseEvent and KeyEvent class. 

This is my rough timeline for the project:

Week 1 - Integrate Box2D into Cinder and write out the general framework for the game (making sure a particle can be drawn to the GUI every time the Trackpad/mouse is pressed and that every particle is controlled in some class). Essentially, I want Week 1 to be dedicated to writing a functional game engine. 

Week 2 - Set up the basic UI for the start screen and game screen and work on implementing additional features such as having the body of the particle change (ex: static to dynamic or static to kinetic), the size of the particle change, the color of the particle change, and the shape of the particle change. 

Week 3 - Add background music and a fun background for the GUI, implement a key/legend in the corner of the GUI so the user knows what keys to press in order to have the particles change their behavior. Create a start screen for the Etch-a-Sketch game. 

Stretch goals: Allow the user to change the background of the GUI with certain keystrokes (examples of potential backgrounds: a green landscape, outer space, etc.). Give the user prompts for what they should draw. 

---
