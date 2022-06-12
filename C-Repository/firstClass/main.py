from dog import *

miles = Dog("Miles",4)

print(miles.name, miles.age, miles.species)

print(miles.description())
print(miles.speak("Woof, Woof"))

bobby = JackRusselTerrier("Bobby",1)

print(type(bobby))
print(isinstance(bobby,Dog))
print(isinstance(bobby,Bulldog))
print(isinstance(bobby,JackRusselTerrier))




# Exercise Tasks
# 1. Add a new class to Dog.py that inherits from Dog. ANy type of dog will do.
# 2. Add a new attribute called "food" to Dog that stores the name of the dogs favourite brand of dog food
# 3. Add a method to dog called "eats()" that returns a string describing the dog eating its favourite food
# 4. Add a method to your new dog subclass that overrides eats() and returns a string describing the special way your dog eats its food.
# 5. Add a private attribute called "treat". Add a method called change_treat(new_treat) that takes a string as a parameter and sets "treat" to "new-treat". This method should be the only way to change "treat"
# 6. Add a method to dog called "give_treat" that gives your dog a treat and describes what happens