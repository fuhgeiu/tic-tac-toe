TIC TAC TOE
-



DISCRIPTION, key points


- To create a tic tac toe game, with the palyer interacitng through either the console or a gui

- Used the mygui library for the gui version


CONTENTS

- main branch,  readme file and git nessasary files, no project files 

- console xcode branch, includes folder containing files and target

- console branch, includes files to run the game with a console interface

- gui branch, includes both gui library and game core files


GUIDE
-

-CONSOLE    /Run console version, no pakage or targets  (branch "console")

  - to run console version (just files, use compiler of ur choice) download these files in the console branch

        -board.hpp

        -game_data.hpp

        -main_current.cpp

        -stream.hpp

        -algorithim.hpp

        
      
  - using a compiler of ur choice, set the "main_current.cpp" as the target/build file/main file
__________________________________________________________________________________________________________


-CONSOLE XCODE    /Run console using a xcode project (recomemded for mac users who have xcode)  (branch "console_xcode")   

  - to run xcode concolse, download this folder in the console_xcode branch

        -tic tac toe xcode

  - Open the  [tic tac toe xcode.xcodeproj] file
  - !warning! make sure tic tac toe xcode target is being used, if test target is selected, only tests will run
  - Press play button, to build and run (will open console, change with scheme edit)
__________________________________________________________________________________________________________


-GUI  (WARNING!!!!   IN PROGRESS   DO NOT CLONE BRANCH OR ATTEMPT TO RUN!)    /Run a gui application using metal api 

  - download the folder in the gui branch

        -gui_metal

  - once cloned, to run use a compiler of ur choice to run the "gui_TTT.cpp" file.
__________________________________________________________________________________________________________


DEV NOTES

    GUI branch utilizes the mygui library to dispaly and interact with ui, by communicating 
    with grpahics api. it will communicate with the TTT core files to run the game.

    currently gui is only being tested and created using apple metal api, will have versions later using direct x api for windows

    currently game loop is run on a main.cpp file temporary as i prepare for adapting the game for gui application 

    currently uses a simple way to check wins via checking all possible combinaitons. preparing the algorithim hpp 
    file to replace current implementation. 


    
    





