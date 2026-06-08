# Epitech Project : my_radar

### Description
The goal of the **my_radar** project was to create a simulation of air traffic radar in C:
- several planes fly on the screen
- control towers are present
- when two planes collide,
  - they avoid each other if they are in the area of a control tower (the air traffic controllers say to go up to one of them and to come down to the
other one)
  - they crash if they are not in the area of a control tower
- the planes informations (departure and arrival positions, speed and time to take off) and the control towers data (position and control area radius) are
parsed from a config file given as argument to the program

### Contributors
- Alexis Guibert {[LinkedIn](https://www.linkedin.com/in/alexis-guibert-it/) / [Github](https://github.com/AGuibert07)}

### Installation
First, clone this repository using
```
git clone git@github.com:AGuibert07/EPITECH_PROJECT-my_radar.git
```
Then, compile the C code using the `make` command.

### Usage
```
$> ./my_radar -h
Air traffic simulation panel
USAGE
  ./my_radar [OPTIONS] path_to_script
    path_to_script    The path to the script file.
OPTIONS
  -h                print the usage and quit.
USER INTERACTIONS
  'L' key        enable/disable hitboxes and areas.
  'S' key        enable/disable sprites.
  'A' key        enable/disable crash animation
  'E' key        enable/disable the window closure when all planes are crashed or arrived
*The previous options are enabled by default.*
  'T' key        enable/disable planes trajectories (disabled by default).
  'B' key        switch the background image
  'P' key        switch the planes image
  'C' key        switch the control towers image
  'Q' or 'escape' key        quit
```

### Technologies Used
- **Coding language**: C
- **Graphical User Interface (GUI)** (graphical library used): [CSFML](https://csfml.1l.is/search.html?q=sfText&check_keywords=yes&area=default)
