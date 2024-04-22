# Neureset Device Group Project

The Neureset Device repository is a Qt/C++ project that creates a GUI Neureset Device
and PC View for EEG graphing and monitoring. Main tasks available on the 
application include: session logging and treatment, session history, and application
(device) configuration of date and time.

Link to Youtube Demo Video: https://youtu.be/OxkL4dZwXso

Track and view changes in the [project board](https://www.drupal.org/project/issues/admin_menu](https://github.com/users/ludigrizz/projects/1)). The contributions 
and distribution of work for each person are visible in the github board.
Contributors: Sofia, Elsa, Christina

## Table of contents of Repo

- design_documentation
- headers
- source files
- ui files
- other files
- build (build backup from Qt)
- icons

### Design Documentation
This folder includes all the design documentation related PDFs and documents, including:
- UML Class Diagram
- State Machine Diagram
- Sequence Diagrams
    - DateTime
    - batteryLow
    - connectionLost
    - session
    - viewHistory
- Use Cases
- Use Case Diagram
- Traceability Matrix

### Headers
This includes the following headers for classes:
- Session.h - sessions class
- Qcustomplot.h - plot class for graph
- pcwindow.h - PC UI class
- mainwindow.h - mainwindow class for the primary device UI
- ledindicator.h - class for led indicators connecting to other classes
- handleconnection.h - class to handle connection (and connection use case)
- graph.h - class for building the graph
- electrode.h - class of electrodes 
- digitalclock.h - class for the digital LCD clock visible in session
- deviceprofile.h - class for attributes of a user's device
- devicecontrol.h - class for controls of the device
- datetimedialog.h - class for setting the date and time dialog
- batteryprogressbar.h - class for battery progression bar
- LED.h - class for LEDs
- listHandler.h - class for handling the passing of QListWidget items to text files and uploading them to the PC UI

### Source Files
Accompanying those header files are their respective source files and main.cpp. Wholistically:
- main.cpp
- Session.cpp
- Qcustomplot.cpp
- pcwindow.cpp
- mainwindow.cpp
- ledindicator.cpp
- handleconnection.cpp
- graph.cpp
- electrode.cpp
- digitalclock.cpp
- deviceprofile.cpp
- devicecontrol.cpp
- datetimedialog.cpp
- batteryprogressbar.cpp
- LED.cpp
- listHandler.cpp

### Other Files
This includes the non class (source or header) files, such as:
- pcwindow.ui -> ui for the PC
- mainwindow.ui -> ui for the mainwindow
- data.txt -> data text file for logging session info history

### Icons
The icons here are used with reference to changing and affecting stylesheets.

# Compilation Instructions
To compile and run do the following:
1. Clone the repo and open in the course VM
2. Open in Qt Creator and click to open the neureset-device-ui.pro
3. Then press the green "play" button to build.
4. The project will build and launch in the VM now.

# Contributions
All contributions are more concretely visible in the aforementionned [project board](https://www.drupal.org/project/issues/admin_menu](https://github.com/users/ludigrizz/projects/1)).

For diagrams: 
    Sofia contributed use cases 4-6, the use case diagram and state diagram.
    Elsa contributed for use cases 1-3 and sequence diagrams.
    Christina contributed the class diagram.
    Traceability matrix was divided equally amongst everyone.

For Coding/Implementation:
    Sofia contributed all the [neureset device and PC front-end implementations](https://github.com/ludigrizz/3004_Final_Project/issues/23) and organization. She also contributed to the handling and building of features like             timers, routing slots and sockets, etc. This work supported the device main page, date and time page, new session page, session log device ui page, and the pc session log page.
    Elsa contributed to building the session and electrode logic and classes that support the new session pages and its history connects to the session log page.
    Christina contributed to the building of the graph in new session and bridging Elsa's session logic to the mainwindow ui components made by Sofia.
    
