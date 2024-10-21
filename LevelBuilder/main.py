import pygame
import json
import GameObject

assets_path = "../assets/"

def position_prefabs(prefab_array):
    b_position_x = WIDTH + 25
    b_position_y = 25
    for prefab in prefab_array:
        prefab.set_pos(b_position_x, b_position_y)
        b_position_x += prefab.width + 25

        if b_position_x + prefab.width > WIDTH + SIDE_MARGIN:
            b_position_x = WIDTH + 25
            b_position_y += prefab.height + 25



def save_scene(gameObjects_list, level):
    with open("../scene" + str(level) + ".json", "w") as file:
        data_array = []
        for gameObject in gameObjects_list:
            data = {
                'image': './' + gameObject.imagesrc,
                'position': gameObject.pos,
                'score': gameObject.score
            }
            data_array.append(data)

        json.dump(data_array, file)

    print("saved")

def draw_gameobject_settings():
    pygame.draw.rect(gameobject_settings, color, input_rect)
    score_text_surface = font.render(score_text, True, (0, 0, 0))
    gameobject_settings.blit(score_text_surface, (input_rect.x + 5, input_rect.y + 5))
    input_rect.w = max(input_rect.w, score_text_surface.get_width() + 10)

    pos_text_surface = font.render(pos_text, True, (0, 0, 0))
    pygame.draw.rect(gameobject_settings, (118, 222, 206), max_pos_rect)
    gameobject_settings.blit(pos_text_surface, (pos_label_rect.x + pos_label_rect.w, pos_label_rect.y))
    screen.blit(gameobject_settings, settings_rect)

pygame.init()

WIDTH = 640
HEIGHT = 480
LOWER_MARGIN = 100
SIDE_MARGIN = 300

level = 1

screen = pygame.display.set_mode((WIDTH + SIDE_MARGIN, HEIGHT + LOWER_MARGIN))
pygame.display.set_caption('Level Editor')

backgroundColor = pygame.Color(255, 0, 255)

pond_background = pygame.image.load(assets_path + 'pond_bottom.bmp').convert_alpha()
pond_background = pygame.transform.scale(pond_background, (WIDTH, HEIGHT))

goldfish_img = pygame.image.load(assets_path + 'goldfish.bmp').convert()
goldfish_img = pygame.transform.scale(goldfish_img, (32, 32))
goldfish_img.set_colorkey(backgroundColor)

goldfish_prefab = GameObject.GameObject(goldfish_img, assets_path + 'goldfish.bmp', 1, "prefab",
                                            WIDTH + SIDE_MARGIN, HEIGHT + LOWER_MARGIN)

catfish_img = pygame.image.load(assets_path + 'catfish.bmp').convert()
catfish_img = pygame.transform.scale(catfish_img, (32, 32))
catfish_img.set_colorkey(backgroundColor)

catfish_prefab = GameObject.GameObject(catfish_img, assets_path + 'catfish.bmp', 10, "prefab",
                                            WIDTH + SIDE_MARGIN, HEIGHT + LOWER_MARGIN)

koi_img = pygame.image.load(assets_path + 'koi.bmp').convert()
koi_img = pygame.transform.scale(koi_img, (32, 32))
koi_img.set_colorkey(backgroundColor)

koi_hero = GameObject.GameObject(koi_img, assets_path + 'koi.bmp', 5, "game object", WIDTH, HEIGHT)
koi_hero.set_pos(int(WIDTH / 2 - 16), int(HEIGHT - 64))

button_font = pygame.font.Font(None, 15)

save_rect = pygame.Rect(WIDTH/2, HEIGHT + LOWER_MARGIN/2, 50, 25)
save_text = button_font.render("Save", True, (255, 255, 255))
save_text_rect = save_text.get_rect(center=save_rect.center)

mouse_shadow = pygame.Surface((32, 32), pygame.SRCALPHA, 32)
mouse_shadow.convert_alpha()
mouse_shadow.set_alpha(128)

font = pygame.font.Font(None, 24)
gameobject_settings = pygame.Surface((SIDE_MARGIN, HEIGHT/2))
gameobject_settings.fill((118, 222, 206))
settings_rect = gameobject_settings.get_rect(topleft=(WIDTH, HEIGHT/2))
score_label = font.render("Score:", True, (0, 0, 0))
label_rect = score_label.get_rect(topleft=(15, 25))
gameobject_settings.blit(score_label, label_rect)

input_rect = pygame.Rect(30+label_rect.width, 20, 100, 32)
pos_label = font.render("Position: ", True, (0, 0, 0))
pos_label_rect = pos_label.get_rect(topleft=(15, 60))
gameobject_settings.blit(pos_label, pos_label_rect)

