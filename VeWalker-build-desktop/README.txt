SETTING UP PROGRAM
////////////////////////////////////////////////////////////////////////////////////////

1) open qt, click "Open Project..."
   open the "VeWalker.pro" file

2) go to "Progjects" menu on left side of screen
   for "Build directory", click "Browse..."
   select the "VeWalker-build-desktop" folder under the VeWalker folder
   
3) go to "Edit" menu on left side of the screen and expand the "Headers" folder
   go to "mywindow.h", find "static const int window_width" and "static const int window_height"
   set them to the appropriate screen size(resolution) that you're using, is an int so no decimal points

4) go to "legoThread.h", find "const static int port"
   go to "devices and printers" under control panel on your computer, click NXT
       if NXT does not show up (make sure it's on), you'll have to connect it to the computer
       if it asks for a paasword I think it's "1234"
   go to "Hardware" tab after you click NXT, and look for "COM_" under the "Name" heading
   set "const static int port" to the "_" # from "COM_"

5) turn the nxt off and on, make sure the sleep mode won't turn on until atleast an hour
       sleep feature is under "Settings"?
   
6) press Ctrl R to run the program

You should only have to do 2-5 once

///////////////////////////////////////////////////////////////////////////////////////




DESCRIPTION OF INPUT AND OUTPUT FOLDERS
////////////////////////////////////////////////////////////////////////////////////////

Setup folder contatins text files for defining trials (practice and actual trials)
    rows are labeled,
    gap is gap time in seconds between cars
    startPos is A for starting on side of road, B for in the middle

cars folder contains text files of the car positions during each participants trials
    left column trial, then time
    each car is described with three numbers
        x, y, and rotation

Demographics folder contains demographics info

pedestrian folder contains pedestrian info
    rows are labeled

data folder contains data for pedestrian behaviour, containing in order:
    trial: contains a p if a practice trial
    start: start position of pedestrian
    time_starttrial: global time the trial started at
    time_bumper: time that the last car past the pedestrian in lane one before the pedestrian steps
    time_step: time that pedestrian first crosses onto the road
    time_latency: time_step - time_bumper
    time_arrive: time the pedestrian first steps onto the middle refuge
    time_crossing: time_arrive - time_step
    steps: number of times the users foot would have planted on the ground
    gap_chosen: time between cars the user went through

//////////////////////////////////////////////////////////////////////////////////////////