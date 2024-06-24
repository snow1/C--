### command
g++ PressureSource.cpp PA33X.cpp AltimeterSource.cpp PA200.cpp Sensor.cpp SensorThread.cpp InertiaSource.cpp MTi_30_AHRS.cpp DataBridge.cpp main.cpp -o main & main

# FlightController
The UML diagram(image.png or image.uxf) shows a system of sensors (e.g., InertiaSource, AltimeterSource, PressureSource, TemperatureSource) and their interrelationships. Each source class has methods for registering receivers, sampling data, and notifying updates. The Sensor abstract class serves as a base for several concrete sensor classes. The ReportGenerator class generates diagnostic reports with various error levels.

The DataBridge class is central to the system, aggregating data from different sensors and providing flight data to the FlightController.

## Sensor Classes

The `Sensor` class serves as an abstract base class with three derived classes, including:

- `PA200`
- `PA3XX`
- `MTI_30_AHRS`

These sensor classes implement methods for initialization, sampling, and termination.

## Abstract Source Classes

The following abstract source classes provide interfaces for registering receivers and notifying sample updates:

- `AltimeterSource`
- `PressureSource`
- `TemperatureSource`(NEW ADD)
- `InertiaSource`

## Data Structures and Integration

Various data structures hold sensor data:

- `Altimeter`
- `Pressure`
- `Temperature`
- `Inertia`
- `FlightData`

The `DataBridge` class aggregates data from these sources and updates the `FlightController`.

## System Integration

The `FlightController` relies on the `DataBridge` to manage and utilize flight data effectively for controlling flight parameters.

## Diagnostic Reporting
The Diagnostic Reporting system is designed to continuously monitor the health and performance of the system. By categorizing issues into different severity levels, it allows for prioritized handling of problems.

A diagnostic system includes the following components:

- `DiagnosticReport` struct contains:
    - has_issue: A boolean indicating if there is an issue.
    - level: An ErrorLevel enumeration with values Green, Yellow, and Red, representing the severity of the issue.
    - issue_message: A string providing a descriptive message about the issue.
- `ReportGenerator` class:
   - The ReportGenerator is an abstract class that defines a method GenerateReport(), which is meant to be overridden by derived classes to generate specific diagnostic reports.

## Discussion

I choose to make the GenerateReport "pull"-based, since checks might only be performed at specific times (before a flight) and might be expensive to run. Therefore doing the pull-based approach allows for only running the expensive operation lazily when needed. The other approach would be to make it "push"-based like the sensors, where they will notify the listeners using a call back function every time the sensor changes its measurement.

Another choice was to make the actual specific sensor classes and not the abstract Sensor class inherit from the ReportGenerator. This was done since I prefer only a single layer of inheritance (more like traits/interfaces) and avoid multiple layers of inheritance as this usually leads to less adaptable code. However having it as an abstract class instead of just adding a generate function to each and the classes, allows for generic functions to work on all of the classes, as well as adding support for dependency injection for testing etc.

