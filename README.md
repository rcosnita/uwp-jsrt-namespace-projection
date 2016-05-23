# Summary

This repository showcase WinRT visual c++ namespace projection into JSRT (Chakra). Open the code in Visual Studio 2015 and see **ChakraTest.cpp** implementation.

# Running the app

Make sure you are using a recent version of Windows 10 (1511 should be enough). Follow the steps below in order to run the sample:

1. Open the solution in Visual Studio 2015.
1. Run the x64 version in debug mode (press F5).
    1. A breakpoint will be hit in app.js file.
    1. You can step by step debug or just press F5 to continue.
1. In the app main page, each time you type a value in the second text box an event is sent to the app.js running loop. If the event sent is **changedEvent** or **changedEvent2** the event name will be displayed from javascript to the main UI.