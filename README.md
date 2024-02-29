# EECS4088 Project Repository

Welcome to the EECS4088 project repository. This repository contains various files and code examples related to embedded systems programming, focusing primarily on BeagleBone Black functionalities. Below is an introduction to each file within the repo:

## Deliverable

### `StateMachine`
- **Description:** Implements a state machine scheduler specifically designed for controlling lighting sequences. This is intended to demonstrate the application of state machines in embedded system scheduling and control.

### `RoundRobin`
- **Description:** Implements a simple round-robin scheduler. The registered tasks within this scheduler focus on flashing an LED, demonstrating task scheduling in an embedded system context.

### `ETL&STL`
- **Author:** Baidu Li
- **Description:** This file is dedicated to comparing basic algorithms between Embedded Template Library (ETL) and Standard Template Library (STL). It includes performance tests for functions such as `find()`, `heap()`, `min()`, `move()`, and `sort()`, each accompanied by a timing mechanism to evaluate efficiency.


## Files for draft&test

### `GPIOfunction2`
- **Description:** Attempt to implement Pulse Width Modulation (PWM) control, focusing on advanced GPIO manipulation. This file remains a work in progress.

### `GPIOfunction`
- **Description:** Demonstrates a proof of concept for controlling an LED using an external library, showcasing practical GPIO usage.

### `PRU_package`
- **Description:** Provides a proof of concept based on the guide available at [Catch22EU's BeagleBone PRU IPC tutorial](https://catch22eu.github.io/website/beaglebone/beaglebone-pru-ipc). It is designed to showcase inter-processor communication (IPC) capabilities with the Programmable Real-time Unit (PRU).

### `prutest`
- **Author:** Derek Molloy
- **Description:** Focuses on memory manipulation techniques, specifically for the BeagleBone's PRU. This file is part of a larger exploration into the capabilities and applications of PRU programming.


### `simPRU`
- **Description:** Attempts to integrate and utilize an external library for PRU simulation, based on the documentation available at [BeagleBoard's simPRU guide](https://docs.beagleboard.org/latest/projects/simppru/basics.html).

### `blinkLED`
- **Author:** Derek Molloy
- **Description:** This file contains a basic example of how to blink an LED on the BeagleBone Black, demonstrating basic GPIO manipulation.
