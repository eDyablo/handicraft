# Mediator pattern

## Motivation

In order to have a good object oriented design we have to create lots of classes interacting one with each other. If certain principles are not applied the final framework will end in a total mess where each object relies on many other objects in order to run. In order to avoid tight coupled frameworks, we need a mechanism to facilitate the interaction between objects in a manner in that objects are not aware of the existence of other objects.

Let's take the example of a screen. When we create it we add all sort of controls to the screen. This control need to interact with all the other control. For example when a button is pressed it must know if the data is valid in other controls. As you have seen if you created different applications using forms you don't have to modify each control class each time you add a new control to the form. All the operations between controls are managed by the form class itself. This class is called mediator.

## Participants

The participants classes in this pattern are:

- **Mediator**
  - defines an interface for communicating with Colleague objects.

- **ConcreteMediator**
  - knows the colleague classes and keep a reference to the colleague objects

  - implements the communication and transfer the messages between the colleague classes

- **Colleague classes**
  - keep a reference to its Mediator object

  - communicate with the Mediator whenever it would have otherwise communicated with another Colleague.

## Applicability

According to Gamma et al, the Mediator pattern should be used when:

- a set of objects communicate in well-defined but complex ways. The resulting interdependencies are unstructured and difficult to understand.

- reusing an object is difficult because it refers to and communicates with many other objects.

- a behavior that's distributed between several classes should be customizable without a lot of subclassing.

## Consequences

### Advantages

- It limits subclassing. A mediator localizes behavior that otherwise would be distributed among several objects. Changing this behaviour requires subclassing Mediator only, Colleague classes can be reused as is.

### Disadvantages

- It centralizes control. The mediator pattern trades complexity of interaction for complexity in the mediator. Because a mediator encapsulates protocols, it can become more complex than any individual colleague. This can make the mediator itself a monolith that’s hard to maintain
