# Graphing_Terminal

A Terminal Based Graphing Calculator written in C. Uses only ASCII characters for Plotting graphs. Has A command Line like implementation for navigation in Coordinate space. 

## Set Up Environment

Clone the Repository and navigate to directory where all source files are placed.


### For GCC compilers

To compile using gcc compiler execuete.

`gcc main.c commandLine.c curves.c camera.c -o executable_name -lm`

`-lm` flag is to instruct compiler to use `math.h` .


## The Navigation Command Line

The Navigation command line powers user to navigate in the coordinate space. Following are the commands to use it.


![CommandLIne Image](/Media/terminal.png "CommandLIne Image")

#### For Changing Absolute Position of Camera

`p x y`

Where `x` is new x coordinate of camera and `y` is new y coordinate of camera.

#### For changeing position of camera relative to current position

`t h relative_horizontal_positon`

`t v relative_vertical_position`

#### For changing Scale of Camera (Only Absolutely)

`s new_scale`


## Some Screenshots

* #### `Sin(x)` Curve

![Sin Curve](/Media/SinCurve.png "Sin(x)")


* #### Limaçon of Pascal

![Limaçon of Pascal](/Media/Limacon.png "Limaçon of Pascal")



## Contacts

* Email : ishanbawne20@gmail.com
---