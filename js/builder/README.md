# Builder Pattern

## Motivation

The more complex an application is the complexity of classes and objects used increases. Complex objects are made of parts produced by other objects that need special care when being built. An application might need a mechanism for building complex objects that is independent from the ones that make up the object. If this is the problem you are being confronted with, you might want to try using the Builder (or Adaptive Builder) design pattern.

This pattern allows a client object to construct a complex object by specifying only its type and content, being shielded from the details related to the object's representation. This way the construction process can be used to create different representations. The logic of this process is isolated form the actual steps used in creating the complex object, so the process can be used again to create a different object form the same set of simple objects as the first one.

## Participants

The participants classes in this pattern are:
- **Builder**
    - class specifies an abstract interface for creating parts of a Product object
- **ConcreteBuilder**
    - constructs and puts together parts of the product by implementing the Builder interface
    - defines and keeps track of the representation it creates and provides an interface for saving the product
- **Director**
    - class constructs the complex object using the Builder interface
- **Product**
    - represents the complex object that is being built
