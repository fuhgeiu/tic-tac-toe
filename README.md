TIC TAC TOE
-



DISCRIPTION, key points


- To create a tic tac toe game, with the palyer interacitng through either the console or a gui

- Used the mygui library for the gui version


CONTENTS

- main branch,  readme file and git nessasary files

- console xcode branch, includes folder containing files and target

- console branch, includes files to run the game with a console interface

- gui branch, includes both gui library and game core files


GUIDE
-

CONSOLE

Run console version, no pakage or targets 

- to run console version (just files, use compiler of ur choice) download these files

      -board.hpp

      -game_data.hpp

      -main_current.cpp

      -stream.hpp

      -algorithim.hpp

        
      
- using a compiler of ur choice, set the "main_current.cpp" as the target/build file/main file


CONSOLE XCODE

Run console using a xcode project (recomemded for mac users who have xcode)

- to run xcode concolse, download this folder

      -tic tac toe xcode

- Open the  [tic tac toe xcode.xcodeproj] file
- make sure tic tac toe xcode target is being used, than build (will open console, change with scheme edit)



GUI  (WARNING!!!!   IN PROGRESS   DO NOT CLONE BRANCH OR ATTEMPT TO RUN!)

Run a gui application using metal api 

- download the folder

        -gui_metal

 - once cloned, to run use a compiler of ur choice to run the "gui_TTT.cpp" file.


NOTES

    GUI branch utilizes the mygui library to dispaly and interact with ui, by communicating 
    with grpahics api. it will communicate with the TTT core files to run the game.

    currently gui is only being tested and created using apple metal api, will have versions later using direct x api for windows

    currently game loop is run on a main.cpp file temporary as i prepare for adapting the game for gui application 

    currently uses a simple way to check wins via checking all possible combinaitons. preparing the algorithim hpp 
    file to replace current implementation. 


    
    





