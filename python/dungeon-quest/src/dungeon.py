import hero
import enemy

plan = []

empty_space = ' '

coin_symbol = '$'

exit_symbol = '.'


def load(room):
    enemy.remove_all()
    plan.clear()
    for row in room:
        plan.append(list(row))
    place_hero()
    place_enemies()


def draw(screen):
    screen.clear()
    for y, row in enumerate(plan):
        screen.addstr(y, 0, ''.join(row))


def is_empty_space(x, y):
    return plan[y][x] == empty_space


def is_coin(x, y):
    return plan[y][x] == coin_symbol


def is_exit(x, y):
    return plan[y][x] == exit_symbol


def is_enemy(x, y):
    return enemy.is_at(x, y)


def remove(x, y):
    plan[y][x] = empty_space


def find(symbol):
    for y, row in enumerate(plan):
        for x, cell in enumerate(row):
            if cell == symbol:
                return x, y


def place_hero():
    x, y = find(hero.symbol)
    remove(x, y)
    hero.move_to(x, y)


def place_enemies():
    enemy.remove_all()
    for y, row in enumerate(plan):
        for x, cell in enumerate(row):
            if cell == enemy.symbol:
                remove(x, y)
                enemy.new_enemy(x, y)
            elif cell == 'V':
                remove(x, y)
                enemy.new_enemy(x, y, 'up')
            elif cell == 'H':
                remove(x, y)
                enemy.new_enemy(x, y, 'left')


def get_room(number):
    return rooms[number % len(rooms)]


rooms = [
    [
        '',
        'use W S D A keys to move',
        '###############',
        '###############',
        '###         ###',
        '###    X      .',
        '###         ###',
        '###############',
        '###############',
    ],
    [
        '',
        'collect the coins',
        '###################',
        '###################',
        '###   $     $   ###',
        '|X                .',
        '###      $      ###',
        '###################',
        '###################',
    ],
    [
        '',
        'do not touch enemies',
        '####################',
        '####################',
        '###          V   ###',
        '|X       ##      ###',
        '###      ##      ###',
        '###   V  ##      ###',
        '##############   ###',
        '##############...###',
    ],
    [
        '',
        '%%%###---###%%%',
        '%%%### X ###%%%',
        '%%%###   ###%%%',
        '######   ######',
        '###        H###',
        '######  $######',
        '######$  ######',
        '###H        ###',
        '######   ######',
        '%%%###...###%%%',
    ],
    [
        '',
        '###---########################',
        '### X ########################',
        '###   ##        ## $  $  $ ###',
        '###   ##   ##   ##   ###   ###',
        '###   ##   ##   ##   ###   ###',
        '###        ##   ## $     $ ###',
        '#############   #####   ######',
        '#############   #####   ######',
        '###$     H      $##   H    ###',
        '####             ##       $###',
        '####  $  $  $              ###',
        '###         H              ###',
        '######$          ##        ###',
        '###$$$V          ##       V  .',
        '##############################',
        '##############################',
    ],
    [
        '',
        '########################################',
        '##  ###  ###############################',
        '##   $   ###                        ####',
        '###  H   ##    V         #########   ###',
        '####### ##          #############     ##',
        '|X               ########       H     ##',
        '###################       #####       ##',
        '####################     #######      ##',
        '## $$$ ##        ##     ##  $  ##  $  ##',
        '##     ##   ##     ## V##  $$$  ##  $ ##',
        '##     ##  ##   ###    ##   $    ##   ##',
        '###    H    ##    H             ########',
        '###...##################################',
    ],
    [
        '',
        '',
        '        Y O U   W I N',
        '        hit Q to quit'
        '',
        '%%%%%%%%%%###---###%%%%%%%%%%',
        '%%%%%%%%###   X   ###%%%%%%%%',
        '%%%%%%###           ###%%%%%%',
        '%%%%###               ###%%%%',
        '%%###       $ $ $       ###%%',
        '###     $ $$ $$$ $$ $     ###',
        '%%###       $ $ $       ###%%',
        '%%%%###               ###%%%%',
        '%%%%%%###           ###%%%%%%',
        '%%%%%%%%###       ###%%%%%%%%',
        '%%%%%%%%%%###   ###%%%%%%%%%%',
        '%%%%%%%%%%%%#####%%%%%%%%%%%%',
    ]
]

game_over_room = [
    '',
    '',
    '   G A M E   O v E R',
    '     hit Q to quit',
    '',
    ' #####################',
    ' #####################',
    ' ###   H           ###',
    ' ###    %%%%%%% V  ###',
    ' ###   %       %   ###',
    ' ###   %   X   %   ###',
    ' ###   %       %   ###',
    ' ### V  %%%%%%%    ###',
    ' ###           H   ###',
    ' #####################',
    ' #####################',
]
