import dungeon

symbol = 'X'

position = [0, 0]

data = {
    'hp': 3,
    'gold': 0,
    'room': 0
}


def move_to(x, y):
    if dungeon.is_empty_space(x, y):
        position[0] = x
        position[1] = y
    if dungeon.is_coin(x, y):
        take_coin(x, y)
    if dungeon.is_enemy(x, y):
        hit_enemy()
    if dungeon.is_exit(x, y):
        exit_room()


def move_up():
    move_to(position[0], position[1] - 1)


def move_down():
    move_to(position[0], position[1] + 1)


def move_left():
    move_to(position[0] - 1, position[1])


def move_right():
    move_to(position[0] + 1, position[1])


def draw(screen):
    screen.addstr(0, 0, f"hp { data['hp'] }  gold { data['gold'] }")
    screen.addstr(position[1], position[0], symbol)


def is_at(x, y):
    return (position[0], position[1]) == (x, y)


def take_coin(x, y):
    dungeon.remove(x, y)
    move_to(x, y)
    data['gold'] += 1


def hit_enemy():
    data['hp'] -= 1
    if data['hp'] == 0:
        dungeon.load(dungeon.game_over_room)


def exit_room():
    data['room'] += 1
    next_room = dungeon.get_room(data['room'])
    dungeon.load(next_room)
