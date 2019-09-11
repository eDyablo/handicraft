import dungeon
import hero

symbol = '@'

enemies = []


def new_enemy(x, y, direction=''):
    enemy = {
        'position': (x, y),
        'direction': direction
    }
    enemies.append(enemy)
    return enemy


def move_to(enemy, x, y):
    if hero.is_at(x, y):
        enemy['position'] = (x, y)
        hero.hit_enemy()
    elif dungeon.is_empty_space(x, y):
        enemy['position'] = (x, y)
    else:
        direction = enemy['direction']
        if direction == 'up':
            direction = 'down'
        elif direction == 'down':
            direction = 'up'
        elif direction == 'left':
            direction = 'right'
        elif direction == 'right':
            direction = 'left'
        enemy['direction'] = direction


def draw(enemy, screen):
    x, y = enemy['position']
    screen.addstr(y, x, symbol)


def draw_all(screen):
    for enemy in enemies:
        draw(enemy, screen)


def remove_all():
    enemies.clear()


def is_at(x, y):
    for enemy in enemies:
        if enemy['position'] == (x, y):
            return True
    return False


def move_up(enemy):
    x, y = enemy['position']
    move_to(enemy, x, y - 1)


def move_down(enemy):
    x, y = enemy['position']
    move_to(enemy, x, y + 1)


def move_left(enemy):
    x, y = enemy['position']
    move_to(enemy, x - 1, y)


def move_right(enemy):
    x, y = enemy['position']
    move_to(enemy, x + 1, y)


def step(enemy):
    direction = enemy['direction']
    if direction == 'up':
        move_up(enemy)
    elif direction == 'down':
        move_down(enemy)
    elif direction == 'left':
        move_left(enemy)
    elif direction == 'right':
        move_right(enemy)


def step_all():
    for enemy in enemies:
        step(enemy)
