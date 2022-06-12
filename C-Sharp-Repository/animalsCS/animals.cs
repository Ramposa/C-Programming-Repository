using System;

public class Animal
{
  private string name;
  private string type;
  private string eats;

  public Animal()
  {
    
  }

  public Animal(string name, string type, string eats)
  {
    this.name = name;
    this.type = type;
    this.eats = eats;
  }

  public string Name
  {
    get { return name; }
    set { name = value; }
  }

  public void run()
  {
    // makes the animal run
  }

  public virtual void speak() {
    // make a generic animal noise
    Console.WriteLine("grrr");
  }
}