score_text = str(koi_hero.score)
pos_text = str(koi_hero.pos)

user_typing = False

pos_text_surface = font.render(pos_text, True, (0, 0, 0))
max_pos_rect = pos_text_surface.get_rect(topleft=(pos_label_rect.x + pos_label_rect.w, pos_label_rect.y))
max_pos_rect.w += 20

level_label = font.render("Level: " + str(level), True, (0, 0, 0))
level_label_rect = level_label.get_rect(topleft=(50, HEIGHT + LOWER_MARGIN / 2))


#update_level_num(screen, level)

gameObjects = []
gameObjects.append(koi_hero)

prefabs = []
prefabs.append(goldfish_prefab)
prefabs.append(catfish_prefab)
position_prefabs(prefabs)

koi_hero.selected = True
currently_selected = koi_hero

drag = False
run = True
while run:
    screen.fill((200, 200, 200))
    screen.blit(pond_background, (0, 0))

    screen.blit(level_label, level_label_rect)

    for gameObject in gameObjects:
        if gameObject.draw(screen):
            currently_selected.selected = False
            currently_selected = gameObject
            score_text = str(currently_selected.score)
            pos_text = str(currently_selected.pos)

    for prefab in prefabs:
        if prefab.draw(screen):
            currently_selected.selected = False
            currently_selected = prefab
            mouse_shadow = pygame.Surface((32, 32), pygame.SRCALPHA, 32)
            mouse_shadow.convert_alpha()
            mouse_shadow.set_alpha(128)

    pygame.draw.rect(screen, (0, 0, 0), save_rect)
    screen.blit(save_text, save_text_rect)

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            run = False
        if event.type == pygame.MOUSEBUTTONDOWN and currently_selected.type == "prefab":
            if (pygame.mouse.get_pos()[0] + currently_selected.width <= WIDTH and pygame.mouse.get_pos()[1] +
                    currently_selected.height <= HEIGHT):
                newGameObject = GameObject.GameObject(currently_selected.image, currently_selected.imagesrc,
                                                      currently_selected.score, "game object", WIDTH, HEIGHT)
                newGameObject.set_pos(pygame.mouse.get_pos()[0], pygame.mouse.get_pos()[1])
                gameObjects.append(newGameObject)
        if event.type == pygame.MOUSEBUTTONDOWN and currently_selected.type == "game object":
            if settings_rect.collidepoint(pygame.mouse.get_pos()):
                absx, absy = pygame.mouse.get_pos()
                relativeX = absx - settings_rect.x
                relativeY = absy - settings_rect.y
                if input_rect.collidepoint((relativeX, relativeY)):
                    user_typing = True
                else:
                    user_typing = False
            elif currently_selected.rect.collidepoint(pygame.mouse.get_pos()):
                drag = True
        if event.type == pygame.MOUSEMOTION and drag:
            currently_selected.set_pos(pygame.mouse.get_pos()[0], pygame.mouse.get_pos()[1])
            pos_text = str(currently_selected.pos)
        if event.type == pygame.MOUSEBUTTONUP and drag:
            drag = False
        if event.type == pygame.MOUSEBUTTONDOWN and save_rect.collidepoint(pygame.mouse.get_pos()):
            save_scene(gameObjects, level)

            gameObjects = []
            gameObjects.append(koi_hero)

            prefabs = []
            prefabs.append(goldfish_prefab)
            prefabs.append(catfish_prefab)
            position_prefabs(prefabs)

            koi_hero.selected = True
            currently_selected = koi_hero
            level += 1
            level_label = font.render("Level: " + str(level), True, (0, 0, 0))
            level_label_rect = level_label.get_rect(topleft=(50, HEIGHT + LOWER_MARGIN / 2))
            pygame.draw.rect(screen, (200, 200, 200), level_label_rect)

        if event.type == pygame.KEYDOWN and user_typing:
            if event.key == pygame.K_BACKSPACE:
                score_text = score_text[:-1]
            elif event.key == pygame.K_RETURN:
                currently_selected.set_score(int(score_text))
                user_typing = False
            else:
                score_text += event.unicode

    if currently_selected.type == "game object":
        color = None
        if user_typing:
            color = pygame.Color('gray100')
        else:
            color = pygame.Color('grey')

        draw_gameobject_settings()

    elif currently_selected.type == "prefab":
        mouse_shadow.blit(currently_selected.ogimage, (0, 0))
        screen.blit(mouse_shadow, pygame.mouse.get_pos())

    pygame.display.update()

pygame.quit()

