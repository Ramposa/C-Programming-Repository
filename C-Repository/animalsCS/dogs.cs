using System;

public class Dog : Animal
{
  public Dog(string name, string type, string eats):base(name, type, eats){
    
  }
  public override void speak() {
    // make a generic animal noise
    Console.WriteLine("woof");
  }
}