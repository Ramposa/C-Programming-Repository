using System;

class MainClass {
  public static void Main (string[] args) {
    Animal cat = new Animal("Cassie", "Cat", "Tuna");
    Dog dog = new Dog("Danny", "Dog", "Bones");

    Console.Write(cat.Name + " says ");
    cat.speak();

    Console.Write(dog.Name + " says ");
    dog.speak();

  }
}