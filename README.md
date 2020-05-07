# Final Project

[![license](https://img.shields.io/badge/license-MIT-green)](LICENSE)
[![docs](https://img.shields.io/badge/docs-yes-brightgreen)](docs/README.md)

Read [this document](https://cliutils.gitlab.io/modern-cmake/chapters/basics/structure.html) to understand the project
layout.

**Author**: Megha Ganesh - [`meghasg2@illinois.edu`](mailto:meghasg2@illinois.edu)

## Dependencies
  - [CMake](https://cmake.org/)
  - [Cinder](https://libcinder.org/)
  - [Box2D](https://box2d.org/)
  - [OpenGL](https://libcinder.org/docs/guides/opengl/index.html)

## Integrated Development Environment
- The development environment for this project was [CLion](https://www.jetbrains.com/clion/). 

## Prerequisites to build and run from either the command line or through CLion
Disclaimer: This project has only been run/tested on MacOS
- Download [Cinder](https://libcinder.org/download) for MacOS (assume it gets downloaded to a folder called cinder_0.9.2_mac)
- Create a subdirectory in the cinder_0.9.2_mac folder called "my-projects" 
- Clone the [repository](https://github.com/CS126SP20/final-project-meghasg2) into my-projects

## Build and run via command line
- cd to the project directory 
```console
cd final-project-meghasg2
```
- Make sure CMake is in the PATH and run CMake on the project. Example:
```console
export PATH="/Applications/CLion.app/Contents/bin/cmake/mac/bin":$PATH
```
- Run cmake . at the project root to generate build files 
```console
cmake . 
```
Build the application
```console
cmake --build . --target cinder-myapp -- -j 4
```
- cd to the executable location 
```console
cd Debug/cinder-myapp/cinder-myapp.app/Contents/MacOS/
```
- Run the app (in this case, in debug mode) 
```console
./cinder-myapp
```

### Build and run using CLion
- Open CLion and go to File -> New CMake Project from Sources 
- Select final-project-meghasg2 and open in CLion
- Build the project in CLion
- MacOS users: it's possible that you may come across 
```
Error running 'cinder-snake': Cannot run program … cinder-snake.app/Contents/Resources"): error=13, Permission denied
```
In this case, try doing Edit configurations -> Executable -> Select Other -> Find my-projects/final-project-meghasg2/cmake-build-debug/Debug/cinder-myapp/Contents/MacOS/cinder-myapp and click run once again
- You should now be able to build and run Etch-a-Sketch! 

### Game
  - Instructions: 
  Click and drag your mouse to draw particles to the screen 

#### Keyboard

| Key        | Action                                                      |
|------------|-------------------------------------------------------------|
| `spacebar` | Clear the screen and change the color of the particles      |
| `s`        | Increase the size of the particles                          |
| `d`        | Decrease the size of the particles                          |
| `a`        | Change the gravity of the particles and watch them fall     | 

---
