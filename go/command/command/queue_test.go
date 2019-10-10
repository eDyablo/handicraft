package command

import "testing"

type TestCommand struct {
  Name string
}

func (cmd *TestCommand) Execute(cntx Context) {
}

func Test_queue_has_no_commands_when_created(test *testing.T) {
  // Arrange
  queue := NewQueue()
  // Assert
  if queue.HasCommands() == false {return}
  test.Error(queue.commands)
}

func Test_queue_enqueue_adds_commands_in_order(test *testing.T) {
  // Arrange
  queue := NewQueue()
  first := &TestCommand { Name: "first" }
  second := &TestCommand { Name: "second" }
  // Act
  queue.Enqueue(first)
  queue.Enqueue(second)
  // Assert
  if len(queue.commands) == 2 &&
    queue.commands[0] == first &&
    queue.commands[1] == second { return }
  test.Error(queue.commands)
}

func Test_queue_dequeue_returns_first_command_in_the_queue_and_removes_it_from_the_queue(test *testing.T) {
  // Arrange
  queue := NewQueue()
  first := &TestCommand { Name: "first" }
  second := &TestCommand { Name: "second" }
  queue.Enqueue(first)
  queue.Enqueue(second)
  // Act
  extracted := queue.Dequeue()
  // Assert
  if extracted == first &&
    len(queue.commands) == 1 &&
    queue.commands[0] == second { return }
  test.Error(queue.commands)
}

func Test_push_adds_commands_in_reverse_order(test *testing.T) {
  // Arrange
  queue := NewQueue()
  first := &TestCommand { Name: "first" }
  second := &TestCommand { Name: "second" }
  // Act
  queue.Push(first)
  queue.Push(second)
  // Assert
  if len(queue.commands) == 2 &&
    queue.commands[0] == second &&
    queue.commands[1] == first { return }
  test.Error(queue.commands)
}
