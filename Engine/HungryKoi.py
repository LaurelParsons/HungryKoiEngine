import mygameengine
import sys
import json

width = 640
height = 480

args = sys.argv
filepath = ""
for arg in args:
    if "json" in arg:
        filepath = arg
if filepath == "":
    print("add json scene file to command line arguments")
else:
    file = open(filepath)
    data = json.load(file)

    application = mygameengine.Application(width, height)
    application.StartScene()
    player = data[0]

    application.AddPlayer(player['image'], player['position'][0], player['position'][1], player['score'])
    data.remove(data[0])

    for gameObject in data:
        application.AddEnemy(gameObject['image'], gameObject['position'][0], gameObject['position'][1], gameObject['score'])

    application.Loop(60.0)
    
#while True:
    #start scene(scene1 map)
    #if(scene.won)
        #start scene(harder map)
    #else
        #start scene(easier map)

#while scene.IsSceneActive():
    #start scene (scene1 map)
    #if(scene.won)
