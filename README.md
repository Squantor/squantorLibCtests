# squantorLibC tests
This repository contains the code to test out the squantorLibC library.
## Checking out
use ```git clone --recurse-submodules https://github.com/Squantor/squantorLibCtests.git``` to clone the repository and its submodules.
## Compiling
Use gnu make to build this project
```
make
```
Building can be done with various configurations that set up flags and other settings, this configuration is set with the ```CONFIG``` variable. Most projects have the ```release``` and ```debug``` where the ```debug``` configuration is default.
The ```release``` configuration has optimizations enabled (usually for size) and minimal included debugging information. The ```debug``` configuration has NO optimization and full debugging information. There might be specific configurations available per project. When no ```CONFIG``` is defined the default is the ```debug``` configuration.
### Depedencies
This program depends my [minimal testing framework](https://github.com/Squantor/squantorMinUnit) based on [minUnit](http://www.jera.com/techinfo/jtns/jtn002.html). This is automatically checked out when using ```git clone --recurse-submodules```.
## Usage
# Additional information
# TODO

