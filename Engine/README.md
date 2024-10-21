## Add any additional notes here

I used this tutorial reference to help make the level editor: https://www.youtube.com/playlist?list=PLjcN1EyupaQn-x_9QuGIwIESxfV9kNUZf

## Game/Engine Publicity

**Project Website**: https://lparsons443.wixsite.com/laurel-parsons/hungrykoiengine

## Compilation Instructions

To compile, navigate to the finalproject/Engine folder and use the following command:
 $ python3 linuxbuild.py
Then to run: 
$ python3 HungryKoi.py ./mygameengine.so ./../scene1.json

To run the level builder, navigate to finalproject/LevelBuilder and run
$ python main.py
resulting json files will be saved in the /finalproject folder

## Project Hieararchy

In the future, other engineers may take on our project, so we have to keep it organized given the following requirements below. Forming some good organization habits now will help us later on when our project grows as well. These are the required files you should have 

### ./Engine Directory Organization

- Docs 
    - Source Code Documentation
- Assets
    - Art assets (With the Sub directories music, sound, images, and anything else)
- src
    - source code(.cpp files) The make file or any build scripts that automate the building of your project should reside here.
- include
    - header files(.h and .hpp files)
- lib
    - libraries (.so, .dll, .a, .dylib files). Note this is a good place to put SDL
- bin
    - This is the directory where your built executable(.exe for windows, .app for Mac, or a.out for Linux) and any additional generated files are put after each build.
- EngineBuild (Optional)
    - You may optionally put a .zip to you final deliverable. One should be able to copy and paste this directory, and only this directory onto another machine and be able to run the game. This is optional because for this course we will be building your projects from source. However, in the game industry it is useful to always have a build of a game ready for testers, thus a game project hieararchy would likely have this directory in a repo or other storage medium.
- ThirdParty
    - Code that you have not written if any.

**Note: For the final project you may add additional directories if you like, for example for your game which demonstrates your engine works.** 

**Additional Notes:** 

1. src and include should only contain ".cpp" or ".hpp" files. Why? It makes it very fast to do a backup of your game project as one example. Secondly, binary files that are generated often clutter up directories. I should not see any binaries in your repository, you may use a '.gitignore' file to help prevent this automatically. 