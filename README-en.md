## Available languages

1. [Russian](README.md)
2. [English](README-en.md)


## Brief Description

The program is a simulation of a weakly non-ideal gas in two-dimensional space, where molecules are modeled as elastic circles. The user can adjust various simulation parameters, based on which the optimal algorithm for processing particle collisions is selected. Macro- and microparameters of the system are monitored and saved. Using this data, the Maxwell distribution and the equation of state for the gas were verified (more details in the **Data Processing** section).


## Build and Run Instructions

1) Make sure you have Homebrew installed and run the following commands:

  ```sh
  brew install g++;
  brew install cmake;
  brew install qt
  ```

2) Clone the remote repository after installing Git:

  ```sh
  git clone git@gitlab.akhcheck.ru:kirill.grinko/box-with-molecules.git
  ```

3) Verify that the `Qt6_DIR` environment variable points to the folder containing the Qt library.

4) Build the project:

  ```sh
  cmake -B build;
  cmake --build build --target box_with_molecules
  ```

5) Run the simulation:
  ```sh
  bin/box_with_molecules
  ```

The file [constants.h](include/constants.h) contains the constants `BOX_WIDTH` and `BOX_HEIGHT`, which define the width and height of the molecular simulation area.


### Data Processing

The [data](data/) directory contains the script [research.py](data/research.py), which verifies the validity of the two-dimensional Maxwell distribution by analyzing particle velocity data saved during the simulation. A visual example of the distribution with good accuracy, based on a precomputed dataset, is shown in [scatter.gif](data/scatter.gif).


### Running Tests & Checking Code Style

User can run unit tests:
  ```sh
  cmake --build build --target box_test;
  bin/box_test
  ``` 

Additionally, the code style can be checked for compliance by running a specific script:

  ```sh
  ./run-clang-format.py -r <directory containing files to check>
  ```
