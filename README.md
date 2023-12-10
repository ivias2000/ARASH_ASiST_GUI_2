![Unt863itled](https://github.com/ivias2000/ARASH_ASiST_GUI_2/assets/125237611/f98e947e-f79c-40f3-a707-6d74b968ec98)
Overview:
This code is for a graphical user interface (GUI) application using Qt for plotting real-time data. The application receives data via a signal-slot mechanism and updates a plot accordingly. The plotted data includes values for phi, psi, d, x, y, and z over time.

Files:
mainwindow.h: Header file for the main window class.
udp.h: Header file for handling UDP communication.
udp_bridge.h: Header file for bridging UDP communication.
loggingthread.h: Header file for a logging thread.
External Dependencies:
Qt framework.
Global Variables:
global_x: An external integer variable.
startlog_gui: An external integer variable indicating whether logging should start.
qv_counter, qv_xValues, qv_yValues, qv_zValues, qv_phiValues, qv_psiValues, qv_dValues: External vectors for storing data points.
existingVectors: A list of vectors to store existing data.
Main Window Class (MainWindow):
Constructor:
Initializes the user interface (UI) and sets up the initial configuration of the plot.
Graphs are added for phi, psi, d, x, y, and z, each with a distinct color.
Sets up labels and background colors.
Destructor:
Cleans up the UI upon destruction.
Public Methods:
receiverGuiSlot(float x, float y, float z, float counter, float phi, float psi, float d): Slot method to receive and display real-time data.
plot_all(): Updates the plot with the latest data.
Signal-Slot Methods:
Several methods to handle radio button clicks, updating the plot based on the selected data to be displayed.
Button Click Handlers:
on_pushButton_start_clicked(): Starts logging.
on_pushButton_stop_clicked(): Stops logging.
How to Use:
Ensure you have the Qt framework installed.
Compile and run the code.
Use the GUI to visualize real-time data.
Start and stop logging using the provided buttons.
