package command

// Queue defines a queue of commands
type Queue struct {
  commands []Command
}

// NewQueue construncts new Queue
func NewQueue() Queue {
  return Queue {}
}

// HasCommands returns true if there are
// pending commands in the queue
func (queue *Queue) HasCommands() bool {
  return len(queue.commands) > 0
}

// Enqueue adds the command at the end of the queue 
func (queue *Queue) Enqueue(command Command) {
  queue.commands = append(queue.commands, command)
}

// Dequeue removes first command from the queue and
// returns the command
func (queue *Queue) Dequeue() Command{
  command := queue.commands[0]
  queue.commands = queue.commands[1:]
  return command
}

// Push adds the command at the beginning of the queue 
func (queue *Queue) Push(command Command) {
  queue.commands = append([]Command{ command }, queue.commands...)
}
