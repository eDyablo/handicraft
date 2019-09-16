import curses
import dungeon
import hero
import enemy

screen = curses.initscr()
screen.timeout(250)
curses.noecho()
curses.cbreak()
curses.curs_set(0)

dungeon.load(dungeon.get_room(0))

while True:
    dungeon.draw(screen)
    enemy.draw_all(screen)
    hero.draw(screen)

    enemy.step_all()

    key = screen.getch()
    if key == ord('q'):
        break
    elif key == ord('w'):
        hero.move_up()
    elif key == ord('s'):
        hero.move_down()
    elif key == ord('d'):
        hero.move_right()
    elif key == ord('a'):
        hero.move_left()

curses.echo()
curses.nocbreak()
curses.endwin()
