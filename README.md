# Hungry Koi Engine
A small, C++ based game engine designed for feeding-frenzy type games. Completed as a final for a building game engines class, this is a component based engine with a smart resource management system. 

Also includes a python GUI level editor, allowing users to design and output scene files. Pybind integration allows the engine to call these Python files. 

**Project Website**: https://lparsons443.wixsite.com/laurel-parsons/hungrykoiengine

## Compilation Instructions

To compile, navigate to the finalproject/Engine folder and use the following command:
 $ python3 linuxbuild.py
Then to run: 
$ python3 HungryKoi.py ./mygameengine.so ./../scene1.json

To run the level builder, navigate to finalproject/LevelBuilder and run
$ python main.py
resulting json files will be saved in the /finalproject folder 

### ./Directory Organization

- assets
    - Art assets
- docs 
    - Source Code Documentation
- Engine
    - src
        - Source files
    - include
        - Header files
- LevelBuilder
    - Python application to create scene files that can be run by the engine.
- scenes
    - Scene files



# Original Project Rubric

- For this assignment you are going to be building a 'Game Maker' as your final project! 
- You will use your engine to make a game with at least '3' scenes.

## Logistics
<!-- NOTE:  This semester you will be completing the project yourself.
- You will be working on this assignment as a team on your choice (or a combination) of the Mac, Linux, or Windows Operating Sytstem.
-->
The **key** components for your project are:

1. The C++ engine that does the heavy lifting and management of game objects and resources
2. A simple to use editor for building games (e.g. a GUI-based tile editor)
3. A game built in your engine (i.e. a class or original game) with 3 'scenes'.

## Technical Requirements

The following are the technical requirements of your game engine. There is significant freedom in how you achieve them, but I would like you to apply these techniques in your engine.

- [ ] Implement a resource manager
- [ ] Implement a GUI-based editor/environment for assisting building a game (e.g. A tilemap editor, 2D animation preview tool, etc.)
    - This tool need not be implemented in C++, but should otherwise generate data that your C++ engine can use.
- [ ] Your engine must be data-driven
  - [ ] Scripts should be loaded for the gameplay logic
  - [ ] Other configuration files (e.g. levels, scenes, etc.) should be loaded at run-time.
- [ ] Your engine should be component-based **or** use some other logical pattern for organizing game objects (At a minimum you should have a gameobject class).
- [ ] Something **extra** that gives your engine a 'wow' factor to show off to the TA's and instructors. Highlight this in your video (could be engineering, could be a gameplay mechanic that you designed your engine around, the goal is that it is something non-trivial)


## Universal Resources

You will be using SDL to build this project and the same libraries that we have been using during the semester.

* General SDL programming tutorials: 
  * http://lazyfoo.net/tutorials/SDL/
  * [Mike's SDL Playlist](https://www.youtube.com/playlist?list=PLvv0ScY6vfd-p1gSnbQhY7vMe2rng0IL0)

# Part 1 and 2 Rubric
   
<table>
  <tbody>
    <tr>
      <th>Points</th>
      <th align="center">Description</th>
    </tr>     
    <tr>
      <td>25% (Engineering/Design Patterns)</td>
      <td align="left">On the polish of your final project (did it work as intended, were there bugs, did I have to struggle to get your tool running, was your solution well engineered, were there patterns used, etc.)</td>
    </tr>
    <tr>
      <td>40%  (Requirements)</td>
      <td align="left">Did you complete all of the requirements from part 2?</td>
    </tr>
    <tr>
      <td>15%% (Wow Factor)</td>
      <td align="left">On the creativity and overall 'wow' factor of your project. Was there a cool feature or surprise that got me excited about the project? Does this project have potential to be extended in the future? Were there creative additional tools that supported your work. Was there something not covered in class that you were excited about, learned, and implemented anyway? (Document this to bring to my attention if so!)</td>
    </tr>
  </tbody>
</table>

# Part 3 - Rubric

<table>
  <tbody>
    <tr>
      <th>Points</th>
      <th align="center">Description</th>
    </tr>
    <tr>
      <td>4% (Engine Architecture diagram)</td>
      <td align="left">Did you add the engine architecture diagram to your website "./media/C4Engine.pdf"?</td>
    </tr>         
    <tr>
      <td>4% (Documentation)</td>
      <td align="left">Did you generate something like "http://www.horde3d.org/docs/html/_api.html"?</td>
    </tr>    
    <tr>
      <td>4% (Build)</td>
      <td align="left">Does the build work when I download your repo and run the game?</td>
    </tr>
    <tr>
      <td>4% (Post mortem)</td>
      <td align="left">Did you learn anything and provide a brief and well-thought out reflection of these learnings?</td>
    </tr>
    <tr>
      <td>4% (Website)</td>
      <td align="left">Do you have a webpage that presents your project in a positive way with the above materials.</td>
    </tr>
  </tbody>
</table>
