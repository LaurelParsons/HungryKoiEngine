import pygame
class GameObject():
    def __init__(self, image, imagesrc, score, type, maxX, maxY):
        self.width = image.get_width()
        self.height = image.get_height()
        self.score = score
        self.imagesrc = imagesrc
        self.ogimage = image
        self.image = pygame.transform.scale(image, (self.width + self.score, self.height + self.score))
        self.rect = self.image.get_rect()
        self.type = type
        self.selected = False
        self.maxX = maxX
        self.maxY = maxY

    def constrain_pos(self):
        self.rect.bottom = min(self.rect.bottom, self.maxY)
        self.rect.right = min(self.rect.right, self.maxX)
        self.rect.top = max(self.rect.top, 0)
        self.rect.left = max(self.rect.left, 0)
        self.pos = self.rect.topleft


    def set_score(self, score):
        self.score = score
        self.image = pygame.transform.scale(self.image, (self.width + self.score, self.height + self.score))
        self.rect = self.image.get_rect(topleft=self.rect.topleft)
        self.constrain_pos()

    def set_pos(self, x, y):
        self.pos = (x, y)
        self.rect.topleft = self.pos
        self.constrain_pos()

    def draw(self, surface):
        selected_this_turn = False

        if self.rect.collidepoint(pygame.mouse.get_pos()):
            if pygame.mouse.get_pressed()[0] == 1 and self.selected is False:
                self.selected = True
                selected_this_turn = True

        if self.type == "game object":
            surface.blit(self.image, self.pos)
        else:
            surface.blit(self.ogimage, self.pos)

        if self.selected:
            pygame.draw.rect(surface, (255, 0, 0), self.rect, 1)

        return selected_this_turn
